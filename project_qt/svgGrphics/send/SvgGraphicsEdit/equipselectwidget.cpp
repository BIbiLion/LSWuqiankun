#include "equipselectwidget.h"
#include "comm.h"
#include <QtGui>

equipSelectWidget::equipSelectWidget(QWidget *parent,QString lineName ,
									 QString lineId ,  QString equip ,
									 QString equipId , QString equipName )
	 : m_lineName(lineName),m_lineId(lineId),m_equip(equip),m_equipId(equipId),m_equipName(equipName), QDialog(parent)
{
	connectName = getSqlConnectName();//获取SQL连接名称
	initWidget();
	initWidgetData();
	setWidgetCurrentData();

}

equipSelectWidget::~equipSelectWidget()
{

	removeSqlConnect(connectName);		//移除SQL连接
	
}



void equipSelectWidget::initWidget()
{
	this->setWindowTitle(tr("装置信息"));

	gridLayout = new QGridLayout();
	inforGroupBox = new QGroupBox();

	lineLabel = new QLabel();
	lineLabel->setObjectName(QString::fromUtf8("lineLabel"));
	lineLabel->setText(tr("线路名称"));
	lineNoLabel = new QLabel();
	lineNoLabel->setObjectName(QString::fromUtf8("lineNoLabel"));
	lineNoLabel->setText(tr("线路编号"));

	lineComBox = new QComboBox();
	lineNoComBox = new QComboBox();
	lineComBox->setEditable(true);
	lineNoComBox->setEditable(true);

	

	equipLabel = new QLabel();
	equipLabel->setObjectName(QString::fromUtf8("equipLabel"));
	equipLabel->setText(tr("装置名称"));
	equipNoLabel = new QLabel();
	equipNoLabel->setObjectName(QString::fromUtf8("equipNoLabel"));
	equipNoLabel->setText(tr("装置编号"));

	equipComBox = new QComboBox();
	equipNoComBox = new QComboBox();
	equipComBox->setEditable(true);
	equipNoComBox->setEditable(true);

	equipNameLabel = new QLabel();
	equipNameLabel->setObjectName(QString::fromUtf8("equipNameLabel"));
	equipNameLabel->setText(tr("保护名称"));
	equipLineEdit = new QLineEdit();


	gridLayout->addWidget(lineLabel,      0,0);
	gridLayout->addWidget(lineComBox,     0,1);
	gridLayout->addWidget(lineNoLabel,    0,2);
	gridLayout->addWidget(lineNoComBox,   0,3);
	gridLayout->addWidget(equipLabel,     1,0);
	gridLayout->addWidget(equipComBox,    1,1);
	gridLayout->addWidget(equipNoLabel,   1,2);
	gridLayout->addWidget(equipNoComBox,  1,3);
	gridLayout->addWidget(equipNameLabel, 2,0);
	gridLayout->addWidget(equipLineEdit,  2,1);

	inforGroupBox->setLayout(gridLayout);

	funGroupBox = new QGroupBox();
	funGridLayout = new QGridLayout();

	execBtn = new QPushButton();
    execBtn->setObjectName(QString::fromUtf8("execBtn"));
	execBtn->setText(tr("确定"));

	cancelBtn = new QPushButton();
    cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
	cancelBtn->setText(tr("退出"));

	funGridLayout->addWidget(execBtn,       0,0);
	funGridLayout->addWidget(cancelBtn,     0,1);

	funGroupBox->setLayout(funGridLayout);

	allVBoxLayout = new QVBoxLayout(this);
	allVBoxLayout->addWidget(inforGroupBox);
	allVBoxLayout->addWidget(funGroupBox);


}

void equipSelectWidget::initWidgetData()
{

    initLine();

	connect(lineComBox,    SIGNAL(currentIndexChanged(const QString &)),this, SLOT(lineComBoxChanged(const QString &)));
	connect(lineNoComBox,  SIGNAL(currentIndexChanged(const QString &)),this, SLOT(lineComBoxChanged(const QString &)));
	connect(equipComBox,   SIGNAL(currentIndexChanged(const QString &)),this, SLOT(lineComBoxChanged(const QString &)));
	connect(equipNoComBox, SIGNAL(currentIndexChanged(const QString &)),this, SLOT(lineComBoxChanged(const QString &)));

	connect(execBtn,     SIGNAL(pressed()),this,SLOT(btnSlots()));
	connect(cancelBtn,   SIGNAL(pressed()),this,SLOT(btnSlots()));

}

void equipSelectWidget::setWidgetCurrentData()
{
	
	//lineComBox->setCurrentIndex(lineComBox->findText(m_lineName));
	//lineNoComBox->setCurrentIndex(lineNoComBox->findText(m_lineId));
	//findEquipFromLine(m_lineId);
	//equipComBox->setCurrentIndex(equipComBox->findText(m_equip));
	//equipNoComBox->setCurrentIndex(equipNoComBox->findText(m_equipId));
	lineComBox->setCurrentText(m_lineName);
	lineNoComBox->setCurrentText(m_lineId);
	findEquipFromLine(m_lineId);
	equipComBox->setCurrentText(m_equip);
	equipNoComBox->setCurrentText(m_equipId);
	equipLineEdit->setText(m_equipName);

}

