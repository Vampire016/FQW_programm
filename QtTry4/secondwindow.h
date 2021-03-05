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

private:
    Ui::SecondWindow *ui;

    QSqlDatabase db;

    bool conect;

signals:
    void ShowMain();
};

#endif // SECONDWINDOW_H
