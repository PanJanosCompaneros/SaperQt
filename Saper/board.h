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
private:
    int length, width;
    int number; // empty -> number=0; bomb->number=-1;
    int buttons[8][8];
    int countBombsInNeighbourhood(int, int);
    void generateEmptyBoard();
    void generateBombs(int);
    void generateNumbers();
};

#endif // BOARD_H

