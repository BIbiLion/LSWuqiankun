#ifndef __ICLIENTXMLGENERATER_H_INCLUDED
#define __ICLIENTXMLGENERATER_H_INCLUDED

#include "IUpdateXmlPlist.h"

interface IClientXmlGenerater
{
	//��ע����л�ȡ�����Ϣ�������ͻ��˵�xml�ļ�
	virtual bool MakeXml() = 0;

	//��xml�ɲ���������ļ�
	virtual bool Save2File(IN CREF MUString& filename) const = 0;

	//��ȡxml�ļ�
	virtual bool LoadXml(IN CREF MUString& filename) = 0;

	//�Ƴ�һ���������Ϣ
	virtual bool removeSoft(IN CREF MUString& softname) = 0;

	//�Ƴ�һ�������İ�װ��Ϣ
	virtual bool removePack(IN CREF IUpdateXmlPlistNode& node) =0;

	//���һ���������Ϣ
	virtual bool appendSoft(IN CREF MUString& softname,INT keytype) = 0;

	//���һ������
	virtual bool appendPack(IN CREF IUpdateXmlPlistNode& node) = 0;
	//���һ������
	virtual void cleanSoft(std::list<MUString>& softlist) = 0;
};

IClientXmlGenerater* wfwGetClientXmlGenerater();

#endif