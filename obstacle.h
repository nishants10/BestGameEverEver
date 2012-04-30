#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <QImage>
#include <QRect>
//base class
class obstacle
{
    public:
        obstacle();
        virtual ~obstacle();//virtual functions
        QRect getRect();
        void setRect(QRect);
        QImage &getImage();
        //virtual functions
        virtual void automove();
        virtual void resetstate();

    protected:
    //protected variables
        QImage image;
        QRect rect;
        int xdir;
        int x, y;
    private:


};

#endif // OBSTACLE_H
