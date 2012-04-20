#-------------------------------------------------
#
# Project created by QtCreator 2012-04-05T22:37:42
#
#-------------------------------------------------

QT       -= gui

TARGET = StockBroker
TEMPLATE = lib

DEFINES += STOCKBROKER_LIBRARY

SOURCES += stockbroker.cpp \
    order.cpp

HEADERS += stockbroker.h\
        StockBroker_global.h \
    order.h \

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE5179F77
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = StockBroker.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
