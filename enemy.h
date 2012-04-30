    #ifndef ENEMY_H
    #define ENEMY_H
    #include "obstacle.h"

//enemy plane header file, inherits from the obstacle
class enemy:public obstacle
{
    public:
        enemy();
        virtual ~enemy();
        //functions needed
        void automove();
        void resetstate();
    protected:
    private:
};

#endif // ENEMY_H
