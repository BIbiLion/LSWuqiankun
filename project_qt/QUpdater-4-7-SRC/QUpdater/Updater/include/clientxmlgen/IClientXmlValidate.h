#ifndef __ICLIENTXMLVALIDATE_H_INCLUDED
#define __ICLIENTXMLVALIDATE_H_INCLUDED

interface IClientXmlValidate
{
	virtual bool isValidate(IN CREF MUString& filename) const = 0;
};

#endif