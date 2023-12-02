#include "objPos.h"

objPos::objPos()
{
    // Intialization 
    x = 0;
    y = 0;
    symbol = 0; //NULL
}

objPos::objPos(objPos &o)
{
    // Copy constructor
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}


objPos::objPos(int xPos, int yPos, char sym)
{
     // Set to x,y,symbol to the provided value/character 
    x = xPos;
    y = yPos;
    symbol = sym;
}

void objPos::setObjPos(objPos o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    // Set to x,y,symbol to the provided value/character 
    x = xPos;
    y = yPos;
    symbol = sym;
}

void objPos::getObjPos(objPos &returnPos)
{
    returnPos.setObjPos(x, y, symbol);
}

char objPos::getSymbol()
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos)
{
    // Checking if coordinates are equal 
    return (refPos->x == x && refPos->y == y); 
}

char objPos::getSymbolIfPosEqual(const objPos* refPos)
{
    if(isPosEqual(refPos))
        return getSymbol(); // Return the sybmol if the coordinates match
    else
        return 0; // Return NULL otherwise 
}




