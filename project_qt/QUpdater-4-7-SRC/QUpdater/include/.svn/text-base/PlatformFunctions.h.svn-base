#ifndef __PLATFORMFUNCTIONS_H_INCLUDED
#define __PLATFORMFUNCTIONS_H_INCLUDED

#include "global.h"
#include "MBCSUNICODESTD.h"

#ifdef WIN32
#pragma warning (disable : 4005)
#include <Windows.h>
#endif

#ifdef WIN32
#include "MfcRegOperator.h"
typedef RegOpe envirOpe;
#endif

namespace platfunc 
{
	//得到当前的processid
	static inline wDWORD getCurrentProcessId()
	{
#ifdef WIN32
		return ::GetCurrentProcessId();
#endif
		return 0;
	}

	static inline bool mutexCreate(CREF MUString& namestr)
	{
#ifdef WIN32
		HANDLE rehandle = ::CreateMutex(NULL, TRUE, (LPCTSTR)namestr.c_str());
		UINT errorCode = GetLastError();
		if (errorCode == ERROR_ALREADY_EXISTS)
		{
			::ReleaseMutex(rehandle);
			::CloseHandle(rehandle);
		}
		return errorCode != ERROR_ALREADY_EXISTS;
#endif
	}

	static inline bool getRegValue(CREF QString& objEnvi, CREF QString& valuename, REF QString& data)
	{
		QString tstr, tstr1, tstr2;

		tstr = objEnvi;
		tstr1 = valuename;
		/*
#ifdef _UNICODE
		tstr = objEnvi.toStdWString();
		tstr1 = valuename.toStdWString();
#else
		tstr = objEnvi.toStdString();
		tstr1 = valuename.toStdString();
#endif
		*/

#ifdef WIN32
		//bool re = RegOpe::query(tstr, tstr1, tstr2);
		bool re = RegOpe::getKeyValueSpStr(tstr, tstr1, tstr2);
#endif

		data = tstr2;

		/*
#ifdef _UNICODE
		data = QString::fromStdWString(tstr2);
#else
		data = QString::fromStdString(tstr2);
#endif
		*/

		return re;
	}

};

#endif