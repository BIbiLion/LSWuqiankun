#-------------------------------------------------
#
# Project created by QtCreator 2016-09-12T14:30:53
#
#-------------------------------------------------

QT       += core gui
config += qwt


CONFIG(debug, debug|release) {
LIBS +=  -L"C:\Qt\Qt5.2.1\5.2.1\mingw48_32\lib" -lqwtd
} else {
LIBS +=  -L"C:\Qt\Qt5.2.1\5.2.1\mingw48_32\lib" -lqwt
}


#LIBS += -L"C:\Qt\Qt5.2.1\5.2.1\mingw48_32\lib" -lqwtd    #debug
#LIBS += -L"C:\Qt\Qt5.2.1\5.2.1\mingw48_32\lib" -lqwt     #release
INCLUDEPATH += "C:\Qt\Qt5.2.1\5.2.1\mingw48_32\include\qwt"
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets




TARGET = testCompass
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
