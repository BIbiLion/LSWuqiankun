#include "mainwindow.h"
#include "ui_mainwindow.h"

/*win_qextserialport.cpp文件中，我们看它的最后一个构造函数，会发现，串口可以在这里进行初始化。

PortSettings：
    BaudRateType BaudRate; //波特率类型
    DataBitsType DataBits; //数据位类型
    ParityType Parity;     //奇偶校验
    StopBitsType StopBits; //停止位设置
    FlowType FlowControl;  //数据流控制
    long Timeout_Millisec; //延时设置

  */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowTitle("read SerialPort ");
    ui->setupUi(this);

    //定义一个结构体，用来存放串口各个参数
    struct PortSettings myComSetting = {BAUD9600,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,500};

    //定义串口对象，并传递参数，在构造函数里对其进行初始化
    myCom= new Win_QextSerialPort("com1",myComSetting,QextSerialBase::EventDriven);

    //以可读写方式打开串口
    myCom ->open(QIODevice::ReadWrite);

    //信号和槽函数关联，当串口缓冲区有数据时，进行读串口操作
    connect(myCom,SIGNAL(readyRead()),this,SLOT(readMyCom()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readMyCom()
{
    QByteArray _tmp=myCom->readAll();
    ui->textBrowser->insertPlainText(_tmp);
}
