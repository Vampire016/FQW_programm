/********************************************************************************
** Form generated from reading UI file 'printorder.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTORDER_H
#define UI_PRINTORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrintOrder
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *img_logo;
    QSpacerItem *horizontalSpacer_5;
    QLabel *txt_logo_1;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *txt_logo_id;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;

    void setupUi(QWidget *PrintOrder)
    {
        if (PrintOrder->objectName().isEmpty())
            PrintOrder->setObjectName(QString::fromUtf8("PrintOrder"));
        PrintOrder->setEnabled(true);
        PrintOrder->resize(620, 877);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PrintOrder->sizePolicy().hasHeightForWidth());
        PrintOrder->setSizePolicy(sizePolicy);
        PrintOrder->setMinimumSize(QSize(620, 877));
        PrintOrder->setMaximumSize(QSize(620, 877));
        widget = new QWidget(PrintOrder);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 599, 101));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        img_logo = new QLabel(widget);
        img_logo->setObjectName(QString::fromUtf8("img_logo"));
        sizePolicy.setHeightForWidth(img_logo->sizePolicy().hasHeightForWidth());
        img_logo->setSizePolicy(sizePolicy);
        img_logo->setMinimumSize(QSize(150, 88));
        img_logo->setMaximumSize(QSize(150, 88));

        horizontalLayout_2->addWidget(img_logo);

        horizontalSpacer_5 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        txt_logo_1 = new QLabel(widget);
        txt_logo_1->setObjectName(QString::fromUtf8("txt_logo_1"));
        sizePolicy.setHeightForWidth(txt_logo_1->sizePolicy().hasHeightForWidth());
        txt_logo_1->setSizePolicy(sizePolicy);
        txt_logo_1->setMinimumSize(QSize(150, 88));
        txt_logo_1->setMaximumSize(QSize(150, 88));

        horizontalLayout_2->addWidget(txt_logo_1);

        horizontalSpacer_6 = new QSpacerItem(85, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        txt_logo_id = new QLabel(widget);
        txt_logo_id->setObjectName(QString::fromUtf8("txt_logo_id"));
        sizePolicy.setHeightForWidth(txt_logo_id->sizePolicy().hasHeightForWidth());
        txt_logo_id->setSizePolicy(sizePolicy);
        txt_logo_id->setMinimumSize(QSize(100, 20));
        txt_logo_id->setMaximumSize(QSize(100, 20));

        verticalLayout->addWidget(txt_logo_id);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(60, 30));
        label->setMaximumSize(QSize(60, 30));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        retranslateUi(PrintOrder);

        QMetaObject::connectSlotsByName(PrintOrder);
    } // setupUi

    void retranslateUi(QWidget *PrintOrder)
    {
        PrintOrder->setWindowTitle(QCoreApplication::translate("PrintOrder", "Form", nullptr));
        img_logo->setText(QCoreApplication::translate("PrintOrder", "TextLabel", nullptr));
        txt_logo_1->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">\320\236\320\236\320\236 &quot;\320\230\320\242 \320\236\321\201\320\276\320\261\320\260&quot; </span></p><p align=\"center\">- \320\237\320\276\320\264\320\276\320\273\321\214\321\201\320\272 -8(499)4033148 </p><p align=\"center\">- www.itosoba.net</p></body></html>", nullptr));
        txt_logo_id->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-size:11pt;\">\320\235\320\276\320\274\320\265\321\200 \320\267\320\260\321\217\320\262\320\272\320\270:</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">n/a</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrintOrder: public Ui_PrintOrder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTORDER_H
