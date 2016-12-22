#include "updaterservermanager.h"
#include "pubfuncs.h"
#include "downloadprogress.h"
#include "../UpdateXmlPlist.h"
#include "IClientCenter.h"
#include <QtGui>
#include <QFileDialog>
#include "CommonFileOperFunction.h"
#include "FtpThread.h"

static QListWidget* pSoftList = 0;
static QListWidget* pPackList = 0;
static QListWidgetItem* lastEditSoftItem = 0;
static QListWidgetItem* lastPackItem = 0;
static CUpdatePack* lastPackData = 0;
static CUpdateXmlPlistTree::EachSoftUpdate* lastSoft = 0;
static QString currentSoftname;
const QString PATHSPILTER = "/";

//更新的队列
struct UpdateDeque 
{
	struct OneRecode
	{
		enum ORType
		{
			addsoft,
			removesoft,
			renamesoft,
			removepack,
			modifypack
		};

		QString name[2];
		QString localefilepath;//本地的文件路径，如果type为add，将被上传
		QString serverfilepath;//服务器上的文件路径，如果type为remove，服务器上的将被删除
		ORType type;//更新的类型 
	};

	static QStringList splitPath(const QString& obj)
	{
		return obj.split(PATHSPILTER, QString::SkipEmptyParts);
	}

	typedef std::list<OneRecode> TListRecodes;
	typedef TListRecodes::iterator TIterRecode;
	TListRecodes d;

	TIterRecode begin() {return d.begin();}
	TIterRecode end() {return d.end();}
	int size() {return SIZE(d);}

	void clear()
	{
		d.clear();
	}

	OneRecode* push_back(OneRecode::ORType type)
	{
		OneRecode xx;
		xx.type = type;
		d.push_back(xx);

		return getLastRecode();
	}

	OneRecode* getLastRecode()
	{
		if (!SIZE(d)) return 0;
		TIterRecode plast = end();
		--plast;
		return &*plast;
	}

	OneRecode* find(const QString& softname, const QString& packname)
	{
		TIterRecode iterrecode = begin();
		while (iterrecode != end())
		{
			if (iterrecode->name[0] == softname && iterrecode->name[1] == packname)
			{
				return &*iterrecode;
			}
		}
		return 0;
	}

	bool existType(OneRecode::ORType _type)
	{
		TIterRecode iterRecode = begin();
		while (iterRecode != end())
		{
			if (iterRecode->type == _type)
			{
				return true;
			}
			++iterRecode;
		}
		return false;
	}
};
static UpdateDeque gUpdateDeque;

UpdaterServerManager::UpdaterServerManager(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	downloadServerPlist();

	//运行 客户端-服务器 更新
	wFtpParam objParam;
	objParam.address = getClientCenter()->ftpAddress;
	objParam.port =getClientCenter()->ftpPort;
	objParam.usr = "Manager";
	objParam.pwd = "Manager";
	pFtpOperator = new wFtpOperator(objParam);

	connect(pFtpOperator, SIGNAL(transferProgress(qint64 , qint64 )),
		this, SLOT(on_ftp_transfer_progress(qint64, qint64)));
	connect(pFtpOperator, SIGNAL(filetransferFinished(bool)),
		this, SLOT(on_ftp_transfer_finished(bool)));
	connect(pFtpOperator, SIGNAL(allCommandsFinished()),
		this, SLOT(on_ftp_cmds_finished()));
}

UpdaterServerManager::~UpdaterServerManager()
{
	pubfunc::release(pFtpOperator);
}

void UpdaterServerManager::on_ftp_transfer_progress(qint64 size, qint64 total)
{
	ui.progressEach->setRange(0, total);
	ui.progressEach->setValue(size);
}

static int currentindex = 0;
static int totalsize = 0;
static bool needInfoMsg = false;
void UpdaterServerManager::on_ftp_transfer_finished(bool download)
{
	if (download) return;
	
	currentindex++;
	ui.progressSubmit->setValue(currentindex);
	if (currentindex == totalsize)
	{
		needInfoMsg = true;
	}
}

void UpdaterServerManager::on_ftp_cmds_finished()
{
	if (needInfoMsg)
	{
		ui.progressSubmit->setRange(0,100);
		ui.progressSubmit->setValue(100);
		ui.progressEach->setRange(0,100);
		ui.progressEach->setValue(100);
		QMessageBox::information(this, tr("info"), tr("commands acomplished"));
		needInfoMsg = false;
	}
}

