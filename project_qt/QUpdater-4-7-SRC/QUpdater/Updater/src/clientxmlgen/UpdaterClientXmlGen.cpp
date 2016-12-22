// UpdaterClientXmlGen.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "UpdaterClientXmlGen.h"
#include "list"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

#include "IClientXmlGenerater.h"
#include "MfcRegOperator.h"

//打开客户端的xml配置文件
extern "C" bool __declspec(dllexport) loadUpdaterClientXmlFile()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//实现方法
	//由注册表中得到Updater客户端的安装路径
	//由路径组合出

	//读取updater键值
	if (RegOpe::exist(_T("Updater\\MAIN")))
	{
		CString clientplistpath;
		if (RegOpe::query(_T("Updater\\MAIN"), _T("UpdaterDir"), clientplistpath))
		{
			MUString filename=clientplistpath;
			return wfwGetClientXmlGenerater()->LoadXml(filename);
		}
	}
	
	return false;
}
extern "C" bool __declspec(dllexport) saveUpdaterClientXmlFile()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	//实现方法
	//由注册表中得到Updater客户端的安装路径
	//读取updater键值
	if (RegOpe::exist(_T("Updater\\MAIN")))
	{
		CString clientplistpath;
		if (RegOpe::query(_T("Updater\\MAIN"), _T("UpdaterDir"), clientplistpath))
		{
			MUString filename=clientplistpath;
			return wfwGetClientXmlGenerater()->Save2File(filename);
		}
	}
	return false;
}
//建立客户端升级用xml文件
extern "C" bool __declspec(dllexport) creatUpdaterClientXmlFile()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return true;
}

//验证客户端升级用的xml文件是否格式正确
extern "C" bool __declspec(dllexport) validateUpdaterClientXmlFile()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return true;
}

//给客户端添加软件
extern "C" bool __declspec(dllexport) appendSoft(CREF MUString& softname)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	wfwGetClientXmlGenerater()->appendSoft(softname,1);

	return true;
}
//新建XML文件
extern "C" bool __declspec(dllexport) repairUpdaterClientXmlFile()
{
	INT keytype=1;
	if ( RegOpe::exist(_T("ECPF\\MAIN")) )
	{
		CString strKT;
		if (RegOpe::query(_T("ECPF\\MAIN"), _T("Keytype"), strKT))
			keytype=atoi(strKT);
	}

	if (!RegOpe::exist(_T("ECPF\\Module")))return false;
	std::list<MUString> nameList;
	//获取已安装的软件名称列表
	if (!RegOpe::getSubKeyList(_T("ECPF\\Module"),nameList))return false;

	//打开xml文件
	if (!RegOpe::exist(_T("ECPF\\MAIN")))return false;

	CString clientplistpath;
	if (RegOpe::query(_T("ECPF\\MAIN"), _T("UpdaterPlist"), clientplistpath))
	{
		MUString filename=clientplistpath;
		if(wfwGetClientXmlGenerater()->LoadXml(filename))
			wfwGetClientXmlGenerater()->cleanSoft(nameList);
		else
			wfwGetClientXmlGenerater()->MakeXml();
		std::list<MUString>::iterator iter=nameList.begin();
		for (;iter!=nameList.end();iter++)
		{
			wfwGetClientXmlGenerater()->appendSoft(*iter,keytype);
		}
		wfwGetClientXmlGenerater()->Save2File(filename);
		return true;
	}
	return false;
}
extern "C" bool __declspec(dllexport) removeSoft(CREF MUString& softname)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	wfwGetClientXmlGenerater()->removeSoft(softname);

	return true;
}
//删除特定的软件的所有升级信息
extern "C" bool __declspec(dllexport) removeSoftFromUpdaterClientXmlFile()
{
	return true;
}

//删除特定软件的特定的补丁包信息
extern "C" bool __declspec(dllexport) removePackFromUpdaterClientXmlFile()
{
	return true;
}

// CUpdaterClientXmlGenApp

BEGIN_MESSAGE_MAP(CUpdaterClientXmlGenApp, CWinApp)
END_MESSAGE_MAP()


// CUpdaterClientXmlGenApp 构造

CUpdaterClientXmlGenApp::CUpdaterClientXmlGenApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CUpdaterClientXmlGenApp 对象

CUpdaterClientXmlGenApp theApp;


// CUpdaterClientXmlGenApp 初始化

BOOL CUpdaterClientXmlGenApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
