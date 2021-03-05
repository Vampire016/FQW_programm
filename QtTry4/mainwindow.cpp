#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTabBar>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
}

void MainWindow::reciveSignal()
{
    this->show();
}
