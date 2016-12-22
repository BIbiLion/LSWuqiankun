#ifndef __APPLICATIONSINGTON_H_INCLUDED
#define __APPLICATIONSINGTON_H_INCLUDED

//应用程序唯一性验证

#include <QtCore/QSettings>
//#include <QtCore/QFile>
#include "PlatformFunctions.h"

struct AppSington
{
	int operator () ()
	{
		//QSettings msingle("QUpdaterClient", "Sington");
		//int existValue = msingle.value("AppHasRuned").toInt();

#ifdef _DEBUG
		//msingle.setValue("AppHasRuned", 0);
		//existValue = 0;
#endif // _DEBUG

		//if (existValue == 0)
		//{
		//	msingle.setValue("AppHasRuned", 1);
		//	needclear = true;
		//}
		//return existValue;

// 		if (mutexfile.open(QIODevice::WriteOnly))
// 		{
// 			needclear = true;
// 			return 0;
// 		}
// 		else
// 		{
// 			return 1;
// 		}

		if (platfunc::mutexCreate(_TT("QUpdaterClient")))
		{
			needclear = true;
			return 0;
		}
		else
			return 1;
	}

	AppSington()
		: needclear(false)
		//mutexfile(".mutex")
	{

	}

	void clear(bool repair = false)
	{
		if (repair)
		{
			needclear = true;
		}

		//QSettings msingle("QUpdaterClient", "Sington");
		//int existValue = msingle.value("AppHasRuned").toInt();
		//if (existValue == 1 && needclear)
		//{
		//	msingle.setValue("AppHasRuned", 0);
		//}

		if (needclear)
		{
			//mutexfile.close();
			//mutexfile.remove();
		}
	}

	//QFile mutexfile;
	bool needclear;
};

static AppSington __g_appsington;

#ifdef _DEBUG
#include <QMessageBox>
#endif
static inline void OutputMessage(int index)
{
#ifdef _DEBUG
	switch (index)
	{
	case 0:
		QMessageBox::critical(0, QObject::tr("warnning"),QObject::tr("have an exist thread"));
		break;
	}
#endif
}

#define APPLICATIONSINGTON \
	if ( __g_appsington() == 1)  {__g_appsington.clear(); \
	 OutputMessage(0); \
	return 1;}

#define SINGTONTEST APPLICATIONSINGTON

#define INITSINGTON __g_appsington.clear();
#define SHUTDOWNSINGTON INITSINGTON

#define REPAIRSINGTON __g_appsington.clear(true);

#define SINGTONEXEC(app) \
		int __t__sington_exec_code = app.exec(); \
		SHUTDOWNSINGTON; \
		return __t__sington_exec_code;

#endif