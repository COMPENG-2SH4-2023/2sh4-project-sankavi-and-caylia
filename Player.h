#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

// Forward declaration of GameMechs class
class GameMechs;

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Direction {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state
        Direction playerDirection;
        GameMechs* mainGameMechsRef;

        Player(GameMechs* thisGMRef);
        ~Player();

        void getPlayerPos(objPos &returnPos); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();


    private:
        objPos playerPos;   // Upgrade this in iteration 3.       
        enum Direction myDir;
       

        


};

#endif