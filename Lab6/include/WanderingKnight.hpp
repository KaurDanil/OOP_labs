#ifndef WANDERINGKNIGHT_H
#define WANDERINGKNIGHT_H

#include "NPC.hpp"
#include "Subject.hpp"

class WanderingKnight : public NPC, public Subject {
public:
    WanderingKnight(const std::string& name, int x, int y);
    std::string getType() const override;
    void accept(Visitor& visitor) override;
    void setName(const std::string& name) override;
    std::string getName() const override;
    void setCoordinates(int x, int y) override;
    int getX() const override;
    int getY() const override;
private:
    std::string name;
    int x, y;
};

#endif