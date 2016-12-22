#ifndef __INSTALLTHREAD_H_INCLUDED
#define __INSTALLTHREAD_H_INCLUDED

#include <QtCore/QThread>
#include <QtCore/QProcess>
#include "IUpdateXmlPlist.h"

//��������װ�߳�

class PacksInstallThread : public QThread
{
	Q_OBJECT

public:
	explicit PacksInstallThread(QObject* pParent = 0);
	~PacksInstallThread();

public:
	void installAllPacks(TMapReadyPacks&);//��װ���еĸ���

signals:
	void progressStep(QString packname, int filescount, int curindex);//��װ���ȵ��źţ������ļ�����������ǰ�ļ��ı��
	void installed();//���а�װ�������ź�
	void packInstallStart();//��ʼ��װһ������
	void packInstallFinished();//һ��������װ����
	void selfUpdatePack();//����������
	void appMustBClosed(QString appname);//��Ҫ�رճ���

protected slots:
	void on_procPackInstalled(int exitCode, QProcess::ExitStatus exitStatus);//ÿһ����װ���̽���
	void on_procInstallPackReadyReadStandardOutput();//������װ��������

protected:
	virtual void run();

private:
	QProcess* procPackInstall;//��һ�İ�װ����
	int	 processCount;//��װ���̼�����
	std::list<IUpdatePack*> mPacks;//��װ�õ�pack��������

public:
	bool appshut;
};

#endif