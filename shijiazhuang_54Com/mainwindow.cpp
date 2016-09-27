#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <string.h>


static char HexChar(char c)
{
    if((c>='0')&&(c<='9'))
        return c-0x30;
    else if((c>='A')&&(c<='F'))
        return c-'A'+10;
    else if((c>='a')&&(c<='f'))
        return c-'a'+10;
    else
        return 0x10;
}

//将一个字符串作为十六进制串转化为一个字节数组，字节间可用空格分隔，
//返回转换后的字节数组长度，同时字节数组长度自动设置。
static int Str2Hex( std::string str, char* data)
{
    int t,t1;
    int rlen=0,len=str.length();
    for(int i=0;i<len;)
    {
        char l,h=str[i];
        if(h==' ')//如果有空格
        {
            i++;
            continue;
        }
        i++;
        if(i>=len)
            break;
        l=str[i];
        t=HexChar(h);
        t1=HexChar(l);
        if((t==16)||(t1==16))
            break;
        else
            t=t*16+t1;
        i++;
        data[rlen]=(char)t;
        rlen++;
    }
    qDebug()<<"长度："<<rlen;
    return rlen;

}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),m_serialPort(NULL),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openComBtn,SIGNAL(clicked()),this,SLOT( openCom() ));
    connect(ui->sendDataBtn,SIGNAL(clicked()),this,SLOT(sendData()));
    connect(ui->clearCls,SIGNAL(clicked()),this,SLOT(clear()));
    QList<QSerialPortInfo> _listSerialPort= QSerialPortInfo::availablePorts();
    foreach (QSerialPortInfo _protInfo, _listSerialPort)
    {
        if(!_protInfo.isNull())
        {
            ui->comboBox->addItem(_protInfo.portName());
            qDebug()<<_protInfo.portName();
        }
    }

}
void MainWindow::clear()
{
    ui->displayTextEdit->setText(QString(""));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openCom()
{
    SerialAttri _seriaAttri(ui->comboBox->currentText(),"38400","无校验","8","1");
    m_serialPort= new SerialPortObject(_seriaAttri);
    connect(m_serialPort,SIGNAL(sendComRev(QByteArray)),this,SLOT(showData(QByteArray)));

}
void MainWindow::showData(QByteArray _by)
{
    QByteArray _hexData=_by.toHex();
    int _count=_hexData.count();
    int _pos=2;
    for(int i=0;i<_count;++i)
    {
        _hexData.insert(_pos,' ');
        _pos+=3;
    }
    ui->displayTextEdit->setText(ui->displayTextEdit->toPlainText()+"\n"+"received："+_hexData);
    //收到23帧 发送83帧  发送81帧（界面上发送的帧）
    qDebug()<<_hexData;
    if(_hexData.count()<8)
    {
        return;
    }
    if(('2'==_hexData[6])&&('3'==_hexData[7]))
    {
        qDebug()<<"收到23帧";
        sendData_83();
        sendData();//发送界面上发送的81帧
    }
}

//发送没用，不做处理
void MainWindow::sendData_83()
{
    //固定长度
    QString _str("55 AA 83 00 11 12 22 20 00 01 11");
    char sendDataPtr[300];
    int length=Str2Hex(_str.toStdString().c_str(),sendDataPtr);
    ui->displayTextEdit->setText(ui->displayTextEdit->toPlainText()+"\n"+"send ---83---:"+_str);
    m_serialPort->write(sendDataPtr,length);
}


void MainWindow::sendData()
{
    if(m_serialPort==NULL )
    {
        return;
    }

    //填写的是 字符串   转换成16进制串
    QString _str=ui->sendTextEdit->toPlainText();
    char p[300];

    int length=Str2Hex(_str.toStdString().c_str(),p);

    ui->displayTextEdit->setText(ui->displayTextEdit->toPlainText()+"\n"+"send --81--"+_str);

    m_serialPort->write(p,length);
}