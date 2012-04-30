#include "game.h"
#include <QPainter>
#include <QApplication>

game::game(QWidget *parent):QWidget (parent){
    {
        x = 0;
        //initialize boolean conditions
        gameOver = false;
        gameWon = false;
        paused = false;
        gameStarted = false;
        goingUp = false;
        doble = false;
        //initialize new objects
        Chop = new chopper();
        FW = new floatwall();
        enem = new enemy();
        boom = new bomb();
        Bul = new bullet(enem->getRect().x(),enem->getRect().y());
        yolo = new life();
        two = new doubler();
        ceil = new ceilwall();
        //initialize int variables
        Lives = 3;
        Level = 1;
        netcount = 0;
        enemycount = 0;
        points = 0;
        fwcount = 0;
        counter = 0;

    }
}

game::~game(){//destructor
    delete Chop;
    delete FW;
    delete enem;
    delete Bul;
}

void game::paintEvent(QPaintEvent *event){ //paints everything and creates the map with all the objects
    //paints different maps for different levels
    if (Level == 1){
        QPalette p = palette();
        QPixmap pixmap1("level1.png");
        QSize size(1000,400);
        QPixmap pixmap(pixmap1.scaled(size));
        p.setBrush(QPalette::Background, pixmap);
        setPalette(p);}
    else if (Level == 2){
    QPalette p = palette();
        QPixmap pixmap1("level2.png");
        QSize size(1000,400);
        QPixmap pixmap(pixmap1.scaled(size));
        p.setBrush(QPalette::Background, pixmap);
        setPalette(p);}
    else{
    QPalette p = palette();
        QPixmap pixmap1("level3.png");
        QSize size(1000,400);
        QPixmap pixmap(pixmap1.scaled(size));
        p.setBrush(QPalette::Background, pixmap);
        setPalette(p);}
    QPainter painter(this);
    if (gameOver){
        QFont font ("Courier", 15, QFont::DemiBold);
        QFontMetrics fm(font);
        int textWidth = fm.width("Game Over");

        painter.setFont(font);
        int h = height();
        int w = width();
        painter.translate(QPoint(w/2, h/2));
        painter.drawText(-textWidth/2, 0, "Game Over");
    }
      else if(gameWon) {
        QFont font("Courier", 15, QFont::DemiBold);
        QFontMetrics fm(font);
        int textWidth = fm.width("Victory");

        painter.setFont(font);
        int h = height();
        int w = width();

        painter.translate(QPoint(w/2, h/2));
        painter.drawText(-textWidth/2, 0, "Victory");
      }

      else {
          //print levels, lives, scores
        std::stringstream sout;
        painter.drawText(900,390,"Points: ");
        sout<<points;
        painter.drawText(960,390,QString(sout.str().c_str()));
        sout.str("");
        painter.drawText(900,370,"Lives: ");
        sout<<Lives;
        painter.drawText(960,370,QString(sout.str().c_str()));
        sout.str("");
        painter.drawText(900,350,"Level: ");
        sout<<Level;
        painter.drawText(960,350,QString(sout.str().c_str()));
        sout.str("");
        //paint all the objects
        if (Level > 1){
            painter.drawImage(ceil->getRect(), ceil->getImage());
            painter.drawImage(yolo->getRect() , yolo->getImage());
            painter.drawImage(boom->getRect(), boom->getImage());

            }
        painter.drawImage(enem->getRect(),enem->getImage());

        if (enem->getRect().x()<800){
            painter.drawImage(Bul->getRect(),Bul->getImage());}

            painter.drawImage(FW->getRect(), FW->getImage());
            painter.drawImage(Chop->getRect(), Chop->getImage());
            painter.drawImage(two->getRect(), two->getImage());
      }
    }


