#include "printorder.h"
#include "ui_printorder.h"


PrintOrder::PrintOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrintOrder)
{
    ui->setupUi(this);

    //this->setWindowFlags(Qt::WindowMinimizeButtonHint);
    this->setWindowFlag(Qt::WindowMinimizeButtonHint, false);
    this->setBtn(0);

    //Добавление на бланк отчета логотип организации
    //--------------------------------------------------------------------------------------------------------------------------------------------
    logo = new QPixmap;
    logo->load(":/resource/img/IT-Osoba_Logo_150x88.png");

    int w = ui->img_logo->width();
    int h = ui->img_logo->height();

    ui->img_logo->setPixmap(logo->scaled(w, h, Qt::KeepAspectRatio));
    //--------------------------------------------------------------------------------------------------------------------------------------------



    connect(ui->lineEdit_bordName, SIGNAL(inputRejected()), this, SLOT(inputReject()));
    //connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(inputReject()));
    //connect(ui->label_BordName, SIGNAL(returnPressed()));
    connect(ui->lineEdit_bordName, SIGNAL(editingFinished()), this, SLOT(inputReject()));
    connect(this, SIGNAL(clicked(QMouseEvent *)), this, SLOT(clearFocusEd()));


    if(!(ui->lineEdit_bordName->hasFocus()))
    {
        ui->label_SubBordName->setText(ui->lineEdit_bordName->text());
    }

//ui->lineEdit_bordName->editingFinished()


}

PrintOrder::~PrintOrder()
{
    delete ui;
}

void PrintOrder::inputReject()
{
    ui->label_SubBordName->setText(ui->lineEdit_bordName->text());
    /*if(ui->lineEdit->text().size() == 5)
    {
        ui->lineEdit_2->setFocus();
    }*/

    /*
    QString a = ui->lineEdit->text();
    qDebug() << a.size();*/
}


void PrintOrder::mousePressEvent (QMouseEvent *event) {
    emit clicked(event);
}

void PrintOrder::setBtn(int btn) {
    this->btn = btn;
}

int PrintOrder::button(void) {
    return this->btn;
}

void PrintOrder::clearFocusEd()
{
    if(this->focusWidget() != NULL)
    {
        this->focusWidget()->clearFocus();
    }
}
