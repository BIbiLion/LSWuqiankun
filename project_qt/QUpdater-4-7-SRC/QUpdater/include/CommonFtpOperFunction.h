#ifndef _COMMONFTPOPERFUNCTION_H_INCLUDED
#define _COMMONFTPOPERFUNCTION_H_INCLUDED

#include "IUpdateXmlPlist.h"
#include <QtCore/QFile>
#include <QtGui/QMessageBox>
#include <QtNetwork/QFtp>

//ftp公共操作类
struct wFtpFunc 
{
	static void downloadFile(QFtp* opeFtp, REF QFile*& opeFile, const QString& filename, const QString& path = "")
	{
		absoluteDownloadFile(opeFtp, opeFile, filename, false, path);
	}

	static void downloadFileEx(QFtp* opeFtp, REF QFile*& opeFile, const QString& filename, const QString& path = "")
	{
		absoluteDownloadFile(opeFtp, opeFile, filename, true, path);
	}

	//简单下载一个文件的流程
	static void absoluteDownloadFile(QFtp* opeFtp, REF QFile*& opeFile, const QString& filename, bool exmode = false, const QString& path = "")
	{
		//必须保证opefile为空
		pubfunc::release(opeFile);

		//路径名不能为空
		if (filename.isEmpty())
			return;

		QString filepath(path + filename);

		pubfunc::release(opeFile);
		opeFile = new QFile(path + filename);
		bool opefileopenstatu = true;
		if ( QFile::exists(filepath) && exmode)
		{
			opefileopenstatu = opeFile->open(QIODevice::WriteOnly | QIODevice::Append);
			if (opefileopenstatu)
			{
				qint64 offset = opeFile->size();
				opeFtp->getex(filename, opeFile, offset);
				//opeFtp->get(filename, opeFile);
			}
		}
		else if (QFile::exists(filepath))
		{
			QFile::remove(filepath);
			if (opeFile->open(QIODevice::WriteOnly))
			{
				opeFtp->get(filename, opeFile);
			}
		}
		else
		{
			if (opeFile->open(QIODevice::WriteOnly))
			{
				opeFtp->get(filename, opeFile);
			}	
		}
	}

	//上传一个文件
	static bool uploadFile(QFtp* opeFtp, REF QFile*& opeFile, const QString& localefile, const QString& remotefile)
	{
		pubfunc::release(opeFile);
		if (!QFile::exists(localefile))
			return false;

		opeFile = new QFile(localefile);
		if (opeFile->open(QIODevice::ReadOnly))
		{
			opeFtp->put(opeFile, remotefile);
			return true;
		}
		return false;
	}
};


#endif