
/*author:
 * yongwangzhiqian
 * qingyunfeiyang
 *
 */
#include <QApplication>
#include "frmmain.h"

#include <QTextCodec>
#include <QDesktopWidget>
#include <QStyleFactory>
#include <QStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //֧�����ı���
    QTextCodec *codec=QTextCodec::codecForLocale();
    QTextCodec::setCodecForLocale(codec);
   // QTextCodec::setCodecForCStrings(codec);
    //QTextCodec::setCodecForTr(codec);

    //���������ʾ
    QDesktopWidget *desktop=QApplication::desktop();
    int width=desktop->width();
    int height=desktop->height();

    frmMain w;
    //���ô���û����󻯰�ť
    w.setWindowFlags(Qt::WindowMinimizeButtonHint);
    w.move((width-w.width())/2,(height-w.height())/2);
    w.setFixedSize(w.width(),w.height());
    w.show();
    //Ӧ����ʽ
    QApplication::setStyle(QStyleFactory::create("Plastique"));
    QApplication::setPalette(QApplication::style()->standardPalette());

    return a.exec();
}