//提交所有的更改
void UpdaterServerManager::on_submit_clicked()
{
	//初始化主进度栏
	currentindex = 0;

	//遍历所有的记录数据，发现需要上传的补丁则上传
	UpdateDeque::TIterRecode iterRecode = gUpdateDeque.begin();
	while (iterRecode != gUpdateDeque.end())
	{
		pFtpOperator->intodirectory("~");//先返回至根目录

		const UpdateDeque::OneRecode* pRecode = &*iterRecode;

		//根据记录的类型进行同步
		switch (pRecode->type)
		{
		case UpdateDeque::OneRecode::addsoft://新增一个软件
			pFtpOperator->createdirectory(pRecode->name[0]);
			break;
		case UpdateDeque::OneRecode::removesoft://移除一个软件
			pFtpOperator->removedirectory(pRecode->name[0]);
			break;
		case UpdateDeque::OneRecode::modifypack://新增一个补丁
			totalsize++;
			pFtpOperator->upload(pRecode->localefilepath, pRecode->serverfilepath);
			break;
		case UpdateDeque::OneRecode::renamesoft://修改软件名称
			pFtpOperator->renamedirectory(pRecode->name[0], pRecode->name[1]);
			break;
		case UpdateDeque::OneRecode::removepack://移除补丁
			pFtpOperator->intodirectory(pRecode->name[0]);
			pFtpOperator->removefile(pRecode->name[1]);
			break;
		}

		++iterRecode;
	}
	gUpdateDeque.clear();

	//保存文件
	getUpdateXmlPlistServerTree()->saveToPlistServer("./_recipes/server.plist");
	//上传服务器端的文件
	pFtpOperator->intodirectory("~");//根目录
	pFtpOperator->upload("./_recipes/server.plist", "server.plist");

	//运行更新
	pFtpOperator->ProcOperations();

	//设置
	ui.progressSubmit->setRange(currentindex, totalsize ? totalsize : 100);
	ui.progressSubmit->setValue(totalsize ? currentindex : 100);

	//
	needInfoMsg = true;
}

void UpdaterServerManager::downloadServerPlist()
{	
	DownloadProgress download;
	download.exec();

	if (!download.sucess)
	{
		QApplication::exit(0);
	}

	pSoftList = ui.SoftList;
	pPackList = ui.PackList;
	connect(pSoftList, SIGNAL(itemClicked(QListWidgetItem*)),
		this, SLOT(on_list_soft_itemclick(QListWidgetItem*)));
	connect(pSoftList, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
		this, SLOT(on_list_soft_itemdoubleclick(QListWidgetItem*)));
	connect(pSoftList, SIGNAL(itemChanged(QListWidgetItem*)),
		this, SLOT(on_list_soft_itemchange(QListWidgetItem*)));

	connect(pPackList, SIGNAL(itemSelectionChanged()),
		this, SLOT(on_list_pack_itemselchanged()));

	putPacksIntoList();
}

void UpdaterServerManager::putPacksIntoList()
{
	pSoftList = ui.SoftList;
	pPackList = ui.PackList;
	pSoftList->clear();
	pPackList->clear();

	CUpdateXmlPlistTree* pServerPlist = (CUpdateXmlPlistTree*)getUpdateXmlPlistServerTree();
	CUpdateXmlPlistTree::TIterEachSoftware iterSoft = pServerPlist->begin();
	while (iterSoft != pServerPlist->end())
	{
		CUpdateXmlPlistTree::EachSoftUpdate* pSoft = &iterSoft->second;
		pSoftList->addItem(pSoft->softName);
		++iterSoft;
	}
}

void UpdaterServerManager::softitemCloseEdit(bool autosel)
{
	if (lastEditSoftItem)
	{
		pSoftList->closePersistentEditor(lastEditSoftItem);
		if (autosel)
			pSoftList->setCurrentItem(lastEditSoftItem);

		softitemTextEdited(lastEditSoftItem);
		lastEditSoftItem = 0;
	}

	QListWidgetItem* pitem = pSoftList->currentItem();
	if (pitem)
	{
		currentSoftname = pitem->text();
	}
}

//修改软件名称
void UpdaterServerManager::softitemTextEdited(QListWidgetItem* item)
{
	QString editedname = item->text();
	if (editedname == currentSoftname)
		return;//没有修改

	getUpdateXmlPlistServerTree()->renameSoft(currentSoftname, editedname);

	//放入修改队列,由于是修改软件名称，所以name的0为软件原始名称，1为更新名称
	UpdateDeque::OneRecode* precode = gUpdateDeque.push_back(UpdateDeque::OneRecode::renamesoft);
	precode->name[0] = currentSoftname;
	precode->name[1] = editedname;
}

