#include "GameMechs.h"
#include "MacUILib.h"
#include <ctime> 

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

void GameMechs::generateFood(objPos blockOff) {

    // ensuring that the random seed is initialized once
    static bool seedInitialized = false;
    if (!seedInitialized) {
        srand(static_cast<unsigned int>(time(nullptr))); // will use time as a seed for the random food generator
        seedInitialized = true;
    }

    int xRange = getBoardSizeX(); // board width
    int yRange = getBoardSizeY(); // board height

    // generating a random ASCII character for the food
    char randomChar = 'A' + rand() % 26; // will randomly generate a letter from A - Z, all uppercase

    // generating random x and y coordinates for the food
    do {
        // generates random x and y coordinates within the board size
        int foodX = rand() % (xRange - 1) + 1;
        int foodY = rand() % (yRange - 1) + 1;

        // checking if the generated coordinates overlap with the blocked off position 
        if (foodX != blockOff.x || foodY != blockOff.y) { // if no overlap, set the food position and exit the loop
            foodPos.x = foodX;
            foodPos.y = foodY;
            foodPos.symbol = randomChar; // represents the randomly generated character
            break;
        }
        // if the coordinates overlap, generate new ones  
    } while (true);
 
}


void GameMechs::getFoodPos(objPos& returnPos) {

    returnPos = foodPos; //returns current position of the food
}

