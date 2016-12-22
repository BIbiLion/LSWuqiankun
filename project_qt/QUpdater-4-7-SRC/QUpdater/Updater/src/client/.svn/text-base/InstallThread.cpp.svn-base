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
	//遍历所有的pack，安装
	std::list<IUpdatePack*>::iterator iterPack = mPacks.begin();
	while (iterPack != mPacks.end())
	{
		const IUpdatePack* pPack = *iterPack;

		//先查找该文件，如果该补丁文件存在，则开始安装进程
		//补丁包的路径
		QString exestr = QString("./_recipes/%1/%2").arg(pPack->softname).arg(pPack->packName);
		//exestr = "E:\\暂存\\testConCout\\Debug\\testConCout.exe";
		QFileInfo fileinfo(exestr);
		if (fileinfo.exists() && pPack->needdownload)//必须属于已经下载的并且是需要下载的才能安装
		{
			//如果补丁包存在

			//新建一个安装进程
			procPackInstall = new QProcess(this);
			procPackInstall->setProcessChannelMode(QProcess::MergedChannels);
			procPackInstall->setReadChannel(QProcess::StandardOutput);
			//绑定信号量
			connect(procPackInstall, SIGNAL(finished(int, QProcess::ExitStatus)),
				this, SLOT(on_procPackInstalled(int, QProcess::ExitStatus)));
			connect(procPackInstall, SIGNAL(readyReadStandardOutput()),
				this, SLOT(on_procInstallPackReadyReadStandardOutput()));

			//判断该更新软件是否正在运行
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

			emit packInstallStart();//开始安装一个更新
			curPackName = pPack->name;

			QStringList argus;
			//如果不需要UI，则加上slient参数
			if (!pPack->needUiShow)
			{
				argus << "/S";//安装参数
			}
			procPackInstall->start(exestr, argus);
			if (pPack->isSelfUpdate)
			{
				//暂时先利用通过NSIS脚本里放入一个函数的方式实现
				//此函数中实现通过kill本身进城pid的方式，关闭主窗口
				//emit selfUpdatePack();//自身升级包信号，需要关闭updaterclient程序
				//获得该进城的PID
				wDWORD currentPid = platfunc::getCurrentProcessId();

				//将当前进程的pid写到自更新程序
				//该程序会自动结束掉主进程，以实现升级自身的目的
				procPackInstall->write(QByteArray::number((qlonglong)currentPid) + "\r\n");
			}

			while ( !procPackInstall->waitForFinished() )
			{
				sleep(1);
			}
			pubfunc::release(procPackInstall);
		}

		emit installed();//全部安装完成

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

	//对readyPacks进行排序，按照发布时间
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
		//错误退出
		break;
	}
}

void PacksInstallThread::on_procInstallPackReadyReadStandardOutput()
{
	QByteArray reByte = procPackInstall->readAll();
	if (reByte.isEmpty())
		return;

	QString readOutStr(reByte);
	// @文件总数#当前已完成@
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