#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H

#include "Observer.hpp"

class ConsoleLogger : public Observer {
public:
    void update(const std::string& message) override;
};

#endif