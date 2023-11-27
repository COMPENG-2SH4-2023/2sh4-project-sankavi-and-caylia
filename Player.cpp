#include "Player.h"
 
Player::Player(GameMechs *thisGMRef)
{
 
    //intializing the border sizes here
    int boardSizeX = thisGMRef->getBoardSizeX();
    int boardSizeY = thisGMRef->getBoardSizeY();
 
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    objPos tempPos;
    tempPos.setObjPos(boardSizeX / 2, boardSizeY / 2, '*');
 
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
 
    //For debugging purposes
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
 
 
    if (input != 0)
    {
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
 
    mainGameMechsRef->clearInput();
}
 
bool Player::checkFoodConsumption()
{
    // checking if the head overlaps with the food
    objPos current_head;
    playerPosList->getHeadElement(current_head);
 
    objPos foodPosition;
    mainGameMechsRef->getFoodPos(foodPosition);
 
    return (current_head.x == foodPosition.x && current_head.y == foodPosition.y);
}
 
void Player::increasePlayerLength()
{
    // inserting a new position at the tail to increase the player length
    objPos tailPosition;
    playerPosList->getTailElement(tailPosition);
    playerPosList->insertTail(tailPosition);
}
 
 
void Player::movePlayer()
{
 
    //holding the posintion info of the current head of player
    objPos current_head;
    playerPosList->getHeadElement(current_head);
 
    int BOARD_WIDTH = mainGameMechsRef->getBoardSizeX();
    int BOARD_HEIGHT = mainGameMechsRef->getBoardSizeY();
 
    switch (myDir)
    {
    case UP:
        // decrementing/wraparound feature
        current_head.y = (current_head.y > 1) ? current_head.y - 1 : BOARD_HEIGHT - 2;
        break;
    case DOWN:
        // incrementing/wraparound feature
        current_head.y = (current_head.y < BOARD_HEIGHT - 2) ? current_head.y + 1 : 1;
        break;
    case LEFT:
        // decrementing/wraparound feature
        current_head.x = (current_head.x > 1) ? current_head.x - 1 : BOARD_WIDTH - 2;
        break;
    case RIGHT:
        // incrementing/wraparound feature
        current_head.x = (current_head.x < BOARD_WIDTH - 2) ? current_head.x + 1 : 1;
        break;
    default:
        // handle an unexpected direction value (e.g., STOP)
        break;
    }
 
 
    if (checkFoodConsumption())
    {
        mainGameMechsRef->incrementScore(); // food is consumed, increase score
        increasePlayerLength(); // increase player length
        objPos initialPos;
        mainGameMechsRef->generateFood(*playerPosList, initialPos); // generating new food
    }
    else
    {
        // the new current head should be inserted to head of the list
        playerPosList->insertHead(current_head);
 
        // lastly remove the tail of the list
        playerPosList->removeTail();
    }
}
