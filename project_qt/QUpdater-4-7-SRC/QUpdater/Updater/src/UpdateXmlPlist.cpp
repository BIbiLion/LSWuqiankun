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
	//�ȶ������������updatenode��ʱ����<�ң���˵����Ҫ��Ҫ����
	CUpdateXmlPlistTree* pserver = static_cast<CUpdateXmlPlistTree*>(_pserver);

	//! �ֱ�������ص��������.
	//! �����жϵ�˳���ܸı�.
	TIterEachSoftware iterEachSoft = this->dataTree.begin();
	while(iterEachSoft != this->dataTree.end())
	{
		EachSoftUpdate* pclientEachSoftUpdate = &iterEachSoft->second;

		//�ڷ������������ҵ���Ӧ�ĸ���Ŀ
		TIterEachSoftware iterServerFind = pserver->dataTree.find(pclientEachSoftUpdate->softName);
		if (iterServerFind != pserver->dataTree.end())
		{
			EachSoftUpdate* pServerEachSoftUpdate = &iterServerFind->second;

			//�ڷ��������ҵ��˸�����ĸ��¼�¼
			//����������������Ĳ�ͬ
			//�������û�У������������У����߷���������Ĳ���ʱ����ڱ��ذ�װ��ʱ�䣬���Ƿ������ϵ�needΪtrue
			//����Ϊfalse
			
			//�ж����з���������ıȱ���ʱ���µ��ļ�
			//ȫȨ��
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

			//�������û�У����������У��򲻹��Ĳ�����������
			//ȫȨ��
			//���ε����Ա���ʱ���ϵĸ��´���
			/*EachSoftUpdate::TIterEachPack */
			/*
			iterServerPack = pServerEachSoftUpdate->dataNodes.begin();
			//�����������ϵ����в���
			while(iterServerPack != pServerEachSoftUpdate->dataNodes.end())
			{
				CUpdateXmlPlistNode* pPack = &*iterServerPack;

				//�ڱ������Ҹò���
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

			//�жϲ���������С������װʱ��
			//ֻ�ܸ�Ϊfalse��������trueȨ��
			//falseȨ��
			iterServerPack = pServerEachSoftUpdate->dataNodes.begin();
			while (iterServerPack != pServerEachSoftUpdate->dataNodes.end())
			{
				CUpdatePack* pPack = &*iterServerPack;

				//�������������С��������汾ʱ����ڱ��������ʱ�䣬���ܰ�װ������
				if (pPack->minSoftTime != 0)//���Ϊ0��˵���˲���Ҫ�жϴ���Ŀ
				{
					if (pPack->minSoftTime > pclientEachSoftUpdate->softLastData)
						pPack->needupdate = false;
				}

				//�ж�������Ƿ����ʹ��
				if (pPack->appendKey != pclientEachSoftUpdate->softKey)
				{
					pPack->needupdate = false;
				}

				++iterServerPack;
			}

			//�жϲ�����������������Ŀ
			/*
				1��������pPack��������Ŀ�б�
				2���ڱ���installedpack���в�ѯ����Ŀ
				3����������ڣ���needpack��false
				ȫ�ֽ�����falseȨ��
			*/
			iterServerPack = pServerEachSoftUpdate->dataNodes.begin();
			while (iterServerPack != pServerEachSoftUpdate->dataNodes.end())
			{
				CUpdatePack* pPack = &*iterServerPack;

				std::map<QString, bool>::iterator iterDependPack = pPack->dependPacks.begin();
				while (iterDependPack != pPack->dependPacks.end())
				{
					//�����Ĳ�����������
					const QString& dependPackname = iterDependPack->first;

					//�ڿͻ����Ѱ�װ�б��в���
					if (pclientEachSoftUpdate->isPackFound(dependPackname))
					{
						//�ҵ���������
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

			//һ���жϽ���
		}

		++iterEachSoft;
	}
}

#define XMLNODEATTRIBUTE_FILENAME "filename"
#define XMLNODEATTRIBUTE_INFO "info"//��Ϣ���ݿ飬��ѡ�����CDATAģ����
#define XMLNODEATTRIBUTE_MD5 "md5"
#define XMLNODEATTRIBUTE_PUBLISHTIME "publishtime"
#define XMLNODEATTRIBUTE_SIZE "size"
#define XMLNODEATTRIBUTE_NAME "name"

#define XMLNODEATTRIBUTE_MINSOFTTIME "minsofttime"
#define XMLNODEATTRIBUTE_DEBPENDPACKS "dependpacks"

#define XMLNODEATTRIBUTE_SELFUPDATE "selfupdate" //Ĭ��Ϊfalse
#define XMLNODEATTRIBUTE_SHOWUI	"showui" //Ĭ��Ϊfalse
#define XMLNODEATTRIBUTE_DEBUG "debug" //����ģʽ��Ĭ��Ϊtrue
#define XMLNODEATTRIBUTE_MUSTDOWNLOAD "mustdownload" //��ѡ������Ĭ��Ϊfalse
#define XMLNODEATTRIBUTE_APPENDKEY "appendkey" //������������

#define XMLTRUE(_value) ((_value) == "true" )
#define RVXMLTRUE(_bool) (_bool ? "true" : "false")


bool CUpdateXmlPlistTree::loadFromPlist(const QString& filename)
{
	//�ļ�״̬�쳣
	if (filename.isEmpty())
		return false;
	if (!QFile::exists(filename))
		return false;

	//���ļ�
	QFile xmlfile(filename);
	if (!xmlfile.open(QIODevice::ReadOnly | QFile::Text))
		return false;

	//�������
	clear();

	QXmlStreamReader xmlStreamReader(&xmlfile);
	if (xmlStreamReader.error() == QXmlStreamReader::NoError)
	{
		//xml��û�д���
		EachSoftUpdate esoftUpdate;

		while (!xmlStreamReader.atEnd())
		{
			xmlStreamReader.readNext();

			if (xmlStreamReader.isEndElement())
				//break;
				continue;

			QStringRef name = xmlStreamReader.name();
			const QXmlStreamAttributes& attris = xmlStreamReader.attributes();

			if (xmlStreamReader.isStartElement() && name != "Root")//�ų����ڵ�
			{
				//���������
				if (name == "EachSoft")
				{
					esoftUpdate.softName = attris.value("Name").toString();//�������
					esoftUpdate.softLastData = attris.value("LastDate").toString().toLongLong();
					esoftUpdate.softKey = attris.value("Key").toString().toInt();//������ı�ʾ

					esoftUpdate.dataNodes.clear();
				}

				//�����б��ͻ����Ѱ�װ�����������ṩ
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
					//�����Ĳ�����֮���� ## �ָ���
					QStringList strlistdependpacks = strDependPacks.split("##", QString::SkipEmptyParts);
					nodeUpdate.dependPacks.clear();
					for (int i=0; i<strlistdependpacks.count(); i++)
					{
						nodeUpdate.dependPacks[strlistdependpacks.at(i)] = true;
					}
					nodeUpdate.isSelfUpdate = XMLTRUE(attris.value(XMLNODEATTRIBUTE_SELFUPDATE).toString().toLower());//�Ƿ�����������
					nodeUpdate.needUiShow = XMLTRUE(attris.value(XMLNODEATTRIBUTE_SHOWUI).toString().toLower());//�Ƿ���Ҫ��ʾ��װ����
					nodeUpdate.debugmode = XMLTRUE(attris.value(XMLNODEATTRIBUTE_DEBUG).toString().toLower());//����ģʽ
					nodeUpdate.mustdownload = XMLTRUE(attris.value(XMLNODEATTRIBUTE_MUSTDOWNLOAD).toString().toLower());//��ѡ����
					nodeUpdate.appendKey = attris.value(XMLNODEATTRIBUTE_APPENDKEY).toString().toInt();//������������

					//test
					//nodeUpdate.needUiShow = true;
					//nodeUpdate.isSelfUpdate = true;
					// \test

					nodeUpdate.needupdate = true;//��Ԥ����Ϊ��Ҫ����
					nodeUpdate.needdownload = true;//��Ԥ��ֵΪ��Ҫ����

					//�����ݷ������ṹ��
					TIterEachSoftware iterSoft = dataTree.find(esoftUpdate.softName);
					if (iterSoft != dataTree.end())
					{
						//˵���Ѵ��ڴ����
						iterSoft->second.dataNodes.push_back(nodeUpdate);
					}
					else
					{
						esoftUpdate.dataNodes.push_back(nodeUpdate);
						//�µ����
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

//����
bool CUpdateXmlPlistTree::saveToPlistServer(const QString& filename)
{
	if (filename.isEmpty())
		return false;
	
	//������ش���ͬ���ļ������ȱ��ݴ��ļ�
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

	//����ͷ
	QTextCodec* localCode = WGetTextCodeForName("GB18030");
	xmlWriter.setCodec(localCode);
	xmlWriter.writeStartDocument("1.0");

	//дroot
	xmlWriter.writeStartElement(QLatin1String("Root"));

	//������д���
	TIterEachSoftware iterSoft = begin();
	while (iterSoft != end())
	{
		xmlWriter.writeStartElement(QLatin1String("EachSoft"));
		
		EachSoftUpdate* pSoft = &iterSoft->second;
		xmlWriter.writeAttribute(QLatin1String("Name"), pSoft->softName);//�������
		xmlWriter.writeAttribute(QLatin1String("Key"), QString::number(pSoft->softKey));//�����������

		//�������в���
		EachSoftUpdate::TIterEachPack iterPack = pSoft->begin();
		while (iterPack != pSoft->end())
		{
			CUpdatePack* pPack = &*iterPack;
			xmlWriter.writeStartElement(QLatin1String("Pack"));

			//��д����
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_INFO, pPack->info);
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_MD5, pPack->md5);
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_NAME, pPack->name);
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_FILENAME, pPack->packName);
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_SIZE, pPack->packSize);
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_PUBLISHTIME, QString::number(pPack->publishTime));
			xmlWriter.writeAttribute(XMLNODEATTRIBUTE_MINSOFTTIME, QString::number(pPack->minSoftTime));
			//�ϲ�����������
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

	//û�и��������Ϣ
	EachSoftUpdate xx;
	xx.softName = softname;
	dataTree.insert( std::make_pair(softname, xx));
	return true;
}

bool CUpdateXmlPlistTree::removeSoft(const XString& softname)
{
	if (!isSoftFound(softname))
		return true;

	//�ҵ��˸����
	TIterEachSoftware itersoft = findSoft(softname);
	dataTree.erase(itersoft);
	return true;
}

bool CUpdateXmlPlistTree::addPack(const IUpdateXmlPlistNode* pPack)
{	
	QString softname = pPack->softname;

	//����ò�����Ӧ�����
	addSoft(softname);

	//�ҵ������
	TIterEachSoftware iterSoft = findSoft(softname);

	EachSoftUpdate& soft = iterSoft->second;

	if (soft.isPackFound(pPack->name))
		return false;//������ͬ���ƵĲ���

	soft.dataNodes.push_back(*((CUpdatePack*)pPack));

	return true;
}

bool CUpdateXmlPlistTree::removePack(const XString& softname, const XString& packname)
{
	//�ҵ���Ӧ�����
	if (!isSoftFound(softname))
		return true;

	TIterEachSoftware iterSoft = findSoft(softname);

	EachSoftUpdate& soft = iterSoft->second;

	if (!soft.isPackFound(packname))
		return true;//û���ҵ�

	EachSoftUpdate::TIterEachPack iterPack = soft.findPack(packname);

	soft.dataNodes.erase(iterPack);
	
	return true;
}

bool CUpdateXmlPlistTree::renameSoft(const QString& oldsoftname, const QString& newsoftname)
{
	if (!isSoftFound(oldsoftname))
		return false;//û���ҵ�
	if (isSoftFound(newsoftname))
		return false;//����

	TIterEachSoftware iterSoft = findSoft(oldsoftname);

	EachSoftUpdate soft = iterSoft->second;
	dataTree.erase(iterSoft);//�Ƴ��ɵ�

	soft.softName = newsoftname;

	//�������еĲ������޸Ĳ����е�����
	EachSoftUpdate::TIterEachPack iterPack = soft.begin();
	while (iterPack != soft.end())
	{
		CUpdatePack& pack = *iterPack;
		pack.softname = newsoftname;
		++iterPack;
	}

	dataTree.insert( std::make_pair(newsoftname, soft));//�����µ�

	return true;
}