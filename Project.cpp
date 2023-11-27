#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"
 
#define DELAY_CONST 100000
#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10
 
using namespace std;
 
 
 
bool exitFlag;
 
//Global Pointers
GameMechs* myGM;
Player* playerPtr = nullptr;
 
 
 
 
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
 
 
 
int main(void)
{
 
    Initialize();
 
 
    while(exitFlag == false)  
    {
        GetInput();
        //playerPtr->updatePlayerDir();
        RunLogic();
       // playerPtr->movePlayer();
        DrawScreen();
        LoopDelay();
    }
 
 
    CleanUp();
 
   // return 0;
}
 
 
 
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
 
    
    exitFlag = false;
    myGM = new GameMechs(BOARD_WIDTH, BOARD_HEIGHT); //make board size
    playerPtr = new Player(myGM);
 
    objPos initialPos(BOARD_WIDTH / 2, BOARD_HEIGHT / 2, '@');
 
    myGM->generateFood(*playerPtr->getPlayerPos(), initialPos);  // pass initialPos to generateFood
 
}
 
void GetInput(void)
{
 
   //myGM->getInput();
   //char input;
 
    /*// Debug-use key to clear old food and generate new one
    if (input == 't') {
        objPos playerPosList;
        playerPtr->getPlayerPos(playerPosList); // Get player position
        myGM->generateFood(playerPosList); // Generate new food position avoiding player's position
    }
    */
   
   
}
 
void RunLogic(void)
{
    playerPtr->updatePlayerDir();
    playerPtr->movePlayer();
    
    
}
 
void DrawScreen(void)
{
MacUILib_clearScreen();
 
    // Getting the entire snake position/body
    objPosArrayList *player_body = playerPtr->getPlayerPos();
    objPos temp_body;
 
    bool drawn;
 
    // Initialize the border and inner spaces and food in one entire for loop
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            drawn = false;
 
            // iteratating through the player body
            for (int k = 0; k < player_body->getSize(); k++)
            {
                player_body->getElement(temp_body, k);
                if (temp_body.x == j && temp_body.y == i)
                {
                    MacUILib_printf("%c", temp_body.symbol);
                    drawn = true;
                    break;
                }
            }
            // Check and draw food if not drawn by player
            if (!drawn)
            {
                objPos foodPosition;
                myGM->getFoodPos(foodPosition);
 
                if (foodPosition.x == j && foodPosition.y == i)
                {
                    MacUILib_printf("%c", foodPosition.symbol);
                    drawn = true;
                }
            }
 
            // next iteration if the player body is drawn
            if (drawn == true)
                continue;
 
            // Draw the boarder, similar to PPA2-3
            if (i == 0 || i == BOARD_HEIGHT - 1 || j == 0 || j == BOARD_WIDTH - 1)
            {
                MacUILib_printf("%c", '#');
            }
            // Drawing the inner blank spaces
            else
            {
                MacUILib_printf("%c", ' ');
            }
        }
        MacUILib_printf("\n");
    }
 
    MacUILib_printf("Current Score: %d\n", myGM->getScore()); // Display the current score
 
    MacUILib_printf("Player position: \n"); // Display the current player position
    for (int l = 0; l < player_body->getSize(); l++)
    {
        player_body->getElement(temp_body, l);
        MacUILib_printf("<%d,%d> symbol: %c\n", temp_body.x, temp_body.y, temp_body.symbol);
    }
 
    
}
 
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}
 
 
void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
 
 
    delete myGM;
    delete playerPtr;
}