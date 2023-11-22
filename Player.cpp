#include "Player.h"
#include <iostream>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

Player::Player(GameMechs* thisGMRef) {
   /* 
    playerPos.x = BOARD_WIDTH / 2;
    playerPos.y = BOARD_HEIGHT / 2;
    playerPos.symbol = '*'; // '*' represents the player
    playerDirection = STOP; // Initial direction is STOP
    // Other initialization code...
    */
    mainGameMechsRef = thisGMRef;
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, 
                        mainGameMechsRef->getBoardSizeY()/2, '*');
}

Player::~Player() {
    // Destructor implementation...
}

void Player::getPlayerPos(objPos& returnPos) {
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
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

    //mainGameMechsRef->drawObject(playerPos);
    
}

void Player::movePlayer() {

    //mainGameMechsRef->clearPosition(playerPos.x, playerPos.y);

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
    // Update the player's new position on the game board
   // mainGameMechsRef->drawObject(playerPos);
}

