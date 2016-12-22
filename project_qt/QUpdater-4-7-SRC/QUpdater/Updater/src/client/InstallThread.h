#ifndef __INSTALLTHREAD_H_INCLUDED
#define __INSTALLTHREAD_H_INCLUDED

#include <QtCore/QThread>
#include <QtCore/QProcess>
#include "IUpdateXmlPlist.h"

//补丁包安装线程

class PacksInstallThread : public QThread
{
	Q_OBJECT

public:
	explicit PacksInstallThread(QObject* pParent = 0);
	~PacksInstallThread();

public:
	void installAllPacks(TMapReadyPacks&);//安装所有的更新

signals:
	void progressStep(QString packname, int filescount, int curindex);//安装进度的信号，所有文件的数量、当前文件的标号
	void installed();//所有安装结束的信号
	void packInstallStart();//开始安装一个补丁
	void packInstallFinished();//一个补丁安装结束
	void selfUpdatePack();//自身升级包
	void appMustBClosed(QString appname);//需要关闭程序

protected slots:
	void on_procPackInstalled(int exitCode, QProcess::ExitStatus exitStatus);//每一个安装进程结束
	void on_procInstallPackReadyReadStandardOutput();//监听安装进程数据

protected:
	virtual void run();

private:
	QProcess* procPackInstall;//单一的安装进程
	int	 processCount;//安装进程计数器
	std::list<IUpdatePack*> mPacks;//安装用的pack数据链表

public:
	bool appshut;
};

#endif