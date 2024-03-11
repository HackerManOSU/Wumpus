#include "Gold.h"
#include <iostream>

using namespace std;

Gold::Gold() : collected(false) {}

void Gold::encounter() {
    if (!collected) {
        cout << "You've found the gold and picked it up!" << endl;
        collected = true;
    }
}

string Gold::percept() const {
    return collected ? "" : "You see a glimmer nearby.";
}

bool Gold::isCollected() const {
    return collected;
}
