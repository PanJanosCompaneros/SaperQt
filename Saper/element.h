#ifndef ELEMENT_H
#define ELEMENT_H


struct Element{
    int value, x, y;
    bool visible;

    Element(){}
    Element(int a, int b){
        this->visible = false;
        this->x = a;
        this->y = b;
        this->value = 0;
    }

};


#endif // ELEMENT_H
