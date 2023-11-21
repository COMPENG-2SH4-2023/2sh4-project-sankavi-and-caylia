#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;

    score = 0; // initializing score
    boardSizeX = 30; // default board size
    boardSizeY = 15;

    SLOWEST_SPEED = 200000; // Delay in microseconds for speed level 1 (slowest)
    SLOW_SPEED = 150000;
    INITIAL_SPEED = 100000; // Represents 100 milliseconds (or 0.1 seconds) delay between game loops
    FAST_SPEED = 50000;
    FASTEST_SPEED = 20000;// Delay in microseconds for speed level 5 (fastest)

    speedLevel = 3; // Initial speed level is set to 3

}

GameMechs::GameMechs(int boardX, int boardY)
{

    input = 0;
    exitFlag = false;
    loseFlag = false;

    score = 0;
    boardSizeX = boardX;  
    boardSizeY = boardY;

    SLOWEST_SPEED = 200000; // Delay in microseconds for speed level 1 (slowest)
    SLOW_SPEED = 150000;
    INITIAL_SPEED = 100000; // Represents 100 milliseconds (or 0.1 seconds) delay between game loops
    FAST_SPEED = 50000;
    FASTEST_SPEED = 20000; // Delay in microseconds for speed level 5 (fastest)

    speedLevel = 3; // Initial speed level is set to 3

}

// do you need a destructor?

/*
GameMechs::~GameMechs() {
    // for adding cleanup code
}
*/

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}


bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}


char GameMechs::getInput()
{
    if (MacUILib_hasChar()) {
        tempInput = MacUILib_getChar();

        if (tempInput == 27) {
            exitFlag = 1; // Terminate program on escape key
        } else if (tempInput == '+') { // When + is pressed, speed will increase up the the max of 5
            if (speedLevel < 5) {
                speedLevel++;
            }
        } else if (tempInput == '-') { // When - is pressed, speed will decrease down the the min of 1
            if (speedLevel > 1) {
                speedLevel--;
            }
        } else {
            input = tempInput; // Update regular input
        }
    }
    return input;

}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
 input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::incrementScore() {

    score++;
}

