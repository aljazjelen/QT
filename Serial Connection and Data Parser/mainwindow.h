#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include "form.h"
#include "plottingwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setTimers();
    ~MainWindow();

private slots:
    void printSmth();

    void on_openFormButton_clicked();
    void getFormData(int);
    void getFormData(Form*);

private:
    Ui::MainWindow *ui;
    int counter = 0;
    bool refreshingPlot = false;
};

#endif // MAINWINDOW_H
