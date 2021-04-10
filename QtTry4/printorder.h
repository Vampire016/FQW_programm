#ifndef PRINTORDER_H
#define PRINTORDER_H

#include "Libraries.h"

namespace Ui {
class PrintOrder;
}

class PrintOrder : public QWidget
{
    Q_OBJECT

public:
    explicit PrintOrder(QWidget *parent = nullptr);
    ~PrintOrder();

private:
    Ui::PrintOrder *ui;

    QPixmap *logo;
};

#endif // PRINTORDER_H
