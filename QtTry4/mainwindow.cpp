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
    qmodel_c1_1 = new QSqlQueryModel;
    qmodel_c2 = new QSqlQueryModel;
    qmodel_categ = new QSqlQueryModel;
    qmodel_stat = new QSqlQueryModel;
    qmodel_reqS = new QSqlQueryModel;
    qmodel_piory = new QSqlQueryModel;
    qmodel_creator = new QSqlQueryModel;
    qmodel_super = new QSqlQueryModel;
    qmodel_appoin = new QSqlQueryModel;
    qmodel_id = new QSqlQueryModel;
    qmodel_ordId = new QSqlQueryModel;
    filOrd = new QSqlQueryModel;
    filOrd_1 = new QSqlQueryModel;


    btnSave = new QSqlQuery(db);
    createOrd = new QSqlQuery(db);    
    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Таймер
    //--------------------------------------------------------------------------------------------------------------------------------------------
    tmr = new QTimer();
    counterUpdate = 0;
    saveTmr = new QTimer();
    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Бланк отчета
    //--------------------------------------------------------------------------------------------------------------------------------------------
    PrOrd = new PrintOrder;
    subWflags = true;
    //--------------------------------------------------------------------------------------------------------------------------------------------

    ui->tableView->setFocusPolicy(Qt::NoFocus);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setModel(qmodel);    

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
    menuFi = new QMenu(this);
    menuFi_2 = new QMenu(this);
    calendarOp = new ClickableCalendar();
    calendarCl = new ClickableCalendar();
    calendarDi = new ClickableCalendar();
    calendarFi = new ClickableCalendar();
    calendarFi_2 = new ClickableCalendar();
    actionOp = new QWidgetAction(this);
    actionCl = new QWidgetAction(this);
    actionDi = new QWidgetAction(this);
    actionFi = new QWidgetAction(this);
    actionFi_2 = new QWidgetAction(this);

    actionOp->setDefaultWidget(calendarOp);
    actionCl->setDefaultWidget(calendarCl);
    actionDi->setDefaultWidget(calendarDi);
    actionFi->setDefaultWidget(calendarFi);
    actionFi_2->setDefaultWidget(calendarFi_2);
    menuOp->addAction(actionOp);
    menuCl->addAction(actionCl);
    menuDi->addAction(actionDi);
    menuFi->addAction(actionFi);
    menuFi_2->addAction(actionFi_2);

    ui->toolButton_Opened->setMenu(menuOp);
    ui->toolButton_Decision->setMenu(menuDi);
    ui->toolButton_Closed->setMenu(menuCl);
    ui->toolButton_Filter->setMenu(menuFi);
    ui->toolButton_Filter_2->setMenu(menuFi_2);
    //--------------------------------------------------------------------------------------------------------------------------------------------



    //Блок соединений
    //--------------------------------------------------------------------------------------------------------------------------------------------
    connect(sw, SIGNAL(ShowMain()), this, SLOT(reciveSignal()));
    connect(sw, SIGNAL(DBConnect(QString, QString)), this, SLOT(SigDBConnect(QString, QString)));
    connect(this, SIGNAL(RevDBConnect(bool)), sw, SLOT(ConOrNot(bool)));
    connect(sw, SIGNAL(DBLog(QString, QString)), this, SLOT(SigDBLog(QString, QString)));
    connect(this, SIGNAL(RevDBLog(bool)), sw, SLOT(LogOrNot(bool)));
    connect(tmr, SIGNAL(timeout()), this, SLOT(UpdateDB()));    
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableView_clicked()));
    connect(ui->tab_6, SIGNAL(clicked(QMouseEvent *)), this, SLOT(ClearFocusLE()));
    connect(calendarOp, SIGNAL(clickedDate()), this, SLOT(FocusDateOp()));
    connect(calendarCl, SIGNAL(clickedDate()), this, SLOT(FocusDateCl()));
    connect(calendarDi, SIGNAL(clickedDate()), this, SLOT(FocusDateDi()));
    connect(calendarFi, SIGNAL(clickedDate()), this, SLOT(FocusDateFi()));
    connect(calendarFi_2, SIGNAL(clickedDate()), this, SLOT(FocusDateFi_2()));
    connect(ui->toolButton_Opened, SIGNAL(clicked()), this, SLOT(FocusToolBtn()));
    connect(saveTmr, SIGNAL(timeout()), this, SLOT(updEditOrd()));

    //connect(ui->tabWidget_2, SIGNAL(tabBarClicked()), ui->lineEdit, SLOT());
    //connect(ui->tab_6, SIGNAL(returnPressed(QKeyEvent *)), this, SLOT(ClearFocusLE()));
    //qDebug() << ui->tab_6->focusWidget();

    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(twiceClickOnTableRow(const QModelIndex &)));
    connect(ui->comboBox_var_1, SIGNAL(currentIndexChanged(QString)), this, SLOT(Var_2_changed()));
    connect(ui->comboBox_var_1_1, SIGNAL(currentIndexChanged(QString)), this, SLOT(Var_2_1_changed()));
    connect(this, SIGNAL(fillReportSig(int)), PrOrd, SLOT(fillReport(int)));


    //ui->tableView->clicked()

    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Фильтр заявок
    //--------------------------------------------------------------------------------------------------------------------------------------------
    cbVar_0_1 = 0;
    cbVar_1 = 0; cbVar_1_1 = 0;
    cbVar_2 = 0; cbVar_2_1 = 0;
    cbVar_3 = 0; cbVar_3_1 = 0;
    leFind = ""; leFind_1 = "";

    btnVis = false;
    str_1 = ""; str_1_1 = "";
    str_2 = ""; str_2_1 = "";
    str_3 = ""; str_3_1 = "";
    str_4 = ""; str_4_1 = "";
    str_and = "";

    QStringList var0 = {"---", "Не"};    
    QStringList var0_1 = {"И", "ИЛИ"};


    var0_0 = new QStringList {" ) AND", " ) OR"};

    var1 = new QStringList {"Все", "Заголовок", "Описание", "Статус", "Приоритет", "Категория", "Тип", "Источник запроса", "Последние изменение",
                            "Инициатор запроса", "Наблюдатель", "Назначено", "Дата Открытия", "Дата Закрытия", "Дата решения", "Дата изменения", "ID"};
    var1_1 = new QStringList {"*", "Orders.Title", "Orders.Description", "Orders.`Status`", "Orders.Priory", "Orders.Category", "Orders.`Type`",
                              "Orders.RequestSource", "`Edit`.WhoEdit", "`Create`.WhoCreate", "`Control`.WhoControlling", "`Work`.WhoWork",
                              "`Create`.DateOpen", "`Work`.DateClose", "`Work`.DateDecision", "`Edit`.DateEdit", "Orders.id"};
    var1_2 = new QStringList {"LIKE", "NOT LIKE", "=", "<>", "<", ">"};

    var2_1 = new QStringList {"Содержит", "Не содержит"};
    var2_2 = new QStringList {"Равен", "Не равен"};
    var2_3 = new QStringList {"Содержит", "Не содержит", "Равна", "Не равна", "До", "После"};
    var2_4 = new QStringList {"Содержит", "Не содержит", "Равен", "Не равен"};

    ui->comboBox_var_0->addItems(var0);
    ui->comboBox_var_0_0->addItems(var0_1);
    ui->comboBox_var_0->setDisabled(true);
    ui->comboBox_var_1->addItems(*var1);
    ui->comboBox_var_1_1->addItems(*var1);
    ui->lineEdit_find->hide();
    ui->toolButton_Filter->hide();

    ui->comboBox_var_0_0->hide();
    ui->comboBox_var_1_1->hide();
    ui->comboBox_var_2_2->hide();
    ui->comboBox_var_3_3->hide();
    ui->lineEdit_find_2->hide();
    ui->toolButton_Filter_2->hide();
    ui->pushButton_twsSearch_del->hide();


    /*
    modelVar2 = (QStandardItemModel*) ui->comboBox_var_1->model();
    modelVar2->item(1)->setSelectable(false);*/
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
    ui->comboBox_13->setModel(qmodel_creator);

    tabBar_2 = ui->tabWidget_2->findChild<QTabBar *>();


    //mdiArea для отчета
    //--------------------------------------------------------------------------------------------------------------------------------------------
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    auto flags = PrOrd->windowFlags();
    flags.setFlag(Qt::MSWindowsFixedSizeDialogHint);
    //PrOrd->setWindowFlags(Qt::CustomizeWindowHint);
    ui->mdiArea->addSubWindow(PrOrd, flags/* & ~Qt::WindowCloseButtonHint*/);
    //ui->mdiArea->setWindowFlag(Qt::WindowSystemMenuHint, false);

    qDebug() << PrOrd->windowFlags();
    //qDebug() << ui->mdiArea->windowFlags();

    //--------------------------------------------------------------------------------------------------------------------------------------------

    leList.operator<<(ui->lineEdit).operator<<(ui->lineEdit_6);
    cbList.operator<<(ui->comboBox_6).operator<<(ui->comboBox_7).operator<<(ui->comboBox_8).operator<<(ui->comboBox_10);
    lableList.operator<<(ui->label).operator<<(ui->label_11).operator<<(ui->label_7).operator<<(ui->label_8).operator<<(ui->label_9).operator<<(ui->label_14);

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
<<<<<<< HEAD
<<<<<<< HEAD
    queryMode = 1;
    multiplier_f = 1;

