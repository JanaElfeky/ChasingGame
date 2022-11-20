#ifndef ENEMY_H
#define ENEMY_H


#include <QApplication>
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QDebug>
#include <QStandardItemModel>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
//#include "bullet.h"

class Enemy:public QObject, public QGraphicsPixmapItem
{   Q_OBJECT;
    private:
    int liveE;
    int rowE;
    int columnE;
    int data [10][10];
public:
    Enemy(int boardData[10][10], int r, int c);
   int getRow();
   int getColumn();
   void setLives(int livesE);
   int getLivesE();
public slots:
 void enemyMove();

};

#endif // ENEMY_H
