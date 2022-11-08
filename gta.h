#ifndef GTA_H
#define GTA_H

#include <QMainWindow>
#include <iostream>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>


QT_BEGIN_NAMESPACE
namespace Ui { class GTA; }
QT_END_NAMESPACE

class GTA : public QMainWindow
{
    Q_OBJECT

public:
    GTA(QWidget *parent = nullptr);
    ~GTA();

private:
    Ui::GTA *ui;
};
#endif // GTA_H
