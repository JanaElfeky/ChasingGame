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
#include <QKeyEvent>
#include <QList>

class Enemy:public QObject, public QGraphicsPixmapItem
{   Q_OBJECT;
    private:
    int liveE;
    int rowE;
    int columnE;
    int data [10][10];
public:

 Enemy(int boardData[10][10], int r, int c);
 Enemy();
 void enemyMove(int lives,int border[10][10]);
 int getRow();
 int getColumn();
 void setLives(int livesE);
 int getLivesE();



};

#endif // ENEMY_H

