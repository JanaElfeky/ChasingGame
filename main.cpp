#include "gta.h"
#include "Franklin.h"
#include "bullet.h"
#include "enemy.h"
#include "power_pellets.h"
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
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // QApplication board(argc,argv);
    QGraphicsView view;
    QGraphicsScene scene;
    view.setFixedSize(600, 600);
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
    treeImage = treeImage.scaledToWidth(50);
    treeImage = treeImage.scaledToHeight(50);
    QPixmap lampImage("/Users/markemad/Documents/Fall 2022/CS 2/gta/Lamp_image.png");
    lampImage = lampImage.scaledToWidth(50);
    lampImage = lampImage.scaledToHeight(50);
    QPixmap roadImage("/Users/markemad/Documents/Fall 2022/CS 2/gta/Road.png");
    roadImage = roadImage.scaledToWidth(50);
    roadImage = roadImage.scaledToHeight(50);
//    QPixmap enemy("/Users/markemad/Documents/Fall 2022/CS 2/gta/Enemy.png");
//    enemy = enemy.scaledToWidth(50);
//    enemy = enemy.scaledToHeight(50);
    //QPixmap Franklin("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin.png");
    //Franklin = Franklin.scaledToWidth(50);
    //Franklin = Franklin.scaledToHeight(50);
//    QPixmap bullet("/Users/markemad/Documents/Fall 2022/CS 2/gta/bullet4.png");
//    bullet = bullet.scaledToWidth(40);
//    bullet = bullet.scaledToHeight(40);
    QPixmap  car("/Users/markemad/Documents/Fall 2022/CS 2/gta/car2.png");
    car = car.scaledToWidth(50);
    car = car.scaledToHeight(50);
    QPixmap F_home("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin_home.png");
    F_home = F_home.scaledToWidth(50);
    F_home = F_home.scaledToHeight(50);
    QPixmap door("/Users/markemad/Documents/Fall 2022/CS 2/gta/SciFi_Door_Pixel.png");
    door = door.scaledToWidth(50);
    door = door.scaledToHeight(50);
//    QPixmap base = QPixmap::fromImage(QImage("grassImage"));
//        QPixmap overlay = QPixmap::fromImage(QImage("lampImage"));
//        QPixmap result(base.width(), base.height());
//        result.fill(Qt::transparent); // force alpha channel
//        {
//            QPainter painter(&result);
//            painter.drawPixmap(0, 0, base);
//            painter.drawPixmap(0, 0, overlay);
//        }
//          QStandardItem *CombinedItem = new QStandardItem();
//          CombinedItem->setData(QVariant(result), Qt::DecorationRole);
//          model->setItem(1,4,CombinedItem);
//          pInventory->setModel(modfl);

//        QPainter painter(&treeImage);

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
//                else if(border[i][j]==6)
//                    boardItems[i][j].setPixmap(bullet);
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
               Franklin1 franklin(border,3);
               scene.addItem(&franklin);
               Bullet bullet1(border,1,1);
               scene.addItem(&bullet1);
               Bullet bullet2(border,1,8);
               scene.addItem(&bullet2);
               Bullet bullet3(border,8,1);
               scene.addItem(&bullet3);
               Bullet bullet4(border,8,8);
               scene.addItem(&bullet4);
               Enemy enemy(border,2,7);
               scene.addItem(&enemy);
               Enemy enemy2(border,7,7);
               scene.addItem(&enemy2);
               enemy.enemyMove(franklin.getLivesF(),border);
               enemy2.enemyMove(franklin.getLivesF(),border);
               view.setScene(&scene);
               view.show();
               return a.exec();



}
