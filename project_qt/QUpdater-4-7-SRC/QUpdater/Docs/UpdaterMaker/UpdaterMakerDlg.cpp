// UpdaterMakerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UpdaterMaker.h"
#include "UpdaterMakerDlg.h"
#include "iostream"
#include <fstream>
#include "DlgAddFile.h"
#include "DlgAddDir.h"
#include "DlgAddGroup.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define endl std::endl;
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
// CUpdaterMakerDlg dialog

CUpdaterMakerDlg::CUpdaterMakerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUpdaterMakerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUpdaterMakerDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	GroupList group;
	group.Files.clear();
	group.GroupName=_T("主程序");
	m_FilesInfo.clear();
	m_FilesInfo.push_back(group);
	m_iterFiles=m_FilesInfo.begin();
}

void CUpdaterMakerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUpdaterMakerDlg)
	DDX_Control(pDX, IDC_CHECK_UpdataSelf, m_Check_UpdataSelf);
	DDX_Control(pDX, IDC_CHECK_BWizard, m_Check_bWizard);
	DDX_Control(pDX, IDC_EDIT_FileName, m_Edit_FileName);
	DDX_Control(pDX, IDC_LIST_Group, m_List_Group);
	DDX_Control(pDX, IDC_LIST_Files, m_List_Files);
	DDX_Control(pDX, IDC_EDIT_PathName, m_Edit_PathName);
	DDX_Control(pDX, IDC_COMBO_SoftName, m_Combo_SoftName);
	DDX_Control(pDX, IDC_EDIT_Intro, m_Edit_Intro);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUpdaterMakerDlg, CDialog)
	//{{AFX_MSG_MAP(CUpdaterMakerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Make1, OnBUTTONMake1)
	ON_BN_CLICKED(IDC_BUTTON_Next, OnBUTTONNext)
	ON_BN_CLICKED(IDC_BUTTON_Previous, OnBUTTONPrevious)
	ON_LBN_SELCHANGE(IDC_LIST_Group, OnSelchangeLISTGroup)
	ON_BN_CLICKED(IDC_BUTTON_AddGroup, OnBUTTONAddGroup)
	ON_BN_CLICKED(IDC_BUTTON_DelGroup, OnBUTTONDelGroup)
	ON_BN_CLICKED(IDC_BUTTON_ModGroup, OnBUTTONModGroup)
	ON_BN_CLICKED(IDC_BUTTON_AddFiles, OnBUTTONAddFiles)
	ON_BN_CLICKED(IDC_BUTTON_DelFiles, OnBUTTONDelFiles)
	ON_BN_CLICKED(IDC_BUTTON_ModFile, OnBUTTONModFile)
	ON_BN_CLICKED(IDC_BUTTON_Browse, OnBUTTONBrowse)
	ON_BN_CLICKED(IDC_BUTTON_AddDir, OnBUTTONAddDir)
	ON_BN_CLICKED(IDC_BUTTON_Load, OnBUTTONLoad)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUpdaterMakerDlg message handlers

