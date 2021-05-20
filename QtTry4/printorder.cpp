#include "printorder.h"
#include "ui_printorder.h"


PrintOrder::PrintOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrintOrder)
{
    ui->setupUi(this);

    this->setBtn(0);

    qmodel_filReport = new QSqlQueryModel;


    this->setWindowFlag(Qt::WindowMinimizeButtonHint, false);
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
    this->setWindowFlag(Qt::WindowSystemMenuHint, false);
    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    this->setWindowFlag(Qt::WindowFullscreenButtonHint, false);



    qDebug() << this->windowFlags();


    //Добавление на бланк отчета логотип организации
    //--------------------------------------------------------------------------------------------------------------------------------------------
    logo = new QPixmap;
    logo->load(":/resource/img/IT-Osoba_Logo_150x88.png");

    int w = ui->img_logo->width();
    int h = ui->img_logo->height();

    ui->img_logo->setPixmap(logo->scaled(w, h, Qt::KeepAspectRatio));
    //--------------------------------------------------------------------------------------------------------------------------------------------



    connect(ui->lineEdit_bordName, SIGNAL(inputRejected()), this, SLOT(inputReject()));    
    connect(ui->lineEdit_bordName, SIGNAL(editingFinished()), this, SLOT(inputReject()));
    connect(this, SIGNAL(clicked(QMouseEvent *)), this, SLOT(clearFocusEd()));


    if(!(ui->lineEdit_bordName->hasFocus()))
    {
        ui->label_SubBordName->setText(ui->lineEdit_bordName->text());
    }
}

PrintOrder::~PrintOrder()
{
    delete ui;
}

void PrintOrder::fillReport(int id)
{
    qmodel_filReport->setQuery("select Orders.Title, `Create`.DateOpen, `Edit`.DateEdit, `Work`.DateDecision, workUser.FullName, editUser.FullName, createUser.FullName, contUser.FullName, Orders.Description "
                               "From ((((((((Orders inner join `Create` on Orders.id = `Create`.id) inner join `Edit` on Orders.id = `Edit`.id) left join `Work` on Orders.id = `Work`.id) "
                               "left join `Control` on Orders.id = `Control`.id) left join Users AS workUser on workUser.id = `Work`.WhoWork) inner join Users AS editUser on editUser.id = `Edit`.WhoEdit) "
                               "inner join Users AS createUser on createUser.id = `Create`.WhoCreate) left join Users AS contUser on contUser.id = `Control`.WhoControlling) "
                               "Where Orders.id = '" + QVariant(id).toString() + "';");
    qmodel_filReport->query().first();

    QString tmp = qmodel_filReport->index(0,7).data().toString();

    ui->label->setText("<html><head/><body><p align='center'><span style=' font-size:14pt; font-weight:600;'>" + QVariant(id).toString() + "</span></p></body></html>");
    ui->lineEdit_bordName_6->setText(qmodel_filReport->index(0,0).data().toString());
    ui->lineEdit_TechName->setText(qmodel_filReport->index(0,4).data().toString());
    if(tmp != "") {
        ui->lineEdit_bordName_8->setText(qmodel_filReport->index(0,7).data().toString());
    }else{
        ui->lineEdit_bordName_8->setText(qmodel_filReport->index(0,6).data().toString());}
    ui->lineEdit_bordName_9->setText(QDateTime::fromString(qmodel_filReport->index(0,1).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
    ui->lineEdit_bordName_10->setText(QDateTime::fromString(qmodel_filReport->index(0,2).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss") + "   на   " + qmodel_filReport->index(0,5).data().toString());
    ui->lineEdit_bordName_11->setText(QDateTime::fromString(qmodel_filReport->index(0,3).data().toString(), "yyyy-MM-ddTHH:mm:ss.zzz").toString("yyyy.MM.dd HH:mm:ss"));
    ui->textEdit->setPlainText(qmodel_filReport->index(0,8).data().toString());
    ui->label_SubTechName->setText(ui->lineEdit_TechName->text());
}

void PrintOrder::inputReject()
{
    ui->label_SubBordName->setText(ui->lineEdit_bordName->text());
    /*if(ui->lineEdit->text().size() == 5)
    {
        ui->lineEdit_2->setFocus();
    }*/

    /*
    QString a = ui->lineEdit->text();
    qDebug() << a.size();*/
}


void PrintOrder::mousePressEvent (QMouseEvent *event) {
    emit clicked(event);
}

void PrintOrder::setBtn(int btn) {
    this->btn = btn;
}

int PrintOrder::button(void) {
    return this->btn;
}

void PrintOrder::clearFocusEd()
{
    if(this->focusWidget() != NULL)
    {
        this->focusWidget()->clearFocus();
    }
}
