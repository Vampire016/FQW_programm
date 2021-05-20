#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include "Libraries.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_LogIN_clicked();

    void on_pushButton_clicked();

    void ConOrNot(bool conect);
    void LogOrNot(bool logIn);
    void logOut();

    void on_btnReturn_clicked();

    void IndexChanged();

private:
    Ui::SecondWindow *ui;

    QSqlDatabase db;

    QStringList *dbTypes;

    bool conect;


    QMovie mLogo;
    double m;

signals:
    void ShowMain();
    void DBConnect(QString sendStr, QString dbType, QString ip);
    void DBLog(QString log, QString pass);
    void RevCon();
};

#endif // SECONDWINDOW_H
