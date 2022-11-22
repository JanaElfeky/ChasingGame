#ifndef WIDGETS_H
#define WIDGETS_H
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>

class Widgets :public QGraphicsTextItem
{
    Q_OBJECT
public:

    Widgets(QString l, int w, int index_x, int index_y);
public slots:
    void timers();
    void timers2();
private:
    QString label;
    int count;
};

#endif // WIDGETS_H
