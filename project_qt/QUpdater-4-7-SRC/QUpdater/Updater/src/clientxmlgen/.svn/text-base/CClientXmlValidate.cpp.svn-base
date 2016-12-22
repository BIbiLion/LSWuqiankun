#include "stdafx.h"
#include "CClientXmlValidate.h"
#include "Markup.h"

bool CClientXmlValidate::isValidate(IN CREF MUString& filename) const
{
	CFileFind find;
	if (!find.FindFile(filename.c_str()))
	{
		return false;
	}

	CMarkup xmlReader;
	if (!xmlReader.Load(filename.c_str()))
	{
		return false;
	}

	return true;
}