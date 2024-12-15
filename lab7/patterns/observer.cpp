#include "observer.h"

std::shared_ptr<Observer> ScreenObserver::get()
{
    static std::shared_ptr<Observer> instance(new ScreenObserver());
    return instance;
}

void ScreenObserver::on_fight(NPC &attacker, NPC &defender, bool win)
{
    if (win)
    {
        std::lock_guard<std::mutex> lck(print_mtx);
        std::cout << std::endl
                  << "Murder --------" << std::endl;
        std::cout << "Killer: ";
        attacker.print();
        std::cout << "Victim: ";
        defender.print();
    }
}
