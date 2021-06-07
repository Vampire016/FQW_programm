#include "actions_left.h"
#include "ui_actions_left.h"

Actions_left::Actions_left(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Actions_left)
{
    ui->setupUi(this);

    usr = new QPixmap;
    usr->load(":/resource/img/user.png");
    clock = new QPixmap;
    clock->load(":/resource/img/11clock.png");


    ui->label_2->setPixmap(usr->scaled(64,64));
    ui->label->setPixmap(clock->scaled(24,24));
    ui->pushButton_delAct->setIcon(QIcon(":/resource/img/Cross.png"));
    ui->pushButton_delAct->setIconSize(QSize(16, 16));
    ui->pushButton_editWork->setIcon(QIcon(":/resource/img/pen.png"));
    ui->pushButton_editWork->setIconSize(QSize(16, 16));

    ui->groupBox_work->hide();
    ui->groupBox_messege->hide();
    ui->groupBox_agreement->hide();
    ui->groupBox_descr->hide();

}

Actions_left::~Actions_left()
{
    delete ui;
}

void Actions_left::Type_Action(int type)
{
    switch (type) {

    case 1:
        ui->groupBox_descr->show();
        break;

    case 2:
        ui->groupBox_messege->show();
        break;

    case 3:
        ui->groupBox_work->show();
        break;

    case 4:
        ui->groupBox_agreement->show();
        break;

    }
}

void Actions_left::on_pushButton_delAct_clicked()
{
    connect(this, SIGNAL(delAct(int)), this->mainWin, SLOT(delAct_clicked(int)));
    emit delAct(pos);
    disconnect(this, SIGNAL(delAct(int)), this->mainWin, SLOT(delAct_clicked(int)));
}

void Actions_left::mainWinP(QMainWindow *mainWin)
{
    this->mainWin = mainWin;
    //connect(this, SIGNAL(delAct(int)), this->mainWin, SLOT(delAct_clicked(int)));
}

void Actions_left::actLeftPos(int pos)
{
    this->pos = pos;
}

void Actions_left::setPosNumber(int number)
{
    this->pos = number;
}

void Actions_left::setTextMessege(QString txt)
{
    ui->textEdit_mess_text->setText(txt);
    ui->textEdit_mess_text->document()->adjustSize();

    if(ui->textEdit_mess_text->document()->size().height() > ui->textEdit_mess_text->height()){
        ui->textEdit_mess_text->setMinimumHeight(ui->textEdit_mess_text->document()->size().height());
        if((ui->textEdit_mess_text->y() + ui->textEdit_mess_text->document()->size().height()) > (ui->groupBox_messege->height() - 20)){
            this->setMinimumHeight(this->height() + (((ui->textEdit_mess_text->y() + ui->textEdit_mess_text->document()->size().height()) + 20) - ui->groupBox_descr->height()));
            ui->groupBox_messege->setMinimumHeight((ui->textEdit_mess_text->y() + ui->textEdit_mess_text->document()->size().height()) + 20);
        }
    }
}

void Actions_left::setTitleDescr(QString title)
{
    ui->label_descr_title->setText("<html><head/><body><p><span style=' font-size:9pt; font-weight:600;'>" + title + "</span></p></body></html>");
}

void Actions_left::setDecriptionDescr(QString descr)
{
    ui->textEdit_descr_desc->setText(descr);
    ui->textEdit_descr_desc->document()->adjustSize();

    if(ui->textEdit_descr_desc->document()->size().height() > ui->textEdit_descr_desc->height()){
        ui->textEdit_descr_desc->setMinimumHeight(ui->textEdit_descr_desc->document()->size().height());
        if((ui->textEdit_descr_desc->y() + ui->textEdit_descr_desc->document()->size().height()) > (ui->groupBox_descr->height() - 20)){
            this->setMinimumHeight(this->height() + (((ui->textEdit_descr_desc->y() + ui->textEdit_descr_desc->document()->size().height()) + 20) - ui->groupBox_descr->height()));
            ui->groupBox_descr->setMinimumHeight((ui->textEdit_descr_desc->y() + ui->textEdit_descr_desc->document()->size().height()) + 20);
        }
    }
}

