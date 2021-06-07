#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/resource/img/IT-Osoba_Logo_ico.ico"));
    w.setWindowTitle("Модуль учета заявок ООО \"ИТ Особа\"");
    //w.show();
    return a.exec();
}
