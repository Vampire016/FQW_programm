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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrintOrder
{
public:
    QFrame *line_2;
    QFrame *line_4;
    QFrame *line_5;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_7;
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
    QLabel *label_DataZayavitel;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_BordName;
    QLineEdit *lineEdit_bordName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_BordName_2;
    QLineEdit *lineEdit_bordName_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_BordName_3;
    QLineEdit *lineEdit_bordName_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_BordName_4;
    QLineEdit *lineEdit_bordName_4;
    QLabel *label_DataZayavitel_2;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_BordName_6;
    QLineEdit *lineEdit_bordName_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_BordName_7;
    QLineEdit *lineEdit_TechName;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_BordName_8;
    QLineEdit *lineEdit_bordName_8;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_BordName_9;
    QLineEdit *lineEdit_bordName_9;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_BordName_10;
    QLineEdit *lineEdit_bordName_10;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_BordName_11;
    QLineEdit *lineEdit_bordName_11;
    QLabel *label_DataZayavitel_5;
    QTextEdit *textEdit;
    QLabel *label_DataZayavitel_4;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QLabel *label_3;
    QTextEdit *textEdit_3;
    QLabel *label_DataZayavitel_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_19;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_4;
    QLabel *label_SubBordName;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_7;
    QLabel *label_SubTechName;

    void setupUi(QWidget *PrintOrder)
    {
        if (PrintOrder->objectName().isEmpty())
            PrintOrder->setObjectName(QString::fromUtf8("PrintOrder"));
        PrintOrder->setEnabled(true);
        PrintOrder->resize(750, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PrintOrder->sizePolicy().hasHeightForWidth());
        PrintOrder->setSizePolicy(sizePolicy);
        PrintOrder->setMinimumSize(QSize(750, 1080));
        PrintOrder->setMaximumSize(QSize(750, 1127));
        line_2 = new QFrame(PrintOrder);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(50, 1040, 131, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(PrintOrder);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(550, 1040, 130, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(PrintOrder);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(250, 1040, 131, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(PrintOrder);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 762, 971));
        verticalLayout_7 = new QVBoxLayout(layoutWidget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        img_logo = new QLabel(layoutWidget);
        img_logo->setObjectName(QString::fromUtf8("img_logo"));
        sizePolicy.setHeightForWidth(img_logo->sizePolicy().hasHeightForWidth());
        img_logo->setSizePolicy(sizePolicy);
        img_logo->setMinimumSize(QSize(150, 88));
        img_logo->setMaximumSize(QSize(150, 88));

        horizontalLayout_2->addWidget(img_logo);

        horizontalSpacer_5 = new QSpacerItem(160, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        txt_logo_1 = new QLabel(layoutWidget);
        txt_logo_1->setObjectName(QString::fromUtf8("txt_logo_1"));
        sizePolicy.setHeightForWidth(txt_logo_1->sizePolicy().hasHeightForWidth());
        txt_logo_1->setSizePolicy(sizePolicy);
        txt_logo_1->setMinimumSize(QSize(150, 88));
        txt_logo_1->setMaximumSize(QSize(150, 88));

        horizontalLayout_2->addWidget(txt_logo_1);

        horizontalSpacer_6 = new QSpacerItem(200, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        txt_logo_id = new QLabel(layoutWidget);
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

        label = new QLabel(layoutWidget);
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

        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        verticalLayout_7->addLayout(verticalLayout_2);

        label_DataZayavitel = new QLabel(layoutWidget);
        label_DataZayavitel->setObjectName(QString::fromUtf8("label_DataZayavitel"));
        sizePolicy.setHeightForWidth(label_DataZayavitel->sizePolicy().hasHeightForWidth());
        label_DataZayavitel->setSizePolicy(sizePolicy);
        label_DataZayavitel->setMinimumSize(QSize(760, 30));
        label_DataZayavitel->setMaximumSize(QSize(800, 30));
        label_DataZayavitel->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));
        label_DataZayavitel->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_DataZayavitel);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_BordName = new QLabel(layoutWidget);
        label_BordName->setObjectName(QString::fromUtf8("label_BordName"));
        sizePolicy.setHeightForWidth(label_BordName->sizePolicy().hasHeightForWidth());
        label_BordName->setSizePolicy(sizePolicy);
        label_BordName->setMinimumSize(QSize(25, 16));
        label_BordName->setMaximumSize(QSize(25, 16));

        horizontalLayout_3->addWidget(label_BordName);

        lineEdit_bordName = new QLineEdit(layoutWidget);
        lineEdit_bordName->setObjectName(QString::fromUtf8("lineEdit_bordName"));
        lineEdit_bordName->setMinimumSize(QSize(260, 16));
        lineEdit_bordName->setMaximumSize(QSize(400, 16));
        lineEdit_bordName->setStyleSheet(QString::fromUtf8("background: transparent;"));
        lineEdit_bordName->setMaxLength(50);
        lineEdit_bordName->setFrame(false);

        horizontalLayout_3->addWidget(lineEdit_bordName);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_BordName_2 = new QLabel(layoutWidget);
        label_BordName_2->setObjectName(QString::fromUtf8("label_BordName_2"));
        sizePolicy.setHeightForWidth(label_BordName_2->sizePolicy().hasHeightForWidth());
        label_BordName_2->setSizePolicy(sizePolicy);
        label_BordName_2->setMinimumSize(QSize(56, 16));
        label_BordName_2->setMaximumSize(QSize(25, 16));

        horizontalLayout_4->addWidget(label_BordName_2);

        lineEdit_bordName_2 = new QLineEdit(layoutWidget);
        lineEdit_bordName_2->setObjectName(QString::fromUtf8("lineEdit_bordName_2"));
        lineEdit_bordName_2->setMinimumSize(QSize(230, 16));
        lineEdit_bordName_2->setMaximumSize(QSize(400, 16));
        lineEdit_bordName_2->setStyleSheet(QString::fromUtf8("background: transparent;"));
        lineEdit_bordName_2->setMaxLength(50);
        lineEdit_bordName_2->setFrame(false);

        horizontalLayout_4->addWidget(lineEdit_bordName_2);


        verticalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_BordName_3 = new QLabel(layoutWidget);
        label_BordName_3->setObjectName(QString::fromUtf8("label_BordName_3"));
        sizePolicy.setHeightForWidth(label_BordName_3->sizePolicy().hasHeightForWidth());
        label_BordName_3->setSizePolicy(sizePolicy);
        label_BordName_3->setMinimumSize(QSize(25, 16));
        label_BordName_3->setMaximumSize(QSize(45, 16));

        horizontalLayout_5->addWidget(label_BordName_3);

        lineEdit_bordName_3 = new QLineEdit(layoutWidget);
        lineEdit_bordName_3->setObjectName(QString::fromUtf8("lineEdit_bordName_3"));
        lineEdit_bordName_3->setMinimumSize(QSize(250, 16));
        lineEdit_bordName_3->setMaximumSize(QSize(400, 16));
        lineEdit_bordName_3->setStyleSheet(QString::fromUtf8("background: transparent;"));
        lineEdit_bordName_3->setMaxLength(50);
        lineEdit_bordName_3->setFrame(false);

        horizontalLayout_5->addWidget(lineEdit_bordName_3);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_BordName_4 = new QLabel(layoutWidget);
        label_BordName_4->setObjectName(QString::fromUtf8("label_BordName_4"));
        sizePolicy.setHeightForWidth(label_BordName_4->sizePolicy().hasHeightForWidth());
        label_BordName_4->setSizePolicy(sizePolicy);
        label_BordName_4->setMinimumSize(QSize(40, 16));
        label_BordName_4->setMaximumSize(QSize(50, 16));

        horizontalLayout_6->addWidget(label_BordName_4);

        lineEdit_bordName_4 = new QLineEdit(layoutWidget);
        lineEdit_bordName_4->setObjectName(QString::fromUtf8("lineEdit_bordName_4"));
        lineEdit_bordName_4->setMinimumSize(QSize(245, 16));
        lineEdit_bordName_4->setMaximumSize(QSize(400, 16));
        lineEdit_bordName_4->setStyleSheet(QString::fromUtf8("background: transparent;"));
        lineEdit_bordName_4->setMaxLength(50);
        lineEdit_bordName_4->setFrame(false);

        horizontalLayout_6->addWidget(lineEdit_bordName_4);


        verticalLayout_4->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout_4);


        verticalLayout_7->addLayout(horizontalLayout_7);

        label_DataZayavitel_2 = new QLabel(layoutWidget);
        label_DataZayavitel_2->setObjectName(QString::fromUtf8("label_DataZayavitel_2"));
        sizePolicy.setHeightForWidth(label_DataZayavitel_2->sizePolicy().hasHeightForWidth());
        label_DataZayavitel_2->setSizePolicy(sizePolicy);
        label_DataZayavitel_2->setMinimumSize(QSize(760, 30));
        label_DataZayavitel_2->setMaximumSize(QSize(800, 30));
        label_DataZayavitel_2->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));
        label_DataZayavitel_2->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_DataZayavitel_2);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_BordName_6 = new QLabel(layoutWidget);
        label_BordName_6->setObjectName(QString::fromUtf8("label_BordName_6"));
        sizePolicy.setHeightForWidth(label_BordName_6->sizePolicy().hasHeightForWidth());
        label_BordName_6->setSizePolicy(sizePolicy);
        label_BordName_6->setMinimumSize(QSize(60, 16));
        label_BordName_6->setMaximumSize(QSize(60, 16));

        horizontalLayout_9->addWidget(label_BordName_6);

        lineEdit_bordName_6 = new QLineEdit(layoutWidget);
        lineEdit_bordName_6->setObjectName(QString::fromUtf8("lineEdit_bordName_6"));
        lineEdit_bordName_6->setMinimumSize(QSize(230, 16));
        lineEdit_bordName_6->setMaximumSize(QSize(400, 16));
        lineEdit_bordName_6->setStyleSheet(QString::fromUtf8("background: transparent;"));
        lineEdit_bordName_6->setMaxLength(50);
        lineEdit_bordName_6->setFrame(false);

        horizontalLayout_9->addWidget(lineEdit_bordName_6);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_BordName_7 = new QLabel(layoutWidget);
        label_BordName_7->setObjectName(QString::fromUtf8("label_BordName_7"));
        sizePolicy.setHeightForWidth(label_BordName_7->sizePolicy().hasHeightForWidth());
        label_BordName_7->setSizePolicy(sizePolicy);
        label_BordName_7->setMinimumSize(QSize(150, 16));
        label_BordName_7->setMaximumSize(QSize(65, 16));

        horizontalLayout_10->addWidget(label_BordName_7);

        lineEdit_TechName = new QLineEdit(layoutWidget);
        lineEdit_TechName->setObjectName(QString::fromUtf8("lineEdit_TechName"));
        lineEdit_TechName->setMinimumSize(QSize(120, 16));
        lineEdit_TechName->setMaximumSize(QSize(400, 16));
        lineEdit_TechName->setStyleSheet(QString::fromUtf8("background: transparent;"));
        lineEdit_TechName->setMaxLength(40);
        lineEdit_TechName->setFrame(false);

        horizontalLayout_10->addWidget(lineEdit_TechName);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_BordName_8 = new QLabel(layoutWidget);
        label_BordName_8->setObjectName(QString::fromUtf8("label_BordName_8"));
        sizePolicy.setHeightForWidth(label_BordName_8->sizePolicy().hasHeightForWidth());
        label_BordName_8->setSizePolicy(sizePolicy);
        label_BordName_8->setMinimumSize(QSize(90, 16));
        label_BordName_8->setMaximumSize(QSize(90, 16));

        horizontalLayout_11->addWidget(label_BordName_8);

        lineEdit_bordName_8 = new QLineEdit(layoutWidget);
        lineEdit_bordName_8->setObjectName(QString::fromUtf8("lineEdit_bordName_8"));
        lineEdit_bordName_8->setMinimumSize(QSize(200, 16));
        lineEdit_bordName_8->setMaximumSize(QSize(400, 16));
        lineEdit_bordName_8->setStyleSheet(QString::fromUtf8("background: transparent;"));
        lineEdit_bordName_8->setMaxLength(50);
        lineEdit_bordName_8->setFrame(false);

        horizontalLayout_11->addWidget(lineEdit_bordName_8);


        verticalLayout_3->addLayout(horizontalLayout_11);


        horizontalLayout_15->addLayout(verticalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_BordName_9 = new QLabel(layoutWidget);
        label_BordName_9->setObjectName(QString::fromUtf8("label_BordName_9"));
        sizePolicy.setHeightForWidth(label_BordName_9->sizePolicy().hasHeightForWidth());
        label_BordName_9->setSizePolicy(sizePolicy);
        label_BordName_9->setMinimumSize(QSize(140, 16));
        label_BordName_9->setMaximumSize(QSize(140, 16));

        horizontalLayout_12->addWidget(label_BordName_9);

        lineEdit_bordName_9 = new QLineEdit(layoutWidget);
        lineEdit_bordName_9->setObjectName(QString::fromUtf8("lineEdit_bordName_9"));
        lineEdit_bordName_9->setMinimumSize(QSize(150, 16));
        lineEdit_bordName_9->setMaximumSize(QSize(400, 16));
        lineEdit_bordName_9->setStyleSheet(QString::fromUtf8("background: transparent;"));
        lineEdit_bordName_9->setMaxLength(40);
        lineEdit_bordName_9->setFrame(false);

        horizontalLayout_12->addWidget(lineEdit_bordName_9);


        verticalLayout_6->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_BordName_10 = new QLabel(layoutWidget);
        label_BordName_10->setObjectName(QString::fromUtf8("label_BordName_10"));
        sizePolicy.setHeightForWidth(label_BordName_10->sizePolicy().hasHeightForWidth());
        label_BordName_10->setSizePolicy(sizePolicy);
        label_BordName_10->setMinimumSize(QSize(45, 16));
        label_BordName_10->setMaximumSize(QSize(45, 16));

        horizontalLayout_13->addWidget(label_BordName_10);

        lineEdit_bordName_10 = new QLineEdit(layoutWidget);
        lineEdit_bordName_10->setObjectName(QString::fromUtf8("lineEdit_bordName_10"));
        lineEdit_bordName_10->setMinimumSize(QSize(245, 16));
        lineEdit_bordName_10->setMaximumSize(QSize(400, 16));
        lineEdit_bordName_10->setStyleSheet(QString::fromUtf8("background: transparent;"));
        lineEdit_bordName_10->setMaxLength(50);
        lineEdit_bordName_10->setFrame(false);

        horizontalLayout_13->addWidget(lineEdit_bordName_10);


        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_BordName_11 = new QLabel(layoutWidget);
        label_BordName_11->setObjectName(QString::fromUtf8("label_BordName_11"));
        sizePolicy.setHeightForWidth(label_BordName_11->sizePolicy().hasHeightForWidth());
        label_BordName_11->setSizePolicy(sizePolicy);
        label_BordName_11->setMinimumSize(QSize(45, 16));
        label_BordName_11->setMaximumSize(QSize(45, 16));

        horizontalLayout_14->addWidget(label_BordName_11);

        lineEdit_bordName_11 = new QLineEdit(layoutWidget);
        lineEdit_bordName_11->setObjectName(QString::fromUtf8("lineEdit_bordName_11"));
        lineEdit_bordName_11->setMinimumSize(QSize(245, 16));
        lineEdit_bordName_11->setMaximumSize(QSize(400, 16));
        lineEdit_bordName_11->setStyleSheet(QString::fromUtf8("background: transparent;"));
        lineEdit_bordName_11->setMaxLength(50);
        lineEdit_bordName_11->setFrame(false);

        horizontalLayout_14->addWidget(lineEdit_bordName_11);


        verticalLayout_6->addLayout(horizontalLayout_14);


        horizontalLayout_15->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout_15);

        label_DataZayavitel_5 = new QLabel(layoutWidget);
        label_DataZayavitel_5->setObjectName(QString::fromUtf8("label_DataZayavitel_5"));
        sizePolicy.setHeightForWidth(label_DataZayavitel_5->sizePolicy().hasHeightForWidth());
        label_DataZayavitel_5->setSizePolicy(sizePolicy);
        label_DataZayavitel_5->setMinimumSize(QSize(760, 30));
        label_DataZayavitel_5->setMaximumSize(QSize(800, 30));
        label_DataZayavitel_5->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));
        label_DataZayavitel_5->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_DataZayavitel_5);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 240));
        textEdit->setStyleSheet(QString::fromUtf8("background: transparent;"));
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setFrameShadow(QFrame::Plain);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        verticalLayout_7->addWidget(textEdit);

        label_DataZayavitel_4 = new QLabel(layoutWidget);
        label_DataZayavitel_4->setObjectName(QString::fromUtf8("label_DataZayavitel_4"));
        sizePolicy.setHeightForWidth(label_DataZayavitel_4->sizePolicy().hasHeightForWidth());
        label_DataZayavitel_4->setSizePolicy(sizePolicy);
        label_DataZayavitel_4->setMinimumSize(QSize(760, 30));
        label_DataZayavitel_4->setMaximumSize(QSize(800, 30));
        label_DataZayavitel_4->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));
        label_DataZayavitel_4->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_DataZayavitel_4);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 16));

        verticalLayout_7->addWidget(label_2);

        textEdit_2 = new QTextEdit(layoutWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setMaximumSize(QSize(16777215, 200));
        textEdit_2->setStyleSheet(QString::fromUtf8("background: transparent;"));
        textEdit_2->setFrameShape(QFrame::NoFrame);
        textEdit_2->setFrameShadow(QFrame::Plain);
        textEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        verticalLayout_7->addWidget(textEdit_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 16));

        verticalLayout_7->addWidget(label_3);

        textEdit_3 = new QTextEdit(layoutWidget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setMaximumSize(QSize(16777215, 140));
        textEdit_3->setStyleSheet(QString::fromUtf8("background: transparent;"));
        textEdit_3->setFrameShape(QFrame::NoFrame);
        textEdit_3->setFrameShadow(QFrame::Plain);
        textEdit_3->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        verticalLayout_7->addWidget(textEdit_3);

        label_DataZayavitel_3 = new QLabel(layoutWidget);
        label_DataZayavitel_3->setObjectName(QString::fromUtf8("label_DataZayavitel_3"));
        sizePolicy.setHeightForWidth(label_DataZayavitel_3->sizePolicy().hasHeightForWidth());
        label_DataZayavitel_3->setSizePolicy(sizePolicy);
        label_DataZayavitel_3->setMinimumSize(QSize(600, 30));
        label_DataZayavitel_3->setMaximumSize(QSize(800, 30));
        label_DataZayavitel_3->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));
        label_DataZayavitel_3->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_DataZayavitel_3);

        layoutWidget1 = new QWidget(PrintOrder);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 1050, 722, 20));
        horizontalLayout_19 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(70, 16));
        label_4->setMaximumSize(QSize(70, 16));

        horizontalLayout_16->addWidget(label_4);

        label_SubBordName = new QLabel(layoutWidget1);
        label_SubBordName->setObjectName(QString::fromUtf8("label_SubBordName"));
        sizePolicy.setHeightForWidth(label_SubBordName->sizePolicy().hasHeightForWidth());
        label_SubBordName->setSizePolicy(sizePolicy);
        label_SubBordName->setMinimumSize(QSize(120, 16));
        label_SubBordName->setMaximumSize(QSize(100, 16));

        horizontalLayout_16->addWidget(label_SubBordName);


        horizontalLayout_19->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(170, 16));
        label_6->setMaximumSize(QSize(170, 16));

        horizontalLayout_17->addWidget(label_6);


        horizontalLayout_19->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(150, 16));
        label_7->setMaximumSize(QSize(70, 16));

        horizontalLayout_18->addWidget(label_7);

        label_SubTechName = new QLabel(layoutWidget1);
        label_SubTechName->setObjectName(QString::fromUtf8("label_SubTechName"));
        sizePolicy.setHeightForWidth(label_SubTechName->sizePolicy().hasHeightForWidth());
        label_SubTechName->setSizePolicy(sizePolicy);
        label_SubTechName->setMinimumSize(QSize(180, 16));
        label_SubTechName->setMaximumSize(QSize(100, 16));

        horizontalLayout_18->addWidget(label_SubTechName);


        horizontalLayout_19->addLayout(horizontalLayout_18);


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
        label_DataZayavitel->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\320\224\320\260\320\275\320\275\321\213\320\265 \320\267\320\260\321\217\320\262\320\270\321\202\320\265\320\273\321\217</span></p></body></html>", nullptr));
        label_BordName->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\230\320\274\321\217:</span></p></body></html>", nullptr));
        label_BordName_2->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\242\320\265\320\273\320\265\321\204\320\276\320\275:</span></p></body></html>", nullptr));
        label_BordName_3->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">E-mail:</span></p></body></html>", nullptr));
        label_BordName_4->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\236\321\202\320\264\320\265\320\273:</span></p></body></html>", nullptr));
        label_DataZayavitel_2->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\320\224\320\265\321\202\320\260\320\273\320\270 \320\267\320\260\321\217\320\262\320\272\320\270</span></p></body></html>", nullptr));
        label_BordName_6->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:</span></p></body></html>", nullptr));
        label_BordName_7->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\242\320\265\321\205\320\275\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\320\270\321\201\321\202:</span></p></body></html>", nullptr));
        label_BordName_8->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\236\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\275\320\270\320\265:</span></p></body></html>", nullptr));
        label_BordName_9->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\224\320\260\321\202\320\260/\320\222\321\200\320\265\320\274\321\217 \320\276\321\202\320\272\321\200\321\213\321\202\320\270\321\217:</span></p></body></html>", nullptr));
        label_BordName_10->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\227\320\260\320\277\320\270\321\201\321\214:</span></p></body></html>", nullptr));
        label_BordName_11->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\222\321\213\321\205\320\276\320\264:</span></p></body></html>", nullptr));
        label_DataZayavitel_5->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\262\321\213\320\267\320\276\320\262\320\260</span></p></body></html>", nullptr));
        label_DataZayavitel_4->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\320\240\320\265\321\210\320\265\320\275\320\270\321\217</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \321\200\320\265\321\210\320\265\320\275\320\270\321\217:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\230\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\320\274\321\213\320\265 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\321\213:</span></p></body></html>", nullptr));
        label_DataZayavitel_3->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\320\237\320\276\320\264\320\277\320\270\321\201\320\270</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\227\320\260\321\217\320\262\320\270\321\202\320\265\320\273\321\214:</span></p></body></html>", nullptr));
        label_SubBordName->setText(QString());
        label_6->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\234\320\265\320\275\320\265\320\264\320\266\320\265\321\200 \320\274\320\265\321\201\321\202\320\276\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("PrintOrder", "<html><head/><body><p><span style=\" font-weight:600;\">\320\242\320\265\321\205\320\275\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\320\270\321\201\321\202:</span></p></body></html>", nullptr));
        label_SubTechName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PrintOrder: public Ui_PrintOrder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTORDER_H
