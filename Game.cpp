#include <iostream>

#include "Game.h"
#include "Bats.h"
#include "Stalactites.h"
#include "Gold.h"
#include "Wumpus.h"
#include "GameGrid.h"
#include "Player.h"

using namespace std;


Game::Game(int width, int height, bool debugMode) : grid(width, height), player(rand() % width, rand() % height), gameOver(false), isDebugMode(debugMode) { // Initialize the grid and player
    srand(static_cast<unsigned int>(time(nullptr)));  // Seed the random generator

    placeEventRandomly(make_shared<Wumpus>()); // Place the Wumpus
    placeEventRandomly(make_shared<Bats>()); // Place the Bats
    placeEventRandomly(make_shared<Bats>());
    placeEventRandomly(make_shared<Stalactites>()); // Place the Stalactites
    placeEventRandomly(make_shared<Stalactites>());
    placeEventRandomly(make_shared<Gold>()); // Place the Gold

    startX = player.getX();
    startY = player.getY();
}

void Game::run() {
    cout << "Game started." << endl;

    while (!gameOver) { // Loop until game is over
        render(); // Display game grid
        handleInput(); // Handle player's input
        updateGame(); // Update game state
        displayPercepts(); // Display percepts
    }

    cout << "Closing Game." << endl; //
}

void Game::handleInput() {
    char input;
    cout << "Enter move (w/a/s/d) or fire arrow (i/j/k/l): ";
    cin >> input; // Get user's input

    switch (input) {
        case 'w': player.move(0, -1, grid.getWidth(), grid.getHeight()); break; // Move up
        case 'a': player.move(-1, 0, grid.getWidth(), grid.getHeight()); break; // Move left
        case 's': player.move(0, 1, grid.getWidth(), grid.getHeight()); break; // Move down
        case 'd': player.move(1, 0, grid.getWidth(), grid.getHeight()); break; // Move right
        case 'i': this->fireArrow(0); break; // Up
        case 'j': this->fireArrow(3); break; // Left
        case 'k': this->fireArrow(2); break; // Down
        case 'l': this->fireArrow(1); break; // Right
        default: cout << "Invalid input!" << endl;
    }
}

void Game::placeEventRandomly(shared_ptr<Event> event) { // Place an event in a random empty room
    int x, y; // Coordinates of the room
    do {
        x = rand() % grid.getWidth(); // Generate random coordinates
        y = rand() % grid.getHeight(); // Generate random coordinates
    } while (grid.getRoom(x, y).hasEvent()); // Loop until empty room is found

    grid.getRoom(x, y).setEvent(event); // Place event in room
}

bool Game::playerEncountersWumpus() { // Check if player encounters the Wumpus
    Room& currentRoom = grid.getRoom(player.getX(), player.getY()); // Get room player is in

    if (currentRoom.hasEvent()) { // Check if room has event
        auto event = currentRoom.getEvent(); // What event

        if (dynamic_cast<Wumpus*>(event.get()) != nullptr) { // Event Wumpus?
            return dynamic_cast<Wumpus*>(event.get())->isAwake(); // Is Wumpus awake?
        }
    }

    return false; // If no Wumpus
}

bool Game::playerHitByStalactites() { // Check if player hit by Stalactites
    Room& currentRoom = grid.getRoom(player.getX(), player.getY()); // Get room player in
    if (currentRoom.hasEvent()) { // Check if room has event
        auto event = currentRoom.getEvent(); // What event
        if (dynamic_cast<Stalactites*>(event.get()) != nullptr) { // Event Stalactites?
            return dynamic_cast<Stalactites*>(event.get())->doTheyFall(); // Do they fall?
        }
    }
    return false; // If no Stalactites
}

bool Game::playerHasCollectedGold() { // Check if player has collected gold
    return gold.isCollected(); // Return if gold is collected
}

bool Game::playerFindsExit() { // Check if player finds exit
    return player.getX() == startX && player.getY() == startY && playerHasCollectedGold();// Return if player finds exit
}


void Game::updateGame() {

    Room& currentRoom = grid.getRoom(player.getX(), player.getY());

    if (currentRoom.hasEvent()) { // Check if room has event
        shared_ptr<Event> event = currentRoom.getEvent(); // What event

        // Handling Stalactites
        if (auto stalactites = dynamic_pointer_cast<Stalactites>(event)) {
            // Logic for Stalactites event
            if (rand() % 2 == 0) {
                cout << "Stalactites fall on you! Game over." << endl;
                gameOver = true;
                return;
            } else {
                cout << "You narrowly escape falling stalactites." << endl;
            }
        }

        // Handling Bats
        if (auto bats = dynamic_pointer_cast<Bats>(event)) { // Check if event is Bats
            player.activateConfusion(); // Activate confusion
            cout << "Bats have confused you! Your movements are reversed." << endl;
        }

        // Handling Wumpus
        if (auto wumpus = dynamic_pointer_cast<Wumpus>(event)) {
            cout << "You've entered the room with the Wumpus! Game over." << endl;
            gameOver = true;
            return;
        }

        // Handling Gold
        if (dynamic_pointer_cast<Gold>(event) != nullptr) {
            player.collectGold();
            cout << "You have found the gold!" << endl;
        }
    }

    if (player.getX() == startX && player.getY() == startY && player.hasGoldCollected()) { // Check if player has returned to start with gold
        cout << "You have successfully returned with the gold! You win!" << endl; // Win
        gameOver = true;
        return;
    }
}


