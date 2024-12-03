#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "NPC.hpp"

class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(NPC& npc) = 0;
};

#endif