#ifndef BULLET_H
#define BULLET_H


#include <QGraphicsPixmapItem>

class Bullet : public QGraphicsPixmapItem
{
private:
    int row;
    int column;
    int data[10][10];
public:
    Bullet(int border[10][10],int row, int column);

};

#endif // BULLET_H
