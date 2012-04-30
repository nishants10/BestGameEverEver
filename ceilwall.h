#ifndef CEILWALL_H
#define CEILWALL_H

#include <obstacle.h>


class ceilwall : public obstacle
{
    public:
        ceilwall();
        virtual ~ceilwall();
        void automove();
        void resetstate();
    protected:
    private:
};

#endif // ceilwall_H
