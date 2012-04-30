#include "life.h"

life::life()
{
    image.load("life.png");
    rect = image.rect();
    resetstate();
}

life::~life(){}

void life::resetstate(){
    int p = ((rand()%200)+400);
    int z =((rand()%10)+10);
    rect.moveTo(p,z);
}
void life::automove(){
    rect.translate(-2,1);
}
