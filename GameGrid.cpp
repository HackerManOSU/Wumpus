#include "GameGrid.h"
#include <iostream>

using namespace std;

GameGrid::GameGrid(int width, int height) : width(width), height(height) {
    grid.resize(height, vector<Room>(width));
}

Room& GameGrid::getRoom(int x, int y) {
    return grid[y][x];
}

void GameGrid::displayGrid() const {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[y][x].hasEvent()) {
                // If the current cell has event, display a representation of the event
                cout << "E ";
            } else {
                // If the current cell does not have an event, display a dot
                cout << ". ";
            }
        }
        cout << endl;
    }
}

int GameGrid::getWidth() const {
    return width;
}

int GameGrid::getHeight() const {
    return height;
}

