#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.hpp"

class Subject {
public:
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify(const std::string& message);
private:
    std::vector<Observer*> observers;
};

#endif