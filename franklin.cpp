#include "franklin.h"
#include <iostream>
#include "bullet.h"
#include "enemy.h"
#include "power_pellet.h"
#include "power_pellet.h"
#include <QTimer>
#include <QtMath>
//#include "ui_gta.h"

Franklin1::Franklin1(int border[10][10],int livesInput)
    {
    lives=livesInput;
    int flag=0;
    if(flag==0){
    QPixmap franklin("/Users/apple/Desktop/CSCE 2/project/Franklin.png");
    franklin = franklin.scaledToWidth(50);
    franklin = franklin.scaledToHeight(50);
    setPixmap(franklin);}
    //if(flag==1){
//    QPixmap franklin("/Users/apple/Desktop/CSCE 2/project/Franklin2.png");
//    franklin = franklin.scaledToWidth(50);
//    franklin = franklin.scaledToHeight(50);
//    setPixmap(franklin);}
     row=5;
     column=5;
    setPos(50 + column * 50, 50 + row * 50);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            data[i][j] = border[i][j];
    //Ui::GTA ui;
    //ui.LivesLeft->setText(QString::number(lives));
    }
//int f=0;
//if(f==0){
//    QPixmap franklin("/Users/apple/Desktop/CSCE 2/project/Franklin.png");
//    franklin = franklin.scaledToWidth(50);
//    franklin = franklin.scaledToHeight(50);
//    setPixmap(franklin);}
//if(f==1){
//    QPixmap franklin("/Users/apple/Desktop/CSCE 2/projectFranklin2.png");
//    franklin = franklin.scaledToWidth(50);
//    franklin = franklin.scaledToHeight(50);
void Franklin1:: keypress (QKeyEvent* event,Enemy* enemy1, Enemy* enemy2)
    {
        if ((event->key() == Qt::Key_Up) && (data[row - 1][column] == 2))
    {
        row--;
//        if (f==0)
//            f=1;
//        else f=0;
    }
    else if ((event->key() == Qt::Key_Down) && (data[row + 1][column] == 2))
    {
        row++;
//        if (f==0)
//            f=1;
//        else f=0;
    }
    else if (event->key() == Qt::Key_Right && data[row][column + 1] == 2)
    {
        column++;
//        if (f==0)
//            f=1;
//        else f=0;
    }
    else if (event->key() == Qt::Key_Left && data[row][column - 1] == 2)
    {
        column--;
//        if (f==0)
//            f=1;
//        else f=0;
    }
    setPos(50 + column * 50, 50 + row * 50);
    QList<QGraphicsItem*> value = collidingItems();
    for (int i = 0; i < value.size(); i++)
    {
        if (typeid(*value[i]) == typeid(Bullet)){
            scene()->removeItem(value[i]);
            double d1, d2;
            d1=qSqrt((qPow((enemy1->getRow()-row),2)-qPow((enemy1->getColumn()-column),2)));
            d2=qSqrt((qPow((enemy2->getRow()-row),2)-qPow((enemy2->getColumn()-column),2)));
            if (d2>=d1){
                enemy1->setLives((enemy1->getLivesE())-1);
            }
            else {
                enemy2->setLives((enemy2->getLivesE())-1);
            }
            if (enemy1->getLivesE()==0){
                enemy1->~Enemy();
            }
            if (enemy2->getLivesE()==0){
                enemy2->~Enemy();
            }

            if (enemy1->getLivesE()==0 && enemy2->getLivesE()==0){
                QPixmap youWin("/Users/apple/Desktop/CSCE 2/project/you_win.png");
                youWin=youWin.scaledToHeight(300);
                youWin=youWin.scaledToWidth(300);
                setPixmap(youWin);
            }
            QTimer * timer = new QTimer(this);
            //connect(timer, &QTimer::timeout, this, QOverload<>::of(&Franklin1::update));
            QPixmap franklin2("/Users/apple/Desktop/CSCE 2/project/Franklin3.png");
            franklin2 = franklin2.scaledToWidth(50);
            franklin2 = franklin2.scaledToHeight(50);
            setPixmap(franklin2);
            connect(timer,SIGNAL(timeout()),this,SLOT(this->setPixmap(franklin2)));
            timer->start(1000);

             // haytala3 el timer
            // hayzawad el sot
           //hayzawad soura w howa masek el sela7
        }
    }
    QList<QGraphicsItem*> value2 = collidingItems();
    for (int i = 0; i < value2.size(); i++)
    {
        if (typeid(*value2[i]) != typeid(power_pellets)){
             //add timer
            // ask law nehot soora lama yakhod el power pellet
        if (typeid(*value2[i]) == typeid(Enemy)){
            lives--;
            if (lives==0){
                QPixmap gameOver("/Users/apple/Desktop/CSCE 2/project/game_over.png");
                gameOver=gameOver.scaledToHeight(300);
                gameOver=gameOver.scaledToWidth(300);
                setPixmap(gameOver);
            }
            //Ui::GTA ui;
            //ui.LivesLeft->setText(QString::number(lives));
            Franklin1(data,lives);
            Enemy(data,2,7);
            Enemy(data,7,7);
            }}
}
}
int Franklin1::getLivesF(){
          return lives;
}

