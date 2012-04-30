#ifndef FLOATWALL_H
#define FLOATWALL_H

#include <obstacle.h>


class floatwall : public obstacle
{
    public:
        floatwall();
        virtual ~floatwall();
        void automove();
        void resetstate();
    protected:
    private:
};

#endif // FLOATWALL_H
