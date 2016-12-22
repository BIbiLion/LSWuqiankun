// DlgAddFile.cpp : implementation file
//

#include "stdafx.h"
#include "UpdaterMaker.h"
#include "DlgAddFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAddFile dialog


CDlgAddFile::CDlgAddFile(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAddFile::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAddFile)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	strFile=_T("");
	strDir=_T("");
}


void CDlgAddFile::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAddFile)
	DDX_Control(pDX, IDC_COMBO_Dir, m_Combo_Dir);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAddFile, CDialog)
	//{{AFX_MSG_MAP(CDlgAddFile)
	ON_BN_CLICKED(IDC_BUTTON_Browse, OnBUTTONBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAddFile message handlers

void CDlgAddFile::OnOK() 
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

BOOL CDlgAddFile::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	for (int i=0;i<DIRCOUNT;i++)
	{
		m_Combo_Dir.AddString(g_directory[i].strName);
	}
	m_Combo_Dir.SetCurSel(0);
	if (strFile!=_T(""))
	{
		GetDlgItem(IDC_EDIT_File)->SetWindowText(strFile);
		for (i=DIRCOUNT-1;i>=0;i--)
		{
			if (strDir.Find(g_directory[i].strDir,0)>=0)
			{
				m_Combo_Dir.SelectString(0,g_directory[i].strName);
				GetDlgItem(IDC_EDIT_SubDir)->SetWindowText(strDir.Right(
					strDir.GetLength()-g_directory[i].strDir.GetLength()-1));
				break;
			}
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgAddFile::OnBUTTONBrowse() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE);
	dlg.DoModal();
	GetDlgItem(IDC_EDIT_File)->SetWindowText(dlg.GetPathName());
}