BOOL CUpdaterMakerDlg::OnInitDialog()
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
	m_Combo_SoftName.SetCurSel(0);

	//移动控件位置
	CRect rc;
	GetDlgItem(IDCANCEL)->GetWindowRect(rc);
	rc.left=0;rc.top=0;rc.bottom+=10;rc.right+=10;
	MoveWindow(rc);
	CenterWindow();

	int dx,dy;
	GetDlgItem(IDC_BUTTON_AddGroup)->GetWindowRect(rc);
	dx=10-rc.left;
	dy=10-rc.top;
	rc.OffsetRect(dx,dy);
	GetDlgItem(IDC_BUTTON_AddGroup)->MoveWindow(rc);

	GetDlgItem(IDC_BUTTON_DelGroup)->GetWindowRect(rc);
	rc.OffsetRect(dx,dy);
	GetDlgItem(IDC_BUTTON_DelGroup)->MoveWindow(rc);

	GetDlgItem(IDC_BUTTON_ModGroup)->GetWindowRect(rc);
	rc.OffsetRect(dx,dy);
	GetDlgItem(IDC_BUTTON_ModGroup)->MoveWindow(rc);

	GetDlgItem(IDC_BUTTON_AddFiles)->GetWindowRect(rc);
	rc.OffsetRect(dx,dy);
	GetDlgItem(IDC_BUTTON_AddFiles)->MoveWindow(rc);

	GetDlgItem(IDC_BUTTON_DelFiles)->GetWindowRect(rc);
	rc.OffsetRect(dx,dy);
	GetDlgItem(IDC_BUTTON_DelFiles)->MoveWindow(rc);

	GetDlgItem(IDC_BUTTON_ModFile)->GetWindowRect(rc);
	rc.OffsetRect(dx,dy);
	GetDlgItem(IDC_BUTTON_ModFile)->MoveWindow(rc);

	GetDlgItem(IDC_LIST_Group)->GetWindowRect(rc);
	rc.OffsetRect(dx,dy);
	GetDlgItem(IDC_LIST_Group)->MoveWindow(rc);

	GetDlgItem(IDC_LIST_Files)->GetWindowRect(rc);
	rc.OffsetRect(dx,dy);
	GetDlgItem(IDC_LIST_Files)->MoveWindow(rc);
	
	GetDlgItem(IDC_BUTTON_Make1)->GetWindowRect(rc);
	rc.OffsetRect(dx,dy);
	GetDlgItem(IDC_BUTTON_Make1)->MoveWindow(rc);

	GetDlgItem(IDC_BUTTON_Previous)->GetWindowRect(rc);
	rc.OffsetRect(dx,dy);
	GetDlgItem(IDC_BUTTON_Previous)->MoveWindow(rc);

	GetDlgItem(IDC_BUTTON_AddDir)->GetWindowRect(rc);
	rc.OffsetRect(dx,dy);
	GetDlgItem(IDC_BUTTON_AddDir)->MoveWindow(rc);


	CheckDlgButton(IDC_RADIO1,1);
	//初始化控件
	m_Edit_FileName.SetWindowText(_T("c:\\20080102.exe"));

	m_List_Files.InsertColumn(0,_T("文件"),LVCFMT_LEFT,250,0);   
	m_List_Files.InsertColumn(1,_T("目的目录"),LVCFMT_LEFT,100,1);   
	m_List_Files.SetItemState(0,LVIS_SELECTED|LVIS_FOCUSED,LVIS_SELECTED|LVIS_FOCUSED);
	
	m_List_Group.AddString(_T("主程序"));
	m_List_Group.SetCurSel(0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CUpdaterMakerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUpdaterMakerDlg::OnPaint() 
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
HCURSOR CUpdaterMakerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CUpdaterMakerDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CUpdaterMakerDlg::OnBUTTONMake1() 
{
	// TODO: Add your control notification handler code here
	std::ofstream ofile;//(strReportPath+"\\"+strReportName);
	CString strFileName;//=_T("c:\\20080102.exe");
	CString strTempNSI;
	CString strLine,strEdit;
	CString strTime;//记录时间
	SYSTEMTIME time;

	GetSystemTime(&time);
	time.wHour+=8;//转换为当前时区
	strTime.Format(_T("%d%d%d%d%d%d%d%d%d"),time.wYear,time.wMonth/10,
		time.wMonth%10,time.wDay/10,time.wDay%10,time.wHour/10,
		time.wHour%10,time.wMinute/10,time.wMinute%10);

	m_Edit_FileName.GetWindowText(strFileName);

	strEdit=strFileName.Right(4);
	if (strEdit!=_T(".exe"))
	{
		return;
	}
		

	//CString str;//=_T("%TEMP%\\temp.nsi");
	char tempPath[256];
	::GetTempPath(255,tempPath);
	strTempNSI.Format(_T("%s\\temp.nsi"),tempPath);
	ofile.open(strTempNSI);
	if(!ofile.is_open()){
		MessageBox("文件打开失败!");
		return;
	}

	ofile<<_T("!include \"MUI.nsh\"")<<endl;
	ofile<<_T("!include \"XML.nsh\"")<<endl;
	ofile<<_T("!define MUI_ABORTWARNING")<<endl;
	ofile<<_T("!define MUI_ICON \"${NSISDIR}\\PKPM\\update.ico\"")<<endl;
	//m_Edit_Intro.GetWindowText(strEdit);
	//strLine.Format(_T("!define INFOMATION \"%s\""),strEdit);
	//ofile<<(LPCSTR)strLine<<endl;
	ofile<<_T("!define INFOMATION \"")<<(LPCSTR)GetIntroStr()<<_T("\"")<<endl;

	int old,pos;
	old=0;
	pos=0;
	//找最后一个\的位置，以获得文件名
	while((pos=strFileName.Find("\\",old))>=0)
		old=pos+1;
	strEdit=strFileName.Right(strFileName.GetLength()-old);
	pos=strEdit.Find(".",0);
	strEdit=strEdit.Left(pos);
	if (strEdit.GetLength()<=0)
	{
		return;
	}
	strLine.Format(_T("!define FileName \"%s\""),strEdit);
	ofile<<(LPCSTR)strLine<<endl;

	m_Edit_PathName.GetWindowText(strEdit);
	if (strEdit.IsEmpty())
	{
		MessageBox("没有填写补丁名称。");
		return;
	}
	strLine.Format(_T("!define PathName \"%s\""),strEdit);
	ofile<<(LPCSTR)strLine<<endl;
	

	if(IsDlgButtonChecked(IDC_RADIO1))
		strEdit="0";
	else 
		strEdit="1";
	strLine.Format(_T("!define KeyType \"%s\""),strEdit);
	ofile<<(LPCSTR)strLine<<endl;


	ofile<<_T("var /global XMLFile")<<endl;
	ofile<<_T("var /global UpdateTime")<<endl;
	ofile<<_T("var /global XMLHandle")<<endl;
	
	ofile<<_T("!insertmacro MUI_PAGE_WELCOME")<<endl;
	//ofile<<_T("")<<endl;
	ofile<<_T("!insertmacro MUI_PAGE_LICENSE \"${NSISDIR}\\PKPM\\license.txt\"")<<endl;
	
	ofile<<_T("!insertmacro MUI_PAGE_COMPONENTS")<<endl;
	ofile<<_T("!insertmacro MUI_PAGE_INSTFILES")<<endl;

	//结束后需要运行的程序
	//ofile<<_T("!define MUI_FINISHPAGE_RUN \"$INSTDIR\\xxx.exe\"")<<endl;
	ofile<<_T("!insertmacro MUI_PAGE_FINISH")<<endl;
	ofile<<_T("!insertmacro MUI_LANGUAGE \"SimpChinese\"")<<endl;
	m_Combo_SoftName.GetWindowText(strEdit);
	strLine.Format(_T("Name %s补丁--"),strEdit);
	m_Edit_PathName.GetWindowText(strEdit);
	strLine+=strEdit;
	ofile<<(LPCSTR)strLine<<endl;

	
	m_Combo_SoftName.GetWindowText(strEdit);
	strLine.Format(_T("OutFile \"%s\""),strFileName);
	ofile<<(LPCSTR)strLine<<endl;
	ofile<<_T("ShowInstDetails show")<<endl;

	//初始化函数部分///////////////////////////////////////
	//by ltx
	//主要功能：
	//		查找注册表，确定是否安装过此补丁对应的软件，并读取安装目录信息，
	//		读取XML文件，确定是否安装过此补丁
	///////////////////////////////////////////////////////////////
	ofile<<_T("Function .onInit")<<endl;

	ofile<<_T("	ClearErrors")<<endl;
	strLine.Format(_T("	ReadRegStr $0 HKLM \"SOFTWARE\\pkpm\\ECPF\\MAIN\" \"Keytype\""));
	ofile<<(LPCSTR)strLine<<endl;
	ofile<<_T("	IfErrors 0 +2")<<endl;
	ofile<<_T("	strcpy $0 \"1\"")<<endl;
	ofile<<_T("	strcmp $0 ${KeyType} +3")<<endl;
	strLine.Format(_T("	MessageBox MB_OK \"此补丁对应的锁类型错误，请更换补丁包。\""));
	ofile<<(LPCSTR)strLine<<endl;
	ofile<<_T("	Quit")<<endl;

	ofile<<_T("	ClearErrors")<<endl;
	strLine.Format(_T("	ReadRegStr $INSTDIR HKLM \"SOFTWARE\\pkpm\\ECPF\\Module\\%s\" \"path\""),strEdit);
	ofile<<(LPCSTR)strLine<<endl;
	ofile<<_T("	IfErrors 0 +3")<<endl;
	strLine.Format(_T("	MessageBox MB_OK \"您没有安装%s，不需要安装此补丁。\""),strEdit);
	ofile<<(LPCSTR)strLine<<endl;
	ofile<<_T("	Quit")<<endl;

	ofile<<_T("	ClearErrors")<<endl;
	ofile<<_T("	ReadRegStr $XMLFile HKLM \"SOFTWARE\\pkpm\\ECPF\\MAIN\" \"UpdaterPlist\"")<<endl;
	ofile<<_T("	IfErrors 0 +3")<<endl;
	ofile<<_T("	MessageBox MB_OK \"注册表数据缺失，请修复程序后再更新。\"")<<endl;
	ofile<<_T("	Quit")<<endl;
	ofile<<_T("	${xml::LoadFile} $XMLFile $1")<<endl;
	ofile<<_T("	strcmp $1 0 +4 0")<<endl;
	ofile<<_T("	MessageBox MB_OK \"文件丢失或有其他更新程序正在运行，请修复程序或等其他更新结束后再更新。\"")<<endl;
	ofile<<_T("	${xml::Unload}")<<endl;
	ofile<<_T("	Quit")<<endl;
	ofile<<_T("	${xml::GotoPath} '/Root/EachSoft' $1")<<endl;
	ofile<<_T("	strcmp $1 0 +4 0")<<endl;
	ofile<<_T("	MessageBox MB_OK \"文件数据错误，请修复程序后再更新。\"")<<endl;
	ofile<<_T("	${xml::Unload}")<<endl;
	ofile<<_T("	Quit")<<endl;
	ofile<<_T("	Goto CHECK")<<endl;
	ofile<<_T("LOOP:")<<endl;
	ofile<<_T("	${xml::NextSiblingElement} \"EachSoft\" $1 $2")<<endl;
	ofile<<_T("	strcmp $2 0 +4 0")<<endl;
	ofile<<_T("	MessageBox MB_OK \"文件数据错误，请修复程序后再更新。\"")<<endl;
	ofile<<_T("	${xml::Unload}")<<endl;
	ofile<<_T("	Quit")<<endl;
	ofile<<_T("CHECK:")<<endl;
	ofile<<_T("	${xml::GetAttribute} \"Name\" $1 $2")<<endl;
	strLine.Format(_T("	strcmp $1 \"%s\" +2 0"),strEdit);
	ofile<<(LPCSTR)strLine<<endl;
	ofile<<_T("	Goto LOOP")<<endl;
	ofile<<_T("	${xml::NodeHandle} $XMLHandle")<<endl;
	ofile<<_T("	${xml::FirstChildElement} \"\" $1 $2")<<endl;
	ofile<<_T("	strcmp $1 \"InstalledPacks\" +4 0")<<endl;
	ofile<<_T("	MessageBox MB_OK \"文件数据错误，请修复程序后再更新。\"")<<endl;
	ofile<<_T("	${xml::Unload}")<<endl;
	ofile<<_T("	Quit")<<endl;
	ofile<<_T("	${xml::FirstChildElement} \"Pack\" $1 $2")<<endl;
	ofile<<_T("	strcmp $2 0 +2 0")<<endl;
	ofile<<_T("	Goto End")<<endl;
	ofile<<_T("	Goto CHECK1")<<endl;
	ofile<<_T("LOOP1:")<<endl;
	ofile<<_T("	${xml::NextSiblingElement} \"Pack\" $1 $2")<<endl;
	ofile<<_T("	strcmp $2 0 +2 0")<<endl;
	ofile<<_T("	Goto End")<<endl;
	ofile<<_T("CHECK1:")<<endl;
	ofile<<_T("	${xml::GetAttribute} \"name\" $1 $2")<<endl;
	ofile<<_T("	strcmp $1 ${PathName} +2 0")<<endl;
	ofile<<_T("	Goto LOOP1")<<endl;
	ofile<<_T("	MessageBox MB_OK \"此文件已经更新过，不需要再更新。\"")<<endl;
	ofile<<_T("	Quit")<<endl;
	ofile<<_T("END:")<<endl;
	ofile<<_T("FunctionEnd")<<endl;


	//当安装成功的时候
	////////////////////////////////////
	//操作:
	//		修改xml文件，记录安装信息
	ofile<<_T("Function .onInstSuccess")<<endl;
	
	strLine.Format(_T("	strcpy $UpdateTime \"%s\""),strTime);
		
	ofile<<(LPCSTR)strLine<<endl;
	ofile<<_T("	${xml::CreateNode} '<Pack filename=\"${FileName}.exe\" appendkey=${KeyType} publishtime=$UpdateTime info=${INFOMATION}  name=${PathName} />' $1")<<endl;
	ofile<<_T("	${xml::GetNodeValue} $2")<<endl;
	ofile<<_T("	strcmp $2 \"Pack\" Equal 0")<<endl;
	ofile<<_T("	${xml::InsertEndChild} $1 $2")<<endl;
	ofile<<_T("	Goto +2")<<endl;
	ofile<<_T("Equal:")<<endl;
	ofile<<_T("	${xml::InsertBeforeNode} $1 $2")<<endl;
	ofile<<_T("	${xml::GotoHandle} $XMLHandle $2")<<endl;
	ofile<<_T("	${xml::GetAttribute} \"LastDate\" $1 $2")<<endl;
	ofile<<_T("	strcmp $2 0 exist notexist")<<endl;
	ofile<<_T("notexist:")<<endl;
	ofile<<_T("	${xml::SetAttribute} \"LastDate\" $UpdateTime $2")<<endl;
	ofile<<_T("	Goto SAVEFILE")<<endl;
	ofile<<_T("exist:")<<endl;
	ofile<<_T("	IntCmp $1 $UpdateTime 0 0 SAVEFILE")<<endl;
	ofile<<_T("	${xml::SetAttribute} \"LastDate\" $UpdateTime $2")<<endl;
	ofile<<_T("SAVEFILE:")<<endl;
	ofile<<_T("	${xml::SaveFile} $XMLFile $1")<<endl;
	ofile<<_T("FunctionEnd")<<endl;

	//退出的时候关闭xml文件
	ofile<<_T("Function .onGUIEnd")<<endl;
	ofile<<_T("	${xml::Unload}")<<endl;
	ofile<<_T("FunctionEnd")<<endl;


	//Section "主程序" SEC01
	//////////////////////////////////////////////////////
	//安装部分
	//		暂时一个组件，以后扩展为n个部分，用户可以选择安装
	//////////////////////////////////
	//设置不同就覆盖模式
	ofile<<_T("SetOverwrite ifdiff")<<endl;

	std::list<GroupList>::iterator iterGroup=m_FilesInfo.begin();
	int FileIndex=1,FileCount=0;
	for (;iterGroup!=m_FilesInfo.end();iterGroup++)
	{
		FileCount+=(int)iterGroup->Files.size();
	}
	if (FileCount==0)
	{
		MessageBox("没有文件。");
		return;
	}
	strEdit=_T("");//记录上个文件所要拷贝的路径
	iterGroup=m_FilesInfo.begin();
	for (int i=1;iterGroup!=m_FilesInfo.end();iterGroup++,i++)
	{
		strLine.Format(_T("Section \"%s\" SEC%d%d"),iterGroup->GroupName,i/10,i%10);
		ofile<<(LPCSTR)strLine<<endl;
		std::list<FileInfo>::iterator iterFile=iterGroup->Files.begin();
		for(;iterFile!=iterGroup->Files.end();iterFile++)
		{
			if (iterFile->Directory!=strEdit)
			{
				strLine.Format(_T("SetOutPath \"%s\""),iterFile->Directory);
				ofile<<(LPCSTR)strLine<<endl;
				strEdit=iterFile->Directory;
			}
			strLine.Format(_T("File \"%s\""),iterFile->FileName);
			ofile<<(LPCSTR)strLine<<endl;

			strLine.Format(_T("NsisTestDll::Test \"@%d#%d@\""),FileCount,FileIndex++);
			ofile<<(LPCSTR)strLine<<endl;
		}
	}
	ofile<<_T("SectionEnd")<<endl;
	ofile.close();

	MessageBox("完成");
	ShellExecute(NULL,"OPEN","C:\\Program Files\\NSIS\\makensis.exe","\""+strTempNSI+"\"",
		NULL,   SW_SHOWNORMAL);

	strFileName.Delete(strFileName.GetLength()-4,4);
	strFileName+=_T(".txt");
	ofile.open(strFileName);
	m_Edit_PathName.GetWindowText(strLine);//显示名称
	ofile<<(LPCSTR)strLine<<endl;

	ofile<<(LPCSTR)strTime<<endl;//发布时间

	int bCheck=m_Check_bWizard.GetCheck();
	ofile<<bCheck<<endl;//安装过程中显示界面

	bCheck=m_Check_UpdataSelf.GetCheck();
	ofile<<bCheck<<endl;//安装过程中显示界面

	if(TRUE==IsDlgButtonChecked(IDC_RADIO1))
	{ofile<<0<<endl;}
	else
	{ofile<<1<<endl;}

	//m_Edit_Intro.GetWindowText(strLine);
	ofile<<(LPCSTR)GetIntroStr()/*strLine*/<<endl;
	ofile.close();
}

void CUpdaterMakerDlg::OnBUTTONNext() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_STATIC_FileName)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_FileName)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_PathName)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_PathName)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SoftName)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBO_SoftName)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_Intro)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_Intro)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_Browse)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_Next)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK_BWizard)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK_UpdataSelf)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_Load)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RADIO1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RADIO2)->ShowWindow(SW_HIDE);
	
	GetDlgItem(IDC_BUTTON_AddDir)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON_Previous)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON_Make1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON_AddGroup)->ShowWindow(SW_SHOW);	
	GetDlgItem(IDC_BUTTON_DelGroup)->ShowWindow(SW_SHOW);	
	GetDlgItem(IDC_BUTTON_ModGroup)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON_AddFiles)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON_DelFiles)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON_ModFile)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_LIST_Group)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_LIST_Files)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON_Make1)->ShowWindow(SW_SHOW);
}

