#include "door.h"

door::door(int border[10][10], int r2, int c2)
{
    QPixmap door("/Users/markemad/Documents/Fall 2022/CS 2/gta/SciFi_Door_Pixel.png");
    door = door.scaledToWidth(50);
    door = door.scaledToHeight(50);
    setPixmap(door);
    row2=5;
    column2=5;
        // Set Position
        setPos(50 + row2 * 50, 50 + column2 * 50);
}
