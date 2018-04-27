#include "board.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */



Board::Board()
{
    this->alive = true;
    this->width =8;
    this->length =8;
    generateEmptyBoard();
    generateBombs(10);
    generateNumbers();

}

Board::~Board()
{

}

bool Board::isAlive()
{
    return this->alive;
}

Element Board::getElement(int a, int b)
{
    return this->elements[a][b];
}

void Board::exposeElement(int a, int b) //
{
    if (this->elements[a][b].visible == true) return;
    if (this->elements[a][b].value == -1) {
        this->elements[a][b].value = -2;
        this->gameOver();
    }
    if (this->elements[a][b].value == 0) exposeEmptyFields(a,b);//+
    this->elements[a][b].visible = true;
    this->fieldsToBeExposed--;
//    if(this->fieldsToBeExposed ==0) youwinthegameeeeeeeeeeeeeeee
}

int Board::howMuchLeft()
{
    return this->fieldsToBeExposed;
}

void Board::gameOver() //+
{
    this->alive = false;
    for (int i = 0 ; i < 8 ; ++i)
        for (int j = 0 ; j < 8 ; ++j)
            this->elements[i][j].visible=true;
}

void Board::exposeEmptyFields(int x, int y)//
{
    if (this->elements[x][y].value != 0) return;
    if (this->elements[x][y].value ==0)
        this->elements[x][y].visible = true;

    if(x-1 >= 0  && this->elements[x-1][y].visible==false) {
        this->elements[x-1][y].visible=true;
        if(this->elements[x-1][y].value == 0)
        this->exposeEmptyFields(x-1,y);
    } // N

    if(x+1 < this->length && this->elements[x+1][y].visible==false) {
        this->elements[x+1][y].visible=true;
        if(this->elements[x+1][y].value== 0)
        this->exposeEmptyFields(x+1,y);
    } // S

    if(y-1 >= 0 &&  this->elements[x][y-1].visible==false){
        this->elements[x][y-1].visible=true;
        if(this->elements[x][y-1].value == 0)
        this->exposeEmptyFields(x,y-1);
    }  //W

     if(y+1 < this->length &&  this->elements[x][y+1].visible==false) {
         this->elements[x][y+1].visible=true;
         if(this->elements[x][y+1].value == 0)
         this->exposeEmptyFields(x,y+1);
     } //E
}

int Board::countHowManyFieldsAreToBeExposed()// +
{
    int result = 64;  // there are 64 fields on the board

    for (int i = 0 ; i < 8 ; ++i)
        for (int j = 0 ; j < 8 ; ++j){
            if (this->elements[i][j].value == 0) --result;
        }
    return result;
}



void Board::generateEmptyBoard(){
    for (int i = 0 ; i < width; ++i)
        for (int j = 0; j < length; ++j){
            Element a(i,j);
            this->elements[i][j] = a;
        }
}
int Board::countBombsInNeighbourhood(int x, int y){
    if(elements[x][y].value==-1)return -1;
    int result = 0;
    if(x-1 >= 0 && y-1 >= 0) result += elements[x-1][y-1].value == -1 ; // N W
    if(x-1 >= 0 && y+1 < this->length) result += elements[x-1][y+1].value == -1; // N E
    if(x-1 > 0) result += elements[x-1][y].value == -1; // N
    if(x+1 < this->length && y-1 >= 0) result += elements[x+1][y-1].value == -1; // S W
    if(x+1 < this->length  && y+1 < this->length) result += elements[x+1][y+1].value == -1;// S E
    if(x+1 >= 0) result += elements[x+1][y].value== -1; // S
    if(y-1 >= 0) result += elements[x][y-1].value == -1; //W
    if(y+1 < this->length) result += elements[x][y+1].value == -1; //E

    return result;
}
void Board::generateBombs(int howManyBombs){
    srand(time(0));
    int i = 0;
    int x,y;
    while (i<howManyBombs){
        x = rand()%8;
        y = rand()%8;
        if (this->elements[x][y].value == -1) continue;
        else {
            this->elements[x][y].value =-1;
            ++i;
        }
    }
}
void Board::generateNumbers(){
    for (int i = 0; i < 8; ++i)
        for (int j=0; j<8; ++j){
            this->elements[i][j].value = countBombsInNeighbourhood(i,j);
        }
}
