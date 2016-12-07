#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T16:44:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mainPro
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    module.cpp

HEADERS  += mainwidget.h \
    module.h

FORMS    += mainwidget.ui \
    form.ui

RESOURCES += \
    rc.qrc

OTHER_FILES += \
    Linux_change_Icon.txt
