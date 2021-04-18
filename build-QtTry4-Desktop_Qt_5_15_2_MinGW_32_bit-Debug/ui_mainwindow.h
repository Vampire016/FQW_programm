/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickablewidget.h"
#include "qtabwidget_v.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *act_home;
    QAction *act_orders;
    QAction *act_editOrd;
    QAction *act_print;
    QAction *act_return;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QPushButton *PB_wOpened;
    QSplitter *splitter_2;
    QLabel *label_btn_Opend;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QSplitter *splitter_4;
    QSplitter *splitter_5;
    QPushButton *PB_wNew;
    QSplitter *splitter_6;
    QLabel *label_btn_New;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QSplitter *splitter_7;
    QSplitter *splitter_8;
    QPushButton *PB_wInWork;
    QSplitter *splitter_9;
    QLabel *label_btn_InWork;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QSplitter *splitter_10;
    QSplitter *splitter_11;
    QPushButton *PB_wSolved;
    QSplitter *splitter_12;
    QLabel *label_btn_Solved;
    QGroupBox *groupBox_10;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_6;
    QSplitter *splitter_13;
    QSplitter *splitter_14;
    QPushButton *PB_wAwaits;
    QSplitter *splitter_15;
    QLabel *label_btn_Awaits;
    QGroupBox *groupBox_11;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_7;
    QSplitter *splitter_16;
    QSplitter *splitter_17;
    QPushButton *PB_wOverdue;
    QSplitter *splitter_18;
    QLabel *label_btn_Overdue;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QTableView *tableView;
    QWidget *tab_3;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_2;
    TabWidget *tabWidget_2;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_7;
    QToolButton *toolButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_DataZayavitel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_6;
    QComboBox *comboBox_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label_7;
    QComboBox *comboBox_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_8;
    QComboBox *comboBox_7;
    QLabel *label_9;
    QComboBox *comboBox_8;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_10;
    QComboBox *comboBox_9;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_11;
    QLineEdit *lineEdit_6;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_12;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_12;
    ClickableWidget *tab_6;
    QVBoxLayout *verticalLayout_5;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        act_home = new QAction(MainWindow);
        act_home->setObjectName(QString::fromUtf8("act_home"));
        act_orders = new QAction(MainWindow);
        act_orders->setObjectName(QString::fromUtf8("act_orders"));
        act_editOrd = new QAction(MainWindow);
        act_editOrd->setObjectName(QString::fromUtf8("act_editOrd"));
        act_print = new QAction(MainWindow);
        act_print->setObjectName(QString::fromUtf8("act_print"));
        act_print->setVisible(true);
        act_return = new QAction(MainWindow);
        act_return->setObjectName(QString::fromUtf8("act_return"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(60, 100));
        groupBox->setMaximumSize(QSize(16777215, 80));
        groupBox->setAutoFillBackground(false);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        splitter_3 = new QSplitter(groupBox);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setMinimumSize(QSize(0, 81));
        splitter_3->setCursor(QCursor(Qt::ArrowCursor));
        splitter_3->setAutoFillBackground(false);
        splitter_3->setOrientation(Qt::Vertical);
        splitter_3->setOpaqueResize(false);
        splitter_3->setHandleWidth(0);
        splitter_3->setChildrenCollapsible(false);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMinimumSize(QSize(61, 50));
        splitter->setOrientation(Qt::Horizontal);
        PB_wOpened = new QPushButton(splitter);
        PB_wOpened->setObjectName(QString::fromUtf8("PB_wOpened"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(25);
        sizePolicy.setVerticalStretch(25);
        sizePolicy.setHeightForWidth(PB_wOpened->sizePolicy().hasHeightForWidth());
        PB_wOpened->setSizePolicy(sizePolicy);
        PB_wOpened->setMinimumSize(QSize(50, 50));
        PB_wOpened->setMaximumSize(QSize(25, 25));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        PB_wOpened->setFont(font);
        PB_wOpened->setCursor(QCursor(Qt::PointingHandCursor));
        splitter->addWidget(PB_wOpened);
        splitter_3->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setMinimumSize(QSize(71, 17));
        splitter_2->setOrientation(Qt::Horizontal);
        label_btn_Opend = new QLabel(splitter_2);
        label_btn_Opend->setObjectName(QString::fromUtf8("label_btn_Opend"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(15);
        sizePolicy1.setHeightForWidth(label_btn_Opend->sizePolicy().hasHeightForWidth());
        label_btn_Opend->setSizePolicy(sizePolicy1);
        label_btn_Opend->setMinimumSize(QSize(0, 15));
        label_btn_Opend->setLayoutDirection(Qt::LeftToRight);
        label_btn_Opend->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        splitter_2->addWidget(label_btn_Opend);
        splitter_3->addWidget(splitter_2);

        horizontalLayout_4->addWidget(splitter_3);


        horizontalLayout->addWidget(groupBox);

        groupBox_7 = new QGroupBox(tab);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(60, 100));
        groupBox_7->setMaximumSize(QSize(16777215, 80));
        groupBox_7->setAutoFillBackground(false);
        groupBox_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayout_5 = new QHBoxLayout(groupBox_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        splitter_4 = new QSplitter(groupBox_7);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setMinimumSize(QSize(0, 81));
        splitter_4->setCursor(QCursor(Qt::ArrowCursor));
        splitter_4->setAutoFillBackground(false);
        splitter_4->setOrientation(Qt::Vertical);
        splitter_4->setOpaqueResize(false);
        splitter_4->setHandleWidth(0);
        splitter_4->setChildrenCollapsible(false);
        splitter_5 = new QSplitter(splitter_4);
        splitter_5->setObjectName(QString::fromUtf8("splitter_5"));
        splitter_5->setMinimumSize(QSize(61, 50));
        splitter_5->setOrientation(Qt::Horizontal);
        PB_wNew = new QPushButton(splitter_5);
        PB_wNew->setObjectName(QString::fromUtf8("PB_wNew"));
        sizePolicy.setHeightForWidth(PB_wNew->sizePolicy().hasHeightForWidth());
        PB_wNew->setSizePolicy(sizePolicy);
        PB_wNew->setMinimumSize(QSize(50, 50));
        PB_wNew->setMaximumSize(QSize(25, 25));
        PB_wNew->setFont(font);
        PB_wNew->setCursor(QCursor(Qt::PointingHandCursor));
        splitter_5->addWidget(PB_wNew);
        splitter_4->addWidget(splitter_5);
        splitter_6 = new QSplitter(splitter_4);
        splitter_6->setObjectName(QString::fromUtf8("splitter_6"));
        splitter_6->setMinimumSize(QSize(71, 17));
        splitter_6->setOrientation(Qt::Horizontal);
        label_btn_New = new QLabel(splitter_6);
        label_btn_New->setObjectName(QString::fromUtf8("label_btn_New"));
        sizePolicy1.setHeightForWidth(label_btn_New->sizePolicy().hasHeightForWidth());
        label_btn_New->setSizePolicy(sizePolicy1);
        label_btn_New->setMinimumSize(QSize(0, 15));
        label_btn_New->setLayoutDirection(Qt::LeftToRight);
        label_btn_New->setAlignment(Qt::AlignCenter);
        splitter_6->addWidget(label_btn_New);
        splitter_4->addWidget(splitter_6);

        horizontalLayout_5->addWidget(splitter_4);


        horizontalLayout->addWidget(groupBox_7);

        groupBox_8 = new QGroupBox(tab);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setMinimumSize(QSize(60, 100));
        groupBox_8->setMaximumSize(QSize(16777215, 80));
        groupBox_8->setAutoFillBackground(false);
        groupBox_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayout_6 = new QHBoxLayout(groupBox_8);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        splitter_7 = new QSplitter(groupBox_8);
        splitter_7->setObjectName(QString::fromUtf8("splitter_7"));
        splitter_7->setMinimumSize(QSize(0, 81));
        splitter_7->setCursor(QCursor(Qt::ArrowCursor));
        splitter_7->setAutoFillBackground(false);
        splitter_7->setOrientation(Qt::Vertical);
        splitter_7->setOpaqueResize(false);
        splitter_7->setHandleWidth(0);
        splitter_7->setChildrenCollapsible(false);
        splitter_8 = new QSplitter(splitter_7);
        splitter_8->setObjectName(QString::fromUtf8("splitter_8"));
        splitter_8->setMinimumSize(QSize(61, 50));
        splitter_8->setOrientation(Qt::Horizontal);
        PB_wInWork = new QPushButton(splitter_8);
        PB_wInWork->setObjectName(QString::fromUtf8("PB_wInWork"));
        sizePolicy.setHeightForWidth(PB_wInWork->sizePolicy().hasHeightForWidth());
        PB_wInWork->setSizePolicy(sizePolicy);
        PB_wInWork->setMinimumSize(QSize(50, 50));
        PB_wInWork->setMaximumSize(QSize(25, 25));
        PB_wInWork->setFont(font);
        PB_wInWork->setCursor(QCursor(Qt::PointingHandCursor));
        splitter_8->addWidget(PB_wInWork);
        splitter_7->addWidget(splitter_8);
        splitter_9 = new QSplitter(splitter_7);
        splitter_9->setObjectName(QString::fromUtf8("splitter_9"));
        splitter_9->setMinimumSize(QSize(71, 17));
        splitter_9->setOrientation(Qt::Horizontal);
        label_btn_InWork = new QLabel(splitter_9);
        label_btn_InWork->setObjectName(QString::fromUtf8("label_btn_InWork"));
        sizePolicy1.setHeightForWidth(label_btn_InWork->sizePolicy().hasHeightForWidth());
        label_btn_InWork->setSizePolicy(sizePolicy1);
        label_btn_InWork->setMinimumSize(QSize(0, 15));
        label_btn_InWork->setLayoutDirection(Qt::LeftToRight);
        label_btn_InWork->setAlignment(Qt::AlignCenter);
        splitter_9->addWidget(label_btn_InWork);
        splitter_7->addWidget(splitter_9);

        horizontalLayout_6->addWidget(splitter_7);


        horizontalLayout->addWidget(groupBox_8);

        groupBox_9 = new QGroupBox(tab);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setMinimumSize(QSize(60, 100));
        groupBox_9->setMaximumSize(QSize(16777215, 80));
        groupBox_9->setAutoFillBackground(false);
        groupBox_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayout_7 = new QHBoxLayout(groupBox_9);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        splitter_10 = new QSplitter(groupBox_9);
        splitter_10->setObjectName(QString::fromUtf8("splitter_10"));
        splitter_10->setMinimumSize(QSize(0, 81));
        splitter_10->setCursor(QCursor(Qt::ArrowCursor));
        splitter_10->setAutoFillBackground(false);
        splitter_10->setOrientation(Qt::Vertical);
        splitter_10->setOpaqueResize(false);
        splitter_10->setHandleWidth(0);
        splitter_10->setChildrenCollapsible(false);
        splitter_11 = new QSplitter(splitter_10);
        splitter_11->setObjectName(QString::fromUtf8("splitter_11"));
        splitter_11->setMinimumSize(QSize(61, 50));
        splitter_11->setOrientation(Qt::Horizontal);
        PB_wSolved = new QPushButton(splitter_11);
        PB_wSolved->setObjectName(QString::fromUtf8("PB_wSolved"));
        sizePolicy.setHeightForWidth(PB_wSolved->sizePolicy().hasHeightForWidth());
        PB_wSolved->setSizePolicy(sizePolicy);
        PB_wSolved->setMinimumSize(QSize(50, 50));
        PB_wSolved->setMaximumSize(QSize(25, 25));
        PB_wSolved->setFont(font);
        PB_wSolved->setCursor(QCursor(Qt::PointingHandCursor));
        splitter_11->addWidget(PB_wSolved);
        splitter_10->addWidget(splitter_11);
        splitter_12 = new QSplitter(splitter_10);
        splitter_12->setObjectName(QString::fromUtf8("splitter_12"));
        splitter_12->setMinimumSize(QSize(71, 17));
        splitter_12->setOrientation(Qt::Horizontal);
        label_btn_Solved = new QLabel(splitter_12);
        label_btn_Solved->setObjectName(QString::fromUtf8("label_btn_Solved"));
        sizePolicy1.setHeightForWidth(label_btn_Solved->sizePolicy().hasHeightForWidth());
        label_btn_Solved->setSizePolicy(sizePolicy1);
        label_btn_Solved->setMinimumSize(QSize(0, 15));
        label_btn_Solved->setLayoutDirection(Qt::LeftToRight);
        label_btn_Solved->setAlignment(Qt::AlignCenter);
        splitter_12->addWidget(label_btn_Solved);
        splitter_10->addWidget(splitter_12);

        horizontalLayout_7->addWidget(splitter_10);


        horizontalLayout->addWidget(groupBox_9);

        groupBox_10 = new QGroupBox(tab);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setMinimumSize(QSize(60, 100));
        groupBox_10->setMaximumSize(QSize(16777215, 80));
        groupBox_10->setAutoFillBackground(false);
        groupBox_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayout_8 = new QHBoxLayout(groupBox_10);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        splitter_13 = new QSplitter(groupBox_10);
        splitter_13->setObjectName(QString::fromUtf8("splitter_13"));
        splitter_13->setMinimumSize(QSize(0, 81));
        splitter_13->setCursor(QCursor(Qt::ArrowCursor));
        splitter_13->setAutoFillBackground(false);
        splitter_13->setOrientation(Qt::Vertical);
        splitter_13->setOpaqueResize(false);
        splitter_13->setHandleWidth(0);
        splitter_13->setChildrenCollapsible(false);
        splitter_14 = new QSplitter(splitter_13);
        splitter_14->setObjectName(QString::fromUtf8("splitter_14"));
        splitter_14->setMinimumSize(QSize(61, 50));
        splitter_14->setOrientation(Qt::Horizontal);
        PB_wAwaits = new QPushButton(splitter_14);
        PB_wAwaits->setObjectName(QString::fromUtf8("PB_wAwaits"));
        sizePolicy.setHeightForWidth(PB_wAwaits->sizePolicy().hasHeightForWidth());
        PB_wAwaits->setSizePolicy(sizePolicy);
        PB_wAwaits->setMinimumSize(QSize(50, 50));
        PB_wAwaits->setMaximumSize(QSize(25, 25));
        PB_wAwaits->setFont(font);
        PB_wAwaits->setCursor(QCursor(Qt::PointingHandCursor));
        splitter_14->addWidget(PB_wAwaits);
        splitter_13->addWidget(splitter_14);
        splitter_15 = new QSplitter(splitter_13);
        splitter_15->setObjectName(QString::fromUtf8("splitter_15"));
        splitter_15->setMinimumSize(QSize(71, 17));
        splitter_15->setOrientation(Qt::Horizontal);
        label_btn_Awaits = new QLabel(splitter_15);
        label_btn_Awaits->setObjectName(QString::fromUtf8("label_btn_Awaits"));
        sizePolicy1.setHeightForWidth(label_btn_Awaits->sizePolicy().hasHeightForWidth());
        label_btn_Awaits->setSizePolicy(sizePolicy1);
        label_btn_Awaits->setMinimumSize(QSize(0, 15));
        label_btn_Awaits->setLayoutDirection(Qt::LeftToRight);
        label_btn_Awaits->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        splitter_15->addWidget(label_btn_Awaits);
        splitter_13->addWidget(splitter_15);

        horizontalLayout_8->addWidget(splitter_13);


        horizontalLayout->addWidget(groupBox_10);

        groupBox_11 = new QGroupBox(tab);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setMinimumSize(QSize(60, 100));
        groupBox_11->setMaximumSize(QSize(16777215, 80));
        groupBox_11->setAutoFillBackground(false);
        groupBox_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        horizontalLayout_9 = new QHBoxLayout(groupBox_11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);

        splitter_16 = new QSplitter(groupBox_11);
        splitter_16->setObjectName(QString::fromUtf8("splitter_16"));
        splitter_16->setMinimumSize(QSize(0, 81));
        splitter_16->setCursor(QCursor(Qt::ArrowCursor));
        splitter_16->setAutoFillBackground(false);
        splitter_16->setOrientation(Qt::Vertical);
        splitter_16->setOpaqueResize(false);
        splitter_16->setHandleWidth(0);
        splitter_16->setChildrenCollapsible(false);
        splitter_17 = new QSplitter(splitter_16);
        splitter_17->setObjectName(QString::fromUtf8("splitter_17"));
        splitter_17->setMinimumSize(QSize(61, 50));
        splitter_17->setOrientation(Qt::Horizontal);
        PB_wOverdue = new QPushButton(splitter_17);
        PB_wOverdue->setObjectName(QString::fromUtf8("PB_wOverdue"));
        sizePolicy.setHeightForWidth(PB_wOverdue->sizePolicy().hasHeightForWidth());
        PB_wOverdue->setSizePolicy(sizePolicy);
        PB_wOverdue->setMinimumSize(QSize(50, 50));
        PB_wOverdue->setMaximumSize(QSize(25, 25));
        PB_wOverdue->setFont(font);
        PB_wOverdue->setCursor(QCursor(Qt::PointingHandCursor));
        splitter_17->addWidget(PB_wOverdue);
        splitter_16->addWidget(splitter_17);
        splitter_18 = new QSplitter(splitter_16);
        splitter_18->setObjectName(QString::fromUtf8("splitter_18"));
        splitter_18->setMinimumSize(QSize(71, 17));
        splitter_18->setOrientation(Qt::Horizontal);
        label_btn_Overdue = new QLabel(splitter_18);
        label_btn_Overdue->setObjectName(QString::fromUtf8("label_btn_Overdue"));
        sizePolicy1.setHeightForWidth(label_btn_Overdue->sizePolicy().hasHeightForWidth());
        label_btn_Overdue->setSizePolicy(sizePolicy1);
        label_btn_Overdue->setMinimumSize(QSize(0, 15));
        label_btn_Overdue->setLayoutDirection(Qt::LeftToRight);
        label_btn_Overdue->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        splitter_18->addWidget(label_btn_Overdue);
        splitter_16->addWidget(splitter_18);

        horizontalLayout_9->addWidget(splitter_16);


        horizontalLayout->addWidget(groupBox_11);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 345, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 70));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 20, 71, 22));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(90, 20, 221, 22));
        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(320, 20, 69, 22));
        comboBox_4 = new QComboBox(groupBox_2);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(400, 20, 211, 22));

        verticalLayout_3->addWidget(groupBox_2);

        tableView = new QTableView(tab_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMouseTracking(false);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setDragDropOverwriteMode(false);

        verticalLayout_3->addWidget(tableView);


        verticalLayout_4->addLayout(verticalLayout_3);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        horizontalLayout_2 = new QHBoxLayout(tab_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget_2 = new TabWidget(tab_4);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setTabPosition(QTabWidget::West);
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_7 = new QVBoxLayout(tab_5);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        toolButton = new QToolButton(tab_5);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_7->addWidget(toolButton);

        scrollArea = new QScrollArea(tab_5);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setMinimumSize(QSize(600, 0));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 695, 618));
        verticalLayout_6 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_DataZayavitel = new QLabel(scrollAreaWidgetContents);
        label_DataZayavitel->setObjectName(QString::fromUtf8("label_DataZayavitel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_DataZayavitel->sizePolicy().hasHeightForWidth());
        label_DataZayavitel->setSizePolicy(sizePolicy3);
        label_DataZayavitel->setMinimumSize(QSize(0, 30));
        label_DataZayavitel->setMaximumSize(QSize(6000, 30));
        label_DataZayavitel->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));
        label_DataZayavitel->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_DataZayavitel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(90, 45));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));

        horizontalLayout_3->addWidget(label);

        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy3.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy3);
        lineEdit->setMinimumSize(QSize(185, 25));
        lineEdit->setMaximumSize(QSize(185, 16777215));

        horizontalLayout_3->addWidget(lineEdit);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setMinimumSize(QSize(100, 45));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(185, 25));
        lineEdit_2->setMaximumSize(QSize(16777000, 16777215));

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setMinimumSize(QSize(90, 45));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));

        horizontalLayout_10->addWidget(label_3);

        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(225, 25));
        lineEdit_3->setMaximumSize(QSize(225, 16777215));

        horizontalLayout_10->addWidget(lineEdit_3);

        horizontalSpacer_9 = new QSpacerItem(6000, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_9);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setMinimumSize(QSize(90, 45));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));

        horizontalLayout_11->addWidget(label_4);

        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        sizePolicy3.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy3);
        lineEdit_4->setMinimumSize(QSize(185, 25));

        horizontalLayout_11->addWidget(lineEdit_4);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);
        label_5->setMinimumSize(QSize(100, 45));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));

        horizontalLayout_11->addWidget(label_5);

        lineEdit_5 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMinimumSize(QSize(185, 25));

        horizontalLayout_11->addWidget(lineEdit_5);


        verticalLayout_6->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);
        label_6->setMinimumSize(QSize(90, 45));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));

        horizontalLayout_12->addWidget(label_6);

        comboBox_5 = new QComboBox(scrollAreaWidgetContents);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        sizePolicy3.setHeightForWidth(comboBox_5->sizePolicy().hasHeightForWidth());
        comboBox_5->setSizePolicy(sizePolicy3);
        comboBox_5->setMinimumSize(QSize(110, 0));
        comboBox_5->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_12->addWidget(comboBox_5);

        horizontalSpacer = new QSpacerItem(75, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        label_7->setMinimumSize(QSize(100, 45));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));

        horizontalLayout_12->addWidget(label_7);

        comboBox_6 = new QComboBox(scrollAreaWidgetContents);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));

        horizontalLayout_12->addWidget(comboBox_6);


        verticalLayout_6->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy3.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy3);
        label_8->setMinimumSize(QSize(90, 45));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));

        horizontalLayout_13->addWidget(label_8);

        comboBox_7 = new QComboBox(scrollAreaWidgetContents);
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));
        sizePolicy3.setHeightForWidth(comboBox_7->sizePolicy().hasHeightForWidth());
        comboBox_7->setSizePolicy(sizePolicy3);
        comboBox_7->setMinimumSize(QSize(185, 0));
        comboBox_7->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_13->addWidget(comboBox_7);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setMinimumSize(QSize(100, 45));
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));

        horizontalLayout_13->addWidget(label_9);

        comboBox_8 = new QComboBox(scrollAreaWidgetContents);
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));

        horizontalLayout_13->addWidget(comboBox_8);


        verticalLayout_6->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy3.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy3);
        label_10->setMinimumSize(QSize(90, 45));
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));

        horizontalLayout_14->addWidget(label_10);

        comboBox_9 = new QComboBox(scrollAreaWidgetContents);
        comboBox_9->setObjectName(QString::fromUtf8("comboBox_9"));
        sizePolicy3.setHeightForWidth(comboBox_9->sizePolicy().hasHeightForWidth());
        comboBox_9->setSizePolicy(sizePolicy3);
        comboBox_9->setMinimumSize(QSize(110, 0));
        comboBox_9->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_14->addWidget(comboBox_9);

        horizontalSpacer_8 = new QSpacerItem(6000, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_8);


        verticalLayout_6->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy3.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy3);
        label_11->setMinimumSize(QSize(90, 45));
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));

        horizontalLayout_15->addWidget(label_11);

        lineEdit_6 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setMinimumSize(QSize(445, 16));
        lineEdit_6->setMaximumSize(QSize(225, 16777215));

        horizontalLayout_15->addWidget(lineEdit_6);

        horizontalSpacer_10 = new QSpacerItem(600, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_10);


        verticalLayout_6->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy4);
        label_12->setMinimumSize(QSize(90, 160));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));

        horizontalLayout_16->addWidget(label_12);

        textEdit = new QTextEdit(scrollAreaWidgetContents);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(0, 160));

        horizontalLayout_16->addWidget(textEdit);


        verticalLayout_6->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalSpacer_11 = new QSpacerItem(290, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_11);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_17->addWidget(pushButton);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_12);


        verticalLayout_6->addLayout(horizontalLayout_17);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_7->addWidget(scrollArea);

        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new ClickableWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        verticalLayout_5 = new QVBoxLayout(tab_6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tabWidget_2->addTab(tab_6, QString());

        horizontalLayout_2->addWidget(tabWidget_2);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menubar->setCursor(QCursor(Qt::PointingHandCursor));
        menubar->setFocusPolicy(Qt::NoFocus);
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setCursor(QCursor(Qt::ArrowCursor));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(act_home);
        menu->addAction(act_orders);
        menu->addAction(menu_2->menuAction());
        menu_2->addAction(act_editOrd);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        act_home->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\274\320\276\320\271", nullptr));
        act_orders->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\217\320\262\320\272\320\270", nullptr));
        act_editOrd->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\276\321\202\321\207\320\265\321\202", nullptr));
        act_print->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\207\320\260\321\202\321\214", nullptr));
        act_return->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\267\320\262\321\200\320\260\321\202", nullptr));
        groupBox->setTitle(QString());
#if QT_CONFIG(tooltip)
        PB_wOpened->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        PB_wOpened->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_btn_Opend->setText(QCoreApplication::translate("MainWindow", "  \320\236\321\202\320\272\321\200\321\213\321\202\321\213\320\265", nullptr));
        groupBox_7->setTitle(QString());
#if QT_CONFIG(tooltip)
        PB_wNew->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        PB_wNew->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_btn_New->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271", nullptr));
        groupBox_8->setTitle(QString());
#if QT_CONFIG(tooltip)
        PB_wInWork->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        PB_wInWork->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_btn_InWork->setText(QCoreApplication::translate("MainWindow", "\320\222 \321\200\320\260\320\261\320\276\321\202\320\265", nullptr));
        groupBox_9->setTitle(QString());
#if QT_CONFIG(tooltip)
        PB_wSolved->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        PB_wSolved->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_btn_Solved->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\321\210\320\265\320\275\320\260", nullptr));
        groupBox_10->setTitle(QString());
#if QT_CONFIG(tooltip)
        PB_wAwaits->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        PB_wAwaits->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_btn_Awaits->setText(QCoreApplication::translate("MainWindow", "\320\236\320\266\320\270\320\264\320\260\321\216\321\211\320\270\320\265", nullptr));
        groupBox_11->setTitle(QString());
#if QT_CONFIG(tooltip)
        PB_wOverdue->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        PB_wOverdue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_btn_Overdue->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\321\200\320\276\321\207\320\265\320\275\320\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        groupBox_2->setTitle(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Tab 3", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_DataZayavitel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">N/A</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><style>\n"
"\n"
"div {\n"
"line-height: 0.5;\n"
"}\n"
"\n"
"</style><body><div><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\224\320\260\321\202\320\260</span></p><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\276\321\202\320\272\321\200\321\213\321\202\320\270\321\217</span></p></div></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\232\320\265\320\274</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><style>\n"
"\n"
"div {\n"
"line-height: 0.5;\n"
"}\n"
"\n"
"</style><body><div><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\237\320\276\321\201\320\273\320\265\320\264\320\275\320\265\320\265</span></p><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265</span></p></div></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><style>\n"
"\n"
"div {\n"
"line-height: 0.5;\n"
"}\n"
"\n"
"</style><body><div><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\224\320\260\321\202\320\260</span></p><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\321\200\320\265\321\210\320\265\320\275\320\270\321\217</span></p></div></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><style>\n"
"\n"
"div {\n"
"line-height: 0.5;\n"
"}\n"
"\n"
"</style><body><div><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\224\320\260\321\202\320\260</span></p><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\267\320\260\320\272\321\200\321\213\321\202\320\270\321\217</span></p></div></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\242\320\270\320\277</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\241\321\202\320\260\321\202\321\203\321\201</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><style>\n"
"\n"
"div {\n"
"line-height: 0.5;\n"
"}\n"
"\n"
"</style><body><div><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272</span></p><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\267\320\260\320\277\321\200\320\276\321\201\320\260</span></p></div></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\237\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \320\267\320\260\321\217\320\262\320\272\320\276\320\271", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QCoreApplication::translate("MainWindow", "\320\227\320\260\321\217\320\262\320\272\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Tab 4", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\264\320\265\321\200\320\266\320\272\320\260", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\207\320\260\321\202\321\214...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
