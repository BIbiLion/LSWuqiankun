#include "qbattery.h"
#include "testwidget.h"
int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    TestWidget win;
    win.show();
    return app.exec();
}
