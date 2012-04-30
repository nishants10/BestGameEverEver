#include "item.h"

item::item()
{

}

item::~item()
{
    //dtor
}
void item::resetstate(){}

QRect item::getRect(){
    return rect;
}

void item::setRect(QRect rct){
    rect = rct;
}

QImage &item::getImage(){
    return image;
}
void item::automove(){}
