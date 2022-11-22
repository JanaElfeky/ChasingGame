#include "gta.h"
#include "franklin.h"
#include "bullets.h"
#include "enemy.h"
#include "power_pellets.h"
#include "widgets.h"
#include <QApplication>
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QTimer>
#include <QDebug>
#include <QStandardItemModel>
#include <QKeyEvent>
#include <QBrush>
#include <QElapsedTimer>
#include "door.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // QApplication board(argc,argv);
    QGraphicsView view;
    QGraphicsScene scene;
    view.setFixedSize(700, 800);
    view.setWindowTitle("GTA Game");
    QBrush brush(Qt::black);
    view.setBackgroundBrush(brush);
    QFile file("/Users/markemad/Documents/Fall 2022/CS 2/gta/Board1.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    int border[10][10];
    QString temp;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            {
                stream >> temp;
                border[i][j] = temp.toInt();
            }
    QPixmap grassImage("/Users/markemad/Documents/Fall 2022/CS 2/gta/Grass_image.png");
    grassImage = grassImage.scaledToWidth(50);
    grassImage = grassImage.scaledToHeight(50);
    QPixmap buildingimage("/Users/markemad/Documents/Fall 2022/CS 2/gta/Building_image.png");
    buildingimage = buildingimage.scaledToWidth(500);
    buildingimage = buildingimage.scaledToHeight(50);
    QPixmap treeImage("/Users/markemad/Documents/Fall 2022/CS 2/gta/Tree_image2.jpg");
    treeImage = treeImage.scaledToWidth(100);
    treeImage = treeImage.scaledToHeight(53);
    QPixmap lampImage("/Users/markemad/Documents/Fall 2022/CS 2/gta/Lamp_image.png");
    lampImage = lampImage.scaledToWidth(50);
    lampImage = lampImage.scaledToHeight(50);
    QPixmap roadImage("/Users/markemad/Documents/Fall 2022/CS 2/gta/Road.png");
    roadImage = roadImage.scaledToWidth(50);
    roadImage = roadImage.scaledToHeight(50);
    QPixmap  car("/Users/markemad/Documents/Fall 2022/CS 2/gta/car2.png");
    car = car.scaledToWidth(50);
    car = car.scaledToHeight(50);
    QPixmap F_home("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin_home.png");
    F_home = F_home.scaledToWidth(50);
    F_home = F_home.scaledToHeight(50);

    QGraphicsPixmapItem boardItems[10][10];
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                // Set Image
                if (border[i][j] == 4)
                    boardItems[i][j].setPixmap(car);
                else if(border[i][j]==5)
                    boardItems[i][j].setPixmap(grassImage);
                else if(border[i][j]== 1)
                    boardItems[i][j].setPixmap(buildingimage);

                else if(border[i][j]== 8)
                   boardItems[i][j].setPixmap(treeImage);
                else if(border[i][j]==3)
                    boardItems[i][j].setPixmap(lampImage);
                else if(border[i][j]== 2)
                    boardItems[i][j].setPixmap(roadImage);
                else if(border[i][j]==7)
                    boardItems[i][j].setPixmap(F_home);

                // Set Position
                boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

                // Add to the Scene
                scene.addItem(&boardItems[i][j]);
            }
//                Widgets *lives,*bullets;
//                lives = new Widgets("Lives: ", 3, 500, 0);
//                bullets = new Widgets("bullets left ", 4, 300, 0);
//                connect(Franklin, SIGNAL(timer()),lives,SLOT(timer));

                Enemy enemy1(border,7,2);
                scene.addItem(&enemy1);
                Enemy enemy2(border,7,7);
                scene.addItem(&enemy2);
                Enemy* enemy1ptr=&enemy1;
                Enemy* enemy2ptr=&enemy2;
               Franklin franklin(border,enemy1ptr,enemy2ptr);
               scene.addItem(&franklin);
               Bullets bullet1(border,1,1);
               scene.addItem(&bullet1);
               Bullets bullet2(border,1,8);
               scene.addItem(&bullet2);
               Bullets bullet3(border,8,1);
               scene.addItem(&bullet3);
               Bullets bullet4(border,8,8);
               scene.addItem(&bullet4);
               QTimer *timer = new QTimer();
               QObject::connect(timer,SIGNAL(timeout()), &enemy1 ,SLOT(enemyMove()));
               QObject::connect(timer,SIGNAL(timeout()), &enemy2 ,SLOT(enemyMove()));
               timer->start(1000);
               power_pellets power1(border,4,6);
               scene.addItem(&power1);
               power_pellets power2(border,7,2);
               scene.addItem(&power2);
               franklin.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
               franklin.setFocus();
               Widgets *lives,*time_left,*state;
               lives = new Widgets("Lives: ", 3, 400, 20);
               state = new Widgets("state: ",0, 50,0);
               time_left = new Widgets("will stay powerful for (seconds)  "
                                       ": ",5, 50, 20);
               QObject::connect(&franklin, SIGNAL(decrease_health()),lives,SLOT(timers()));
               scene.addItem(lives);
               //QObject::connect(&franklin, SIGNAL(decrease_time()),time_left,SLOT(timers()));
               scene.addItem(time_left);
               scene.addItem(state);
               QObject::connect(&franklin,SIGNAL(winner()),&franklin,SLOT(win()));
               QObject::connect(&franklin,SIGNAL(loser()),&franklin,SLOT(lose()));
//               if (SIGNAL(winner())){
//                                QPixmap door("/Users/markemad/Documents/Fall 2022/CS 2/gta/SciFi_Door_Pixel.png");
//                                door = door.scaledToWidth(50);
//                                door = door.scaledToHeight(50);
//                                boardItems[6][6].setPixmap(door);
//                                scene.addItem(door);
//                                fsetpos(50 + 5 * 50, 50 + 5 * 50);
               //}
               view.setScene(&scene);
               view.show();
               return a.exec();


}
