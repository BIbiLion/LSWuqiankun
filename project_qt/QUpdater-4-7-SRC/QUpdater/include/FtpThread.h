#ifndef __FTPTHREAD_H_INCLUDED
#define __FTPTHREAD_H_INCLUDED

#include <QtCore/QThread>
#include <vector>
#include <QUrlInfo>

class QFtp;
class QFile;

struct wFtpParam 
{
	wFtpParam()
	{
		port = 21;
	}
	QString address;//地址
	quint16 port;//端口
	QString usr;//用户名
	QString pwd;//密码

	bool isvalid() const//判断是否可用
	{
		return !address.isEmpty() && !usr.isEmpty() && !pwd.isEmpty();
	}
};

struct wFtpState
{
	wFtpState()
	{
		connected = logined = downloading = alldownloaded = uploading = false;
	}

	bool connected, logined, downloading, alldownloaded, uploading;

	bool hasError()
	{
		bool suc = connected && logined;
		return !suc;
	}
};

//FTP操作子
class wFtpOperator : public QObject
{
	Q_OBJECT
public:
	//默认调用 startThread
	wFtpOperator(const wFtpParam& mparam, QObject* parent = 0);

	//根据destoryrun决定是否运行ftp操作
	virtual ~wFtpOperator();

public:
	void ProcOperations();

public:
	void intodirectory(const QString&);
	void download(const QString& pathServer, const QString& directoryClient);
	void upload(const QString& pathClient, const QString& pathServer);
	void createdirectory(const QString& dir);
	void renamefile(const QString& oldname, const QString& newname);
	void renamedirectory(const QString& oldname, const QString& newname);
	void removefile(const QString& filename);
	void removedirectory(const QString& dir);
	void listdirectory(const QString& dir);

	inline bool hasError() {return opeState.hasError();}

protected:
	void start();
	void packSlots();//装配信号量

protected slots:
	void on_ftp_command_started(int id);
	void on_ftp_command_finished(int id, bool error);
	void on_ftp_transfer_progress(qint64, qint64);
	void on_ftp_listinfo(const QUrlInfo& i);

signals:
	void transferProgress(qint64 size, qint64 total);
	void filetransferFinished(bool mode);
	void allCommandsFinished();//所有命令执行完毕

protected:
	const wFtpParam opeParam;
	QFile* opeFile;
	QFtp* opeFtp;
	wFtpState opeState;
	
	void addCommand(const QString&);
	void insertCommand(const QString&);
	std::pair<bool, QString> popLastCommand();
	std::vector<QString> mCommands;
	bool invokeLastCommand();//返回false则意味着全部命令执行完毕

private:
	wFtpOperator(QObject*) {}
};

#endif