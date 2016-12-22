// UpdaterMakerDlg.h : header file
//

#if !defined(AFX_UPDATERMAKERDLG_H__3295CF89_E7C7_4093_A477_A121C70BD06F__INCLUDED_)
#define AFX_UPDATERMAKERDLG_H__3295CF89_E7C7_4093_A477_A121C70BD06F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUpdaterMakerDlg dialog

struct FileInfo{
	CString FileName;
	CString Directory;
};
struct GroupList{
	CString GroupName;
	std::list<FileInfo> Files;
};

class CUpdaterMakerDlg : public CDialog
{
// Construction
public:
	CString GetIntroStr();
	void AddFiles(CString FromDir,CString ToDir);
	//根据list更新ListCtrl控件内容
	void UpdataListCtrl();
	//根据ListCtrl控件内容更新list信息
	void UpdataListFiles();
	CUpdaterMakerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUpdaterMakerDlg)
	enum { IDD = IDD_UPDATERMAKER_DIALOG };
	CButton	m_Check_UpdataSelf;
	CButton	m_Check_bWizard;
	CEdit	m_Edit_FileName;
	CListBox	m_List_Group;
	CListCtrl	m_List_Files;
	CEdit	m_Edit_PathName;
	CComboBox	m_Combo_SoftName;
	CEdit	m_Edit_Intro;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpdaterMakerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	std::list<GroupList>	m_FilesInfo;
	std::list<GroupList>::iterator m_iterFiles;
	// Generated message map functions
	//{{AFX_MSG(CUpdaterMakerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBUTTONMake1();
	afx_msg void OnBUTTONNext();
	afx_msg void OnBUTTONPrevious();
	afx_msg void OnSelchangeLISTGroup();
	afx_msg void OnBUTTONAddGroup();
	afx_msg void OnBUTTONDelGroup();
	afx_msg void OnBUTTONModGroup();
	afx_msg void OnBUTTONAddFiles();
	afx_msg void OnBUTTONDelFiles();
	afx_msg void OnBUTTONModFile();
	afx_msg void OnBUTTONBrowse();
	afx_msg void OnBUTTONAddDir();
	afx_msg void OnBUTTONLoad();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPDATERMAKERDLG_H__3295CF89_E7C7_4093_A477_A121C70BD06F__INCLUDED_)
