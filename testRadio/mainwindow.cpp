#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QPixmap>
#include <QDesktopWidget>
#include <QScreen>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(19);
    //ui->lcdNumber->setSegmentStyle(QLCDNumber::Outline);
    ui->lcdNumber->display(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

