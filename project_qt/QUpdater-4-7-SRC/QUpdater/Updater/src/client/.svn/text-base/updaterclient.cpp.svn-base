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

	/* 重新采用奇趣提供的plugintest工程的设计方法构建treeview显示
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
	//启动时最小化
	{
		QAction* pStartMinimal = ui.actionStart_minimal;
		pStartMinimal->setCheckable(true);
		connect(pStartMinimal, SIGNAL(toggled(bool)), this, SLOT(on_menu_startminimal(bool)));
		pStartMinimal->setChecked(getCConfig()->getValue("StartMinimal").toBool());
	}

	//是否自动刷新更新信息
	{
		QAction* pAutoRefresh = ui.actionAuto_refresh;
		pAutoRefresh->setCheckable(true);
		connect(pAutoRefresh, SIGNAL(toggled(bool)), this, SLOT(on_menu_autorefresh(bool)));
		pAutoRefresh->setChecked(getCConfig()->getValue("AutoRefresh").toBool());
		on_menu_autorefresh(getCConfig()->getValue("AutoRefresh").toBool());
	}

	//是否自动下载
	{
		QAction* pAutoDownload = ui.actionQuto_download;
		pAutoDownload->setCheckable(true);
		connect(pAutoDownload, SIGNAL(toggled(bool)), this, SLOT(on_menu_autodownload(bool)));
		pAutoDownload->setChecked(getCConfig()->getValue("AutoDownload").toBool());
	}

	//是否自动安装
	{
		QAction* pAutoInstall = ui.actionAuto_install;
		pAutoInstall->setCheckable(true);
		connect(pAutoInstall, SIGNAL(toggled(bool)), this, SLOT(on_menu_autoinstall(bool)));
		pAutoInstall->setChecked(getCConfig()->getValue("AutoInstall").toBool());
	}

	//其他菜单事件
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
	//! 如果还存在没有结束的下载，则跳出提示
	//! 如果用户执意退出，则保存断点续传
	if (filecount != SIZE(mapReadyPacks))
	{
		this->show();

		//! 存在没有下载好的包
		QMessageBox msg(QMessageBox::Warning, tr("warning"), tr("have some packs in downloading queue"),
			QMessageBox::Yes | QMessageBox::No, this);
		msg.button(QMessageBox::Yes)->setText(tr("Yes"));
		msg.button(QMessageBox::No)->setText(tr("No"));
		if (msg.exec() != QMessageBox::Yes)
		{
			//如果用户不点击退出
			directQuit = false;
			return;
		}
		else
		{
			//需要暂停下载
			if (!IsNull(opeFtp) && !IsNull(opeFile))
			{
				opeFtp->abort();
				opeFile->close();
			}

			directQuit = true;
		}
	}
	else
	{//不存在更新包，则允许退出
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
	//初始化按钮状态
	ui.btndownloadall->setDisabled(false);

	//清理
	filecount = 0;
	mapReadyPacks.clear();
	QStandardItemModel* pStandardItemModel = (QStandardItemModel*)pmodelSortFilterProxy->sourceModel();
	//while (pStandardItemModel->rowCount())
	{
		pStandardItemModel->removeRows(0, pStandardItemModel->rowCount());
	}

	//开始流程
	DownloadProgress download;
	if (useui)
		download.exec();
	else
	{
		download.processClient2Server();
		download.processXml();
	}

	//根据计算的结构进行显示
	if (!download.sucess)
		return;

	CUpdateXmlPlistTree* pdataServerData = static_cast<CUpdateXmlPlistTree*>(getUpdateXmlPlistServerTree());
	CUpdateXmlPlistTree::TIterEachSoftware iterEachSoftware = pdataServerData->begin();
	//遍历所有软件
	while(iterEachSoftware != pdataServerData->end())
	{
		CUpdateXmlPlistTree::EachSoftUpdate* pEachSoft = &iterEachSoftware->second;
		CUpdateXmlPlistTree::EachSoftUpdate::TIterEachPack iterPack = pEachSoft->begin();
		//遍历每一个补丁包
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

	//显示所有可用的补丁
	TMapReadyPacks::iterator iterReadyPack = mapReadyPacks.begin();
	while(iterReadyPack != mapReadyPacks.end())
	{
		const IUpdatePack* pPack = iterReadyPack->second;
		//addPackShow((QStandardItemModel*)pmodelSortFilterProxy->sourceModel(), pPack);
		addPackShow(pStdItemModel, pPack);

		++iterReadyPack;
	}

	//显示其他信息
	QTextBrowser* packInfo = ui.packInfo;
	QString restr = QString("一共找到%1个更新需要执行。").arg(SIZE(mapReadyPacks));
	packInfo->setHtml(restr);

	//没有更新
	if (SIZE(mapReadyPacks) == 0)
	{
		QPushButton* pbtnDownAll = ui.btndownloadall;
		pbtnDownAll->setDisabled(false);//允许退出

		pbtnDownAll->setText(tr("EXIT"));
		packInfo->setHtml(tr("NONUPDATE"));
		btnMode = BM_Complete;
		return;
	}

	//如果有更新才进行如下显示
	if (SIZE(mapReadyPacks))
	{
		//显示气泡提示
		wTrayWindow::showTrayMessage(tr("info"), restr);

		//判断是否需要自动下载
		if (getCConfig()->getValue("AutoDownload").toBool())
		{
			//如果是自动安装，此时禁用安装按钮
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
	
	if (!pPack->mustdownload)//如果是可选补丁
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

//树形结构被点击
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
	//显示补丁信息
	QTextBrowser* ptextPackinfo = ui.packInfo;
	ptextPackinfo->setHtml(pPack->info);
}

void UpdaterClient::downloadPacks()
{
	if (!SIZE(mapReadyPacks)) return;

	//更新checkbox状态来决定是否需要下载该补丁
	//遍历所有的行
	bool existneeddownload = false;//是否存在需要下载的项目
	for (int row=0; row<pStdItemModel->rowCount(); row++)
	{
		//pStdItemModel->removeRows(row, 1);
		QStandardItem* pitem = pStdItemModel->item(row);

		bool checked;
		if (pitem->isCheckable())
		{
			//可选补丁
			checked = pitem->checkState() == Qt::Checked;
		}
		else//必选补丁
			checked = true;

		QString seletedstr = pitem->text();
		TMapReadyPacks::iterator findpack = mapReadyPacks.find(seletedstr);
		if (findpack == mapReadyPacks.end())
			return;

		IUpdatePack* pPack = findpack->second;
		pPack->needdownload = checked;

		if (!checked)
			filecount++;//如果属于未选中的，则改变下载基数

		existneeddownload |= checked;
	}
	if (!existneeddownload)
		return;//不存在需要下载的项目

	pubfunc::release(opeFtp);

	//
	iterInstallingPack = mapReadyPacks.begin();//第一个补丁

	//建立环境
	opeFtp = new QFtp();
	opeFtp->connectToHost(getClientCenter()->ftpAddress);

	//绑定信号
	connect(opeFtp, SIGNAL(commandFinished (int, bool)),
		this, SLOT(on_ftpCommandFinished(int, bool)));
	connect(opeFtp, SIGNAL(dataTransferProgress(qint64, qint64)),
		this, SLOT(on_ftpDataTransferProgress(qint64, qint64)));

	//登陆服务器
	opeFtp->login("Client", "Client");
}

void UpdaterClient::installPacks()
{
	if (!SIZE(mapReadyPacks)) return;

	QLabel* plabelStatus = ui.statusLabel;
	plabelStatus->setText(tr("Installing..."));
	plabelStatus->setVisible(true);

	//新建一安装线程
	pubfunc::release(pPacksInstallThread);
	pPacksInstallThread = new PacksInstallThread();

	//绑定信号量
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

//下载更新的按钮被按动
//分为两种模式，1为下载，2为安装
void UpdaterClient::on_btndownloadall_clicked()
{	
	switch (btnMode)
	{
	case BM_DownLoad:
		{//下载所有的更新
			downloadPacks();
			break;
		}
		break;
	case BM_Install:
		{//安装所有的更新
			installPacks();
			break;
		}
		break;
	case BM_Complete:
		{
			//退出程序
			QApplication::exit();
		}
		break;
	}
}

void UpdaterClient::on_packsInstalled()
{
	//全部安装完成
	QPushButton* pbtnDownAll = ui.btndownloadall;
	pbtnDownAll->setText(tr("Quit"));
	btnMode = BM_Complete;

	//隐藏掉进度显示
	QLabel* plabelStatus = ui.statusLabel;
	plabelStatus->setVisible(false);

	QTextBrowser* qtextPackInfo = ui.packInfo;
	qtextPackInfo->setHtml(tr("Install Finish"));

	wTrayWindow::showTrayMessage(tr("info"), tr("Install Finish"));

	//全部安装结束，恢复按钮状态
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
	//连接前预判断
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
			//已经下载完成
			if (!error)
				opeFile->close();
			else
				opeFile->remove();

			pubfunc::release(opeFile);

			filecount++;
			if (filecount == SIZE(mapReadyPacks))
			{
				//关闭ftp链接
				opeFtp->close();

				//所有文件已经下载好了
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

				//登陆成功，可以开始下载文件
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

//下载下一个更新
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
	//找到一个需要下载的

	//建立对应软件更新的目录
	QDir dir(getClientCenter()->localRecipesDir);
	if ( !dir.exists(QString("%1").arg(pPack->softname)))
		dir.mkdir(QString("%1").arg(pPack->softname));

	//如果当前文件下已经存在该文件，则比对md5码决定是否需要下载
	QString localFileName = getClientCenter()->localRecipesDir + QString("/%1/%2").arg(pPack->softname).arg(pPack->packName);
	QFileInfo localFileInfo(localFileName);
	bool needDownload = true;//是否需要下载该文件
	if (localFileInfo.exists())
	{
		//如果本地已存在同名文件，则需要匹配md5编码
		QString localMd5 = wFileFunc::calcFileMd5(localFileName);
		if ( localMd5 == pPack->md5 )
		{
			//如果md5匹配则不需要下载该文件
			needDownload = false;
			//计数器自增
			filecount++;
			if (filecount == SIZE(mapReadyPacks))
			{
				//关闭ftp链接
				opeFtp->close();
				//所有文件已经下载好了
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
			//! 如果不匹配
			//! 为了支持断点续传，则不移除同名文件
			//QFile::remove(localFileName);
		}
	}

	//和需要下载的位与
	needDownload &= pPack->needdownload;

	if (needDownload)
	{
		QLabel* plabelStatus = ui.statusLabel;
		plabelStatus->setText(QString(tr("downloading ") + pPack->name));
		plabelStatus->setVisible(true);

		//下载更新的文件
		wFtpFunc::downloadFileEx(opeFtp, opeFile,
			QString("/%1/%2").arg(pPack->softname).arg(pPack->packName),
			getClientCenter()->localRecipesDir);
	}

	iterInstallingPack ++;
}

//所有文件下载完毕
void UpdaterClient::afterAllPacksDownloaded()
{
	QLabel* plabelStatus = ui.statusLabel;

	//下载完成，隐藏信息显示
	plabelStatus->setVisible(false);
	plabelStatus->setText(tr("Installing..."));

	//改变按钮文字为安装更新
	QPushButton* pbtnDownAll = ui.btndownloadall;
	pbtnDownAll->setText(tr("Install"));
	pbtnDownAll->setEnabled(true);
	btnMode = BM_Install;

	//跟新信息显示
	QTextBrowser* qtextPackInfo = ui.packInfo;
	qtextPackInfo->setHtml(tr("Download Finished"));

	wTrayWindow::showTrayMessage(tr("info"), tr("Download Finished"));

	//
	QProgressBar* pDownloadProgress = ui.progressBarAllDownload;
	pDownloadProgress->setRange(0, 100);
	pDownloadProgress->setValue(100);

	//自动安装
	if (getCConfig()->getValue("AutoInstall").toBool())
	{
		//如果是自动安装，则禁用按钮
		ui.btndownloadall->setDisabled(true);

		installPacks();
	}

}

void UpdaterClient::showLogs()
{
	std::list<QString>& logs = getClientCenter()->logs;
	if (SIZE(logs))
	{
		//存在没有看过的日志
		QString logstr = pubfunc::combine<QString, std::list<QString> >(logs, "\n");
		//logs.clear();
		QMessageBox::warning(this, tr("warning"), logstr);
	}
}