#include <QCoreApplication>
#include <stdio.h>
#include <iomanip>
#include <QDebug>
#include <QBitArray>
#include <iostream>
#include <sstream>
#include <typeinfo>
using namespace std;
typedef union MDouble
{
    double numD;
    unsigned char _ch[8];

}MDouble;

int main(int argc, char *argv[])
{

 double  g_lngD=127.12345678;
    MDouble _mdouble;
    _mdouble.numD=g_lngD;
    for(int i=0;i<8;++i)
    {
        printf("0x%2X,", _mdouble._ch[i]);
    }

   qDebug()<<"\n";
      unsigned char * bv = (unsigned char*)&g_lngD;

      for(int i = 0; i<8; i++)
          printf("0x%2X,", bv[i]);

   system("pause");
    float af=27.1234567;
    qDebug()<<QString("%1").arg((double)af,10,'g',11);

    QString _str2("123.12345678");
  qDebug()<<_str2;

    system("pause");
    QByteArray _bta;
    _bta.resize(1);
    _bta[0]=10;
    QString _jiancexinxiStrHex(_bta.toHex());
    qDebug()<<_jiancexinxiStrHex;

    float _d=2.01;
    QString _str;
    qDebug()<< _str.setNum(_d,'g',6);

    system("pause");
    int _integer=697;
    int _zz=_integer/10;
    float _mod=_integer%10*0.1;
    qDebug()<<_zz<<_mod;


    system("pause");
    unsigned int asi=697;
    unsigned char * bs = (unsigned char*)&asi;

    for(int i = 0; i<2; i++)
        printf("0x%2X,", bs[i]);

    qDebug()<<sizeof(unsigned short)<<sizeof(short int)<<sizeof(short);

    system("pause");
    // 将十六进制转换为float形式
    unsigned char pMem[] = {0x66,0xE6,0xF0,0x42};
    float *p = (float*)pMem;
    printf("%g\r\n",*p);

    // 将float转换为16进制
    //float a=120.45f;
    float a=27.0001f;
    unsigned char * b = (unsigned char*)&a;

    for(int i = 0; i<4; i++)
        printf("0x%2X,", b[i]);


    qDebug()<<"----------------"<<QString::number(a,'g',10)<<QString::number(a,'f')<<QString::number(a,'e');
    system("pause");
    unsigned char _tmp=0xFF;
    QBitArray _bt(3);
    _bt.setBit(0,true);
    _bt.setBit(1,false);
    qDebug()<<"-----"<<QString("%1").arg(_bt.at(0))<<_bt.at(1);

    char _c[5];
    qDebug()<<"----------"<<strlen(_c)<<sizeof(_c);

    system("pause");

    unsigned char pm[]={0x20,0x12};
    unsigned short *pshort=(unsigned short*)pm;
    qDebug()<<*pshort;


    unsigned short aa=20;
    unsigned char *ss=(unsigned char *)&aa;
    for(int i = 0; i<2; i++)
        printf("0x%2X,", ss[i]);



    double tmp;
    cout << typeid(tmp).name() << endl;//用于验证tmp的类型
    string str = "0.98765432120123456789";
    cout << typeid(str).name() << endl;
    istringstream istr(str);
    istr >> tmp;
    cout<<tmp<<"\n";
    double _f=QString(str.c_str()).toDouble();
    qDebug()<<_f<<QString(str.c_str()).toFloat();


    qDebug()<<sizeof(unsigned short)<<sizeof(short);// 2 2
    system("pause");


    unsigned char pInt[] = {0x7d,0x7a,0x33,0x01};
    unsigned int *pi = (unsigned int*)pInt;
    qDebug()<<*pi;//


    unsigned int pai=20150909;
    unsigned char * bi = (unsigned char*)&pai;

    for(int i = 0; i<4; i++)
        printf("0x%2X,", bi[i]);


    unsigned int paia=235959;
    unsigned char * bia = (unsigned char*)&paia;

    for(int i = 0; i<4; i++)
        printf("0x%2X,", bia[i]);

    system("pause");
    unsigned char pDouble[] = {0x3A,0xE9,0x7D,0xE3,0xEB,0xE1,0x70,0x40};
    double *pd = (double*)pDouble;
    qDebug()<<*pd;//


    double ad=270.12009;
    unsigned char * bd = (unsigned char*)&ad;

    for(int i = 0; i<8; i++)
        printf("0x%2X,", bd[i]);



    //outPut 精度格式输出
    //    cout<<12345.0<<endl;//输出12345
    //    //cout<<fixed<<setprecision(2)<<123.456<<endl;/*如果在这个位置就加上fixed的话，后面的输出全部都按照fixed处理*/
    //    cout << setprecision(4)<< 3.1415926 << endl;//输出的结果是3.142
    //    cout<<setprecision(3)<<12345.0<<endl;//输出的结果是 "1.23e+004 "
    //    cout<<fixed<<setprecision(2)<<123.456<<endl;//输出的结果是123.46，要进行四舍五入
    //    cout<<showpoint<<12345.0<<endl;//输出12345.0

    return 0;
}
