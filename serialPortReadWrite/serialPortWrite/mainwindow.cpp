#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "win_qextserialport.h"

/*
  д���ڳ���ʱ��Ҫ�ȴ򿪴����ٶ����������ã���Ȼ���þͲ��������á����ԣ�����Ӧ��˵������һ���͵ڶ��������ǲ�̫��ȷ�ģ���ȷ�ķ���Ӧ���������������һ����
�ȶ���Win_QextSerialPort�����Ȼ��򿪴��ڣ������Ǽ������ú����Դ��ڽ������á�
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
    //����һ���ṹ�壬������Ŵ��ڸ�������
    struct PortSettings myComSetting = {BAUD9600,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,500};

    //���崮�ڶ��󣬲����ݲ������ڹ��캯���������г�ʼ��,//this set is not work.
    myCom= new Win_QextSerialPort("com1",myComSetting,QextSerialBase::EventDriven);

    //it work in this;
    //myCom->setTimeout(500);

    //�Կɶ�д��ʽ�򿪴���
    myCom ->open(QIODevice::ReadWrite);

    //�źźͲۺ��������������ڻ�����������ʱ�����ж����ڲ���
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


