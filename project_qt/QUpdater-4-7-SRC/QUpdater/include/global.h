#ifndef __GLOBAL_H_INCLUDED
#define __GLOBAL_H_INCLUDED

/********************************************************************
	created:	2008/02/26
	created:	26:2:2008   11:51
	filename: 	e:\InternetService\include\global.h
	file path:	e:\InternetService\include
	file base:	global
	file ext:	h
	author:		wybo copyright@2008
	
	purpose:	
*********************************************************************/

#ifndef NULL
#define NULL (void*)0;
#endif
#ifndef null
#define null NULL
#endif
#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif
#ifndef CIN
#define CIN const
#endif
#ifndef COUT
#define COUT const
#endif
#ifndef REF
#define REF
#endif
#ifndef CREF
#define CREF const
#endif
#ifndef SIZE
#define  SIZE(stdcon) ((int)stdcon.size())
#endif
#ifndef interface
#define interface struct
#endif
#ifndef DISABLE_COPY //禁止默认的拷贝构造函数
#define DISABLE_COPY(ClassName) private: ClassName (const ClassName & ) {}
#endif
#ifndef DISABLE_NONEAGRUCONSTRUCTION //禁止默认的无参数构造函数
#define DISABLE_NONEAGRUCONSTRUCTION(ClassName) private: ClassName (){}
#endif
#ifndef IsNull
#define IsNull(ptr) ((ptr) == NULL)
#endif
#ifndef Nothing
#define Nothing IsNull
#endif

typedef unsigned long wDWORD;
typedef void *wHANDLE;

#define CMDSPLITER "##"

#ifdef QT_CORE_LIB
#ifndef QT
#define QT
#endif
#endif

template <typename TT>
	class With
{
	DISABLE_COPY(With);
	DISABLE_NONEAGRUCONSTRUCTION(With);

public:
	With(TT& obj)
	{
		pdata = &obj;
	}

	With(TT* pobj)
	{
		pdata = pobj;
	}

	TT* operator -> ()
	{
		return pdata;
	}

	TT* operator ()()
	{
		return pdata;
	}

	bool isValid()
	{
		return pdata != NULL;
	}

private:
	TT* pdata;
};

#endif