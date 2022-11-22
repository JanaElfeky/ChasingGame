#include "enemy.h"
#include <QTimer>

Enemy::Enemy(int border[10][10], int r, int c)
    {
       QPixmap enemy("/Users/markemad/Documents/Fall 2022/CS 2/gta/Enemy.png");
       enemy = enemy.scaledToWidth(55);
       enemy = enemy.scaledToHeight(60);
    setPixmap(enemy);
     liveE =2;
     rowE=r;
     columnE=c;
    setPos(50 + columnE * 50, 50 + rowE * 50);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            data[i][j] = border[i][j];
//    if (liveE == 0){
//        scene()->removeItem(enemy);
    }



void Enemy::enemyMove()
{
       int  moveE=arc4random()%4;
        if ( moveE==0 && data[rowE - 1][columnE] == 2)
        {
            rowE--;

        }
        else if (moveE==1 && data[rowE + 1][columnE] == 2)
        {
            rowE++;
        }
        else if (moveE==2 && data[rowE][columnE+1] == 2)
        {
            columnE++;
        }
        else if (moveE==3 && data[rowE][columnE-1] == 2)
        {
            columnE--;
        }
        setPos(50 + columnE * 50, 50 + rowE * 50);

}
int Enemy::getRow(){
     return rowE;
 }
 int Enemy::getColumn(){
     return columnE;
 }
 void Enemy::setLives(int livesE){
     liveE=livesE;
 }
 int Enemy::getLivesE(){
     return liveE;
 }
