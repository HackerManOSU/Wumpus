#include "Bats.h"
#include <iostream>

using namespace std;

Bats::Bats() : confusionCounter(0) {} // Bats constructor, initialize confusionCounter to 0

void Bats::encounter() {
    cout << "You've encountered super bats. They confuse you, reversing your movement direction." << endl;
    triggerConfusion();
}

string Bats::percept() const {
    return "You hear wings flapping.";
}

void Bats::triggerConfusion() {
    confusionCounter = 5;
}

bool Bats::isConfused() const {
    return confusionCounter > 0;
}

void Bats::decrementConfusion() { //decrement confusion counter if > 0
    if (confusionCounter > 0) {
        confusionCounter--;
    }
}

