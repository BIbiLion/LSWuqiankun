#ifndef DOWNLOADPROGRESS_H
#define DOWNLOADPROGRESS_H

#include <QDialog>
#include "ui_downloadprogress.h"
#include "WindowPos.h"

class QFtp;
class QFile;
class DownloadProgress : public QDialog, public wWindowPos
{
	Q_OBJECT

public:
	DownloadProgress(QWidget *parent = NULL);
	~DownloadProgress();
	enum {WidgetWidth = 500, WidgetHeigth = 40};

public:
	bool	sucess;

	//operators
public:
	//处理
	void processClient2Server();
	//分析xml文档，确定需要下载的补丁包
	void processXml();

	//virtuals
protected:

	//slots
protected slots:
	void ftpCommandFinished(int id, bool error);


	//attributes
protected:
	QFtp* opeFtp;
	QFile* opeFile;

private:
	Ui::downloadprogressclass ui;
};

#endif // DOWNLOADPROGRESS_H
