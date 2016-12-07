#-------------------------------------------------
#
# Project created by QtCreator 2016-12-01T15:19:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    translatewidget.cpp

HEADERS  += mainwidget.h \
    translatewidget.h

FORMS    += mainwidget.ui \
  form.ui \
  translatewidget.ui



#MOC_DIR += ./tmp
#DESTDIR += ./bin
