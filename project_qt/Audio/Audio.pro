#-------------------------------------------------
#
# Project created by QtCreator 2014-07-29T09:53:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Audio
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        curveplot.cpp

HEADERS  += mainwindow.h \
    curveplot.h \
    fmod.h \
    fmod_errors.h

FORMS    += mainwindow.ui

LIBS     +=E:\LSwuqiankun\LSWuqiankun\project_qt\Audio/libfmodex.a

RESOURCES += \
    images/images.qrc

DISTFILES += \
    fmod_sounds--sooundChangel
