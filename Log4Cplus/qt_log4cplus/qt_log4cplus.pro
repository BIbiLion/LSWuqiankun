#-------------------------------------------------
#
# Project created by QtCreator 2016-12-30T11:42:16
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = qt_log4cplus
CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH+=/usr/local/include/log4cplus
LIBS += /usr/local/lib/liblog4cplus.so

TEMPLATE = app


SOURCES += main.cpp
