#include "plottingwindow.h"
#include "ui_plottingwindow.h"

PlottingWindow::PlottingWindow(QWidget *parent) : QWidget(parent), ui(new Ui::PlottingWindow)
{
    ui->setupUi(this);
    ui->plotTop->setStorage(200);
    ui->plotBot->setStorage(2000);
}

PlottingWindow::~PlottingWindow()
{
    delete ui;
}

void PlottingWindow::on_startStopbutton_clicked()
{
    this->ui->plotTop->setRefreshing();
    this->ui->plotBot->setRefreshing();
}