void UpdaterServerManager::on_list_soft_itemclick(QListWidgetItem *item)
{
	if (lastEditSoftItem && lastEditSoftItem != item)
	{
		softitemCloseEdit();
	}

	currentSoftname = item->text();

	CUpdateXmlPlistTree* pServerTree = (CUpdateXmlPlistTree*)getUpdateXmlPlistServerTree();
	//刷新packlist
	pPackList->clear();
	ui.comboBoxValidPacks->clear();
	ui.comboBoxValidPacks->addItem("-----");
	ui.listPackDependPacks->clear();

	if (pServerTree->isSoftFound(currentSoftname))
	{
		CUpdateXmlPlistTree::TIterEachSoftware objsoft = pServerTree->findSoft(currentSoftname);
		CUpdateXmlPlistTree::EachSoftUpdate* pObjSoft = &objsoft->second;
		CUpdateXmlPlistTree::EachSoftUpdate::TIterEachPack iterPack = pObjSoft->begin();
		while (iterPack != pObjSoft->end())
		{
			CUpdatePack* pPack = &*iterPack;
			//放入补丁的信息
			pPackList->addItem(new QListWidgetItem(pPack->name));

			//初始化依赖pack可供选择的列表
			ui.comboBoxValidPacks->addItem(pPack->name);
			++iterPack;
		}
		ui.comboBoxValidPacks->setCurrentIndex(0);
	}

	//设置补丁的当前软件字段
	ui.editPackSoft->setText(item->text());
}

//当pack表换选时，需要栓新项目数据显示
void UpdaterServerManager::on_list_pack_itemselchanged()
{
	QListWidgetItem* ppackitem = pPackList->currentItem();
	QListWidgetItem* psoftitem = pSoftList->currentItem();
	if (!ppackitem || !psoftitem)
	{
		return;
	}

	QString softname = psoftitem->text();
	QString packname = ppackitem->text();

	//找到对应的软件
	CUpdateXmlPlistTree* pServerTree = (CUpdateXmlPlistTree*)getUpdateXmlPlistServerTree();
	CUpdateXmlPlistTree::EachSoftUpdate* pSoft = &pServerTree->findSoft(softname)->second;
	CUpdatePack* pPack = pSoft->findPackPt(packname);
	
	bool exist = pPack;//是否存在该补丁，不存在则清空所有的显示
	//刷新数据

	//刷新依赖项
	ui.listPackDependPacks->clear();
	if (exist)
	{
		CUpdatePack::TIterDependPack iterDependPack = pPack->dependPacksBegin();
		while (iterDependPack != pPack->dependPacksEnd())
		{
			ui.listPackDependPacks->addItem(iterDependPack->first);
			++iterDependPack;
		}
	}

	//其他数据，均输出直接复制的
	ui.editPackPublishTime->setText(QString::number(pPack ? pPack->publishTime : 0));
	ui.editPackFileName->setText(pPack ? pPack->packName : "");
	ui.editPackSize->setText(pPack ? pPack->packSize : "");
	ui.editPackMd5->setText(pPack ? pPack->md5 : "");
	ui.textPackInfo->setHtml(pPack ? pPack->info : "");
	ui.editPackName->setText(pPack ? pPack->name : "");
	ui.editPackSoft->setText(pPack ? pPack->softname : softname);
	ui.editPackSoftMinTime->setText(QString::number(pPack ? pPack->minSoftTime : 0));
	ui.checkPackSelfUpdater->setChecked(pPack ? pPack->isSelfUpdate : false);
	ui.checkPackShowUi->setChecked(pPack ? pPack->needUiShow : false);
	ui.checkDebug->setChecked(pPack ? pPack->debugmode : false);
	ui.checkMustdownload->setChecked(pPack ? pPack->mustdownload : false);
	ui.editPackPath->setText("");//清空路径
	ui.editPackSoftKey->setText(QString::number(pPack ? pPack->appendKey : 1));
}

//双击，进入修改模式
void UpdaterServerManager::on_list_soft_itemdoubleclick(QListWidgetItem* item)
{
	if (!lastEditSoftItem)
	{
		lastEditSoftItem = item;
	}

	pSoftList->openPersistentEditor(item);
	lastEditSoftItem = item;
}

