#if !defined(AFX_DLGADDFILE_H__0517DA2C_3A65_40FF_B33B_661C1E0541AC__INCLUDED_)
#define AFX_DLGADDFILE_H__0517DA2C_3A65_40FF_B33B_661C1E0541AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAddFile.h : header file
//
#include "string.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgAddFile dialog
struct OutDir{
	OutDir(CString _a,CString _b):strName(_a),strDir(_b){}
	CString strName;
	CString strDir;
};
const OutDir g_directory[]=
{
	OutDir("PKPMÄ¿Â¼","$INSTDIR\\.."),
	OutDir("Èí¼þÂ·¾¶","$INSTDIR"),
	OutDir("ECPF","$INSTDIR\\..\\ECPF")
};

#define DIRCOUNT 3
class CDlgAddFile : public CDialog
{
// Construction
public:
	CDlgAddFile(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgAddFile)
	enum { IDD = IDD_DIALOG_AddFile };
	CComboBox	m_Combo_Dir;
	//}}AFX_DATA

	CString strFile;
	CString strDir;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAddFile)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAddFile)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnBUTTONBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADDFILE_H__0517DA2C_3A65_40FF_B33B_661C1E0541AC__INCLUDED_)
