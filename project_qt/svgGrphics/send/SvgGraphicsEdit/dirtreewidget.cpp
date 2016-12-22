#include "dirtreewidget.h"
//#include "comm.h"
#include <QtGui>
#include <QtCore>

DirTreeWidget::DirTreeWidget(QWidget *parent)
	: QTreeWidget(parent)
{
    setAcceptDrops(true);
	//connectName = getSqlConnectName();//获取SQL连接名称
	initTree();

	
	connect(this,   SIGNAL(itemPressed( QTreeWidgetItem * , int )), this, SLOT(itemPressed( QTreeWidgetItem * , int )));
}


DirTreeWidget::~DirTreeWidget()
{

	//removeSqlConnect(connectName);		//移除SQL连接
}



QString DirTreeWidget::getStationName()
{
	/*

	QSqlQuery	*query;
	QString     strSql;   
	QString     strStatinName;

	query = new QSqlQuery("",getSqlConnect(connectName));

	strSql = "SELECT StationName  FROM SystemDef";

	query->exec(strSql);

	while( query->next()){	
		strStatinName = query->value(0).toString(); 
		strStatinName = strStatinName.trimmed(); 	
	}

	return strStatinName;

	*/
	return "";
}




int DirTreeWidget::getStationId()
{
	/*

	QSqlQuery	*query;
	QString     strSql;   
	int         staId;

	query = new QSqlQuery("",getSqlConnect(connectName));

	strSql = "SELECT StationId  FROM SystemDef";

	query->exec(strSql);

	while( query->next()){	
		staId = query->value(0).toInt(); 
		
	}

	return staId;

	*/
	return 0;
}




void DirTreeWidget::fillLine(QTreeWidgetItem *parent,DirStruct dirData)
{
/*
	QSqlQuery			*query;
	QString				sql;
	
	query = new QSqlQuery("",getSqlConnect(connectName));

	sql = tr("SELECT LineId, LineName  FROM LineDef ORDER BY LineId");								
	query->exec(sql);
	while( query->next()){		
		int lineId = query->value(0).toInt();
		QString lineName = query->value(1).toString();
		dirData.lineId = lineId;
		dirData.lineName = lineName;

		dirData.type = LINE;
		dirData.equipId = 0;
		dirData.equipName = "equipName";
		dirData.staId = 0;
		dirData.staName = "stationName";
		QTreeWidgetItem* lineItem = createChildItem(parent,dirData);
		dirData.type = EQUIP;
		fillEquip(lineItem,dirData);

	}

	delete query;
	*/

}


void DirTreeWidget::fillEquip(QTreeWidgetItem *parent,DirStruct dirData)
{
	/*
	QSqlQuery	*query;
	QString     strSql;  
	int         id;
	QString     equipName;
	

	query = new QSqlQuery("",getSqlConnect(connectName));

	strSql = QString("SELECT EquipId,EquipName  FROM EquipDef  where LineId = %1 order by EquipId").arg(dirData.lineId);
	query->exec(strSql);

	while( query->next()){	
		int id = query->value(0).toInt();
		QString equipName = query->value(1).toString();
		dirData.equipId = id;
		dirData.equipName = equipName;
		createChildItem(parent,dirData);
	}

	delete query;
*/
}

QTreeWidgetItem* DirTreeWidget::createChildItem(QTreeWidgetItem *item,DirStruct dirData)
{

	 QTreeWidgetItem *childItem;
	 QIcon icon;
     if (item) {
         childItem = new QTreeWidgetItem(item);
     } else {
         childItem = new QTreeWidgetItem(this);
     }

	 QString text ;
	 switch(dirData.type){
		case STATION:
			text = dirData.staName;
			childItem->setIcon(0,QIcon(QDir::currentPath() + "/images/dirtree/" + "station.png"));
		    break;
		case LINE:
			text = dirData.lineName;
			childItem->setIcon(0,QIcon(QDir::currentPath() + "/images/dirtree/" + "line.png"));
			break;
		case EQUIP:
			text = dirData.equipName;
			childItem->setIcon(0,QIcon(QDir::currentPath() + "/images/dirtree/" + "equip.png"));
			break;
		default:
			text = dirData.equipName;
			childItem->setIcon(0,QIcon(QDir::currentPath() + "/images/dirtree/" + "equip.png"));
			break;
	 }


	 QVariant v;
	 v.setValue(dirData);
	 childItem->setData(0,Qt::UserRole+1,v);
	 childItem->setText(0,text);
	 
     return childItem;

}


void DirTreeWidget::initTree()
{
    DirStruct dirData;

	dirData.staId = getStationId();
	dirData.staName = getStationName();
	dirData.type = STATION;
	dirData.equipId = 0;
	dirData.equipName = "equipName";
	dirData.lineId = 0;
	dirData.lineName = "lineName";
	QTreeWidgetItem *root = createChildItem(NULL,dirData);
	root->setExpanded(true); 

	dirData.type = LINE;
	fillLine(root,dirData);

}


void DirTreeWidget::itemPressed( QTreeWidgetItem * item, int column )
{

	 QMimeData *mimeData = new QMimeData;
	  

	 DirStruct dirData;
     QVariant v;

	 v = item->data(column,Qt::UserRole+1);
	 if (v.canConvert<DirStruct>())
        dirData = v.value<DirStruct>();
	
	 int		staId = dirData.staId;
	 QString	staName = dirData.staName;
	 int		lineId= dirData.lineId;
	 QString	lineName= dirData.lineName;
	 int		equipId= dirData.equipId;
	 QString	equipName= dirData.equipName;
	 fillType	type= dirData.type;

     mimeData->setText(QString("%1 %2 %3 %4 %5 %6 %7")
		       .arg(staId)
			   .arg(staName)
			   .arg(lineId)
			   .arg(lineName)
			   .arg(equipId)
			   .arg(equipName)
			   .arg(type));
     
     QDrag *drag = new QDrag(this);
     drag->setMimeData(mimeData);

     Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);

}

void  DirTreeWidget:: dragMoveEvent(QDragMoveEvent *event)
{

	if ((event->pos() - dragStartPosition).manhattanLength() < QApplication::startDragDistance())
        return;

	if (event->mimeData()->hasText()) {
         if (children().contains(event->source())) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
         } else {
             event->acceptProposedAction();
         }
     } else {
         event->ignore();
     }
}


void DirTreeWidget::dragEnterEvent(QDragEnterEvent *event)

 {

    if (event->mimeData()->hasText()) {
         if (children().contains(event->source())) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
         } else {
             event->acceptProposedAction();
         }
     } else {
         event->ignore();
     }
 }

void DirTreeWidget::dropEvent(QDropEvent *event)

 {

	 if (event->mimeData()->hasText()) {
         QStringList pieces = event->mimeData()->text().split(QRegExp("\\s+"),
                              QString::SkipEmptyParts);
         QPoint position = event->pos();

         if (children().contains(event->source())) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
         } else {
             event->acceptProposedAction();
         }
     } else {
         event->ignore();
     }

 }