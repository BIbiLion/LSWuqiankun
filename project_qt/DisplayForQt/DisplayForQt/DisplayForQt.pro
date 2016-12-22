#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T23:47:48
#
#-------------------------------------------------

QT       += core gui datavisualization

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DisplayForQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    DisplayWidget.cpp

HEADERS  += mainwindow.h \
    DisplayWidget.h

FORMS    += mainwindow.ui \
    DisplayWidget.ui

CONFIG   += c++11

#include(./dataV/customproxy.pri)

DISTFILES += \
    readMe
