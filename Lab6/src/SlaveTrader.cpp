#include "../include/SlaveTrader.hpp"

SlaveTrader::SlaveTrader(const std::string& name, int x, int y)
    : name(name), x(x), y(y) {}

std::string SlaveTrader::getType() const {
    return "SlaveTrader";
}

void SlaveTrader::accept(Visitor& visitor) {
    // Placeholder for accept method
}

void SlaveTrader::setName(const std::string& name) {
    this->name = name;
}

std::string SlaveTrader::getName() const {
    return name;
}

void SlaveTrader::setCoordinates(int x, int y) {
    this->x = x;
    this->y = y;
}

int SlaveTrader::getX() const {
    return x;
}

int SlaveTrader::getY() const {
    return y;
}