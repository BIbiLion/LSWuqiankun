#include <QApplication>
#include <Queue/safequeue.h>
#include "ProjectUI/mainwindow.h"

SafeQueue<QByteArray> gParseQueue;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *mainWindow = new MainWindow(0);
    mainWindow->show();
    return a.exec();
}
