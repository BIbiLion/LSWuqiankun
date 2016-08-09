#-------------------------------------------------
#
# Project created by QtCreator 2015-07-20T15:02:29
#
#-------------------------------------------------

QT       += core serialport gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialcomDemo
CONFIG   += console
CONFIG   += c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    SerialCom/ParseWorker.cpp \
    SerialCom/SerialCom.cpp \
    ProjectUI/mainwindow.cpp \
    ProjectUI/CustomControl/mycombox.cpp \
    Public/mycustonevent.cpp

HEADERS += \
    Queue/safequeue.h \
    SerialCom/ParseWorker.h \
    Public/global.h \
    SerialCom/SerialCom.h \
    ProjectUI/mainwindow.h \
    ProjectUI/CustomControl/mycombox.h \
    Public/mycustonevent.h

RESOURCES += \
    resources.qrc
