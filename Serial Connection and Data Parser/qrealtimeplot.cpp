#include "qrealtimeplot.h"

QRealTimePlot::QRealTimePlot(QWidget *parent)
{
    this->addGraph();
    this->setInteraction(QCP::iRangeDrag, true);
    this->setInteraction(QCP::iRangeZoom,true);
    this->initTimers();
    //this->setInteraction(QCP::SelectionType,true);
    //this->selectionRect(QCP::srmSelect);
    //this->selectionRectMode(QCP::stSingleData);
}

QRealTimePlot::~QRealTimePlot(){}

void QRealTimePlot::increaseCounter()
{

}

void QRealTimePlot::setStorage(int storage)
{
    this->storage = storage;
}

void QRealTimePlot::setRefreshing()
{
    this->refreshingPlot = !this->refreshingPlot;
    if (this->refreshingPlot == false){
        this->drawTimer->stop();
    }
    else if (this->refreshingPlot == true){
        this->drawTimer->start(10);
    }
}

void QRealTimePlot::initTimers()
{
    connect(this->drawTimer,SIGNAL(timeout()),SLOT(redrawPlot()));
}

void QRealTimePlot::redrawPlot()
{
    float elapsed = this->currentTime.elapsed() / 1000.0;

    this->time.append(elapsed);
    this->value.append(qSin(this->time.last()*10));

    if (this->time.length()>this->storage)
    {
        this->time.removeFirst();
        this->value.removeFirst();
    }

    double maxValue = *std::max_element(this->value.constBegin(), this->value.constEnd());
    double minValue = *std::min_element(this->value.constBegin(), this->value.constEnd());

    this->xAxis->setRange(this->time.first(), this->time.last());
    this->yAxis->setRange(1.1 * minValue, 1.1 * maxValue);

    this->graph(0)->setData(this->time,this->value);
    this->replot();
    this->counter++;
}


//#include "qrealtimeplot.moc"
