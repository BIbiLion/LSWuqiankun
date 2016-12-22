#include <QString>
#include "ClientCenter.h"
#include "pubfuncs.h"
#include "UpdateXmlPlist.h"
#include "dataFromFile.h"
#include <QtGui/QMessageBox>
#include <QtCore/QSettings>

CClientCenter __g_clientcenter;

IClientCenter::~IClientCenter()
{
	pubfunc::release(__g_clientcenter.pUpdateXmlPlistClientTree);
	pubfunc::release(__g_clientcenter.pUpdateXmlPllistServerTree);
}

IClientCenter* createClientCenter()
{
	__g_clientcenter.pUpdateXmlPlistClientTree = new CUpdateXmlPlistTree();
	__g_clientcenter.pUpdateXmlPllistServerTree = new CUpdateXmlPlistTree();

	//__g_clientcenter.ftpAddress = QString("192.168.0.116");
	dataFromFile::FtpConfig ftpconfig;
	if (!dataFromFile::loadFtpConfig(ftpconfig))
	{
		//QMessageBox::critical(0, QString(QObject::tr("STOP")), QString(QObject::tr("LOSTCONFIGFILE")));
	}
	__g_clientcenter.ftpAddress = ftpconfig.address;
	__g_clientcenter.ftpPort = ftpconfig.port;

	__g_clientcenter.localRecipesDir = "./_recipes";

	//默认的参数
#ifdef _DEBUG
#define DefaultAutoRefreshTime 10000
#else
#define DefaultAutoRefreshTime 1800000
#endif // _DEBUG
	getCConfig()->initValue("DefaultAutoRefreshTime", DefaultAutoRefreshTime);
	getCConfig()->initValue("AutoRefresh", true);
	getCConfig()->initValue("AutoDownload", false);
	getCConfig()->initValue("AutoInstall", false);
	getCConfig()->initValue("StartMinimal", true);

	return &__g_clientcenter;
}

IClientCenter* getClientCenter()
{
	return &__g_clientcenter;
}

IUpdateXmlPlistTree* getUpdateXmlPlistClientTree()
{
	return __g_clientcenter.pUpdateXmlPlistClientTree;
}

IUpdateXmlPlistTree* newUpdateXmlPlistTree()
{
	return new CUpdateXmlPlistTree();
}

IUpdateXmlPlistTree* getUpdateXmlPlistServerTree()
{
	return __g_clientcenter.pUpdateXmlPllistServerTree;
}

IClientConfig* getCConfig()
{
	return &getClientCenter()->clientConfig;
}

QVariant IClientConfig::getValue(const QString& name)
{
	QSettings readSettings("QUpdaterClient", "ClientConfig");
	return readSettings.value(name);
}

void IClientConfig::setValue(const QString& name, const QVariant& value)
{
	QSettings saveSettings("QUpdaterClient", "ClientConfig");
	saveSettings.setValue(name, value);
}

void IClientConfig::initValue(const QString& name, const QVariant& value)
{
	QSettings saveSettings("QUpdaterClient", "ClientConfig");
	QVariant& vdata = saveSettings.value(name, value);
	saveSettings.setValue(name, vdata);
}