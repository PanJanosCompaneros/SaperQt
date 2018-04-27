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
    if (this->elements[a][b].value == -1) this->alive = false; // zamiast tego dac if(...) this->gameOver();
    if (this->elements[a][b].value == 0) exposeEmptyFields(a,b);//+
    this->elements[a][b].visible = true;
}

void Board::exposeEmptyFields(int x, int y)//
{
    if (this->elements[x][y].value != 0) return;
    if (this->elements[x][y].value ==0)
        this->elements[x][y].visible = true;
    //dla kazdego sasiada, ktory ISTNIEJE, jest NIEODKRYTY i ma wartosc ZERO, odkrywamy go i odpalamy dla niego te funkcje
    // teraz dla kazdego jego sasiada (N,NW,NE,S,SW,SE,E,W) jesli sasiad istnieje i ma value==0, odpal te metode
//    if(x-1 >= 0 && y-1 >= 0 && this->elements[x-1][y-1].value == 0 && this->elements[x-1][y-1].visible == false) {this->elements[x-1][y-1].visible = true; this->exposeEmptyFields(x-1,y-1);} ; // N W
//    if(x-1 >= 0 && y+1 < this->length && elements[x-1][y+1].value == 0 && this->elements[x-1][y+1].visible == false) {this->elements[x-1][y+1].visible=true; this->exposeEmptyFields(x-1,y+1);} // N E
    if(x-1 > 0 && this->elements[x-1][y].value == 0 && this->elements[x-1][y].visible==false) {this->elements[x-1][y].visible=true; this->exposeEmptyFields(x-1,y);} // N
//    if(x+1 < this->length && y-1 >= 0 && elements[x+1][y-1].value == 0 && this->elements[x+1][y-1].visible==false){this->elements[x+1][y-1].visible=true; this->exposeEmptyFields(x+1,y-1);}  // S W
//    if(x+1 < this->length  && y+1 < this->length && this->elements[x+1][y+1].value == 0 && this->elements[x+1][y+1].visible==false) {this->elements[x+1][y+1].visible=true; this->exposeEmptyFields(x+1,y+1);}// S E
    if(x+1 >= 0 && this->elements[x+1][y].value== 0 && this->elements[x+1][y].visible==false) {this->elements[x+1][y].visible=true; this->exposeEmptyFields(x+1,y);} // S
    if(y-1 >= 0 && this->elements[x][y-1].value == 0 && this->elements[x][y-1].visible==false){this->elements[x][y-1].visible=true; this->exposeEmptyFields(x,y-1);}  //W
    if(y+1 < this->length && this->elements[x][y+1].value == 0 && this->elements[x][y+1].visible==false) {this->elements[x][y+1].visible=true; this->exposeEmptyFields(x,y+1);} //E
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
