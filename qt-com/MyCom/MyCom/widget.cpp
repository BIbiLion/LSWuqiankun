//-------------------------------------------------
//
// Project created by QQ1977800361 2015-04-27T21:34:39
//
//-------------------------------------------------


#include "widget.h"
#include "ui_widget.h"



#include <QMessageBox>
#include <QDebug>
#include <QDataStream>
#include <QString>
#include <QFile>
#include <QByteArray>
#include <QStringRef>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
       timer = new QTimer(this);//定时计
    timer->start(500);//定时器开始计时，其中1000表示1000ms即1s,每1000ms就会触发一次槽函数。读取系统时间


   //setting界面
    Settings = new SettingsDialog; //


    //串口
    MyCom = new QSerialPort(this);

    //信号与槽函数
    //串口有数据就接受读，会有问题，读取不完全

  connect(MyCom,SIGNAL(readyRead()),this,SLOT(readData()));

  connect(timer,SIGNAL(timeout()),this,SLOT(timeUpDate()));//定时一到就刷新时间。
  myTimer2 = new QTimer(this); //建立串口读写超时定时器

  connect(myTimer2,SIGNAL(timeout()),this,SLOT(TimerUpdate_COM()));//必须要有的






}

Widget::~Widget()
{

    delete MyCom;  //
    delete ui;

    delete Settings; //释放窗口
}


//测试消除按钮********************************************
void Widget::on_TestpushButton_clicked()
{
   ui->ReadtextBrowser->clear();
   MyCom->clear();





}

//系统时间*****************************
void Widget::timeUpDate(){


    systime=QDateTime::currentDateTime();
    mysystime=systime.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->SysTimelabel->setText(mysystime);

}

//检测一个字符是不是十六进制字符，若是返回相应的值，否则返回0x10；
 char Widget::ConvertHexChar(char ch)
 {
     if((ch >= '0') && (ch <= '9'))
         return ch-0x30;
     else if((ch >= 'A') && (ch <= 'F'))
         return ch-'A'+10;
     else if((ch >= 'a') && (ch <= 'f'))
         return ch-'a'+10;
     else return (-1);
 }


 //将一个字符串作为十六进制串转化为一个字节数组，字节间可用空格分隔，返回转换后的字节数组长度，同时字节数组长度自动设置。
 void Widget::String2Hex(QString str, QByteArray &senddata)
    {
     int hexdata,lowhexdata;

         int hexdatalen = 0;

         int len = str.length();
         qDebug()<<len;//计算数据长度

         senddata.resize(len/2);

         char lstr,hstr;

         for(int i=0; i<len; )

         {

             //char lstr,

             hstr=str[i].toLatin1();

             if(hstr == ' ')

             {

                 i++;

                 continue;

             }

             i++;

             if(i >= len)

                 break;

             lstr = str[i].toLatin1();

             hexdata = ConvertHexChar(hstr);

             lowhexdata = ConvertHexChar(lstr);

             if((hexdata == 16) || (lowhexdata == 16))

                 break;

             else

                 hexdata = hexdata*16+lowhexdata;

             i++;

             senddata[hexdatalen] = (char)hexdata;

             hexdatalen++;

         }

         senddata.resize(hexdatalen);
         qDebug()<<"转换数据已结束";//

 }




//设置串口按钮******************************************************
void Widget::on_SettingpushButton_clicked()
{

    Settings->show();
    ui->openlabel->setText("设置串口完毕！");//或者用insert函数实现
}

//然后设置串口的信息**********************************************
void Widget::openSerialPort(){


    SettingsDialog::Settings p = Settings->settings();
    MyCom->setPortName(p.name);
    MyCom->setBaudRate(p.baudRate);
    MyCom->setDataBits(p.dataBits);
    MyCom->setParity(p.parity);
    MyCom->setStopBits(p.stopBits);
    MyCom->setFlowControl(p.flowControl);


if(MyCom->open(QIODevice::ReadWrite)){
    QString MyComName=MyCom->portName();
    //QString ComName ="已经打开"+Mycom; //字符串的组合
  ui->openStatuslabel->setText("已经打开"+MyComName);

}
else {
QMessageBox::critical(this, tr("Error"), MyCom->errorString());


}
}

//打开串口按钮********************************************
void Widget::on_OpenpushButton_clicked()
{
  this->openSerialPort();



}


//发送数据按钮**********************************************
void Widget::on_SendpushButton_clicked()
{
    //清空报警列表及红灯关闭
    //ui->AlarmtextBrowser->clear();


   if(MyCom->isOpen())
        {

      Widget::String2Hex(ui->SendlineEdit->text(),myHexdata); //将一个字符串作为十六进制串转化为一个字节数组，


      this->writeData(myHexdata);
      }
   else{
    qDebug()<<"端口打开出错";

    //QMessageBox::critical(this, tr("Error"), Myport->errorString());
     QMessageBox::warning(this, tr("My Application"),tr("The SerialPort has not open!"
                                                        ), QMessageBox::Ok );

      }
}


    //写入串口数据********************************************
 void Widget::writeData(const QByteArray &data){


        MyCom->write(data);
        qDebug()<<"数据写入完毕";
    }


   //读取串口数据的原始数据B型************************************
 void Widget::readData()
 {
     myTimer2->start(600);

     //QString myTemp;   //局部变量数据

    Readdata = myData2.append(MyCom->readAll());//读串口缓冲区QByteArray数据 关键是append

    qDebug()<<Readdata.toHex()<<"转换结束";//读取数据并转换，此时读取完毕后已经得到了整合后的数据

 }




 //读取数据按钮*************************************************
void Widget::on_ReadpushButton_clicked()
{
    if(MyCom->isOpen() ){        //串口打开才能读取
        this->readData();
        qDebug()<<"准备读取";
         }
    else
        return ;
}



//超时候处理数据。。。。进行数据帅选********************************
void Widget::TimerUpdate_COM(){

    myTimer2->stop();  
    qDebug()<<"需要处理的数据"<<Readdata.toHex();

          //************************//
          //**********重点在此*******//
        QDataStream out(&Readdata,QIODevice::ReadWrite);//有字节数据发送过来
 while(!out.atEnd())

     {
           qint8 outChar = 0;//设置发送长度初始值为0
           out>>outChar;//每字节填充一次，直到结束
           myStringData1 = QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0')).toUpper();
            myStringData2 +=myStringData1;
            }
       //ui的Readlabel显示
    ui->ReadtextBrowser->setText("***@"+myStringData2+"@***"+"\n");//读取到的所有信息,其实可以使用。tohex可以实现



    }



 //释放数据内存



































//关闭软件按钮**************************************************
void Widget::on_ClosepushButton_clicked()
{
    MyCom->close();
    this->close();

}





//void Widget::on_pushButton_clicked()
//{

//}