<<<<<<< HEAD
    //ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->setFocusPolicy(Qt::NoFocus);
=======
    ui->comboBox_var_1->clear();
    ui->comboBox_var_1_1->clear();
    ui->comboBox_var_1->addItems(*var1);
    ui->comboBox_var_1_1->addItems(*var1);
>>>>>>> 54806f89d0e45761bd5f47c45d138df273804283

    ui->pushButton_twsSearch_del->click();

=======
>>>>>>> parent of 54806f8 (beta 0.4.5)
=======
>>>>>>> parent of 54806f8 (beta 0.4.5)
    ui->tabWidget->setCurrentIndex(1);    

    ui->tableView->setColumnWidth(1, 400);
    ui->tableView->resizeRowsToContents();

    ui->comboBox_var_1->setCurrentIndex(0);

    for (int i = 0; i < 6; i++)
    {
        lableList.at(i)->setStyleSheet("background-color: rgb(181, 181, 181);");
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------


void MainWindow::Var_2_changed()
{
    ui->comboBox_var_2->clear();

    if(ui->comboBox_var_1->currentIndex() == 0)
    {
        ui->comboBox_var_2->setDisabled(true);
        ui->comboBox_var_3->setDisabled(true);
        ui->lineEdit_find->show();
        ui->lineEdit_find->setDisabled(true);
        ui->toolButton_Filter->hide();
        ui->comboBox_var_3->show();
    }
    else if(ui->comboBox_var_1->currentIndex() > 0 && ui->comboBox_var_1->currentIndex() < 3)
    {
        ui->comboBox_var_2->setDisabled(false);
        ui->comboBox_var_3->setDisabled(false);
        ui->comboBox_var_2->addItems(*var2_1);
        ui->comboBox_var_3->hide();
        ui->lineEdit_find->show();
        ui->lineEdit_find->setDisabled(false);
    }
    else if(ui->comboBox_var_1->currentIndex() > 2 && ui->comboBox_var_1->currentIndex() < 12)
    {
        ui->comboBox_var_2->setDisabled(false);
        ui->comboBox_var_3->setDisabled(false);
        ui->comboBox_var_2->addItems(*var2_2);
        ui->lineEdit_find->hide();
        ui->toolButton_Filter->hide();
        ui->comboBox_var_3->show();

        QStringList sub_var_2 = {"`Status`", "Priority", "`Categories`", "`Types`", "RequestSource", "Users", "Users", "Users", "Users"};
        QStringList sub_var = {"SName", "PName", "`C+SC`", "TName", "RName", "FullName", "FullName", "FullName", "FullName"};
        QString cond = "WHERE Users.FullName <> 'Почтовый робот';";

        if(ui->comboBox_var_1->currentIndex() < 10)
        {
            filOrd->setQuery("SELECT " + sub_var.at(ui->comboBox_var_1->currentIndex() - 3) + " FROM " + sub_var_2.at(ui->comboBox_var_1->currentIndex() - 3) + ";");
        }
        else
        {
            filOrd->setQuery("SELECT " + sub_var.at(ui->comboBox_var_1->currentIndex() - 3) + " FROM " + sub_var_2.at(ui->comboBox_var_1->currentIndex() - 3) + " " + cond);
        }

        ui->comboBox_var_3->setModel(filOrd);
    }
    else if(ui->comboBox_var_1->currentIndex() > 11 && ui->comboBox_var_1->currentIndex() < 16)
    {
        ui->comboBox_var_2->setDisabled(false);
        ui->comboBox_var_3->setDisabled(false);
        ui->lineEdit_find->setDisabled(false);
        ui->comboBox_var_2->addItems(*var2_3);
        ui->comboBox_var_3->hide();
        ui->lineEdit_find->show();
        ui->toolButton_Filter->show();
    }
    else
    {
        ui->comboBox_var_2->setDisabled(false);
        ui->comboBox_var_3->setDisabled(false);
        ui->lineEdit_find->setDisabled(false);
        ui->comboBox_var_2->addItems(*var2_4);
        ui->lineEdit_find->show();
        ui->toolButton_Filter->hide();
    };
}


void MainWindow::Var_2_1_changed()
{
    ui->comboBox_var_2_2->clear();

    if(ui->comboBox_var_1_1->currentIndex() == 0)
    {
        ui->comboBox_var_2_2->setDisabled(true);
        ui->comboBox_var_3_3->setDisabled(true);
        ui->lineEdit_find_2->show();
        ui->lineEdit_find_2->setDisabled(true);
        ui->toolButton_Filter_2->hide();
        ui->comboBox_var_3_3->show();
    }
    else if(ui->comboBox_var_1_1->currentIndex() > 0 && ui->comboBox_var_1_1->currentIndex() < 3)
    {
        ui->comboBox_var_2_2->setDisabled(false);
        ui->comboBox_var_3_3->setDisabled(false);
        ui->comboBox_var_2_2->addItems(*var2_1);
        ui->comboBox_var_3_3->hide();
        ui->lineEdit_find_2->show();
        ui->lineEdit_find_2->setDisabled(false);
    }
    else if(ui->comboBox_var_1_1->currentIndex() > 2 && ui->comboBox_var_1_1->currentIndex() < 12)
    {
        ui->comboBox_var_2_2->setDisabled(false);
        ui->comboBox_var_3_3->setDisabled(false);
        ui->comboBox_var_2_2->addItems(*var2_2);
        ui->lineEdit_find_2->hide();
        ui->toolButton_Filter_2->hide();
        ui->comboBox_var_3_3->show();

        QStringList sub_var_2 = {"`Status`", "Priority", "`Categories`", "`Types`", "RequestSource", "Users", "Users", "Users", "Users"};
        QStringList sub_var = {"SName", "PName", "`C+SC`", "TName", "RName", "FullName", "FullName", "FullName", "FullName"};
        QString cond = "WHERE Users.FullName <> 'Почтовый робот';";

        if(ui->comboBox_var_1_1->currentIndex() < 10)
        {
            filOrd_1->setQuery("SELECT " + sub_var.at(ui->comboBox_var_1_1->currentIndex() - 3) + " FROM " + sub_var_2.at(ui->comboBox_var_1_1->currentIndex() - 3) + ";");
        }
        else
        {
            filOrd_1->setQuery("SELECT " + sub_var.at(ui->comboBox_var_1_1->currentIndex() - 3) + " FROM " + sub_var_2.at(ui->comboBox_var_1_1->currentIndex() - 3) + " " + cond);
        }

        ui->comboBox_var_3_3->setModel(filOrd_1);
    }
    else if(ui->comboBox_var_1_1->currentIndex() > 11 && ui->comboBox_var_1_1->currentIndex() < 16)
    {
        ui->comboBox_var_2_2->setDisabled(false);
        ui->comboBox_var_3_3->setDisabled(false);
        ui->lineEdit_find_2->setDisabled(false);
        ui->comboBox_var_2_2->addItems(*var2_3);
        ui->comboBox_var_3_3->hide();
        ui->lineEdit_find_2->show();
        ui->toolButton_Filter_2->show();
    }
    else
    {
        ui->comboBox_var_2_2->setDisabled(false);
        ui->comboBox_var_3_3->setDisabled(false);
        ui->lineEdit_find_2->setDisabled(false);
        ui->comboBox_var_2_2->addItems(*var2_4);
        ui->lineEdit_find_2->show();
        ui->toolButton_Filter_2->hide();
    };
}


void MainWindow::on_pushButton_search_clicked()
{    
    cbVar_1 = ui->comboBox_var_1->currentIndex();
    cbVar_2 = ui->comboBox_var_2->currentIndex();
    cbVar_3 = ui->comboBox_var_3->currentIndex();
    leFind = ui->lineEdit_find->text();

    if(ui->pushButton_twsSearch_del->isVisible()){
    cbVar_0_1 = ui->comboBox_var_0_0->currentIndex();
    cbVar_1_1 = ui->comboBox_var_1_1->currentIndex();
    cbVar_2_1 = ui->comboBox_var_2_2->currentIndex();
    cbVar_3_1 = ui->comboBox_var_3_3->currentIndex();
    leFind_1 = ui->lineEdit_find_2->text();}

    if(ui->pushButton_twsSearch_del->isVisible()) {
        btnVis = true;
        str_and = var0_0->at(cbVar_0_1);

        if(cbVar_1_1 > 11 && cbVar_1_1 < 16){
            if(cbVar_2_1 > 1){
                leFind_1 = QDateTime::fromString(ui->lineEdit_find_2->text(), "yyyy.MM.dd").toString("yyyy-MM-dd");}
            if(cbVar_2_1 == 4){
                str_4_1 = " 00:00:00'";
            }else if(cbVar_2_1 == 5){
                str_4_1 = " 23:59:59'";}
        }else{
            if(cbVar_2_1 == 2 || cbVar_2_1 == 3){
                str_4_1 = "'";
            }else{
            str_4_1 = "";}}

        if(cbVar_1_1 > 2 && cbVar_1_1 < 12){
            str_3_1 = QVariant(cbVar_3_1 + 1).toString();
        }else{
            if(cbVar_2_1 > 3 || (cbVar_2_1 > 1 && cbVar_1_1 == 16)){
                str_3_1 = "'" + leFind_1;
            }else{
            str_3_1 = "'%" + leFind_1 + "%'";}}
    }else{
        btnVis = false;
        str_1_1 = "";
        str_2_1 = "";
        str_3_1 = "";
        str_4_1 = "";
        str_and = "";}



    if(cbVar_1 > 11 && cbVar_1 < 16){
        if(cbVar_2 > 1){
            leFind = QDateTime::fromString(ui->lineEdit_find->text(), "yyyy.MM.dd").toString("yyyy-MM-dd");}
        if(cbVar_2 == 4){
            str_4 = " 00:00:00'";
        }else if(cbVar_2 == 5){
            str_4 = " 23:59:59'";}
    }else{
        if(cbVar_2 == 2 || cbVar_2 == 3){
            str_4 = "'";
        }else{
        str_4 = "";}}

    if(cbVar_1 > 2 && cbVar_1 < 12){
        str_3 = QVariant(cbVar_3 + 1).toString();
    }else{
        if(cbVar_2 > 3 || (cbVar_2 > 1 && cbVar_1 == 16)){
            str_3 = "'" + leFind;
        }else{
        str_3 = "'%" + leFind + "%'";}}

    tmr->start(1);
}


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
                    curUser = query.value(0).toInt();
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

    qDebug() << "Update #" + QVariant(counterUpdate).toString() + "   Current User ID: " + QVariant(curUser).toString();



    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    QString str(buf);



    if((cbVar_1 == 0 && btnVis == false) || (btnVis && (cbVar_1 == 0 || cbVar_1_1 == 0))) {
        qmodel->setQuery("SELECT Orders.id, Orders.Title, `Status`.SName AS `Status`, `Edit`.DateEdit AS `Last edit`, `Create`.DateOpen AS `Date Open`, Priority.PName AS `Priority`, createUser.FullName AS `Initiator`, workUser.FullName AS `Appointed`, Categories.`C+SC` AS `Category` "
        "FROM Users AS workUser RIGHT JOIN (Categories INNER JOIN (`Status` INNER JOIN (Priority INNER JOIN (((Orders INNER JOIN (Users AS createUser INNER JOIN `Create` ON createUser.id = `Create`.WhoCreate) ON Orders.id = `Create`.id) INNER JOIN `Edit` ON Orders.id = `Edit`.id) INNER JOIN `Work` ON Orders.id = `Work`.id) ON Priority.id = Orders.Priory) ON `Status`.id = Orders.`Status`) ON Categories.id = Orders.Category) ON workUser.id = `Work`.WhoWork ORDER BY Orders.id DESC;");}
    else{
        str_1 = var1_1->at(cbVar_1);
        if(cbVar_1 < 3 || cbVar_1 > 11){
        var_2 = cbVar_2;
        if ((cbVar_1 > 11 && cbVar_1 < 16) && (cbVar_2 == 2 || cbVar_2 == 3)){
            var_2 = var_2 - 2;}
        }else{
        var_2 = cbVar_2 + 2;
        }
        str_2 = var1_2->at(var_2);

        if(btnVis) {
            str_1_1 = "( " + var1_1->at(cbVar_1_1);
            if(cbVar_1_1 < 3 || cbVar_1_1 > 11){
            var_2_2 = cbVar_2_1;
            if ((cbVar_1_1 > 11 && cbVar_1_1 < 16) && (cbVar_2_1 == 2 || cbVar_2_1 == 3)){
                var_2_2 = var_2_2 - 2;}
            }else{
                var_2_2 = cbVar_2_1 + 2;
            }
            str_2_1 = var1_2->at(var_2_2);
        }

        qmodel->setQuery("SELECT Orders.id, Orders.Title, `Status`.SName AS `Status`, `Edit`.DateEdit AS `Last edit`, `Create`.DateOpen AS `Date Open`, Priority.PName AS `Priority`, createUser.FullName AS `Initiator`, workUser.FullName AS `Appointed`, Categories.`C+SC` AS `Category` "
    "FROM Users AS workUser RIGHT JOIN (Categories INNER JOIN (`Status` INNER JOIN (Priority INNER JOIN (((Orders INNER JOIN (Users AS createUser INNER JOIN `Create` ON createUser.id = `Create`.WhoCreate) ON Orders.id = `Create`.id) INNER JOIN `Edit` ON Orders.id = `Edit`.id) INNER JOIN `Work` ON Orders.id = `Work`.id) ON Priority.id = Orders.Priory) ON `Status`.id = Orders.`Status`) ON Categories.id = Orders.Category) ON workUser.id = `Work`.WhoWork "
    "WHERE ( " + str_1 + " " + str_2 + " " + str_3 + str_4 + str_and + " " + str_1_1 + " " + str_2_1 + " " + str_3_1 + str_4_1 + " ) ORDER BY Orders.id DESC;");
        }


    ui->tableView->resizeRowsToContents();


    qmodel_c1->setQuery("SELECT "
"ABS(SUM(NOT Status.SName = 'Закрыто')) AS cOpened, "
"ABS(SUM(Status.SName = 'В работе (назначена)' OR Status.SName = 'В работе (запланированна)')) AS cInWork, "
"ABS(SUM(Status.SName = 'Новый')) AS cNew, "
"ABS(SUM(Status.SName = 'Решена')) AS cSolved, "
"ABS(SUM(Status.SName = 'Ожидающие')) AS cAwaits "
"FROM Status INNER JOIN Orders ON Status.id = Orders.Status;");

    qmodel_c1_1->setQuery("SELECT ABS(SUM(`Work`.DateDecision < '" + str + "' AND Orders.`Status` <> 'Закрыто')) FROM `Work` INNER JOIN (Orders INNER JOIN `Status` ON Orders.`Status` = `Status`.id) ON `Work`.id = Orders.id;");

    qmodel_c1->query().first();
    qmodel_c1_1->query().first();

    ui->PB_wOpened->setText(qmodel_c1->query().value(0).toString());
    ui->PB_wInWork->setText(qmodel_c1->query().value(1).toString());
    ui->PB_wNew->setText(qmodel_c1->query().value(2).toString());
    ui->PB_wSolved->setText(qmodel_c1->query().value(3).toString());
    ui->PB_wAwaits->setText(qmodel_c1->query().value(4).toString());
    ui->PB_wOverdue->setText(qmodel_c1_1->query().value(0).toString());

    /*
    //Стили центальных кнопок
    //--------------------------------------------------------------------------------------------------------------------------------------------
    ui->PB_wOpened->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color:   blue}");
    ui->PB_wNew->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color:      aqua}");
    ui->PB_wAwaits->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color:   orange}");
    ui->PB_wSolved->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color:   darkgreen}");
    ui->PB_wOverdue->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color:  red}");
    ui->PB_wInWork->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color:   limegreen}");
    //--------------------------------------------------------------------------------------------------------------------------------------------
    */



    if(ui->PB_wOpened->text() == "0")
    {
        ui->PB_wOpened->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: black}");
    }
    else
    {
        ui->PB_wOpened->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: blue}");
    }
    if(ui->PB_wNew->text() == "0")
    {
        ui->PB_wNew->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: black}");
    }
    else
    {
        ui->PB_wNew->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: aqua}");
    }
    if(ui->PB_wInWork->text() == "0")
    {
        ui->PB_wInWork->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: black}");
    }
    else
    {
        ui->PB_wInWork->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: limegreen}");
    }
    if(ui->PB_wSolved->text() == "0")
    {
        ui->PB_wSolved->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: black}");
    }
    else
    {
        ui->PB_wSolved->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: darkgreen}");
    }
    if(ui->PB_wAwaits->text() == "0")
    {
        ui->PB_wAwaits->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: black}");
    }
    else
    {
        ui->PB_wAwaits->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: orange}");
    }
    if(ui->PB_wOverdue->text() == "0")
    {
        ui->PB_wOverdue->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: black}");
    }
    else
    {
        ui->PB_wOverdue->setStyleSheet("QPushButton{background: transparent; font-weight: bold; color: red}");
    }


    tmr->start(10000);
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//Клик на кнопку "Открытые"
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_PB_wOpened_clicked()
{
    ui->tabWidget->setCurrentIndex(1);

    ui->pushButton_twsSearch_del->click();

    ui->comboBox_var_1->setCurrentIndex(3);
    ui->comboBox_var_2->setCurrentIndex(1);
    ui->comboBox_var_3->setCurrentIndex(5);

    ui->tableView->setColumnWidth(1, 400);

    ui->pushButton_search->click();
}
//--------------------------------------------------------------------------------------------------------------------------------------------

