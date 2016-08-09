#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPainter>
#include "imagewidget.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    QPainter painter;
    //    QPen pen;
    //    pen.setColor(QColor(255,0,0));  //���û���Ϊ��ɫ
    //    painter.setPen(pen);  //ѡ�񻭱�
    //    painter.drawLine(0,0,100,100); //�øú�ɫ���ʻ�һ���ߣ����(0,0)���յ�(100,100)
    //    painter.end(); //�������ơ�����ʱʹ�õ��κ���Դ�����ͷš���Ȼ��ʱ����Ҫ����end()��������������ִ����
    ImageWidget * _imagewidget= new ImageWidget();
    this->setCentralWidget(_imagewidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{

}
