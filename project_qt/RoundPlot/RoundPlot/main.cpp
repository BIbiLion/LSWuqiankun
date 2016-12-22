#include "frmroundplot.h"
#include <QApplication>

#include "gradienttest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    frmRoundPlot w;
    w.show();


    gradientTest gt;
    gt.show();
    return a.exec();
}
