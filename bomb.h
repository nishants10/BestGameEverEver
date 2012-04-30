#ifndef BOMB_H
#define BOMB_H
#include "item.h"

//bombs that fall from the sky inherits from item
class bomb:public item
{
    public:
        bomb();
        virtual ~bomb();
        void resetstate();
        void automove();
    protected:
    private:
};

#endif // bomb_H