void equipSelectWidget::btnSlots()
{
	QWidget *senderWidget = qobject_cast<QWidget *>(sender());

	if (senderWidget == execBtn)
	{
		m_lineName = lineComBox->currentText();
		m_lineId = lineNoComBox->currentText();
		m_equip = equipComBox->currentText();
		m_equipId = equipNoComBox->currentText();
		m_equipName = equipLineEdit->text();
		QDialog::accept();
	}
	else 
	{
		QDialog::close();

	}

}

void equipSelectWidget::lineComBoxChanged(const QString str)
{

	QWidget *senderWidget = qobject_cast<QWidget *>(sender());

	if (senderWidget == lineComBox)
	{
		QString lineName = lineComBox->currentText();
		QString lineId = findLineNameOrId(1,lineName,"");	
		lineNoComBox->setCurrentIndex(lineNoComBox->findText(lineId));
		findEquipFromLine(lineId);


	}
	else if (senderWidget == lineNoComBox)
	{
		QString lineId = lineNoComBox->currentText();
		QString lineName = findLineNameOrId(2,"",lineId);
		lineComBox->setCurrentIndex(lineComBox->findText(lineName));
		findEquipFromLine(lineId);

	}
	else if (senderWidget == equipComBox)
	{
		QString equipName = equipComBox->currentText();
		QString equipId = findEquipNameOrId(1,equipName,"");
		equipNoComBox->setCurrentIndex(equipNoComBox->findText(equipId));


	}
	else if (senderWidget == equipNoComBox)
	{
		QString equipId = equipNoComBox->currentText();
		QString equipName = findEquipNameOrId(2,"",equipId);
		equipComBox->setCurrentIndex(equipComBox->findText(equipName));

	}


}

void equipSelectWidget::initLine()
{
	

	QSqlQuery			*query;
	QString				sql;
	
	query = new QSqlQuery("",getSqlConnect(connectName));

	sql = tr("SELECT LineId, LineName  FROM LineDef ORDER BY LineId");								
	query->exec(sql);
	while( query->next()){	

		QString lineId = query->value(0).toString();
		QString lineName = query->value(1).toString();

		lineComBox->addItem(lineName);
		lineNoComBox->addItem(lineId);
		
	}

	delete query;


}


QString equipSelectWidget::findLineNameOrId(int type ,QString lineName,QString lineId)
{

	QSqlQuery			*query;
	QString				sql;
	QString             str;
	
	query = new QSqlQuery("",getSqlConnect(connectName));

	if (type == 1)
		sql = tr("SELECT LineId    FROM LineDef WHERE LineName = '%1'").arg(lineName);	
	else 
		sql = tr("SELECT LineName  FROM LineDef WHERE LineId = %1 ").arg(lineId);	

	query->exec(sql);
	while( query->next()){	

		str = query->value(0).toString();
		
	}

	delete query;

	return str;

	
	return "";
}


QString equipSelectWidget::findEquipNameOrId(int type ,QString equipName,QString equipId )
{

	QSqlQuery			*query;
	QString				sql;
	QString             str;
	
	query = new QSqlQuery("",getSqlConnect(connectName));

	if (type == 1)
		sql = QString("SELECT EquipId  FROM EquipDef  where EquipName = '%1' ").arg(equipName);
	else 
		sql = QString("SELECT EquipName  FROM EquipDef  where EquipId = %1 ").arg(equipId);

	query->exec(sql);
	while( query->next()){	

		str = query->value(0).toString();
		
	}

	delete query;

	return str;

	
	return "";
}


void  equipSelectWidget::findEquipFromLine(QString lineId)
{

	QSqlQuery			*query;
	QString				sql;
	QString             str;
	
	query = new QSqlQuery("",getSqlConnect(connectName));

	
	sql = QString("SELECT EquipId ,EquipName FROM EquipDef  where LineId = %1 ").arg(lineId);

	equipNoComBox->clear();
	equipComBox->clear();
	

	query->exec(sql);
	while( query->next()){	

		equipNoComBox->addItem(query->value(0).toString());
		equipComBox->addItem(query->value(1).toString());	
		
	}

	delete query;

}


QString equipSelectWidget::getLineName()
{
	return m_lineName;

}
QString equipSelectWidget::getLineId()
{
	return m_lineId;
}
QString equipSelectWidget::getEquip()
{
	return m_equip;

}

QString equipSelectWidget::getEquipId()
{

	return m_equipId;
}

QString equipSelectWidget::getEquipName()
{
	return m_equipName;

}


stationSelectWidget::stationSelectWidget(QWidget *parent,        
										 QString staId ,
										 QString staName )
	 : m_staId(staId),m_staName(staName), QDialog(parent)
{
	//connectName = getSqlConnectName();//获取SQL连接名称
	initWidget();
	initWidgetData();
	setWidgetCurrentData();

}

