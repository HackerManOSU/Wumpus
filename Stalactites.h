#ifndef STALACTITES_H
#define STALACTITES_H

#include "Event.h"

using namespace std;

class Stalactites : public Event {
public:
    Stalactites();
    void encounter() override;
    string percept() const override;
    bool doTheyFall();
};

#endif // STALACTITES_H
