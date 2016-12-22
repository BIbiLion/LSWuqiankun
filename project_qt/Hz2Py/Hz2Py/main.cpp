#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f = a.font();
    f.setFamily("Consolas");
    f.setPixelSize(14);
    f.setItalic(true);
    f.setBold(true);
    a.setFont(f);
    MainWindow w;
    w.show();

    return a.exec();
}
