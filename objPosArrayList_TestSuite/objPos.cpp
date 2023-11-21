#include "objPos.h"
#include <iostream>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

objPos::objPos()
{
    x = 0;
    y = 0;
    symbol = 0; //NULL
}

objPos::objPos(objPos &o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}


objPos::objPos(int xPos, int yPos, char sym)
{
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
    return (refPos->x == x && refPos->y == y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos)
{
    if(isPosEqual(refPos))
        return getSymbol();
    else
        return 0;
}
void DrawGameBoard() {
    objPos positions[BOARD_WIDTH * BOARD_HEIGHT];

    // Draw the border of the game board with '#'
    for (int i = 0; i < BOARD_WIDTH; ++i) {
        positions[i].setObjPos(i, 0, '#'); // Top border
        positions[i + BOARD_WIDTH * (BOARD_HEIGHT - 1)].setObjPos(i, BOARD_HEIGHT - 1, '#'); // Bottom border
    }

    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        positions[i * BOARD_WIDTH].setObjPos(0, i, '#'); // Left border
        positions[i * BOARD_WIDTH + (BOARD_WIDTH - 1)].setObjPos(BOARD_WIDTH - 1, i, '#'); // Right border
    }

    // Draw a few ASCII characters on the game board with arbitrary positions and symbols
    positions[5 * BOARD_WIDTH + 5].setObjPos(5, 5, '@');
    positions[7 * BOARD_WIDTH + 3].setObjPos(3, 7, '$');

    // Display the game board
    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            std::cout << positions[i * BOARD_WIDTH + j].getSymbol() << " ";
        }
        std::cout << std::endl;
    }
}





