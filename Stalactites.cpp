#include "Stalactites.h"
#include <iostream>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For time to seed random

using namespace std;

Stalactites::Stalactites() {
    srand(static_cast<unsigned int>(time(nullptr)));  // Seed random number generator
    
}

bool Stalactites::doTheyFall() {
    return rand() % 2 == 0; // 50% chance for true (fall) or false (not fall)
}

void Stalactites::encounter() {
    int chance = rand() % 2;  // Randomly generates 0 or 1

    if (chance == 0) {
        cout << "Stalactites fall and you lose." << endl;
    } else {
        cout << "Stalactites do not fall. You continue your journey." << endl;
    }
}

string Stalactites::percept() const {
    return "You hear water dripping.";
}
