/********************************************************************************
** Form generated from reading UI file 'actions_right.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIONS_RIGHT_H
#define UI_ACTIONS_RIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Actions_right
{
public:
    QGroupBox *groupBox_work;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_editWork;
    QSpacerItem *horizontalSpacer_14;
    QCheckBox *checkBox_work;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_work_title;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QTextEdit *textEdit_work_desc;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_work_dates;
    QLabel *label_work_worker;
    QSpacerItem *horizontalSpacer_5;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_curDate;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_cre_name;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_descr;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_descr_id;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_descr_title;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_11;
    QTextEdit *textEdit_descr_desc;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QGroupBox *groupBox_messege;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_mess_helpdesk;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_13;
    QTextEdit *textEdit_mess_text;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_delAct;
    QGroupBox *groupBox_agreement;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QTextEdit *textEdit_text_agree;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_date_name_agree;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_agreement_color;

    void setupUi(QWidget *Actions_right)
    {
        if (Actions_right->objectName().isEmpty())
            Actions_right->setObjectName(QString::fromUtf8("Actions_right"));
        Actions_right->resize(1220, 183);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Actions_right->sizePolicy().hasHeightForWidth());
        Actions_right->setSizePolicy(sizePolicy);
        Actions_right->setMinimumSize(QSize(1220, 183));
        Actions_right->setMaximumSize(QSize(1220, 16777215));
        groupBox_work = new QGroupBox(Actions_right);
        groupBox_work->setObjectName(QString::fromUtf8("groupBox_work"));
        groupBox_work->setGeometry(QRect(370, 20, 651, 151));
        sizePolicy.setHeightForWidth(groupBox_work->sizePolicy().hasHeightForWidth());
        groupBox_work->setSizePolicy(sizePolicy);
        groupBox_work->setMinimumSize(QSize(651, 151));
        groupBox_work->setLayoutDirection(Qt::RightToLeft);
        groupBox_work->setStyleSheet(QString::fromUtf8("background: rgba(244, 164, 96, 0.6);"));
        verticalLayout_9 = new QVBoxLayout(groupBox_work);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        pushButton_editWork = new QPushButton(groupBox_work);
        pushButton_editWork->setObjectName(QString::fromUtf8("pushButton_editWork"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_editWork->sizePolicy().hasHeightForWidth());
        pushButton_editWork->setSizePolicy(sizePolicy1);
        pushButton_editWork->setMinimumSize(QSize(24, 24));
        pushButton_editWork->setMaximumSize(QSize(24, 24));
        pushButton_editWork->setCursor(QCursor(Qt::ClosedHandCursor));
        pushButton_editWork->setStyleSheet(QString::fromUtf8("background: transparent;"));
        pushButton_editWork->setIconSize(QSize(24, 24));

        horizontalLayout_11->addWidget(pushButton_editWork);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_14);

        checkBox_work = new QCheckBox(groupBox_work);
        checkBox_work->setObjectName(QString::fromUtf8("checkBox_work"));
        sizePolicy1.setHeightForWidth(checkBox_work->sizePolicy().hasHeightForWidth());
        checkBox_work->setSizePolicy(sizePolicy1);
        checkBox_work->setMinimumSize(QSize(20, 20));
        checkBox_work->setStyleSheet(QString::fromUtf8("background: transparent;"));
        checkBox_work->setIconSize(QSize(16, 16));

        horizontalLayout_11->addWidget(checkBox_work);


        verticalLayout_9->addLayout(horizontalLayout_11);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_15);

        label_work_title = new QLabel(groupBox_work);
        label_work_title->setObjectName(QString::fromUtf8("label_work_title"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_work_title->sizePolicy().hasHeightForWidth());
        label_work_title->setSizePolicy(sizePolicy2);
        label_work_title->setMinimumSize(QSize(0, 16));
        label_work_title->setMaximumSize(QSize(500, 16777215));
        label_work_title->setStyleSheet(QString::fromUtf8("background: transparent;"));

        horizontalLayout_14->addWidget(label_work_title);


        verticalLayout_9->addLayout(horizontalLayout_14);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        textEdit_work_desc = new QTextEdit(groupBox_work);
        textEdit_work_desc->setObjectName(QString::fromUtf8("textEdit_work_desc"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textEdit_work_desc->sizePolicy().hasHeightForWidth());
        textEdit_work_desc->setSizePolicy(sizePolicy3);
        textEdit_work_desc->setMinimumSize(QSize(500, 16));
        textEdit_work_desc->setMaximumSize(QSize(500, 16777215));
        textEdit_work_desc->setStyleSheet(QString::fromUtf8("background: transparent;"));
        textEdit_work_desc->setFrameShape(QFrame::NoFrame);
        textEdit_work_desc->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_work_desc->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_work_desc->setTextInteractionFlags(Qt::TextSelectableByMouse);

        horizontalLayout_5->addWidget(textEdit_work_desc);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_work_dates = new QLabel(groupBox_work);
        label_work_dates->setObjectName(QString::fromUtf8("label_work_dates"));
        sizePolicy2.setHeightForWidth(label_work_dates->sizePolicy().hasHeightForWidth());
        label_work_dates->setSizePolicy(sizePolicy2);
        label_work_dates->setMinimumSize(QSize(0, 16));
        label_work_dates->setLayoutDirection(Qt::RightToLeft);
        label_work_dates->setStyleSheet(QString::fromUtf8("color: rgb(128, 128, 128); background: transparent;"));

        verticalLayout_2->addWidget(label_work_dates);

        label_work_worker = new QLabel(groupBox_work);
        label_work_worker->setObjectName(QString::fromUtf8("label_work_worker"));
        sizePolicy2.setHeightForWidth(label_work_worker->sizePolicy().hasHeightForWidth());
        label_work_worker->setSizePolicy(sizePolicy2);
        label_work_worker->setMinimumSize(QSize(0, 16));
        label_work_worker->setLayoutDirection(Qt::RightToLeft);
        label_work_worker->setStyleSheet(QString::fromUtf8("color: rgb(128, 128, 128); background: transparent;"));
        label_work_worker->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_work_worker);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_9->addLayout(verticalLayout_3);

        layoutWidget = new QWidget(Actions_right);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1040, 20, 160, 129));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setPixmap(QPixmap(QString::fromUtf8("img/11clock.png")));

        horizontalLayout->addWidget(label);

        label_curDate = new QLabel(layoutWidget);
        label_curDate->setObjectName(QString::fromUtf8("label_curDate"));

        horizontalLayout->addWidget(label_curDate);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setPixmap(QPixmap(QString::fromUtf8("img/user.png")));
        label_2->setScaledContents(true);

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_cre_name = new QLabel(layoutWidget);
        label_cre_name->setObjectName(QString::fromUtf8("label_cre_name"));

        horizontalLayout_2->addWidget(label_cre_name);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox_descr = new QGroupBox(Actions_right);
        groupBox_descr->setObjectName(QString::fromUtf8("groupBox_descr"));
        groupBox_descr->setGeometry(QRect(220, 20, 801, 151));
        sizePolicy.setHeightForWidth(groupBox_descr->sizePolicy().hasHeightForWidth());
        groupBox_descr->setSizePolicy(sizePolicy);
        groupBox_descr->setMinimumSize(QSize(801, 151));
        groupBox_descr->setMaximumSize(QSize(801, 16777215));
        groupBox_descr->setLayoutDirection(Qt::RightToLeft);
        groupBox_descr->setStyleSheet(QString::fromUtf8("background: rgba(60, 179, 113, 0.6);"));
        verticalLayout_6 = new QVBoxLayout(groupBox_descr);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_descr_id = new QLabel(groupBox_descr);
        label_descr_id->setObjectName(QString::fromUtf8("label_descr_id"));
        sizePolicy2.setHeightForWidth(label_descr_id->sizePolicy().hasHeightForWidth());
        label_descr_id->setSizePolicy(sizePolicy2);
        label_descr_id->setLayoutDirection(Qt::RightToLeft);
        label_descr_id->setStyleSheet(QString::fromUtf8("color: rgb(128, 128, 128); background: transparent;"));

        horizontalLayout_8->addWidget(label_descr_id);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);


        verticalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_10);

        label_descr_title = new QLabel(groupBox_descr);
        label_descr_title->setObjectName(QString::fromUtf8("label_descr_title"));
        sizePolicy2.setHeightForWidth(label_descr_title->sizePolicy().hasHeightForWidth());
        label_descr_title->setSizePolicy(sizePolicy2);
        label_descr_title->setMaximumSize(QSize(700, 16777215));
        label_descr_title->setStyleSheet(QString::fromUtf8("background: transparent;"));

        horizontalLayout_9->addWidget(label_descr_title);


        verticalLayout_6->addLayout(horizontalLayout_9);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_11);

        textEdit_descr_desc = new QTextEdit(groupBox_descr);
        textEdit_descr_desc->setObjectName(QString::fromUtf8("textEdit_descr_desc"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textEdit_descr_desc->sizePolicy().hasHeightForWidth());
        textEdit_descr_desc->setSizePolicy(sizePolicy4);
        textEdit_descr_desc->setMinimumSize(QSize(500, 16));
        textEdit_descr_desc->setMaximumSize(QSize(500, 16777215));
        textEdit_descr_desc->setStyleSheet(QString::fromUtf8("background: transparent;"));
        textEdit_descr_desc->setFrameShape(QFrame::NoFrame);
        textEdit_descr_desc->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_descr_desc->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_descr_desc->setTextInteractionFlags(Qt::TextSelectableByMouse);

        horizontalLayout_10->addWidget(textEdit_descr_desc);


        verticalLayout_5->addLayout(horizontalLayout_10);

        verticalSpacer = new QSpacerItem(20, 6000, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        verticalLayout_6->addLayout(verticalLayout_5);

        line = new QFrame(Actions_right);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 0, 1201, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_messege = new QGroupBox(Actions_right);
        groupBox_messege->setObjectName(QString::fromUtf8("groupBox_messege"));
        groupBox_messege->setGeometry(QRect(370, 20, 651, 151));
        sizePolicy.setHeightForWidth(groupBox_messege->sizePolicy().hasHeightForWidth());
        groupBox_messege->setSizePolicy(sizePolicy);
        groupBox_messege->setMinimumSize(QSize(651, 151));
        groupBox_messege->setLayoutDirection(Qt::RightToLeft);
        groupBox_messege->setStyleSheet(QString::fromUtf8("background: rgba(192, 192, 192, 0.6);\n"
""));
        verticalLayout_8 = new QVBoxLayout(groupBox_messege);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_mess_helpdesk = new QLabel(groupBox_messege);
        label_mess_helpdesk->setObjectName(QString::fromUtf8("label_mess_helpdesk"));
        sizePolicy1.setHeightForWidth(label_mess_helpdesk->sizePolicy().hasHeightForWidth());
        label_mess_helpdesk->setSizePolicy(sizePolicy1);
        label_mess_helpdesk->setMinimumSize(QSize(47, 16));
        label_mess_helpdesk->setMaximumSize(QSize(47, 16));
        label_mess_helpdesk->setLayoutDirection(Qt::RightToLeft);
        label_mess_helpdesk->setStyleSheet(QString::fromUtf8("color: rgb(128, 128, 128); background: transparent;"));

        horizontalLayout_12->addWidget(label_mess_helpdesk);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_12);


        verticalLayout_8->addLayout(horizontalLayout_12);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_13);

        textEdit_mess_text = new QTextEdit(groupBox_messege);
        textEdit_mess_text->setObjectName(QString::fromUtf8("textEdit_mess_text"));
        sizePolicy4.setHeightForWidth(textEdit_mess_text->sizePolicy().hasHeightForWidth());
        textEdit_mess_text->setSizePolicy(sizePolicy4);
        textEdit_mess_text->setMinimumSize(QSize(500, 16));
        textEdit_mess_text->setMaximumSize(QSize(500, 16777215));
        textEdit_mess_text->setStyleSheet(QString::fromUtf8("background: transparent;"));
        textEdit_mess_text->setFrameShape(QFrame::NoFrame);
        textEdit_mess_text->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_mess_text->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_mess_text->setTextInteractionFlags(Qt::TextSelectableByMouse);

        horizontalLayout_13->addWidget(textEdit_mess_text);


        verticalLayout_7->addLayout(horizontalLayout_13);

        verticalSpacer_2 = new QSpacerItem(20, 9000, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);


        verticalLayout_8->addLayout(verticalLayout_7);

        pushButton_delAct = new QPushButton(Actions_right);
        pushButton_delAct->setObjectName(QString::fromUtf8("pushButton_delAct"));
        pushButton_delAct->setGeometry(QRect(10, 20, 24, 24));
        pushButton_delAct->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_delAct->setStyleSheet(QString::fromUtf8("background: transparent;"));
        pushButton_delAct->setIconSize(QSize(16, 16));
        groupBox_agreement = new QGroupBox(Actions_right);
        groupBox_agreement->setObjectName(QString::fromUtf8("groupBox_agreement"));
        groupBox_agreement->setGeometry(QRect(370, 20, 651, 151));
        sizePolicy.setHeightForWidth(groupBox_agreement->sizePolicy().hasHeightForWidth());
        groupBox_agreement->setSizePolicy(sizePolicy);
        groupBox_agreement->setMinimumSize(QSize(651, 151));
        groupBox_agreement->setLayoutDirection(Qt::RightToLeft);
        groupBox_agreement->setStyleSheet(QString::fromUtf8("background: rgba(135, 206, 250, 0.6);"));
        horizontalLayout_15 = new QHBoxLayout(groupBox_agreement);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        textEdit_text_agree = new QTextEdit(groupBox_agreement);
        textEdit_text_agree->setObjectName(QString::fromUtf8("textEdit_text_agree"));
        sizePolicy4.setHeightForWidth(textEdit_text_agree->sizePolicy().hasHeightForWidth());
        textEdit_text_agree->setSizePolicy(sizePolicy4);
        textEdit_text_agree->setMinimumSize(QSize(500, 16));
        textEdit_text_agree->setMaximumSize(QSize(500, 16777215));
        textEdit_text_agree->setStyleSheet(QString::fromUtf8("background: transparent;"));
        textEdit_text_agree->setFrameShape(QFrame::NoFrame);
        textEdit_text_agree->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_text_agree->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_text_agree->setTextInteractionFlags(Qt::TextSelectableByMouse);

        horizontalLayout_6->addWidget(textEdit_text_agree);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_date_name_agree = new QLabel(groupBox_agreement);
        label_date_name_agree->setObjectName(QString::fromUtf8("label_date_name_agree"));
        sizePolicy2.setHeightForWidth(label_date_name_agree->sizePolicy().hasHeightForWidth());
        label_date_name_agree->setSizePolicy(sizePolicy2);
        label_date_name_agree->setLayoutDirection(Qt::RightToLeft);
        label_date_name_agree->setStyleSheet(QString::fromUtf8("color: rgb(128, 128, 128); background: transparent;"));

        horizontalLayout_7->addWidget(label_date_name_agree);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout_10->addLayout(verticalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 9000, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_3);


        horizontalLayout_15->addLayout(verticalLayout_10);

        groupBox_agreement_color = new QGroupBox(groupBox_agreement);
        groupBox_agreement_color->setObjectName(QString::fromUtf8("groupBox_agreement_color"));
        sizePolicy.setHeightForWidth(groupBox_agreement_color->sizePolicy().hasHeightForWidth());
        groupBox_agreement_color->setSizePolicy(sizePolicy);
        groupBox_agreement_color->setMinimumSize(QSize(16, 0));
        groupBox_agreement_color->setAutoFillBackground(false);
        groupBox_agreement_color->setStyleSheet(QString::fromUtf8("background: green; border: 0; "));

        horizontalLayout_15->addWidget(groupBox_agreement_color);


        retranslateUi(Actions_right);

        QMetaObject::connectSlotsByName(Actions_right);
    } // setupUi

    void retranslateUi(QWidget *Actions_right)
    {
        Actions_right->setWindowTitle(QCoreApplication::translate("Actions_right", "Form", nullptr));
        groupBox_work->setTitle(QString());
        pushButton_editWork->setText(QString());
        checkBox_work->setText(QString());
        label_work_title->setText(QCoreApplication::translate("Actions_right", "TextLabel", nullptr));
        label_work_dates->setText(QCoreApplication::translate("Actions_right", "TextLabel", nullptr));
        label_work_worker->setText(QCoreApplication::translate("Actions_right", "TextLabel", nullptr));
        label->setText(QString());
        label_curDate->setText(QCoreApplication::translate("Actions_right", "TextLabel", nullptr));
        label_2->setText(QString());
        label_cre_name->setText(QCoreApplication::translate("Actions_right", "TextLabel", nullptr));
        groupBox_descr->setTitle(QString());
        label_descr_id->setText(QCoreApplication::translate("Actions_right", "TextLabel", nullptr));
        label_descr_title->setText(QCoreApplication::translate("Actions_right", "TextLabel", nullptr));
        groupBox_messege->setTitle(QString());
        label_mess_helpdesk->setText(QCoreApplication::translate("Actions_right", "Helpdesk", nullptr));
        pushButton_delAct->setText(QString());
        groupBox_agreement->setTitle(QString());
        label_date_name_agree->setText(QCoreApplication::translate("Actions_right", "TextLabel", nullptr));
        groupBox_agreement_color->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class Actions_right: public Ui_Actions_right {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONS_RIGHT_H
