#-------------------------------------------------
#
# Project created by QtCreator 2016-09-27T10:45:50
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shijiazhuang_54Com
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialportobject.cpp \
    serialattri.cpp

HEADERS  += mainwindow.h \
    serialportobject.h \
    serialattri.h

FORMS    += mainwindow.ui
