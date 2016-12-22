#include <QtGui>
#include <QCloseEvent>
#include <QtCore>
#include "updaterclient.h"
#include "downloadprogress.h"
#include "aboutdlg.h"
#include "historyshow.h"
#include "IClientCenter.h"
#include "../UpdateXmlPlist.h"
#include "pubfuncs.h"
#include "CommonFtpOperFunction.h"
#include "CommonFileOperFunction.h"
#include "InstallThread.h"

UpdaterClient::UpdaterClient(QWidget *parent, Qt::WFlags flags)
	: wTrayWindow(parent, flags), wWindowPos(this, WidgetWidth, WidgetHeigth),
	pmodelSortFilterProxy(0),
	pStdItemModel(0),
	opeFtp(0),
	opeFile(0),
	filecount(0),
	btnMode(BM_DownLoad),
	pPacksInstallThread(0),
	pRefreshTimer(0),
	directQuit(false)
{
	setupUi();

	loadDownloadProgress();
}

UpdaterClient::~UpdaterClient()
{
	pubfunc::release(pmodelSortFilterProxy);
	pubfunc::release(pStdItemModel);
	pubfunc::release(opeFtp);
	pubfunc::release(opeFile);
	pubfunc::release(pPacksInstallThread);
	pubfunc::release(pRefreshTimer);
}

void UpdaterClient::setupUi()
{
	ui.setupUi(this);

	/* ���²�����Ȥ�ṩ��plugintest���̵���Ʒ�������treeview��ʾ
	pStdItemModel = new QStandardItemModel(0, 5, this);
	pStdItemModel->setHeaderData(0, Qt::Horizontal, tr("check"));
	pStdItemModel->setHeaderData(1, Qt::Horizontal, tr("name"));
	pStdItemModel->setHeaderData(2, Qt::Horizontal, tr("date"));
	pStdItemModel->setHeaderData(3, Qt::Horizontal, tr("size"));
	pStdItemModel->setHeaderData(4, Qt::Horizontal, tr("soft"));
	*/
	pStdItemModel = new QStandardItemModel();
	pStdItemModel->clear();
	pStdItemModel->setHorizontalHeaderLabels(QStringList() << tr("name") << tr("date") << tr("size") << tr("soft"));
	//

	pmodelSortFilterProxy = new QSortFilterProxyModel();
	pmodelSortFilterProxy->setDynamicSortFilter(true);
	pmodelSortFilterProxy->setSourceModel(pStdItemModel);
	QTreeView* pviewPacks = ui.Packs;
	pviewPacks->setRootIsDecorated(false);
	pviewPacks->setAlternatingRowColors(true);
	pviewPacks->setModel(pmodelSortFilterProxy);
	pviewPacks->setSortingEnabled(true);
	pviewPacks->sortByColumn(2, Qt::AscendingOrder);

	//
	QLabel* plabelStatus = ui.statusLabel;
	plabelStatus->setVisible(false);

	//tray
	trayparam.icon = QIcon(":/icon.png");
	wTrayWindow::createTrayIcon(trayparam);

	//menu
	//����ʱ��С��
	{
		QAction* pStartMinimal = ui.actionStart_minimal;
		pStartMinimal->setCheckable(true);
		connect(pStartMinimal, SIGNAL(toggled(bool)), this, SLOT(on_menu_startminimal(bool)));
		pStartMinimal->setChecked(getCConfig()->getValue("StartMinimal").toBool());
	}

	//�Ƿ��Զ�ˢ�¸�����Ϣ
	{
		QAction* pAutoRefresh = ui.actionAuto_refresh;
		pAutoRefresh->setCheckable(true);
		connect(pAutoRefresh, SIGNAL(toggled(bool)), this, SLOT(on_menu_autorefresh(bool)));
		pAutoRefresh->setChecked(getCConfig()->getValue("AutoRefresh").toBool());
		on_menu_autorefresh(getCConfig()->getValue("AutoRefresh").toBool());
	}

	//�Ƿ��Զ�����
	{
		QAction* pAutoDownload = ui.actionQuto_download;
		pAutoDownload->setCheckable(true);
		connect(pAutoDownload, SIGNAL(toggled(bool)), this, SLOT(on_menu_autodownload(bool)));
		pAutoDownload->setChecked(getCConfig()->getValue("AutoDownload").toBool());
	}

	//�Ƿ��Զ���װ
	{
		QAction* pAutoInstall = ui.actionAuto_install;
		pAutoInstall->setCheckable(true);
		connect(pAutoInstall, SIGNAL(toggled(bool)), this, SLOT(on_menu_autoinstall(bool)));
		pAutoInstall->setChecked(getCConfig()->getValue("AutoInstall").toBool());
	}

	//�����˵��¼�
	{
		QAction* pHelp = ui.actionHelp;
		connect(pHelp, SIGNAL(triggered()), this, SLOT(on_menu_help()));

		QAction* pHistory = ui.actionInstallhistory;
		connect(pHistory, SIGNAL(triggered()), this, SLOT(on_menu_history()));
	}

}

