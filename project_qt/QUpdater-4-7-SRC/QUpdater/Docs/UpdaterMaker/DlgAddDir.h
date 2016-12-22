#if !defined(AFX_DLGADDDIR_H__EEE2E3F1_1C3F_4AE5_BC06_F2BADDA4F3D1__INCLUDED_)
#define AFX_DLGADDDIR_H__EEE2E3F1_1C3F_4AE5_BC06_F2BADDA4F3D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAddDir.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgAddDir dialog

class CDlgAddDir : public CDialog
{
// Construction
public:
	CDlgAddDir(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgAddDir)
	enum { IDD = IDD_DIALOG_AddDir };
	CComboBox	m_Combo_Dir;
	//}}AFX_DATA
	
	CString strFile;
	CString strDir;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAddDir)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAddDir)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnBUTTONBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADDDIR_H__EEE2E3F1_1C3F_4AE5_BC06_F2BADDA4F3D1__INCLUDED_)
