#include "door.h"

door::door(int border[10][10], int r2, int c2)
{
    QPixmap door("/Users/markemad/Documents/Fall 2022/CS 2/gta/SciFi_Door_Pixel.png");
    door = door.scaledToWidth(50);
    door = door.scaledToHeight(50);
    //setPixmap(door);
    r2=5;
    c2=5;
        // Set Position
        setPos(50 + r2 * 50, 50 + c2 * 50);
}
