#-------------------------------------------------
#
# Project created by QtCreator 2016-06-06T09:54:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TabWidget
TEMPLATE = app

INCLUDEPATH +=../test/

SUBDIRS+=
SOURCES += main.cpp\
        mainwindow.cpp \
    tabwidget.cpp

HEADERS  += mainwindow.h \
    tabwidget.h

FORMS    += mainwindow.ui \
    tabwidget.ui
