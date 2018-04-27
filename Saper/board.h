#ifndef BOARD_H
#define BOARD_H
#include "element.h"

class Board
{

public:
    Board();
    bool alive;
    ~Board();
    //metoda hideButtons();  // zeby zaciemnic na poczatku
    //metoda isVisible();    // zeby sprawdzic, czy dany klocek jest wciaz zaciemniony (wciaz nieodkryty)
    Element getElement(int, int);
    void exposeElement(int, int);//
    // int howMuchLeft();
private:
    void exposeEmptyFields(int, int);
    //int fieldsToBeExposed;
    Element elements[8][8];
    int length, width;
    int number; // empty -> number=0; bomb->number=-1;

    int countBombsInNeighbourhood(int, int);
    void generateEmptyBoard();
    void generateBombs(int);
    void generateNumbers();
};

#endif // BOARD_H