void CUpdaterMakerDlg::OnBUTTONPrevious() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_STATIC_FileName)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT_FileName)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC_PathName)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT_PathName)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC_SoftName)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_COMBO_SoftName)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC_Intro)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT_Intro)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON_Browse)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON_Next)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_CHECK_BWizard)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_CHECK_UpdataSelf)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON_Load)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_RADIO1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_RADIO2)->ShowWindow(SW_SHOW);

	
	GetDlgItem(IDC_BUTTON_AddDir)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_Previous)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_Make1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_AddGroup)->ShowWindow(SW_HIDE);	
	GetDlgItem(IDC_BUTTON_DelGroup)->ShowWindow(SW_HIDE);	
	GetDlgItem(IDC_BUTTON_ModGroup)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_AddFiles)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_DelFiles)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_ModFile)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_LIST_Group)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_LIST_Files)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_Make1)->ShowWindow(SW_HIDE);
}

void CUpdaterMakerDlg::OnSelchangeLISTGroup() 
{
	// TODO: Add your control notification handler code here
	int index=m_List_Group.GetCurSel();
	CString str;
	m_List_Group.GetText(index,str);
	if (m_iterFiles->GroupName==str )return;
	m_iterFiles=m_FilesInfo.begin();
	for (;m_iterFiles!=m_FilesInfo.end();m_iterFiles++)
	{
		if (m_iterFiles->GroupName==str)
		{
			UpdataListCtrl();
			return;
		}
	}
}

