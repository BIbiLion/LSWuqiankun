#-------------------------------------------------
#
# Project created by QtCreator 2016-12-06T16:25:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = node_edge
TEMPLATE = app


SOURCES += main.cpp\
    node.cpp \
    testitem.cpp \
    edge.cpp

HEADERS  += \
    node.h \
    testitem.h \
    edge.h

FORMS    += widget.ui

OTHER_FILES += \
    readme.txt