stationSelectWidget::~stationSelectWidget()
{

	//removeSqlConnect(connectName);		//移除SQL连接
	
}



void stationSelectWidget::initWidget()
{
	this->setWindowTitle(tr("子站信息"));

	gridLayout = new QGridLayout();
	inforGroupBox = new QGroupBox();

	staLabel = new QLabel();
	staLabel->setObjectName(QString::fromUtf8("staLabel"));
	staLabel->setText(tr("子站名称"));
	staNoLabel = new QLabel();
	staNoLabel->setObjectName(QString::fromUtf8("staNoLabel"));
	staNoLabel->setText(tr("子站编号"));

	staComBox = new QComboBox();
	staNoComBox = new QComboBox();
	staComBox->setEditable(true);
	staNoComBox->setEditable(true);

	gridLayout->addWidget(staNoLabel,    0,0);
	gridLayout->addWidget(staNoComBox,   0,1);
	gridLayout->addWidget(staLabel,      1,0);
	gridLayout->addWidget(staComBox,     1,1);
	
	

	inforGroupBox->setLayout(gridLayout);

	funGroupBox = new QGroupBox();
	funGridLayout = new QGridLayout();

	execBtn = new QPushButton();
    execBtn->setObjectName(QString::fromUtf8("execBtn"));
	execBtn->setText(tr("确定"));

	cancelBtn = new QPushButton();
    cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
	cancelBtn->setText(tr("退出"));

	funGridLayout->addWidget(execBtn,       0,0);
	funGridLayout->addWidget(cancelBtn,     0,1);

	funGroupBox->setLayout(funGridLayout);

	allVBoxLayout = new QVBoxLayout(this);
	allVBoxLayout->addWidget(inforGroupBox);
	allVBoxLayout->addWidget(funGroupBox);


}


void stationSelectWidget::initWidgetData()
{

   initStation();

	connect(staComBox,    SIGNAL(currentIndexChanged(const QString &)),this, SLOT(comBoxChanged(const QString &)));
	connect(staNoComBox,  SIGNAL(currentIndexChanged(const QString &)),this, SLOT(comBoxChanged(const QString &)));
	
	connect(execBtn,     SIGNAL(pressed()),this,SLOT(btnSlots()));
	connect(cancelBtn,   SIGNAL(pressed()),this,SLOT(btnSlots()));

}



void stationSelectWidget::comBoxChanged(const QString str)
{

	QWidget *senderWidget = qobject_cast<QWidget *>(sender());

	if (senderWidget == staComBox)
	{
		QString staName = staComBox->currentText();
		QString staId = findStationOrId(1,staName,"");	
		staNoComBox->setCurrentIndex(staNoComBox->findText(staId));


	}
	else if (senderWidget == staNoComBox)
	{
		QString staId = staNoComBox->currentText();
		QString staName = findStationOrId(2,"",staId);
		staComBox->setCurrentIndex(staComBox->findText(staName));

	}
	
}

void stationSelectWidget::initStation()
{

	/*
	QSqlQuery			*query;
	QString				sql;
	
	query = new QSqlQuery("",getSqlConnect(connectName));

	sql = tr("SELECT StationId, StationName  FROM SystemDef ORDER BY StationId");								
	query->exec(sql);
	while( query->next()){	

		QString staId = query->value(0).toString();
		QString staName = query->value(1).toString();

		staComBox->addItem(staName);
		staNoComBox->addItem(staId);
		
	}

	delete query;

*/

}


void stationSelectWidget::setWidgetCurrentData()
{
	
	//staComBox->setCurrentIndex(staComBox->findText(m_staName));
	//staNoComBox->setCurrentIndex(staNoComBox->findText(m_staId));
	staComBox->setCurrentText(m_staName);
	staNoComBox->setCurrentText(m_staId);
	

}

QString stationSelectWidget::findStationOrId(int type,QString staName,QString staId )
{

	/*
	QSqlQuery			*query;
	QString				sql;
	QString             str;
	
	query = new QSqlQuery("",getSqlConnect(connectName));

	if (type == 1)
		sql = tr("SELECT StationId    FROM SystemDef WHERE StationName = '%1'").arg(staName);	
	else 
		sql = tr("SELECT StationName  FROM SystemDef WHERE StationId = %1 ").arg(staId);	

	query->exec(sql);
	while( query->next()){	

		str = query->value(0).toString();
		
	}

	delete query;

	return str;

	*/
	return "";
}

void stationSelectWidget::btnSlots()
{
	QWidget *senderWidget = qobject_cast<QWidget *>(sender());

	if (senderWidget == execBtn)
	{
		m_staName = staComBox->currentText();
		m_staId   = staNoComBox->currentText();
		
		QDialog::accept();
	}
	else 
	{
		QDialog::close();

	}

}


QString stationSelectWidget::getStatName()
{

	return m_staName;
}
QString stationSelectWidget::getStatId()
{

	return m_staId;

}


