#include "widgets.h"

Widgets::Widgets(QString l, int w, int index_x, int index_y)
{
QFont font;
font.setBold(true);
font.setPixelSize(30);
setDefaultTextColor(Qt::white);
setFont(font);
setPos(index_x,index_y);
count = w;
label = l;
setPlainText(label+ QString::number(count));

}
void Widgets::timers(){
    count--;
    setPlainText(label+ QString::number(count));
}

