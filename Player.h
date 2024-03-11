#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(int startX, int startY);
    void move(int dx, int dy, int gridWidth, int gridHeight);

    int getArrows() const; // Method to get the number of arrows

    void useArrow();


    int getX() const;
    int getY() const;

    void activateConfusion();
    void reverseMoveDirection(); // Method to handle confusion effect

    void collectGold();  // Method to handle gold collection

    bool hasGoldCollected() const;  // Getter for hasGold

private:
    int x, y;
    int arrows;
    int confusionCounter;
    bool hasGold;
};

#endif // PLAYER_H
