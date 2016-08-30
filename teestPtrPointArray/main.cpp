#include <QCoreApplication>
#include <QDebug>
#include <QFile>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile ** _file;//指针的指针
    _file=NULL;
    _file= new  QFile*[5];//指针的指针  指向一个 一维数组  *******************
    qDebug()<<&( _file[0])<<&( _file[1])<<&( _file[2])<<&( _file[3]);

    //test
    char p[]={0x01,0xFF};

qDebug()<<(p[0]<<1)<<( (p[0]<<1)| (p[0]<<2)+1);//先+ 后与

    return a.exec();
}
