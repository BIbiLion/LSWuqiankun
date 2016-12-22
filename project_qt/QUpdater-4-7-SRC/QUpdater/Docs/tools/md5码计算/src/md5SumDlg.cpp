// md5SumDlg.cpp : implementation file
//

#include "stdafx.h"
#include "md5Sum.h"
#include "MD5.h"
#include "md5SumDlg.h"
#include <stdio.h> 
#include <stdlib.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMd5SumDlg dialog

CMd5SumDlg::CMd5SumDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMd5SumDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMd5SumDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CMd5SumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMd5SumDlg)
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMd5SumDlg, CDialog)
	//{{AFX_MSG_MAP(CMd5SumDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Browse, OnBUTTONBrowse)
	ON_BN_CLICKED(IDC_BUTTON_BrowsePath, OnBUTTONBrowsePath)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMd5SumDlg message handlers

BOOL CMd5SumDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_Edit.SetWindowText("c:\\");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMd5SumDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMd5SumDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMd5SumDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMd5SumDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString str;
	m_Edit.GetWindowText(str);
	CFile in;
	if(in.Open(str,CFile::modeRead))
	{
		in.Close();
		CString strFile;
		strFile=str;
		int index=0;
		int pos;
		while ((pos=strFile.Find('\\',index+1))>0)
			index=pos;
		strFile.Delete(index,strFile.GetLength()-index);
		CFile out(strFile+"\\md5code.txt",CFile::modeCreate|CFile::modeWrite);
		CString strMD5;
		out.Write(str.GetBuffer(str.GetLength()),str.GetLength());
		out.Write("\t",1);
		strMD5.Format("%s",MD5File(str.GetBuffer(str.GetLength())));
		out.Write(strMD5.GetBuffer(strMD5.GetLength()),strMD5.GetLength());
		out.Write("\r\n",2);
		out.Close();
		MessageBox("完成");
	}else{
		CFileFind finder;
		
		CString m_strCurrentDirectory=str;
		str += "\\*.*";
		
		BOOL bWorking = finder.FindFile( str );
		CFile out(m_strCurrentDirectory+"\\md5code.txt",CFile::modeCreate|CFile::modeWrite);
		CString strMD5;
		while( bWorking )
		{
			bWorking = finder.FindNextFile();
			
			if( finder.IsDots() || finder.IsDirectory() )
			{
				continue;
			}
			else
			{
				if (finder.GetFileName()==_T("md5code.txt"))
				{
					continue;
				}
				CString filePath = m_strCurrentDirectory + _T("\\")+finder.GetFileName();
				out.Write(filePath.GetBuffer(filePath.GetLength()),filePath.GetLength());
				out.Write("\t",1);
				strMD5.Format("%s",MD5File(filePath.GetBuffer(filePath.GetLength())));
				out.Write(strMD5.GetBuffer(strMD5.GetLength()),strMD5.GetLength());
				out.Write("\r\n",2);
			}
		}
		out.Close();
		finder.Close();
		MessageBox("完成");
	}
	//str.Format("");
}

void CMd5SumDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CMd5SumDlg::OnBUTTONBrowse() 
{
	// TODO: Add your control notification handler code here
	CString szFilter = _T("All File(*.*)|*.*|");
	
	CFileDialog fd( true,NULL,NULL,OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY,
			LPCTSTR(szFilter) );
	fd.DoModal();
	m_Edit.SetWindowText(fd.GetPathName());

}

//CPathDialog

void CMd5SumDlg::OnBUTTONBrowsePath() 
{
	// TODO: Add your control notification handler code here
	BROWSEINFO bi;
	//pBS->
	bi.hwndOwner = this -> m_hWnd; // owner of created dialog box
	bi.pidlRoot = 0; // unused
	bi.pszDisplayName = 0; // buffer to receive name
	// displayed by folder
	// (not a valid path)
	bi.lpszTitle = _T("c:\\")  ; // title is "Browse for
	// Folder", this is
	// an instruction
	bi.lpfn = NULL;//BrowseCallbackProc; // callback routine called
	// when dialog has been
	// initialized
	bi.lParam = 0; // passed to callback routine
	bi.ulFlags =BIF_RETURNONLYFSDIRS | // only allow user to select
		// a directory
		BIF_STATUSTEXT  // create status text field
		// we will be writing to
		// in callback
		// BIF_BROWSEFORCOMPUTER| // only allow user to select
		// a computer
		// BIF_BROWSEFORPRINTER | // only allow user to select
		// a printer
		// BIF_BROWSEINCLUDEFILES| // displays files too which
		// user can pick
		// BIF_DONTGOBELOWDOMAIN| // when user is exploring the
		// "Entire Network" they
		// are not allowed into
		// any domain
		;
	LPITEMIDLIST pIL=SHBrowseForFolder(&bi);
	CString strPath;
	//char strPath[256];
	SHGetPathFromIDList(pIL,strPath.GetBuffer(256));
	m_Edit.SetWindowText(strPath);
}
