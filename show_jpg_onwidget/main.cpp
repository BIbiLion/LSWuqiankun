#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QDebug>
#include <QTextCodec>

#include <QImage>
#include "imagewidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("system"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("system"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));
    //    QString s("ÖÐÎÄ");
    //    QTextCodec::codecForName("GBK")->fromUnicode(s);


    char g_appPath[260];
    QString exePath= QCoreApplication::applicationDirPath();
    if (exePath=="")
    {

    }
    exePath.replace("/","\\");
    if (exePath!="\\")
    {
        exePath+="\\";
    }
    qDebug()<<"----------"<<exePath<<"\n"<<exePath.toAscii();
    strncpy(g_appPath,exePath.toAscii().data(),260);
    //strncpy(g_appPath,exePath.toAscii().data(),260);
    //strncpy(g_appPath,exePath.toLocal8Bit().data(),260);
    //strncpy(g_appPath,exePath.toStdString().c_str(),260);
    qDebug()<<g_appPath;
    qDebug()<<"-----------------------------";

    QImage _image("F:\wuqiankn\test\winter.jpg");
    uchar * det=_image.bits();



    MainWindow w;
    w.show();

    ImageWidget imW;
    imW.show();
    return a.exec();
}
