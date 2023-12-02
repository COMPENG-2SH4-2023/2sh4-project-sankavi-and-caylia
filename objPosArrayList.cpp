#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.


objPosArrayList::objPosArrayList(int capacity) : sizeArray(capacity), sizeList(0) {
    if (sizeArray < 1) {
        sizeArray = ARRAY_MAX_CAP; // Default sizeArray if an invalid capacity is provided
    }
    aList = new objPos[sizeArray]; //Dynamically allocating memory 
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; //Deallocating memory 

}

int objPosArrayList::getSize()
{
    return sizeList; 

}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (sizeList < sizeArray) {
        for (int i = sizeList; i > 0; --i) {
            aList[i] = aList[i - 1]; //Shifting elements to right
        }
        aList[0] = thisPos; //Inserting the element at the head 
        sizeList++; //Increment the size of the list 
    }

}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (sizeList < sizeArray) {
        aList[sizeList] = thisPos; //Inserting the element at the tail
        sizeList++; //Increment the size of the list 
    }

}

void objPosArrayList::removeHead()
{
    if (sizeList > 0) {
        for (int i = 0; i < sizeList - 1; ++i) {
            aList[i] = aList[i + 1]; //Shifting elements to left
        }
        sizeList--; //Decrement the size of list 
    }
    
}

void objPosArrayList::removeTail()
{
    if (sizeList > 0) {
        sizeList--; //Decrement the size of list 
    }

}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    if (sizeList > 0) {
        returnPos = aList[0]; //Return element at the head 
    }

}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    if (sizeList > 0) {
        returnPos = aList[sizeList - 1]; //Return element at the tail
    }

}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    // Check if the index is valid within the list bounds
        if (index >= 0 && index < sizeList) {
        returnPos = aList[index];
    }


}