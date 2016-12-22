#include "InstallThread.h"
#include <QtCore/QFileInfo>
#include <QMessageBox>
#include "pubfuncs.h"
#include "PlatformFunctions.h"
#include "IUpdateXmlPlist.h"
#include <algorithm>

PacksInstallThread::PacksInstallThread(QObject* pParent)
: QThread(pParent),
	procPackInstall(0),
	processCount(0),
	appshut(false)
{

}

PacksInstallThread::~PacksInstallThread()
{
	QThread::wait();
	pubfunc::release(procPackInstall);
}

static QString curPackName;
void PacksInstallThread::run()
{
	//�������е�pack����װ
	std::list<IUpdatePack*>::iterator iterPack = mPacks.begin();
	while (iterPack != mPacks.end())
	{
		const IUpdatePack* pPack = *iterPack;

		//�Ȳ��Ҹ��ļ�������ò����ļ����ڣ���ʼ��װ����
		//��������·��
		QString exestr = QString("./_recipes/%1/%2").arg(pPack->softname).arg(pPack->packName);
		//exestr = "E:\\�ݴ�\\testConCout\\Debug\\testConCout.exe";
		QFileInfo fileinfo(exestr);
		if (fileinfo.exists() && pPack->needdownload)//���������Ѿ����صĲ�������Ҫ���صĲ��ܰ�װ
		{
			//�������������

			//�½�һ����װ����
			procPackInstall = new QProcess(this);
			procPackInstall->setProcessChannelMode(QProcess::MergedChannels);
			procPackInstall->setReadChannel(QProcess::StandardOutput);
			//���ź���
			connect(procPackInstall, SIGNAL(finished(int, QProcess::ExitStatus)),
				this, SLOT(on_procPackInstalled(int, QProcess::ExitStatus)));
			connect(procPackInstall, SIGNAL(readyReadStandardOutput()),
				this, SLOT(on_procInstallPackReadyReadStandardOutput()));

			//�жϸø�������Ƿ���������
#ifdef _UNICODE
			while (!platfunc::mutexCreate(pPack->softname.toStdWString()))
#else
			while (!platfunc::mutexCreate(pPack->softname.toStdString()))
#endif
			{
				//QMessageBox::warning(0, tr("warning"), tr("please close the app ") + pPack->softname);
				emit appMustBClosed(pPack->softname);
				appshut = false;
				
				while (!appshut)
				{
				}
			}

			emit packInstallStart();//��ʼ��װһ������
			curPackName = pPack->name;

			QStringList argus;
			//�������ҪUI�������slient����
			if (!pPack->needUiShow)
			{
				argus << "/S";//��װ����
			}
			procPackInstall->start(exestr, argus);
			if (pPack->isSelfUpdate)
			{
				//��ʱ������ͨ��NSIS�ű������һ�������ķ�ʽʵ��
				//�˺�����ʵ��ͨ��kill�������pid�ķ�ʽ���ر�������
				//emit selfUpdatePack();//�����������źţ���Ҫ�ر�updaterclient����
				//��øý��ǵ�PID
				wDWORD currentPid = platfunc::getCurrentProcessId();

				//����ǰ���̵�pidд���Ը��³���
				//�ó�����Զ������������̣���ʵ�����������Ŀ��
				procPackInstall->write(QByteArray::number((qlonglong)currentPid) + "\r\n");
			}

			while ( !procPackInstall->waitForFinished() )
			{
				sleep(1);
			}
			pubfunc::release(procPackInstall);
		}

		emit installed();//ȫ����װ���

		++iterPack;
	}
}

struct stdSortComp
{
	static inline bool MapPackLess(const IUpdatePack* packA, const IUpdatePack* packB)
	{
		return packA->publishTime < packB->publishTime;
	}
};

void PacksInstallThread::installAllPacks(TMapReadyPacks& readyPacks)
{
	processCount = 0;

	mPacks.clear();
	TIterMapReadyPack iterPack = readyPacks.begin();
	while (iterPack != readyPacks.end())
	{
		mPacks.push_back(iterPack->second);
		++iterPack;
	}

	//��readyPacks�������򣬰��շ���ʱ��
	std::stable_sort(mPacks.begin(), mPacks.end(), &stdSortComp::MapPackLess);

	if (!QThread::isRunning())
	{
		QThread::start();
	}
}

void PacksInstallThread::on_procPackInstalled(int exitCode, QProcess::ExitStatus exitStatus)
{
	emit packInstallFinished();
	switch (exitStatus)
	{
	case QProcess::CrashExit:
		//�����˳�
		break;
	}
}

void PacksInstallThread::on_procInstallPackReadyReadStandardOutput()
{
	QByteArray reByte = procPackInstall->readAll();
	if (reByte.isEmpty())
		return;

	QString readOutStr(reByte);
	// @�ļ�����#��ǰ�����@
	QStringList readlist = readOutStr.split("@", QString::SkipEmptyParts);
	QStringList::iterator iterProgress = readlist.begin();
	while (iterProgress != readlist.end())
	{
		QString strProgress = *iterProgress;
		QStringList listSingle = strProgress.split("#", QString::SkipEmptyParts);
		if (listSingle.size() == 2 )
		{
			QString countFiles = listSingle.at(0);
			QString countCurFileIndex = listSingle.at(1);

			emit progressStep(curPackName, countFiles.toInt(), countCurFileIndex.toInt());
		}
		++iterProgress;
	}
}