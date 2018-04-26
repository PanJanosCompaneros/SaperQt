#ifndef BOARD_H
#define BOARD_H


class Board
{

public:
    Board();
    Board* exposeButton(int, int);
    bool alive;
    int getValue(int,int);
    ~Board();
    //metoda hideButtons();  // zeby zaciemnic na poczatku
    //metoda isVisible();    // zeby sprawdzic, czy dany klocek jest wciaz zaciemniony (wciaz nieodkryty)
private:
    int length, width;
    int number; // empty -> number=0; bomb->number=-1;
    int buttons[8][8];
    bool visible[8][8];
    int countBombsInNeighbourhood(int, int);
    void generateEmptyBoard();
    void generateBombs(int);
    void generateNumbers();
};

#endif // BOARD_H

