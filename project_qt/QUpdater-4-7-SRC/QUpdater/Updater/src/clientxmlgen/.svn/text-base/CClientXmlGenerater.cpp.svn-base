#include "stdafx.h"
#include "CClientXmlGenerater.h"
#include "Markup.h"
#include "MfcRegOperator.h"


static CClientXmlGenerater  __g_clientxmlgenerater;

IClientXmlGenerater* wfwGetClientXmlGenerater()
{
	return &__g_clientxmlgenerater;
}

//升级的数据
class CUpdateXmlPlistTree : public IUpdateXmlPlistTree
{
public:
	CUpdateXmlPlistTree()
	{
		pXmlOper=new CMarkup();
	}
	~CUpdateXmlPlistTree()
	{
		pubfunc::release(pXmlOper);
	}
	virtual void calcClientNeedUpdate(IUpdateXmlPlistTree* pserver)
	{}

	//添加软件节点
	virtual bool insertSoft(IN CREF MUString& softname,INT keytype)
	{
		pXmlOper->ResetPos();
		if ( !pXmlOper->FindElem() )
			return false;

		pXmlOper->IntoElem();	//IntoRoot

		while(pXmlOper->FindElem(_T("EachSoft")))
		{
			if (pXmlOper->GetAttrib(_T("Name"))==softname.c_str())
			{//如果已经存在,添加失败
				return false;
			}
		}
		if(pXmlOper->AddElem(_T("EachSoft")))
		{
			MUString keyname="ECPF\\Module\\"+softname;
			//如果注册表中没有此软件的信息，失败
			if (!RegOpe::exist(keyname))return false;

			pXmlOper->AddAttrib(_T("LastDate"),_T("0"));//初始化为0
			pXmlOper->AddAttrib(_T("Name"),softname.c_str());
			pXmlOper->AddAttrib(_T("Key"),keytype);
			//如果读到版本信息，修改其值
			CString clientplistpath;
			if (RegOpe::query(keyname, _T("PATH"), clientplistpath))
			{
				CFile file;
				if(file.Open(clientplistpath+_T("\\version"),CFile::modeRead))
				{
					clientplistpath.ReleaseBuffer(12);
					UINT b=file.Read(clientplistpath.GetBuffer(clientplistpath.GetLength()),12);
					//clientplistpath.SetAt(13,0);
					if (b)
					{
						pXmlOper->AddAttrib(_T("LastDate"),clientplistpath);
					}
					file.Close();
					clientplistpath.ReleaseBuffer();
				}
			}
			pXmlOper->IntoElem();	//IntoRoot
			pXmlOper->AddElem(_T("InstalledPacks"));

		}else{
			return false;
		}
		return true;
	}
	//根据list中的内容，清除不需要的软件信息
	virtual void cleanSoft(std::list<MUString>& softlist)
	{
		pXmlOper->ResetPos();
		if ( !pXmlOper->FindElem() )
			return;

		pXmlOper->IntoElem();	//IntoRoot

		while(pXmlOper->FindElem(_T("EachSoft")))
		{
			std::list<MUString>::iterator iter=softlist.begin();
			bool isExist=false;//此软件是否存在
			MUString softname=pXmlOper->GetAttrib(_T("Name"));
			for (;iter!=softlist.end();iter++)
			{
				if (softname==*iter)
				{
					isExist=true;
				}
			}
			if (!isExist)
			{
				pXmlOper->RemoveElem();
				//removeSoft(softname);
			}
		}
	}
	//移除软件节点
	virtual bool removeSoft(IN CREF MUString& softname)
	{
		pXmlOper->ResetPos();
		if ( !pXmlOper->FindElem() )
			return false;

		pXmlOper->IntoElem();	//IntoRoot

		while(pXmlOper->FindElem(_T("EachSoft")))
		{
			if (pXmlOper->GetAttrib(_T("Name"))==softname.c_str())
			{//如果已经存在,添加失败
				pXmlOper->RemoveElem();
				return true;
			}
		}
		return false;
	}

	//读取文件
	virtual bool loadFromPlist(const MUString& filename)
	{
		return pXmlOper->Load(filename.c_str());
		//return true;
	}

	//保存到文件
	bool save2Plist(const MUString& filename)
	{
		return pXmlOper->Save(filename.c_str());
		//return true;
	}
	virtual bool creatNewXml()
	{
		//清空原来的东西
		pubfunc::release(pXmlOper);
		pXmlOper=new CMarkup;

		pXmlOper->SetDoc(_T("<?xml version=\"1.0\" encoding=\"GB18030\" ?>"));
		pXmlOper->AddElem(_T("Root"));
		return true;
	}
	virtual bool isValid()
	{
		return true;
	}

private:
	CMarkup* pXmlOper;//xml操作子
};


CClientXmlGenerater::CClientXmlGenerater()
: pXmlOper(0),
mDataTree(0)
{
	pXmlOper = new CMarkup();
	mDataTree = new CUpdateXmlPlistTree();
}

CClientXmlGenerater::~CClientXmlGenerater()
{
	pubfunc::release(pXmlOper);
	pubfunc::release(mDataTree);
}

bool CClientXmlGenerater::MakeXml()
{
	mOperMode = GEN;
	
	return mDataTree->creatNewXml();
	//return true;
}

bool CClientXmlGenerater::Save2File(IN CREF MUString& filename) const
{
	return mDataTree->save2Plist(filename);
	//return true;
}

bool CClientXmlGenerater::LoadXml(IN CREF MUString& filename)
{
	mOperMode = FILE;
	//读取一个目标xml文件
	return mDataTree->loadFromPlist(filename);
}

bool CClientXmlGenerater::removeSoft(IN CREF MUString& softname)
{
	//针对 pOperXml 操作

	return mDataTree->removeSoft(softname);
}

bool CClientXmlGenerater::removePack(IN CREF IUpdateXmlPlistNode& node)
{
	//针对 pOperXml 操作
	
	return true;
}

bool CClientXmlGenerater::appendSoft(IN CREF MUString& softname,INT keytype)
{
	//添加 一个软件

	return mDataTree->insertSoft(softname,keytype);
}

bool CClientXmlGenerater::appendPack(IN CREF IUpdateXmlPlistNode& node)
{
	//添加 一个补丁

	return true;
}

void CClientXmlGenerater::cleanSoft(std::list<MUString>& softlist)
{
	//整理软件，去除没有的软件
	mDataTree->cleanSoft(softlist);
}