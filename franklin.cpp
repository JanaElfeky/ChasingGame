#include "franklin.h"
#include "bullets.h"
#include "enemy.h"
#include "power_pellets.h"
#include "door.h"
#include <QTimer>
Franklin::Franklin(int border[10][10],int l,Enemy* enemy1, Enemy* enemy2)
    {   
    QPixmap franklin("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin.png");
    franklin = franklin.scaledToWidth(50);
    franklin = franklin.scaledToHeight(50);
    setPixmap(franklin);
     lives = 3;
     row=5;
     column=5;
    setPos(50 + column * 50, 50 + row * 50);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            boarder[i][j] = border[i][j];
    Enemy1=enemy1;
    Enemy2=enemy2;
}

//void Franklin::handler(Enemy* enemy1,Enemy* enemy2){
//    QTimer *timer = new QTimer();
//      connect(timer,SIGNAL(timeout()),this,SLOT(setFranklin()));
//      timer->start(1800);
//     QList<QGraphicsItem*> value = collidingItems();
//     for (int i = 0; i < value.size(); i++)
//     {
//         if (typeid(*value[i]) == typeid(Bullets)){
//             scene()->removeItem(value[i]);
//             QPixmap franklin3("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin3.png");
//              franklin3 = franklin3.scaledToWidth(50);
//              franklin3 = franklin3.scaledToHeight(50);
//              setPixmap(franklin3);

//             double d1, d2;
//                         d1=qSqrt((qPow((enemy1->getRow()-row),2)-qPow((enemy1->getColumn()-column),2)));
//                         d2=qSqrt((qPow((enemy2->getRow()-row),2)-qPow((enemy2->getColumn()-column),2)));
//                         if (d2>=d1){
//                             enemy1->setLives((enemy1->getLivesE())-1);
//                         }
//                         else {
//                             enemy2->setLives((enemy2->getLivesE())-1);
//                         }
//                         if (enemy1->getLivesE()==0){
//                             enemy1->~Enemy();
//                         }
//                         if (enemy2->getLivesE()==0){
//                             enemy2->~Enemy();
//                         }

//                         if (enemy1->getLivesE()==0 && enemy2->getLivesE()==0){
//                             QPixmap youWin("/Users/apple/Desktop/CSCE 2/project/you_win.png");
//                             youWin=youWin.scaledToHeight(300);
//                             youWin=youWin.scaledToWidth(300);
//                             setPixmap(youWin);

//            // connect(timer, &QTimer::timeout, this, QOverload<>::of(&Franklin::update));
//            QPixmap franklin3("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin3.png");
//             franklin3 = franklin3.scaledToWidth(50);
//             franklin3 = franklin3.scaledToHeight(50);
//             setPixmap(franklin3);


//             // haytala3 el timer
//

//         }
//     }
//    QList<QGraphicsItem*> values = collidingItems();
//     for (int i = 0; i < values.size(); i++)
//    {
//       if (typeid(*value[i]) == typeid(power_pellets)){
//          scene()->removeItem(value[i]);
//           if (typeid(*values[i]) != typeid(power_pellets)){
//                        QTime time;
//                         time.setHMS(0,1,0);

//                        //add timer
//                     // ask law nehot soora lama yakhod el power pellet
//                     if (typeid(*values[i]) == typeid(Enemy)){
//                     lives--;
//                     if (lives==0){
//                                       QPixmap gameOver("/Users/apple/Desktop/CSCE 2/project/game_over.png");
//                                       gameOver=gameOver.scaledToHeight(300);
//                                        gameOver=gameOver.scaledToWidth(300);
//                                        setPixmap(gameOver);
//                                     }
//                         Franklin(boarder,lives);
//                       Enemy(boarder,2,7);
//                         Enemy(boarder,7,7);
//                        }
//          }
//}

