#include "widget.h"
#include <QApplication>
#include <QTextCodec>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.showMaximized();

    return a.exec();
}
