#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QSqlDatabase>

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

private:
    Ui::SecondWindow *ui;

    QSqlDatabase db;

    bool conect;    

signals:
    void ShowMain();
    void DBConnect(QString sendStr);
    void DBLog(QString log, QString pass);
};

#endif // SECONDWINDOW_H