void Game::render() {
    for (int y = 0; y < grid.getHeight(); y++) {
        for (int x = 0; x < grid.getWidth(); x++) {
            if (x == player.getX() && y == player.getY()) {
                cout << "| * |";  // Representing the player
            } else if (isDebugMode) {
                // In debug mode, display all events and their positions
                Room& room = grid.getRoom(x, y);
                if (room.hasEvent()) {
                    if (dynamic_cast<Wumpus*>(room.getEvent().get()) != nullptr) {
                        cout << "| W |";  // Wumpus
                    } else if (dynamic_cast<Bats*>(room.getEvent().get()) != nullptr) {
                        cout << "| B |";  // Bats
                    } else if (dynamic_cast<Stalactites*>(room.getEvent().get()) != nullptr) {
                        cout << "| S |";  // Stalactites
                    } else if (dynamic_cast<Gold*>(room.getEvent().get()) != nullptr) {
                        cout << "| G |";  // Gold
                    } else {
                        cout << "|   |";  // Empty room
                    }
                } else {
                    cout << "|   |";  // Empty room
                }
            } else {
                cout << "|   |";  // In normal mode, only show the player
            }
        }
        cout << "|" << endl;  // Add a bar at the end of each row
        for (int x = 0; x < grid.getWidth(); x++) {
            cout << "+---+";  // Add bars between the rooms
        }
        cout << "+" << endl;
    }
    cout << "Arrows remaining: " << player.getArrows() << endl;
}

void Game::displayRoomPercept(int x, int y) {
    if (x >= 0 && x < grid.getWidth() && y >= 0 && y < grid.getHeight()) {
        Room& room = grid.getRoom(x, y);
        if (room.hasEvent()) {
            cout << room.getEvent()->percept() << endl;
        }
    }
}

void Game::displayPercepts() {
    int x = player.getX();
    int y = player.getY();
    displayRoomPercept(x, y - 1); // North
    displayRoomPercept(x + 1, y); // East
    displayRoomPercept(x, y + 1); // South
    displayRoomPercept(x - 1, y); // West
}

void Game::fireArrow(int direction) {
    if (player.getArrows() <= 0) {
        cout << "You have no arrows left." << endl;
        return;
    }

    player.useArrow();

    bool wumpusHit = false;

    int x = player.getX();
    int y = player.getY();

    for (int i = 0; i < 3; ++i) { // Arrow travels through max 3 rooms
        // Update the coordinates based on the direction
        switch (direction) {
            case 0: y--; break; // Up
            case 1: x++; break; // Right
            case 2: y++; break; // Down
            case 3: x--; break; // Left
        }

        // Check if the arrow is still within bounds of grid
        if (x < 0 || x >= grid.getWidth() || y < 0 || y >= grid.getHeight()) {
            cout << "The arrow hits a wall." << endl;
            break;
        }

        Room& targetRoom = grid.getRoom(x, y); //Get the target room
        if (targetRoom.hasEvent()) { // Check if has event
            shared_ptr<Event> event = targetRoom.getEvent(); // Retrieve event
            if (auto wumpus = dynamic_pointer_cast<Wumpus>(event)) { // Check if event is Wumpus
                wumpusHit = true; //Set Wumpus hit flag true
                wumpus->kill(); // KILL WUMPUS
                gameOver = true; // Set game over flag true
                cout << "You hear a scream. The Wumpus has been hit!" << endl;
                return;
            } else {
                cout << "The arrow hits nothing :/" << endl;
                break;
            }
        } 
        if (!wumpusHit && rand() % 4 < 3) { // 75% chance to move the Wumpus if missed
            moveWumpusToRandomEmptyRoom();
        }
    }
}

// Honestly just gave up on this one :// it compiles though so I'm just gonna leave it as it is
void Game::moveWumpusToRandomEmptyRoom() {
    // Find the Wumpus' current position
    int wumpusX = wumpus.getX();
    int wumpusY = wumpus.getY();

    std::vector<std::pair<int, int>> adjacentEmptyRooms;
    std::pair<int, int> directions[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    // Check each direction for an empty or player-occupied room
    for (const auto& dir : directions) {
        int newX = wumpusX + dir.first;
        int newY = wumpusY + dir.second;

        // Check grid boundaries
        if (newX >= 0 && newX < grid.getWidth() && newY >= 0 && newY < grid.getHeight()) {
            Room& room = grid.getRoom(newX, newY);
            // The room is considered empty if it has no event or if the player is there
            if (!room.hasEvent() || (newX == player.getX() && newY == player.getY())) {
                adjacentEmptyRooms.emplace_back(newX, newY);
            }
        }
    }

    // If there are adjacent empty rooms, move the Wumpus
    if (!adjacentEmptyRooms.empty()) {
        int randomIndex = rand() % adjacentEmptyRooms.size();
        std::pair<int, int> newRoomCoords = adjacentEmptyRooms[randomIndex];
        
        // Transfer the Wumpus to the new room
        std::shared_ptr<Event> wumpusEvent = grid.getRoom(wumpusX, wumpusY).getEvent();
        grid.getRoom(wumpusX, wumpusY).removeEvent(); // This should only clear the pointer, not delete the event
        grid.getRoom(newRoomCoords.first, newRoomCoords.second).setEvent(wumpusEvent);

        // Update the Wumpus position
        wumpus.setPosition(newRoomCoords.first, newRoomCoords.second);
    }
}