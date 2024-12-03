#include <iostream>
#include "../include/Subject.hpp"
#include <algorithm>

void Subject::attach(Observer* observer) {
    observers.push_back(observer);
}

void Subject::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify(const std::string& message) {
    std::cout << "Notifying observers about: " << message << std::endl;
    for (auto observer : observers) {
        observer->update(message);
    }
}