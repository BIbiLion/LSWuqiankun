#include "mainwidget.h"
#include <QApplication>
#include  "translatewidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWidget w;
    w.show();

    translateWidget trw;
     trw.setWindowTitle("test_translate");
    trw.show();

    return a.exec();
}
