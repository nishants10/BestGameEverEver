#include "bomb.h"

bomb::bomb()
{
    image.load("bomb.png");
    rect = image.rect();
    resetstate();
}

bomb::~bomb(){}

void bomb::resetstate(){
    int p = ((rand()%800)+100);
    int z =((rand()%10)+10);
    rect.moveTo(p,z);
}
void bomb::automove(){
    rect.translate(-2,1);
}
