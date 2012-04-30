#ifndef BULLET_H
#define BULLET_H
#include <QImage>
#include <QRect>
#include <cmath>

//bullet class, tracking conditions done in the game file
class bullet
{
    public:
        bullet();
        ~bullet();
        bullet(int,int);
        void automove(int, int);
        void resetstate();
        void resetstate(int, int);
        QRect getRect();
        QImage getImage();
    protected:
    private:
        QImage image;
        QRect rect;
};

#endif // BULLET_H
