#include "obstacle.h"

obstacle::obstacle(){
    xdir = -2;
}

obstacle::~obstacle(){
    //std::cout <<("obstacle deleted\n");
}


QRect obstacle::getRect(){
    return rect;
}

void obstacle::setRect(QRect rct){
    rect = rct;
}
QImage &obstacle::getImage(){
    return image;
}

void obstacle::automove(){}
void obstacle::resetstate(){}
