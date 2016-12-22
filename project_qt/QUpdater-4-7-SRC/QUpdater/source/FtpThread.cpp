#include <QtNetwork/QFtp>
#include <QtCore>
#include "FtpThread.h"
#include "pubfuncs.h"
#include "CommonFtpOperFunction.h"

wFtpOperator::wFtpOperator(const wFtpParam& mparam, QObject* parent)
: QObject(parent),
	opeParam(mparam),
	opeFtp(0),
	opeFile(0)
{
	start();//Ĭ�������߳�
}

wFtpOperator::~wFtpOperator()
{
	pubfunc::release(opeFtp);
	pubfunc::release(opeFile);
}


void wFtpOperator::start()
{
	pubfunc::release(opeFtp);
	opeFtp = new QFtp();
	packSlots();

	opeFtp->connectToHost(opeParam.address, opeParam.port);
}

void wFtpOperator::packSlots()
{
	_ASSERT(opeFtp);

	connect(opeFtp, SIGNAL(commandFinished(int, bool)),
		this, SLOT(on_ftp_command_finished(int, bool)));
	connect(opeFtp, SIGNAL(dataTransferProgress(qint64, qint64)),
		this, SLOT(on_ftp_transfer_progress(qint64, qint64)));
	connect(opeFtp, SIGNAL(listInfo(const QUrlInfo&)),
		this, SLOT(on_ftp_listinfo(const QUrlInfo&)));
}

void wFtpOperator::on_ftp_transfer_progress(qint64 size, qint64 total)
{
	emit transferProgress(size, total);
}

void wFtpOperator::ProcOperations()
{
	invokeLastCommand();
}

//����Ŀ¼
void wFtpOperator::intodirectory(const QString& dir)
{	
	addCommand(QLatin1String("cd") + CMDSPLITER + dir);
}

//����
void wFtpOperator::download(const QString& pathServer, const QString& directoryClient)
{
	addCommand(QLatin1String("get") + CMDSPLITER + pathServer + CMDSPLITER + directoryClient);
}

//�ϴ�
void wFtpOperator::upload(const QString& pathClient, const QString& pathServer)
{
	addCommand(QLatin1String("put") + CMDSPLITER + pathClient + CMDSPLITER + pathServer);
}

//�½�Ŀ¼
void wFtpOperator::createdirectory(const QString& dir)
{
	addCommand(QLatin1String("mkdir") + CMDSPLITER + dir);
}

//����
void wFtpOperator::renamefile(const QString& oldname, const QString& newname)
{
	addCommand(QLatin1String("rename") + CMDSPLITER + oldname + CMDSPLITER + newname);
}
void wFtpOperator::renamedirectory(const QString& oldname, const QString& newname)
{
	renamefile(oldname, newname);
}

//�г�Ŀ¼
void wFtpOperator::listdirectory(const QString& dir)
{
	addCommand(QLatin1String("list") + CMDSPLITER + dir);
}

//ɾ��
void wFtpOperator::removefile(const QString& filename)
{
	addCommand(QLatin1String("del") + CMDSPLITER + filename);
}
void wFtpOperator::removedirectory(const QString& dir)
{
	//����Ŀ¼
	addCommand(QLatin1String("list") + CMDSPLITER + dir);

	//ɾ��Ŀ¼�µ��ļ�
	addCommand(QLatin1String("del *.*") + CMDSPLITER + dir);

	//��Ҫ����ɾ���������ϵ��ļ�
	addCommand(QLatin1String("rmdir") + CMDSPLITER + dir);
}

void wFtpOperator::addCommand(const QString& comstr)
{
	mCommands.push_back(comstr);
}

void wFtpOperator::insertCommand(const QString& comstr)
{
	mCommands.insert(mCommands.begin(), comstr);
}

std::pair<bool, QString> wFtpOperator::popLastCommand()
{
	if (!SIZE(mCommands))
	{
		emit allCommandsFinished();
		return std::make_pair(false, "");
	}

	QString comstr = mCommands[0];
	mCommands.erase(mCommands.begin());
	return std::make_pair(true, comstr);
}

std::list<const QUrlInfo> listinoflist;
void wFtpOperator::on_ftp_listinfo(const QUrlInfo& i)
{
	listinoflist.push_back(i);
}

