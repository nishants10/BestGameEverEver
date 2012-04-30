#ifndef GAME_H
#define GAME_H
#include "chopper.h"
#include "floatwall.h"
#include "bullet.h"
#include "enemy.h"
#include "life.h"
#include "bomb.h"
#include "doubler.h"
#include "ceilwall.h"
#include <QWidget>
#include <QKeyEvent>
#include <iostream>
#include <cmath>
#include <sstream>

class game : public QWidget
{
    Q_OBJECT

    public: //public member functions
        game(QWidget *parent = 0);
        ~game();

    protected: //protected member functions
        void paintEvent(QPaintEvent *event);
        void timerEvent(QTimerEvent *event);
        void keyPressEvent (QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);

        void startGame();
        void pauseGame();
        void stopGame();
        void victory();
        void checkCollision();

    private: //variable
        int x; //counter
        int xdir, ydir, xchp, ychp; //used to help bullet track the chopper
        float ang; //used to help bullet track chopper
        int timerId; //timer variable
        //call the different objects
        chopper *Chop;
        floatwall *FW;
        bullet *Bul;
        enemy *enem;
        life *yolo;
        bomb *boom;
        doubler *two;
        ceilwall *ceil;
        int enemycount; //number of enemies
        //booleans that control different funtionalities
        bool gameOver;
        bool gameWon;
        bool gameStarted;
        bool paused;

        bool goingUp;//if chopper is going up, returns true
        bool bulletShot;//so that the chopper doesn't shoot again after bullet has just been shot
        bool juststarted;
        int bigcount;//global counter
        int Lives;
        int points;//counter that increments with the global counter
        int k;
        int maxcount,netcount;
        int Level;
        int fwcount;
        int counter;//level 2&3 counter
        bool doble;//boolean that returns true if your score has just been doubled
};

#endif // GAME_H
