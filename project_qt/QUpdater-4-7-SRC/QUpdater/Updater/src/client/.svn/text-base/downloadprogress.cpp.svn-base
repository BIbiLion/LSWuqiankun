#include "downloadprogress.h"
#include <QtCore/QFile>
#include <QtCore/QFileInfo>
#include <QtCore/QDir>
#include <QtGui/QMessageBox>
#include "pubfuncs.h"
#include "CommonFtpOperFunction.h"
#include "IClientCenter.h"
#include "../dataFromFile.h"

#define CLIENTFILENAME "recipe.plist"
#define SERVERFILENAME "server.plist"

DownloadProgress::DownloadProgress(QWidget *parent)
	: QDialog(parent), wWindowPos(this, WidgetWidth, WidgetHeigth),
	opeFile(0),
	opeFtp(0),
	sucess(false)
{
	ui.setupUi(this);

	ui.progressBar->setValue(0);
	ui.progressBar->setRange(0, 0);

	processClient2Server();
}

DownloadProgress::~DownloadProgress()
{
	pubfunc::release(opeFtp);
	pubfunc::release(opeFile);
}

void DownloadProgress::processClient2Server()
{
	/*ftp操作
	顺序
	1，打开ftp链接，192.116.0.99
	2，登陆 usr：Client	psw：Client
	3，成功后，在当前目录下建立一个名为"recipes"的目录，下载server.plist
	4，关闭链接
	*/
	pubfunc::release(opeFtp);
	opeFtp = new QFtp();
	//绑定信号
	connect(opeFtp, SIGNAL(commandFinished(int, bool)),
				this, SLOT(ftpCommandFinished(int, bool)));

	//链接服务器
	opeFtp->connectToHost(getClientCenter()->ftpAddress, getClientCenter()->ftpPort);

	//登陆服务器
	opeFtp->login("Client", "Client");
	
	//建立一个 recipes 目录
	QDir dirRecipes("./");
	if (!dirRecipes.exists("./_recipes"))
	{
		dirRecipes.mkdir("_recipes");
	}
}

void DownloadProgress::ftpCommandFinished(int id, bool error)
{
	//连接前预判断
	switch (opeFtp->currentCommand())
	{
	case QFtp::ConnectToHost:
	case QFtp::Login:
		{
			if (error)
			{
#ifdef _DEBUG
				QMessageBox temStopMsg;
				temStopMsg.setText(opeFtp->errorString());
				temStopMsg.exec();
#else
				getClientCenter()->logs.push_back(tr("lost server"));
				getClientCenter()->pTrayIcon->setIcon(QIcon(":/lost.png"));
#endif
				this->close();
				return;
			}
		}
		break;
	case QFtp::Get:
		{
			//下载成功
			opeFile->close();
			if (error)
				opeFile->remove();

			//关闭服务器链接
			opeFtp->close();

			//关闭当前对话框
			this->close();

			if (!error)
				processXml();
		}
	}

	switch (opeFtp->currentCommand())
	{
	case QFtp::Login:
		{
			if (opeFtp->state() == QFtp::LoggedIn)
			{
				//登陆成功，可以开始下载文件了
				wFtpFunc::downloadFile(opeFtp, opeFile, "server.plist", ".\\_recipes\\");
			}
		}
		break;
	}
}

void DownloadProgress::processXml()
{
	//之前的步骤已经确定当前的server.plist一定是最新的

	QString serverXmlPath (getClientCenter()->localRecipesDir + "/server.plist");

	//取得客户端文件路径
	QString clientXmlPath;// ("./recipe.plist");

#ifdef _DEBUG
	if (!dataFromFile::loadClientDataFilePath(clientXmlPath))
	{
		clientXmlPath = "./recipe.plist";//测试用，仅在无法找到配置文件时使用
	}
#else
	if (!dataFromFile::loadClientDataFilePath(clientXmlPath))
	{
		getClientCenter()->logs.push_back(tr("CLIENTFILELOST"));
		getClientCenter()->pTrayIcon->setIcon(QIcon(":/lost.png"));
		return;
	}
#endif

	bool xmlloadsuc = true;

	IUpdateXmlPlistTree* ptreeClient = getUpdateXmlPlistClientTree();//取得客户端的数据结构
	if (!ptreeClient->loadFromPlist(clientXmlPath))
		xmlloadsuc = false;//读取数据失败

	IUpdateXmlPlistTree* ptreeServer = getUpdateXmlPlistServerTree();//新建服务器的数据结构
	if (!ptreeServer->loadFromPlist(serverXmlPath))//读取服务器的数据
		xmlloadsuc = false;

	//移除文件
	QFile::remove(serverXmlPath);

	if (!xmlloadsuc)
	{
		getClientCenter()->logs.push_back(tr("XMLReadFailed"));
		getClientCenter()->pTrayIcon->setIcon(QIcon(":/lost.png"));
		return;
	}

	//差异计算
	ptreeClient->calcClientNeedUpdate(ptreeServer);

	//
	sucess = true;
}