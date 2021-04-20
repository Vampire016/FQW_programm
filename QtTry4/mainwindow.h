#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "secondwindow.h"
#include "printorder.h"
#include "Libraries.h"
#include "qtabwidget_v.h"
#include "clickablewidget.h"
#include "clickablecalendar.h"
#include "qtoolcalendar.h"



//struct Node_1;

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
    void on_act_home_triggered();
    void on_act_orders_triggered();
    void on_act_print_triggered();
    void on_act_editOrd_triggered();

    void SigDBConnect(QString str);
    void SigDBLog(QString log, QString pass);
    void reciveSignal();

    void UpdateDB();

    void on_PB_wOpened_clicked();
    void on_PB_wNew_clicked();

    void CreateMenu();
    void ReturnEdit();    

    void print(QPrinter * printer);   

    void onTableView_clicked(const QModelIndex &);

    void ClearFocusLE();

    void FocusDateOp();
    void FocusDateCl();
    void FocusDateDi();

    void FocusToolBtn();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;

    QSqlQueryModel* qmodel;
    QSqlQueryModel* qmodel_c1;
    QSqlQueryModel* qmodel_c2;


    SecondWindow *sw;
    PrintOrder *PrOrd;

    QTimer *tmr;

    QMdiArea * mdiArea;

    QMenu *report;
    QMenu *menuOp;
    QMenu *menuCl;
    QMenu *menuDi;

    QWidget *centrWidget;

    QWidgetAction *actionOp;
    QWidgetAction *actionCl;
    QWidgetAction *actionDi;

    ClickableCalendar *calendarOp;
    ClickableCalendar *calendarCl;
    ClickableCalendar *calendarDi;



    bool subWflags;
    bool conect;
    int counterUpdate;
    QToolButton *curToolBtn;

//    Node_1 *head, *tail;

signals:
    void RevDBConnect(bool conect);
    void RevDBLog(bool logIn);
};
/*
struct Node_1
{
    Node_1 *next;

    int id;
    QString data;
};
*/

#endif // MAINWINDOW_H
