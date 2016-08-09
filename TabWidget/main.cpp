#include "mainwindow.h"
#include <QApplication>

#include "tabwidget.h"
#include "imagewidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    TabWidget tw;
    tw.show();

    return a.exec();
}