void CUpdaterMakerDlg::OnBUTTONAddGroup() 
{
	// TODO: Add your control notification handler code here
	CDlgAddGroup dlg;
	if (dlg.DoModal()==IDOK)
	{
		int i;
		if(0<=m_List_Group.FindString(0,dlg.m_Edit_Name))
		{
			MessageBox("此组已经添加过了!");
			return;
		}
		m_List_Group.AddString(dlg.m_Edit_Name);
		//m_List_Group.SetCurSel()
		i=m_List_Group.SelectString(0,dlg.m_Edit_Name);
		GroupList gl;
		gl.GroupName=dlg.m_Edit_Name;
		gl.Files.clear();
		m_FilesInfo.push_back(gl);
		m_List_Files.DeleteAllItems();
		m_iterFiles=m_FilesInfo.end();
		m_iterFiles--;
	}
}
void CUpdaterMakerDlg::UpdataListCtrl()
{
	m_List_Files.DeleteAllItems();
	std::list<FileInfo>::iterator iter=m_iterFiles->Files.begin();
	for (int i=0;iter!=m_iterFiles->Files.end();iter++,i++)
	{
		m_List_Files.InsertItem(i,iter->FileName);
		m_List_Files.SetItemText(i,1,iter->Directory);   
	}
}
void CUpdaterMakerDlg::OnBUTTONDelGroup() 
{
	// TODO: Add your control notification handler code here
	int index=m_List_Group.GetCurSel();
	CString strName;
	m_List_Group.GetText(index,strName);
	std::list<GroupList>::iterator iter=m_FilesInfo.begin();
	for (;iter!=m_FilesInfo.end();iter++)
	{
		if (iter->GroupName==strName)
		{
			iter=m_FilesInfo.erase(iter);
			break;
		}
	}
	m_List_Group.DeleteString(index);
	if (index>=m_List_Group.GetCount())
	{
		index=m_List_Group.GetCount()-1;
	}
	m_List_Group.SetCurSel(index);
	m_List_Group.GetText(index,strName);

	m_iterFiles=m_FilesInfo.begin();
	for (;m_iterFiles!=m_FilesInfo.end();m_iterFiles++)
	{
		if (m_iterFiles->GroupName==strName)
		{
			break;
		}
	}
	UpdataListCtrl();
	
}

