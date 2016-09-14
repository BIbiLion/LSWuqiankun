#include <QCoreApplication>

#include <QDebug>
#include <QVector>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<int> _ver(20);

 for(int i=0;i<20;++i)
 {
     _ver[i]=i;
     //qDebug()<<_ver[0];
 }

 memmove(&_ver[0],&_ver[1],19);
 _ver[19]=20;

 for(int i=0;i<20;++i)
 {
     qDebug()<<_ver[i];
 }

    return a.exec();
}
