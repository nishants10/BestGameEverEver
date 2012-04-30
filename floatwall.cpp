#include "floatwall.h"

floatwall::floatwall(){
    image.load("floatwall.png");
    rect = image.rect();
    resetstate();
    xdir = -2;
}

floatwall::~floatwall(){
    //dtor
}

void floatwall::resetstate(){
    int k = (rand()%150)+ 75;
    rect.moveTo(999,k);
    xdir = -2;

}

void floatwall::automove(){
    xdir = -2;
    rect.translate(xdir, 0);

}
