#ifndef __ICLIENTXMLGENERATER_H_INCLUDED
#define __ICLIENTXMLGENERATER_H_INCLUDED

#include "IUpdateXmlPlist.h"

interface IClientXmlGenerater
{
	//从注册表中获取软件信息，制作客户端的xml文件
	virtual bool MakeXml() = 0;

	//将xml由操作保存回文件
	virtual bool Save2File(IN CREF MUString& filename) const = 0;

	//读取xml文件
	virtual bool LoadXml(IN CREF MUString& filename) = 0;

	//移除一个软件的信息
	virtual bool removeSoft(IN CREF MUString& softname) = 0;

	//移除一个补丁的安装信息
	virtual bool removePack(IN CREF IUpdateXmlPlistNode& node) =0;

	//添加一个软件的信息
	virtual bool appendSoft(IN CREF MUString& softname,INT keytype) = 0;

	//添加一个补丁
	virtual bool appendPack(IN CREF IUpdateXmlPlistNode& node) = 0;
	//添加一个补丁
	virtual void cleanSoft(std::list<MUString>& softlist) = 0;
};

IClientXmlGenerater* wfwGetClientXmlGenerater();

#endif