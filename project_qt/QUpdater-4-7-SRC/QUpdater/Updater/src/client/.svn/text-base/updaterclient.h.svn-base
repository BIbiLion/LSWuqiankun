#ifndef UPDATERCLIENT_H
#define UPDATERCLIENT_H

#include <QtCore/QProcess>
#include "WindowPos.h"
#include "ui_updaterclient.h"
#include<map>
#include "IUpdateXmlPlist.h"
#include "TrayWindow.h"

class QSortFilterProxyModel;
class QStandardItemModel;
class CUpdateXmlPlistNode;
class QFtp;
class QFile;
//class QProcess;
class PacksInstallThread;
class QCloseEvent;
class QTimer;
class UpdaterClient : public wTrayWindow, public wWindowPos
{
	Q_OBJECT

public:
	UpdaterClient(QWidget *parent = 0, Qt::WFlags flags = 0);
	~UpdaterClient();
	enum {WidgetWidth = 500, WidgetHeigth = 350};

protected:
	void loadDownloadProgress(bool useui = true);// useui 决定显示不显示进度条

	//operator
protected:
	void setupUi();//装配显示环境
	void addPackShow(QStandardItemModel* pItem, const IUpdatePack* pPack);//给显示列表中加入该补丁的显示
	void afterAllPacksDownloaded();//更新下载结束
	//void clearTreeView();
	void downloadPacks();//下载更新
	void installPacks();//安装所有已下载的更新
	void donwloadNextPack();//下载下一个文件

	//virtual
protected:
	virtual void closeEvent(QCloseEvent*);
	virtual void showLogs();

	//types
protected:
	//按钮的模式
	enum BtnMode
	{BM_DownLoad,BM_Install,BM_Complete,};

	//attributes
protected:
	QSortFilterProxyModel* pmodelSortFilterProxy;
	QStandardItemModel*  pStdItemModel;
	TMapReadyPacks mapReadyPacks;//可以更新的补丁包列表
	QFtp* opeFtp;//ftp操作子
	QFile* opeFile;//文件下载的操作子
	int filecount;//现在文件的计数器
	BtnMode btnMode;//按钮的模式 
	QProcess* pEachPackInstallProc;
	PacksInstallThread* pPacksInstallThread;//安装更新的线程
	wTrayWindowParam trayparam;//
	QTimer* pRefreshTimer;//主要的下载计时器
	TMapReadyPacks::iterator iterInstallingPack;//下载用的迭代器
	bool directQuit;//是否直接退出

private:
	Ui::UpdaterClientClass ui;

private slots:
	void on_Packs_clicked(const QModelIndex &);
	void on_btndownloadall_clicked();
	void on_ftpCommandFinished(int id, bool error);
	void on_ftpDataTransferProgress(qint64 done, qint64 total);
	void on_packsInstalled();//所有已安装
	void on_packInstallProgress(QString, int, int);//安装进度
	void on_threadSelfUpdate();//响应自身升级信号
	void on_menu_startminimal(bool checked);
	void on_menu_autorefresh(bool checked);
	void on_menu_autodownload(bool checked);
	void on_menu_autoinstall(bool checked);
	void on_menu_help();
	void on_refreshautotimerout();
	void on_proxyClose();//直接退出
	void on_menu_history();//补丁安装历史
	void on_thread_appMustBClosed(QString);//必须关闭软件
};

#endif // UPDATERCLIENT_H
