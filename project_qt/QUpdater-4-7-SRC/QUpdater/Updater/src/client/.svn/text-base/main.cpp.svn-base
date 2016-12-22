#include <QtGui>
#include "updaterclient.h"
#include "IClientCenter.h"
#include <QtCore>
#include <QtPlugin>
#include "WexTextCodecPlugin.h"
#include "ApplicationSington.h"

//! 自身修复
void repairapp()
{
	REPAIRSINGTON;
}

int main(int argc, char *argv[])
{
	//! 初始化显示
	QApplication a(argc, argv);

	//! 初始化基本数据
	createClientCenter();

	//! 自身修复
	if (argv[0] == "/r")
		repairapp();

	//! single application
	SINGTONTEST;

	//显示到tray
	if (!QSystemTrayIcon::isSystemTrayAvailable()) {
		QMessageBox::critical(0, QObject::tr("Systray"),QObject::tr("couldn't detect any system tray ""on this system."));
		return 1;
	}

	QTextCodec* localCode = WGetTextCodeForName("GB18030");
	QTextCodec::setCodecForCStrings(localCode);
	QString localstr = QLocale::system().name();

	//加载翻译文件
	QTranslator translator;
	translator.load(QString("updateclient_") + localstr, QString("./translations"));
	a.installTranslator(&translator);

	//启动时最小化
#ifdef _DEBUG
	//getCConfig()->setValue("StartMinimal", true);
#endif // _DEBUG
	bool startmin = getCConfig()->getValue("StartMinimal").toBool();
	UpdaterClient w;
	if (!startmin)//如果为true，说明不需要显示对话框
		w.show();

	a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
	
	//return a.exec();
	SINGTONEXEC(a);
}
