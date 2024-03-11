#ifndef BATS_H
#define BATS_H

#include "Event.h"

using namespace std;

class Bats : public Event {
public:
    Bats(); // Declare the constructor
    void encounter() override;
    string percept() const override;
    void triggerConfusion();
    bool isConfused() const;
    void decrementConfusion();

private:
    int confusionCounter;
};

#endif // BATS_H
