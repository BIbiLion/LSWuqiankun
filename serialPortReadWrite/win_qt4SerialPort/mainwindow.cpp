#include "mainwindow.h"
#include "ui_mainwindow.h"

/*win_qextserialport.cpp�ļ��У����ǿ��������һ�����캯�����ᷢ�֣����ڿ�����������г�ʼ����

PortSettings��
    BaudRateType BaudRate; //����������
    DataBitsType DataBits; //����λ����
    ParityType Parity;     //��żУ��
    StopBitsType StopBits; //ֹͣλ����
    FlowType FlowControl;  //����������
    long Timeout_Millisec; //��ʱ����

  */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowTitle("read SerialPort ");
    ui->setupUi(this);

    //����һ���ṹ�壬������Ŵ��ڸ�������
    struct PortSettings myComSetting = {BAUD9600,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,500};

    //���崮�ڶ��󣬲����ݲ������ڹ��캯���������г�ʼ��
    myCom= new Win_QextSerialPort("com1",myComSetting,QextSerialBase::EventDriven);

    //�Կɶ�д��ʽ�򿪴���
    myCom ->open(QIODevice::ReadWrite);

    //�źźͲۺ��������������ڻ�����������ʱ�����ж����ڲ���
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
