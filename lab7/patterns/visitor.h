#pragma once

#include <iostream>
#include "../npc/npc.h"
#include "../npc/wanderingKnight.h"
#include "../npc/slaveTrader.h"
#include "../npc/squirrel.h"
#include "observer.h"

class FightVisitor : public NPCVisitor
{
public:
    bool visit(WanderingKnight &defender, NPC &attacker) override;
    bool visit(SlaveTrader &defender, NPC &attacker) override;
    bool visit(Squirrel &defender, NPC &attacker) override;
};