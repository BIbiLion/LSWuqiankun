#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    float af=27.1234567;
   // qDebug()<<
  QString _str( QString("%1").arg((double)af,10,'g',11) );
  ui->lineEdit->setText(_str);



}

MainWindow::~MainWindow()
{
    delete ui;
}
