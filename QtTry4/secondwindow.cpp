#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QProcess>


SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    conect = false;

    ui->groupBox_2->hide();

    mLogo.setFileName("E:/Ilya/Desktop/Osoba_LOGO/OsobaLogo.gif");
    mLogo.setSpeed(100);
    mLogo.setScaledSize(QSize(150,98));
    ui->label_mLogo->setMovie(&mLogo);
    mLogo.start();

//Список возможных для соединения видов БД
//--------------------------------------------------------------------------------------------------------------------------------------------
    dbTypes = new QStringList();

    //dbTypes->operator<<("").operator<<("mySQL (Localhost)").operator<<("mySQL (Server)");
    dbTypes->operator<<("").operator<<("mySQL");

    ui->comboBox->addItems(*dbTypes);

    ui->label_4->hide();
    ui->lineEdit_2->hide();
//--------------------------------------------------------------------------------------------------------------------------------------------

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(IndexChanged()));

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
        emit DBConnect(ui->lineEdit->text(), ui->comboBox->currentText(), ui->lineEdit_2->text());
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
        this->conect = conect;

        ui->groupBox->hide();
        ui->groupBox_2->show();
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------

void SecondWindow::logOut()
{
    QProcess process;
    process.startDetached("QtTry4.exe",QStringList());

    qApp->quit();
}

void SecondWindow::on_btnReturn_clicked()
{
    emit RevCon();

    ui->groupBox->show();
    ui->groupBox_2->hide();

    ui->login->clear();
    ui->password->clear();

    ui->comboBox->setCurrentIndex(0);
}

void SecondWindow::IndexChanged()
{
    //qDebug() << "Sig";
    if(ui->comboBox->currentIndex() == 2){
        ui->lineEdit_2->setEnabled(true);
    }else{
        ui->lineEdit_2->setEnabled(false);
    }
}
