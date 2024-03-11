#ifndef GAMEGRID_H
#define GAMEGRID_H

#include <vector>
#include "Room.h"

using namespace std;

class GameGrid {
public:
    GameGrid(int width, int height);
    Room& getRoom(int x, int y);
    void displayGrid() const;  // For debug mode
    int getWidth() const;
    int getHeight() const;

private:
    int width, height;
    vector<vector<Room>> grid;
};

#endif // GAMEGRID_H