void MainWindow::on_PB_wNew_clicked()
{
    ui->tabWidget->setCurrentIndex(1);

    ui->pushButton_twsSearch_del->click();

    ui->comboBox_var_1->setCurrentIndex(3);
    ui->comboBox_var_2->setCurrentIndex(0);
    ui->comboBox_var_3->setCurrentIndex(0);

    ui->tableView->setColumnWidth(1, 400);

    ui->pushButton_search->click();
}


void MainWindow::on_PB_wInWork_clicked()
{
    ui->tabWidget->setCurrentIndex(1);

    ui->pushButton_twsSearch_add->click();

    ui->comboBox_var_1->setCurrentIndex(3);
    ui->comboBox_var_2->setCurrentIndex(0);
    ui->comboBox_var_3->setCurrentIndex(1);
    ui->comboBox_var_0_0->setCurrentIndex(1);
    ui->comboBox_var_1_1->setCurrentIndex(3);
    ui->comboBox_var_2_2->setCurrentIndex(0);
    ui->comboBox_var_3_3->setCurrentIndex(2);

    ui->tableView->setColumnWidth(1, 400);

    ui->pushButton_search->click();
}


void MainWindow::on_PB_wSolved_clicked()
{
    ui->tabWidget->setCurrentIndex(1);

    ui->pushButton_twsSearch_del->click();

    ui->comboBox_var_1->setCurrentIndex(3);
    ui->comboBox_var_2->setCurrentIndex(0);
    ui->comboBox_var_3->setCurrentIndex(4);

    ui->tableView->setColumnWidth(1, 400);

    ui->pushButton_search->click();
}


