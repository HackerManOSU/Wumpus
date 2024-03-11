#include "Wumpus.h"
#include <iostream>

using namespace std;

Wumpus::Wumpus() : awake(false), alive(true) {}

void Wumpus::encounter() {
    if (awake) {
        cout << "The Wumpus is awake and eats you. Game over!" << endl;
    } else {
        cout << "You've encountered a sleeping Wumpus." << endl;
    }
}

string Wumpus::percept() const {
    return "You smell a terrible stench.";
}

void Wumpus::wakeUp(bool arrowMissed) {
    if (arrowMissed) {
        awake = (rand() % 4) < 3;
    } else {
        awake = true;
    }
}

bool Wumpus::isAwake() const {
    return awake;
}

void Wumpus::kill() {
    alive = false;
    cout << "Game Over! You Win!" << endl;
}

int Wumpus::getX() const {
    return x;
}

int Wumpus::getY() const {
    return y;
}

void Wumpus::setPosition(int newX, int newY) {  // Set the position of the Wumpus to the specified x and y coordinates.

    x = newX;
    y = newY;
}
