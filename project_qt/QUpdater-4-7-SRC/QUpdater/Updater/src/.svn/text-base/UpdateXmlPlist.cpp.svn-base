#include <QtCore>
#include <QtXml/QXmlStreamReader>
#include <QtXml/QXmlStreamWriter>
#include "UpdateXmlPlist.h"
#include "pubfuncs.h"
#include <algorithm>
#include "WexTextCodecPlugin.h"

CUpdateXmlPlistTree::CUpdateXmlPlistTree()
{
	clear();
}

bool CUpdateXmlPlistTree::isValid()
{
	return SIZE(dataTree) != 0;
}

void CUpdateXmlPlistTree::clear()
{
	dataTree.clear();
}

void CUpdateXmlPlistTree::calcClientNeedUpdate(IUpdateXmlPlistTree* _pserver)
{
	//比对两个树，如果updatenode的时间左<右，则说明需要需要更新
	CUpdateXmlPlistTree* pserver = static_cast<CUpdateXmlPlistTree*>(_pserver);

	//! 分别遍历本地的所有软件.
	//! 以下判断的顺序不能改变.
	TIterEachSoftware iterEachSoft = this->dataTree.begin();
	while(iterEachSoft != this->dataTree.end())
	{
		EachSoftUpdate* pclientEachSoftUpdate = &iterEachSoft->second;

		//在服务器的树中找到对应的该项目
		TIterEachSoftware iterServerFind = pserver->dataTree.find(pclientEachSoftUpdate->softName);
		if (iterServerFind != pserver->dataTree.end())
		{
			EachSoftUpdate* pServerEachSoftUpdate = &iterServerFind->second;

			//在服务器中找到了该软件的更新记录
			//遍历本地与服务器的不同
			//如果本地没有，服务器上面有，或者服务器上面的补丁时间大于本地安装的时间，则标记服务器上的need为true
			//否则为false
			
			//判断所有服务器上面的比本地时间新的文件
			//全权限
			EachSoftUpdate::TIterEachPack iterServerPack = pServerEachSoftUpdate->dataNodes.begin();
			while(iterServerPack != pServerEachSoftUpdate->dataNodes.end())
			{
				CUpdateXmlPlistNode* pPack = &*iterServerPack;
				if (pPack->publishTime > pclientEachSoftUpdate->softLastData)
					pPack->needupdate = true;
				else
					pPack->needupdate = false;
				++iterServerPack;
			}

			//如果本地没有，服务器上有，则不关心补丁发布日期
			//全权限
			//屏蔽掉，以避免时间上的更新错误
			/*EachSoftUpdate::TIterEachPack */
			/*
			iterServerPack = pServerEachSoftUpdate->dataNodes.begin();
			//遍历服务器上的所有补丁
			while(iterServerPack != pServerEachSoftUpdate->dataNodes.end())
			{
				CUpdateXmlPlistNode* pPack = &*iterServerPack;

				//在本地中找该补丁
				EachSoftUpdate::TIterEachPack piterClientFind = std::find( pclientEachSoftUpdate->dataNodes.begin(),
																									 pclientEachSoftUpdate->dataNodes.end(),
																									*pPack);
				if (piterClientFind == pclientEachSoftUpdate->dataNodes.end())
					pPack->needupdate = true;
				else
					pPack->needupdate = false;
				++iterServerPack;
			}
			*/

			//判断补丁包的最小依赖安装时间
			//只能改为false，不具有true权限
			//false权限
			iterServerPack = pServerEachSoftUpdate->dataNodes.begin();
			while (iterServerPack != pServerEachSoftUpdate->dataNodes.end())
			{
				CUpdatePack* pPack = &*iterServerPack;

				//如果补丁包的最小依赖软件版本时间大于本地软件的时间，则不能安装本补丁
				if (pPack->minSoftTime != 0)//如果为0，说名此不需要判断此项目
				{
					if (pPack->minSoftTime > pclientEachSoftUpdate->softLastData)
						pPack->needupdate = false;
				}

				//判断软件锁是否可以使用
				if (pPack->appendKey != pclientEachSoftUpdate->softKey)
				{
					pPack->needupdate = false;
				}

				++iterServerPack;
			}

			//判断补丁包的依赖补丁项目
			/*
				1，遍历该pPack的依赖项目列表
				2，在本地installedpack池中查询该项目
				3，如果不存在，则needpack置false
				全局仅具有false权限
			*/
			iterServerPack = pServerEachSoftUpdate->dataNodes.begin();
			while (iterServerPack != pServerEachSoftUpdate->dataNodes.end())
			{
				CUpdatePack* pPack = &*iterServerPack;

				std::map<QString, bool>::iterator iterDependPack = pPack->dependPacks.begin();
				while (iterDependPack != pPack->dependPacks.end())
				{
					//依赖的补丁包的名称
					const QString& dependPackname = iterDependPack->first;

					//在客户端已安装列表中查找
					if (pclientEachSoftUpdate->isPackFound(dependPackname))
					{
						//找到该依赖项
						iterDependPack->second = true;
					}
					else
					{
						iterDependPack->second = false;
						pPack->needupdate = false;
					}

					++iterDependPack;
				}
				++iterServerPack;
			}

			//一次判断结束
		}

		++iterEachSoft;
	}
}