void MainWindow::on_PB_wAwaits_clicked()
{
    ui->tabWidget->setCurrentIndex(1);

    ui->pushButton_twsSearch_del->click();

    ui->comboBox_var_1->setCurrentIndex(3);
    ui->comboBox_var_2->setCurrentIndex(0);
    ui->comboBox_var_3->setCurrentIndex(3);

    ui->tableView->setColumnWidth(1, 400);

    ui->pushButton_search->click();
}


void MainWindow::on_PB_wOverdue_clicked()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y.%m.%d", &tstruct);
    QString str(buf);

    ui->tabWidget->setCurrentIndex(1);

    ui->pushButton_twsSearch_add->click();

    ui->comboBox_var_1->setCurrentIndex(14);
    ui->comboBox_var_2->setCurrentIndex(4);
    ui->lineEdit_find->setText(str);
    ui->comboBox_var_0_0->setCurrentIndex(0);
    ui->comboBox_var_1_1->setCurrentIndex(3);
    ui->comboBox_var_2_2->setCurrentIndex(1);
    ui->comboBox_var_3_3->setCurrentIndex(5);

    ui->tableView->setColumnWidth(1, 400);

    ui->pushButton_search->click();
}


/*
    //PrintOrder *pr = new PrintOrder(mdiArea);


    //PrOrd->show();

    //PrOrd->setFixedSize(620, 877);

    //PrOrd->setWindowTitle("Sub Window");


    //PrOrd->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    //pr->update();


    //qDebug() << PrOrd->windowFlags();

    //mdiArea->addSubWindow(PrOrd, Qt::MSWindowsFixedSizeDialogHint);*/


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


