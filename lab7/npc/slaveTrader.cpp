#include "slaveTrader.h"

SlaveTrader::SlaveTrader(const Point<int> &position_) : NPC(position_, SlaveTraderType) {}

void SlaveTrader::print()
{
    std::cout << *this;
}

void SlaveTrader::print(std::ostream &os)
{
    os << *this;
}

void SlaveTrader::save(std::ostream &os)
{
    os << SlaveTraderType << std::endl;
    NPC::save(os);
}

bool SlaveTrader::accept(NPCVisitor &visitor, NPC &attacker)
{
    return visitor.visit(*this, attacker);
}

std::ostream &operator<<(std::ostream &os, SlaveTrader &slaveTrader)
{
    os << "SlaveTrader: " << *static_cast<NPC *>(&slaveTrader) << std::endl;
    return os;
}
