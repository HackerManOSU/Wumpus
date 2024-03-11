/////////////////////////////////////////////////////
// Author: Zane "BlackHatHackerOSU" Garvey
// Date: 11/28/2023
// Wumpus Game
// Objective: Kill the wumpus or find the gold and return to the startpoint
//////////////////////////////////////////////////////


#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int width, height;
    string debugInput;
    bool debugMode = false;

    cout << "Enter the width and height of the grid (minimum 4, maximum 50 for each):";
    cin >> width >> height;
    
    cout << "Enter debug mode (true/false): ";
    cin >> boolalpha >> debugMode; 

    // Validate input
    if (width < 4 || height < 4 || width > 50 || height > 50) {
        cout << "Invalid grid size. Please restart the game with valid dimensions." << endl;
        return 1;
    }

    Game game(width, height, debugMode); // Create Game object with the specified width, height, and debug mode
    game.run();

    return 0;
}
