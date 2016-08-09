#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDataStream>
#include <QDebug>
#include <QFile>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(showNextPage()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(showPrePage()));
    connect(ui->pushButton_close,SIGNAL(clicked()),this,SLOT(close()));
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showNextPage()
{
    //ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}
void MainWindow::showPrePage()
{
    //ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget->setCurrentWidget(ui->page);
}
