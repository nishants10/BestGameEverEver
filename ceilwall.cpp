#include "ceilwall.h"

ceilwall::ceilwall(){
    image.load("ceilwall.png");
    rect = image.rect();
    resetstate();
    xdir = -3;
}

ceilwall::~ceilwall(){
    //dtor
}

void ceilwall::resetstate(){
    rect.moveTo(999,0);
    xdir = -3;

}

void ceilwall::automove(){
    xdir = -3;
    rect.translate(xdir, 0);

}
