#include <QtGui/QApplication>
#include "myserialport.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

	MySerialPort *w = new  MySerialPort(NULL, Qt::WindowMinimizeButtonHint);
	w->show();

	return a.exec();
}
