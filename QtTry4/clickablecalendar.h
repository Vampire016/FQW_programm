#ifndef CLICKABLECALENDAR_H
#define CLICKABLECALENDAR_H

#include "Libraries.h"


class ClickableCalendar : public QCalendarWidget
{
    Q_OBJECT
public:
    explicit ClickableCalendar(QCalendarWidget *parent = nullptr);

signals:
    void clickedDate();

protected slots:
    void DateChosen();
};

#endif // CLICKABLECALENDAR_H
