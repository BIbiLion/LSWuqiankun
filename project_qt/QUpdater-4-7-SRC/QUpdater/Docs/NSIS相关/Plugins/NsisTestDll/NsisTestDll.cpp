// NsisTestDll.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include <iostream>
#include "ExDLL.h"

void *operator new( unsigned int num_bytes )
{
	return GlobalAlloc(GPTR,num_bytes);
}
void operator delete( void *p ) { if (p) GlobalFree(p); }

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

extern "C" __declspec(dllexport) void Test(HWND hwndParent, int string_size, char *variables, stack_t **stacktop)
{
	EXDLL_INIT();
	{
		char tmp[1024];// = new char[1024];
		popstring(tmp);

		std::cout<<tmp<<std::endl;
		fflush(stdout);
		Sleep(100);
	}
}

BOOL EnableDebugPrevilige(BOOL fEnable)
{
	//该调试权限允许程序查看服务程序的信息
	//在进行快照前使用EnableDebugPrevilige(TRUE),
	//所有都快照完毕后,用EnableDebugPrevilige(FALSE);
	
	//   Enabling   the   debug   privilege   allows   the   application   to   see   
	//   information   about   service   applications   
	BOOL   fOk   =   FALSE;         //   Assume   function   fails   
	HANDLE   hToken;   
    
	//   Try   to   open   this   process's   access   token   
	if   (OpenProcessToken(GetCurrentProcess(),   TOKEN_ADJUST_PRIVILEGES,     
		&hToken))   {   
		
		//   Attempt   to   modify   the   "Debug"   privilege   
		TOKEN_PRIVILEGES   tp;   
		tp.PrivilegeCount   =   1;   
		LookupPrivilegeValue(NULL,   SE_DEBUG_NAME,   &tp.Privileges[0].Luid);   
		tp.Privileges[0].Attributes   =   fEnable   ?   SE_PRIVILEGE_ENABLED   :   0;   
		AdjustTokenPrivileges(hToken,   FALSE,   &tp,   sizeof(tp),   NULL,   NULL);   
		fOk   =   (GetLastError()   ==   ERROR_SUCCESS);   
		CloseHandle(hToken);   
	}   
	return(fOk);   
}   

//结束一个进程
extern "C" __declspec(dllexport) void KillProcess(HWND hwndParent, int string_size, char *variables, stack_t **stacktop)
{
	EXDLL_INIT();

	char tmp[1024];
	std::cin >> tmp;//等待输入

	long pid = atol(tmp);//取得pid
	
	EnableDebugPrevilige(TRUE);
	
	HANDLE handle = ::OpenProcess(PROCESS_TERMINATE, FALSE, pid);
	
	BOOL re = ::TerminateProcess(handle, 0);
	
	DWORD dwerror = GetLastError();
	
	::CloseHandle(handle);
	
	EnableDebugPrevilige(FALSE);

	pushstring(tmp);
}