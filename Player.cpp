#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(int startX, int startY) : x(startX), y(startY), arrows(3), confusionCounter(0) {}

void Player::move(int dx, int dy, int gridWidth, int gridHeight) {

    if (confusionCounter > 0) {
        dx = -dx;
        dy = -dy;
        confusionCounter--;
    }
    int newX = x + dx;
    int newY = y + dy;

    // Check boundaries
    if (newX >= 0 && newX < gridWidth && newY >= 0 && newY < gridHeight) {
        x = newX;
        y = newY;
    } else {
        cout << "Cannot move outside the grid." << endl;
    }
}

void Player::useArrow() {
    if (arrows > 0) {
        arrows--;
    }
}

int Player::getArrows() const {
    return arrows;
}

void Player::activateConfusion() {
    confusionCounter = 5;  // Set confusion for 5 turns
}

void Player::reverseMoveDirection() {
    // Reverse the move direction for the next turn
    if (confusionCounter > 0) {
        confusionCounter--;
    }
}

int Player::getX() const {
    return x;
}

int Player::getY() const {
    return y;
}

void Player::collectGold() {
    hasGold = true;
}

bool Player::hasGoldCollected() const {
    return hasGold;
}
