#-------------------------------------------------
#
# Project created by QtCreator 2016-04-24T09:51:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hz2Py
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    PinyinResource.h

FORMS    += mainwindow.ui

RESOURCES += \
    db/db.qrc
