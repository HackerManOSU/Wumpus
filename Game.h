#ifndef GAME_H
#define GAME_H

#include "GameGrid.h"
#include "Player.h"
#include "Wumpus.h"
#include "Gold.h"

using namespace std;

class Game {
public:
    Game(int width, int height, bool debugMode);
    void run(); // Run the game

private:
    GameGrid grid; // The game grid object
    Player player; // The player onbject
    Wumpus wumpus; // The wumpus object
    Gold gold; // The gold object
    bool gameOver; // Whether the game is over or not
    bool isDebugMode; // Whether the game is in debug mode or not
    int startX, startY; // Starting position of the player

    void handleInput(); // Handle user input
    void updateGame(); // Update the game state
    void render(); // Render the game
    void displayPercepts(); // Display the percepts of the current room
    void displayRoomPercept(int x, int y); // Display the percepts of the room at the specified coordinates

    //Self explanatory
    void placeEventRandomly(shared_ptr<Event> event);
    void moveWumpusToRandomEmptyRoom();

    bool playerEncountersWumpus();
    bool playerHitByStalactites();
    bool playerHasCollectedGold();
    bool playerFindsExit();

    void fireArrow(int direction);

};

#endif // GAME_H
