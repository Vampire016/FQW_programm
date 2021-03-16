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
    model = new QSqlTableModel;

    qmodel->setQuery("SELECT Orders.id, Orders.Title, Status.SName, Edit.DateEdit, Create.DateOpen, Priority.PName, createUser.fullName AS Инициатор, workUser.FullName AS [Кто назначен], Categories.[C+SC] "
"FROM Users AS workUser INNER JOIN (Categories INNER JOIN (Status INNER JOIN (Priority INNER JOIN (((Orders INNER JOIN (Users AS createUser INNER JOIN [Create] ON createUser.id = Create.WhoCreate) ON Orders.id = Create.id) INNER JOIN Edit ON Orders.id = Edit.id) INNER JOIN [Work] ON Orders.id = Work.id) ON Priority.id = Orders.Priory) ON Status.id = Orders.Status) ON Categories.id = Orders.Category) ON workUser.id = Work.WhoWork;", db);

    ui->tableView->setModel(qmodel);
    ui->tableView->resizeRowsToContents();
    ui->tableView->setColumnWidth(1, 270);


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
