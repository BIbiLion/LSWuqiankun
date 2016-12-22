// DlgAddGroup.cpp : implementation file
//

#include "stdafx.h"
#include "UpdaterMaker.h"
#include "DlgAddGroup.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAddGroup dialog


CDlgAddGroup::CDlgAddGroup(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAddGroup::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAddGroup)
	m_Edit_Name = _T("");
	//}}AFX_DATA_INIT
}


void CDlgAddGroup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAddGroup)
	DDX_Text(pDX, IDC_EDIT_Name, m_Edit_Name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAddGroup, CDialog)
	//{{AFX_MSG_MAP(CDlgAddGroup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAddGroup message handlers

void CDlgAddGroup::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(m_Edit_Name.IsEmpty()){
		MessageBox("«Î ‰»Î◊È√˚!");
		return;
	}
	CDialog::OnOK();
}
