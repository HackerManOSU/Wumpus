#ifndef WUMPUS_H
#define WUMPUS_H

#include "Event.h"
#include <string>

using namespace std;

class Wumpus : public Event {
public:
    Wumpus();
    void encounter() override;
    string percept() const override; // Override of the percept() function from the base class Event
    void wakeUp(bool arrowMissed);
    bool isAwake() const;
    void kill();

    int getX() const; // Function to get the x-coordinate of the Wumpus
    int getY() const; // Function to get the y-coordinate of the Wumpus

    void setPosition(int x, int y);

private:
    bool awake;
    bool alive;
    int x, y;
};

#endif // WUMPUS_H
