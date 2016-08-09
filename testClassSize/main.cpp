#include <QCoreApplication>
#include "testclass.h"
#include <QDebug>
#include <stdio.h>
#include <QByteArray>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    testClass tc;

    qDebug()<<sizeof(tc);
    QByteArray _byte("5C 66 01 33 7A 7D A6");
    unsigned char _data[7];



    for(int i=0;i<7 ;++i)
    {
        qDebug()<<_data[0];
    }
    return a.exec();
}
