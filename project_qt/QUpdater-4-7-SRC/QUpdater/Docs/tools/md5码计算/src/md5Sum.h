// md5Sum.h : main header file for the MD5SUM application
//

#if !defined(AFX_MD5SUM_H__5466F6FD_11B7_4ED7_B8F3_07CB87CD9C6B__INCLUDED_)
#define AFX_MD5SUM_H__5466F6FD_11B7_4ED7_B8F3_07CB87CD9C6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMd5SumApp:
// See md5Sum.cpp for the implementation of this class
//

class CMd5SumApp : public CWinApp
{
public:
	CMd5SumApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMd5SumApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMd5SumApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MD5SUM_H__5466F6FD_11B7_4ED7_B8F3_07CB87CD9C6B__INCLUDED_)
