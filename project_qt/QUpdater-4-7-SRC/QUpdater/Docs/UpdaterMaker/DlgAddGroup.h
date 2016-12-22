#if !defined(AFX_DLGADDGROUP_H__7C70541A_3A8D_4B22_A61C_62B8E62717D7__INCLUDED_)
#define AFX_DLGADDGROUP_H__7C70541A_3A8D_4B22_A61C_62B8E62717D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAddGroup.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgAddGroup dialog

class CDlgAddGroup : public CDialog
{
// Construction
public:
	CDlgAddGroup(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgAddGroup)
	enum { IDD = IDD_DIALOG_AddGroup };
	CString	m_Edit_Name;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAddGroup)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAddGroup)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADDGROUP_H__7C70541A_3A8D_4B22_A61C_62B8E62717D7__INCLUDED_)
