#-------------------------------------------------
#
# Project created by QtCreator 2015-06-12T17:41:18
#
#-------------------------------------------------

QT       += core gui webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets

TARGET = EchartDemo
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

INCLUDEPATH += $$PWD
MOC_DIR     = temp/moc
RCC_DIR     = temp/rcc
UI_DIR      = temp/ui
OBJECTS_DIR = temp/obj
DESTDIR     = bin
