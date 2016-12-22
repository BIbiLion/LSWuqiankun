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
	/*ftp����
	˳��
	1����ftp���ӣ�192.116.0.99
	2����½ usr��Client	psw��Client
	3���ɹ����ڵ�ǰĿ¼�½���һ����Ϊ"recipes"��Ŀ¼������server.plist
	4���ر�����
	*/
	pubfunc::release(opeFtp);
	opeFtp = new QFtp();
	//���ź�
	connect(opeFtp, SIGNAL(commandFinished(int, bool)),
				this, SLOT(ftpCommandFinished(int, bool)));

	//���ӷ�����
	opeFtp->connectToHost(getClientCenter()->ftpAddress, getClientCenter()->ftpPort);

	//��½������
	opeFtp->login("Client", "Client");
	
	//����һ�� recipes Ŀ¼
	QDir dirRecipes("./");
	if (!dirRecipes.exists("./_recipes"))
	{
		dirRecipes.mkdir("_recipes");
	}
}

void DownloadProgress::ftpCommandFinished(int id, bool error)
{
	//����ǰԤ�ж�
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
			//���سɹ�
			opeFile->close();
			if (error)
				opeFile->remove();

			//�رշ���������
			opeFtp->close();

			//�رյ�ǰ�Ի���
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
				//��½�ɹ������Կ�ʼ�����ļ���
				wFtpFunc::downloadFile(opeFtp, opeFile, "server.plist", ".\\_recipes\\");
			}
		}
		break;
	}
}

void DownloadProgress::processXml()
{
	//֮ǰ�Ĳ����Ѿ�ȷ����ǰ��server.plistһ�������µ�

	QString serverXmlPath (getClientCenter()->localRecipesDir + "/server.plist");

	//ȡ�ÿͻ����ļ�·��
	QString clientXmlPath;// ("./recipe.plist");

#ifdef _DEBUG
	if (!dataFromFile::loadClientDataFilePath(clientXmlPath))
	{
		clientXmlPath = "./recipe.plist";//�����ã������޷��ҵ������ļ�ʱʹ��
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

	IUpdateXmlPlistTree* ptreeClient = getUpdateXmlPlistClientTree();//ȡ�ÿͻ��˵����ݽṹ
	if (!ptreeClient->loadFromPlist(clientXmlPath))
		xmlloadsuc = false;//��ȡ����ʧ��

	IUpdateXmlPlistTree* ptreeServer = getUpdateXmlPlistServerTree();//�½������������ݽṹ
	if (!ptreeServer->loadFromPlist(serverXmlPath))//��ȡ������������
		xmlloadsuc = false;

	//�Ƴ��ļ�
	QFile::remove(serverXmlPath);

	if (!xmlloadsuc)
	{
		getClientCenter()->logs.push_back(tr("XMLReadFailed"));
		getClientCenter()->pTrayIcon->setIcon(QIcon(":/lost.png"));
		return;
	}

	//�������
	ptreeClient->calcClientNeedUpdate(ptreeServer);

	//
	sucess = true;
}