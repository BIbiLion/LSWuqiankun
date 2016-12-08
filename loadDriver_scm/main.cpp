#include <QCoreApplication>

#include <Windows.h>

BOOL WINAPI InstallService(LPCTSTR ServiceName,
    LPCTSTR DisplayName,
    LPCTSTR szPath,
    DWORD StartType,
    DWORD ErrorControl = SERVICE_ERROR_NORMAL,
    DWORD ServiceType = SERVICE_WIN32_OWN_PROCESS){
    SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
    if (hSCManager != NULL){
        SC_HANDLE hService = CreateService(hSCManager, ServiceName, DisplayName, SERVICE_ALL_ACCESS, ServiceType, StartType, ErrorControl, szPath, NULL, NULL, NULL, NULL, TEXT(""));
        if (hService != NULL){
            CloseServiceHandle(hService);
            CloseServiceHandle(hSCManager);
            return TRUE;
        }
        CloseServiceHandle(hSCManager);
        return FALSE;
    }
    else return FALSE;
}



BOOL WINAPI StartService2(LPCTSTR ServiceName){
    SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT);
    if (hSCManager != NULL){
        SC_HANDLE hService = OpenService(hSCManager, ServiceName, SERVICE_START);
        if (hService != NULL){
            if (StartService(hService, 0, NULL))
            {
                CloseServiceHandle(hService);
                CloseServiceHandle(hSCManager);
                return TRUE;
            }
            CloseServiceHandle(hService);
            CloseServiceHandle(hSCManager);
            return FALSE;
        }
        CloseServiceHandle(hSCManager);
        return FALSE;
    }
    else return FALSE;
}



BOOL WINAPI StopService(LPCTSTR ServiceName){

    SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    SERVICE_STATUS svcsta = { 0 };
    if (hSCManager != NULL){
        SC_HANDLE hService = OpenService(hSCManager, ServiceName, SERVICE_STOP);
        if (hService != NULL){
            if (ControlService(hService, SERVICE_CONTROL_STOP, &svcsta))
            {
                CloseServiceHandle(hService);
                CloseServiceHandle(hSCManager);
                return TRUE;
            }
            CloseServiceHandle(hService);
            CloseServiceHandle(hSCManager);
            return FALSE;
        }
        CloseServiceHandle(hSCManager);
        return FALSE;
    }
    else return FALSE;
}
/*
BOOL WINAPI DeleteService(LPCTSTR ServiceName){
    SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT);
    if (hSCManager != NULL){
        SC_HANDLE hService = OpenService(hSCManager, ServiceName, DELETE);
        if (hService != NULL){
            if (DeleteService(hService))
            {
                CloseServiceHandle(hService);
                CloseServiceHandle(hSCManager);
                return TRUE;
            }
            CloseServiceHandle(hService);
            CloseServiceHandle(hSCManager);
            return FALSE;
        }
        CloseServiceHandle(hSCManager);
        return FALSE;
    }
    else return FALSE;
}


*/
int main(int argc, char* argv[])
{
    InstallService(TEXT("mydriver"), TEXT("mydriver"), TEXT("C:\\mydriver.sys"), SERVICE_DEMAND_START, SERVICE_ERROR_IGNORE, SERVICE_KERNEL_DRIVER);
    //SERVICE_KERNEL_DRIVER：驱动服务；SERVICE_DEMAND_START：手动启动
    if (StartService2(TEXT("mydriver"))){
        printf("驱动已经加载\n");
    }
    Sleep(3000);
    if (StopService(TEXT("mydriver"))){
        printf("驱动已经停止\n");
    }
    getchar();
    return 0;
}



/*
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
*/
