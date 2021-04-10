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
    connect(sw, SIGNAL(DBConnect(QString)), this, SLOT(SigDBConnect(QString)));
    connect(this, SIGNAL(RevDBConnect(bool)), sw, SLOT(ConOrNot(bool)));
    connect(sw, SIGNAL(DBLog(QString, QString)), this, SLOT(SigDBLog(QString, QString)));
    connect(this, SIGNAL(RevDBLog(bool)), sw, SLOT(LogOrNot(bool)));
    connect(tmr, SIGNAL(timeout()), this, SLOT(UpdateDB()));
    connect(ui->act_return, SIGNAL(triggered()), this, SLOT(ReturnEdit()));
    //--------------------------------------------------------------------------------------------------------------------------------------------

    //Фильтр заявок
    //--------------------------------------------------------------------------------------------------------------------------------------------
    QStringList var1 = {"---", "Не"};
    QStringList var2 = {"---", "Не"};

    ui->comboBox->addItems(var1);
    ui->comboBox_2->addItems(var2);
    //--------------------------------------------------------------------------------------------------------------------------------------------



    /*
    Node_1 *First = new Node_1();
    for (int i = 0; i < 2; i++)
    {
        if(i == 0)
        {
            First->next = NULL;

            head = First;
            tail = First;

            First->id = 0;
            First->data = "---";
        }
        else
        {
            Node_1 *First = new Node_1();
            tail->next = First;

            First->next = NULL;
            tail = First;

            First->id = 1;
            First->data = "Не";
        }
    }

    Node_1 *tmp = head;

    while(tmp != NULL)
        {
            qDebug() << "#" + QVariant(tmp->id).toString() + " Data: " + tmp->data;

            tmp = tmp -> next;
        }
*/




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

//Соединение с БД Access
//--------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::SigDBConnect(QString str)
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(str);

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



    qmodel->setQuery("SELECT Orders.id, Orders.Title, Status.SName, Edit.DateEdit, Create.DateOpen, Priority.PName, createUser.fullName AS Инициатор, workUser.FullName AS [Кто назначен], Categories.[C+SC] "
"FROM Users AS workUser INNER JOIN (Categories INNER JOIN (Status INNER JOIN (Priority INNER JOIN (((Orders INNER JOIN (Users AS createUser INNER JOIN [Create] ON createUser.id = Create.WhoCreate) ON Orders.id = Create.id) INNER JOIN Edit ON Orders.id = Edit.id) INNER JOIN [Work] ON Orders.id = Work.id) ON Priority.id = Orders.Priory) ON Status.id = Orders.Status) ON Categories.id = Orders.Category) ON workUser.id = Work.WhoWork ORDER BY Orders.id DESC;", db);

    qmodel_c1->setQuery("SELECT "
"-SUM(NOT Status.SName = 'Закрыто') AS cOpened, "
"-SUM(Status.SName = 'В работе (назначена)' OR Status.SName = 'В работе (запланированна)') AS cInWork "
"FROM Status INNER JOIN Orders ON Status.id = Orders.Status;", db);

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

//Действие "Возврат" в меню работы с отчетом
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
