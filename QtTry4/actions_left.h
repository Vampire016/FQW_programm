#ifndef ACTIONS_LEFT_H
#define ACTIONS_LEFT_H

#include "Libraries.h"
#include <QWidget>

namespace Ui {
class Actions_left;
}

class Actions_left : public QWidget
{
    Q_OBJECT

public:
    explicit Actions_left(QWidget *parent = nullptr);
    ~Actions_left();


private:
    Ui::Actions_left *ui;

    QPixmap *usr, *clock;

    QMainWindow *mainWin;

    int pos;


signals:
    void delAct(int pos);
    void checkBoxChanged(int pos, int arg1);
    void workEditClick(int pos);

public slots:
    void mainWinP(QMainWindow *mainWin);
    void actLeftPos(int pos);
    void setDelHiden();

    void on_pushButton_delAct_clicked();

    void Type_Action(int type);
    void setPosNumber(int number);    


    //____________Agreement______________
    void setTextAgree(QString txt);
    void setDate_CurUsrName(QString date, QString name, int agree);
    //-----------------------------------

    void setUserDate(QString date);
    void setUserName(QString usrName);

    //______________descr________________
    void setTitleDescr(QString title);
    void setDecriptionDescr(QString descr);
    void setTickedID (int id);
    //-----------------------------------

    //_____________messege_______________
    void setTextMessege(QString txt);
    //-----------------------------------

    //______________work________________
    void setCheckWork(int check);
    void setTitleWork(QString title);
    void setTextWork(QString txt);
    void setDateRangeWork(QString date);
    void setNameWorkerWork(QString name);
    //-----------------------------------

private slots:
    void on_checkBox_work_clicked();
    void on_pushButton_editWork_clicked();

};

#endif // ACTIONS_LEFT_H
