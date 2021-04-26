#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "secondwindow.h"
#include "printorder.h"
#include "Libraries.h"
#include "qtabwidget_v.h"
#include "clickablewidget.h"
#include "clickablecalendar.h"
#include "qtoolcalendar.h"


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

    void SigDBConnect(QString name, QString type);
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

    void on_act_create_ord_triggered();

private:
    Ui::MainWindow *ui;    

    QSqlDatabase db;

    QSqlQueryModel* qmodel, * qmodel_c1, * qmodel_c2, * qmodel_categ, * qmodel_stat, * qmodel_reqS, * qmodel_piory, * qmodel_creator,
    * qmodel_super, * qmodel_appoin, * qmodel_id;

    QSqlQuery *createOrd;

    QStandardItemModel *modelVar2;

    SecondWindow *sw;
    PrintOrder *PrOrd;

    QTimer *tmr;

    QMdiArea * mdiArea;

    QMenu *report, *menuOp, *menuCl, *menuDi;

    QWidget *centrWidget;

    QWidgetAction *actionOp, *actionCl,  *actionDi;

    ClickableCalendar *calendarOp, *calendarCl, *calendarDi;

    QToolButton *curToolBtn;


    bool subWflags, conect;
    int counterUpdate;    

signals:
    void RevDBConnect(bool conect);
    void RevDBLog(bool logIn);

};
#endif // MAINWINDOW_H
