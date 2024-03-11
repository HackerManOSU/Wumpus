#ifndef GOLD_H
#define GOLD_H

#include "Event.h"

using namespace std;

class Gold : public Event {
public:
    Gold();
    void encounter() override;
    string percept() const override;
    bool isCollected() const;

private:
    bool collected;
};

#endif // GOLD_H
