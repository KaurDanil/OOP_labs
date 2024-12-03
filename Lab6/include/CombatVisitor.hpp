#ifndef COMBAT_VISITOR_HPP
#define COMBAT_VISITOR_HPP

#include "Visitor.hpp"
#include "Subject.hpp"
#include "NPC.hpp"
#include <set>
#include <string>
#include <vector>
#include <memory>

class CombatVisitor : public Subject, public Visitor {
public:
    CombatVisitor(int combatRange, std::vector<std::unique_ptr<NPC>>& npcList);
    void visit(NPC& npc) override;
    void handleCombat(NPC& attacker, NPC& defender);
    void performCombat();
    const std::set<NPC*>& getToKill() const { return toKill; }
private:
    int combatRange;
    std::vector<std::unique_ptr<NPC>>& npcList;
    std::set<NPC*> toKill;
    bool canAttack(const NPC& attacker, const NPC& defender);
    bool shouldKill(const NPC& attacker, const NPC& defender);
};

#endif