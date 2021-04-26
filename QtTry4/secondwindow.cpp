#include "secondwindow.h"
#include "ui_secondwindow.h"


SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    conect = false;

//Список возможных для соединения видов БД
//--------------------------------------------------------------------------------------------------------------------------------------------
    dbTypes = new QStringList();
    /*
    dbTypes->insert(0, "");
    dbTypes->insert(1, "mySQL");
    dbTypes->insert(2, "MS Access");
    */
    dbTypes->operator<<("").operator<<("mySQL").operator<<("MS Access");

    ui->comboBox->addItems(*dbTypes);
//--------------------------------------------------------------------------------------------------------------------------------------------

    if (!conect)
    {
        ui->LogIN->setEnabled(false);
    }
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

//Отправка сигнала о попытке авторизации с логином и паролем
//--------------------------------------------------------------------------------------------------------------------------------------------
void SecondWindow::on_LogIN_clicked()
{
    emit DBLog(ui->login->text(), ui->password->text());
}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Возврат информации об авторизации(успешно/нет)
//--------------------------------------------------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------------------------------------------------

//Отправка сигнала о попытке соединения с БД (имя БД)
//--------------------------------------------------------------------------------------------------------------------------------------------
void SecondWindow::on_pushButton_clicked()
{    
        emit DBConnect(ui->lineEdit->text(), ui->comboBox->currentText());
}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Возврат информации о соединении с БД (успешно/нет)
//--------------------------------------------------------------------------------------------------------------------------------------------
void SecondWindow::ConOrNot(bool conect)
{
    if(!conect)
    {
        qDebug() << db.lastError();

        if(ui->comboBox->currentIndex() == 0)
        {
            QMessageBox::critical(this, "Connection", "Выберите тип используемой БД!");
        }
        else
        {
            QMessageBox::critical(this, "Connection", "Наименование/тип БД указан(о) не верно/не инициализированно!");
        }
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
//--------------------------------------------------------------------------------------------------------------------------------------------
