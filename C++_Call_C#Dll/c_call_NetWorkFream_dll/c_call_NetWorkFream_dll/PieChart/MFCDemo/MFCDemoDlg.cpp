// MFCDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCDemo.h"
#include "MFCDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDemoDlg dialog




CMFCDemoDlg::CMFCDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCDemoDlg::IDD, pParent), step(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	/*
	 * add the following line, it's something like, the Managed Control
	 * is associated with IDC_PLACEHOLDER, which is a MFC resource and 
	 * will be displayed. and it doesn't matter what the original type
	 * of control is associated with the ID, you can change IDC_PLACEHOLDER,
	 * which is a static originally, to IDC_BUTTON1, which is a button originally
	 */
	Microsoft::VisualC::MFC::DDX_ManagedControl(pDX, IDC_PLACEHOLDER /*IDC_BUTTON1*/, m_pieChartControl);

}

BEGIN_MESSAGE_MAP(CMFCDemoDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &CMFCDemoDlg::OnBnClickedButtonChange)
END_MESSAGE_MAP()


// CMFCDemoDlg message handlers

BOOL CMFCDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
 
	

	m_pieChartControl->LeftMargin = 10;
	m_pieChartControl->RightMargin = 10;
	m_pieChartControl->TopMargin = 20;
	m_pieChartControl->BottomMargin = 20;
	m_pieChartControl->FitChart = false;
	m_pieChartControl->SliceRelativeHeight = 0.25;
	m_pieChartControl->InitialAngle = -30;
	m_pieChartControl->EdgeLineWidth = 1;
	m_pieChartControl->Size = Size(400, 200);
	m_pieChartControl->Location = Point(10, 10);	
	
	ColorArray colors;
	colors.Add(Color::Red);
	colors.Add(Color::Blue);
	colors.Add(Color::Yellow);
	colors.Add(Color::Orange);
	colors.Add(Color::Purple);
	colors.Add(Color::Green);

	DecimalArray values;
	values.Add(20);
	values.Add(20);
	values.Add(10);
	values.Add(30);
	values.Add(10);
	values.Add(10);

	StringArray texts;
	texts.Add("hello1");
	texts.Add("hello2");
	texts.Add("hello3");
	texts.Add("hello4");
	texts.Add("hello5");
	texts.Add("hello6");

	FloatArray displacement;
	displacement.Add(0.20f);
	displacement.Add(0.05f);
	displacement.Add(0.05f);
	displacement.Add(0.05f);
	displacement.Add(0.05f);
	displacement.Add(0.05f);	

	//it is used like a pointer, you may remember how to use a smart pointer
	m_pieChartControl->Colors = colors.Get(); 
	m_pieChartControl->Values = values.Get();
	m_pieChartControl->Texts = texts.Get();
	m_pieChartControl->SliceRelativeDisplacements = displacement.Get();

	m_pieChartControl->EdgeColorType = EdgeColorType::LighterThanSurface;
	m_pieChartControl->ShadowStyle = ShadowStyle::GradualShadow;
	m_pieChartControl->ToolTips = texts.Get();


    
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCDemoDlg::OnBnClickedButtonChange()
{	
	Size size = m_pieChartControl->Size;
	if (0 == step || size.Width < 100 || size.Height < 100)
	{
		step = 10;
	}	
	CRect rect;
	GetWindowRect(&rect);
	if (size.Width  > rect.Width()
		|| size.Height  > rect.Height())
	{
		step = -10;
	}

	int newWidth = size.Width + step;
	int newHeight = size.Height + (float)size.Height / size.Width * step;
	m_pieChartControl->Size = Size(newWidth, newHeight);
}
