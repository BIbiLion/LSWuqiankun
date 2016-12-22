#ifndef EQUIPSELECTWIDGET_H
#define EQUIPSELECTWIDGET_H

#include <QDialog>

class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class QVBoxLayout;
class QGridLayout;
class QGroupBox;

class equipSelectWidget : public QDialog
{
	Q_OBJECT

public:
	equipSelectWidget(QWidget *parent,        QString lineName = "",
		                QString lineId = "",  QString equip = "",
						QString equipId = "", QString equipName = "");
	~equipSelectWidget();

private:
	
	QString   connectName;					//数据库连接名称

	QGridLayout  *gridLayout;
	QLabel       *lineLabel;
	QComboBox    *lineComBox;
	QLabel       *lineNoLabel;
	QComboBox    *lineNoComBox;

    QLabel       *equipLabel;
	QComboBox    *equipComBox;
	QLabel       *equipNoLabel;
	QComboBox    *equipNoComBox;

    QLabel       *equipNameLabel;
	QLineEdit    *equipLineEdit;

	QGridLayout  *funGridLayout;
	QPushButton  *execBtn;
	QPushButton  *cancelBtn;

	QGroupBox    *inforGroupBox;
	QGroupBox    *funGroupBox;
	QVBoxLayout  *allVBoxLayout;

	QString      m_lineName;
	QString      m_lineId;
	QString      m_equip;
	QString      m_equipId;
	QString      m_equipName;

	void initWidget();
	void initWidgetData();
	void setWidgetCurrentData();

	void initLine();
	QString findLineNameOrId(int type = 1,QString lineName= "",QString lineId = "");
	QString findEquipNameOrId(int type = 1,QString equipName= "",QString equipId = "");
	void    findEquipFromLine(QString lineId);

public:

	QString getLineName();
	QString getLineId();
	QString getEquip();
	QString getEquipId();
	QString getEquipName();

public slots:

	void lineComBoxChanged(const QString  str);
	void btnSlots();

};

class stationSelectWidget : public QDialog
{
	Q_OBJECT
public:
	stationSelectWidget(QWidget *parent,        
		                QString staId = "",
		                QString staName = "");

	~stationSelectWidget();

private:
	
	QString   connectName;					//数据库连接名称

	QGridLayout  *gridLayout;
	QLabel       *staLabel;
	QComboBox    *staComBox;
	QLabel       *staNoLabel;
	QComboBox    *staNoComBox;


	QGridLayout  *funGridLayout;
	QPushButton  *execBtn;
	QPushButton  *cancelBtn;

	QGroupBox    *inforGroupBox;
	QGroupBox    *funGroupBox;
	QVBoxLayout  *allVBoxLayout;

	QString      m_staName;
	QString      m_staId;

	void initWidget();
	void initWidgetData();
	void setWidgetCurrentData();

	void initStation();
	QString findStationOrId(int type = 1,QString staName= "",QString staId = "");

public:

	QString getStatName();
	QString getStatId();
public slots:

	void comBoxChanged(const QString  str);
	void btnSlots();

};


#endif // EQUIPSELECTWIDGET_H
