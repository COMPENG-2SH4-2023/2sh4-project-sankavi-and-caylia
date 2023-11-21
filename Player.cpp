#include "Player.h"
#include <iostream>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

Player::Player(GameMechs* thisGMRef) {
    mainGameMechsRef = thisGMRef;
    playerPos.x = BOARD_WIDTH / 2;
    playerPos.y = BOARD_HEIGHT / 2;
    playerPos.symbol = '*'; // '*' represents the player
    playerDirection = STOP; // Initial direction is STOP
    // Other initialization code...
}

Player::~Player() {
    // Destructor implementation...
}

void Player::getPlayerPos(objPos& returnPos) {
    returnPos = playerPos;
}

void Player::updatePlayerDir() {
    char userInput = mainGameMechsRef->getInput(); // Assuming getUserInput() method in GameMechs class

    switch (userInput) {
        case 'w':
            if (playerDirection != DOWN) {
                playerDirection = UP;
            }
            break;
        case 's':
            if (playerDirection != UP) {
                playerDirection = DOWN;
            }
            break;
        case 'a':
            if (playerDirection != RIGHT) {
                playerDirection = LEFT;
            }
            break;
        case 'd':
            if (playerDirection != LEFT) {
                playerDirection = RIGHT;
            }
            break;
        case ' ': // Exit
            // Handle exit action...
            break;
        default:
            break;
    }
}

void Player::movePlayer() {

    std::cout << "Before movement - Player Pos X: " << playerPos.x << ", Y: " << playerPos.y << std::endl;
    switch (playerDirection) {
        case UP:
            if (playerPos.y > 1) {
                playerPos.y--;
            } else {
                playerPos.y = BOARD_HEIGHT - 2;
            }
            break;
        case DOWN:
            if (playerPos.y < BOARD_HEIGHT - 2) {
                playerPos.y++;
            } else {
                playerPos.y = 1;
            }
            break;
        case LEFT:
            if (playerPos.x > 1) {
                playerPos.x--;
            } else {
                playerPos.x = BOARD_WIDTH - 2;
            }
            break;
        case RIGHT:
            if (playerPos.x < BOARD_WIDTH - 2) {
                playerPos.x++;
            } else {
                playerPos.x = 1;
            }
            break;
        default:
            break;
    }

    std::cout << "After movement - Player Pos X: " << playerPos.x << ", Y: " << playerPos.y << std::endl;
}

