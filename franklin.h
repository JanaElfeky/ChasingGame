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
  bool powerful;
int t=10;
   public:
    QTime timer;

    Franklin(int boardData[10][10],Enemy* enemy1, Enemy* enemy2);
    int getLivesF();
   // int decrease_t(int t);

public slots:
    void keyPressEvent (QKeyEvent* event);
    void setFranklin();
     void sethulk();
     void Normal();
     void win();
     void lose();
     int decrease_t(int t){
          if( t>0)
             t--;
          return t;

     }
     void setGun();
signals:
     void winner();
     void loser();
     void decrease_health();
     void decrease_time();

};

#endif // FRANKLIN_H