//增加软件
void UpdaterServerManager::on_addsoft_clicked()
{
	//关闭修改
	softitemCloseEdit();

	const QString oritext(tr("newsoft"));

	//遍历所有的text，不能存在和newsoft 相通的项
	for (int rowi = 0; rowi < pSoftList->count(); rowi++)
	{
		QString itemtext = pSoftList->item(rowi)->text();
		if (itemtext == oritext)
		{
			QMessageBox::information(0, tr("info"), tr("soft exist"));
			return;
		}
	}

	QListWidgetItem* pItem = new QListWidgetItem(pSoftList);
	pItem->setFlags(Qt::ItemIsEditable | Qt::ItemIsSelectable);
	pItem->setText(oritext);

	getUpdateXmlPlistServerTree()->addSoft(oritext);

	//放入修改队列
	UpdateDeque::OneRecode* precode = gUpdateDeque.push_back(UpdateDeque::OneRecode::addsoft);
	precode->name[0] = oritext;
}

//移除软件
void UpdaterServerManager::on_removeSoft_clicked()
{
	//关闭soft的修改
	softitemCloseEdit(true);

	//先确定是否可以移除（updatequeue中不存在addsoft项目
	if (gUpdateDeque.existType(UpdateDeque::OneRecode::addsoft))
	{
		QMessageBox::information(this, tr("info"), tr("please submit first"));
		return;
	}

	QListWidgetItem* psoftitem = pSoftList->currentItem();
	if (!psoftitem)
	{
		QMessageBox::information(this, tr("info"), tr("please select a soft"));
		return;
	}

	QString softname = psoftitem->text();
	getUpdateXmlPlistServerTree()->removeSoft(softname);

	//
	UpdateDeque::OneRecode* precode = gUpdateDeque.push_back(UpdateDeque::OneRecode::removesoft);
	precode->name[0] = softname;

	//
	putPacksIntoList();//重新写入列表，qlistwidget的removeitem功能无用
}

//添加补丁
void UpdaterServerManager::on_addPack_clicked()
{
	//关闭soft的修改
	softitemCloseEdit(true);

	const QListWidgetItem* psoftitem = pSoftList->currentItem();
	if (!psoftitem)
	{
		QMessageBox::information(0, tr("info"), tr("please select a soft"));
		return;
	}

	const QString oritext(tr("newpack"));
	//遍历所有的text，不能存在和newsoft 相通的项
	for (int rowi = 0; rowi < pPackList->count(); rowi++)
	{
		QString itemtext = pPackList->item(rowi)->text();
		if (itemtext == oritext)
		{
			QMessageBox::information(0, tr("info"), tr("pack exist"));
			return;
		}
	}

	pPackList->addItem(oritext);
	//由于默认生成的补丁包为所有数值都是空的，所以只有当用户点击 更新补丁信息 按钮后，才真正把补丁放入上传序列
}

//移除补丁
void UpdaterServerManager::on_removePack_clicked()
{
	//关闭soft的修改
	softitemCloseEdit(true);

	QListWidgetItem* ppackitem = pPackList->currentItem();
	QListWidgetItem* psoftitem = pSoftList->currentItem();
	if (!ppackitem || !psoftitem)
	{
		QMessageBox::information(0, tr("info"), tr("please select a pack"));
		return;
	}

	QString softname = psoftitem->text();
	QString packname = ppackitem->text();
	QString packfilename = ui.editPackFileName->text();

	CUpdateXmlPlistTree* pServerTree = (CUpdateXmlPlistTree*)getUpdateXmlPlistServerTree();
	pServerTree->removePack(softname, packname);

	//
	UpdateDeque::OneRecode* precode = gUpdateDeque.push_back(UpdateDeque::OneRecode::removepack);
	precode->name[0] = softname;
	precode->name[1] = packfilename;

	//刷新packlist
	pPackList->clear();
	ui.comboBoxValidPacks->clear();
	ui.comboBoxValidPacks->addItem("-----");
	ui.listPackDependPacks->clear();

	if (pServerTree->isSoftFound(softname))
	{
		CUpdateXmlPlistTree::TIterEachSoftware objsoft = pServerTree->findSoft(softname);
		CUpdateXmlPlistTree::EachSoftUpdate* pObjSoft = &objsoft->second;
		CUpdateXmlPlistTree::EachSoftUpdate::TIterEachPack iterPack = pObjSoft->begin();
		while (iterPack != pObjSoft->end())
		{
			CUpdatePack* pPack = &*iterPack;
			//放入补丁的信息
			pPackList->addItem(new QListWidgetItem(pPack->name));

			//初始化依赖pack可供选择的列表
			ui.comboBoxValidPacks->addItem(pPack->name);
			++iterPack;
		}
		ui.comboBoxValidPacks->setCurrentIndex(0);
	}
}

