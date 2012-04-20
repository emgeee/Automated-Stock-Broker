#-------------------------------------------------
#
# Project created by QtCreator 2012-04-17T16:23:00
#
#-------------------------------------------------

QT       += core gui

TARGET = MarketSimulation
TEMPLATE = app


INCLUDEPATH = ../StockBroker

SOURCES += main.cpp\
            mainwindow.cpp \
            simulationmarket.cpp \
            simbroker.cpp

HEADERS  += mainwindow.h \
            simulationmarket.h \
            simbroker.h \
            stockbroker.h \
            order.h


FORMS    += mainwindow.ui

unix:!macx:!symbian: LIBS += -L$$PWD/../StockBroker/ -lStockBroker

INCLUDEPATH += $$PWD/../StockBroker
DEPENDPATH += $$PWD/../StockBroker
