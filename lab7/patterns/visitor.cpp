#include "visitor.h"
#include "../npc/npc.h"

// Рыцарь убивает Работорговцев
bool FightVisitor::visit(WanderingKnight &defender, NPC &attacker)
{
    if (attacker.get_type() == SlaveTraderType && attacker.is_alive())
    {
        attacker.fight_notify(defender, true);
        return true;
    }
    attacker.fight_notify(defender, false);
    return false;
}

// Работорговец убивает Белок
bool FightVisitor::visit(SlaveTrader &defender, NPC &attacker)
{
    if (attacker.get_type() == SquirrelType && attacker.is_alive())
    {
        attacker.fight_notify(defender, true);
        return true;
    }
    attacker.fight_notify(defender, false);
    return false;
}

// Белка убивает только Белку
bool FightVisitor::visit(Squirrel &defender, NPC &attacker)
{
    if (attacker.get_type() == SquirrelType && attacker.is_alive())
    {
        attacker.fight_notify(defender, true);
        return true;
    }
    attacker.fight_notify(defender, false);
    return false;
}