//浏览补丁文件
void UpdaterServerManager::on_browserPack_clicked()
{
	QString filepath = QFileDialog::getOpenFileName(this, tr("locate a pack file"), QString(), "packfile (*.exe)");
	if (filepath.isEmpty())
		return;

	ui.editPackPath->setText(filepath);

	//找到补丁文件，则计算文件大小以及md5
	QFile packfile(filepath);
	packfile.open(QIODevice::ReadOnly);
	qint64 packfilesize = packfile.size();
	packfile.close();
	ui.statusBar->showMessage(tr("calc md5"));
	QString md5 = wFileFunc::calcFileMd5(filepath);
	ui.statusBar->clearMessage();
	ui.editPackMd5->setText( md5 );
	//需要将byte换算成K,M或者G
	int k = int(packfilesize / 1024);
	int m = int(packfilesize / 1024 / 1024);
	int g = int(packfilesize /1024 / 1024 / 1024);
	int t = int(packfilesize / 1024 / 1024 / 1024 / 1024);
	QString filesize;
	if (k == 0)
	{
		filesize = QString::number(packfilesize) + "B";
	}
	else if ( m == 0)
	{
		filesize = QString::number(k) + "KB";
	}
	else if ( g == 0)
	{
		filesize = QString::number(m) + "MB";
	}
	else
		filesize = QString::number(g) + "GB";
	ui.editPackSize->setText( filesize );

	QStringList filelist = filepath.split("/",QString::SkipEmptyParts);
	ui.editPackFileName->setText(filelist.at(filelist.size() -1));

	//将exe换成txt，自动从nsis打包程序获取补丁的信息
	QString infofile = filepath.replace(".exe", ".txt", Qt::CaseInsensitive);
	if (QFile::exists(infofile))
	{
		QFile xfile(infofile);
		if (xfile.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QByteArray linedata = xfile.readLine();
			linedata = linedata.left(linedata.count() -1);//去除掉/0
			QString linestr(linedata);
			ui.editPackName->setText(linestr);//显示名称
			linestr = QString(xfile.readLine());
			ui.editPackPublishTime->setText(linestr);//发布时间
			linestr = QString(xfile.readLine());
			ui.checkPackShowUi->setChecked(linestr.toInt() == 0 ? false : true);//安装过程中显示界面
			linestr = QString(xfile.readLine());
			ui.checkPackSelfUpdater->setChecked(linestr.toInt() == 0 ? false : true);//自升级包
			linestr = QString(xfile.readLine());
			ui.editPackSoftKey->setText(linestr);//软件锁类型

			linestr = QString(xfile.readAll());
			ui.textPackInfo->setHtml(linestr);

			xfile.close();
		}
		else
			QMessageBox::information(this, tr("info"), tr("failed to open info file"));
	}
	else
	{
		QMessageBox::information(this, tr("info"), tr("info file lost"));
	}
}

