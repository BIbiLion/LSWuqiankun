#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QFile>
/*
QFile qssFile("D:\\Test\\qss.qss");/////////"D:\\Test\\qss.qss"/////////
qssFile.open(QFile::ReadOnly);
if(qssFile.isOpen())
{
    qss = QLatin1String(qssFile.readAll());
    qApp->setStyleSheet(qss);
    qssFile.close();
}
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
qDebug()<<QCoreApplication::applicationDirPath();

QString _qssFilePath=QCoreApplication::applicationDirPath()+"/"+"frame.qss";
 QFile _file(_qssFilePath);
_file.open(QFile::ReadOnly );

if(_file.isOpen())
{
    QString _str=QLatin1String(_file.readAll());
   qDebug()<<_str;
    qApp->setStyleSheet(_str);
    _file.close();
}

    w.show();

    return a.exec();
}
