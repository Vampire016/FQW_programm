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
    void on_act_create_ord_triggered();

    void SigDBConnect(QString name, QString type);
    void SigDBLog(QString log, QString pass);
    void reciveSignal();

    void UpdateDB();

    void on_PB_wOpened_clicked();
    void on_PB_wNew_clicked();    

    void print(QPrinter * printer);   

    void onTableView_clicked();

    void ClearFocusLE();

    void FocusDateOp();
    void FocusDateCl();
    void FocusDateDi();
    void FocusDateFi();
    void FocusDateFi_2();

    void FocusToolBtn();

    void on_pushButton_clicked();    

    void on_btn_print_clicked();

    void twiceClickOnTableRow(const QModelIndex &);

    void on_pushButton_2_clicked();

    void updEditOrd();

    void on_pushButton_3_clicked();

    void Var_2_changed();
    void Var_2_1_changed();

    void on_pushButton_search_clicked();

    void on_pushButton_twsSearch_add_clicked();

    void on_pushButton_twsSearch_del_clicked();

    void on_PB_wInWork_clicked();

    void on_PB_wSolved_clicked();

    void on_PB_wAwaits_clicked();

    void on_PB_wOverdue_clicked();

private:
    Ui::MainWindow *ui;    

    QSqlDatabase db;

    QSqlQueryModel* qmodel, * qmodel_c1, * qmodel_c1_1, * qmodel_c2, * qmodel_categ, * qmodel_stat, * qmodel_reqS, * qmodel_piory, * qmodel_creator,
    * qmodel_super, * qmodel_appoin, * qmodel_id, *qmodel_ordId, *filOrd, *filOrd_1;

    QSqlQuery *createOrd, *btnSave;

    QStandardItemModel *modelVar2;

    SecondWindow *sw;
    PrintOrder *PrOrd;

    QTimer *tmr, *saveTmr;

    QMenu *report, *menuOp, *menuCl, *menuDi, *menuFi, *menuFi_2;

    QWidgetAction *actionOp, *actionCl,  *actionDi, *actionFi, *actionFi_2;

    ClickableCalendar *calendarOp, *calendarCl, *calendarDi, *calendarFi, *calendarFi_2;

    QToolButton *curToolBtn;

    QTabBar *tabBar_2;

    QList<QLineEdit*> leList;
    QList<QComboBox*> cbList;
    QList<QLabel*> lableList;


    bool subWflags, conect, btnVis;
    int counterUpdate, curUser, cbVar_1, cbVar_2, cbVar_3, cbVar_0_1, cbVar_1_1, cbVar_2_1, cbVar_3_1;
    QString id, leFind, leFind_1;
    QStringList *var0_0, *var1, *var1_1, *var1_2, *var2_1, *var2_2, *var2_3, *var2_4;

    int var_2, var_2_2;
    QString str_1, str_1_1;
    QString str_2, str_2_1;
    QString str_3, str_3_1;
    QString str_4, str_4_1;
    QString str_and;

signals:
    void RevDBConnect(bool conect);
    void RevDBLog(bool logIn);
    void fillReportSig(int id);

};
#endif // MAINWINDOW_H