//Вывод на печать из меню работы с отчетом
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_btn_print_clicked()
{
    QPrinter printer;
    //print(&printer);


    QPainter painter;

    //painter.setWindow(PrOrd->rect());
    //this->render(&painter);

    //QPrintDialog dialog(&printer, this);

    //QPixmap pix = QWidget::grab(PrOrd->rect());


    QPixmap pix = QPixmap::grabWidget(PrOrd);


    QPrintDialog dialog(&printer);


    if(dialog.exec() == QDialog::Accepted)
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
void MainWindow::onTableView_clicked()
{
    ui->tableView->selectRow(ui->tableView->currentIndex().row());

<<<<<<< HEAD
    qDebug() << index;
    qDebug() << ui->tableView->currentIndex().row();
=======
    //qDebug() << index;
>>>>>>> 54806f89d0e45761bd5f47c45d138df273804283
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

void MainWindow::FocusDateFi()
{
    ui->lineEdit_find->setText(calendarFi->selectedDate().toString(QString("yyyy.MM.dd")));
}

void MainWindow::FocusDateFi_2()
{
    ui->lineEdit_find_2->setText(calendarFi_2->selectedDate().toString(QString("yyyy.MM.dd")));
}
//--------------------------------------------------------------------------------------------------------------------------------------------

void MainWindow::FocusToolBtn()
{
    qDebug() << ui->tab_6->focusWidget();
}


//Создание новой заявки
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text() != "" && ui->lineEdit_6->text() != "" && ui->comboBox_6->currentIndex() != 0 && ui->comboBox_7->currentIndex() != 0
            && ui->comboBox_8->currentIndex() != 0 && ui->comboBox_10->currentIndex() != 0)
    {
        QMessageBox::StandardButton create;
        create = QMessageBox::question(this, "Запись заявки", "Вы действительно хотите внести сформированную заявку в базу данных?", QMessageBox::Yes|QMessageBox::No);

        if(create == QMessageBox::Yes)
        {
            time_t     now = time(0);
            struct tm  tstruct;
            char       buf[80];
            tstruct = *localtime(&now);

            strftime(buf, sizeof(buf), "%Y.%m.%d %X", &tstruct);

            QString str(buf);



            qmodel_id->setQuery("Select max(Orders.id), max(`Create`.id), max(`Edit`.id), max(`Work`.id), max(`Categories`.id), max(Priority.id), max(RequestSource.id), max(`Status`.id), max(`Control`.id) "
            "From `Categories`, `Create`, `Edit`, Orders, Priority, RequestSource, `Status`, `Work`, `Control`");
            qmodel_id->query().first();

            QSqlQuery creOrd(db);


            creOrd.prepare("INSERT INTO Orders (id, `Category`, `Priory`, `Status`, `Title`, `Description`, RequestSource, `Type`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
            creOrd.addBindValue(1 + qmodel_id->query().value(0).toInt());
            creOrd.addBindValue(ui->comboBox_6->currentIndex());
            creOrd.addBindValue(1 + ui->comboBox_9->currentIndex());
            creOrd.addBindValue(ui->comboBox_7->currentIndex());
            creOrd.addBindValue(ui->lineEdit_6->text());
            creOrd.addBindValue(ui->textEdit->toPlainText());
            creOrd.addBindValue(ui->comboBox_8->currentIndex());
            creOrd.addBindValue(1 + ui->comboBox_5->currentIndex());
            creOrd.exec();

            creOrd.prepare("INSERT INTO `Create` (id, `DateOpen`, WhoCreate) VALUES (?, ?, ?)");
            creOrd.addBindValue(1 + qmodel_id->query().value(1).toInt());
            creOrd.addBindValue(ui->lineEdit->text());
            creOrd.addBindValue(ui->comboBox_10->currentIndex());
            creOrd.exec();

            creOrd.prepare("INSERT INTO `Edit` (id, `DateEdit`, WhoEdit) VALUES (?, ?, ?)");
            creOrd.addBindValue(1 + qmodel_id->query().value(2).toInt());
            creOrd.addBindValue(str);
            creOrd.addBindValue(curUser);
            creOrd.exec();

            creOrd.prepare("INSERT INTO `Work` (id, WhoWork) VALUES (?, ?)");
            creOrd.addBindValue(1 + qmodel_id->query().value(3).toInt());
            if(ui->comboBox_12->currentIndex() == 0)
            {
                creOrd.addBindValue(QVariant(QVariant::Int));
            }
            else
            {
                creOrd.addBindValue(ui->comboBox_12->currentIndex());
            };
            creOrd.exec();

            creOrd.prepare("INSERT INTO `Control` (id, WhoControlling) VALUES (?, ?)");
            creOrd.addBindValue(1 + qmodel_id->query().value(8).toInt());
            if(ui->comboBox_11->currentIndex() == 0)
            {
                creOrd.addBindValue(QVariant(QVariant::Int));
            }
            else
            {
                creOrd.addBindValue(ui->comboBox_11->currentIndex());
            };
            creOrd.exec();

            tmr->start(0);
            emit ui->act_orders->triggered();
        }
    }
    else
    {
        QMessageBox::critical(this, "Формирование заявки", "Одно или несколько обязательных полей пусты!\n\nПожалуйста, проверь введенные данные.\n\n(Поля \"Наблюдатель\", \"Назначено\" и \"Описание\" не являются обязательными)");
        //return;
    }

    for (int i = 0; i< 2; i++)
    {
        if(leList.at(i)->text() == "")
        {
            lableList.at(i)->setStyleSheet("background-color: rgb(181, 181, 181); border: 2px solid red;");
        }
        else
        {
            lableList.at(i)->setStyleSheet("background-color: rgb(181, 181, 181);");
        }
    }
    for (int i = 0; i< 4; i++)
    {
        if(cbList.at(i)->currentIndex() == 0)
        {
            lableList.at(2 + i)->setStyleSheet("background-color: rgb(181, 181, 181); border: 2px solid red;");
        }
        else
        {
            lableList.at(2 + i)->setStyleSheet("background-color: rgb(181, 181, 181);");
        }
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------

void MainWindow::on_act_create_ord_triggered()
{    
    for (int i = 0; i < 6; i++)
    {
        lableList.at(i)->setStyleSheet("background-color: rgb(181, 181, 181);");
    }

    tabBar_2->hide();

    ui->tabWidget->setCurrentIndex(3);
    ui->tabWidget_2->setCurrentIndex(1);

    ui->label_idZayavki->setText("<html><head/><body><p><span style=' font-size:12pt; font-weight:600;'>Формирование новой заявки</span></p></body></html>");

    qmodel_categ->setQuery("SELECT NULL FROM `Categories` UNION SELECT `C+SC` From `Categories`");
    qmodel_stat->setQuery("SELECT NULL FROM `Status` UNION SELECT SName FROM `Status`");
    qmodel_reqS->setQuery("SELECT NULL FROM RequestSource UNION SELECT RName FROM RequestSource");
    qmodel_piory->setQuery("SELECT PName FROM Priority");
    qmodel_creator->setQuery("SELECT NULL FROM Users UNION SELECT FullName FROM Users");
    qmodel_super->setQuery("SELECT NULL FROM Users UNION SELECT FullName FROM Users WHERE FullName <> 'Почтовый робот'");
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

void MainWindow::twiceClickOnTableRow(const QModelIndex &index)
{    
    for (int i = 0; i < 6; i++)
    {
        lableList.at(i)->setStyleSheet("background-color: rgb(181, 181, 181);");
    }

    id = qmodel->index(index.row(), 0).data().toString();

    qmodel_ordId->setQuery("SELECT Orders.id, Orders.Title, Orders.`Status`, `Edit`.DateEdit, `Create`.DateOpen, `Work`.DateClose, `Create`.WhoCreate, `Edit`.WhoEdit, `Work`.WhoWork, Orders.Priory, Orders.Category, Orders.RequestSource, Orders.`Description`, Orders.`Type`, `Work`.DateDecision, `Control`.WhoControlling, editUser.FullName "
"FROM (((Orders INNER JOIN `Control` ON Orders.id = `Control`.id) INNER JOIN `Create` ON Orders.id = `Create`.id) INNER JOIN (Users AS editUser INNER JOIN `Edit` ON editUser.id = `Edit`.WhoEdit) ON Orders.id = `Edit`.id) INNER JOIN `Work` ON Orders.id = `Work`.id WHERE Orders.id = " + id);
    qmodel_ordId->query().first();

    qmodel_categ->setQuery("SELECT NULL FROM `Categories` UNION SELECT `C+SC` FROM `Categories`");
    qmodel_categ->setQuery("SELECT `C+SC`, id FROM `Categories` ORDER BY id");
    qmodel_stat->setQuery("SELECT NULL FROM `Status` UNION SELECT SName FROM `Status`");
    qmodel_reqS->setQuery("SELECT NULL FROM RequestSource UNION SELECT RName FROM RequestSource");
    qmodel_piory->setQuery("SELECT PName FROM Priority");
    qmodel_creator->setQuery("SELECT NULL FROM Users UNION SELECT FullName FROM Users");
    qmodel_super->setQuery("SELECT NULL FROM Users UNION SELECT FullName FROM Users WHERE FullName <> 'Почтовый робот'");
    qmodel_appoin->setQuery(qmodel_super->query());

    tabBar_2->show();

    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->label_17->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->toolButton_Decision->show();
    ui->toolButton_Closed->show();
    ui->comboBox_13->show();
    ui->pushButton->hide();

    ui->textEdit->clear(); ui->lineEdit->clear(); ui->lineEdit_4->clear(); ui->lineEdit_5->clear(); ui->lineEdit_6->clear();


    ui->tabWidget->setCurrentIndex(3);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->label_idZayavki->setText("<html><head/><body><p><span style=' font-size:12pt; font-weight:600;'>Заявка - ID  " + id + "  (ITOsoba LLC)</span></p></body></html>");
    ui->lineEdit->setText(QDateTime::fromString(qmodel_ordId->index(0, 4).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
    ui->lineEdit_4->setText(QDateTime::fromString(qmodel_ordId->index(0, 14).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
    ui->lineEdit_5->setText(QDateTime::fromString(qmodel_ordId->index(0, 5).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
    ui->comboBox_13->setCurrentIndex(qmodel_ordId->index(0, 6).data().toInt());
    ui->label_17->setText(QDateTime::fromString(qmodel_ordId->index(0, 3).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss") + "  на  " + qmodel_ordId->index(0, 16).data().toString());
    ui->comboBox_5->setCurrentIndex(qmodel_ordId->index(0, 13).data().toInt() - 1);    
    ui->comboBox_6->setCurrentIndex(qmodel_ordId->index(0, 10).data().toInt());
    ui->comboBox_7->setCurrentIndex(qmodel_ordId->index(0, 2).data().toInt());
    ui->comboBox_8->setCurrentIndex(qmodel_ordId->index(0, 11).data().toInt());
    ui->comboBox_9->setCurrentIndex(qmodel_ordId->index(0, 9).data().toInt() - 1);
    ui->comboBox_10->setCurrentIndex(qmodel_ordId->index(0, 6).data().toInt());
    ui->comboBox_11->setCurrentIndex(qmodel_ordId->index(0, 15).data().toInt());
    ui->comboBox_12->setCurrentIndex(qmodel_ordId->index(0, 8).data().toInt());
    ui->lineEdit_6->setText(qmodel_ordId->index(0, 1).data().toString());
    ui->textEdit->setText(qmodel_ordId->index(0, 12).data().toString());

    emit fillReportSig(QVariant(id).toInt());
}

void MainWindow::on_pushButton_2_clicked()
{    
    if(ui->lineEdit->text() != "" && ui->lineEdit_6->text() != "" && ui->comboBox_6->currentIndex() != 0 && ui->comboBox_7->currentIndex() != 0
            && ui->comboBox_8->currentIndex() != 0 && ui->comboBox_10->currentIndex() != 0)
    {
        QMessageBox::StandardButton create;
        create = QMessageBox::question(this, "Запись заявки", "Вы действительно хотите внести изменения в заявку?", QMessageBox::Yes|QMessageBox::No);

        if(create == QMessageBox::Yes)
        {
            time_t     now = time(0);
            struct tm  tstruct;
            char       buf[80];
            tstruct = *localtime(&now);
            strftime(buf, sizeof(buf), "%Y.%m.%d %X", &tstruct);
            QString str(buf);


            QSqlQuery updOrd(db);

            updOrd.prepare("UPDATE Orders SET `Category`=:1, `Priory`=:2, `Status`=:3, `Title`=:4, `Description`=:5, RequestSource=:6, `Type`=:7 WHERE Orders.id = " + id);
            updOrd.bindValue(":1", ui->comboBox_6->currentIndex());
            updOrd.bindValue(":2", ui->comboBox_9->currentIndex() + 1);
            updOrd.bindValue(":3", ui->comboBox_7->currentIndex());
            updOrd.bindValue(":4", ui->lineEdit_6->text());
            updOrd.bindValue(":5", ui->textEdit->toPlainText());
            updOrd.bindValue(":6", ui->comboBox_8->currentIndex());
            updOrd.bindValue(":7", ui->comboBox_5->currentIndex() + 1);
            updOrd.exec();

            updOrd.prepare("UPDATE `Create` SET `DateOpen`=:1, WhoCreate=:2 WHERE `Create`.id = " + id);
            updOrd.bindValue(":1", ui->lineEdit->text());
            updOrd.bindValue(":2", ui->comboBox_10->currentIndex());
            updOrd.exec();

            updOrd.prepare("UPDATE `Edit` SET `DateEdit`=:1, WhoEdit=:2 WHERE `Edit`.id = " + id);
            updOrd.bindValue(":1", str);
            updOrd.bindValue(":2", curUser);
            updOrd.exec();

            updOrd.prepare("UPDATE `Control` SET `WhoControlling`=:1 WHERE `Control`.id = " + id);
            if(ui->comboBox_11->currentIndex() == 0)
            {
                updOrd.bindValue(":1", QVariant(QVariant::Int));
            }
            else
            {
                updOrd.bindValue(":1", ui->comboBox_11->currentIndex());
            };
            updOrd.exec();

            updOrd.prepare("UPDATE `Work` SET `DateClose`=:1, WhoWork=:2, `DateDecision`=:3 WHERE `Work`.id = " + id);
            if(ui->lineEdit_5->text() == "")
            {
                updOrd.bindValue(":1", QVariant(QVariant::DateTime));
            }
            else
            {
                updOrd.bindValue(":1", ui->lineEdit_5->text());
            };
            if(ui->comboBox_12->currentIndex() == 0)
            {
                updOrd.bindValue(":2", QVariant(QVariant::Int));
            }
            else
            {
                updOrd.bindValue(":2", ui->comboBox_12->currentIndex());
            };
            if(ui->lineEdit_4->text() == "")
            {
                updOrd.bindValue(":3", QVariant(QVariant::DateTime));
            }
            else
            {
                updOrd.bindValue(":3", ui->lineEdit_4->text());
            };
            updOrd.exec();

            saveTmr->start(500);
        }
    }
    else
    {
        QMessageBox::critical(this, "Редактирование заявки", "Одно или несколько обязательных полей пусты!\n\nПожалуйста, проверь введенные данные.\n\n(Поля \"Наблюдатель\", \"Назначено\", \"Описание\", \"Дата решения\" и \"Дата закрытия\" не являются обязательными)");
        //return;
    }

    for (int i = 0; i< 2; i++)
    {
        if(leList.at(i)->text() == "")
        {
            lableList.at(i)->setStyleSheet("background-color: rgb(181, 181, 181); border: 2px solid red;");
        }
        else
        {
            lableList.at(i)->setStyleSheet("background-color: rgb(181, 181, 181);");
        }
    }
    for (int i = 0; i< 4; i++)
    {
        if(cbList.at(i)->currentIndex() == 0)
        {
            lableList.at(2 + i)->setStyleSheet("background-color: rgb(181, 181, 181); border: 2px solid red;");
        }
        else
        {
            lableList.at(2 + i)->setStyleSheet("background-color: rgb(181, 181, 181);");
        }
    }
}

void MainWindow::updEditOrd()
{    
    qmodel_ordId->setQuery("SELECT Orders.id, Orders.Title, Orders.`Status`, `Edit`.DateEdit, `Create`.DateOpen, `Work`.DateClose, `Create`.WhoCreate, `Edit`.WhoEdit, `Work`.WhoWork, Orders.Priory, Orders.Category, Orders.RequestSource, Orders.`Description`, Orders.`Type`, `Work`.DateDecision, `Control`.WhoControlling, editUser.FullName "
"FROM (((Orders INNER JOIN `Control` ON Orders.id = `Control`.id) INNER JOIN `Create` ON Orders.id = `Create`.id) INNER JOIN (Users AS editUser INNER JOIN `Edit` ON editUser.id = `Edit`.WhoEdit) ON Orders.id = `Edit`.id) INNER JOIN `Work` ON Orders.id = `Work`.id WHERE Orders.id = " + id);

    ui->label_idZayavki->setText("<html><head/><body><p><span style=' font-size:12pt; font-weight:600;'>Заявка - ID  " + id + "  (ITOsoba LLC)</span></p></body></html>");
    ui->lineEdit->setText(QDateTime::fromString(qmodel_ordId->index(0, 4).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
    ui->lineEdit_4->setText(QDateTime::fromString(qmodel_ordId->index(0, 14).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
    ui->lineEdit_5->setText(QDateTime::fromString(qmodel_ordId->index(0, 5).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
    ui->comboBox_13->setCurrentIndex(qmodel_ordId->index(0, 6).data().toInt());
    ui->label_17->setText(QDateTime::fromString(qmodel_ordId->index(0, 3).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss") + "  на  " + qmodel_ordId->index(0, 16).data().toString());
    ui->comboBox_5->setCurrentIndex(qmodel_ordId->index(0, 13).data().toInt() - 1);
    ui->comboBox_6->setCurrentIndex(qmodel_ordId->index(0, 10).data().toInt());
    ui->comboBox_7->setCurrentIndex(qmodel_ordId->index(0, 2).data().toInt());
    ui->comboBox_8->setCurrentIndex(qmodel_ordId->index(0, 11).data().toInt());
    ui->comboBox_9->setCurrentIndex(qmodel_ordId->index(0, 9).data().toInt() - 1);
    ui->comboBox_10->setCurrentIndex(qmodel_ordId->index(0, 6).data().toInt());
    ui->comboBox_11->setCurrentIndex(qmodel_ordId->index(0, 15).data().toInt());
    ui->comboBox_12->setCurrentIndex(qmodel_ordId->index(0, 8).data().toInt());
    ui->lineEdit_6->setText(qmodel_ordId->index(0, 1).data().toString());
    ui->textEdit->setText(qmodel_ordId->index(0, 12).data().toString());

    saveTmr->stop();
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton del;
    del = QMessageBox::question(this, "Удаление заявки", "Внимание!!!\n\nДанные по заявке  \"ID " + id + "\"  будут удалены безвозвратно!\n\nВы действительно хотите удалить заявку?", QMessageBox::Yes|QMessageBox::No);

    if(del == QMessageBox::Yes)
    {
        QSqlQuery delOrd(db);

        delOrd.exec("DELETE FROM `Create` WHERE id = " + id);
        delOrd.exec("DELETE FROM `Work` WHERE id = " + id);
        delOrd.exec("DELETE FROM `Edit` WHERE id = " + id);
        delOrd.exec("DELETE FROM `Control` WHERE id = " + id);
        delOrd.exec("DELETE FROM `Orders` WHERE id = " + id);

        tmr->start(0);
        emit ui->act_orders->triggered();
    }
}

void MainWindow::on_pushButton_twsSearch_add_clicked()
{
    ui->pushButton_twsSearch_add->hide();
    ui->groupBox_2->setMinimumHeight(90);
    ui->pushButton_twsSearch_del->show();
    ui->comboBox_var_0_0->show();
    ui->comboBox_var_1_1->show();
    ui->comboBox_var_1_1->setCurrentIndex(0);
    ui->comboBox_var_2_2->show();
    ui->comboBox_var_3_3->show();

    ui->pushButton_search->setGeometry(920, 50, 70, 22);
}

void MainWindow::on_pushButton_twsSearch_del_clicked()
{
    ui->pushButton_twsSearch_add->show();
    ui->groupBox_2->setMinimumHeight(60);
    ui->pushButton_twsSearch_del->hide();
    ui->comboBox_var_0_0->hide();
    ui->comboBox_var_1_1->hide();
    ui->comboBox_var_1_1->setCurrentIndex(0);
    ui->comboBox_var_2_2->hide();
    ui->lineEdit_find_2->hide();
    ui->comboBox_var_3_3->hide();

    ui->pushButton_search->setGeometry(920, 20, 70, 22);
}
