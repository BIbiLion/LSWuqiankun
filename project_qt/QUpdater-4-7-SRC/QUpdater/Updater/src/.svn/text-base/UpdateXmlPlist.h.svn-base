#ifndef __CUPDATEXMLPLIST_H_INCLUDED
#define __CUPDATEXMLPLIST_H_INCLUDED

#include <map>
#include <list>
#include "IUpdateXmlPlist.h"
#include "pubfuncs.h"

class CUpdateXmlPlistNode : public IUpdateXmlPlistNode
{
public:
	virtual bool operator == (const CUpdateXmlPlistNode& _obj)
	{
		//本地不书写md5的数值
		//return IUpdateXmlPlistNode::md5 == _obj.md5;
		return (IUpdateXmlPlistNode::name ==  _obj.name) &&
			(IUpdateXmlPlistNode::packName ==  _obj.packName) &&
			(IUpdateXmlPlistNode::publishTime == _obj.publishTime); 
	}

	virtual bool operator < (const CUpdateXmlPlistNode& _obj)
	{
		return IUpdateXmlPlistNode::publishTime < _obj.publishTime;
	}

	virtual bool isValid() const
	{
		return IUpdateXmlPlistNode::name != "" &&
			IUpdateXmlPlistNode::packName != "" &&
			IUpdateXmlPlistNode::publishTime != 0;
	}
};

typedef CUpdateXmlPlistNode CUpdatePack;

class CUpdateXmlPlistTree : public IUpdateXmlPlistTree
{
public:
	CUpdateXmlPlistTree();

public:
	virtual void calcClientNeedUpdate(IUpdateXmlPlistTree* pserver);
	virtual bool loadFromPlist(const QString& filename);
	virtual bool saveToPlistServer(const QString& filename);
	virtual void clear();
	virtual bool isValid();

public:
	struct EachSoftUpdate
	{
		QString softName;//软件名称
		qlonglong      softLastData;//当前版本
		int			softKey;//软件的附加锁类型

		typedef std::list<CUpdateXmlPlistNode> TPackDatas;
		typedef TPackDatas::iterator TIterEachPack;
		TPackDatas dataNodes;//! 安装包的安装数据树

		TIterEachPack begin()
		{
			return dataNodes.begin();
		}

		TIterEachPack end()
		{
			return dataNodes.end();
		}

		TIterEachPack findPack(const QString& name)
		{
			TIterEachPack iterpack = dataNodes.begin();
			while (iterpack != dataNodes.end())
			{
				if (iterpack->name == name)
				{
					return iterpack;
				}
				++iterpack;
			}
			return iterpack;
		}

		CUpdatePack* findPackPt(const QString& name)
		{
			TIterEachPack iterpack = findPack(name);
			return iterpack != end() ? &*iterpack : 0;
		}

		bool isPackFound(TIterEachPack& iter)
		{
			return iter != end();
		}

		bool isPackFound(const QString& name)
		{
			return isPackFound(findPack(name));
		}
	};

	typedef std::map<QString, EachSoftUpdate> TEachSoftware;
	typedef std::map<QString, EachSoftUpdate>::iterator TIterEachSoftware;
	TEachSoftware dataTree;//! 主数据存储树

	TIterEachSoftware begin()
	{
		return dataTree.begin();
	}

	TIterEachSoftware end()
	{
		return dataTree.end();
	}

	TIterEachSoftware findSoft(const XString& softname)
	{
		TIterEachSoftware iterSoft = begin();
		while (iterSoft != end())
		{
			if (iterSoft->first == softname)
			{
				return iterSoft;
			}
			++iterSoft;
		}
		return iterSoft;
	}

	bool isSoftFound(TIterEachSoftware& iter)
	{
		return iter != end();
	}

	bool isSoftFound(const XString& softname)
	{
		return isSoftFound(findSoft(softname));
	}

	//
	virtual bool addSoft(const XString& softname);
	virtual bool removeSoft(const XString& softname);
	virtual bool renameSoft(const XString& oldsoftname, const XString& newsoftname);
	virtual bool addPack(const IUpdateXmlPlistNode* pPack);
	virtual bool removePack(const XString& softname, const XString& packname);
};

#endif