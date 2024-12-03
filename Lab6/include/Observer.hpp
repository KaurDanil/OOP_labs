#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

class Observer {
public:
    virtual ~Observer() {}
    virtual void update(const std::string& message) = 0;
};

#endif