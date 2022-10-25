#include "inputhyper.h"
#include "ui_inputhyper.h"

inputhyper::inputhyper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputhyper)
{
    ui->setupUi(this);
}

inputhyper::~inputhyper()
{
    delete ui;
}

void inputhyper::on_buttonBox_accepted()
{
    accept();
}


void inputhyper::on_buttonBox_rejected()
{
    reject();
}

QString inputhyper::name(){
    return ui->lineEdit->text();
}
QString inputhyper::hyperlink(){
    return ui->lineEdit_2->text();
}
QString inputhyper::description(){
    return ui->lineEdit_3->text();
}