void UpdaterServerManager::on_refreshPackInfo_clicked()
{
	QListWidgetItem* ppackitem = pPackList->currentItem();
	QListWidgetItem* psoftitem = pSoftList->currentItem();
	if (!ppackitem || !psoftitem)
	{
		QMessageBox::information(0, tr("info"), tr("please select a pack"));
		return;
	}

	QString softname = psoftitem->text();
	QString packname = ppackitem->text();
	
	//更新界面数据到树之上
	CUpdateXmlPlistTree* pServerTree = (CUpdateXmlPlistTree*)getUpdateXmlPlistServerTree();
	CUpdateXmlPlistTree::EachSoftUpdate* pSoft = &pServerTree->findSoft(softname)->second;
	CUpdatePack* pPack;bool needrelease = false;
	if (!pSoft->isPackFound(packname))
	{
		pPack = new CUpdatePack();
		needrelease = true;

		pPack->softname = softname;
	}
	else
	{
		CUpdateXmlPlistTree::EachSoftUpdate::TIterEachPack iterpack = pSoft->findPack(packname);
		pPack = &*iterpack;
	}

	//对pack进行修改
	if (pPack->md5 != ui.editPackMd5->text())
	{
		UpdateDeque::OneRecode* pRecode = gUpdateDeque.push_back(UpdateDeque::OneRecode::modifypack);

		pPack->md5 = ui.editPackMd5->text();
		pPack->packName = ui.editPackFileName->text();
		pPack->packSize = ui.editPackSize->text();

		pRecode->localefilepath = ui.editPackPath->text();
		pRecode->serverfilepath = pPack->getServerPath();
	}

	//其余的直接改变信息
	pPack->name = ui.editPackName->text();
	ppackitem->setText(pPack->name);
	pPack->info = ui.textPackInfo->toHtml();
	pPack->softname = softname;
	pPack->isSelfUpdate = ui.checkPackSelfUpdater->isChecked();
	pPack->minSoftTime = ui.editPackSoftMinTime->text().toLongLong();
	pPack->needUiShow = ui.checkPackShowUi->isChecked();
	pPack->publishTime = ui.editPackPublishTime->text().toLongLong();
	pPack->debugmode = ui.checkDebug->isChecked();
	pPack->mustdownload = ui.checkMustdownload->isChecked();
	pPack->dependPacks.clear();
	pPack->appendKey = ui.editPackSoftKey->text().toInt();
	for (int dlistrowi = 0; dlistrowi < ui.listPackDependPacks->count(); dlistrowi++)
	{
		QString dstr = ui.listPackDependPacks->item(dlistrowi)->text();
		pPack->dependPacks.insert(std::make_pair(dstr, true));
	}

	if (needrelease)
	{
		pServerTree->addPack(pPack);
		pubfunc::release(pPack);
	}

	//刷新combo
	ui.comboBoxValidPacks->clear();
	ui.comboBoxValidPacks->addItem("-----");
	CUpdateXmlPlistTree::TIterEachSoftware objsoft = pServerTree->findSoft(currentSoftname);
	CUpdateXmlPlistTree::EachSoftUpdate* pObjSoft = &objsoft->second;
	CUpdateXmlPlistTree::EachSoftUpdate::TIterEachPack iterPack = pObjSoft->begin();
	while (iterPack != pObjSoft->end())
	{
		CUpdatePack* pPack = &*iterPack;
		//初始化依赖pack可供选择的列表
		ui.comboBoxValidPacks->addItem(pPack->name);
		++iterPack;
	}
	ui.comboBoxValidPacks->setCurrentIndex(0);
}


void UpdaterServerManager::on_addPackDepend_clicked()
{
	QListWidgetItem* ppackitem = pPackList->currentItem();
	QListWidgetItem* psoftitem = pSoftList->currentItem();
	if (!ppackitem || !psoftitem)
	{
		QMessageBox::information(0, tr("info"), tr("please select a pack"));
		return;
	}

	QString packname = ui.comboBoxValidPacks->currentText();
	if (packname == QString("-----"))
	{
		return;
	}

	if (packname != ppackitem->text())//如果选中的是自己，则不能用来依赖
		ui.listPackDependPacks->addItem(new QListWidgetItem(packname));
	else
		QMessageBox::information(this, tr("info"), tr("can`t use self as a depended pack "));
}

void UpdaterServerManager::on_removeDepend_clicked()
{
	if (!ui.listPackDependPacks->count())
		return;

	QListWidgetItem* pitem = ui.listPackDependPacks->currentItem();
	if (!pitem)
	{
		QMessageBox::information(this, tr("info"), tr("select a pack"));
		return;
	}

	ui.listPackDependPacks->removeItemWidget(pitem);
}

//启动打包程序
void UpdaterServerManager::on_runPackApp_clicked()
{
	QString packapp = "./UpdaterMaker.exe";
	if (!QFile::exists(packapp))
	{
		QMessageBox::information(this, tr("info"), tr("packmaker lost"));
		return;
	}

	QProcess::execute(packapp);
}

void UpdaterServerManager::on_pushButtonImportInfo_clicked()
{
	QString filepath = QFileDialog::getOpenFileName(this, tr("locate a info file"), QString(), "infofile (*.html | *.txt)");
	if (filepath.isEmpty())
		return;

	ui.textPackInfo->clear();

	QFile xfile(filepath);
	if (xfile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QByteArray xdate = xfile.readAll();
		ui.textPackInfo->setHtml(QString(xdate));
		xfile.close();
	}
}