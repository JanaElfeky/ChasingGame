#include "enemy.h"

Enemy::Enemy(){
    liveE=0;
    rowE=0;
    columnE=0;
}
Enemy::Enemy(int border[10][10], int r, int c)
    {
       QPixmap enemy("/Users/apple/Desktop/CSCE 2/project/Enemy.png");
       enemy = enemy.scaledToWidth(50);
       enemy = enemy.scaledToHeight(50);
    setPixmap(enemy);
     liveE =2;
     rowE=r;
     columnE=c;
    setPos(50 + columnE * 50, 50 + rowE * 50);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            data[i][j] = border[i][j];
    }
void Enemy::enemyMove(int lives,int border[10][10]){
   //for (int i=0;i<10;i++){
        rowE=arc4random()%10;
        columnE=arc4random()%10;
        if (border[rowE][columnE]==2){
            setPos(50 + columnE * 50, 50 + rowE * 50);
        }
    //}
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
