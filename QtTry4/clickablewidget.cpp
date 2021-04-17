#include "clickablewidget.h"

ClickableWidget::ClickableWidget(QWidget *parent) : QWidget(parent)
{
    this->setBtn(0);
}

ClickableWidget::~ClickableWidget() {}

void ClickableWidget::mousePressEvent (QMouseEvent *event) {
    emit clicked(event);
}

void ClickableWidget::setBtn(int btn) {
    this->btn = btn;
}

int ClickableWidget::button(void) {
    return this->btn;
}

