#include "Player.h"
#include <iostream>
 
Player::Player(GameMechs *thisGMRef)
{
 
    //Intializing the border sizes 
    int boardSizeX = thisGMRef->getBoardSizeX();
    int boardSizeY = thisGMRef->getBoardSizeY();
 
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    objPos tempPos;
    tempPos.setObjPos(boardSizeX / 2, boardSizeY / 2, '*');
 
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
 
    //For debugging purposes and checking various size of snake body 
    //playerPosList->insertHead(tempPos);
    //playerPosList->insertHead(tempPos);
    //playerPosList->insertHead(tempPos);
 
}
 
Player::~Player()
{
    //Deconstructor
    delete playerPosList;
}
 
objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
}
 
 
void Player::updatePlayerDir()
{
 
    //PPA3 concept used here for WSAD key inputs
    char input = mainGameMechsRef->getInput();
 
    // Check if there is a valid input
    if (input != 0)
    {
        // Switch statement to handle player direction based on current direction
        switch (myDir)
        {
        case STOP:
            switch (input)
            {
            case 'w':
                myDir = UP;
                break;
            case 's':
                myDir = DOWN;
                break;
            case 'a':
                myDir = LEFT;
                break;
            case 'd':
                myDir = RIGHT;
                break;
            }
            break;
 
        case UP:
        case DOWN:
            // Change direction when the player is moving vertically (up or down)
            switch (input)
            {
            case 'a':
                myDir = LEFT;
                break;
            case 'd':
                myDir = RIGHT;
                break;
            }
            break;
 
        case LEFT:
        case RIGHT:
            // Change direction when the player is moving horizontally (left or right)
            switch (input)
            {
            case 'w':
                myDir = UP;
                break;
            case 's':
                myDir = DOWN;
                break;
            }
            break;
        }
    }
    // Clear the input after handling player direction, avoid multiple movements with a single input
    mainGameMechsRef->clearInput();
}
 
bool Player::checkFoodConsumption()
{
    // Checking if the head overlaps with the food
    objPos current_head;
    playerPosList->getHeadElement(current_head);
 
    objPos foodPosition; // Getting current position of the snakes head
    mainGameMechsRef->getFoodPos(foodPosition);// Getting the position of the food

    // Return true if the head's position matches the food's position
    return (current_head.x == foodPosition.x && current_head.y == foodPosition.y);
}
 
void Player::increasePlayerLength()
{
    // Inserting a new position at the tail to increase the player length
    objPos tailPosition;
    playerPosList->getTailElement(tailPosition);
    playerPosList->insertTail(tailPosition);
}

bool Player::checkSelfCollision() {
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);

    // Get the current position of the head 
    int headX = currentHead.x;
    int headY = currentHead.y;

    // Start checking collision from the second segment, index 1
    for (int i = 1; i < playerPosList->getSize(); ++i) {
        objPos segment;
        playerPosList->getElement(segment, i);

        // Check if the head's position matches any segment's position in the snake's body
        if (headX == segment.x && headY == segment.y) {
            // Check if the snakes length is greater than 2
            if (playerPosList->getSize() > 2) {
                mainGameMechsRef->setLoseFlag(); // Set lose flag to end the game
                mainGameMechsRef->setExitTrue(); // Set exit flag to exit the game loop
                return true; // Collision detected
            } else {
                // The snake has not moved and collision is due to its length being less than 2 after consuming food
                // Reset the head position to avoid immediate collision
                playerPosList->removeHead();
                playerPosList->insertHead(currentHead);
                return false;
            }
        }
    }

    return false; // No collision detected

}


 
void Player::movePlayer()
{
 
    // Holding the position information of the current head of player
    objPos current_head;
    playerPosList->getHeadElement(current_head);
 
    int BOARD_WIDTH = mainGameMechsRef->getBoardSizeX();
    int BOARD_HEIGHT = mainGameMechsRef->getBoardSizeY();
 
    switch (myDir)
    {
    case UP:
        // Decrementing/wraparound feature
        current_head.y = (current_head.y > 1) ? current_head.y - 1 : BOARD_HEIGHT - 2;
        break;
    case DOWN:
        // Incrementing/wraparound feature
        current_head.y = (current_head.y < BOARD_HEIGHT - 2) ? current_head.y + 1 : 1;
        break;
    case LEFT:
        // Decrementing/wraparound feature
        current_head.x = (current_head.x > 1) ? current_head.x - 1 : BOARD_WIDTH - 2;
        break;
    case RIGHT:
        // Incrementing/wraparound feature
        current_head.x = (current_head.x < BOARD_WIDTH - 2) ? current_head.x + 1 : 1;
        break;
    default:
        // Handle an unexpected direction value (e.g. STOP)
        break;
    }
 
    if (!checkSelfCollision()) {
        
        if (checkFoodConsumption())
        {
            mainGameMechsRef->incrementScore(); // Food is consumed, increase score
            increasePlayerLength(); // Increase player length
            objPos initialPos;
            mainGameMechsRef->generateFood(*playerPosList, initialPos); // Generating new food
        }
        else
        {
            // The new current head should be inserted to head of the list
            playerPosList->insertHead(current_head);
 
            // Lastly remove the tail of the list
            playerPosList->removeTail();
        }
    }
}
