#ifndef CHOPPER_H
#define CHOPPER_H
#include <QImage>
#include <QRect>
#include <iostream>

class chopper
{
    public:
        chopper();
        virtual ~chopper();
        void resetState();
        void moveUp(int);
        void autoMove();
        QRect getRect();
        QImage &getImage();

    protected:
    private:
        QImage image;
        QRect rect;
        int speed;
        int ydir;
};

#endif // CHOPPER_H
