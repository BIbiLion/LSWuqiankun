#ifndef __MBCSUNICODESTD_H_INCLUDED
#define __MBCSUNICODESTD_H_INCLUDED

#include <string>

#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#endif

#ifdef NMFC
#define NONMFC
#undef USEMFC
#else
#define USEMFC
#endif

#ifdef MUString
#undef MUString
#endif

#ifdef _UNICODE
#define MUString std::wstring
#else
#define MUString std::string
#endif

#ifdef NONMFC
#define MCString MUString
#ifdef _UNICODE
#define _TT(a) L##a
#else
#define _TT(a) a
#endif
#else
#define MCString CString
#define _TT(a) _T(a)
#endif

#endif