
//-------------------------------------------------
//
// Project created by QQ1977800361 2015-04-27T21:34:39
//
//-------------------------------------------------


#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QTimer>
#include <QDateTime>
#include <QtSerialPort/QtSerialPort>
#include "settingsdialog.h"



#include <QStringListModel>
#include <QStringList>

namespace Ui {
class Widget;
}

class SettingsDialog;



class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_TestpushButton_clicked();//测试按钮
    void timeUpDate();    //系统时间更新

    void on_SettingpushButton_clicked();

    void on_OpenpushButton_clicked();

    void on_SendpushButton_clicked();

    void String2Hex(QString str, QByteArray &senddata);//字符串转16进制

    void openSerialPort();

    void writeData(const QByteArray &data);  //写数据
    void readData();  //读数据
    void TimerUpdate_COM();  //串口读写超时定时处理




    void on_ReadpushButton_clicked();

    void on_ClosepushButton_clicked();



    //void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    QString mysystime;//系统时间显示文本
    QDateTime systime; //新建时间对象
    QTimer *timer;    //定时计刷新系统时间
    SettingsDialog *Settings;

    QSerialPort * MyCom;   //串口对象
    QString MyComName; //串口名
    //十六进制的转换
    QByteArray myHexdata;
    char ConvertHexChar(char ch);
     QTimer *myTimer2;  //计时器2

     QByteArray myData2; //读取串口数据并叠加数据是B型的

     QByteArray Readdata;//读取到的原始叠加后的数据

     QString myStringData1;  //第一次完整转换得到接收到的串口数据
          QString myStringData2;   //第二次整合后的String




};

#endif // WIDGET_H
