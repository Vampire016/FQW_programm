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
    QString log = ui->login->text();
    QString pass = ui->password->text();

    QSqlQuery query;
    query = QSqlQuery(db);

    query.exec("SELECT * FROM Users");

    if (conect)
        {
            while (query.next())
            {
                QString s1 = query.value(3).toString();
                QString s2 = query.value(4).toString();

                if(log == s1 && pass == s2)
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
            }

            QMessageBox::critical(this, "Авторизация", "Логин и/или пароль введены не верно!");

            return;
         }
}

void SecondWindow::on_pushButton_clicked()
{
    db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName(ui->lineEdit->text());

        if (!db.open())
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
                    conect = true;
                }
}
