#ifndef SERIALPORTOBJECT_H
#define SERIALPORTOBJECT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include "serialattri.h"
class SerialPortObject : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortObject(SerialAttri &serialPortAttr, QObject *parent = 0);
    ~SerialPortObject();
signals:
    void sendComRev(QByteArray  _byteArray);
public slots:
    void close();
    void initSerialPort(SerialAttri &serialPortAttr);
    void dispalySerialPort();
    void reveiveData();
    //void writeDate(QString  writeDate);
    void writeDate(const char *data, qint64 len);

    void write(const char *data, qint64 len);
    void errorDispaly(QSerialPort::SerialPortError);


    void changePortName(const QString &);
    void changeBrauRate(const QString &);
    void changeDataBits(const QString &);
    void changeParity(const QString &);
    void changeStopBits(const QString &);


    void BanudRateChangeSlot(qint32,QSerialPort::Directions=QSerialPort::AllDirections);
    void dataBitsChangedSlot(QSerialPort::DataBits);
    void parityChangedSlot(QSerialPort::Parity);
    void stopBitsChangedSlot(QSerialPort::StopBits);
    void flowControlChangedSlot(QSerialPort::FlowControl);

private :
public:

    QSerialPort * m_serialPort;
    //SerialAttri m_serialPortAttr;
};

#endif // SERIALPORTOBJECT_H
