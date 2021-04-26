#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    //Окно авторизации
    //--------------------------------------------------------------------------------------------------------------------------------------------
    conect = false;
    sw = new SecondWindow;
    sw->show();
    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Скрытие вкладок таб бара
    //--------------------------------------------------------------------------------------------------------------------------------------------
    QTabBar *tabBar = ui->tabWidget->findChild<QTabBar *>();
    tabBar->hide();
    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Создание объектов запросов
    //--------------------------------------------------------------------------------------------------------------------------------------------
    qmodel = new QSqlQueryModel;
    qmodel_c1 = new QSqlQueryModel;
    qmodel_c2 = new QSqlQueryModel;
    qmodel_categ = new QSqlQueryModel;
    qmodel_stat = new QSqlQueryModel;
    qmodel_reqS = new QSqlQueryModel;
    qmodel_piory = new QSqlQueryModel;
    qmodel_creator = new QSqlQueryModel;
    qmodel_super = new QSqlQueryModel;
    qmodel_appoin = new QSqlQueryModel;
    qmodel_id = new QSqlQueryModel;

    createOrd = new QSqlQuery(db);
    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Таймер
    //--------------------------------------------------------------------------------------------------------------------------------------------
    tmr = new QTimer();
    counterUpdate = 0;
    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Бланк отчета
    //--------------------------------------------------------------------------------------------------------------------------------------------
    PrOrd = new PrintOrder;
    subWflags = true;
    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Валидатор значений для полей дата/время
    //--------------------------------------------------------------------------------------------------------------------------------------------
    QRegExp r_date_time("(19[0-9][0-9]|20[0-9][0-9])\\.(0[1-9]|[1][0-2])\\.(0[1-9]|[12][0-9]|3[01])\\ (0[1-9]|1[0-9]|2[0-3])\\:([0-5][0-9])\\:([0-5][0-9])");
    QRegExpValidator *valida = new QRegExpValidator(r_date_time, this);

    ui->lineEdit->setValidator(valida);
    ui->lineEdit_4->setValidator(valida);
    ui->lineEdit_5->setValidator(valida);
    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Кнопки вывода календаря (наверное можно компактнее)
    //--------------------------------------------------------------------------------------------------------------------------------------------
    menuOp = new QMenu(this);
    menuCl = new QMenu(this);
    menuDi = new QMenu(this);
    calendarOp = new ClickableCalendar();
    calendarCl = new ClickableCalendar();
    calendarDi = new ClickableCalendar();
    actionOp = new QWidgetAction(this);
    actionCl = new QWidgetAction(this);
    actionDi = new QWidgetAction(this);

    actionOp->setDefaultWidget(calendarOp);
    actionCl->setDefaultWidget(calendarCl);
    actionDi->setDefaultWidget(calendarDi);
    menuOp->addAction(actionOp);
    menuCl->addAction(actionCl);
    menuDi->addAction(actionDi);

    ui->toolButton_Opened->setMenu(menuOp);
    ui->toolButton_Decision->setMenu(menuDi);
    ui->toolButton_Closed->setMenu(menuCl);
    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Стили центальных кнопок
    //--------------------------------------------------------------------------------------------------------------------------------------------
    ui->PB_wOpened->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: blue}");
    ui->PB_wNew->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: black}");
    ui->PB_wAwaits->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: orange}");
    ui->PB_wSolved->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: black}");
    ui->PB_wOverdue->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: red}");
    ui->PB_wInWork->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: green}");    
    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Блок соединений
    //--------------------------------------------------------------------------------------------------------------------------------------------
    connect(sw, SIGNAL(ShowMain()), this, SLOT(reciveSignal()));
    connect(sw, SIGNAL(DBConnect(QString, QString)), this, SLOT(SigDBConnect(QString, QString)));
    connect(this, SIGNAL(RevDBConnect(bool)), sw, SLOT(ConOrNot(bool)));
    connect(sw, SIGNAL(DBLog(QString, QString)), this, SLOT(SigDBLog(QString, QString)));
    connect(this, SIGNAL(RevDBLog(bool)), sw, SLOT(LogOrNot(bool)));
    connect(tmr, SIGNAL(timeout()), this, SLOT(UpdateDB()));
    connect(ui->act_return, SIGNAL(triggered()), this, SLOT(ReturnEdit()));
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableView_clicked(const QModelIndex &)));    
    connect(ui->tab_6, SIGNAL(clicked(QMouseEvent *)), this, SLOT(ClearFocusLE()));
    connect(calendarOp, SIGNAL(clickedDate()), this, SLOT(FocusDateOp()));
    connect(calendarCl, SIGNAL(clickedDate()), this, SLOT(FocusDateCl()));
    connect(calendarDi, SIGNAL(clickedDate()), this, SLOT(FocusDateDi()));
    connect(ui->toolButton_Opened, SIGNAL(clicked()), this, SLOT(FocusToolBtn()));

    //connect(ui->tabWidget_2, SIGNAL(tabBarClicked()), ui->lineEdit, SLOT());
    //connect(ui->tab_6, SIGNAL(returnPressed(QKeyEvent *)), this, SLOT(ClearFocusLE()));
    //qDebug() << ui->tab_6->focusWidget();

    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Фильтр заявок (пока не работает)
    //--------------------------------------------------------------------------------------------------------------------------------------------
    QStringList var1 = {"---", "Не"};
    QStringList var2 = {"---", "Не"};

    ui->comboBox->addItems(var1);
    ui->comboBox_2->addItems(var2);



    modelVar2 = (QStandardItemModel*) ui->comboBox_2->model();
    modelVar2->item(1)->setSelectable(false);
    //modelVar2->item(1)->
    //--------------------------------------------------------------------------------------------------------------------------------------------



    QStringList type = {"Инцендент", "Запрос"};

    /*
    QStringList Status = {};
    QStringList Priory = {};
    QStringList Category = {};
    QStringList RequestSours = {};
    QStringList Creator = {};
    QStringList Supervisor = {};
    QStringList Appointed = {};
    */

    ui->comboBox_5->addItems(type);
    ui->comboBox_5->setCurrentIndex(0);

    ui->comboBox_6->setModel(qmodel_categ);
    ui->comboBox_7->setModel(qmodel_stat);
    ui->comboBox_8->setModel(qmodel_reqS);
    ui->comboBox_9->setModel(qmodel_piory);
    ui->comboBox_10->setModel(qmodel_creator);
    ui->comboBox_11->setModel(qmodel_super);
    ui->comboBox_12->setModel(qmodel_appoin);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Возврат на страртовую страницу
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_act_home_triggered()
{
    ui->tabWidget->setCurrentIndex(0);
}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Переход на вкладку "заявки"
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_act_orders_triggered()
{
    ui->tabWidget->setCurrentIndex(1);

    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->setFocusPolicy(Qt::NoFocus);

    ui->tableView->verticalHeader()->setVisible(false);

    ui->tableView->setModel(qmodel);
    ui->tableView->resizeRowsToContents();
    ui->tableView->setColumnWidth(1, 270);
}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Отображение главного окна после успешной авторизации
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::reciveSignal()
{
    this->show();
}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Соединение с БД
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::SigDBConnect(QString name, QString type)
{
    if(type == "MS Access")
    {
        db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName(name);
    }

    if(type == "mySQL")
    {/*
        db = QSqlDatabase::addDatabase("QMYSQL");   \
        db.setHostName("localhost");                |
        db.setDatabaseName(name);                    > не установлен плагин :(
        db.setUserName("root");                     |
        db.setPassword("root");                     /
    */

        db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("localhost");
        db.setDatabaseName(name);
        db.setUserName("root");
        db.setPassword("root");
    }


    if(!db.open())
    {
        emit RevDBConnect(conect);
    }
    else
    {
        conect = true;
        emit RevDBConnect(conect);
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Авторизация
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::SigDBLog(QString log, QString pass)
{
    QSqlQuery query;
    query = QSqlQuery(db);

    query.exec("SELECT * FROM Users");

    if (conect)
        {
            while (query.next())
            {
                QString s1 = query.value(4).toString();
                QString s2 = query.value(5).toString();

                if(log == s1 && pass == s2)
                {
                    emit RevDBLog(true);
                    tmr->start(1);
                    return;
                }
            }

            emit RevDBLog(false);
            return;
        }
}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Выборка заявок из БД и ее обновление; Выборка значений на кнопки
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::UpdateDB()
{
    counterUpdate++;

    qDebug() << "Update #" + QVariant(counterUpdate).toString();

    qmodel->setQuery("SELECT Orders.id, Orders.Title, `Status`.SName, `Edit`.DateEdit, `Create`.DateOpen, Priority.PName, createUser.FullName AS Инициатор, workUser.FullName AS `Кто назначен`, Categories.`C+SC` "
"FROM Users AS workUser INNER JOIN (Categories INNER JOIN (`Status` INNER JOIN (Priority INNER JOIN (((Orders INNER JOIN (Users AS createUser INNER JOIN `Create` ON createUser.id = `Create`.WhoCreate) ON Orders.id = `Create`.id) INNER JOIN `Edit` ON Orders.id = `Edit`.id) INNER JOIN `Work` ON Orders.id = `Work`.id) ON Priority.id = Orders.Priory) ON `Status`.id = Orders.`Status`) ON Categories.id = Orders.Category) ON workUser.id = `Work`.WhoWork ORDER BY Orders.id DESC;");

    qmodel_c1->setQuery("SELECT "
"ABS(SUM(NOT Status.SName = 'Закрыто')) AS cOpened, "
"ABS(SUM(Status.SName = 'В работе (назначена)' OR Status.SName = 'В работе (запланированна)')) AS cInWork "
"FROM Status INNER JOIN Orders ON Status.id = Orders.Status;");

    qmodel_c1->query().first();

    ui->PB_wOpened->setText(qmodel_c1->query().value(0).toString());
    ui->PB_wInWork->setText(qmodel_c1->query().value(1).toString());

    tmr->start(10000);
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//Клик на кнопку "В работе"
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_PB_wOpened_clicked()
{
    QPrinter printer;
    //print(&printer);


    QPainter painter;

    //painter.setWindow(PrOrd->rect());
    //this->render(&painter);

    //QPrintDialog dialog(&printer, this);

    //QPixmap pix = QWidget::grab(PrOrd->rect());


    QPixmap pix = QPixmap::grabWidget(PrOrd);


    QPrintPreviewDialog preview(&printer);




    if(preview.exec() == QDialog::Accepted)
    {/*
        painter.setWindow(PrOrd->rect());
        PrOrd->render(&painter);*/


        painter.begin(&printer);
        painter.drawPixmap(0, 0, pix);
        painter.end();
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------

void MainWindow::on_PB_wNew_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}

//Редактирование отчета перед выводом на печать
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_act_editOrd_triggered()
{
    ui->tabWidget->setCurrentIndex(2);

    tmr->stop();

    ui->menu->setDisabled(true);

    CreateMenu();

    ui->menubar->addMenu(report);
/*
    //PrintOrder *pr = new PrintOrder(mdiArea);


    //PrOrd->show();

    //PrOrd->setFixedSize(620, 877);

    //PrOrd->setWindowTitle("Sub Window");


    //PrOrd->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    //pr->update();


    //qDebug() << PrOrd->windowFlags();

    //mdiArea->addSubWindow(PrOrd, Qt::MSWindowsFixedSizeDialogHint);*/

    mdiArea = new QMdiArea(ui->tab_3);

    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    //qDebug() << centralWidget();
    qDebug() << mdiArea;

    centrWidget = takeCentralWidget();
    setCentralWidget(mdiArea);

    auto flags = PrOrd->windowFlags();
    flags.setFlag(Qt::MSWindowsFixedSizeDialogHint).setFlag(Qt::WindowCloseButtonHint, false);

    mdiArea->addSubWindow(PrOrd, flags & ~Qt::WindowCloseButtonHint);

    /*
    //PrOrd->setWindowFlags(windowFlags() & ~Qt::WindowSystemMenuHint);
    //PrOrd->setWindowFlag(Qt::WindowCloseButtonHint, false);
    //qDebug() << PrOrd->windowFlags();
    //qDebug() << flags;
    //qDebug() << centralWidget();
    //PrOrd->show();
    */
    //^
    //| пытался решить проблему наличия кнопок на подчиненном окне путем добавления/отключения/уничтожения флагов...
    //  не вышло, однако больше не расягтвается -> достижение

    //Комплекс вывода на печать (снять внешний коммент)
    /*
    QPrinter printer;

    QPainter painter;

    //painter.setWindow(sw->rect());
    //this->render(&painter);

    //QPrintDialog dialog(&printer, this);

    QPixmap pix = QWidget::grab(sw->rect());


    QPrintPreviewDialog preview(&printer,this);


    if(preview.exec() == QDialog::Accepted)
    {
        //painter.begin(&printer);
        //painter.drawPixmap(0, 0, pix);
        //painter.end();
    }


    if(dialog.exec() == QDialog::Accepted)
    {
        //painter.begin(&printer);
        //painter.drawPixmap(0, 0, pix);
        //painter.end();
    }*/
}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Создание меню работы с отчетом
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::CreateMenu()
{
    report = new QMenu(nullptr);
    report->setTitle("Работа с отчетом");
    report->addAction(ui->act_print);
    report->addSeparator();
    report->addAction(ui->act_return);
}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Действие "Возврат" в меню работы с отчетом (вылеты)
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::ReturnEdit()
{
    delete report;
    //report = NULL;
    delete mdiArea;

    ui->menu->setDisabled(false);


    setCentralWidget(centrWidget);

    //qDebug() << centrWidget;
    //qDebug() << centralWidget();

    //qDebug() << mdiArea;


    tmr->start(1);

    ui->tabWidget->setCurrentIndex(1);
}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Вывод на печать из меню работы с отчетом
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_act_print_triggered()
{
    QPrinter printer;
    //print(&printer);


    QPainter painter;

    //painter.setWindow(PrOrd->rect());
    //this->render(&painter);

    //QPrintDialog dialog(&printer, this);

    //QPixmap pix = QWidget::grab(PrOrd->rect());


    QPixmap pix = QPixmap::grabWidget(PrOrd);


    QPrintPreviewDialog preview(&printer);


    if(preview.exec() == QDialog::Accepted)
    {/*
        painter.setWindow(PrOrd->rect());
        PrOrd->render(&painter);*/


        painter.begin(&printer);
        painter.drawPixmap(0, 0, pix);
        painter.end();
    }

}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Попытка реализовать принтер отдельно
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::print(QPrinter * printer)
{
    QPainter painter(printer);
    painter.setWindow(PrOrd->rect());
    PrOrd->render(&painter);
}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Попытка выделить всю строку в TableView
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::onTableView_clicked(const QModelIndex &index)
{
    /*ui->tableView->selectRow(ui->tableView->currentIndex().row());

    qDebug() << index;
    qDebug() << ui->tableView->currentIndex().row();*/
}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Снятие фокуса с QLineEdit по щелчку мыши
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::ClearFocusLE()
{
    qDebug() << ui->tab_6->focusWidget();

    qDebug() << (ui->tab_6->focusWidget() == NULL);

    if(ui->tab_6->focusWidget() != NULL)
    {
        ui->tab_6->focusWidget()->clearFocus();
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------

//Добавление даты и времени с выпадающего календаря (реализовать с какого именно календаря, пока на каждый отдельно)
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::FocusDateOp()
{
    ui->lineEdit->setText(calendarOp->selectedDate().toString(QString("yyyy.MM.dd")) + " 12:00:00");


    //qDebug() << calendarOp->selectedDate().toString("dd.MM.yyyy");

    /*
    //текущее время и дата

    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);

    //strftime(buf, sizeof(buf), "%d.%m.%Y %X", &tstruct);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    qDebug() << buf;*/
}

void MainWindow::FocusDateCl()
{
    ui->lineEdit_5->setText(calendarCl->selectedDate().toString(QString("yyyy.MM.dd")) + " 12:00:00");
}

void MainWindow::FocusDateDi()
{
    ui->lineEdit_4->setText(calendarDi->selectedDate().toString(QString("yyyy.MM.dd")) + " 12:00:00");
}
//--------------------------------------------------------------------------------------------------------------------------------------------

void MainWindow::FocusToolBtn()
{
    qDebug() << ui->tab_6->focusWidget();
}


//Добавление текущей даты и времени в поле последние изменение (пока только на меня) (Реализовано на Си)
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_clicked()
{

    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y.%m.%d %X", &tstruct);
    //strftime(buf, sizeof(buf), "%X", &tstruct);

    QString str(buf);
/*
    qmodel_c2->setQuery("SELECT Users.FullName FROM Users");
    qmodel_c2->query().first();

    ui->label_17->setText(str + " на " + qmodel_c2->query().value(0).toString());
*/



    qmodel_id->setQuery("Select max(Orders.id), max(`Create`.id), max(`Edit`.id), max(`Work`.id), max(`Categories`.id), max(Priority.id), max(RequestSource.id), max(`Status`.id) "
                        "From `Categories`, `Create`, `Edit`, Orders, Priority, RequestSource, `Status`, `Work`");
    qmodel_id->query().first();

    QSqlQuery creOrd(db);

    //qDebug() << creOrd.exec("Select * From `Work`");
    //qDebug() << createOrd->exec();

    creOrd.prepare("INSERT INTO Orders (id, `Category`, `Priory`, `Status`, `Title`, `Description`, RequestSource) VALUES (?, ?, ?, ?, ?, ?, ?)");
    creOrd.addBindValue(1 + qmodel_id->query().value(0).toInt());
    creOrd.addBindValue(1 + ui->comboBox_6->currentIndex());
    creOrd.addBindValue(1 + ui->comboBox_9->currentIndex());
    creOrd.addBindValue(1 + ui->comboBox_7->currentIndex());
    creOrd.addBindValue(ui->lineEdit_6->text());
    creOrd.addBindValue(ui->textEdit->toPlainText());
    creOrd.addBindValue(1 + ui->comboBox_8->currentIndex());
    creOrd.exec();

    creOrd.prepare("INSERT INTO `Create` (id, `DateOpen`, WhoCreate) VALUES (?, ?, ?)");
    creOrd.addBindValue(1 + qmodel_id->query().value(1).toInt());
    creOrd.addBindValue(ui->lineEdit->text());
    creOrd.addBindValue(1 + ui->comboBox_10->currentIndex());
    creOrd.exec();

    creOrd.prepare("INSERT INTO `Edit` (id, `DateEdit`, WhoEdit) VALUES (?, ?, ?)");
    creOrd.addBindValue(1 + qmodel_id->query().value(2).toInt());
    creOrd.addBindValue(str);
    creOrd.addBindValue(1 + ui->comboBox_10->currentIndex());
    creOrd.exec();

    creOrd.prepare("INSERT INTO `Work` (id, WhoWork) VALUES (?, ?)");
    creOrd.addBindValue(1 + qmodel_id->query().value(3).toInt());
    creOrd.addBindValue(1 + ui->comboBox_12->currentIndex());
    creOrd.exec();
}
//--------------------------------------------------------------------------------------------------------------------------------------------

void MainWindow::on_act_create_ord_triggered()
{
    QTabBar *tabBar_2 = ui->tabWidget_2->findChild<QTabBar *>();
    tabBar_2->hide();



    ui->tabWidget->setCurrentIndex(3);
    ui->tabWidget_2->setCurrentIndex(1);

    ui->label_idZayavki->setText("<html><head/><body><p><span style=' font-size:12pt; font-weight:600;'>Формирование новой заявки</span></p></body></html>");

    qmodel_categ->setQuery("SELECT `C+SC` From `Categories`");

    qmodel_stat->setQuery("SELECT SName FROM `Status`");
    qmodel_reqS->setQuery("SELECT RName FROM RequestSource");
    qmodel_piory->setQuery("SELECT PName FROM Priority");
    qmodel_creator->setQuery("SELECT FullName FROM Users");

    qmodel_super->setQuery("SELECT FullName FROM Users WHERE FullName <> 'Почтовый робот'");
    qmodel_appoin->setQuery(qmodel_super->query());

    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_17->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->pushButton->show();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->toolButton_Decision->hide();
    ui->toolButton_Closed->hide();
    ui->comboBox_13->hide();

    ui->lineEdit->clear();
    ui->lineEdit_6->clear();
    ui->textEdit->clear();

    ui->comboBox_9->setCurrentIndex(2);
}
