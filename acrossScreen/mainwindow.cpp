#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent * event)
{
    m_startPoint=event->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event )
{
    QPoint _curPoint=event->pos();
}

void MainWindow::mouseReleaseEvent(QMouseEvent * event)
{
    m_endPoint=event->pos();
    if(m_endPoint.x()>m_endPoint)
    {
        qDebug()<<"pre  page";
    }
    else
    {
        qDebug()<<"next page";
    }
}
