#include "mainwindow.h"
#include <QApplication>
#include <QByteArray>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();
  unsigned char _c('a');
   _c=0xFF;
   QString str("a");
   qDebug()<<_c<<(_c+7);


   qDebug()<<sizeof(double)<<sizeof(unsigned int)<<sizeof(int)<<sizeof(unsigned short);
    system("pause");
    QByteArray ba;
    ba.resize(5);
    ba[0] = 0x68;
    ba[1] = 0x0D;
    ba[2] = 0x00;
    ba[3] = '\n';
    ba[4]=0x68;
    int _pos=-1;
    QByteArray _testA;
    _testA.resize(1);
    _testA[0]=0x68;
    _pos=ba.indexOf(_testA,1);
    qDebug()<<_pos;
    if((_pos=ba.indexOf(_testA) > -1))
    {
        qDebug()<<"hello";
    }

    if(ba[3]==0x0a)
    {
         qDebug()<<"LINE";
    }
    return a.exec();
}
