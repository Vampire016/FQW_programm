#include "qtoolcalendar.h"

QToolCalendar::QToolCalendar(QWidget *parent) : QToolButton(parent)
{
    this->setPopupMode(QToolButton::InstantPopup);
    this->setIcon(QIcon(":/resource/img/calendar.png"));
    this->setIconSize(QSize(16, 16));
}

//QToolCalendar::~QToolCalendar() {}
