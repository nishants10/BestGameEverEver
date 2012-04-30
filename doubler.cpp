#include "doubler.h"

doubler::doubler()
{
    image.load("doubler.png");
    rect = image.rect();
    resetstate();
}

doubler::~doubler(){}

void doubler::resetstate(){
    int p = ((rand()%700)+300);
    int z =((rand()%10)+400);
    rect.moveTo(p,z);
}
void doubler::automove(){
    rect.translate(-2,-1);
}
