#ifndef COMM_H
#define COMM_H

#include <QtSql/QSqlDatabase> 
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtXml/QDomDocument>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QObject>

#define Q_OS_WIN

#if defined(Q_OS_WIN) 
	#include <windows.h>
#endif

#if defined(Q_OS_UNIX) 
	#define sleep(msec) usleep(1000*msec)
#elif defined(Q_OS_WIN)
    #define sleep(msec) Sleep(msec)
#endif


//装置信息
typedef struct
{
	QString			driver;
	QString			database;
	QString			user;
	QString			password;
	QString			host;
}ConnParam;	


//获取连接参数
inline void getConnectParam(ConnParam &connParam)
{
	QDomNodeList		albums;
	QString				errorStr;
	int					errorLine;
	int					errorColumn;
    QDomDocument		domDocument;

	QString fileName = QDir::currentPath()+"/config/config.xml";

	QFile file(QDir::currentPath()+"/config/config.xml");
	if (!file.open(QFile::ReadOnly | QFile::Text)) 
		return;

	if (!domDocument.setContent(&file, true, &errorStr, &errorLine,&errorColumn)) 
		return;

	QDomElement root = domDocument.documentElement();
	if (root.tagName() != "Param")
		return;

	albums = domDocument.elementsByTagName("Driver");
	if( albums.count() > 0)
		connParam.driver = albums.item(0).toElement().text();

	albums = domDocument.elementsByTagName("DBServer");
	if( albums.count() > 0)
		connParam.host = albums.item(0).toElement().text();	

	albums = domDocument.elementsByTagName("DataBase");
	if( albums.count() > 0)
		connParam.database = albums.item(0).toElement().text();
	
	albums = domDocument.elementsByTagName("UserName");
	if( albums.count() > 0)
		connParam.user = albums.item(0).toElement().text();
	
	albums = domDocument.elementsByTagName("Password");
	if( albums.count() > 0)
		connParam.password = albums.item(0).toElement().text();
}


//获取SQL连接名称
inline QString getSqlConnectName()
{
	static int			i;
	QString				name;				

	i++;
	name =  QObject::tr("%1").arg(i);

	return name;
}


//获取SQL连接
inline QSqlDatabase getSqlConnect(QString connName)
{
	bool			connStatus = true;
	QSqlDatabase	db; 

	if( QSqlDatabase::contains(connName))
	{
		db = QSqlDatabase::database(connName);

		QSqlQuery	query("", db);
		query.exec("SELECT StationId FROM SystemDef");

		QSqlError err = query.lastError();
		if( err.number() == 2006)
		{
			QSqlDatabase::removeDatabase(connName);
			connStatus = false;
		}
	}
	else
	{
		connStatus = false;
	}

	if( connStatus == false)
	{
		ConnParam			connParm;

		//获取连接参数
		getConnectParam(connParm);

		db = QSqlDatabase::addDatabase(connParm.driver,connName);
		db.setHostName(connParm.host);
		db.setDatabaseName(connParm.database);
		db.setUserName(connParm.user);
		db.setPassword(connParm.password);	

		if( db.open() == false)
			QSqlDatabase::removeDatabase(connName);
	}
	
	return db;
}


//删除除SQL连接
inline void removeSqlConnect(QString connName)
{
	if( QSqlDatabase::contains(connName))
		QSqlDatabase::removeDatabase(connName);
}

#endif // COMM_H
