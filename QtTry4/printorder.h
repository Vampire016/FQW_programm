#ifndef PRINTORDER_H
#define PRINTORDER_H

#include "Libraries.h"

namespace Ui {
class PrintOrder;
}

class PrintOrder : public QWidget
{
    Q_OBJECT

signals:
    void clicked(QMouseEvent *);

public:
    explicit PrintOrder(QWidget *parent = nullptr);
    ~PrintOrder();

    void setBtn(int);
    int button(void);

private:
    Ui::PrintOrder *ui;

    QPixmap *logo;

    QSqlQueryModel *qmodel_filReport;

    int btn;

private slots:
    void inputReject();
    void clearFocusEd();
    void fillReport(int id);

protected:
    void mousePressEvent (QMouseEvent *);
};

#endif // PRINTORDER_H
