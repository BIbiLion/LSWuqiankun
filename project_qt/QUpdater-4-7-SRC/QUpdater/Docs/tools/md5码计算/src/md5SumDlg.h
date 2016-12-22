// md5SumDlg.h : header file
//

#if !defined(AFX_MD5SUMDLG_H__01E8ED8C_2DCF_43A8_83B2_AF218A5AEF08__INCLUDED_)
#define AFX_MD5SUMDLG_H__01E8ED8C_2DCF_43A8_83B2_AF218A5AEF08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMd5SumDlg dialog

class CMd5SumDlg : public CDialog
{
// Construction
public:
	CMd5SumDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMd5SumDlg)
	enum { IDD = IDD_MD5SUM_DIALOG };
	CEdit	m_Edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMd5SumDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMd5SumDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBUTTONBrowse();
	afx_msg void OnBUTTONBrowsePath();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MD5SUMDLG_H__01E8ED8C_2DCF_43A8_83B2_AF218A5AEF08__INCLUDED_)
