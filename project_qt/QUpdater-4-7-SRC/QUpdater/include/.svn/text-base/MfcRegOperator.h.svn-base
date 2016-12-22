#ifndef __MFCREFOPERATOR_H_INCLUDED
#define __MFCREFOPERATOR_H_INCLUDED

/*
利用MFC读取注册表的类 
*/


#include "MBCSUNICODESTD.h"
#include "pubfuncs.h"
#include <list>

const MUString PKPMREG = _TT("SOFTWARE\\PKPM\\");
const MUString COMPANYREG = _TT("PKPM");
const HKEY PKPMMAINREG = HKEY_LOCAL_MACHINE;
const MUString PKPMMAINREGSTR = _TT("HKEY_LOCAL_MACHINE");
const unsigned int REGMAXPATH = 256;

#ifdef QT
#include <QtCore/QSettings>
#endif

struct RegOpe
{
	#define exist(key) absolutexist(key, true).first

	//添加一个键
	static bool addNewKey(CREF MUString& _keyname, 
		CREF MUString& directory = PKPMREG, CREF HKEY& mainreg = PKPMMAINREG)
	{
		MUString keyname = directory + _keyname;

		HKEY mkey;
		DWORD dw;

		LONG reCode = ::RegCreateKeyEx(mainreg,
			(LPCTSTR)keyname.c_str(),
			NULL,
			NULL,
			REG_OPTION_NON_VOLATILE,
			KEY_ALL_ACCESS,
			NULL,
			&mkey,
			&dw);

		if (reCode == ERROR_SUCCESS)
		{
			::RegCloseKey(mkey);
			return true;
		}

		return false;
	}

	//判断该键是否存在
	//一般调用请 使用 exist 宏判断
	static std::pair<bool, HKEY> absolutexist(CREF MUString& _keyname, 
		bool autoclose = true, 
		CREF MUString& directory = PKPMREG, CREF HKEY& mainreg = PKPMMAINREG)
	{
		MUString keyname = directory + _keyname;

		HKEY rekey;

		LPCTSTR temKeyname = (LPCTSTR)keyname.c_str();
		LONG reCode = ::RegOpenKeyEx(mainreg,
			temKeyname, 
			NULL, 
			KEY_ALL_ACCESS,
			&rekey);

		if (reCode == ERROR_SUCCESS)
		{
			if (autoclose)
			{
				::RegCloseKey(rekey);
				return std::make_pair<bool, HKEY>(true, NULL);
			}
			return std::make_pair<bool, HKEY>(true, rekey);
		}
		
		return std::make_pair<bool, HKEY>(false, NULL);
	}

	//删除一个键
	static bool removeKey(CREF MUString& _keyname,
		CREF MUString& directory = PKPMREG, CREF HKEY& mainreg = PKPMMAINREG)
	{
		if (exist(_keyname))
		{
			MUString keyname = directory + _keyname;
			LONG reCode = ::RegDeleteKeyEx(mainreg, 
				(LPCTSTR)_keyname.c_str(), 
				KEY_ALL_ACCESS, 
				NULL);

			if (reCode == ERROR_SUCCESS)
			{
				return true;
			}
			else
				return false;
		}
		return true;
	}

	static bool getSubKeyList(CREF MUString& _keyname,std::list<MUString>& SubList,
		CREF MUString& directory = PKPMREG, CREF HKEY& mainreg = PKPMMAINREG)
	{
		DWORD	numSubKey=0;					//存放子键的项数
		DWORD	i;								//计数
		DWORD   sizeSubKey;						//子键大小
		TCHAR	subKey[255];			//子键名
		SubList.clear();
		
		if (exist(_keyname))
		{
			HKEY openedKey = absolutexist(_keyname, false).second;
			RegQueryInfoKey(openedKey,
				NULL,//keyname.GetBuffer(keyname.GetLength()),
				NULL,//(LPDWORD)strName.GetBuffer(strName.GetLength()),//NULL,
				NULL,//NULL,
				&numSubKey,		//查得子键的项数
				NULL,
				NULL,
				NULL,
				NULL,
				NULL,
				NULL,
				NULL
				);
			if (numSubKey)	
			{
				for (i=0; i<numSubKey; i++)
				{
					subKey[0]='\0';				//该两行很重要，保证了每次循环的初始	
					sizeSubKey=255;	//第一行清空子键，第二行赋缓冲区大小

					RegEnumKeyEx(	openedKey,		//键柄
						i,			//子键序号
						subKey,		//存入子键名
						&sizeSubKey,//指明缓冲区大小
						NULL,
						NULL,
						NULL,
						NULL);
					SubList.push_back(subKey);
				}
				::RegCloseKey(openedKey);
				return true;
			}
		}
		return true;
	}


