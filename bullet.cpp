#include "bullet.h"
bullet::bullet(){
    image.load("bullet.png");
    rect = image.rect();
    resetstate();
}
bullet::bullet(int x, int y){
    image.load("bullet.png");
    rect = image.rect();
    resetstate(x,y);

}
bullet::~bullet(){}

void bullet::resetstate(){
    rect.moveTo(700, 200);
}
void bullet::resetstate(int x, int y){
    rect.moveTo(x,y);
}
void bullet::automove(int xdir, int ydir){
    rect.translate(xdir,ydir);
}

QImage bullet::getImage(){
    return image;
}
QRect bullet::getRect(){
    return rect;
}
