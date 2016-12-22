#ifndef __CCLIENTXMLGENERATER_H_INCLUDED
#define __CCLIENTXMLGENERATER_H_INCLUDED

#include "IClientXmlGenerater.h"

class CMarkup;
class CUpdateXmlPlistTree;
class CClientXmlGenerater : public IClientXmlGenerater
{
	enum operMode
	{
		GEN = 0,
		FILE,
	};
public:
	CClientXmlGenerater();
	virtual ~CClientXmlGenerater();

	virtual bool MakeXml();
	virtual bool Save2File(IN CREF MUString& filename) const;
	virtual bool LoadXml(IN CREF MUString& filename);
	virtual bool removeSoft(IN CREF MUString& softname);
	virtual bool removePack(IN CREF IUpdateXmlPlistNode& node);
	virtual bool appendSoft(IN CREF MUString& softname,INT keytype);
	virtual bool appendPack(IN CREF IUpdateXmlPlistNode& node);
	virtual void cleanSoft(std::list<MUString>& softlist);

private:
	CMarkup* pXmlOper;//xml操作子
	operMode mOperMode;//操作的模式
	CUpdateXmlPlistTree* mDataTree;//主数据树
};

#endif