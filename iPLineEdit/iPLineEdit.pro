#-------------------------------------------------
#
# Project created by QtCreator 2016-06-01T18:02:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iPLineEdit
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp  \
    MyIpPartLineEdit.cpp \
    MyIpAddrEdit.cpp

HEADERS  += mainwindow.h \
    MyIpPartLineEdit.h \
    MyIpAddrEdit.h

FORMS    += mainwindow.ui
