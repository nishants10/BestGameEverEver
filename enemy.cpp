#include "enemy.h"

enemy::enemy(){
    image.load("enemy.png");
    rect = image.rect();
    resetstate();
    xdir = -3;
}

enemy::~enemy(){
    //dtor
}

void enemy::resetstate(){
    int k = (rand()%200)+ 100;
    rect.moveTo(999,k);
    xdir = -3 ;
}

void enemy::automove(){
    xdir = -3;
    rect.translate(xdir, 0);
}
