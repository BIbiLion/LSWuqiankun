#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int converNum(char _c)
{
    int _rNum=0;

    QByteArray _byte;
    _byte.resize(1);
    _byte[0]=_c;

    QByteArray _hexByte=_byte.toHex();
    QString _hexStr=QString(_hexByte);\
    bool _isOK=false;
    return _hexStr.toInt(&_isOK);
    qDebug()<<_hexStr;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    char _c=0x20;
   int _result= converNum(_c);



    return a.exec();
}
