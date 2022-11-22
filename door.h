#ifndef DOOR_H
#define DOOR_H

#include <QGraphicsPixmapItem>
class door: public QGraphicsPixmapItem
{
private:
    int row2;
    int column2;
    int data[10][10];

public:
    door(/*int border[10][10],*/ int r2, int c2);
};

#endif // DOOR_H
