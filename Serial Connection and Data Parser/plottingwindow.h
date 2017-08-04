#ifndef PLOTTINGWINDOW_H
#define PLOTTINGWINDOW_H

#include <QWidget>
#include "qrealtimeplot.h"

namespace Ui {
class PlottingWindow;
}

class PlottingWindow : public QWidget
{
    Q_OBJECT
private:
    Ui::PlottingWindow *ui;
public:
    explicit PlottingWindow(QWidget *parent = nullptr);
    ~PlottingWindow();

signals:

public slots:
private slots:
    void on_startStopbutton_clicked();
};

#endif // PLOTTINGWINDOW_H