void CUpdaterMakerDlg::OnBUTTONModGroup() 
{
	// TODO: Add your control notification handler code here
	CDlgAddGroup dlg;
	if(m_List_Group.GetCurSel()<0)
	{
		MessageBox("请选中一个已存在的组!");
		return;
	}
	m_List_Group.GetText(m_List_Group.GetCurSel(),dlg.m_Edit_Name);
	if (dlg.DoModal()==IDOK)
	{
		int	index=m_List_Group.GetCurSel();
		m_List_Group.InsertString(m_List_Group.GetCurSel(),dlg.m_Edit_Name);
		m_List_Group.DeleteString(m_List_Group.GetCurSel());
		m_List_Group.SetCurSel(index);
	}
}

void CUpdaterMakerDlg::OnBUTTONAddFiles() 
{
	// TODO: Add your control notification handler code here
	CDlgAddFile dlg;
	if (dlg.DoModal()==IDOK)
	{
		int index=m_List_Files.GetItemCount();
		m_List_Files.InsertItem(index,dlg.strFile);
		m_List_Files.SetItemText(index,1,dlg.strDir); 
		FileInfo fi;
		fi.FileName=dlg.strFile;
		fi.Directory=dlg.strDir;
		m_iterFiles->Files.push_back(fi);
	}
}
void CUpdaterMakerDlg::OnBUTTONAddDir() 
{
	// TODO: Add your control notification handler code here
	CDlgAddDir dlg;
	if (dlg.DoModal()==IDOK)
	{
		AddFiles(dlg.strFile,dlg.strDir);
		//UpdataListCtrl();
	}
}

