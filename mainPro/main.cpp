#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);//去掉标题栏
    w.show();


    return a.exec();
}
