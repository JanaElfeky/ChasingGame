#include "gta.h"

#include <QApplication>
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GTA w;
    w.show();
    return a.exec();
    QApplication board(argc,argv);
    QGraphicsView view;
    QGraphicsScene scene;
    view.setFixedSize(800, 800);
    view.setWindowTitle("GTA Game");
    QBrush brush(Qt::black);
    view.setBackgroundBrush(brush);
    QFile file("Board.txt");
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
    QPixmap grassImage("Grass_image.png");
    grassImage = grassImage.scaledToWidth(50);
    grassImage = grassImage.scaledToHeight(50);
    QPixmap buildingimage("Building_image.png");
    buildingimage = buildingimage.scaledToWidth(50);
    buildingimage = buildingimage.scaledToHeight(50);
    QPixmap treeImage("Tree_image.png");
    treeImage = treeImage.scaledToWidth(50);
    treeImage = treeImage.scaledToHeight(50);
    QPixmap lampImage("Lamp_image.png");
    lampImage = lampImage.scaledToWidth(50);
    lampImage = lampImage.scaledToHeight(50);
    QPixmap roadImage("Road_Image.png");
    roadImage = roadImage.scaledToWidth(50);
    roadImage = roadImage.scaledToHeight(50);
    QPixmap enemy("Enemy.png");
    enemy = enemy.scaledToWidth(50);
    enemy = enemy.scaledToHeight(50);
    QPixmap Franklin("Franklin.png");
    Franklin = Franklin.scaledToWidth(50);
    Franklin = Franklin.scaledToHeight(50);
    QPixmap bullet("Bullet.png");
    bullet = bullet.scaledToWidth(50);
    bullet = bullet.scaledToHeight(50);
    QPixmap  car("Grey_car.png)");
    car = car.scaledToWidth(50);
    car = car.scaledToHeight(50);
    QPixmap F_home("Franklin_home.png");
    F_home = F_home.scaledToWidth(50);
    F_home = F_home.scaledToHeight(50);
    QPixmap door("SciFi_Door_Pixel.png");
    door = door.scaledToWidth(50);
    door = door.scaledToHeight(50);
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                // Set Image
                if (border[i][j] == 'C')
                    border[i][j].setPixmap(car);
                else
                    boardItems[i][j].setPixmap(grassImage);

                // Set Position
                boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

                // Add to the Scene
                scene.addItem(&boardItems[i][j]);
            }


}
