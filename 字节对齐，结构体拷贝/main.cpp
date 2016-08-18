#include <QCoreApplication>
#include <QDebug>

#pragma pack(1) //1个字节对齐          就是没有空的字节
struct File
{
    unsigned short u_s;
    double a_D;
    double b_D;
    char i_ch;
    float  c_F;
    unsigned char _ch;
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    File _file;
    _file.u_s=6000;
    _file.a_D=20.0001;
    _file.b_D=20.0001;
    _file.c_F=20.0001;
    _file.i_ch=11;
    _file._ch=0x0A;



    qDebug()<<sizeof(File)<<sizeof(double)<<sizeof(float)<<sizeof(unsigned short);

    File _newFile;
    memset(&_newFile,0,sizeof(File));
    memcpy(&_newFile,&_file,sizeof(File));
   qDebug()<<  _newFile.a_D <<_newFile.c_F<<_newFile.u_s<<_newFile.b_D<<_newFile._ch;
    return a.exec();
}
