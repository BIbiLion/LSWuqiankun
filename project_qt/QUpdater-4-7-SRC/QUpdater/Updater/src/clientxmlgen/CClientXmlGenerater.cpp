#include "stdafx.h"
#include "CClientXmlGenerater.h"
#include "Markup.h"
#include "MfcRegOperator.h"


static CClientXmlGenerater  __g_clientxmlgenerater;

IClientXmlGenerater* wfwGetClientXmlGenerater()
{
	return &__g_clientxmlgenerater;
}

//����������
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

	//�������ڵ�
	virtual bool insertSoft(IN CREF MUString& softname,INT keytype)
	{
		pXmlOper->ResetPos();
		if ( !pXmlOper->FindElem() )
			return false;

		pXmlOper->IntoElem();	//IntoRoot

		while(pXmlOper->FindElem(_T("EachSoft")))
		{
			if (pXmlOper->GetAttrib(_T("Name"))==softname.c_str())
			{//����Ѿ�����,���ʧ��
				return false;
			}
		}
		if(pXmlOper->AddElem(_T("EachSoft")))
		{
			MUString keyname="ECPF\\Module\\"+softname;
			//���ע�����û�д��������Ϣ��ʧ��
			if (!RegOpe::exist(keyname))return false;

			pXmlOper->AddAttrib(_T("LastDate"),_T("0"));//��ʼ��Ϊ0
			pXmlOper->AddAttrib(_T("Name"),softname.c_str());
			pXmlOper->AddAttrib(_T("Key"),keytype);
			//��������汾��Ϣ���޸���ֵ
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
	//����list�е����ݣ��������Ҫ�������Ϣ
	virtual void cleanSoft(std::list<MUString>& softlist)
	{
		pXmlOper->ResetPos();
		if ( !pXmlOper->FindElem() )
			return;

		pXmlOper->IntoElem();	//IntoRoot

		while(pXmlOper->FindElem(_T("EachSoft")))
		{
			std::list<MUString>::iterator iter=softlist.begin();
			bool isExist=false;//������Ƿ����
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
	//�Ƴ�����ڵ�
	virtual bool removeSoft(IN CREF MUString& softname)
	{
		pXmlOper->ResetPos();
		if ( !pXmlOper->FindElem() )
			return false;

		pXmlOper->IntoElem();	//IntoRoot

		while(pXmlOper->FindElem(_T("EachSoft")))
		{
			if (pXmlOper->GetAttrib(_T("Name"))==softname.c_str())
			{//����Ѿ�����,���ʧ��
				pXmlOper->RemoveElem();
				return true;
			}
		}
		return false;
	}

	//��ȡ�ļ�
	virtual bool loadFromPlist(const MUString& filename)
	{
		return pXmlOper->Load(filename.c_str());
		//return true;
	}

	//���浽�ļ�
	bool save2Plist(const MUString& filename)
	{
		return pXmlOper->Save(filename.c_str());
		//return true;
	}
	virtual bool creatNewXml()
	{
		//���ԭ���Ķ���
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
	CMarkup* pXmlOper;//xml������
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
	//��ȡһ��Ŀ��xml�ļ�
	return mDataTree->loadFromPlist(filename);
}

bool CClientXmlGenerater::removeSoft(IN CREF MUString& softname)
{
	//��� pOperXml ����

	return mDataTree->removeSoft(softname);
}

bool CClientXmlGenerater::removePack(IN CREF IUpdateXmlPlistNode& node)
{
	//��� pOperXml ����
	
	return true;
}

bool CClientXmlGenerater::appendSoft(IN CREF MUString& softname,INT keytype)
{
	//��� һ�����

	return mDataTree->insertSoft(softname,keytype);
}

bool CClientXmlGenerater::appendPack(IN CREF IUpdateXmlPlistNode& node)
{
	//��� һ������

	return true;
}

void CClientXmlGenerater::cleanSoft(std::list<MUString>& softlist)
{
	//���������ȥ��û�е����
	mDataTree->cleanSoft(softlist);
}