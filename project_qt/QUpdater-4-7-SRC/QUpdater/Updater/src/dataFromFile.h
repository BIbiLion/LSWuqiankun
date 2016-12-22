#ifndef __DATAFROMFILE_H_INCLUDED
#define __DATAFROMFILE_H_INCLUDED

//#include <QtCore/QFileInfo>
#include <QtCore/QFile>
#include <QtCore/QStringList>
#include "PlatformFunctions.h"

static const QString ftpConfigFile = QString("./serverdata");
static const QString clientdataFilePath = QString("./datafile");

struct dataFromFile 
{
	static bool isConfigExist(const QString& filename)
	{
		return QFile::exists(filename);
	}

	//读取ftp配置
	struct FtpConfig
	{
		FtpConfig()
		{
			address = "192.168.0.116";
			port = 21;
		}
		QString address;//地址
		unsigned int port;//端口
	};


	static bool loadFtpConfig(FtpConfig& _config)
	{
		if (!isConfigExist(ftpConfigFile))
			return false;
		
		QFile xfile(ftpConfigFile);
		if (!xfile.open(QIODevice::ReadOnly))
			return false;

		QByteArray eachline;
		while (!xfile.atEnd())
		{
			eachline = xfile.readLine();
			QString eachlinestr(eachline);

			QStringList procstrs = eachlinestr.split(":");

			_config.address = procstrs[0];
			_config.port = procstrs[1].toUInt();
		}
		return true;
	}

	//取得客户端路径
	static bool loadClientDataFilePath(REF QString& path)
	{
		if (!isConfigExist(clientdataFilePath))
			return false;

		QFile xfile(clientdataFilePath);
		if (!xfile.open(QIODevice::ReadOnly))
			return false;

		QByteArray eachline;
		eachline = xfile.readLine();
		QString filenvir(eachline);
		eachline = xfile.readLine();
		QString valuename(eachline);
		return platfunc::getRegValue(filenvir, valuename, path);
	}

};

#endif