	//自动切换数据类型
	template<typename T>
	static DWORD  getValueTypeMode(CREF T&)
	{}
	template<>
	static DWORD getValueTypeMode(CREF MCString&)
	{
		return (DWORD)REG_SZ;
	}
	template<>
	static DWORD getValueTypeMode(CREF DWORD&)
	{
		return (DWORD)REG_DWORD;
	}
	
	//根据数据类型生成实例
	template<typename TTYPE>
	static void makeData(TTYPE& obj, BYTE* _parray, int size)
	{
		obj = TTYPE(_parray);
	}
	template<>
	static void makeData(MCString& obj, BYTE* _parray, int size)
	{
#ifdef _MBCS
		BYTE* noempty = _parray;
#else
		BYTE* noempty = pubfunc::skipEmpty(_parray, size);
#endif // _UNICODE
		
		obj = MCString((LPCTSTR)noempty);
#ifdef _UNICODE
		pubfunc::releasearray(noempty);
#endif
	}

	//查询一个键值
	template<typename T>
	static bool query(CREF MUString& _key, CREF MUString& _valuename, T& _value)
	{
		if (exist(_key))
		{
			HKEY openedKey = absolutexist(_key, false).second;

			DWORD modetype = getValueTypeMode(_value);
			BYTE data[REGMAXPATH];
			DWORD cbdata = sizeof(data);

			LONG reCode = ::RegQueryValueEx(openedKey,
				(LPCTSTR)_valuename.c_str(),
				NULL,
				&modetype,
				data,
				&cbdata
				);

			if (ERROR_SUCCESS!=reCode)return false;

			makeData(_value, data, cbdata);
	
			::RegCloseKey(openedKey);

			return true;
		}
		return false;
	}

	//数值转换
	template<typename TTYPE>
	static std::pair<LPBYTE, int> convert2LPBYTE(TTYPE& value)
	{
		return std::make_pair(NULL, NULL);
	}
	//CString -> Byte
	template<>
	static std::pair<LPBYTE, int> convert2LPBYTE(MCString& value)
	{
		LPBYTE lpbyte;
#ifdef NONMFC
		lpbyte = (LPBYTE)value.c_str();
		return std::make_pair(lpbyte, value.length());
#else
		lpbyte = (LPBYTE)value.GetBuffer(value.GetLength());
		value.ReleaseBuffer();
		return std::make_pair(lpbyte, value.GetLength());
#endif
	}

	//设置一个键值
	template<typename T>
	static bool setKeyValue(CREF MUString& _valuepath, CREF T& value,
		CREF MUString& directory = PKPMREG, CREF HKEY& mainreg = PKPMMAINREG)
	{
		MUString keyname = directory + _valuepath;

		std::pair<LPBYTE, int> data = convert2LPBYTE(value);
		LONG reCode = ::RegSetValueEx(mainreg,
			keyname,
			NULL,
			getValueTypeMode(value),
			data.first,
			data.second
			);

		return reCode == ERROR_SUCCESS;
	}

#ifdef QT
	static bool getKeyValueSpStr(CREF QString& s1, CREF QString& s2, REF QString& value)
	{
		QString xstr = 
#ifdef _UNICODE
			QString::fromStdWString(PKPMMAINREGSTR.c_str()) + "\\" +
			QString::fromStdWString(PKPMREG.c_str()) + s1
#else
			QString::fromStdString(PKPMMAINREGSTR.c_str()) + "\\" +
			QString::fromStdString(PKPMREG.c_str()) + s1
#endif
			;

		QString path = xstr.simplified();//由于QString在结尾加上两个符号，需要剔除
		QSettings mysetting(path, QSettings::NativeFormat);
		if (mysetting.value(s2, "NONE").toString() == "NONE")
			return false;

		value = mysetting.value(s2).toString();
		return true;
	}
#endif

};

#endif