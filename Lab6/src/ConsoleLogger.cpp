#include "ConsoleLogger.hpp"
#include <iostream>

void ConsoleLogger::update(const std::string& message) {
    std::cout << message << std::endl;
}