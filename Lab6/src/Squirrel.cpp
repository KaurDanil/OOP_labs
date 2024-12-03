#include "../include/Squirrel.hpp"

Squirrel::Squirrel(const std::string& name, int x, int y)
    : name(name), x(x), y(y) {}

std::string Squirrel::getType() const {
    return "Squirrel";
}

void Squirrel::accept(Visitor& visitor) {
    // Placeholder for accept method
}

void Squirrel::setName(const std::string& name) {
    this->name = name;
}

std::string Squirrel::getName() const {
    return name;
}

void Squirrel::setCoordinates(int x, int y) {
    this->x = x;
    this->y = y;
}

int Squirrel::getX() const {
    return x;
}

int Squirrel::getY() const {
    return y;
}