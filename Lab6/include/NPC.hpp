#ifndef NPC_H
#define NPC_H

#include <string>
#include "Observer.hpp"

class Visitor;
class Observer;

class NPC {
public:
    virtual ~NPC() {}
    virtual std::string getType() const = 0;
    virtual void accept(Visitor& visitor) = 0;
    virtual void setName(const std::string& name) = 0;
    virtual std::string getName() const = 0;
    virtual void setCoordinates(int x, int y) = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
};

#endif