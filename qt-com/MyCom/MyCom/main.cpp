
//-------------------------------------------------
//
// Project created by QQ1977800361 2015-04-27T21:34:39
//
//-------------------------------------------------

#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setStyleSheet("QLineEdit { background-color: gray }"); //样式
    Widget w;
    w.show();
    return a.exec();
}
