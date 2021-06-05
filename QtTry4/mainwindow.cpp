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
    qmodel_stats = new QSqlQueryModel;
    qmodel_reqS = new QSqlQueryModel;
    qmodel_piory = new QSqlQueryModel;
    qmodel_agree = new QSqlQueryModel;
    qmodel_creator = new QSqlQueryModel;
    qmodel_super = new QSqlQueryModel;
    qmodel_appoin = new QSqlQueryModel;
    qmodel_id = new QSqlQueryModel;
    qmodel_ordId = new QSqlQueryModel;
    filOrd = new QSqlQueryModel;
    filOrd_1 = new QSqlQueryModel;
    countOrd = new QSqlQueryModel;

    qmodel_actID = new QSqlQueryModel;
    qmodel_act = new QSqlQueryModel;
    qmodel_usrNames = new QSqlQueryModel;

    qmodel_u_func = new QSqlQueryModel;
    qmodel_u_rules = new QSqlQueryModel;

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

    //Внешний вид TableView и загрузка моделей
    //--------------------------------------------------------------------------------------------------------------------------------------------
    queryMode = 1;    

    ui->tableView->setFocusPolicy(Qt::NoFocus);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setStyleSheet("QHeaderView::section { background: rgb(181,181,181);}");
    ui->tableView->setModel(qmodel);

    ui->tableView_2->setFocusPolicy(Qt::NoFocus);
    ui->tableView_2->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView_2->verticalHeader()->setVisible(false);
    ui->tableView_2->setStyleSheet("QHeaderView::section { background: rgb(181,181,181);}");
    ui->tableView_2->setModel(qmodel_stats);
    //--------------------------------------------------------------------------------------------------------------------------------------------


    //Валидатор значений для полей дата/время
    //--------------------------------------------------------------------------------------------------------------------------------------------
    QRegExp r_date_time("(19[0-9][0-9]|20[0-9][0-9])\\.(0[1-9]|[1][0-2])\\.(0[1-9]|[12][0-9]|3[01])\\ (0[1-9]|1[0-9]|2[0-3])\\:([0-5][0-9])\\:([0-5][0-9])");
    QRegExpValidator *valida = new QRegExpValidator(r_date_time, this);    

    ui->lineEdit->setValidator(valida);
    ui->lineEdit_4->setValidator(valida);
    ui->lineEdit_5->setValidator(valida);
    ui->lineEdit_u_validF->setValidator(valida);
    ui->lineEdit_u_validU->setValidator(valida);
    ui->lineEdit_set_beg_date_work->setValidator(valida);
    ui->lineEdit_set_fin_date_work->setValidator(valida);
    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Кнопки вывода календаря (наверное можно компактнее)
    //--------------------------------------------------------------------------------------------------------------------------------------------
    menuOp = new QMenu(this);
    menuCl = new QMenu(this);
    menuDi = new QMenu(this);
    menuFi = new QMenu(this);
    menuFi_2 = new QMenu(this);
    menuVF = new QMenu(this);
    menuVU = new QMenu(this);
    menuSBD = new QMenu(this);
    menuSFD = new QMenu(this);
    menuDecision = new QMenu(this);
    calendarOp = new ClickableCalendar();
    calendarCl = new ClickableCalendar();
    calendarDi = new ClickableCalendar();
    calendarFi = new ClickableCalendar();
    calendarFi_2 = new ClickableCalendar();
    calendarVF = new ClickableCalendar();
    calendarVU = new ClickableCalendar();
    calendarSBD = new ClickableCalendar();
    calendarSFD = new ClickableCalendar();
    calendarDecision = new ClickableCalendar();
    actionOp = new QWidgetAction(this);
    actionCl = new QWidgetAction(this);
    actionDi = new QWidgetAction(this);
    actionFi = new QWidgetAction(this);
    actionFi_2 = new QWidgetAction(this);
    actionVF = new QWidgetAction(this);
    actionVU = new QWidgetAction(this);
    actionSBD = new QWidgetAction(this);
    actionSFD = new QWidgetAction(this);
    actionDecision = new QWidgetAction(this);

    actionOp->setDefaultWidget(calendarOp);
    actionCl->setDefaultWidget(calendarCl);
    actionDi->setDefaultWidget(calendarDi);
    actionFi->setDefaultWidget(calendarFi);
    actionFi_2->setDefaultWidget(calendarFi_2);
    actionVF->setDefaultWidget(calendarVF);
    actionVU->setDefaultWidget(calendarVU);
    actionSBD->setDefaultWidget(calendarSBD);
    actionSFD->setDefaultWidget(calendarSFD);
    actionDecision->setDefaultWidget(calendarDecision);
    menuOp->addAction(actionOp);
    menuCl->addAction(actionCl);
    menuDi->addAction(actionDi);
    menuFi->addAction(actionFi);
    menuFi_2->addAction(actionFi_2);
    menuVF->addAction(actionVF);
    menuVU->addAction(actionVU);
    menuSBD->addAction(actionSBD);
    menuSFD->addAction(actionSFD);
    menuDecision->addAction(actionDecision);

    ui->toolButton_Opened->setMenu(menuOp);
    ui->toolButton_Decision->setMenu(menuDi);
    ui->toolButton_Closed->setMenu(menuCl);
    ui->toolButton_Filter->setMenu(menuFi);
    ui->toolButton_Filter_2->setMenu(menuFi_2);
    ui->toolButton_u_validF->setMenu(menuVF);
    ui->toolButton_u_validU->setMenu(menuVU);
    ui->toolButton_set_beg_date_work->setMenu(menuSBD);
    ui->toolButton_set_fin_date_work->setMenu(menuSFD);
    ui->toolButton_set_date_decision->setMenu(menuDecision);
    //--------------------------------------------------------------------------------------------------------------------------------------------



    //Блок соединений
    //--------------------------------------------------------------------------------------------------------------------------------------------
    connect(sw, SIGNAL(ShowMain()), this, SLOT(reciveSignal()));
    connect(sw, SIGNAL(DBConnect(QString, QString, QString)), this, SLOT(SigDBConnect(QString, QString, QString)));
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
    connect(calendarVF, SIGNAL(clickedDate()), this, SLOT(FocusDateVF()));
    connect(calendarVU, SIGNAL(clickedDate()), this, SLOT(FocusDateVU()));
    connect(calendarSBD, SIGNAL(clickedDate()), this, SLOT(FocusDateSBD()));
    connect(calendarSFD, SIGNAL(clickedDate()), this, SLOT(FocusDateSFD()));
    connect(calendarDecision, SIGNAL(clickedDate()), this, SLOT(FocusDateDecision()));
    connect(ui->toolButton_Opened, SIGNAL(clicked()), this, SLOT(FocusToolBtn()));
    connect(saveTmr, SIGNAL(timeout()), this, SLOT(updEditOrd()));
    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(twiceClickOnTableRow(const QModelIndex &)));
    connect(ui->comboBox_var_1, SIGNAL(currentIndexChanged(QString)), this, SLOT(Var_2_changed()));
    connect(ui->comboBox_var_1_1, SIGNAL(currentIndexChanged(QString)), this, SLOT(Var_2_1_changed()));
    connect(this, SIGNAL(fillReportSig(int)), PrOrd, SLOT(fillReport(int)));
    connect(this, SIGNAL(reload()), sw, SLOT(logOut()));
    connect(ui->comboBox_pages, SIGNAL(currentIndexChanged(int)), this, SLOT(countPagesChanges()));




    //ui->tableView->clicked()
    //connect(ui->tabWidget_2, SIGNAL(tabBarClicked()), ui->lineEdit, SLOT());
    //connect(ui->tab_6, SIGNAL(returnPressed(QKeyEvent *)), this, SLOT(ClearFocusLE()));
    //qDebug() << ui->tab_6->focusWidget();

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
    var1_u = new QStringList {"Все", "Имя", "Имя профиля", "e-mail", "Телефон", "Мобильный тел.", "Телефон 2", "Мобильный тел. 2", "Описание", "Профиль доступа",
                              "Должность", "Активен (статус)", "Активен с...", "Активен до..."};
    var1_1_u = new QStringList {"*", "Users.FullName", "Users.`Login`", "Users.Email", "Users.Phone", "Users.Phone_m", "Users.Phone2", "Users.Phone2_m",
                                "Users.`Description`", "Users.`Rights`", "Users.`Function`", "Users.`Active`", "Users.Valid_from", "Users.Valid_until"};
    var1_2 = new QStringList {"LIKE", "NOT LIKE", "=", "<>", "<", ">"};

    var2_1 = new QStringList {"Содержит", "Не содержит"};
    var2_2 = new QStringList {"Равен", "Не равен"};
    var2_3 = new QStringList {"Содержит", "Не содержит", "Равна", "Не равна", "До", "После"};
    var2_4 = new QStringList {"Содержит", "Не содержит", "Равен", "Не равен"};

    Limit_s = new QStringList {"5", "10", "15", "20", "30", "40", "50", "100", "250", "500", "1000", "2500", "5000", "9999"};
    Limit_bef = "15";
    Limit = "15";
    multiplier_f = 1;
    multiplier_s = 1;
    ui->comboBox_pages->addItems(*Limit_s);
    ui->comboBox_pages->setCurrentIndex(2);

    ui->comboBox_var_0->addItems(var0);
    ui->comboBox_var_0_0->addItems(var0_1);
    ui->comboBox_var_0->setDisabled(true);

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


    //Заполнение ComboBox-ов моделями данных
    //--------------------------------------------------------------------------------------------------------------------------------------------
    QStringList type = {"Инцендент", "Запрос"};
    QStringList active = {"Нет", "Да"};
    QStringList agreement = {"В ожидании согласования", "Отклонено", "Принята", "Не подлежит согласованию"};

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
    ui->comboBox_ord_agree->setModel(qmodel_agree);
    ui->comboBox_set_status_agree->addItems(agreement);

    ui->comboBox_u_active->addItems(active);
    ui->comboBox_u_func->setModel(qmodel_u_func);
    ui->comboBox_u_rules->setModel(qmodel_u_rules);
    //--------------------------------------------------------------------------------------------------------------------------------------------


    //Отключение вкладок TabBar-ов
    //--------------------------------------------------------------------------------------------------------------------------------------------
    tabBar_2 = ui->tabWidget_2->findChild<QTabBar *>();
    tabBar_3 = ui->tabWidget_3->findChild<QTabBar *>();
    tabBar_3->hide();
    //--------------------------------------------------------------------------------------------------------------------------------------------


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

    leList2.operator<<(ui->lineEdit_u_login).operator<<(ui->lineEdit_u_secName).operator<<(ui->lineEdit_u_name).operator<<(ui->lineEdit_u_password).operator<<(ui->lineEdit_u_pass_valid).operator<<(ui->lineEdit_u_phone);
    lableList2.operator<<(ui->label_u_login).operator<<(ui->label_u_secName).operator<<(ui->label_u_name).operator<<(ui->label_u_password).operator<<(ui->label_u_pass_valid).operator<<(ui->label_u_phone);

    ui->widget_set_agree->hide();
    ui->widget_set_mess->hide();
    ui->widget_set_work->hide();

    act_type_click = 0;

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
    queryMode = 1;
    multiplier_f = 1;

    ui->comboBox_var_1->clear();
    ui->comboBox_var_1_1->clear();
    ui->comboBox_var_1->addItems(*var1);
    ui->comboBox_var_1_1->addItems(*var1);

    ui->pushButton_twsSearch_del->click();

    ui->tabWidget->setCurrentIndex(1);    

    ui->tableView->setColumnWidth(1, 400);
    ui->tableView->resizeRowsToContents();

    ui->comboBox_var_1->setCurrentIndex(0);

    for (int i = 0; i < 6; i++)
    {
        lableList.at(i)->setStyleSheet("background-color: rgb(181, 181, 181);");
    }

    ui->pushButton_search->click();
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//Занесение вариантов выбора в фильтр 1
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::Var_2_changed()
{
    ui->comboBox_var_2->clear();
    multiplier_f = 1;

    if(queryMode == 1){
    if(ui->comboBox_var_1->currentIndex() == 0)
    {
        ui->comboBox_var_2->setDisabled(true);
        ui->comboBox_var_3->setDisabled(true);
        ui->lineEdit_find->clear();
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
        ui->lineEdit_find->clear();
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
        ui->lineEdit_find->clear();
        ui->lineEdit_find->show();
        ui->toolButton_Filter->show();
    }
    else
    {
        ui->comboBox_var_2->setDisabled(false);
        ui->comboBox_var_3->setDisabled(false);
        ui->lineEdit_find->setDisabled(false);
        ui->comboBox_var_2->addItems(*var2_4);
        ui->lineEdit_find->clear();
        ui->lineEdit_find->show();
        ui->toolButton_Filter->hide();
    };
    }else if(queryMode == 2){
        if(ui->comboBox_var_1->currentIndex() == 0)
        {
            ui->comboBox_var_2->setDisabled(true);
            ui->comboBox_var_3->setDisabled(true);
            ui->lineEdit_find->clear();
            ui->lineEdit_find->show();
            ui->lineEdit_find->setDisabled(true);
            ui->toolButton_Filter->hide();
            ui->comboBox_var_3->show();
        }
        else if(ui->comboBox_var_1->currentIndex() > 0 && ui->comboBox_var_1->currentIndex() < 9)
        {
            ui->comboBox_var_2->setDisabled(false);
            ui->comboBox_var_3->setDisabled(false);
            ui->comboBox_var_2->addItems(*var2_1);
            ui->comboBox_var_3->hide();
            ui->lineEdit_find->clear();
            ui->lineEdit_find->show();
            ui->lineEdit_find->setDisabled(false);
            ui->toolButton_Filter->hide();
        }else if(ui->comboBox_var_1->currentIndex() > 8 && ui->comboBox_var_1->currentIndex() < 12)
        {
            ui->comboBox_var_2->setDisabled(false);
            ui->comboBox_var_3->setDisabled(false);
            ui->comboBox_var_2->addItems(*var2_2);
            ui->lineEdit_find->hide();
            ui->toolButton_Filter->hide();
            ui->comboBox_var_3->show();

            QStringList sub_var_2 = {"`Rights`", "`Functions`"};
            QStringList sub_var = {"`Name`", "`FName`", };
            QStringList active = {"`Нет`", "`Да`"};

            if(ui->comboBox_var_1->currentIndex() == 11){
                ui->comboBox_var_3->setModel(ui->comboBox_u_active->model());
            }else{
                filOrd->setQuery("SELECT " + sub_var.at(ui->comboBox_var_1->currentIndex() - 9) + " FROM " + sub_var_2.at(ui->comboBox_var_1->currentIndex() - 9) + ";");
                ui->comboBox_var_3->setModel(filOrd);
            }


        }
        else
        {
            ui->comboBox_var_2->setDisabled(false);
            ui->comboBox_var_3->setDisabled(false);
            ui->lineEdit_find->setDisabled(false);
            ui->comboBox_var_2->addItems(*var2_3);
            ui->comboBox_var_3->hide();
            ui->lineEdit_find->clear();
            ui->lineEdit_find->show();
            ui->toolButton_Filter->show();
        };
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//Занесение вариантов выбора в фильтр 2
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::Var_2_1_changed()
{
    //qDebug() << "Signal";
    ui->comboBox_var_2_2->clear();
    multiplier_f = 1;

    if(queryMode == 1){
    if(ui->comboBox_var_1_1->currentIndex() == 0)
    {
        ui->comboBox_var_2_2->setDisabled(true);
        ui->comboBox_var_3_3->setDisabled(true);
        ui->lineEdit_find_2->clear();
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
        ui->lineEdit_find_2->clear();
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
        ui->lineEdit_find_2->clear();
        ui->lineEdit_find_2->show();
        ui->toolButton_Filter_2->show();
    }
    else
    {
        ui->comboBox_var_2_2->setDisabled(false);
        ui->comboBox_var_3_3->setDisabled(false);
        ui->lineEdit_find_2->setDisabled(false);
        ui->comboBox_var_2_2->addItems(*var2_4);
        ui->lineEdit_find_2->clear();
        ui->lineEdit_find_2->show();
        ui->toolButton_Filter_2->hide();
    };
    }else if(queryMode == 2){
        if(ui->comboBox_var_1_1->currentIndex() == 0)
        {
            ui->comboBox_var_2_2->setDisabled(true);
            ui->comboBox_var_3_3->setDisabled(true);
            ui->lineEdit_find_2->clear();
            ui->lineEdit_find_2->show();
            ui->lineEdit_find_2->setDisabled(true);
            ui->toolButton_Filter_2->hide();
            ui->comboBox_var_3_3->show();
        }
        else if(ui->comboBox_var_1_1->currentIndex() > 0 && ui->comboBox_var_1_1->currentIndex() < 9)
        {
            ui->comboBox_var_2_2->setDisabled(false);
            ui->comboBox_var_3_3->setDisabled(false);
            ui->comboBox_var_2_2->addItems(*var2_1);
            ui->comboBox_var_3_3->hide();
            ui->lineEdit_find_2->clear();
            ui->lineEdit_find_2->show();
            ui->lineEdit_find_2->setDisabled(false);
            ui->toolButton_Filter_2->hide();
        }else if(ui->comboBox_var_1_1->currentIndex() > 8 && ui->comboBox_var_1_1->currentIndex() < 12)
        {
            ui->comboBox_var_2_2->setDisabled(false);
            ui->comboBox_var_3_3->setDisabled(false);
            ui->comboBox_var_2_2->addItems(*var2_2);
            ui->lineEdit_find_2->hide();
            ui->toolButton_Filter_2->hide();
            ui->comboBox_var_3_3->show();

            QStringList sub_var_2 = {"`Rights`", "`Functions`"};
            QStringList sub_var = {"`Name`", "`FName`" };
            QStringList active = {"`Нет`", "`Да`"};

            if(ui->comboBox_var_1_1->currentIndex() == 11){
                ui->comboBox_var_3_3->setModel(ui->comboBox_u_active->model());

            }else{
                filOrd_1->setQuery("SELECT " + sub_var.at(ui->comboBox_var_1_1->currentIndex() - 9) + " FROM " + sub_var_2.at(ui->comboBox_var_1_1->currentIndex() - 9) + ";");
                ui->comboBox_var_3_3->setModel(filOrd_1);
            }

        }
        else
        {
            ui->comboBox_var_2_2->setDisabled(false);
            ui->comboBox_var_3_3->setDisabled(false);
            ui->lineEdit_find_2->setDisabled(false);
            ui->comboBox_var_2_2->addItems(*var2_3);
            ui->comboBox_var_3_3->hide();
            ui->lineEdit_find_2->clear();
            ui->lineEdit_find_2->show();
            ui->toolButton_Filter_2->show();
        };
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//Клик по кнопке "Поиск" в окне вывода заявок
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_search_clicked()
{    
    cbVar_1 = ui->comboBox_var_1->currentIndex();
    cbVar_2 = ui->comboBox_var_2->currentIndex();
    cbVar_3 = ui->comboBox_var_3->currentIndex();
    leFind = ui->lineEdit_find->text();

    multiplier_s = multiplier_f;
/*
    if(countOrd->index(0,0).data().toInt() - (QVariant(ui->comboBox_pages->currentText()).toInt() * multiplier_s) < 0){
        offset = "0";
    }else{
        offset = QVariant(countOrd->index(0,0).data().toInt() - (QVariant(ui->comboBox_pages->currentText()).toInt() * multiplier_s)).toString();}

    if(countOrd->index(0,0).data().toInt() - lTo >= 0){
        Limit = ui->comboBox_pages->currentText();
    }else{
        Limit = QVariant(abs(countOrd->index(0,0).data().toInt() - lTo)).toString();
    }
*/
    Limit = Limit_bef;

    lFrom = (1 + (QVariant(ui->comboBox_pages->currentText()).toInt() * (multiplier_s - 1)));

    offset = QVariant(QVariant(ui->comboBox_pages->currentText()).toInt() * (multiplier_s - 1)).toString();

    if(queryMode == 1){

    if(ui->pushButton_twsSearch_del->isVisible()){
        cbVar_0_1 = ui->comboBox_var_0_0->currentIndex();
        cbVar_1_1 = ui->comboBox_var_1_1->currentIndex();
        cbVar_2_1 = ui->comboBox_var_2_2->currentIndex();
        cbVar_3_1 = ui->comboBox_var_3_3->currentIndex();
        leFind_1 = ui->lineEdit_find_2->text();

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

    }else if(queryMode == 2){

        if(ui->pushButton_twsSearch_del->isVisible()){
            cbVar_0_1 = ui->comboBox_var_0_0->currentIndex();
            cbVar_1_1 = ui->comboBox_var_1_1->currentIndex();
            cbVar_2_1 = ui->comboBox_var_2_2->currentIndex();
            cbVar_3_1 = ui->comboBox_var_3_3->currentIndex();
            leFind_1 = ui->lineEdit_find_2->text();

            btnVis = true;
            str_and = var0_0->at(cbVar_0_1);

            if(cbVar_1_1 > 11){
                if(cbVar_2_1 > 1){
                    leFind_1 = QDateTime::fromString(ui->lineEdit_find_2->text(), "yyyy.MM.dd").toString("yyyy-MM-dd");}
                    str_4_1 = "";
                if(cbVar_2_1 == 4){
                    str_4_1 = " 00:00:00'";
                }else if(cbVar_2_1 == 5){
                    str_4_1 = " 23:59:59'";}
            }else{
                if(cbVar_2_1 == 2 || cbVar_2_1 == 3){
                    str_4_1 = "'";
                }else{
                str_4_1 = "";}}

            if(cbVar_1_1 == 9){
                str_3_1 = "'" + ui->comboBox_var_3_3->currentText() + "'";
            }else if (cbVar_1_1 == 11){
                str_3_1 = QVariant(cbVar_3_1).toString();
            }else if(cbVar_1_1 == 10){
                str_3_1 = QVariant(cbVar_3_1 + 1).toString();
            }else if(cbVar_1_1 > 11 && (cbVar_2_1 > 3)){
                str_3_1 = "'" + leFind_1;
            }else{
                str_3_1 = "'%" + leFind_1 + "%'";
            }
        }else{
            btnVis = false;
            str_1_1 = "";
            str_2_1 = "";
            str_3_1 = "";
            str_4_1 = "";
            str_and = "";}

        if(cbVar_1 > 11){
            if(cbVar_2 > 1){
                leFind = QDateTime::fromString(ui->lineEdit_find->text(), "yyyy.MM.dd").toString("yyyy-MM-dd");}
                str_4 = "";
            if(cbVar_2 == 4){
                str_4 = " 00:00:00'";
            }else if(cbVar_2 == 5){
                str_4 = " 23:59:59'";}
        }else{
            if(cbVar_2 == 2 || cbVar_2 == 3){
                str_4 = "'";
            }else{
            str_4 = "";}}

        if(cbVar_1 == 9){
            str_3 = "'" + ui->comboBox_var_3->currentText() + "'";
        }else if (cbVar_1 == 11){
            str_3 = QVariant(cbVar_3).toString();
        }else if(cbVar_1 == 10){
            str_3 = QVariant(cbVar_3 + 1).toString();
        }else if(cbVar_1 > 11 && (cbVar_2 > 3)){
            str_3 = "'" + leFind;
        }else{
            str_3 = "'%" + leFind + "%'";
        }
    }

    tmr->start(1);
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
void MainWindow::SigDBConnect(QString name, QString type, QString ip)
{
    if(type == "MS Access")
    {
        db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName(name);
    }

    if(type == "mySQL (Localhost)")
    {
        db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("localhost");
        db.setDatabaseName(name);
        db.setUserName("root");
        db.setPassword("root");
    }

    if(type == "mySQL (Server)")
    {
        db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName(ip);
        db.setDatabaseName(name);
        db.setUserName("root");
        db.setPassword("root");

        /*
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(ip);
        db.setDatabaseName(name);
        db.setUserName("root");
        db.setPassword("root");*/
    }

    if(type == "mySQL")
    {
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

void MainWindow::RevCon()
{
    conect = false;
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

                    if(query.value(6).toString() != "") {
                        ui->pushButton_5->setText("  " + query.value(1).toString() + " (" + query.value(6).toString() + ")");
                    }else{
                        ui->pushButton_5->setText("  " + query.value(1).toString() + " ( n/a )");
                    }

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

    if(counterUpdate == 1){
        on_act_orders_triggered();
        on_act_home_triggered();
    }

    qDebug() << "Update #" + QVariant(counterUpdate).toString() + "   Current User ID: " + QVariant(curUser).toString();



    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    QString str(buf);



    qmodel_stats->setQuery("SELECT `Status`.SName AS `Orders`, COUNT(Orders.`Status`) AS `Amount` FROM Orders LEFT JOIN `Status` ON Orders.`Status` = `Status`.id");
    qmodel_stats->query().first();


    if(queryMode == 1){

        countOrd->setQuery("Select Count(Orders.id) From Orders;");
        countOrd->query().first();



    if((cbVar_1 == 0 && btnVis == false) || (btnVis && (cbVar_1 == 0 || cbVar_1_1 == 0))) {
        qmodel->setQuery("SELECT Orders.id, Orders.Title, `Status`.SName AS `Status`, `Edit`.DateEdit AS `Last edit`, `Create`.DateOpen AS `Date Open`, Priority.PName AS `Priority`, createUser.FullName AS `Initiator`, workUser.FullName AS `Appointed`, Categories.`C+SC` AS `Category` "
        "FROM Users AS workUser RIGHT JOIN (Categories INNER JOIN (`Status` INNER JOIN (Priority INNER JOIN (((Orders INNER JOIN (Users AS createUser INNER JOIN `Create` ON createUser.id = `Create`.WhoCreate) ON Orders.id = `Create`.id) INNER JOIN `Edit` ON Orders.id = `Edit`.id) INNER JOIN `Work` ON Orders.id = `Work`.id) ON Priority.id = Orders.Priory) ON `Status`.id = Orders.`Status`) ON Categories.id = Orders.Category) ON workUser.id = `Work`.WhoWork "
        "ORDER BY Orders.id DESC;");
        qmodel->query().first();
        countRows = qmodel->rowCount();

        qmodel->setQuery("SELECT Orders.id, Orders.Title, `Status`.SName AS `Status`, `Edit`.DateEdit AS `Last edit`, `Create`.DateOpen AS `Date Open`, Priority.PName AS `Priority`, createUser.FullName AS `Initiator`, workUser.FullName AS `Appointed`, Categories.`C+SC` AS `Category` "
        "FROM Users AS workUser RIGHT JOIN (Categories INNER JOIN (`Status` INNER JOIN (Priority INNER JOIN (((Orders INNER JOIN (Users AS createUser INNER JOIN `Create` ON createUser.id = `Create`.WhoCreate) ON Orders.id = `Create`.id) INNER JOIN `Edit` ON Orders.id = `Edit`.id) INNER JOIN `Work` ON Orders.id = `Work`.id) ON Priority.id = Orders.Priory) ON `Status`.id = Orders.`Status`) ON Categories.id = Orders.Category) ON workUser.id = `Work`.WhoWork "
        "ORDER BY Orders.id DESC LIMIT " + Limit + " OFFSET " + offset + ";");

        qmodel->query().first();
    }else{
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
        qmodel->query().first();
        countRows = qmodel->rowCount();

        qmodel->setQuery("SELECT Orders.id, Orders.Title, `Status`.SName AS `Status`, `Edit`.DateEdit AS `Last edit`, `Create`.DateOpen AS `Date Open`, Priority.PName AS `Priority`, createUser.FullName AS `Initiator`, workUser.FullName AS `Appointed`, Categories.`C+SC` AS `Category` "
    "FROM Users AS workUser RIGHT JOIN (Categories INNER JOIN (`Status` INNER JOIN (Priority INNER JOIN (((Orders INNER JOIN (Users AS createUser INNER JOIN `Create` ON createUser.id = `Create`.WhoCreate) ON Orders.id = `Create`.id) INNER JOIN `Edit` ON Orders.id = `Edit`.id) INNER JOIN `Work` ON Orders.id = `Work`.id) ON Priority.id = Orders.Priory) ON `Status`.id = Orders.`Status`) ON Categories.id = Orders.Category) ON workUser.id = `Work`.WhoWork "
    "WHERE ( " + str_1 + " " + str_2 + " " + str_3 + str_4 + str_and + " " + str_1_1 + " " + str_2_1 + " " + str_3_1 + str_4_1 + " ) ORDER BY Orders.id DESC LIMIT " + Limit + " OFFSET " + offset + ";");

        qmodel->query().first();
        }
    }else if(queryMode == 2){

        countOrd->setQuery("Select Count(Users.id) From Users;");
        countOrd->query().first();


        if((cbVar_1 == 0 && btnVis == false) || (btnVis && (cbVar_1 == 0 || cbVar_1_1 == 0))) {
            str_2 = ""; str_2_1 = ""; str_3 = ""; str_3_1 = "";
            qmodel->setQuery("SELECT Users.`Login` AS `Profile name`, Users.FullName AS `Name`, Users.Email AS `e-mail`, Users.Phone AS `Phone`, Users.Phone_m AS `Mobile phone`, IF(users.`Active` = 1, 'Да', 'Нет') AS `Active`, Users.`Rights` AS `Rights` "
            "FROM Users "
            "ORDER BY Users.id ASC;");
            qmodel->query().first();
            countRows = qmodel->rowCount();

            qmodel->setQuery("SELECT Users.`Login` AS `Profile name`, Users.FullName AS `Name`, Users.Email AS `e-mail`, Users.Phone AS `Phone`, Users.Phone_m AS `Mobile phone`, IF(users.`Active` = 1, 'Да', 'Нет') AS `Active`, Users.`Rights` AS `Rights` "
            "FROM Users "
            "ORDER BY Users.id ASC LIMIT " + Limit + " OFFSET " + offset + ";");

            qmodel->query().first();            
        }else{
            str_1 = var1_1_u->at(cbVar_1);
            var_2 = cbVar_2;
            if(cbVar_1 < 12 ){
            if(cbVar_1 == 10 || cbVar_1 == 11){
                var_2 += 2;}
                str_2 = var1_2->at(var_2);
            }else if ((cbVar_1 > 11) && (cbVar_2 == 2 || cbVar_2 == 3)){
                var_2 = var_2 - 2;
                str_2 = var1_2->at(var_2);
            }else if((cbVar_1 > 11) && (cbVar_2 <2 || cbVar_2> 3)){
                str_2 = var1_2->at(var_2);
            }


            if(btnVis) {
                str_1_1 = "( " + var1_1_u->at(cbVar_1_1);
                var_2_2 = cbVar_2_1;
                if(cbVar_1_1 < 12){
                if(cbVar_1_1 == 10 || cbVar_1_1 == 11){
                    var_2_2 += 2;}
                    str_2_1 = var1_2->at(var_2_2);
                }else if ((cbVar_1_1 > 11) && (cbVar_2_1 == 2 || cbVar_2_1 == 3)){
                    var_2_2 = var_2_2 - 2;
                    str_2_1 = var1_2->at(var_2_2);
                }else if((cbVar_1_1 > 11) && (cbVar_2_1 <2 || cbVar_2_1> 3)){
                    str_2_1 = var1_2->at(var_2_2);
                }
            }
            qmodel->setQuery("SELECT Users.`Login` AS `Profile name`, Users.FullName AS `Name`, Users.Email AS `e-mail`, Users.Phone AS `Phone`, Users.Phone_m AS `Mobile phone`, IF(users.`Active` = 1, 'Да', 'Нет') AS `Active`, Users.`Rights` AS `Rights` "
            "FROM Users "
            "WHERE (" + str_1 + " " + str_2 + " " + str_3 + str_4 + str_and + " " + str_1_1 + " " + str_2_1 + " " + str_3_1 + str_4_1 + " ) ORDER BY Users.id ASC;");
            qmodel->query().first();
            countRows = qmodel->rowCount();

            qmodel->setQuery("SELECT Users.`Login` AS `Profile name`, Users.FullName AS `Name`, Users.Email AS `e-mail`, Users.Phone AS `Phone`, Users.Phone_m AS `Mobile phone`, IF(users.`Active` = 1, 'Да', 'Нет') AS `Active`, Users.`Rights` AS `Rights` "
            "FROM Users "
            "WHERE (" + str_1 + " " + str_2 + " " + str_3 + str_4 + str_and + " " + str_1_1 + " " + str_2_1 + " " + str_3_1 + str_4_1 + " ) ORDER BY Users.id ASC LIMIT " + Limit + " OFFSET " + offset + ";");

            qmodel->query().first();           
        }
/*
        qDebug() << "#####################";
        qDebug() << str_1;
        qDebug() << str_2;
        qDebug() << str_3;
        qDebug() << str_4;
        qDebug() << str_and;
        qDebug() << str_1_1;
        qDebug() << str_2_1;
        qDebug() << str_3_1;
        qDebug() << str_4_1;
        qDebug() << "#####################";
*/
    }


    if((countRows - (QVariant(Limit).toInt() * multiplier_s)) >= 0){
        lTo = countRows - (countRows - (QVariant(Limit).toInt() * multiplier_s));
    }else{
        lTo = countRows;
    }

    //lTo = ((countOrd->index(0,0).data().toInt() - lFrom) + lFrom);

    if(countRows < lFrom){
        multiplier_f = 1;
        ui->pushButton_search->click();
    }


    ui->label_pages->setText("c " + QVariant(lFrom).toString() + " по " + QVariant(lTo).toString() + " из " + QVariant(countRows).toString());

    //qDebug() << ui->comboBox_pages->currentText();
    //qDebug() << offset;

    ui->tableView->setColumnWidth(1, 400);
    ui->tableView->resizeRowsToContents();


    qmodel_c1->setQuery("SELECT "
"ABS(SUM(NOT Status.SName = 'Закрыто')) AS cOpened, "
"ABS(SUM(Status.SName = 'В работе (назначена)')) AS cInWork_N, "
"ABS(SUM(Status.SName = 'В работе (запланирована)')) AS cInWork_Z, "
"ABS(SUM(Status.SName = 'Новый')) AS cNew, "
"ABS(SUM(Status.SName = 'Решена')) AS cSolved, "
"ABS(SUM(Status.SName = 'Ожидающие')) AS cAwaits "
"FROM Status INNER JOIN Orders ON Status.id = Orders.Status;");

    qmodel_c1_1->setQuery("SELECT ABS(SUM(`Work`.DateDecision < '" + str + "' AND Orders.`Status` <> 'Закрыто')) FROM `Work` INNER JOIN (Orders INNER JOIN `Status` ON Orders.`Status` = `Status`.id) ON `Work`.id = Orders.id;");

    qmodel_c1->query().first();
    qmodel_c1_1->query().first();

    ui->PB_wOpened->setText(qmodel_c1->query().value(0).toString());
    ui->PB_wInWork->setText(QVariant(qmodel_c1->query().value(1).toInt() + qmodel_c1->query().value(2).toInt()).toString());
    ui->PB_wNew->setText(qmodel_c1->query().value(3).toString());
    ui->PB_wSolved->setText(qmodel_c1->query().value(4).toString());
    ui->PB_wAwaits->setText(qmodel_c1->query().value(5).toString());
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
    queryMode = 1;
    multiplier_f = 1;

    ui->tabWidget->setCurrentIndex(1);

    ui->comboBox_var_1->clear();
    ui->comboBox_var_1_1->clear();
    ui->comboBox_var_1->addItems(*var1);
    ui->comboBox_var_1_1->addItems(*var1);

    ui->pushButton_twsSearch_del->click();

    ui->comboBox_var_1->setCurrentIndex(3);
    ui->comboBox_var_2->setCurrentIndex(1);
    ui->comboBox_var_3->setCurrentIndex(5);

    ui->tableView->setColumnWidth(1, 400);

    ui->pushButton_search->click();
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//Клик на кнопку "Новые"
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_PB_wNew_clicked()
{
    queryMode = 1;
    multiplier_f = 1;

    ui->tabWidget->setCurrentIndex(1);

    ui->comboBox_var_1->clear();
    ui->comboBox_var_1_1->clear();
    ui->comboBox_var_1->addItems(*var1);
    ui->comboBox_var_1_1->addItems(*var1);

    ui->pushButton_twsSearch_del->click();

    ui->comboBox_var_1->setCurrentIndex(3);
    ui->comboBox_var_2->setCurrentIndex(0);
    ui->comboBox_var_3->setCurrentIndex(0);

    ui->tableView->setColumnWidth(1, 400);

    ui->pushButton_search->click();
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//Клик на кнопку "В работе"
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_PB_wInWork_clicked()
{
    queryMode = 1;
    multiplier_f = 1;

    ui->tabWidget->setCurrentIndex(1);

    ui->comboBox_var_1->clear();
    ui->comboBox_var_1_1->clear();
    ui->comboBox_var_1->addItems(*var1);
    ui->comboBox_var_1_1->addItems(*var1);

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
//--------------------------------------------------------------------------------------------------------------------------------------------


//Клик на кнопку "Решенные"
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_PB_wSolved_clicked()
{
    queryMode = 1;
    multiplier_f = 1;

    ui->tabWidget->setCurrentIndex(1);

    ui->comboBox_var_1->clear();
    ui->comboBox_var_1_1->clear();
    ui->comboBox_var_1->addItems(*var1);
    ui->comboBox_var_1_1->addItems(*var1);

    ui->pushButton_twsSearch_del->click();

    ui->comboBox_var_1->setCurrentIndex(3);
    ui->comboBox_var_2->setCurrentIndex(0);
    ui->comboBox_var_3->setCurrentIndex(4);

    ui->tableView->setColumnWidth(1, 400);

    ui->pushButton_search->click();
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//Клик на кнопку "Ожидающие"
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_PB_wAwaits_clicked()
{
    queryMode = 1;
    multiplier_f = 1;

    ui->tabWidget->setCurrentIndex(1);

    ui->comboBox_var_1->clear();
    ui->comboBox_var_1_1->clear();
    ui->comboBox_var_1->addItems(*var1);
    ui->comboBox_var_1_1->addItems(*var1);

    ui->pushButton_twsSearch_del->click();

    ui->comboBox_var_1->setCurrentIndex(3);
    ui->comboBox_var_2->setCurrentIndex(0);
    ui->comboBox_var_3->setCurrentIndex(3);

    ui->tableView->setColumnWidth(1, 400);

    ui->pushButton_search->click();
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//Клик на кнопку "Просроченые"
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_PB_wOverdue_clicked()
{
    queryMode = 1;
    multiplier_f = 1;

    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y.%m.%d", &tstruct);
    QString str(buf);

    ui->tabWidget->setCurrentIndex(1);

    ui->comboBox_var_1->clear();
    ui->comboBox_var_1_1->clear();
    ui->comboBox_var_1->addItems(*var1);
    ui->comboBox_var_1_1->addItems(*var1);

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
//--------------------------------------------------------------------------------------------------------------------------------------------


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

    //qDebug() << index;
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

void MainWindow::FocusDateVF()
{
    ui->lineEdit_u_validF->setText(calendarVF->selectedDate().toString(QString("yyyy.MM.dd")) + " 00:00:00");
}

void MainWindow::FocusDateVU()
{
    ui->lineEdit_u_validU->setText(calendarVU->selectedDate().toString(QString("yyyy.MM.dd")) + " 23:59:59");
}

void MainWindow::FocusDateSBD()
{
    ui->lineEdit_set_beg_date_work->setText(calendarSBD->selectedDate().toString(QString("yyyy.MM.dd")) + " 12:00:00");
}

void MainWindow::FocusDateSFD()
{
    ui->lineEdit_set_fin_date_work->setText(calendarSFD->selectedDate().toString(QString("yyyy.MM.dd")) + " 12:00:00");
}

void MainWindow::FocusDateDecision()
{
    ui->lineEdit_set_date_decision->setText(calendarDecision->selectedDate().toString(QString("yyyy.MM.dd")) + " 23:59:59");
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


            creOrd.prepare("INSERT INTO Orders (id, `Category`, `Priory`, `Status`, `Title`, `Description`, RequestSource, `Type`, Agreement) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
            creOrd.addBindValue(1 + qmodel_id->query().value(0).toInt());
            creOrd.addBindValue(ui->comboBox_6->currentIndex());
            creOrd.addBindValue(1 + ui->comboBox_9->currentIndex());
            creOrd.addBindValue(ui->comboBox_7->currentIndex());
            creOrd.addBindValue(ui->lineEdit_6->text());
            creOrd.addBindValue(ui->textEdit->toPlainText());
            creOrd.addBindValue(ui->comboBox_8->currentIndex());
            creOrd.addBindValue(1 + ui->comboBox_5->currentIndex());
            creOrd.addBindValue(1 + ui->comboBox_ord_agree->currentIndex());
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


//Переход в окно создания новой заявки
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
    qmodel_agree->setQuery("SELECT AName FROM Agreement");
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
//--------------------------------------------------------------------------------------------------------------------------------------------


//Переход на конкретную заявку / пользователя
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::twiceClickOnTableRow(const QModelIndex &index)
{
    if(queryMode == 1){
    for (int i = 0; i < 6; i++)
    {
        lableList.at(i)->setStyleSheet("background-color: rgb(181, 181, 181);");
    }    

    id = qmodel->index(index.row(), 0).data().toString();

    //___________________________________________________________________________
    reprintActs();
    //___________________________________________________________________________


    qmodel_ordId->setQuery("SELECT Orders.id, Orders.Title, Orders.`Status`, `Edit`.DateEdit, `Create`.DateOpen, `Work`.DateClose, `Create`.WhoCreate, `Edit`.WhoEdit, `Work`.WhoWork, Orders.Priory, Orders.Category, Orders.RequestSource, Orders.`Description`, Orders.`Type`, `Work`.DateDecision, `Control`.WhoControlling, editUser.FullName, Orders.Agreement "
"FROM (((Orders INNER JOIN `Control` ON Orders.id = `Control`.id) INNER JOIN `Create` ON Orders.id = `Create`.id) INNER JOIN (Users AS editUser INNER JOIN `Edit` ON editUser.id = `Edit`.WhoEdit) ON Orders.id = `Edit`.id) INNER JOIN `Work` ON Orders.id = `Work`.id WHERE Orders.id = " + id);
    qmodel_ordId->query().first();

    qmodel_categ->setQuery("SELECT NULL FROM `Categories` UNION SELECT `C+SC` FROM `Categories`");
    qmodel_categ->setQuery("SELECT `C+SC`, id FROM `Categories` ORDER BY id");
    qmodel_stat->setQuery("SELECT NULL FROM `Status` UNION SELECT SName FROM `Status`");
    qmodel_reqS->setQuery("SELECT NULL FROM RequestSource UNION SELECT RName FROM RequestSource");
    qmodel_agree->setQuery("SELECT AName FROM Agreement");
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
    ui->comboBox_ord_agree->setCurrentIndex(qmodel_ordId->index(0, 17).data().toInt() - 1);
    ui->comboBox_9->setCurrentIndex(qmodel_ordId->index(0, 9).data().toInt() - 1);
    ui->comboBox_10->setCurrentIndex(qmodel_ordId->index(0, 6).data().toInt());
    ui->comboBox_11->setCurrentIndex(qmodel_ordId->index(0, 15).data().toInt());
    ui->comboBox_12->setCurrentIndex(qmodel_ordId->index(0, 8).data().toInt());
    ui->lineEdit_6->setText(qmodel_ordId->index(0, 1).data().toString());
    ui->textEdit->setText(qmodel_ordId->index(0, 12).data().toString());

    emit fillReportSig(QVariant(id).toInt());
    }else if(queryMode == 2){
        qmodel_ordId->setQuery("SELECT Users.FullName, Users.`Name`, Users.SecName, Users.`Login`, Users.`Password`, Users.`Rights`, Users.`Function`, Users.`Active`, Users.Valid_from, Users.Valid_until, Users.Email, Users.Phone,"
        "Users.Phone_m, Users.Phone2, Users.Phone2_m, Users.`Description`, Users.`id` "
        "FROM Users WHERE Users.FullName = '" + qmodel->index(index.row(), 1).data().toString() + "';");
        qmodel_ordId->query().first();

        qmodel_u_func->setQuery("SELECT NULL FROM `Functions` UNION SELECT FName From `Functions`");
        qmodel_u_rules->setQuery("SELECT NULL FROM `Rights` UNION SELECT Name From `Rights`");

        ui->tabWidget->setCurrentIndex(4);
        ui->tabWidget_3->setCurrentIndex(0);

        ui->label_u_pass_valid->hide();
        ui->lineEdit_u_pass_valid->hide();
        ui->pushButton_u_add->hide();
        ui->pushButton_u_save->show();
        ui->pushButton_u_del->show();

        ui->label_Users->setText("<html><head/><body><p><span style=' font-size:12pt; font-weight:600;'>Профиль пользователя: " + qmodel->index(index.row(), 0).data().toString() + " (" + qmodel->index(index.row(), 1).data().toString() + ")</span></p></body></html>");
        ui->lineEdit_u_login->setText(qmodel_ordId->index(0, 3).data().toString());
        ui->lineEdit_u_name->setText(qmodel_ordId->index(0, 1).data().toString());
        ui->lineEdit_u_secName->setText(qmodel_ordId->index(0, 2).data().toString());
        ui->lineEdit_u_password->setText(qmodel_ordId->index(0, 4).data().toString());
        ui->comboBox_u_active->setCurrentIndex(qmodel_ordId->index(0, 7).data().toInt());
        ui->lineEdit_u_email->setText(qmodel_ordId->index(0, 10).data().toString());
        ui->lineEdit_u_validF->setText(QDateTime::fromString(qmodel_ordId->index(0, 8).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
        ui->lineEdit_u_validU->setText(QDateTime::fromString(qmodel_ordId->index(0, 9).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
        ui->lineEdit_u_phone->setText(qmodel_ordId->index(0, 11).data().toString());
        ui->lineEdit_u_phone_m->setText(qmodel_ordId->index(0, 12).data().toString());
        ui->lineEdit_u_phone2->setText(qmodel_ordId->index(0, 13).data().toString());
        ui->lineEdit_u_phone2_m->setText(qmodel_ordId->index(0, 14).data().toString());
        ui->textEdit_u_description->setPlainText(qmodel_ordId->index(0, 15).data().toString());
        ui->comboBox_u_func->setCurrentIndex(qmodel_ordId->index(0, 6).data().toInt());
        ui->comboBox_u_rules->setCurrentText(qmodel_ordId->index(0, 5).data().toString());


    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//Редактирование заявки
//--------------------------------------------------------------------------------------------------------------------------------------------
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

            updOrd.prepare("UPDATE Orders SET `Category`=:1, `Priory`=:2, `Status`=:3, `Title`=:4, `Description`=:5, RequestSource=:6, `Type`=:7, Agreement=:8 WHERE Orders.id = " + id);
            updOrd.bindValue(":1", ui->comboBox_6->currentIndex());
            updOrd.bindValue(":2", ui->comboBox_9->currentIndex() + 1);
            updOrd.bindValue(":3", ui->comboBox_7->currentIndex());
            updOrd.bindValue(":4", ui->lineEdit_6->text());
            updOrd.bindValue(":5", ui->textEdit->toPlainText());
            updOrd.bindValue(":6", ui->comboBox_8->currentIndex());
            updOrd.bindValue(":7", ui->comboBox_5->currentIndex() + 1);
            updOrd.bindValue(":8", ui->comboBox_ord_agree->currentIndex() + 1);
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

            reprintActs();
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
//--------------------------------------------------------------------------------------------------------------------------------------------


//Обновление полей после редактирования заявки
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::updEditOrd()
{    
    qmodel_ordId->setQuery("SELECT Orders.id, Orders.Title, Orders.`Status`, `Edit`.DateEdit, `Create`.DateOpen, `Work`.DateClose, `Create`.WhoCreate, `Edit`.WhoEdit, `Work`.WhoWork, Orders.Priory, Orders.Category, Orders.RequestSource, Orders.`Description`, Orders.`Type`, `Work`.DateDecision, `Control`.WhoControlling, editUser.FullName, Orders.Agreement "
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
    ui->comboBox_ord_agree->setCurrentIndex(qmodel_ordId->index(0, 17).data().toInt() - 1);
    ui->comboBox_9->setCurrentIndex(qmodel_ordId->index(0, 9).data().toInt() - 1);
    ui->comboBox_10->setCurrentIndex(qmodel_ordId->index(0, 6).data().toInt());
    ui->comboBox_11->setCurrentIndex(qmodel_ordId->index(0, 15).data().toInt());
    ui->comboBox_12->setCurrentIndex(qmodel_ordId->index(0, 8).data().toInt());
    ui->lineEdit_6->setText(qmodel_ordId->index(0, 1).data().toString());
    ui->textEdit->setText(qmodel_ordId->index(0, 12).data().toString());

    saveTmr->stop();
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//Удаление заявки
//--------------------------------------------------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------------------------------------------------


//Добавление второй линии запроса
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_twsSearch_add_clicked()
{
    ui->pushButton_twsSearch_add->hide();
    ui->groupBox_2->setMinimumHeight(110);
    ui->pushButton_twsSearch_del->show();
    ui->comboBox_var_0_0->show();
    ui->comboBox_var_1_1->show();
    ui->comboBox_var_1_1->setCurrentIndex(0);
    ui->comboBox_var_2_2->show();
    ui->comboBox_var_3_3->show();

    ui->comboBox_pages->setGeometry(50, 80, 71, 22);
    ui->pushButton_toFirst->setGeometry(130, 80, 22, 22);
    ui->pushButton_back->setGeometry(160, 80, 22, 22);
    ui->label_pages->setGeometry(190, 80, 100, 22);
    ui->pushButton_next->setGeometry(300, 80, 22, 22);
    ui->pushButton_toLast->setGeometry(330, 80, 22, 22);

    ui->pushButton_search->setGeometry(920, 50, 70, 22);
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//Скрытие второй линии запроса
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_twsSearch_del_clicked()
{
    ui->pushButton_twsSearch_add->show();
    ui->groupBox_2->setMinimumHeight(80);
    ui->pushButton_twsSearch_del->hide();
    ui->comboBox_var_0_0->hide();
    ui->comboBox_var_1_1->hide();
    ui->comboBox_var_1_1->setCurrentIndex(0);
    ui->comboBox_var_2_2->hide();
    ui->lineEdit_find_2->hide();
    ui->comboBox_var_3_3->hide();

    ui->comboBox_pages->setGeometry(50, 50, 71, 22);
    ui->pushButton_toFirst->setGeometry(130, 50, 22, 22);
    ui->pushButton_back->setGeometry(160, 50, 22, 22);
    ui->label_pages->setGeometry(190, 50, 100, 22);
    ui->pushButton_next->setGeometry(300, 50, 22, 22);
    ui->pushButton_toLast->setGeometry(330, 50, 22, 22);

    ui->pushButton_search->setGeometry(920, 20, 70, 22);
}
//--------------------------------------------------------------------------------------------------------------------------------------------


//LogOut / перезапуск
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_4_clicked()
{
    tmr->stop();

    db.close();
    db.removeDatabase("QODBC");

    emit reload();
}
//--------------------------------------------------------------------------------------------------------------------------------------------

void MainWindow::on_action_u_create_triggered()
{
    ui->tabWidget->setCurrentIndex(4);
    ui->tabWidget_3->setCurrentIndex(0);

    ui->pushButton_u_save->hide();
    ui->pushButton_u_del->hide();

    ui->pushButton_u_add->show();
    ui->label_u_pass_valid->show();
    ui->lineEdit_u_pass_valid->show();


    ui->label_Users->setText("<html><head/><body><p><span style=' font-size:12pt; font-weight:600;'>Формирование профиля пользователя</span></p></body></html>");

    qmodel_u_func->setQuery("SELECT NULL FROM `Functions` UNION SELECT FName From `Functions`");
    qmodel_u_rules->setQuery("SELECT NULL FROM `Rights` UNION SELECT Name From `Rights`");

    for (int i = 0; i< 6; i++) {
        leList2.at(i)->clear();}
    ui->lineEdit_u_phone2->clear();
    ui->lineEdit_u_phone2_m->clear();
    ui->lineEdit_u_phone_m->clear();
    ui->lineEdit_u_validF->clear();
    ui->lineEdit_u_validU->clear();
    ui->lineEdit_u_email->clear();
    ui->textEdit_u_description->clear();
    ui->comboBox_u_active->setCurrentIndex(0);
}

void MainWindow::on_pushButton_u_add_clicked()
{
    //qDebug() << leList2.at(0)->text();

    if(ui->lineEdit_u_login->text() != "" && ui->lineEdit_u_name->text() != "" && ui->lineEdit_u_secName->text() != "" && ui->lineEdit_u_password->text() != "" &&
       ui->lineEdit_u_pass_valid->text() != "" && ui->lineEdit_u_phone->text().length() == 18){
        if(ui->lineEdit_u_password->text() == ui->lineEdit_u_pass_valid->text()){
            QMessageBox::StandardButton create;
            create = QMessageBox::question(this, "Внесение пользователя", "Вы действительно хотите внести нового пользователя в систему?", QMessageBox::Yes|QMessageBox::No);

            if(create == QMessageBox::Yes)
            {
                qmodel_id->setQuery("Select max(Users.id) "
                "From Users");
                qmodel_id->query().first();

                QSqlQuery creUsr(db);


                creUsr.prepare("INSERT INTO Users (id, `Name`, SecName, `Login`, `Password`, `Rights`, `Function`, `Active`, Valid_from, Valid_until, Email, "
                               "Phone, Phone_m, Phone2, Phone2_m, `Description`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
                creUsr.addBindValue(1 + qmodel_id->query().value(0).toInt());
                creUsr.addBindValue(ui->lineEdit_u_name->text());
                creUsr.addBindValue(ui->lineEdit_u_secName->text());
                creUsr.addBindValue(ui->lineEdit_u_login->text());
                creUsr.addBindValue(ui->lineEdit_u_password->text());
                if(ui->comboBox_u_rules->currentIndex() == 0){
                    creUsr.addBindValue(QVariant(QVariant::Int));
                }else{
                    creUsr.addBindValue(ui->comboBox_u_rules->currentText());
                }
                if(ui->comboBox_u_func->currentIndex() == 0){
                    creUsr.addBindValue(QVariant(QVariant::Int));
                }else{
                    creUsr.addBindValue(ui->comboBox_u_func->currentIndex());
                }
                creUsr.addBindValue(ui->comboBox_u_active->currentIndex());
                if(ui->lineEdit_u_validF->text() == ""){
                    creUsr.addBindValue(QVariant(QVariant::DateTime));
                }else{
                    creUsr.addBindValue(QDateTime::fromString(ui->lineEdit_u_validF->text(), "yyyy.MM.dd hh:mm:ss").toString("yyyy-MM-dd hh:mm:ss"));
                }
                if(ui->lineEdit_u_validU->text() == ""){
                    creUsr.addBindValue(QVariant(QVariant::DateTime));
                }else{
                    creUsr.addBindValue(QDateTime::fromString(ui->lineEdit_u_validU->text(), "yyyy.MM.dd hh:mm:ss").toString("yyyy-MM-dd hh:mm:ss"));
                }
                creUsr.addBindValue(ui->lineEdit_u_email->text());
                if(ui->lineEdit_u_phone->text().length() != 18){
                    creUsr.addBindValue(QVariant(QVariant::Int));
                }else{
                    creUsr.addBindValue(ui->lineEdit_u_phone->text());
                }
                if(ui->lineEdit_u_phone_m->text().length() != 18){
                    creUsr.addBindValue(QVariant(QVariant::Int));
                }else{
                    creUsr.addBindValue(ui->lineEdit_u_phone_m->text());
                }
                if(ui->lineEdit_u_phone2->text().length() != 18){
                    creUsr.addBindValue(QVariant(QVariant::Int));
                }else{
                    creUsr.addBindValue(ui->lineEdit_u_phone2->text());
                }
                if(ui->lineEdit_u_phone2_m->text().length() != 18){
                    creUsr.addBindValue(QVariant(QVariant::Int));
                }else{
                    creUsr.addBindValue(ui->lineEdit_u_phone2_m->text());
                }
                if(ui->textEdit_u_description->toPlainText() == ""){
                    creUsr.addBindValue(QVariant(QVariant::Int));
                }else{
                    creUsr.addBindValue(ui->textEdit_u_description->toPlainText());
                }
                creUsr.exec();

                emit ui->action_users->triggered();
            }
        }else
        {
            QMessageBox::critical(this, "Внесение пользователя", "Поля \"Пароль\" и \"Подтверждение пароля\" не совпадают!\n\nПожалуйста, проверь введенные данные.)");
        }
    }else
    {
        QMessageBox::critical(this, "Внесение пользователя", "Одно или несколько обязательных полей пусты!\n\nПожалуйста, проверь введенные данные.)");
    }

    for (int i = 0; i< 5; i++) {
        if(leList2.at(i)->text() == "") {
            lableList2.at(i)->setStyleSheet("background-color: rgb(181, 181, 181); border: 2px solid red;");
        }else{
            lableList2.at(i)->setStyleSheet("background-color: rgb(181, 181, 181);");}}

    if(leList2.at(5)->text().length() < 18) {
            lableList2.at(5)->setStyleSheet("background-color: rgb(181, 181, 181); border: 2px solid red;");
        }else {
            lableList2.at(5)->setStyleSheet("background-color: rgb(181, 181, 181);");}

    if(leList2.at(3)->text() != leList2.at(4)->text()) {
        for (int i = 3; i< 5; i++) {
            lableList2.at(i)->setStyleSheet("background-color: rgb(181, 181, 181); border: 2px solid red;");
        }
    }
}

void MainWindow::on_action_users_triggered()
{
    queryMode = 2;
    multiplier_f = 1;

    ui->comboBox_var_1->clear();
    ui->comboBox_var_1_1->clear();
    ui->comboBox_var_1->addItems(*var1_u);
    ui->comboBox_var_1_1->addItems(*var1_u);

    ui->pushButton_twsSearch_del->click();
    ui->comboBox_var_1->setCurrentIndex(0);

    ui->tabWidget->setCurrentIndex(1);

    ui->tableView->setColumnWidth(0, 150);
    ui->tableView->setColumnWidth(1, 150);
    ui->tableView->setColumnWidth(2, 150);
    ui->tableView->setColumnWidth(3, 150);
    ui->tableView->setColumnWidth(4, 150);
    ui->tableView->resizeRowsToContents();


    for (int i = 0; i< 6; i++) {
        lableList2.at(i)->setStyleSheet("background-color: rgb(181, 181, 181);");}

    ui->pushButton_search->click();
}

void MainWindow::on_pushButton_5_clicked()
{
    qmodel_ordId->setQuery("SELECT Users.FullName, Users.`Name`, Users.SecName, Users.`Login`, Users.`Password`, Users.`Rights`, Users.`Function`, Users.`Active`, Users.Valid_from, Users.Valid_until, Users.Email, Users.Phone,"
    "Users.Phone_m, Users.Phone2, Users.Phone2_m, Users.`Description`, Users.`id` "
    "FROM Users WHERE Users.id = '" + QVariant(curUser).toString() + "';");
    qmodel_ordId->query().first();

    qmodel_u_func->setQuery("SELECT NULL FROM `Functions` UNION SELECT FName From `Functions`");
    qmodel_u_rules->setQuery("SELECT NULL FROM `Rights` UNION SELECT Name From `Rights`");

    ui->tabWidget->setCurrentIndex(4);
    ui->tabWidget_3->setCurrentIndex(0);

    ui->label_u_pass_valid->hide();
    ui->lineEdit_u_pass_valid->hide();
    ui->pushButton_u_add->hide();

    ui->label_Users->setText("<html><head/><body><p><span style=' font-size:12pt; font-weight:600;'>Профиль пользователя: " + qmodel_ordId->index(0, 0).data().toString() + " (" + qmodel_ordId->index(0, 5).data().toString() + ")</span></p></body></html>");
    ui->lineEdit_u_login->setText(qmodel_ordId->index(0, 3).data().toString());
    ui->lineEdit_u_name->setText(qmodel_ordId->index(0, 1).data().toString());
    ui->lineEdit_u_secName->setText(qmodel_ordId->index(0, 2).data().toString());
    ui->lineEdit_u_password->setText(qmodel_ordId->index(0, 4).data().toString());
    ui->comboBox_u_active->setCurrentIndex(qmodel_ordId->index(0, 7).data().toInt());
    ui->lineEdit_u_email->setText(qmodel_ordId->index(0, 10).data().toString());
    ui->lineEdit_u_validF->setText(QDateTime::fromString(qmodel_ordId->index(0, 8).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
    ui->lineEdit_u_validU->setText(QDateTime::fromString(qmodel_ordId->index(0, 9).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
    ui->lineEdit_u_phone->setText(qmodel_ordId->index(0, 11).data().toString());
    ui->lineEdit_u_phone_m->setText(qmodel_ordId->index(0, 12).data().toString());
    ui->lineEdit_u_phone2->setText(qmodel_ordId->index(0, 13).data().toString());
    ui->lineEdit_u_phone2_m->setText(qmodel_ordId->index(0, 14).data().toString());
    ui->textEdit_u_description->setPlainText(qmodel_ordId->index(0, 15).data().toString());
    ui->comboBox_u_func->setCurrentIndex(qmodel_ordId->index(0, 6).data().toInt());
    ui->comboBox_u_rules->setCurrentText(qmodel_ordId->index(0, 5).data().toString());
}

void MainWindow::on_pushButton_u_del_clicked()
{
    QMessageBox::StandardButton del;
    del = QMessageBox::question(this, "Удаление пользователя", "Внимание!!!\n\nДанные пользователя  " + qmodel_ordId->index(0,0).data().toString() + "  будут удалены безвозвратно!\n\nВы действительно хотите удалить пользователя?", QMessageBox::Yes|QMessageBox::No);

    if(del == QMessageBox::Yes)
    {
        QSqlQuery delOrd(db);

        //qDebug() << qmodel_ordId->index(0,16).data().toString();

        delOrd.exec("DELETE FROM Users WHERE id = " + qmodel_ordId->index(0,16).data().toString());

        tmr->start(1);
        emit ui->action_users->triggered();
    }
}

void MainWindow::on_pushButton_u_save_clicked()
{
    if(ui->lineEdit_u_login->text() != "" && ui->lineEdit_u_name->text() != "" && ui->lineEdit_u_secName->text() != "" && ui->lineEdit_u_password->text() != "" &&
       ui->lineEdit_u_pass_valid->text() != "" && ui->lineEdit_u_phone->text().length() == 18){

        QMessageBox::StandardButton create;
        create = QMessageBox::question(this, "Редактирование пользователя", "Вы действительно хотите внести изменения в профиль пользователя?", QMessageBox::Yes|QMessageBox::No);

        if(create == QMessageBox::Yes)
        {
            QSqlQuery updUsr(db);

            updUsr.prepare("UPDATE Users SET `Name`=:1, `SecName`=:2, `Login`=:3, `Password`=:4, `Rights`=:5, `Function`=:6 , `Active`=:7, `Valid_from`=:8, `Valid_until`=:9, "
                           "`Email`=:10, `Phone`=:11, `Phone_m`=:12, `Phone2`=:13, `Phone2_m`=:14, `Description`=:15 WHERE Users.`id` = " + qmodel_ordId->index(0, 16).data().toString() + ";");
            updUsr.bindValue(":1", ui->lineEdit_u_name->text());
            updUsr.bindValue(":2", ui->lineEdit_u_secName->text());
            updUsr.bindValue(":3", ui->lineEdit_u_login->text());
            updUsr.bindValue(":4", ui->lineEdit_u_password->text());
            if(ui->comboBox_u_rules->currentIndex() == 0)
            {
                updUsr.bindValue(":5", QVariant(QVariant::Int));
            }else{
                updUsr.bindValue(":5", ui->comboBox_u_rules->currentText());
            }
            if(ui->comboBox_u_func->currentIndex() == 0)
            {
                updUsr.bindValue(":6", QVariant(QVariant::Int));
            }else{
                updUsr.bindValue(":6", ui->comboBox_u_func->currentIndex());
            }
            updUsr.bindValue(":7", ui->comboBox_u_active->currentIndex());
            if(ui->lineEdit_u_validF->text() == ""){
                updUsr.bindValue(":8", QVariant(QVariant::DateTime));
            }else{
                updUsr.bindValue(":8",QDateTime::fromString(ui->lineEdit_u_validF->text(), "yyyy.MM.dd hh:mm:ss").toString("yyyy-MM-dd hh:mm:ss"));
            }
            if(ui->lineEdit_u_validU->text() == ""){
                updUsr.bindValue(":9", QVariant(QVariant::DateTime));
            }else{
                updUsr.bindValue(":9",QDateTime::fromString(ui->lineEdit_u_validU->text(), "yyyy.MM.dd hh:mm:ss").toString("yyyy-MM-dd hh:mm:ss"));
            }
            if(ui->lineEdit_u_email->text() == ""){
                updUsr.bindValue(":10", QVariant(QVariant::Int));
            }else{
                updUsr.bindValue(":10", ui->lineEdit_u_email->text());
            }
            updUsr.bindValue(":11", ui->lineEdit_u_phone->text());
            if(ui->lineEdit_u_phone_m->text() == ""){
                updUsr.bindValue(":12", QVariant(QVariant::Int));
            }else{
                updUsr.bindValue(":12", ui->lineEdit_u_phone_m->text());
            }
            if(ui->lineEdit_u_phone2->text() == ""){
                updUsr.bindValue(":13", QVariant(QVariant::Int));
            }else{
                updUsr.bindValue(":13", ui->lineEdit_u_phone2->text());
            }
            if(ui->lineEdit_u_phone2_m->text() == ""){
                updUsr.bindValue(":14", QVariant(QVariant::Int));
            }else{
                updUsr.bindValue(":14", ui->lineEdit_u_phone2_m->text());
            }
            if(ui->textEdit_u_description->toPlainText() == ""){
                updUsr.bindValue(":15", QVariant(QVariant::Int));
            }else{
                updUsr.bindValue(":15", ui->textEdit_u_description->toPlainText());
            }
            updUsr.exec();
        }

    }else{
        QMessageBox::critical(this, "Редактирование пользователя", "Одно или несколько обязательных полей пусты!\n\nПожалуйста, проверь введенные данные.)");
    }

    for (int i = 0; i< 5; i++) {
        if(leList2.at(i)->text() == "") {
            lableList2.at(i)->setStyleSheet("background-color: rgb(181, 181, 181); border: 2px solid red;");
        }else{
            lableList2.at(i)->setStyleSheet("background-color: rgb(181, 181, 181);");}}

    if(leList2.at(5)->text().length() < 18) {
            lableList2.at(5)->setStyleSheet("background-color: rgb(181, 181, 181); border: 2px solid red;");
        }else {
            lableList2.at(5)->setStyleSheet("background-color: rgb(181, 181, 181);");}
}

void MainWindow::countPagesChanges()
{
    multiplier_f = 1;

    Limit_bef = ui->comboBox_pages->currentText();
}

void MainWindow::on_pushButton_next_clicked()
{
    if(countRows - (QVariant(ui->comboBox_pages->currentText()).toInt() * multiplier_s) > 0){
        multiplier_f++;
    }

    ui->pushButton_search->click();
}

void MainWindow::on_pushButton_back_clicked()
{
    if(multiplier_f != 1){
        multiplier_f--;
    }

    ui->pushButton_search->click();
}

void MainWindow::on_pushButton_toLast_clicked()
{
    while (countRows - (QVariant(ui->comboBox_pages->currentText()).toInt() * multiplier_f) > 0) {
        multiplier_f++;
    }

    ui->pushButton_search->click();
}

void MainWindow::on_pushButton_toFirst_clicked()
{
    multiplier_f = 1;

    ui->pushButton_search->click();
}


void MainWindow::delAct_clicked(int pos)
{
    Node_act *curr = head;
    //qDebug() << head->numberPos;


    QMessageBox::StandardButton del;
    del = QMessageBox::question(this, "Удаление действия", "Внимание!!!\n\nДействие по заявке будет удалено безвозвратно!\n\nВы действительно хотите удалить действие?", QMessageBox::Yes|QMessageBox::No);

    if(del == QMessageBox::Yes)
    {
        for (int i = 0; i < (tail->numberPos); i++) {
            if(curr->numberPos == pos){
                //qDebug() << "Сработало " + QVariant(curr->numberPos).toString();
                //qDebug() << "#" + QVariant(i).toString() + " номер позиции " + QVariant(curr->numberPos).toString() + " / полученный " +  QVariant(pos).toString();

                QSqlQuery delAct(db);

                delAct.exec("DELETE FROM Actions WHERE act_pos = " + QVariant(pos).toString());
            }
            curr = curr->next;
        }
        reprintActs();
    }
}


void MainWindow::reprintActs()
{
    QSqlQuery query_act;
    query_act = QSqlQuery(db);

    query_act.exec("SELECT Actions.id, Actions.id_ord, Actions.id_creator, Actions.id_editor, Actions.date_create, Actions.act_type, Actions.act_pos, Actions.right_or_left "
    "From Actions INNER JOIN Orders ON Actions.id_ord = Orders.id "
    "WHERE Actions.id_ord = " + id + ";");

    bool fst = false;

    while(QLayoutItem *item = ui->Layout_actions->itemAt(0))
    {
        ui->Layout_actions->removeItem( item );
        ui->Layout_actions->removeWidget(item->widget());
        delete item->widget();
        delete item;
        ui->Layout_actions->update();
    }

    if(head != NULL){
        Node_act *cur = head;
        while(cur->next != NULL){
            //disconnect(this, SIGNAL(mainWinP(QMainWindow *)), cur->Wg, SLOT(mainWinP(QMainWindow *)));
            cur = cur->next;
            delete cur->prev;
        }
        //disconnect(this, SIGNAL(mainWinP(QMainWindow *)), cur->Wg, SLOT(mainWinP(QMainWindow *)));
        delete cur;
        cur = nullptr;
        head = NULL; tail = NULL;

        fst = false;
    }


    while (query_act.next()) {
        actNode = new Node_act();

        QSqlQuery updActPos(db);

        if(!fst)
        {
            actLeft = new Actions_left();
            actLeft->Type_Action(query_act.value(5).toInt());

            actNode->Wg = actLeft;
            actNode->next = NULL;
            actNode->prev = NULL;
            actNode->numberPos = 1;

            //emit actLeftPos(actNode->numberPos - 1);
            //actNode->Wg->setPosNumber(actNode->numberPos - 1);
            actLeft->setPosNumber(actNode->numberPos - 1);

            tail = actNode; head = actNode;

            autoFillActs(query_act.value(0).toString());

            ui->Layout_actions->insertWidget(0, actNode->Wg);

            fst = true;
        }else{
            if(query_act.value(7) == "L"){
                actLeft = new Actions_left();
                actLeft->Type_Action(query_act.value(5).toInt());
                actNode->Wg = actLeft;
                actNode->prev = tail;
                tail->next = actNode;
                tail = actNode;
                actNode->numberPos = actNode->prev->numberPos + 1;

                autoFillActs(query_act.value(0).toString());

                actLeft->setPosNumber(actNode->numberPos - 1);
            }else{
                actRight = new Actions_right();
                actRight->Type_Action(query_act.value(5).toInt());
                actNode->Wg = actRight;
                actNode->prev = tail;
                tail->next = actNode;
                tail = actNode;
                actNode->numberPos = actNode->prev->numberPos + 1;

                autoFillActs(query_act.value(0).toString());

                actRight->setPosNumber(actNode->numberPos - 1);
            }

            updActPos.exec("UPDATE Actions SET `act_pos`= " + QVariant(actNode->numberPos - 1).toString() +" WHERE Actions.`id_ord` = " + id + " AND Actions.act_pos = " + query_act.value(6).toString());

            ui->Layout_actions->insertWidget(0, actNode->Wg);

        }

        connect(this, SIGNAL(mainWinP(QMainWindow *)), actNode->Wg, SLOT(mainWinP(QMainWindow *)));

        emit mainWinP(this);

        //qDebug() << ui->scrollArea_actions->co
        //ui->scrollArea_actions->update();

    }
}

void MainWindow::autoFillActs(QString actID)
{
    QSqlQuery query_act;
    query_act = QSqlQuery(db);

    query_act.exec("SELECT Actions.id, Actions.id_ord, Actions.id_creator, Actions.id_editor, Actions.date_create, Actions.act_type, Actions.act_pos, Actions.right_or_left, Actions.`text`, Actions.`check`, Actions.date_beg, Actions.date_fin, Actions.date_agree "
    "From Actions INNER JOIN Orders ON Actions.id_ord = Orders.id "
    "WHERE Actions.id = " + actID + ";");
    query_act.first();

    qmodel_ordId->setQuery("SELECT Orders.id, Orders.Title, Orders.`Status`, `Edit`.DateEdit, `Create`.DateOpen, `Work`.DateClose, `Create`.WhoCreate, `Edit`.WhoEdit, `Work`.WhoWork, Orders.Priory, Orders.Category, Orders.RequestSource, Orders.`Description`, Orders.`Type`, `Work`.DateDecision, `Control`.WhoControlling, editUser.FullName, Orders.Agreement "
    "FROM (((Orders INNER JOIN `Control` ON Orders.id = `Control`.id) INNER JOIN `Create` ON Orders.id = `Create`.id) INNER JOIN (Users AS editUser INNER JOIN `Edit` ON editUser.id = `Edit`.WhoEdit) ON Orders.id = `Edit`.id) INNER JOIN `Work` ON Orders.id = `Work`.id WHERE Orders.id = " + id);
    qmodel_ordId->query().first();

    qmodel_usrNames->setQuery("SELECT createUser.FullName, workUser.FullName, conUser.FullName "
    "FROM (((Orders INNER JOIN (Users AS createUser INNER JOIN `Create` ON createUser.id = `Create`.WhoCreate) ON Orders.id = `Create`.id) "
    "LEFT JOIN (Users AS workUser INNER JOIN `Work` ON workUser.id = `Work`.WhoWork) ON Orders.id = `Work`.id) "
    "LEFT JOIN (Users AS conUser INNER JOIN `Control` ON conUser.id = `Control`.WhoControlling) ON Orders.id = `Control`.id) "
    "WHERE Orders.id =" + id);
    qmodel_usrNames->query().first();

    //qDebug() << qmodel_ordId->query().value(0).toString();


    QSqlQuery selUsrs(db);



    switch (query_act.value(5).toInt())
    {
    case 1:
        if(query_act.value(7).toString() == "L"){
            actLeft->setUserName(qmodel_usrNames->query().value(0).toString());
            actLeft->setUserDate(QDateTime::fromString(query_act.value(4).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
            actLeft->setTickedID(QVariant(id).toInt());
            actLeft->setTitleDescr(qmodel_ordId->query().value(1).toString());
            actLeft->setDecriptionDescr(qmodel_ordId->query().value(12).toString());
        }else{
            actRight->setUserName(qmodel_usrNames->query().value(0).toString());
            actRight->setUserDate(QDateTime::fromString(query_act.value(4).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
            actRight->setTickedID(QVariant(id).toInt());
            actRight->setTitleDescr(qmodel_ordId->query().value(1).toString());
            actRight->setDecriptionDescr(qmodel_ordId->query().value(12).toString());
        }
        break;
    case 2:
        selUsrs.exec("Select FullName From `Users` Where `id` = " + query_act.value(3).toString());
        selUsrs.first();

        if(query_act.value(7).toString() == "L"){
            actLeft->setUserName(selUsrs.value(0).toString());
            actLeft->setUserDate(QDateTime::fromString(query_act.value(4).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
            actLeft->setTextMessege(query_act.value(8).toString());
        }else{
            actRight->setUserName(selUsrs.value(0).toString());
            actRight->setUserDate(QDateTime::fromString(query_act.value(4).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
            actRight->setTextMessege(query_act.value(8).toString());
        }
        break;
    case 3:
        selUsrs.exec("Select FullName From `Users` Where `id` = " + query_act.value(3).toString());
        selUsrs.first();

        if(query_act.value(7).toString() == "L"){
            actLeft->setUserName(selUsrs.value(0).toString());
            actLeft->setUserDate(QDateTime::fromString(query_act.value(4).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
            actLeft->setCheckWork(query_act.value(9).toInt());
            actLeft->setTitleWork(qmodel_ordId->query().value(1).toString());
            actLeft->setTextWork(query_act.value(8).toString());
            actLeft->setDateRangeWork(QDateTime::fromString(query_act.value(10).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss") + " => " + QDateTime::fromString(query_act.value(11).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
            actLeft->setNameWorkerWork("на " + qmodel_usrNames->query().value(1).toString());
        }else{
            actRight->setUserName(selUsrs.value(0).toString());
            actRight->setUserDate(QDateTime::fromString(query_act.value(4).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
            actRight->setCheckWork(query_act.value(9).toInt());
            actRight->setTitleWork(qmodel_ordId->query().value(1).toString());
            actRight->setTextWork(query_act.value(8).toString());
            actRight->setDateRangeWork(QDateTime::fromString(query_act.value(10).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss") + " => " + QDateTime::fromString(query_act.value(11).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
            actRight->setNameWorkerWork("на " + qmodel_usrNames->query().value(1).toString());
        }
        break;
    case 4:
        selUsrs.exec("Select FullName From `Users` Where `id` = " + query_act.value(3).toString());
        selUsrs.first();

        if(query_act.value(7).toString() == "L"){
            actLeft->setUserName(selUsrs.value(0).toString());
            actLeft->setUserDate(QDateTime::fromString(query_act.value(4).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
            actLeft->setTextAgree(query_act.value(8).toString());
            actLeft->setDate_CurUsrName(QDateTime::fromString(query_act.value(12).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"), selUsrs.value(0).toString(), qmodel_ordId->query().value(17).toInt());
        }else{
            actRight->setUserName(selUsrs.value(0).toString());
            actRight->setUserDate(QDateTime::fromString(query_act.value(4).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
            actRight->setTextAgree(query_act.value(8).toString());
            actRight->setDate_CurUsrName(QDateTime::fromString(query_act.value(12).toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"), selUsrs.value(0).toString(), qmodel_ordId->query().value(17).toInt());
        }
        break;
    }
}

void MainWindow::on_pushButton_act_return_clicked()
{
    act_type_click = 0;
    ui->tabWidget->setCurrentIndex(3);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->widget_set_mess->hide();
    ui->widget_set_work->hide();
    ui->widget_set_agree->hide();

    ui->label_act_fill->setText("<html><head/><body><p><span style=' font-size:12pt; font-weight:600;'>N/A</span></p></body></html>");

    ui->textEdit_set_work_txt->clear();
    ui->textEdit_set_mess_txt->clear();
    ui->textEdit_set_agree_txt->clear();
    ui->lineEdit_set_beg_date_work->clear();
    ui->lineEdit_set_fin_date_work->clear();
    ui->comboBox_set_status_agree->setCurrentIndex(0);
}

void MainWindow::on_pushButton_messege_clicked()
{
    act_type_click = 2;
    ui->tabWidget->setCurrentIndex(4);
    ui->tabWidget_3->setCurrentIndex(1);
    ui->widget_set_mess->show();

    ui->label_act_fill->setText("<html><head/><body><p><span style=' font-size:12pt; font-weight:600;'>Данные блока \"Комментарий\"</span></p></body></html>");

    /*
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y.%m.%d %X", &tstruct);
    QString str(buf);


    actLeft = new Actions_left;

    connect(this, SIGNAL(mainWinP(QMainWindow *)), actLeft, SLOT(mainWinP(QMainWindow *)));

    emit mainWinP(this);



    actNode->Wg = actLeft;
    actNode->prev = tail;
    actNode->numberPos = tail->numberPos + 1;
    tail->next = actNode;
    tail = actNode;

    ui->Layout_actions->insertWidget(0, actLeft);
    actLeft->Type_Action(2);
    actLeft->setTextMessege("*test - test - test*");


    Node_act *curr = head;
    for (int i = 0; i < (tail->numberPos); i++) {
        connect(this, SIGNAL(actLeftPos(int)), curr->Wg, SLOT(actLeftPos(int)));
        emit actLeftPos(i);
        curr = curr->next;
    }


    qmodel_actID->setQuery("SELECT max(Actions.id) FROM Actions");
    qmodel_actID->query().first();

    QSqlQuery insAct(db);

    insAct.prepare("INSERT INTO Actions (id, id_ord, id_creator, id_editor, date_create, act_type, text) "
    "VALUES (?, ?, ?, ?, ?, ?, ?)");
    insAct.addBindValue(QVariant(1 + qmodel_actID->query().value(0).toInt()).toString());
    insAct.addBindValue(id);
    insAct.addBindValue(qmodel_ordId->query().value(6).toString());
    insAct.addBindValue(QVariant(curUser).toString());
    insAct.addBindValue(str);
    insAct.addBindValue(QVariant(2).toString());
    insAct.addBindValue("");
    insAct.exec();
    */
}

void MainWindow::on_pushButton_act_add_clicked()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    QString str(buf);


    QSqlQuery selUsrs(db);

    actNode = new Node_act();

    if(curUser == qmodel_ordId->query().value(6).toInt()){
        actLeft = new Actions_left;

        connect(this, SIGNAL(mainWinP(QMainWindow *)), actLeft, SLOT(mainWinP(QMainWindow *)));
        emit mainWinP(this);

        actNode->Wg = actLeft;
        actNode->prev = tail;
        actNode->numberPos = tail->numberPos + 1;
        tail->next = actNode;
        tail = actNode;

        ui->Layout_actions->insertWidget(0, actLeft);
        actLeft->Type_Action(act_type_click);

        switch (act_type_click) {
        case 2:
            selUsrs.exec("Select FullName From `Users` Where `id` = " + QVariant(curUser).toString());
            selUsrs.first();

            actLeft->setUserDate(str);
            actLeft->setUserName(selUsrs.value(0).toString());
            actLeft->setTextMessege(ui->textEdit_set_mess_txt->toPlainText());
            break;
        case 3:
            selUsrs.exec("Select FullName From `Users` Where `id` = " + QVariant(curUser).toString());
            selUsrs.first();

            actLeft->setUserDate(str);
            actLeft->setUserName(selUsrs.value(0).toString());
            actLeft->setTitleWork(qmodel_ordId->query().value(1).toString());
            actLeft->setTextWork(ui->textEdit_set_work_txt->toPlainText());
            actLeft->setDateRangeWork(ui->lineEdit_set_beg_date_work->text() + " => " + ui->lineEdit_set_fin_date_work->text());
            selUsrs.exec("Select FullName From `Users` Where `id` = " + qmodel_ordId->query().value(8).toString());
            selUsrs.first();
            actLeft->setNameWorkerWork(selUsrs.value(0).toString());
            break;
        case 4:
            selUsrs.exec("Select FullName From `Users` Where `id` = " + QVariant(curUser).toString());
            selUsrs.first();

            actLeft->setUserDate(str);
            actLeft->setUserName(selUsrs.value(0).toString());
            actLeft->setTextAgree(ui->textEdit_set_agree_txt->toPlainText());
            actLeft->setDate_CurUsrName(ui->lineEdit_set_date_decision->text(), selUsrs.value(0).toString(), ui->comboBox_set_status_agree->currentIndex() + 1);
            break;
        }
    }else{
        actRight = new Actions_right;

        connect(this, SIGNAL(mainWinP(QMainWindow *)), actRight, SLOT(mainWinP(QMainWindow *)));
        emit mainWinP(this);

        actNode->Wg = actRight;
        actNode->prev = tail;
        actNode->numberPos = tail->numberPos + 1;
        tail->next = actNode;
        tail = actNode;

        ui->Layout_actions->insertWidget(0, actRight);
        actRight->Type_Action(act_type_click);

        switch (act_type_click) {
        case 2:
            selUsrs.exec("Select FullName From `Users` Where `id` = " + QVariant(curUser).toString());
            selUsrs.first();

            actRight->setUserDate(str);
            actRight->setUserName(selUsrs.value(0).toString());
            actRight->setTextMessege(ui->textEdit_set_mess_txt->toPlainText());
            break;
        case 3:
            selUsrs.exec("Select FullName From `Users` Where `id` = " + QVariant(curUser).toString());
            selUsrs.first();

            actRight->setUserDate(str);
            actRight->setUserName(selUsrs.value(0).toString());
            actRight->setTitleWork(qmodel_ordId->query().value(1).toString());
            actRight->setTextWork(ui->textEdit_set_work_txt->toPlainText());
            actRight->setDateRangeWork(ui->lineEdit_set_beg_date_work->text() + " => " + ui->lineEdit_set_fin_date_work->text());
            selUsrs.exec("Select FullName From `Users` Where `id` = " + qmodel_ordId->query().value(8).toString());
            selUsrs.first();
            actRight->setNameWorkerWork(selUsrs.value(0).toString());
            break;
        case 4:
            selUsrs.exec("Select FullName From `Users` Where `id` = " + QVariant(curUser).toString());
            selUsrs.first();

            actRight->setUserDate(str);
            actRight->setUserName(selUsrs.value(0).toString());
            actRight->setTextAgree(ui->textEdit_set_agree_txt->toPlainText());
            actRight->setDate_CurUsrName(ui->lineEdit_set_date_decision->text(), selUsrs.value(0).toString(), ui->comboBox_set_status_agree->currentIndex() + 1);
            break;
        }
    }

    Node_act *curr = head;
    for (int i = 0; i < (tail->numberPos); i++) {
        connect(this, SIGNAL(actLeftPos(int)), curr->Wg, SLOT(actLeftPos(int)));
        emit actLeftPos(i);
        curr = curr->next;
    }

    //actLeft->setPosNumber(actNode->numberPos - 1);

    qmodel_actID->setQuery("SELECT max(Actions.id) FROM Actions");
    qmodel_actID->query().first();

    QSqlQuery insAct(db);
    QSqlQuery updOrdDateDecision(db);

    switch (act_type_click) {
    case 2:
        insAct.prepare("INSERT INTO Actions (id, id_ord, id_creator, id_editor, date_create, act_type, text, right_or_left, act_pos) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
        insAct.addBindValue(QVariant(1 + qmodel_actID->query().value(0).toInt()).toString());
        insAct.addBindValue(id);
        insAct.addBindValue(qmodel_ordId->query().value(6).toString());
        insAct.addBindValue(QVariant(curUser).toString());
        insAct.addBindValue(str);
        insAct.addBindValue(QVariant(act_type_click).toString());
        insAct.addBindValue(ui->textEdit_set_mess_txt->toPlainText());
        if(curUser == qmodel_ordId->query().value(6).toInt()){
            insAct.addBindValue("L");
        }else{
            insAct.addBindValue("R");
        }
        insAct.addBindValue(actNode->numberPos - 1);
        insAct.exec();
        break;
    case 3:
        insAct.prepare("INSERT INTO Actions (id, id_ord, id_creator, id_editor, date_create, act_type, text, right_or_left, act_pos, date_beg, date_fin, check) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        insAct.addBindValue(QVariant(1 + qmodel_actID->query().value(0).toInt()).toString());
        insAct.addBindValue(id);
        insAct.addBindValue(qmodel_ordId->query().value(6).toString());
        insAct.addBindValue(QVariant(curUser).toString());
        insAct.addBindValue(str);
        insAct.addBindValue(QVariant(act_type_click).toString());
        insAct.addBindValue(ui->textEdit_set_mess_txt->toPlainText());
        if(curUser == qmodel_ordId->query().value(6).toInt()){
            insAct.addBindValue("L");
        }else{
            insAct.addBindValue("R");
        }
        insAct.addBindValue(actNode->numberPos - 1);
        insAct.addBindValue(ui->lineEdit_set_beg_date_work->text());
        insAct.addBindValue(ui->lineEdit_set_fin_date_work->text());
        insAct.addBindValue(0);
        insAct.exec();
        break;
    case 4:
        insAct.prepare("INSERT INTO Actions (id, id_ord, id_creator, id_editor, date_create, act_type, text, right_or_left, act_pos, date_agree) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        insAct.addBindValue(QVariant(1 + qmodel_actID->query().value(0).toInt()).toString());
        insAct.addBindValue(id);
        insAct.addBindValue(qmodel_ordId->query().value(6).toString());
        insAct.addBindValue(QVariant(curUser).toString());
        insAct.addBindValue(str);
        insAct.addBindValue(QVariant(act_type_click).toString());
        insAct.addBindValue(ui->textEdit_set_mess_txt->toPlainText());
        if(curUser == qmodel_ordId->query().value(6).toInt()){
            insAct.addBindValue("L");
        }else{
            insAct.addBindValue("R");
        }
        insAct.addBindValue(actNode->numberPos - 1);
        insAct.addBindValue(ui->lineEdit_set_date_decision->text());
        insAct.exec();

        updOrdDateDecision.exec("UPDATE `Work` SET DateDecision =" + ui->lineEdit_set_date_decision->text() + " Where `Work`.id = " + id);
        break;
    }
    on_pushButton_act_return_clicked();
}

void MainWindow::on_pushButton_7_clicked()
{
    act_type_click = 3;
    ui->tabWidget->setCurrentIndex(4);
    ui->tabWidget_3->setCurrentIndex(1);
    ui->widget_set_work->show();

    ui->label_act_fill->setText("<html><head/><body><p><span style=' font-size:12pt; font-weight:600;'>Данные блока \"Задача\"</span></p></body></html>");
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->tabWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_10_clicked()
{
    act_type_click = 4;
    ui->tabWidget->setCurrentIndex(4);
    ui->tabWidget_3->setCurrentIndex(1);
    ui->widget_set_agree->show();

    ui->label_act_fill->setText("<html><head/><body><p><span style=' font-size:12pt; font-weight:600;'>Данные блока \"Решение\"</span></p></body></html>");
}
