//main file
#include <QApplication>
#include <QMainWindow>
#include "mainwindow.h"
#include "MyIpAddrEdit.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow mainwindow;
    mainwindow.setFixedSize(300, 200);
    CIPLineEdit *pIPLineEdit = new CIPLineEdit(&mainwindow);
    pIPLineEdit->setGeometry(50, 50, 120, 26);
    mainwindow.show();
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));





    MyIpAddrEdit *ipAddr = new MyIpAddrEdit();
    ipAddr->settext("127.0.0.1");
    ipAddr->show();




    return a.exec();
}