void UpdaterClient::on_menu_help()
{
	AboutDlg aboutdlg;
	aboutdlg.exec();
	this->setWindowState(Qt::WindowActive);
}

void UpdaterClient::on_menu_history()
{
	HistoryShow hisdlg;
	hisdlg.exec();
	this->setWindowState(Qt::WindowActive);
}

void UpdaterClient::on_menu_startminimal(bool checked)
{
	getCConfig()->setValue("StartMinimal", checked);
}

void UpdaterClient::on_menu_autodownload(bool checked)
{
	getCConfig()->setValue("AutoDownload", checked);
}

void UpdaterClient::on_menu_autoinstall(bool checked)
{
	getCConfig()->setValue("AutoInstall", checked);
}

void UpdaterClient::on_menu_autorefresh(bool checked)
{
	getCConfig()->setValue("AutoRefresh", checked);

	if (checked)
	{
		pRefreshTimer = new QTimer();
		pRefreshTimer->start(getCConfig()->getValue("DefaultAutoRefreshTime").toLongLong());

		connect(pRefreshTimer, SIGNAL(timeout()), this, SLOT(on_refreshautotimerout()));
	}
	else
	{
		pRefreshTimer->stop();
		pubfunc::release(pRefreshTimer);
	}
}

void UpdaterClient::on_refreshautotimerout()
{
	if (this->isHidden())
		loadDownloadProgress(false);
}

void UpdaterClient::on_proxyClose()
{
	//! ���������û�н��������أ���������ʾ
	//! ����û�ִ���˳����򱣴�ϵ�����
	if (filecount != SIZE(mapReadyPacks))
	{
		this->show();

		//! ����û�����غõİ�
		QMessageBox msg(QMessageBox::Warning, tr("warning"), tr("have some packs in downloading queue"),
			QMessageBox::Yes | QMessageBox::No, this);
		msg.button(QMessageBox::Yes)->setText(tr("Yes"));
		msg.button(QMessageBox::No)->setText(tr("No"));
		if (msg.exec() != QMessageBox::Yes)
		{
			//����û�������˳�
			directQuit = false;
			return;
		}
		else
		{
			//��Ҫ��ͣ����
			if (!IsNull(opeFtp) && !IsNull(opeFile))
			{
				opeFtp->abort();
				opeFile->close();
			}

			directQuit = true;
		}
	}
	else
	{//�����ڸ��°����������˳�
		directQuit = true;
	}

	QMetaObject::invokeMethod(this, "close");
}

void UpdaterClient::closeEvent(QCloseEvent* pevent)
{
	if (!directQuit)
	{
		this->hide();
		pevent->ignore();
		return;
	}
}

