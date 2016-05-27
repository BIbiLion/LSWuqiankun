#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "win_qextserialport.h"

/*
  写串口程序时，要先打开串口再对它进行设置，不然设置就不会起作用。所以，这里应该说明，第一个和第二个程序都是不太正确的，正确的方法应该是像第三个程序一样，
先定义Win_QextSerialPort类对象，然后打开串口，再用那几个设置函数对串口进行设置。
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowTitle("write SerialPort ");
    ui->setupUi(this);
    ui->closeComBtn->setEnabled(false);
    ui->sendMesBtn->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_opencComBtn_clicked()
{
    //定义一个结构体，用来存放串口各个参数
    struct PortSettings myComSetting = {BAUD9600,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,500};

    //定义串口对象，并传递参数，在构造函数里对其进行初始化,//this set is not work.
    myCom= new Win_QextSerialPort("com1",myComSetting,QextSerialBase::EventDriven);

    //it work in this;
    //myCom->setTimeout(500);

    //以可读写方式打开串口
    myCom ->open(QIODevice::ReadWrite);

    //信号和槽函数关联，当串口缓冲区有数据时，进行读串口操作
    connect(myCom,SIGNAL(readyRead()),this,SLOT(readMyCom()));

    ui->opencComBtn->setEnabled(false);
    ui->closeComBtn->setEnabled(true);
    ui->sendMesBtn->setEnabled(true);
}

void MainWindow::on_closeComBtn_clicked()
{
    myCom->close();

    ui->opencComBtn->setEnabled(true);
    ui->closeComBtn->setEnabled(false);
    ui->sendMesBtn->setEnabled(false);

}

void MainWindow::on_sendMesBtn_clicked()
{
    myCom->write(ui->sendMeslineEdit->text().toAscii());
}

void MainWindow::readMyCom()
{
  ui->textBrowser->insertPlainText(myCom->readAll());
}


