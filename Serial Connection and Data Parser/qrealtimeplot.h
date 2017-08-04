#ifndef QREALTIMEPLOT_H
#define QREALTIMEPLOT_H

#include "qcustomplot.h"
#include "algorithm"

class QRealTimePlot : public QCustomPlot
{
    Q_OBJECT
public:
    QRealTimePlot(QWidget *parent = 0);
    ~QRealTimePlot();

    void increaseCounter();
    void refreshX();
    void setStorage(int storage);
    void setRefreshing();
    //void redrawPlot();

private slots:
    void redrawPlot();

private:
    QVector<double> time;
    QVector<double> value;

    QTimer *drawTimer = new QTimer(this);
    QTime currentTime = QTime::currentTime();

    bool refreshingPlot = false;
    int storage = 200;
    int counter = 0;

    // Methods
    void initTimers();
};

#endif // QREALTIMEPLOT_H
