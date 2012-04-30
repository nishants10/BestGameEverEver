#ifndef DOUBLER_H
#define DOUBLER_H
#include "item.h"


class doubler:public item
{
    public:
        doubler();
        virtual ~doubler();
        void resetstate();
        void automove();
    protected:
    private:
};

#endif // doubler_H
