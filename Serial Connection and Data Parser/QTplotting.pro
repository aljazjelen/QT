#-------------------------------------------------
#
# Project created by QtCreator 2017-08-03T12:15:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = QTplotting
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    qrealtimeplot.cpp \
    form.cpp \
    plottingwindow.cpp

HEADERS  += mainwindow.h\
        qcustomplot.h \
    qrealtimeplot.h \
    form.h \
    plottingwindow.h

FORMS    += mainwindow.ui \
    form.ui \
    plottingwindow.ui
