#include "wanderingKnight.h"

WanderingKnight::WanderingKnight(const Point<int> &position_) : NPC(position_, WanderingKnightType) {}

void WanderingKnight::print()
{
    std::cout << *this;
}

void WanderingKnight::print(std::ostream &os)
{
    os << *this;
}

void WanderingKnight::save(std::ostream &os)
{
    os << WanderingKnightType << std::endl;
    NPC::save(os);
}

bool WanderingKnight::accept(NPCVisitor &visitor, NPC &attacker)
{
    return visitor.visit(*this, attacker);
}

std::ostream &operator<<(std::ostream &os, WanderingKnight &wanderingKnight)
{
    os << "WanderingKnight: " << *static_cast<NPC *>(&wanderingKnight) << std::endl;
    return os;
}
