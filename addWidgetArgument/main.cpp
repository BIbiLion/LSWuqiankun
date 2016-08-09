/*
Descriple: this is a test about the addwidget's argument.
//widget ,行，列， 占用行数，占用列数。
addWidget(QWidget* widget,int row,int colune,int rowspan,int coluneSpan)

Function:
author: wuqiankun
time:
*/

#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
