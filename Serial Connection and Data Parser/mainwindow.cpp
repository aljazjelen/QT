#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "form.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setTimers();
    QTextStream(stdout) << "Main window created ..." << endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTimers()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(printSmth()));
    timer->start(10);
    QTextStream(stdout) << "Setting timers ..." << endl;
}

void MainWindow::printSmth()
{
    ui->status->setText(QString::number(this->counter));
    counter++;
}

void MainWindow::on_openFormButton_clicked()
{
    Form *myform = new Form();
    connect(myform,SIGNAL(passData(Form*)),this,SLOT(getFormData(Form*)));
    myform->show();

    PlottingWindow *plotW = new PlottingWindow();
    plotW->show();
}

void MainWindow::getFormData(int data)
{
    QTextStream out(stdout);

    out << data;
}

void MainWindow::getFormData(Form *form)
{
    QTextStream out(stdout);

    out << form->name;
}
