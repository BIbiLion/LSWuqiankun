#include "SerialCom.h"
#include <QRegExp>
#include <QDebug>
#include <iostream>
#include <windows.h>
#include "Public/global.h"

using namespace std;
// 构造函数
SerialCom::SerialCom(QObject *parent)
    : QObject(parent)
{
    m_serialCom = new QSerialPort(this);
    initConnect();
}

// 析构函数
SerialCom::~SerialCom()
{

}

void SerialCom::initConnect()
{
    connect(m_serialCom, SIGNAL(readyRead()), this, SLOT(slot_readData()));
    connect(m_serialCom, SIGNAL(error(QSerialPort::SerialPortError)),
            this, SLOT(slot_HandleError(QSerialPort::SerialPortError)));
}


// 异步处理串口通信数据（槽）
void SerialCom::slot_readData()
{
    if(!m_serialCom->bytesAvailable())
        return;
    QByteArray bytesTemp = m_serialCom->readAll();
    //qDebug()<<bytesTemp;
    //return;
    m_serialBuff += bytesTemp;
    while(m_serialBuff.length() != 0)
    {
        bool bExist = false;
        unsigned char buff[] = {0x0D, 0x0A};
        int length = 0;
        while((length = m_serialBuff.indexOf(QByteArray((char*)buff,
                                                     sizeof(buff)/sizeof(char)))) >= 0)
        {
            bExist = true;
            QByteArray data = m_serialBuff.left(length);
            //std::cout<<data.toStdString()<<endl;
            // 将数据push_back进上行数据分析队列中
            gParseQueue.push_back(data);
            // 取出数据的同时，对缓冲区数据做删除处理
            m_serialBuff.remove(0, length+2);
        }
        if(!bExist)
            break;
    }
}

// 打开串口
bool SerialCom::openSerial(SERIAL_PORT& port)
{
    QRegExp rx("^COM\\d+");
    if(port.strPort.indexOf(rx) >= 0)
    {
        QString strPort = rx.cap();
        m_serialCom->setBaudRate(port.baudRate);
        m_serialCom->setDataBits(static_cast<QSerialPort::DataBits>(port.dataBits));
        m_serialCom->setFlowControl(static_cast<QSerialPort::FlowControl>(port.flowControl));
        m_serialCom->setParity(static_cast<QSerialPort::Parity>(port.parity));
        m_serialCom->setStopBits(static_cast<QSerialPort::StopBits>(port.stopBits));
        m_serialCom->setPortName(strPort);

        if(m_serialCom->open(QIODevice::ReadWrite))
        {
            // 清空残留数据
            m_serialCom->clear(QSerialPort::AllDirections);
            qDebug()<<tr("%0 打开成功！").arg(strPort);
            return true;

        }
        else
        {
            qDebug()<<tr("%0 打开失败！").arg(strPort);

        }
    }
    return false;
}

// 关闭串口
void SerialCom::closeSerial()
{
    if(m_serialCom->isOpen())
    {
        qDebug()<<tr("%0 关闭！").arg(m_serialCom->portName());
        m_serialCom->close();
    }
}

bool SerialCom::serialState()
{
    return m_serialCom->isOpen() ? true : false;
}

void SerialCom::slot_HandleError(QSerialPort::SerialPortError error)
{
    switch (error)
    {
    case QSerialPort::DeviceNotFoundError:
        qDebug("串口设备不存在");
        break;
    case QSerialPort::PermissionError:
        qDebug("串口设备已经被打开，或者在其他进程中请关闭串口设备或者其他进程。没有足够的权限请使用root/administrator权限");
        break;
    case QSerialPort::OpenError:
        qDebug("串口设备已经被打开");
        break;
    case QSerialPort::NotOpenError:
        qDebug("串口设备打开成功");
        break;
    case QSerialPort::WriteError:
        qDebug("串口写入数据错误");
        break;
    case QSerialPort::ReadError:
        qDebug("串口读取数据错误");
        break;
    case QSerialPort::ResourceError:
        {
            qDebug("IO错误,串口不可用,设备意外拔出");
        }
        break;
    case QSerialPort::TimeoutError:
        qDebug("串口延时错误");
        break;
    case QSerialPort::UnknownError:
        qDebug("串口未知的错误");
        break;
    default:
        break;
    }
}