void UpdaterClient::loadDownloadProgress(bool useui)
{
	//��ʼ����ť״̬
	ui.btndownloadall->setDisabled(false);

	//����
	filecount = 0;
	mapReadyPacks.clear();
	QStandardItemModel* pStandardItemModel = (QStandardItemModel*)pmodelSortFilterProxy->sourceModel();
	//while (pStandardItemModel->rowCount())
	{
		pStandardItemModel->removeRows(0, pStandardItemModel->rowCount());
	}

	//��ʼ����
	DownloadProgress download;
	if (useui)
		download.exec();
	else
	{
		download.processClient2Server();
		download.processXml();
	}

	//���ݼ���Ľṹ������ʾ
	if (!download.sucess)
		return;

	CUpdateXmlPlistTree* pdataServerData = static_cast<CUpdateXmlPlistTree*>(getUpdateXmlPlistServerTree());
	CUpdateXmlPlistTree::TIterEachSoftware iterEachSoftware = pdataServerData->begin();
	//�����������
	while(iterEachSoftware != pdataServerData->end())
	{
		CUpdateXmlPlistTree::EachSoftUpdate* pEachSoft = &iterEachSoftware->second;
		CUpdateXmlPlistTree::EachSoftUpdate::TIterEachPack iterPack = pEachSoft->begin();
		//����ÿһ��������
		while(iterPack != pEachSoft->end())
		{
			CUpdatePack* pPack = &*iterPack;
			if (pPack->needupdate 
#ifndef _DEBUG
				&& !pPack->debugmode
#endif
				)
			{
				//addPackShow((QStandardItemModel*)pmodelSortFilterProxy->sourceModel(), pPack);
				mapReadyPacks[pPack->name] = pPack;
			}
			++iterPack;
		}
		++iterEachSoftware;
	}

	//��ʾ���п��õĲ���
	TMapReadyPacks::iterator iterReadyPack = mapReadyPacks.begin();
	while(iterReadyPack != mapReadyPacks.end())
	{
		const IUpdatePack* pPack = iterReadyPack->second;
		//addPackShow((QStandardItemModel*)pmodelSortFilterProxy->sourceModel(), pPack);
		addPackShow(pStdItemModel, pPack);

		++iterReadyPack;
	}

	//��ʾ������Ϣ
	QTextBrowser* packInfo = ui.packInfo;
	QString restr = QString("һ���ҵ�%1��������Ҫִ�С�").arg(SIZE(mapReadyPacks));
	packInfo->setHtml(restr);

	//û�и���
	if (SIZE(mapReadyPacks) == 0)
	{
		QPushButton* pbtnDownAll = ui.btndownloadall;
		pbtnDownAll->setDisabled(false);//�����˳�

		pbtnDownAll->setText(tr("EXIT"));
		packInfo->setHtml(tr("NONUPDATE"));
		btnMode = BM_Complete;
		return;
	}

	//����и��²Ž���������ʾ
	if (SIZE(mapReadyPacks))
	{
		//��ʾ������ʾ
		wTrayWindow::showTrayMessage(tr("info"), restr);

		//�ж��Ƿ���Ҫ�Զ�����
		if (getCConfig()->getValue("AutoDownload").toBool())
		{
			//������Զ���װ����ʱ���ð�װ��ť
			ui.btndownloadall->setDisabled(true);

			downloadPacks();
		}
	}
}

void UpdaterClient::addPackShow(QStandardItemModel* pModel, const IUpdatePack* pPack)
{
	/* same reason as initial procession
	pItems->insertRow(0);
	pItems->setData(pItems->index(0, 0), Qt::Checked, Qt::CheckStateRole);
	pItems->setData(pItems->index(0, 1), pPack->name, Qt::DisplayRole);
	QString datestr = QString::number(pPack->publishTime);
	QString dateyear, datemonth, dateday;
	datestr.remove(dateyear = datestr.left(4));
	datestr.remove(datemonth = datestr.left(2));
	datestr.remove(dateday = datestr.left(2));
	pItems->setData(pItems->index(0, 2), QDate(dateyear.toInt(), datemonth.toInt(), dateday.toInt()), Qt::DisplayRole);
	pItems->setData(pItems->index(0, 3), pPack->packSize, Qt::DisplayRole);
	pItems->setData(pItems->index(0, 4), pPack->softname, Qt::DisplayRole);
	*/

	QList<QStandardItem*> columns;
	QStandardItem* name = new QStandardItem(pPack->name);
	name->setEditable(false);
	
	if (!pPack->mustdownload)//����ǿ�ѡ����
	{
		name->setCheckable(true);
		name->setCheckState(Qt::Checked);
	}

	QString datestr = QString::number(pPack->publishTime);
	QStandardItem* date = new QStandardItem(datestr);
	QString dateyear, datemonth, dateday;
	date->setText(datestr);
	datestr.remove(dateyear = datestr.left(4));
	datestr.remove(datemonth = datestr.left(2));
	datestr.remove(dateday = datestr.left(2));
	date->setData(QDate(dateyear.toInt(), datemonth.toInt(), dateday.toInt()));
	date->setEditable(false);

	QStandardItem* size = new QStandardItem(pPack->packSize);
	size->setEditable(false);

	QStandardItem* softname = new QStandardItem(pPack->softname);
	softname->setEditable(false);

	columns << name << date << size << softname;
	pModel->appendRow(columns);
}

