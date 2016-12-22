#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include<QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    QStringList keyList = QStyleFactory::keys();//主机平台支持的Style类型
    qDebug()<<"QStyle"<<keyList;//QStyle ("Windows", "WindowsXP", "WindowsVista", "Fusion")

    MainWindow w;
    w.show();

    return a.exec();
}
