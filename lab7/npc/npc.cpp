#include "npc.h"

NPC::NPC(const Point<int> &position_, NpcType type_) : position(position_), type(type_) {}

void NPC::save(std::ostream &os)
{
    os << position.x_ << std::endl;
    os << position.y_ << std::endl;
}

bool NPC::is_close(const std::shared_ptr<NPC> &other)
{
    std::lock_guard<std::mutex> lck(mtx);

    if (this == other.get()) // Исключаем бой с самим собой
        return false;

    size_t distance = 0;
    switch (this->type)
    {
    case WanderingKnightType:
    case SlaveTraderType:
        distance = 10; // Рыцари и Работорговцы видят на 10 клеток
        break;
    case SquirrelType:
        distance = 5; // Белки видят только на 5 клеток
        break;
    default:
        break;
    }

    int dx = position.x_ - other->position.x_;
    int dy = position.y_ - other->position.y_;
    return (dx * dx + dy * dy <= static_cast<int>(distance * distance));
}

void NPC::subscribe(std::shared_ptr<Observer> observer)
{
    observers.push_back(observer);
}

void NPC::fight_notify(NPC &defender, bool win)
{
    for (auto &o : observers)
    {
        o->on_fight(*this, defender, win);
    }
}

NpcType NPC::get_type()
{
    return type;
}

bool NPC::is_alive()
{
    std::lock_guard<std::mutex> lck(mtx);
    return alive;
}

void NPC::must_die()
{
    std::lock_guard<std::mutex> lck(mtx);
    alive = false;
}

std::ostream &operator<<(std::ostream &os, NPC &npc)
{
    os << npc.position << " ";
    return os;
}

void NPC::move(int shift_x, int shift_y, int max_x, int max_y)
{
    std::lock_guard<std::mutex> lck(mtx);
    int move_distance = 0;

    if (this->type == WanderingKnightType)
    {
        move_distance = 30; // Уменьшено для плавного перемещения
    }
    else if (this->type == SquirrelType)
    {
        move_distance = 5; // Белки перемещаются медленнее
    }
    else if (this->type == SlaveTraderType)
    {
        move_distance = 10; // Работорговцы тоже перемещаются медленно
    }

    // Расчет нового положения с учетом move_distance
    int new_x = position.x_ + move_distance * shift_x;
    int new_y = position.y_ + move_distance * shift_y;

    // Ограничиваем координаты в пределах карты
    position.x_ = std::max(0, std::min(max_x, new_x));
    position.y_ = std::max(0, std::min(max_y, new_y));
}
