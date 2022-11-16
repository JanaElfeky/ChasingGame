#ifndef FRANKLIN_H
#define FRANKLIN_H
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

class Franklin1 :public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT;
  private:
  int lives;
  int row;
  int column;
  int data[10][10];

   public:

    Franklin1(int boardData[10][10],int lives);
    int getLivesF();
public slots:
    void keypress (QKeyEvent* event);

    };


//};
#endif // FRANKLIN_H