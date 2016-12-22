#include <QtGui/QApplication>
#include "updaterservermanager.h"
#include <QtCore>
#include <QtPlugin>
#include "WexTextCodecPlugin.h"
#include "IClientCenter.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	createClientCenter();
	QTextCodec* localCode = WGetTextCodeForName("GB18030");
	QTextCodec::setCodecForCStrings(localCode);
	QString localstr = QLocale::system().name();
	//¼ÓÔØ·­ÒëÎÄ¼þ
	QTranslator translator;
	translator.load(QString("updaterservermanager_") + localstr, QString("./translations"));
	a.installTranslator(&translator);

	UpdaterServerManager w;

	w.show();
	a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
	return a.exec();
}
