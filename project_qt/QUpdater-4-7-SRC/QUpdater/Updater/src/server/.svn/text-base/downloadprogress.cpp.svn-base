#include "downloadprogress.h"
#include <QtCore/QFile>
#include <QtCore/QFileInfo>
#include <QtCore/QDir>
#include <QtGui/QMessageBox>
#include "pubfuncs.h"
#include "CommonFtpOperFunction.h"
#include "IClientCenter.h"

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
	opeFtp->login("Manager", "Manager");
	
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
				QMessageBox temStopMsg;
				temStopMsg.setText(opeFtp->errorString());
				temStopMsg.exec();
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

	bool xmlloadsuc = true;

	//IUpdateXmlPlistTree* ptreeClient = getUpdateXmlPlistClientTree();//取得客户端的数据结构
	//if (!ptreeClient->loadFromPlist(clientXmlPath))
	//	xmlloadsuc = false;//读取数据失败

	IUpdateXmlPlistTree* ptreeServer = getUpdateXmlPlistServerTree();//新建服务器的数据结构
	if (!ptreeServer->loadFromPlist(serverXmlPath))//读取服务器的数据
		xmlloadsuc = false;

	if (!xmlloadsuc)
	{
		QMessageBox msgBox;
		msgBox.setText(tr("XMLReadFailed"));
		msgBox.exec();
		return;
	}

	sucess = true;
}