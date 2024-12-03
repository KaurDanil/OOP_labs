#include "CombatVisitor.hpp"
#include "NPC.hpp"
#include <cmath>
#include <iostream>

CombatVisitor::CombatVisitor(int combatRange, std::vector<std::unique_ptr<NPC>>& npcList)
    : combatRange(combatRange), npcList(npcList) {}

void CombatVisitor::visit(NPC& npc) {
    for (auto& other : npcList) {
        if (&npc == other.get() || toKill.find(other.get()) != toKill.end()) continue; // Skip self and NPCs marked for killing
        handleCombat(npc, *other);
    }
}

void CombatVisitor::handleCombat(NPC& attacker, NPC& defender) {
    if (&attacker == &defender) return; // Skip self

    if (canAttack(attacker, defender)) {
        if (shouldKill(attacker, defender)) {
            toKill.insert(&defender);
            notify(attacker.getName() + " killed " + defender.getName());
        }
    }
}

bool CombatVisitor::canAttack(const NPC& attacker, const NPC& defender) {
    int dx = attacker.getX() - defender.getX();
    int dy = attacker.getY() - defender.getY();
    return (dx * dx + dy * dy) <= combatRange * combatRange;
}

bool CombatVisitor::shouldKill(const NPC& attacker, const NPC& defender) {
    std::string attackerType = attacker.getType();
    std::string defenderType = defender.getType();

    if (attackerType == "SlaveTrader" && defenderType == "Squirrel") {
        return true;
    } else if (attackerType == "WanderingKnight" && defenderType == "SlaveTrader") {
        return true;
    } else if (attackerType == "Squirrel" && defenderType == "Squirrel") {
        return true;
    }
    return false;
}

void CombatVisitor::performCombat() {
    toKill.clear(); // Clear previous kills

    // Collect toKill set based on turn-based combat
    for (size_t i = 0; i < npcList.size(); ++i) {
        NPC& attacker = *npcList[i];
        if (toKill.find(&attacker) != toKill.end()) {
            continue; // Skip NPCs marked for killing
        }
        for (size_t j = 0; j < npcList.size(); ++j) {
            if (i == j) continue; // Skip self
            NPC& defender = *npcList[j];
            if (toKill.find(&defender) != toKill.end()) {
                continue; // Skip NPCs marked for killing
            }
            handleCombat(attacker, defender);
        }
    }

    // Remove killed NPCs
    std::vector<std::unique_ptr<NPC>> newNpcList;
    for (auto& npc : npcList) {
        if (toKill.find(npc.get()) == toKill.end()) {
            newNpcList.push_back(std::move(npc));
        }
    }
    npcList = std::move(newNpcList);
}