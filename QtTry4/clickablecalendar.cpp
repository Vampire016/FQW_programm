#include "clickablecalendar.h"

ClickableCalendar::ClickableCalendar(QCalendarWidget *parent) : QCalendarWidget(parent)
{
    connect(this, SIGNAL(selectionChanged()), this, SLOT(DateChosen()));       
}

void ClickableCalendar::DateChosen()
{
    emit clickedDate();
}
