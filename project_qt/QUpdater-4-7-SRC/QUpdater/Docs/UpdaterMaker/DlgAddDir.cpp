// DlgAddDir.cpp : implementation file
//

#include "stdafx.h"
#include "UpdaterMaker.h"
#include "DlgAddDir.h"
#include "DlgAddFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAddDir dialog


CDlgAddDir::CDlgAddDir(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAddDir::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAddDir)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	strFile=_T("");
	strDir=_T("");
}


void CDlgAddDir::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAddDir)
	DDX_Control(pDX, IDC_COMBO_Dir, m_Combo_Dir);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAddDir, CDialog)
	//{{AFX_MSG_MAP(CDlgAddDir)
	ON_BN_CLICKED(IDC_BUTTON_Browse, OnBUTTONBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAddDir message handlers

void CDlgAddDir::OnOK() 
{
	// TODO: Add extra validation here
	GetDlgItem(IDC_EDIT_File)->GetWindowText(strFile);
	m_Combo_Dir.GetLBText(m_Combo_Dir.GetCurSel(),strDir);
	CString strSub;
	GetDlgItem(IDC_EDIT_SubDir)->GetWindowText(strSub);
	for (int i=0;i<DIRCOUNT;i++)
	{
		if(strDir==g_directory[i].strName)
		{
			if(strSub.IsEmpty())
				strDir=g_directory[i].strDir;
			else
				strDir=g_directory[i].strDir+"\\"+strSub;
			break;
		}
	}
	CDialog::OnOK();
}

BOOL CDlgAddDir::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	for (int i=0;i<DIRCOUNT;i++)
	{
		m_Combo_Dir.AddString(g_directory[i].strName);
	}
	m_Combo_Dir.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgAddDir::OnBUTTONBrowse() 
{
	// TODO: Add your control notification handler code here
	::CoInitialize(NULL);   
	LPITEMIDLIST   pidlPath;   
	char   pszDplName[MAX_PATH];   
	BROWSEINFO   biFile;   
	IMalloc   *pDllMlc; 
	
	biFile.hwndOwner   =   m_hWnd;   
	biFile.pidlRoot   =   NULL;   
	biFile.pszDisplayName   =   NULL;   
	biFile.lpszTitle   =   "选择目录";   
	biFile.ulFlags   =   BIF_RETURNFSANCESTORS;   
	biFile.lpfn   =   NULL;   
	biFile.lParam   =   NULL;   
	biFile.iImage   =   0;   
	if(SUCCEEDED(SHGetMalloc(&pDllMlc)))   
	{   
		pidlPath=SHBrowseForFolder(&biFile);   
		if(pidlPath   !=   NULL)   
		{
			SHGetPathFromIDList(pidlPath,pszDplName);//pszDplName:文件的路径地址
			GetDlgItem(IDC_EDIT_File)->SetWindowText(pszDplName);
		}
		pDllMlc->Free(NULL);   
		pDllMlc->Release();
	} 
	::CoUninitialize();
}