void Actions_left::setTickedID (int id)
{
    ui->label_descr_id->setText("Ticket #" + QVariant(id).toString() + " description");
}

void Actions_left::setUserDate(QString date)
{
    ui->label_curDate->setText(date);
}

void Actions_left::setUserName(QString usrName)
{
    ui->label_cre_name->setText(usrName);
}

void Actions_left::setCheckWork(int check)
{
    ui->checkBox_work->setChecked(check);
}

void Actions_left::setTitleWork(QString title)
{
    ui->label_work_title->setText(title);
}

void Actions_left::setTextWork(QString txt)
{
    ui->textEdit_work_desc->setText(txt);

    ui->textEdit_work_desc->document()->adjustSize();

    if(ui->textEdit_work_desc->document()->size().height() > ui->textEdit_work_desc->height()){
        ui->textEdit_work_desc->setMinimumHeight(ui->textEdit_work_desc->document()->size().height());

        if((ui->textEdit_work_desc->y() + ui->textEdit_work_desc->document()->size().height()) > (ui->groupBox_work->height() - 20)){
            this->setMinimumHeight(this->height() + (((ui->textEdit_work_desc->y() + ui->textEdit_work_desc->document()->size().height()) + 60) - ui->groupBox_work->height()));
            ui->groupBox_work->setMinimumHeight((ui->textEdit_work_desc->y() + ui->textEdit_work_desc->document()->size().height()) + 60);
        }
    }
}

void Actions_left::setDateRangeWork(QString date)
{
    ui->label_work_dates->setText(date);
}

void Actions_left::setNameWorkerWork(QString name)
{
    ui->label_work_worker->setText(name);
}


void Actions_left::setTextAgree(QString txt)
{
    ui->textEdit_text_agree->setText(txt);
    ui->textEdit_text_agree->document()->adjustSize();

    if(ui->textEdit_text_agree->document()->size().height() > ui->textEdit_text_agree->height()){
        ui->textEdit_text_agree->setMinimumHeight(ui->textEdit_text_agree->document()->size().height());
        if((ui->textEdit_text_agree->y() + ui->textEdit_text_agree->document()->size().height()) > (ui->groupBox_agreement->height() - 20)){
            this->setMinimumHeight(this->height() + (((ui->textEdit_text_agree->y() + ui->textEdit_text_agree->document()->size().height()) + 30) - ui->groupBox_agreement->height()));
            ui->groupBox_agreement->setMinimumHeight((ui->textEdit_text_agree->y() + ui->textEdit_text_agree->document()->size().height()) + 30);
        }
    }
}

void Actions_left::setDate_CurUsrName(QString date, QString name, int agree)
{
    QString agreement;
    if(agree == 3 || agree == 4){
        ui->groupBox_agreement_color->setStyleSheet("background: green;");
        agreement = "Принята на ";
    }else if(agree == 2){
        ui->groupBox_agreement_color->setStyleSheet("background: red;");
        agreement = "Отклонено на ";
    }else{
        ui->groupBox_agreement_color->setStyleSheet("background: orange;");
        agreement = "В ожидании согласнования на ";
    }
    ui->label_date_name_agree->setText(agreement + date + " " + name);
}

void Actions_left::on_checkBox_work_clicked()
{
    int ch;

    if(ui->checkBox_work->checkState() == Qt::Checked){
        ch = 1;
    }else{
        ch = 0;
    }

    connect(this, SIGNAL(checkBoxChanged(int, int)), this->mainWin, SLOT(checkBoxChanged(int, int)));
    emit checkBoxChanged(pos, ch);
}

void Actions_left::on_pushButton_editWork_clicked()
{
    connect(this, SIGNAL(workEditClick(int)), this->mainWin, SLOT(actWorkEditClicked(int)));
    emit workEditClick(pos);
}

void Actions_left::setDelHiden()
{
    ui->pushButton_delAct->hide();
}
