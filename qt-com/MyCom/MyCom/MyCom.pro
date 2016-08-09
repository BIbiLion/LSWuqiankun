#-------------------------------------------------
#
# Project created by QtCreator 2015-04-27T21:34:39
#
#-------------------------------------------------

QT       += core gui

QT += serialport  ##

#CONFIG+=qwt 增加qwt的用�?

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BWMS
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    settingsdialog.cpp

HEADERS  += widget.h \
    settingsdialog.h

FORMS    += widget.ui \
    settingsdialog.ui



RC_ICONS=Myico.ico

RESOURCES += \
    icons.qrc
