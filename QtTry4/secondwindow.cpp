#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    conect = false;

    if (!conect)
    {
        ui->LogIN->setEnabled(false);
    }
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_LogIN_clicked()
{
    emit DBLog(ui->login->text(), ui->password->text());
}

void SecondWindow::LogOrNot(bool logIn)
{
    if(logIn)
    {
        QMessageBox *msgBox;
        msgBox = new QMessageBox;

        msgBox->about(this, "Авторизация", "Авторизация прошла успешно!");
        if (msgBox->Ok)
        {
            emit ShowMain();            
            delete msgBox;
            this->close();
        }
        return;
    }
    else
    {
        QMessageBox::critical(this, "Авторизация", "Логин и/или пароль введены не верно!");
        return;
    }
}

void SecondWindow::on_pushButton_clicked()
{
    emit DBConnect(ui->lineEdit->text());
}

void SecondWindow::ConOrNot(bool conect)
{
    if(!conect)
    {
        qDebug() << db.lastError();

        QMessageBox::critical(this, "Connection", "Наименование БД указано не верно/не инициализированно!");
    }
    else
    {
        ui->LogIN->setEnabled(true);
        ui->lineEdit->clear();
        ui->lineEdit->setEnabled(false);
        ui->pushButton->setEnabled(false);
        this->conect = conect;
    }
}
