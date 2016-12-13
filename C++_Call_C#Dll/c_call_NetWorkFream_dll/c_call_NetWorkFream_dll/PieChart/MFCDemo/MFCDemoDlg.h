// MFCDemoDlg.h : header file
//
#include "ManagedCode.h"
#pragma once

// CMFCDemoDlg dialog
class CMFCDemoDlg : public CDialog
{
// Construction
public:
	CMFCDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	CWinFormsControl<System::Drawing::PieChart::PieChartControl> m_pieChartControl;


	int step;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonChange();
};
