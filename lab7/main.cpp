#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include "./npc/npc.h"
#include "./npc/wanderingKnight.h"
#include "./npc/slaveTrader.h"
#include "./npc/squirrel.h"
#include "./patterns/factory.h"
#include "./patterns/visitor.h"
#include <set>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>
#include <shared_mutex>

using namespace std::chrono;
using set_t = std::set<std::shared_ptr<NPC>>;
std::mutex print_mutex;

std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array)
        n->print();
    return os;
}

void save(const set_t &array, const std::string &filename)
{
    std::string filepath = "../lab6/" + filename;
    std::ofstream fs(filepath);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename)
{
    std::string filepath = "../lab6/" + filename;
    set_t result;
    std::ifstream is(filepath);
    if (!is.is_open())
    {
        std::cerr << "Error: " << std::endl;
    }
    int count, x, y;
    int type;
    is >> count;
    for (int i = 0; i < count; ++i)
    {
        is >> type >> x >> y;
        result.insert(NPCFactory::factory(static_cast<NpcType>(type), Point(x, y)));
    }

    is.close();

    return result;
}

std::atomic<bool> isRunning{true};
struct FightEvent
{
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager
{
private:
    std::vector<FightEvent> events;
    std::shared_mutex mtx;

    FightManager() {}

public:
    static FightManager &get()
    {
        static FightManager instance;
        return instance;
    }

    void add_event(FightEvent &&event)
    {
        std::lock_guard<std::shared_mutex> lock(mtx);

        if (!event.attacker->is_close(event.defender) ||
            !event.attacker->is_alive() || !event.defender->is_alive())
        {
            return;
        }

        for (const auto &existing_event : events)
        {
            if (existing_event.attacker == event.attacker &&
                existing_event.defender == event.defender)
            {
                return;
            }
        }

        events.push_back(std::move(event));
    }

    void operator()()
    {
        FightVisitor visitor;

        while (isRunning)
        {
            std::optional<FightEvent> event;

            {
                std::lock_guard<std::shared_mutex> lock(mtx);
                if (!events.empty())
                {
                    event = std::move(events.front());
                    events.erase(events.begin());
                }
            }

            if (event)
            {
                auto attacker = event->attacker;
                auto defender = event->defender;

                if (!attacker->is_alive() || !defender->is_alive())
                {
                    continue;
                }

                if (defender->accept(visitor, *attacker))
                {
                    defender->must_die(); // Defender умирает
                }
            }
            else
            {
                std::this_thread::sleep_for(500ms);
            }
        }
    }
};

int main()
{
    set_t array; // Набор всех NPC

    const int MAX_X{100};
    const int MAX_Y{100};

    // Генерация начального распределения NPC
    for (size_t i = 0; i < 50; ++i)
        array.insert(NPCFactory::factory(NpcType(std::rand() % 3), Point(std::rand() % MAX_X, std::rand() % MAX_Y)));

    // Поток обработки событий боя
    std::thread fight_thread(std::ref(FightManager::get()));

    // Поток перемещения NPC и добавления боев
    std::thread move_thread([&array, MAX_X, MAX_Y]()
                            {
        while (isRunning){
            // Фаза перемещения
            for (std::shared_ptr<NPC> npc : array)
            {
                if (npc->is_alive())
                {
                    int shift_x = (std::rand() % 3 - 1); // -1, 0, 1
                    int shift_y = (std::rand() % 3 - 1); // -1, 0, 1
                    npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                }
            }

            // Фаза боя
            for (std::shared_ptr<NPC> npc : array)
            {
                for (std::shared_ptr<NPC> other : array)
                {
                    if (other != npc && npc->is_alive() && other->is_alive() && npc->is_close(other))
                    {
                        FightManager::get().add_event({npc, other});
                    }
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        } });

    // Поток завершения игры
    std::thread game_thread([]()
                            {
        std::this_thread::sleep_for(std::chrono::seconds(25));
        isRunning = false; });

    // Основной цикл игры
    while (isRunning)
    {
        const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        {
            std::array<char, grid * grid> fields{0};
            for (std::shared_ptr<NPC> npc : array)
            {
                Point<int> pos = npc->position;
                int i = pos.x_ / step_x;
                int j = pos.y_ / step_y;

                if (npc->is_alive())
                {
                    switch (npc->get_type())
                    {
                    case WanderingKnightType:
                        fields[i + grid * j] = 'W'; // Рыцарь
                        break;
                    case SlaveTraderType:
                        fields[i + grid * j] = 'S'; // Работорговец
                        break;
                    case SquirrelType:
                        fields[i + grid * j] = 'Q'; // Белка
                        break;
                    default:
                        break;
                    }
                }
                else
                {
                    fields[i + grid * j] = '.'; // Мертвый NPC
                }
            }

            std::lock_guard<std::mutex> lck(print_mutex);
            for (int j = 0; j < grid; ++j)
            {
                for (int i = 0; i < grid; ++i)
                {
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(1s);
    };

    // Ожидание завершения потоков
    game_thread.join();
    move_thread.join();
    fight_thread.join();

    std::cout << "Game over. Final NPC states:" << std::endl;
    for (const auto &npc : array)
    {
        if (npc->is_alive()) // Проверяем, жив ли NPC
        {
            npc->print(); // Вывод информации о выживших
        }
    }

    return 0;
}
