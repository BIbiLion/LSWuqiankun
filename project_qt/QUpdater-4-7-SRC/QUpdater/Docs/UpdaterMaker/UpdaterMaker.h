// UpdaterMaker.h : main header file for the UPDATERMAKER application
//

#if !defined(AFX_UPDATERMAKER_H__4C3129B3_AE02_408D_A97E_2EADE36B0CD3__INCLUDED_)
#define AFX_UPDATERMAKER_H__4C3129B3_AE02_408D_A97E_2EADE36B0CD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUpdaterMakerApp:
// See UpdaterMaker.cpp for the implementation of this class
//

class CUpdaterMakerApp : public CWinApp
{
public:
	CUpdaterMakerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUpdaterMakerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUpdaterMakerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPDATERMAKER_H__4C3129B3_AE02_408D_A97E_2EADE36B0CD3__INCLUDED_)