//���νṹ�����
void UpdaterClient::on_Packs_clicked(const QModelIndex & qindex)
{
	if (!qindex.isValid())
		return;

	QTreeView* pviewPacks = ui.Packs;
	QAbstractItemModel* pItems = pviewPacks->model();
	//QMap<int, QVariant> find = pItems->itemData(qindex);
	
	const QModelIndex& temindex = pItems->index(qindex.row(), 0);
	QMap<int, QVariant> find = pItems->itemData(temindex);
	
	if (!SIZE(find))
		return;
	Q_ASSERT(SIZE(find));
	
	QString seletedstr = find[0].toString();
	TMapReadyPacks::iterator findpack = mapReadyPacks.find(seletedstr);
	if (findpack == mapReadyPacks.end())
		return;

	const IUpdatePack* pPack = findpack->second;
	//��ʾ������Ϣ
	QTextBrowser* ptextPackinfo = ui.packInfo;
	ptextPackinfo->setHtml(pPack->info);
}

void UpdaterClient::downloadPacks()
{
	if (!SIZE(mapReadyPacks)) return;

	//����checkbox״̬�������Ƿ���Ҫ���ظò���
	//�������е���
	bool existneeddownload = false;//�Ƿ������Ҫ���ص���Ŀ
	for (int row=0; row<pStdItemModel->rowCount(); row++)
	{
		//pStdItemModel->removeRows(row, 1);
		QStandardItem* pitem = pStdItemModel->item(row);

		bool checked;
		if (pitem->isCheckable())
		{
			//��ѡ����
			checked = pitem->checkState() == Qt::Checked;
		}
		else//��ѡ����
			checked = true;

		QString seletedstr = pitem->text();
		TMapReadyPacks::iterator findpack = mapReadyPacks.find(seletedstr);
		if (findpack == mapReadyPacks.end())
			return;

		IUpdatePack* pPack = findpack->second;
		pPack->needdownload = checked;

		if (!checked)
			filecount++;//�������δѡ�еģ���ı����ػ���

		existneeddownload |= checked;
	}
	if (!existneeddownload)
		return;//��������Ҫ���ص���Ŀ

	pubfunc::release(opeFtp);

	//
	iterInstallingPack = mapReadyPacks.begin();//��һ������

	//��������
	opeFtp = new QFtp();
	opeFtp->connectToHost(getClientCenter()->ftpAddress);

	//���ź�
	connect(opeFtp, SIGNAL(commandFinished (int, bool)),
		this, SLOT(on_ftpCommandFinished(int, bool)));
	connect(opeFtp, SIGNAL(dataTransferProgress(qint64, qint64)),
		this, SLOT(on_ftpDataTransferProgress(qint64, qint64)));

	//��½������
	opeFtp->login("Client", "Client");
}

void UpdaterClient::installPacks()
{
	if (!SIZE(mapReadyPacks)) return;

	QLabel* plabelStatus = ui.statusLabel;
	plabelStatus->setText(tr("Installing..."));
	plabelStatus->setVisible(true);

	//�½�һ��װ�߳�
	pubfunc::release(pPacksInstallThread);
	pPacksInstallThread = new PacksInstallThread();

	//���ź���
	connect(pPacksInstallThread, SIGNAL(installed()),
		this, SLOT(on_packsInstalled()));
	connect(pPacksInstallThread, SIGNAL(progressStep(QString, int, int)),
		this, SLOT(on_packInstallProgress(QString, int, int)));
	connect(pPacksInstallThread, SIGNAL(selfUpdatePack()),
		this, SLOT(on_threadSelfUpdate()));
	connect(pPacksInstallThread, SIGNAL(appMustBClosed(QString)),
		this, SLOT(on_thread_appMustBClosed(QString)));

	pPacksInstallThread->installAllPacks(mapReadyPacks);
}

