#ifndef __CCLIENTXMLVALIDATE_H_INCLUDED
#define __CCLIENTXMLVALIDATE_H_INCLUDED

#include "IClientXmlValidate.h"

class CClientXmlValidate : public IClientXmlValidate
{
	virtual bool isValidate(IN CREF MUString& filename) const;
};

#endif