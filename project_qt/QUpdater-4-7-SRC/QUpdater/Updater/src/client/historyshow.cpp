#include "historyshow.h"
#include "IClientCenter.h"
#include "../UpdateXmlPlist.h"
#include <QtGui>
#include <QtCore>
#include <QStandardItemModel>

HistoryShow::HistoryShow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//初始化数据
	QTreeView* pTree = ui.treeHistory;

	//列表
	QStandardItemModel* pStdItemModel = new QStandardItemModel();
	pStdItemModel->clear();
	pStdItemModel->setHorizontalHeaderLabels(QStringList() << tr("name") << tr("date") << tr("soft"));
	QSortFilterProxyModel* pmodelSortFilterProxy = new QSortFilterProxyModel();
	pmodelSortFilterProxy->setDynamicSortFilter(true);
	pmodelSortFilterProxy->setSourceModel(pStdItemModel);
	pTree->setRootIsDecorated(false);
	pTree->setAlternatingRowColors(true);
	pTree->setModel(pmodelSortFilterProxy);
	pTree->setSortingEnabled(true);
	pTree->sortByColumn(2, Qt::AscendingOrder);

	CUpdateXmlPlistTree* pData = (CUpdateXmlPlistTree*)getUpdateXmlPlistClientTree();
	//遍历已安装的所有补丁
	CUpdateXmlPlistTree::TIterEachSoftware iterSoft = pData->begin();
	while (iterSoft != pData->end())
	{
		CUpdateXmlPlistTree::EachSoftUpdate::TIterEachPack iterPack = iterSoft->second.begin();
		while (iterPack != iterSoft->second.end())
		{
			CUpdatePack* pPack = &*iterPack;
			//显示

			if (pPack->isValid())
			{
				QList<QStandardItem*> columns;
				QStandardItem* name = new QStandardItem(pPack->name);
				name->setEditable(false);

				QString datestr = QString::number(pPack->publishTime);
				QStandardItem* date = new QStandardItem(datestr);
				QString dateyear, datemonth, dateday;
				date->setText(datestr);
				datestr.remove(dateyear = datestr.left(4));
				datestr.remove(datemonth = datestr.left(2));
				datestr.remove(dateday = datestr.left(2));
				date->setData(QDate(dateyear.toInt(), datemonth.toInt(), dateday.toInt()));
				date->setEditable(false);

				//QStandardItem* size = new QStandardItem(pPack->packSize);
				//size->setEditable(false);

				QStandardItem* softname = new QStandardItem(pPack->softname);
				softname->setEditable(false);

				columns << name << date /*<< size*/ << softname;
				pStdItemModel->appendRow(columns);
			}

			++iterPack;
		}

		++iterSoft;
	}
}

HistoryShow::~HistoryShow()
{

}
