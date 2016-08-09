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
    //    pen.setColor(QColor(255,0,0));  //设置画笔为红色
    //    painter.setPen(pen);  //选择画笔
    //    painter.drawLine(0,0,100,100); //用该红色画笔画一条线，起点(0,0)，终点(100,100)
    //    painter.end(); //结束绘制。绘制时使用的任何资源都被释放。虽然有时不需要调用end()，析构函数将会执行它
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
