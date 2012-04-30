#ifndef LIFE_H
#define LIFE_H
#include "item.h"


class life:public item
{
    public:
        life();
        virtual ~life();
        void resetstate();
        void automove();
    protected:
    private:
};

#endif // LIFE_H
