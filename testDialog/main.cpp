#include "mainwindow.h"
#include <QApplication>
#include "form.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    QString _str("116.1234567");
    double _d=_str.toDouble();
    double _mm=126.1234567;

    QString _str2("123456gkxyz");

    if(!_str2.startsWith("gk"))
    {
        int _pos=_str2.indexOf("gk");
        _str2= _str2.mid(_pos);
    }
    qDebug()<<_str2;

    //Form f;
    //f.show();
    return a.exec();
}