void Franklin::keyPressEvent(QKeyEvent* event)
{


     QPixmap franklin("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin.png");
     franklin = franklin.scaledToWidth(50);
     franklin = franklin.scaledToHeight(50);
     setPixmap(franklin);
    if (event->key() == Qt::Key_Up && boarder[row - 1][column] == 2)
    {
        row--;

    }
    else if (event->key() == Qt::Key_Down && boarder[row + 1][column] == 2)
    {
        row++;

    }
    else if (event->key() == Qt::Key_Right && boarder[row][column + 1] == 2)
    {
        column++;

    }
    else if (event->key() == Qt::Key_Left && boarder[row][column - 1] == 2)
    {
        column--;

    }
    setPos(50 + column * 50, 50 + row * 50);
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(setFranklin()));
    timer->start(1800);
     QList<QGraphicsItem*> value = collidingItems();
     int bulletCount=4;
     for (int i = 0; i < value.size(); i++)
     {
         if (typeid(*value[i]) == typeid(Bullets)){
             scene()->removeItem(value[i]);
             bulletCount--;
             if (bulletCount==0){
                 Enemy1->~Enemy();
                 Enemy2->~Enemy();
             }
             QPixmap franklin3("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin3.png");
              franklin3 = franklin3.scaledToWidth(50);
              franklin3 = franklin3.scaledToHeight(50);
              setPixmap(franklin3);

             double d1, d2;
             int enemyCount=2;
                         d1=qSqrt((qPow((Enemy1->getRow()-row),2)+qPow((Enemy1->getColumn()-column),2)));
                         d2=qSqrt((qPow((Enemy2->getRow()-row),2)+qPow((Enemy2->getColumn()-column),2)));
                         if (d2>=d1){
                             Enemy1->setLives((Enemy1->getLivesE())-1);
                             if (Enemy1->getLivesE()==0){
                                 Enemy1->~Enemy();
                                 enemyCount--;
                             }
                         }
                         else {
                             Enemy2->setLives((Enemy2->getLivesE())-1);
                             if (Enemy2->getLivesE()==0){
                                 Enemy2->~Enemy();
                                 enemyCount--;
                             }
                         }


         }
//          if (Enemy1->getLivesE()==0 && Enemy2->getLivesE()==0 && lives!=0){
//              door door1(boarder,5,3);
//              scene.addItem();

//              QPixmap door("/Users/markemad/Documents/Fall 2022/CS 2/gta/SciFi_Door_Pixel.png");
//              door = door.scaledToWidth(50);
//              door = door.scaledToHeight(50);
//              setPixmap(door);
//              setPos(50 + 5 * 50, 50 + 5 * 50);
//              QPixmap youWin("/Users/markemad/Documents/Fall 2022/CS 2/gta/you_win.jpeg");
//              youWin=youWin.scaledToHeight(300);
//              youWin=youWin.scaledToWidth(300);
//              setPixmap(youWin);
//              }}

    QList<QGraphicsItem*> values = collidingItems();
    for (int i = 0; i < values.size(); i++)
    {

        timer2->start(9000000000000000);
        if (typeid(*values[i]) != typeid(power_pellets)){
//             timer2->stop();
                    if (typeid(*values[i]) == typeid(Enemy)){
                        lives--;
                       // setPos(50 + column * 50, 50 + row * 50);
                        if (lives==0){
                        QPixmap gameOver("/Users/markemad/Documents/Fall 2022/CS 2/gta/game_over.png");
                        gameOver=gameOver.scaledToHeight(300);
                        gameOver=gameOver.scaledToWidth(300);
                        setPixmap(gameOver);

                    }}
                        //this->setPos(50 + column * 50, 50 + row * 50);
                       // Enemy1->setPos()
                       // Franklin(boarder,lives,Enemy1,Enemy2);
                      //  Enemy(boarder,2,7);
                       // Enemy(boarder,7,7);
                        }
        else if (typeid(*values[i]) == typeid(power_pellets)){
            scene()->removeItem(values[i]);
            connect(timer2,SIGNAL(timeout()),this,SLOT(sethulk()));
            QPixmap hulk("/Users/markemad/Documents/Fall 2022/CS 2/gta/hulk.png");
             hulk = hulk.scaledToWidth(50);
             hulk = hulk.scaledToHeight(50);
             setPixmap(hulk);
         }}}


int Franklin::getLivesF(){
     return lives;
}
void Franklin::sethulk(){
        QPixmap hulk("/Users/markemad/Documents/Fall 2022/CS 2/gta/hulk.png");
        hulk = hulk.scaledToWidth(50);
        hulk = hulk.scaledToHeight(50);
        this->setPixmap(hulk);
}
void Franklin::setFranklin(){
    QPixmap franklin1("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin.png");
    franklin1 = franklin1.scaledToWidth(50);
    franklin1 = franklin1.scaledToHeight(50);
    this->setPixmap(franklin1);
}
void Franklin:: win()
{
    if (Enemy1->getLivesE()==0 && Enemy2->getLivesE()==0 && lives!=0){
             door door1(boarder,5,3);
             scene.addItem();

             QPixmap door("/Users/markemad/Documents/Fall 2022/CS 2/gta/SciFi_Door_Pixel.png");
             door = door.scaledToWidth(50);
             door = door.scaledToHeight(50);
             setPixmap(door);
             setPos(50 + 5 * 50, 50 + 5 * 50);
             QPixmap youWin("/Users/markemad/Documents/Fall 2022/CS 2/gta/you_win.jpeg");
             youWin=youWin.scaledToHeight(300);
             youWin=youWin.scaledToWidth(300);
             setPixmap(youWin);
             }
}
void Franklin:: lose()
{
    if (Franklin->getLivesF == 0)
    {
        QPixmap gameOver("/Users/apple/Desktop/CSCE 2/project/game_over.png");
        gameOver=gameOver.scaledToHeight(300);
        gameOver=gameOver.scaledToWidth(300);
        setPixmap(gameOver);
    }
}
