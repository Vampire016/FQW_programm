#ifndef CLICKABLEWIDGET_H
#define CLICKABLEWIDGET_H

#include "Libraries.h"


class ClickableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClickableWidget(QWidget *parent = nullptr);
    ~ClickableWidget();

signals:
    void clicked(QMouseEvent *);

protected:
    void mousePressEvent (QMouseEvent *);

private:
    int btn;

public:
    void setBtn(int);
    int button(void);
};

#endif // CLICKABLEWIDGET_H
