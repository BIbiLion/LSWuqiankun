#include "widget.h"
#include <QApplication>
#include "cdefinechart.h"
#include"cpiechart.h"
//#include "qchartviewer.h"


#include "meterwidget.h"
#include "realtimedemo.h"

#include"xylinewidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.showMaximized();


    MeterWidget m(0,360);
    //m.show();

   // RealTimeDemo rtd;
   // rtd.show();

    XYLineWidget xy;
    xy.show();


    return a.exec();
}
