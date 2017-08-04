#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) : QWidget(parent) ,  ui(new Ui::Form)
{
    ui->setupUi(this);
}

void Form::on_confirmButton_clicked()
{
    //this->passData();
    emit passData(this);
    this->close();
}