#define XMLNODEATTRIBUTE_FILENAME "filename"
#define XMLNODEATTRIBUTE_INFO "info"//信息数据块，将选择放入CDATA模块中
#define XMLNODEATTRIBUTE_MD5 "md5"
#define XMLNODEATTRIBUTE_PUBLISHTIME "publishtime"
#define XMLNODEATTRIBUTE_SIZE "size"
#define XMLNODEATTRIBUTE_NAME "name"

#define XMLNODEATTRIBUTE_MINSOFTTIME "minsofttime"
#define XMLNODEATTRIBUTE_DEBPENDPACKS "dependpacks"

#define XMLNODEATTRIBUTE_SELFUPDATE "selfupdate" //默认为false
#define XMLNODEATTRIBUTE_SHOWUI	"showui" //默认为false
#define XMLNODEATTRIBUTE_DEBUG "debug" //测试模式，默认为true
#define XMLNODEATTRIBUTE_MUSTDOWNLOAD "mustdownload" //必选补丁，默认为false
#define XMLNODEATTRIBUTE_APPENDKEY "appendkey" //附加所的类型

#define XMLTRUE(_value) ((_value) == "true" )
#define RVXMLTRUE(_bool) (_bool ? "true" : "false")


bool CUpdateXmlPlistTree::loadFromPlist(const QString& filename)
{
	//文件状态异常
	if (filename.isEmpty())
		return false;
	if (!QFile::exists(filename))
		return false;

	//打开文件
	QFile xmlfile(filename);
	if (!xmlfile.open(QIODevice::ReadOnly | QFile::Text))
		return false;

	//清空数据
	clear();

	QXmlStreamReader xmlStreamReader(&xmlfile);
	if (xmlStreamReader.error() == QXmlStreamReader::NoError)
	{
		//xml打开没有错误
		EachSoftUpdate esoftUpdate;

		while (!xmlStreamReader.atEnd())
		{
			xmlStreamReader.readNext();

			if (xmlStreamReader.isEndElement())
				//break;
				continue;

			QStringRef name = xmlStreamReader.name();
			const QXmlStreamAttributes& attris = xmlStreamReader.attributes();

			if (xmlStreamReader.isStartElement() && name != "Root")//排除根节点
			{
				//软件名称行
				if (name == "EachSoft")
				{
					esoftUpdate.softName = attris.value("Name").toString();//软件名称
					esoftUpdate.softLastData = attris.value("LastDate").toString().toLongLong();
					esoftUpdate.softKey = attris.value("Key").toString().toInt();//软件锁的标示

					esoftUpdate.dataNodes.clear();
				}

				//更新列表：客户端已安装、服务器端提供
				if (name == "InstalledPacks" || name == "Pack")
				{
					CUpdateXmlPlistNode nodeUpdate;
					nodeUpdate.info = attris.value(XMLNODEATTRIBUTE_INFO).toString();
					nodeUpdate.md5 = attris.value(XMLNODEATTRIBUTE_MD5).toString();
					nodeUpdate.md5 = nodeUpdate.md5.toLower();
					nodeUpdate.name = attris.value(XMLNODEATTRIBUTE_NAME).toString();
					nodeUpdate.packName = attris.value(XMLNODEATTRIBUTE_FILENAME).toString();
					nodeUpdate.packSize = attris.value(XMLNODEATTRIBUTE_SIZE).toString();
					nodeUpdate.publishTime = attris.value(XMLNODEATTRIBUTE_PUBLISHTIME).toString().toLongLong();
					nodeUpdate.softname = esoftUpdate.softName;
					nodeUpdate.minSoftTime = attris.value(XMLNODEATTRIBUTE_MINSOFTTIME).toString().toLongLong();
					QString strDependPacks = attris.value(XMLNODEATTRIBUTE_DEBPENDPACKS).toString();
					//依赖的补丁包之间以 ## 分隔开
					QStringList strlistdependpacks = strDependPacks.split("##", QString::SkipEmptyParts);
					nodeUpdate.dependPacks.clear();
					for (int i=0; i<strlistdependpacks.count(); i++)
					{
						nodeUpdate.dependPacks[strlistdependpacks.at(i)] = true;
					}
					nodeUpdate.isSelfUpdate = XMLTRUE(attris.value(XMLNODEATTRIBUTE_SELFUPDATE).toString().toLower());//是否是自身升级
					nodeUpdate.needUiShow = XMLTRUE(attris.value(XMLNODEATTRIBUTE_SHOWUI).toString().toLower());//是否需要显示安装界面
					nodeUpdate.debugmode = XMLTRUE(attris.value(XMLNODEATTRIBUTE_DEBUG).toString().toLower());//测试模式
					nodeUpdate.mustdownload = XMLTRUE(attris.value(XMLNODEATTRIBUTE_MUSTDOWNLOAD).toString().toLower());//必选补丁
					nodeUpdate.appendKey = attris.value(XMLNODEATTRIBUTE_APPENDKEY).toString().toInt();//附加所的类型

					//test
					//nodeUpdate.needUiShow = true;
					//nodeUpdate.isSelfUpdate = true;
					// \test

					nodeUpdate.needupdate = true;//先预设置为都要更新
					nodeUpdate.needdownload = true;//现预设值为都要下载

					//将数据放入树结构中
					TIterEachSoftware iterSoft = dataTree.find(esoftUpdate.softName);
					if (iterSoft != dataTree.end())
					{
						//说明已存在此软件
						iterSoft->second.dataNodes.push_back(nodeUpdate);
					}
					else
					{
						esoftUpdate.dataNodes.push_back(nodeUpdate);
						//新的软件
						dataTree[esoftUpdate.softName] = esoftUpdate;
					}
				}
			}
		}
	}
	else
	{
		xmlfile.close();
		return false;
	}

	xmlfile.close();

	return true;
}

