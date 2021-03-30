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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
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
    QLabel *label;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QSplitter *splitter_4;
    QSplitter *splitter_5;
    QPushButton *PB_wNew;
    QSplitter *splitter_6;
    QLabel *label_5;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QSplitter *splitter_7;
    QSplitter *splitter_8;
    QPushButton *PB_wInWork;
    QSplitter *splitter_9;
    QLabel *label_6;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QSplitter *splitter_10;
    QSplitter *splitter_11;
    QPushButton *PB_wSolved;
    QSplitter *splitter_12;
    QLabel *label_9;
    QGroupBox *groupBox_10;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_6;
    QSplitter *splitter_13;
    QSplitter *splitter_14;
    QPushButton *PB_wAwaits;
    QSplitter *splitter_15;
    QLabel *label_10;
    QGroupBox *groupBox_11;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_7;
    QSplitter *splitter_16;
    QSplitter *splitter_17;
    QPushButton *PB_wOverdue;
    QSplitter *splitter_18;
    QLabel *label_11;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(885, 588);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
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
        label = new QLabel(splitter_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(15);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 15));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        splitter_2->addWidget(label);
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
        label_5 = new QLabel(splitter_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(0, 15));
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignCenter);
        splitter_6->addWidget(label_5);
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
        label_6 = new QLabel(splitter_9);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(0, 15));
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setAlignment(Qt::AlignCenter);
        splitter_9->addWidget(label_6);
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
        label_9 = new QLabel(splitter_12);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        label_9->setMinimumSize(QSize(0, 15));
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setAlignment(Qt::AlignCenter);
        splitter_12->addWidget(label_9);
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
        label_10 = new QLabel(splitter_15);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(0, 15));
        label_10->setLayoutDirection(Qt::LeftToRight);
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        splitter_15->addWidget(label_10);
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
        label_11 = new QLabel(splitter_18);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setMinimumSize(QSize(0, 15));
        label_11->setLayoutDirection(Qt::LeftToRight);
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        splitter_18->addWidget(label_11);
        splitter_16->addWidget(splitter_18);

        horizontalLayout_9->addWidget(splitter_16);


        horizontalLayout->addWidget(groupBox_11);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 345, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tableView = new QTableView(tab_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMouseTracking(false);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setDragDropOverwriteMode(false);

        horizontalLayout_3->addWidget(tableView);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 885, 21));
        menubar->setCursor(QCursor(Qt::PointingHandCursor));
        menubar->setFocusPolicy(Qt::NoFocus);
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addAction(action_3);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\274\320\276\320\271", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\217\320\262\320\272\320\270", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\207\320\260\321\202\321\214...", nullptr));
        groupBox->setTitle(QString());
#if QT_CONFIG(tooltip)
        PB_wOpened->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        PB_wOpened->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "  \320\236\321\202\320\272\321\200\321\213\321\202\321\213\320\265", nullptr));
        groupBox_7->setTitle(QString());
#if QT_CONFIG(tooltip)
        PB_wNew->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        PB_wNew->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271", nullptr));
        groupBox_8->setTitle(QString());
#if QT_CONFIG(tooltip)
        PB_wInWork->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        PB_wInWork->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\222 \321\200\320\260\320\261\320\276\321\202\320\265", nullptr));
        groupBox_9->setTitle(QString());
#if QT_CONFIG(tooltip)
        PB_wSolved->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        PB_wSolved->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\321\210\320\265\320\275\320\260", nullptr));
        groupBox_10->setTitle(QString());
#if QT_CONFIG(tooltip)
        PB_wAwaits->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        PB_wAwaits->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\236\320\266\320\270\320\264\320\260\321\216\321\211\320\270\320\265", nullptr));
        groupBox_11->setTitle(QString());
#if QT_CONFIG(tooltip)
        PB_wOverdue->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        PB_wOverdue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\321\200\320\276\321\207\320\265\320\275\320\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\264\320\265\321\200\320\266\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
