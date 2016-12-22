#ifndef __ICLIENTCENTER_H_INCLUDED
#define __ICLIENTCENTER_H_INCLUDED

#ifndef interface
#define interface struct
#endif

#include "IUpdateXmlPlist.h"

#include <QtCore/QVariant>

#include <QSystemTrayIcon>

interface IClientConfig
{
	void initValue(const QString& name, const QVariant& value);
	void setValue(const QString& name, const QVariant& value);
	QVariant getValue(const QString& name);
};

interface IClientCenter
{
	virtual ~IClientCenter();
	IUpdateXmlPlistTree* pUpdateXmlPlistClientTree;//客户端的数据
	IUpdateXmlPlistTree* pUpdateXmlPllistServerTree;//服务器的数据

	//! server
	QString ftpAddress;//ftp服务器路径
	unsigned int ftpPort;//ftp服务器端口

	//! client
	QString localRecipesDir;//本地补丁路径

	IClientConfig clientConfig;//本地的配置

	//! tray logger
	std::list<QString> logs;
	QSystemTrayIcon* pTrayIcon;
};

IClientCenter* createClientCenter();
IClientCenter* getClientCenter();
IUpdateXmlPlistTree* getUpdateXmlPlistClientTree();//取得客户端数据
IUpdateXmlPlistTree* newUpdateXmlPlistTree();//新建一个树，需要手动释放内存
IUpdateXmlPlistTree* getUpdateXmlPlistServerTree();//取得服务器数据
IClientConfig* getCConfig();//取得客户端配置

#endif