bool wFtpOperator::invokeLastCommand()
{
	if (!opeState.logined) return false;

	std::pair<bool, QString> compair = popLastCommand();
	if (!compair.first) return false;

	QStringList commandlist = compair.second.split(CMDSPLITER, QString::SkipEmptyParts);
	if (!SIZE(commandlist)) return false;

	const QString cmd = commandlist.at(0);

	if (cmd == "cd")
	{
		opeFtp->cd(commandlist.at(1));//����Ŀ¼
	}
	else if (cmd == "mkdir")
	{
		opeFtp->mkdir(commandlist.at(1));
	}
	else if (cmd == "rename")
	{
		opeFtp->rename(commandlist.at(1), commandlist.at(2));
	}
	else if (cmd == "del")
	{
		opeFtp->remove(commandlist.at(1));
	}
	else if (cmd == "rmdir")
	{
		opeFtp->rmdir(commandlist.at(1));
	}
	else if (cmd == "list")
	{
		opeFtp->list(commandlist.at(1));
	}
	else if (cmd == "get")
	{
		opeState.downloading = true;
		pubfunc::release(opeFile);
		wFtpFunc::downloadFile(opeFtp, opeFile, commandlist.at(1), commandlist.at(2));
	}
	else if (cmd == "put")
	{
		opeState.uploading = true;
		pubfunc::release(opeFile);
		wFtpFunc::uploadFile(opeFtp, opeFile, commandlist.at(1), commandlist.at(2));
	}
	else if (cmd == "del *.*")
	{
		std::list<const QUrlInfo>::iterator iterUriInfo = listinoflist.begin();
		while (iterUriInfo != listinoflist.end())
		{
			const QUrlInfo& murl = *iterUriInfo;
			if (murl.isFile())
			{//�����������
				insertCommand(QLatin1String("rmdir") + CMDSPLITER + commandlist.at(1));
				insertCommand(QLatin1String("cd") + CMDSPLITER + QLatin1String("~"));
				insertCommand(QLatin1String("del") + CMDSPLITER + murl.name());//ɾ���ļ�
				insertCommand(QLatin1String("cd") + CMDSPLITER + commandlist.at(1));//����Ŀ¼
			}
			if (murl.isDir() && murl.name() != "." && murl.name() != "..")
			{
				removedirectory(commandlist.at(1) + "\\" + murl.name());
			}
			++iterUriInfo;
		}
		invokeLastCommand();
	}

	return true;
}

void wFtpOperator::on_ftp_command_started(int id)
{
	switch (opeFtp->currentCommand())
	{
	case QFtp::List:
		listinoflist.clear();
		break;
	}
}

void wFtpOperator::on_ftp_command_finished(int id, bool error)
{
	switch (opeFtp->currentCommand())
	{
	case QFtp::ConnectToHost:
		{
			if (error)
			{
				opeState.connected = false;
				return;
			}

			opeState.connected = true;
			opeFtp->login(opeParam.usr, opeParam.pwd);
			break;
		}
		break;
	case QFtp::Login:
		{
			if (error)
			{
				opeState.logined = false;
				return;
			}

			opeState.logined = true;
			break;
		}
		break;
	case QFtp::Get:
		{
			opeFile->close();
			pubfunc::release(opeFile);
			opeState.downloading = false;

			emit filetransferFinished(true);

			if (error)
			{
				opeFile->remove();
				return;
			}
		}
		break;
	case QFtp::Put:
		{
			opeFile->close();
			pubfunc::release(opeFile);
			opeState.uploading = false;

			emit filetransferFinished(false);

			if (error)
			{
				return;
			}
		}
		break;
	case QFtp::List:
		{
			if (error)
			{
				return;
			}
		}
		break;
	case QFtp::Cd:
	case QFtp::Rename:
	case QFtp::Mkdir:
		{
			if (error)
			{
				QString errorstr = opeFtp->errorString();
				switch (opeFtp->currentCommand())
				{
				case QFtp::Mkdir://����ͬ���ļ���
				case QFtp::Rename://�¸ĵ����ƴ���ͬ���ļ���
					break;
				default:
					return;
				}
			}
		}
		break;
	}

	//������һ������
	invokeLastCommand();
}