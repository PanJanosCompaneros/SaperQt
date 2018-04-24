#include "board.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Board::Board()
{
    this->alive = true;
    this->width =10;
    this->length =10;
    this->buttons = new int*[length];
    for (int i =0; i < length; ++i){
        buttons[i]= new int[width];
    }
    generateEmptyBoard();
    generateBombs(10);
    generateNumbers();


}

Board* Board::exposeButton(int a, int b){
    if (this->buttons[a][b] ==0)
        this->alive = false;

    return this;
}

void Board::generateEmptyBoard(){
    for (int i = 0 ; i < width; ++i)
        for (int j = 0; j < length; ++j){
            this->buttons[i][j] =0;
        }
}
int Board::countBombsInNeighbourhood(int x, int y){
    int result = 0;
    int left=x-1, right=x+1, top=y-1, bottom=y+1;
    if (left<0) left =0;
    if (top<0) top =0;
    if (right>7) right =7;
    if (bottom>7) bottom = 7;
    for (int i = left; i < right+1; ++i){
        for (int j = top; j < bottom+1; ++j){
            if ((i==x) && (j==y)) continue;
            if (this->buttons[i][j] ==-1) result++;
        }
    }
    return result;
}
void Board::generateBombs(int howManyBombs){
    srand(time(0));
    int i = 0;
    int x,y;
    while (i<howManyBombs){
        x = rand()%8;
        y = rand()%8;
        if (this->buttons[x][y] == -1) continue;
        else {
            this->buttons[x][y] =-1;
            ++i;
        }
    }
}
void Board::generateNumbers(){
    for (int i = 0; i < 8; ++i)
        for (int j=0; j<8; ++j){
            this->buttons[i][j] = countBombsInNeighbourhood(i,j);
        }
}
