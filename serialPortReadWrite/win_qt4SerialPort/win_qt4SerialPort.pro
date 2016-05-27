#-------------------------------------------------
#
# Project created by QtCreator 2016-05-27T15:44:30
#
#-------------------------------------------------

QT       += core gui

TARGET = win_qt4SerialPort
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    win_qextserialport.cpp \
    qextserialport.cpp \
    qextserialbase.cpp

HEADERS  += mainwindow.h \
    qextserialport.h \
    qextserialbase.h \
    win_qextserialport.h

FORMS    += mainwindow.ui
