#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event {
public:
    virtual ~Event() = default; //Virtual destructor
    virtual void encounter() = 0; // Pure virtual function for encounter
    virtual std::string percept() const = 0; // Pure virtual function for percept
};

#endif // EVENT_H
