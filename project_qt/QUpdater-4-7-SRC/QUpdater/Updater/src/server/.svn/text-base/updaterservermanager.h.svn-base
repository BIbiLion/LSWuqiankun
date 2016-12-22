#ifndef UPDATERSERVERMANAGER_H
#define UPDATERSERVERMANAGER_H

#include <QtGui/QMainWindow>
#include <QtNetwork>
#include <QtCore>
#include "ui_updaterservermanager.h"

class wFtpOperator;
class UpdaterServerManager : public QMainWindow
{
	Q_OBJECT

public:
	UpdaterServerManager(QWidget *parent = 0, Qt::WFlags flags = 0);
	~UpdaterServerManager();

protected:
	void downloadServerPlist();//下载服务器端的文件
	void putPacksIntoList();//显示服务器端的数据
	void softitemTextEdited(QListWidgetItem* item);
	void softitemCloseEdit(bool autosel = false);

protected slots:
	void on_list_pack_itemselchanged();
	void on_list_soft_itemclick(QListWidgetItem* item);
	void on_list_soft_itemdoubleclick(QListWidgetItem* item);

private:
	Ui::UpdaterServerManagerClass ui;
	wFtpOperator* pFtpOperator;

private slots:
	void on_pushButtonImportInfo_clicked();
	void on_runPackApp_clicked();
	void on_removeDepend_clicked();
	void on_addPackDepend_clicked();
	void on_refreshPackInfo_clicked();
	void on_browserPack_clicked();
	void on_submit_clicked();
	void on_removePack_clicked();
	void on_addPack_clicked();
	void on_removeSoft_clicked();
	void on_addsoft_clicked();
	void on_ftp_transfer_progress(qint64, qint64);
	void on_ftp_transfer_finished(bool);
	void on_ftp_cmds_finished();
};

#endif // UPDATERSERVERMANAGER_H
