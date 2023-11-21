#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"



#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

using namespace std;

#define DELAY_CONST 100000



bool exitFlag;



// Create a GameBoard object
class GameBoard {
private:
    static const int width = 20; //creating the game board width 
    static const int height = 10; //creating the game board height
    char board[height][width]; // Game board

public:
    void initializeBoard() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                    board[i][j] = '#'; // Draw border with '#' character
                } else {
                    board[i][j] = ' '; //Initialize empty spaces inside the border
                }
            }
        }
    }

    void drawObject(const objPos &position) {
        board[position.y][position.x] = position.symbol; // Draw object symbol at given position
    }

    void displayBoard() {
        string display;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                display += board[i][j];
            }
            display += '\n';
        }
        // Display the string representation of the game board
        cout << display;
    }
};

// Forward declaration of GameMechs class
class GameMechs;

enum Direction {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

class Player {
private:
    // Define data members: position, direction, etc.
    // Direction enum (UP, DOWN, LEFT, RIGHT)
    objPos playerPos;   // Upgrade this in iteration 3.       
    enum Direction myDir;
 
    Direction playerDirection;
    GameMechs* mainGameMechsRef;

public:
    // Constructor and Destructor
    Player(GameMechs* thisGMRef);
    ~Player();

    // Method to retrieve player position
    void getPlayerPos(objPos &returnPos);
    void updatePlayerDir();
    void movePlayer();

};






void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

GameBoard game; 

// Global pointer to Player object
Player* playerPtr = nullptr;





int main(void)
{

    Initialize();

    // Call methods of the Player class as needed
    playerPtr->updatePlayerDir(); // Update player direction based on input
    playerPtr->movePlayer();



    while(exitFlag == false)  
    {
        GetInput();
        //playerPtr->updatePlayerDir(); // Update player direction based on input

        
        RunLogic();
        //playerPtr->movePlayer();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

    return 0;

}



void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;

    // Initialize the game board
    game.initializeBoard();

    // Create an instance of GameMechs (assuming it exists)
    GameMechs gameMechanics;

    playerPtr = new Player(&gameMechanics);

    objPos initialPos(BOARD_WIDTH / 2, BOARD_HEIGHT / 2, '@');
    playerPtr->getPlayerPos(initialPos);

    //delete playerPtr;


}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 

     // Drawing objects on the game board using objPos class
    objPos obj1(5, 5, 'A');
    objPos obj2(8, 3, 'B');

    // Draw objects on the game board
    game.drawObject(obj1);
    game.drawObject(obj2);

    // gettting the player's position and draw it on the game board
    objPos playerPosition;
    playerPtr->getPlayerPos(playerPosition);
    game.drawObject(playerPosition);


    // display the game board
    game.displayBoard();


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
