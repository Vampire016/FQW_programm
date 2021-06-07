#ifndef ACTIONS_RIGHT_H
#define ACTIONS_RIGHT_H

#include "Libraries.h"
#include <QWidget>

namespace Ui {
class Actions_right;
}

class Actions_right : public QWidget
{
    Q_OBJECT

public:
    explicit Actions_right(QWidget *parent = nullptr);
    ~Actions_right();

private:
    Ui::Actions_right *ui;

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

#endif // ACTIONS_RIGHT_H
