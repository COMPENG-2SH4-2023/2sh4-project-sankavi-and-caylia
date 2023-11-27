#ifndef GAMEMECHS_H
#define GAMEMECHS_H
 
#include <cstdlib>
#include <ctime>
 
#include "objPos.h"
#include "objPosArrayList.h"
#include "Player.h"
 
using namespace std;
 
// Forward declaration of Player class
class Player;
 
class GameMechs
{
    // Construct the remaining declaration from the project manual.
 
    // Only some sample members are included here
 
    // You will include more data members and member functions to complete your design.
 
    private:
        objPos foodPos;
        char input;
        char tempInput;
        bool exitFlag;
        bool loseFlag;
        
        int score;
        int boardSizeX;
        int boardSizeY;
 
        int SLOWEST_SPEED;  
        int SLOW_SPEED;
        int INITIAL_SPEED;  
        int FAST_SPEED;
        int FASTEST_SPEED;  
 
        int speedLevel;
 
    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        //~GameMechs();
 
        //Food();
        //~Food();
        
        bool getExitFlagStatus();
        void setExitTrue();
 
        bool getLoseFlagStatus();
        void setLoseFlag();
 
        char getInput();
        void setInput(char this_input);
        void clearInput();
 
        int getBoardSizeX();
        int getBoardSizeY();
        int getScore();
 
        void incrementScore();
        void generateFood(objPosArrayList& playerPosList, const objPos& initialPos);   
        void getFoodPos(objPos& returnPos);
          
 
};
 
#endif