#include "gta.h"
#include "ui_gta.h"

GTA::GTA(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GTA)
{
    ui->setupUi(this);
}

GTA::~GTA()
{
    delete ui;
}

