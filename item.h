#ifndef ITEM_H
#define ITEM_H
#include <stdlib.h>
#include <QImage>
#include <QRect>

class item
{
    public:
        item();
        virtual ~item();
        virtual void resetstate();
        virtual void automove();
        void setRect(QRect);
        QImage &getImage();
        QRect getRect();

    protected:
        QImage image;
        QRect rect;
        int xdir;
        int x, y;
    private:
};

#endif // ITEM_H
