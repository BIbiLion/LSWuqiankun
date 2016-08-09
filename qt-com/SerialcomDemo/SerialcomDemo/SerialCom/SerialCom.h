#ifndef _SerialCom_H
#define _SerialCom_H
#include <QSerialPort>
#include <QStringList>

// 串口通信参数
typedef struct SerialPort
{
    int baudRate;
    int dataBits;
    int parity;
    int stopBits;
    int flowControl;
    QString strPort;
    // 默认初始的参数值
    inline SerialPort()
        : baudRate(QSerialPort::Baud115200),
        dataBits(QSerialPort::Data8),
        parity(QSerialPort::NoParity),
        stopBits(QSerialPort::OneStop),
        flowControl(QSerialPort::NoFlowControl){}
}SERIAL_PORT;

// 串口通信工作类
class SerialCom : public QObject
{
    Q_OBJECT
public:
    // 构造函数
    explicit SerialCom(QObject *parent = 0);
    // 析构函数
    virtual ~SerialCom();

private:
    // 信号槽连接
    void initConnect();
public:
    bool openSerial(SERIAL_PORT& port);
    void closeSerial();
    bool serialState();

signals:

private slots:
    void slot_readData();
    void slot_HandleError(QSerialPort::SerialPortError error);

private:
    // 串口通信对象
    QSerialPort *m_serialCom;
    // 串口数据缓冲区
    QByteArray m_serialBuff;
};

#endif
