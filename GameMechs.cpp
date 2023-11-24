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

    // Ensure that the random seed is initialized once  
    static bool seedInitialized = false;
    if (!seedInitialized) {
        srand(static_cast<unsigned int>(time(nullptr))); // Use time as a seed for the random food generator
        seedInitialized = true;
    }

    int xRange = getBoardSizeX(); // Board width
    int yRange = getBoardSizeY(); // Board height

    // generating random character as food 
    char randomChar = 'A' + rand() % 26; // from A-Z

    // generating random spots (x and y coordinates) for the food
    do {
        // generating coordinates to stay within the border size
        int foodX = rand() % (xRange - 2) + 1;
        int foodY = rand() % (yRange - 2) + 1;

        // Checking if the generated coordinates overlap with the blocked-off position or border
        if ((foodX != blockOff.x || foodY != blockOff.y) && (foodX != 0 && foodY != 0 && foodX != xRange - 1 && foodY != yRange - 1)) {
            // If no overlap with block-off position or border, set the food position and exit the loop
            foodPos.x = foodX;
            foodPos.y = foodY;
            foodPos.symbol = randomChar; // Represents the randomly generated character
            break;
        }
        // If the coordinates overlap, generate new ones
    } while (true);
 
}


void GameMechs::getFoodPos(objPos& returnPos) {

    returnPos = foodPos; //returns current position of the food
}