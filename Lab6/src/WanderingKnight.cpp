#include "WanderingKnight.hpp"

WanderingKnight::WanderingKnight(const std::string& name, int x, int y)
    : name(name), x(x), y(y) {}

std::string WanderingKnight::getType() const {
    return "WanderingKnight";
}

void WanderingKnight::accept(Visitor& visitor) {
    // Placeholder for accept method
}

void WanderingKnight::setName(const std::string& name) {
    this->name = name;
}

std::string WanderingKnight::getName() const {
    return name;
}

void WanderingKnight::setCoordinates(int x, int y) {
    this->x = x;
    this->y = y;
}

int WanderingKnight::getX() const {
    return x;
}

int WanderingKnight::getY() const {
    return y;
}