void CUpdaterMakerDlg::OnBUTTONDelFiles() 
{
	// TODO: Add your control notification handler code here
	POSITION pos=m_List_Files.GetFirstSelectedItemPosition();  
	std::vector<int> index;
	int i;
	index.resize(m_List_Files.GetSelectedCount());
	for (i=0;i<(int)index.size();i++)
	{
		index[i]=m_List_Files.GetNextSelectedItem(pos);
	}
	for (i=index.size()-1;i>=0;i--)
	{
		m_List_Files.DeleteItem(index[i]);
	}
	UpdataListFiles();
}

void CUpdaterMakerDlg::OnBUTTONModFile() 
{
	// TODO: Add your control notification handler code here
	if (m_List_Files.GetSelectedCount()!=1)
	{
		MessageBox("请选择一个文件!");
		return;
	}
	POSITION pos=m_List_Files.GetFirstSelectedItemPosition();
	int index=m_List_Files.GetNextSelectedItem(pos);
	
	CDlgAddFile dlg;
	dlg.strFile=m_List_Files.GetItemText(index,0);
	dlg.strDir=m_List_Files.GetItemText(index,1);
	if (dlg.DoModal()==IDOK)
	{
		m_List_Files.SetItemText(index,0,dlg.strFile);
		m_List_Files.SetItemText(index,1,dlg.strDir);
		UpdataListFiles();
	}
}