void UpdaterClient::on_thread_appMustBClosed(QString appname)
{
	QMessageBox::warning(0, tr("warning"), tr("please close the app ") + appname);
	pPacksInstallThread->appshut = true;
}

void UpdaterClient::on_threadSelfUpdate()
{
	pPacksInstallThread->quit();
	this->close();
	QApplication::quit();
}

//���ظ��µİ�ť������
//��Ϊ����ģʽ��1Ϊ���أ�2Ϊ��װ
void UpdaterClient::on_btndownloadall_clicked()
{	
	switch (btnMode)
	{
	case BM_DownLoad:
		{//�������еĸ���
			downloadPacks();
			break;
		}
		break;
	case BM_Install:
		{//��װ���еĸ���
			installPacks();
			break;
		}
		break;
	case BM_Complete:
		{
			//�˳�����
			QApplication::exit();
		}
		break;
	}
}

void UpdaterClient::on_packsInstalled()
{
	//ȫ����װ���
	QPushButton* pbtnDownAll = ui.btndownloadall;
	pbtnDownAll->setText(tr("Quit"));
	btnMode = BM_Complete;

	//���ص�������ʾ
	QLabel* plabelStatus = ui.statusLabel;
	plabelStatus->setVisible(false);

	QTextBrowser* qtextPackInfo = ui.packInfo;
	qtextPackInfo->setHtml(tr("Install Finish"));

	wTrayWindow::showTrayMessage(tr("info"), tr("Install Finish"));

	//ȫ����װ�������ָ���ť״̬
	ui.btndownloadall->setDisabled(false);
}

void UpdaterClient::on_packInstallProgress(QString name, int filescount, int fileindex)
{
	QLabel* plabelStatus = ui.statusLabel;
	plabelStatus->setText(QString(tr("Installing...")) + QString(" %1").arg(name));

	QProgressBar* pProgressBar = ui.progressBarAllDownload;
	pProgressBar->setRange(0, filescount);
	pProgressBar->setValue(fileindex);
}

void UpdaterClient::on_ftpDataTransferProgress(qint64 done, qint64 total)
{
	QProgressBar* pdownProgress = ui.progressBarAllDownload;
	pdownProgress->setRange(0, total);
	pdownProgress->setValue(done);
}

void UpdaterClient::on_ftpCommandFinished(int id, bool error)
{
	//����ǰԤ�ж�
	switch (opeFtp->currentCommand())
	{
	case QFtp::ConnectToHost:
	case QFtp::Login:
		{
			if (error)
			{
				getClientCenter()->logs.push_back(opeFtp->errorString());
				getClientCenter()->pTrayIcon->setIcon(QIcon(":/lost.png"));
				return;
			}
		}
		break;
	case QFtp::Get:
		{
			//�Ѿ��������
			if (!error)
				opeFile->close();
			else
				opeFile->remove();

			pubfunc::release(opeFile);

			filecount++;
			if (filecount == SIZE(mapReadyPacks))
			{
				//�ر�ftp����
				opeFtp->close();

				//�����ļ��Ѿ����غ���
				afterAllPacksDownloaded();
			}
			else
				donwloadNextPack();
		}
	}

	switch (opeFtp->currentCommand())
	{
	case QFtp::Login:
		{
			if (opeFtp->state() == QFtp::LoggedIn)
			{
				QPushButton* pbtnDownAll = ui.btndownloadall;
				pbtnDownAll->setEnabled(false);

				donwloadNextPack();

				//��½�ɹ������Կ�ʼ�����ļ�
// 				TMapReadyPacks::iterator iterReadyPack = mapReadyPacks.begin();
// 				while(iterReadyPack != mapReadyPacks.end())
// 				{
// 					const IUpdatePack* pPack = iterReadyPack->second;
// 
// 					
// 					++iterReadyPack;
// 				}
			}
		}
		break;
	}
}

