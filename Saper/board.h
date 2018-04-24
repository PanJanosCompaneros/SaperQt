#ifndef BOARD_H
#define BOARD_H


class Board
{

public:
    Board();
    Board* exposeButton(int, int);
    bool alive;
private:
    int length, width;
    int number; // empty -> number=0; bomb->number=-1;
    int **buttons;
    int countBombsInNeighbourhood(int, int);
    void generateEmptyBoard();
    void generateBombs(int);
    void generateNumbers();
};

#endif // BOARD_H

