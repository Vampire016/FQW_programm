#ifndef MYQLINEEDIT_H
#define MYQLINEEDIT_H

#include <QWidget>
#include <QLineEdit>

class myQLineEdit : public QWidget
{
public:
    explicit myQLineEdit(QWidget *parent = nullptr);

signals:
    /*bool LessFocus(bool)
    {
        if(!(myQLineEdit->hasFocus()))
        {
            emit LessFocus(false)
        }
    }*/
};

#endif // MYQLINEEDIT_H
