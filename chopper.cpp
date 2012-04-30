#include "chopper.h"

chopper::chopper(){
    image.load("chopper.png");
    rect = image.rect();
    resetState();
    ydir = 3;
}
chopper::~chopper(){
    //std::cout <<("chopper deleted\n");
}

void chopper::resetState(){
    rect.moveTo(100,180);
    ydir = 3;
}

void chopper::moveUp(int up){
    if (rect.top() >= 2)
        rect.moveTo(rect.left(),up);
}
void chopper::autoMove(){
    ydir = 2;
    rect.translate(0,ydir);

}

QRect chopper::getRect(){
    return rect;
}

QImage & chopper::getImage(){
    return image;
}