//保存
bool CUpdateXmlPlistTree::saveToPlistServer(const QString& filename)
{
	if (filename.isEmpty())
		return false;
	
	//如果本地存在同名文件，则先备份此文件
	{
		QString localfilename = filename;
		while (QFile::exists(localfilename))
		{
			QString currentTime = QDateTime::currentDateTime().toString("yy-MM-dd-hh-mm-ss");
			localfilename += "_" + currentTime + ".bak";
		}
		QFile::rename(filename, localfilename);
	}

	QFile baseFile(filename);
	if (!baseFile.open(QIODevice::WriteOnly | QIODevice::Text))
		return false;
	QXmlStreamWriter xmlWriter(&baseFile);

	//设置头
	QTextCodec* localCode = WGetTextCodeForName("GB18030");
	xmlWriter.setCodec(localCode);
	xmlWriter.writeStartDocument("1.0");

	//写root
	xmlWriter.writeStartElement(QLatin1String("Root"));

	//遍历书写软件
	TIterEachSoftware iterSoft = begin();
	while (iterSoft != end())
	{
		xmlWriter.writeStartElement(QLatin1String("EachSoft"));
		
		EachSoftUpdate* pSoft = &iterSoft->second;
		xmlWriter.writeAttribute(QLatin1String("Name"), pSoft->softName);//软件名称
		xmlWriter.writeAttribute(QLatin1String("Key"), QString::number(pSoft->softKey));//软件锁的类型

		//遍历现有补丁
		EachSoftUpdate::TIterEachPack iterPack = pSoft->begin();
		while (iterPack != pSoft->end())
		{
			CUpdatePack* pPack = &*iterPack;
			xmlWriter.writeStartElement(QLatin1String("Pack"));

			//书写数据
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_INFO, pPack->info);
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_MD5, pPack->md5);
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_NAME, pPack->name);
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_FILENAME, pPack->packName);
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_SIZE, pPack->packSize);
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_PUBLISHTIME, QString::number(pPack->publishTime));
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_MINSOFTTIME, QString::number(pPack->minSoftTime));
			//合并依赖补丁包
			QString dependpacksstr;
			std::map<QString, bool>::iterator iterDependPack = pPack->dependPacks.begin();
			while (iterDependPack != pPack->dependPacks.end())
			{
				dependpacksstr += iterDependPack->first + "##";
				++iterDependPack;
			}
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_DEBPENDPACKS, dependpacksstr);
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_SELFUPDATE, RVXMLTRUE(pPack->isSelfUpdate));
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_SHOWUI, RVXMLTRUE(pPack->needUiShow));
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_DEBUG, RVXMLTRUE(pPack->debugmode));
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_MUSTDOWNLOAD, RVXMLTRUE(pPack->mustdownload));
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_APPENDKEY, QString::number(pPack->appendKey));

			xmlWriter.writeEndElement();
			++iterPack;
		}

		xmlWriter.writeEndElement();
		++iterSoft;
	}

	xmlWriter.writeEndElement();
	xmlWriter.writeEndDocument();
	baseFile.close();
	return true;
}

