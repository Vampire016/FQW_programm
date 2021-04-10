#include "printorder.h"
#include "ui_printorder.h"


PrintOrder::PrintOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrintOrder)
{
    ui->setupUi(this);

    //Добавление на бланк отчета логотип организации
    //--------------------------------------------------------------------------------------------------------------------------------------------
    logo = new QPixmap;
    logo->load(":/resource/img/IT-Osoba_Logo_150x88.png");

    int w = ui->img_logo->width();
    int h = ui->img_logo->height();

    ui->img_logo->setPixmap(logo->scaled(w, h, Qt::KeepAspectRatio));
    //--------------------------------------------------------------------------------------------------------------------------------------------

}

PrintOrder::~PrintOrder()
{
    delete ui;
}
