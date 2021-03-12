#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secondwindow.h"
#include <QSqlQuery>
#include <QSqlTableModel>

#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_action_2_triggered();

    void reciveSignal();

    void SigDBConnect(QString str);
    void SigDBLog(QString log, QString pass);

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    QSqlTableModel* model;
    QSqlQueryModel* qmodel;

    SecondWindow *sw;

    bool conect;

signals:
    void RevDBConnect(bool conect);
    void RevDBLog(bool logIn);
};
#endif // MAINWINDOW_H