bool CUpdateXmlPlistTree::addSoft(const XString& softname)
{
	if (isSoftFound(softname))
		return false;

	//没有该软件的信息
	EachSoftUpdate xx;
	xx.softName = softname;
	dataTree.insert( std::make_pair(softname, xx));
	return true;
}

bool CUpdateXmlPlistTree::removeSoft(const XString& softname)
{
	if (!isSoftFound(softname))
		return true;

	//找到了该软件
	TIterEachSoftware itersoft = findSoft(softname);
	dataTree.erase(itersoft);
	return true;
}

bool CUpdateXmlPlistTree::addPack(const IUpdateXmlPlistNode* pPack)
{	
	QString softname = pPack->softname;

	//插入该补丁对应的软件
	addSoft(softname);

	//找到该软件
	TIterEachSoftware iterSoft = findSoft(softname);

	EachSoftUpdate& soft = iterSoft->second;

	if (soft.isPackFound(pPack->name))
		return false;//存在相同名称的补丁

	soft.dataNodes.push_back(*((CUpdatePack*)pPack));

	return true;
}

bool CUpdateXmlPlistTree::removePack(const XString& softname, const XString& packname)
{
	//找到对应的软件
	if (!isSoftFound(softname))
		return true;

	TIterEachSoftware iterSoft = findSoft(softname);

	EachSoftUpdate& soft = iterSoft->second;

	if (!soft.isPackFound(packname))
		return true;//没有找到

	EachSoftUpdate::TIterEachPack iterPack = soft.findPack(packname);

	soft.dataNodes.erase(iterPack);
	
	return true;
}

bool CUpdateXmlPlistTree::renameSoft(const QString& oldsoftname, const QString& newsoftname)
{
	if (!isSoftFound(oldsoftname))
		return false;//没有找到
	if (isSoftFound(newsoftname))
		return false;//重名

	TIterEachSoftware iterSoft = findSoft(oldsoftname);

	EachSoftUpdate soft = iterSoft->second;
	dataTree.erase(iterSoft);//移除旧的

	soft.softName = newsoftname;

	//遍历所有的补丁，修改补丁中的名称
	EachSoftUpdate::TIterEachPack iterPack = soft.begin();
	while (iterPack != soft.end())
	{
		CUpdatePack& pack = *iterPack;
		pack.softname = newsoftname;
		++iterPack;
	}

	dataTree.insert( std::make_pair(newsoftname, soft));//插入新的

	return true;
}