void CUpdaterMakerDlg::OnBUTTONBrowse() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(FALSE,_T("*.exe|"),NULL,OFN_OVERWRITEPROMPT,_T("EXE Files (*.exe)|*.exe||"));
	dlg.DoModal();
	m_Edit_FileName.SetWindowText(dlg.GetPathName());
}

//从ListCtrl中更新list中的内容
void CUpdaterMakerDlg::UpdataListFiles()
{
	m_iterFiles->Files.clear();
	for (int index=0;index<m_List_Files.GetItemCount();index++)
	{
		FileInfo fi;
		fi.FileName=m_List_Files.GetItemText(index,0);
		fi.Directory=m_List_Files.GetItemText(index,1);
		m_iterFiles->Files.push_back(fi);
	}
}



void CUpdaterMakerDlg::AddFiles(CString FromDir, CString ToDir)
{
	CFileFind finder;
	CString m_strCurrentDirectory=FromDir;
	m_strCurrentDirectory += "\\*.*";
	
	BOOL bWorking = finder.FindFile( m_strCurrentDirectory );
	while( bWorking )
	{
		bWorking = finder.FindNextFile();
		if( finder.IsDots())
		{
			continue;
		}else if (finder.IsDirectory())
		{
			AddFiles(FromDir+"\\"+finder.GetFileName(),ToDir+"\\"+finder.GetFileName());
		}else{
			//FromDir;
			int index=m_List_Files.GetItemCount();
			m_List_Files.InsertItem(index,FromDir+"\\"+finder.GetFileName());
			m_List_Files.SetItemText(index,1,ToDir); 
			FileInfo fi;
			fi.FileName=FromDir+"\\"+finder.GetFileName();
			fi.Directory=ToDir;
			m_iterFiles->Files.push_back(fi);
		}
	}
	finder.Close();
}