void game::timerEvent(QTimerEvent *event){ //controls what happens at every tick of the timer
    bigcount++;
    if (goingUp == false){
        Chop->autoMove();
    }
    if (juststarted)
        enemycount= 0;
    FW->automove();
    if (FW->getRect().right() < 0){
        FW = new floatwall();
        FW->automove();
        fwcount++;
    }
    if (enemycount < 3 || Level == 3)
        enem->automove();
    if (enem->getRect().right()< 0){
        enem = new enemy();
        enem->automove();
        enemycount++;
        bulletShot = false;
        Bul->resetstate();
    }
    if (bulletShot == false){//bullet tracking
        Bul = new bullet(enem->getRect().x(),enem->getRect().y());
        xchp = Chop->getRect().x();
        ychp = Chop->getRect().y();
        ang = ((enem->getRect().y() - ychp)/(enem->getRect().x() - xchp));
        xdir = 5*cos(atan(ang));
        ydir = 10*sin(atan(ang));
    }
    if(enem->getRect().left() < 800&&Chop->getRect().y()>enem->getRect().y()){
        Bul->automove(-xdir, 2);
        bulletShot = true;
    }
    else if(enem->getRect().left() < 800&&Chop->getRect().y()<enem->getRect().y()){
        Bul->automove(-xdir, -2);
        bulletShot = true;
    }
    //makes sure different things happen in different levels
        if (Level > 1){
            counter++;
            yolo->automove();
            boom->automove();
            k = ((rand()%40+100));
            if (yolo->getRect().x()<0&&counter%200 == 0)
                yolo->resetstate();
            if (boom->getRect().x()<0&&counter%50 ==0)
                boom ->resetstate();
            if (two->getRect().x()<0&&counter%1000 == 0)
                two ->resetstate();

            if (Level > 2){
                yolo->automove();
                boom->automove();
                two->automove();
                ceil ->automove();
                if (yolo->getRect().x()<0&&counter%250 == 0)
                    yolo->resetstate();
                if (boom->getRect().x()<0&&counter%25 ==0)
                    boom ->resetstate();
                if (two->getRect().x()<0&&counter%1000 == 0)
                    two ->resetstate();
                if (ceil->getRect().x()<0 && bigcount%k == 0)
                ceil ->resetstate();
            }
        }
    checkCollision();
    repaint();
    if (doble == true){
        points*=2;
        doble = false;
    }
    else
        points++;
    if (Level == 1 && enemycount == 3){
        Level++;
        enemycount = 0;
        fwcount = 0;
        }
    else if (Level == 2 && enemycount == 3){
        Level++;
        enemycount = 0;
        fwcount = 0;
        }
    }

void game::keyPressEvent(QKeyEvent *event){//controls what happens when different keys are pressed
    switch (event -> key()){
        case Qt::Key_Up:
            {
                int x = Chop-> getRect().y();
                for (int i = 0; i<=5; i++)
                    Chop->moveUp(x--);
                checkCollision();
                goingUp = true;
            }
            break;
        case Qt::Key_P:
            {
                pauseGame();
            }
            break;
        case Qt::Key_Space:
            {
                startGame();
                juststarted = true;
            }
            break;
        case Qt::Key_Escape:
            {
                qApp -> exit();
            }
            break;
        default:
            QWidget::keyPressEvent(event);
    }
}

void game::keyReleaseEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Up&&!(event->isAutoRepeat()))
        goingUp = false;
    if (event->key() == Qt::Key_Space)
        juststarted = false;
}
void game::startGame(){
    if(!gameStarted){
        Chop->resetState();
        FW->resetstate();
        enem->resetstate();
        gameOver = false;
        gameWon = false;
        gameStarted = true;
        Lives = 3;
        enemycount = 3;
        timerId = startTimer(10);
    }
}
//pauses game
void game::pauseGame(){
    if (paused){
        timerId = startTimer(10);
        paused = false;
    }
    else {
       paused = true;
       killTimer(timerId);
    }
}
//game over conditions
void game::stopGame(){
      killTimer(timerId);
      gameOver = TRUE;
      gameStarted = FALSE;
}

//controls what happens when there's object collisions
void game::checkCollision(){
    if (Chop-> getRect().bottom() > 395 || Chop-> getRect().bottom() < 5||Chop->getRect().intersects(FW->getRect())||Chop->getRect().intersects(enem->getRect())||Chop->getRect().intersects(Bul->getRect())||Chop->getRect().intersects(boom->getRect())||Chop->getRect().intersects(ceil->getRect())){
        Lives--;
        Chop->resetState();
        FW->resetstate();
        enem->resetstate();
        boom->resetstate();
        ceil->resetstate();
        if (enem->getRect().x()<800)
            Bul->resetstate(enem->getRect().x(),enem->getRect().y());
        bulletShot = true;
    }
    if (Chop-> getRect().intersects(yolo->getRect())){
        Lives++;
        yolo->resetstate();
    }
    if (Chop-> getRect().intersects(two->getRect())){
        doble = true;
        two->resetstate();
    }

    if (Lives == 0)
        stopGame();
}
