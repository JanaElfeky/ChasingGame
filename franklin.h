#ifndef FRANKLIN_H
#define FRANKLIN_H


#include <QGraphicsPixmapItem>
#include <QDir>
#include <QDebug>
#include <QStandardItemModel>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include "enemy.h"


class Franklin :public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT;
  private:
  int lives;
  int row;
  int column;
  int boarder[10][10];
  Enemy* Enemy1,*Enemy2;

   public:
    QTime time;
    QTimer *timer2 = new QTimer();
    bool flag=false;
    Franklin(int boardData[10][10],int lives,Enemy* enemy1, Enemy* enemy2);
    int getLivesF();

public slots:
    void keyPressEvent (QKeyEvent* event);
    void setFranklin();
     void sethulk();
     //void handler(Enemy* enemy1,Enemy* enemy2);
};

#endif // FRANKLIN_H
