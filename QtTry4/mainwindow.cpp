#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTabBar>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    conect = false;
    sw = new SecondWindow;
    sw->show();

    QTabBar *tabBar = ui->tabWidget->findChild<QTabBar *>();
    tabBar->hide();

    ui->pushButton->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: blue}");
    ui->pushButton_2->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: black}");
    ui->pushButton_3->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: orange}");
    ui->pushButton_4->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: black}");
    ui->pushButton_7->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: red}");
    ui->pushButton_8->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: green}");

    connect(sw, SIGNAL(ShowMain()), this, SLOT(reciveSignal()));
    connect(sw, SIGNAL(DBConnect(QString)), this, SLOT(SigDBConnect(QString)));
    connect(this, SIGNAL(RevDBConnect(bool)), sw, SLOT(ConOrNot(bool)));
    connect(sw, SIGNAL(DBLog(QString, QString)), this, SLOT(SigDBLog(QString, QString)));
    connect(this, SIGNAL(RevDBLog(bool)), sw, SLOT(LogOrNot(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    ui->tabWidget->setCurrentIndex(0);
}


void MainWindow::on_action_2_triggered()
{
    ui->tabWidget->setCurrentIndex(1);

    qmodel = new QSqlQueryModel;
    qmodel->setQuery("SELECT Orders.id, Orders.Title, Status.SName, Edit.DateEdit, Create.DateOpen, Priority.PName, Users.FullName "
    "FROM Users INNER JOIN ((Priority INNER JOIN ((Status INNER JOIN Orders ON Status.id = Orders.Status) INNER JOIN Edit ON Orders.id = Edit.id) ON Priority.id = Orders.Priory) INNER JOIN [Create] ON Orders.id = Create.id) ON (Users.id = Edit.WhoEdit) AND (Users.id = Create.WhoCreate)", db);


    ui->tableView->setModel(qmodel);
}

void MainWindow::reciveSignal()
{
    this->show();
}

void MainWindow::SigDBConnect(QString str)
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(str);

    if(!db.open())
    {
        emit RevDBConnect(conect);
    }
    else
    {
        conect = true;
        emit RevDBConnect(conect);
    }
}

void MainWindow::SigDBLog(QString log, QString pass)
{
    QSqlQuery query;
    query = QSqlQuery(db);

    query.exec("SELECT * FROM Users");

    if (conect)
        {
            while (query.next())
            {
                QString s1 = query.value(4).toString();
                QString s2 = query.value(5).toString();

                if(log == s1 && pass == s2)
                {
                    emit RevDBLog(true);
                    return;
                }
            }

            emit RevDBLog(false);
            return;
        }
}