//������һ������
void UpdaterClient::donwloadNextPack()
{
	if (iterInstallingPack == mapReadyPacks.end())
		return;

	IUpdatePack* pPack = iterInstallingPack->second;
	while (!pPack->needdownload && iterInstallingPack != mapReadyPacks.end())
	{
		iterInstallingPack++;
		pPack = iterInstallingPack->second;
	}

	if (!pPack->needdownload)
		return;
	//�ҵ�һ����Ҫ���ص�

	//������Ӧ������µ�Ŀ¼
	QDir dir(getClientCenter()->localRecipesDir);
	if ( !dir.exists(QString("%1").arg(pPack->softname)))
		dir.mkdir(QString("%1").arg(pPack->softname));

	//�����ǰ�ļ����Ѿ����ڸ��ļ�����ȶ�md5������Ƿ���Ҫ����
	QString localFileName = getClientCenter()->localRecipesDir + QString("/%1/%2").arg(pPack->softname).arg(pPack->packName);
	QFileInfo localFileInfo(localFileName);
	bool needDownload = true;//�Ƿ���Ҫ���ظ��ļ�
	if (localFileInfo.exists())
	{
		//��������Ѵ���ͬ���ļ�������Ҫƥ��md5����
		QString localMd5 = wFileFunc::calcFileMd5(localFileName);
		if ( localMd5 == pPack->md5 )
		{
			//���md5ƥ������Ҫ���ظ��ļ�
			needDownload = false;
			//����������
			filecount++;
			if (filecount == SIZE(mapReadyPacks))
			{
				//�ر�ftp����
				opeFtp->close();
				//�����ļ��Ѿ����غ���
				afterAllPacksDownloaded();
			}
			else
			{
				iterInstallingPack ++;
				donwloadNextPack();
				return;
			}
		}
		else
		{
			//! �����ƥ��
			//! Ϊ��֧�ֶϵ����������Ƴ�ͬ���ļ�
			//QFile::remove(localFileName);
		}
	}

	//����Ҫ���ص�λ��
	needDownload &= pPack->needdownload;

	if (needDownload)
	{
		QLabel* plabelStatus = ui.statusLabel;
		plabelStatus->setText(QString(tr("downloading ") + pPack->name));
		plabelStatus->setVisible(true);

		//���ظ��µ��ļ�
		wFtpFunc::downloadFileEx(opeFtp, opeFile,
			QString("/%1/%2").arg(pPack->softname).arg(pPack->packName),
			getClientCenter()->localRecipesDir);
	}

	iterInstallingPack ++;
}

//�����ļ��������
void UpdaterClient::afterAllPacksDownloaded()
{
	QLabel* plabelStatus = ui.statusLabel;

	//������ɣ�������Ϣ��ʾ
	plabelStatus->setVisible(false);
	plabelStatus->setText(tr("Installing..."));

	//�ı䰴ť����Ϊ��װ����
	QPushButton* pbtnDownAll = ui.btndownloadall;
	pbtnDownAll->setText(tr("Install"));
	pbtnDownAll->setEnabled(true);
	btnMode = BM_Install;

	//������Ϣ��ʾ
	QTextBrowser* qtextPackInfo = ui.packInfo;
	qtextPackInfo->setHtml(tr("Download Finished"));

	wTrayWindow::showTrayMessage(tr("info"), tr("Download Finished"));

	//
	QProgressBar* pDownloadProgress = ui.progressBarAllDownload;
	pDownloadProgress->setRange(0, 100);
	pDownloadProgress->setValue(100);

	//�Զ���װ
	if (getCConfig()->getValue("AutoInstall").toBool())
	{
		//������Զ���װ������ð�ť
		ui.btndownloadall->setDisabled(true);

		installPacks();
	}

}

void UpdaterClient::showLogs()
{
	std::list<QString>& logs = getClientCenter()->logs;
	if (SIZE(logs))
	{
		//����û�п�������־
		QString logstr = pubfunc::combine<QString, std::list<QString> >(logs, "\n");
		//logs.clear();
		QMessageBox::warning(this, tr("warning"), logstr);
	}
}