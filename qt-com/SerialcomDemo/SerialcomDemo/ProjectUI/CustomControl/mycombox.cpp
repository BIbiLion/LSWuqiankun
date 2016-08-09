#include "mycombox.h"
#include <QDebug>
#include <windows.h>
#include <iostream>

MyCombox::MyCombox(QWidget *parent)
    : QComboBox(parent)
{

}

MyCombox::~MyCombox()
{

}

void MyCombox::showPopup()
{
    clear();
    enumPortList();
    QComboBox::showPopup();
}

static BOOL WStringToString(const std::wstring &wstr,std::string &str)
{
      int nLen = (int)wstr.length();
      str.resize(nLen,' ');

      int nResult = WideCharToMultiByte(CP_ACP,0,(LPCWSTR)wstr.c_str(),nLen,(LPSTR)str.c_str(),nLen,NULL,NULL);

      if (nResult == 0)
      {
         return FALSE;
      }

      return TRUE;
}

void MyCombox::enumPortList()
{
    HKEY hKey;
    LPCTSTR data_Set = L"HARDWARE\\DEVICEMAP\\SERIALCOMM\\";
    LONG ret0 = RegOpenKeyEx(HKEY_LOCAL_MACHINE, data_Set, 0, KEY_READ, &hKey);
    if(ret0 != ERROR_SUCCESS)
    {
        return;
    }

    DWORD dwIndex = 0;
    while(1)
    {
        LONG Status;
        WCHAR Name[256]={0};
        UCHAR szPortName[80]={0};
        DWORD dwName;
        DWORD dwSizeofPortName;
        DWORD Type;
        dwName = sizeof(Name);
        dwSizeofPortName = sizeof(szPortName);
        Status = RegEnumValue(hKey, dwIndex++, Name, &dwName, NULL, &Type,
            szPortName, &dwSizeofPortName);

        if((Status == ERROR_SUCCESS)||(Status == ERROR_MORE_DATA))
        {
            std::wstring wstr = std::wstring((PWCHAR)szPortName);
            std::string str;
            if(WStringToString(wstr, str))
            {
                //std::cout<<str<<std::endl;
                this->addItem(str.data());
            }
        }
        else
        {
            break;
        }
    }
    RegCloseKey(hKey);
}
