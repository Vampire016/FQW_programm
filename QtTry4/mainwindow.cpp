#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTabBar>
#include <QLabel>

#include <QDebug>

#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QPixmap>
#include <QPrintPreviewDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    counterUpdate = 0;

    conect = false;
    sw = new SecondWindow;
    sw->show();

    QTabBar *tabBar = ui->tabWidget->findChild<QTabBar *>();
    tabBar->hide();

    qmodel = new QSqlQueryModel;
    qmodel_c1 = new QSqlQueryModel;

    tmr = new QTimer();

    ui->PB_wOpened->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: blue}");
    ui->PB_wNew->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: black}");
    ui->PB_wAwaits->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: orange}");
    ui->PB_wSolved->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: black}");
    ui->PB_wOverdue->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: red}");
    ui->PB_wInWork->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: green}");

    connect(sw, SIGNAL(ShowMain()), this, SLOT(reciveSignal()));
    connect(sw, SIGNAL(DBConnect(QString)), this, SLOT(SigDBConnect(QString)));
    connect(this, SIGNAL(RevDBConnect(bool)), sw, SLOT(ConOrNot(bool)));
    connect(sw, SIGNAL(DBLog(QString, QString)), this, SLOT(SigDBLog(QString, QString)));
    connect(this, SIGNAL(RevDBLog(bool)), sw, SLOT(LogOrNot(bool)));
    connect(tmr, SIGNAL(timeout()), this, SLOT(UpdateDB()));
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

    ui->tableView->verticalHeader()->setVisible(false);



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
                    tmr->start(1);
                    return;
                }
            }

            emit RevDBLog(false);
            return;
        }
}

void MainWindow::UpdateDB()
{
    counterUpdate++;

    qDebug() << "Update #" + QVariant(counterUpdate).toString();



    qmodel->setQuery("SELECT Orders.id, Orders.Title, Status.SName, Edit.DateEdit, Create.DateOpen, Priority.PName, createUser.fullName AS Инициатор, workUser.FullName AS [Кто назначен], Categories.[C+SC] "
"FROM Users AS workUser INNER JOIN (Categories INNER JOIN (Status INNER JOIN (Priority INNER JOIN (((Orders INNER JOIN (Users AS createUser INNER JOIN [Create] ON createUser.id = Create.WhoCreate) ON Orders.id = Create.id) INNER JOIN Edit ON Orders.id = Edit.id) INNER JOIN [Work] ON Orders.id = Work.id) ON Priority.id = Orders.Priory) ON Status.id = Orders.Status) ON Categories.id = Orders.Category) ON workUser.id = Work.WhoWork ORDER BY Orders.id DESC;", db);

    qmodel_c1->setQuery("SELECT "
"-SUM(NOT Status.SName = 'Закрыто') AS cOpened, "
"-SUM(Status.SName = 'В работе (назначена)' OR Status.SName = 'В работе (запланированна)') AS cInWork "
"FROM Status INNER JOIN Orders ON Status.id = Orders.Status;", db);

    qmodel_c1->query().first();

    ui->PB_wOpened->setText(qmodel_c1->query().value(0).toString());
    ui->PB_wInWork->setText(qmodel_c1->query().value(1).toString());


    tmr->start(10000);
}

void MainWindow::on_PB_wOpened_clicked()
{

}

void MainWindow::on_action_3_triggered()
{
    QPrinter printer;

    QPainter painter;

    /*painter.setWindow(sw->rect());
    this->render(&painter);*/

    //QPrintDialog dialog(&printer, this);
    QPixmap pix = QWidget::grab(sw->rect());




    QPrintPreviewDialog preview(&printer,this);




    if(preview.exec() == QDialog::Accepted)
    {
        /*
        painter.begin(&printer);
        painter.drawPixmap(0, 0, pix);
        painter.end();*/
    }

    /*
    if(dialog.exec() == QDialog::Accepted)
    {
        painter.begin(&printer);
        painter.drawPixmap(0, 0, pix);
        painter.end();
    }*/
}