void CUpdaterMakerDlg::OnBUTTONLoad() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE);
	dlg.DoModal();
	CFile file(dlg.GetPathName(),CFile::modeRead|CFile::typeBinary);
	DWORD fileLength=file.GetLength();
	char* fcontent=new char[fileLength];
	file.Read(fcontent,fileLength);
	CString strFile(fcontent,fileLength);
	m_Edit_Intro.SetWindowText(strFile);
}

CString CUpdaterMakerDlg::GetIntroStr()
{
	CString strEdit;
	m_Edit_Intro.GetWindowText(strEdit);

	UINT pos;
	pos=0;
	strEdit+=_T(" ");
	while(pos!=strEdit.GetLength())
	{
		char c=strEdit.GetAt(pos);
		if (c=='\n'||c=='\r')
		{
			strEdit.Delete(pos);
			continue;
		}
		if (c=='\"')
		{
			strEdit.Delete(pos);
			strEdit.Insert(pos,_T("&quot; "));
			pos+=6;
		}
		else if (c=='\'')
		{
			strEdit.Delete(pos);
			strEdit.Insert(pos,_T("&apos; "));
			pos+=6;
		}
		else if (c=='$')
		{
			strEdit.Insert(pos,_T("$"));
			pos++;
		}
		else if (c=='<')
		{
			strEdit.Delete(pos);
			strEdit.Insert(pos,_T("&lt; "));
			pos+=4;
		}
		else if (c=='>')
		{
			strEdit.Delete(pos);
			strEdit.Insert(pos,_T("&gt; "));
			pos+=4;
		}
		pos++;
	}
	return strEdit;
}
