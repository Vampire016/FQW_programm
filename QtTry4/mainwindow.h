#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "secondwindow.h"
#include "printorder.h"
#include "Libraries.h"
#include "qtabwidget_v.h"
#include "clickablewidget.h"
#include "clickablecalendar.h"
#include "actions_left.h"
#include "actions_right.h"
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

    void SigDBConnect(QString name, QString type, QString ip);
    void SigDBLog(QString log, QString pass);
    void reciveSignal();
    void RevCon();

    void UpdateDB();

    void on_PB_wOpened_clicked();
    void on_PB_wNew_clicked();    

    void print(QPrinter * printer);   

    void onTableView_clicked();
    void countPagesChanges();

    void ClearFocusLE();

    void FocusDateOp();
    void FocusDateCl();
    void FocusDateDi();
    void FocusDateFi();
    void FocusDateFi_2();
    void FocusDateVF();
    void FocusDateVU();
    void FocusDateSBD();
    void FocusDateSFD();
    void FocusDateDecision();

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

    void on_pushButton_4_clicked();

    void on_action_u_create_triggered();

    void on_pushButton_u_add_clicked();

    void on_action_users_triggered();

    void on_pushButton_5_clicked();

    void on_pushButton_u_del_clicked();

    void on_pushButton_u_save_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_toLast_clicked();

    void on_pushButton_toFirst_clicked();

    void on_pushButton_messege_clicked();

    void delAct_clicked(int pos);



    void on_pushButton_act_return_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_act_add_clicked();

private:
    Ui::MainWindow *ui;    

    QSqlDatabase db;

    QSqlQueryModel* qmodel, * qmodel_u_func, * qmodel_u_rules, * qmodel_stats, * qmodel_c1, * qmodel_c1_1, * qmodel_c2, * qmodel_categ, * qmodel_stat, * qmodel_reqS, * qmodel_agree, * qmodel_piory, * qmodel_creator,
    * qmodel_super, * qmodel_appoin, * qmodel_id, *qmodel_ordId, *filOrd, *filOrd_1, *countOrd, *qmodel_actID, *qmodel_act, *qmodel_usrNames;

    QSqlQuery *createOrd, *btnSave;

    QStandardItemModel *modelVar2;

    SecondWindow *sw;
    PrintOrder *PrOrd;

    QTimer *tmr, *saveTmr;

    QMenu *report, *menuOp, *menuCl, *menuDi, *menuFi, *menuFi_2, *menuVF, *menuVU, *menuSBD, *menuSFD, *menuDecision;

    QWidgetAction *actionOp, *actionCl,  *actionDi, *actionFi, *actionFi_2, *actionVF, *actionVU, *actionSBD, *actionSFD, *actionDecision;

    ClickableCalendar *calendarOp, *calendarCl, *calendarDi, *calendarFi, *calendarFi_2, *calendarVF, *calendarVU, *calendarSBD, *calendarSFD, *calendarDecision;

    QToolButton *curToolBtn;

    QTabBar *tabBar_2, *tabBar_3;

    QList<QLineEdit*> leList, leList2;
    QList<QComboBox*> cbList;
    QList<QLabel*> lableList, lableList2;

    QGraphicsScene *scene;
    QPixmap image;

    Actions_left *actLeft;
    Actions_right *actRight;


    bool subWflags, conect, btnVis;        
    QStringList *var0_0, *var1, *var1_1, *var1_u, *var1_1_u, *var1_2, *var2_1, *var2_2, *var2_3, *var2_4, *Limit_s;

    int counterUpdate, curUser, cbVar_1, cbVar_2, cbVar_3, cbVar_0_1, cbVar_1_1, cbVar_2_1, cbVar_3_1, var_2, var_2_2,
        queryMode, multiplier_f, multiplier_s, lFrom, lTo, countRows, act_type_click;

    QString str_1, str_1_1, str_2, str_2_1, str_3, str_3_1, str_4, str_4_1, str_and, id, leFind, leFind_1, offset, Limit_bef, Limit;

    struct Node_act
    {
        QWidget *Wg = nullptr;
        struct Node_act *next;
        struct Node_act *prev;
        int numberPos = NULL;
    };

    Node_act *tail = NULL, *head = NULL, *actNode;

    void reprintActs();
    void autoFillActs(QString actID);

signals:
    void RevDBConnect(bool conect);
    void RevDBLog(bool logIn);
    void fillReportSig(int id);
    void reload();

    void mainWinP(QMainWindow *mainWin);
    void actLeftPos(int pos);
};
#endif // MAINWINDOW_H
