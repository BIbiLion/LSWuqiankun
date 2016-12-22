#ifndef __IUPDATEXMLPLIST_H_INCLUDED
#define __IUPDATEXMLPLIST_H_INCLUDED

#ifndef interface
#define interface struct
#endif

#ifndef QT_CORE_LIB
#define XString MUString
#define XTime long long
#else
#define XString QString
#define XTime qlonglong
#endif

#include <map>

//数据节点结构
interface IUpdateXmlPlistNode
{
	XTime	publishTime;//发布时间
	XString		packName;//补丁文件名
	XString		packSize;//补丁大小
	XString		md5;//md5值
	XString		info;//额外的信息
	XString		name;//补丁的名称
	XString		softname;//所属软件的名称
	
	XTime minSoftTime;//最小软件版本日期依赖
	std::map<XString, bool> dependPacks;//依赖的补丁包
	typedef std::map<XString, bool> TDependPacks;
	typedef TDependPacks::iterator TIterDependPack;

	virtual TIterDependPack dependPacksBegin()
	{
		return dependPacks.begin();
	}
	virtual TIterDependPack dependPacksEnd()
	{
		return dependPacks.end();
	}

	virtual XString getDependPacksStr() 
	{
		typedef std::map<XString, bool>::const_iterator TCIter;
		XString re;
		TCIter iterdata = dependPacks.begin();
		while (iterdata != dependPacks.end())
		{
			re += iterdata->first + "##";
			++iterdata;
		}
		return re;
	}

	XString getServerPath()
	{
		return "/" + softname + "/" + packName;
	}

	bool			isSelfUpdate;//是否是自身升级安装(安装时将自动关闭程序并运行补丁安装)
	bool			needUiShow;//是否需要显示安装界面（安装的时候不默认适配 /S 参数）
	bool			needupdate;//是否需要更新，如果是false，就说明用户已经更新了该文件
	bool			needdownload;//是否需要下载该更新
	bool			debugmode;//测试模式
	bool			mustdownload;//必选补丁
	int				appendKey;//附加锁类型的判断

	//运算符重载
	virtual bool operator == (const IUpdateXmlPlistNode& _obj) {return true;};
	virtual bool operator != (const IUpdateXmlPlistNode& _obj) {return !(*this == _obj);};
	virtual bool operator < (const IUpdateXmlPlistNode& _obj) {return true;};
	virtual bool operator > (const IUpdateXmlPlistNode& _obj) {return !(*this < _obj);};
	virtual bool isValid() const {return true;};
};

//由一个xml生成出来的数据树
interface IUpdateXmlPlistTree
{
	//通过比对，修改数据树，使得最终的树仅还有需要更新的补丁包信息
	virtual void calcClientNeedUpdate(IUpdateXmlPlistTree* pserver) = 0;
	//从文件中生成数据
	virtual bool loadFromPlist(const XString& filename) = 0;
	//保存文件到服务器端数据
	virtual bool saveToPlistServer(const XString& filename) {return true;}
	//保存文件到客户端数据
	virtual bool saveToPlistClient(const XString& filename) {return true;}
	//增加一个软件
	virtual bool addSoft(const XString& softname) {return true;}
	//移除一个软件
	virtual bool removeSoft(const XString& softname) {return true;}
	//修改软件名称
	virtual bool renameSoft(const XString& oldsoftname, const XString& newsoftname) {return true;}
	//增加一个补丁包
	virtual bool addPack(const IUpdateXmlPlistNode* pPack) {return true;}
	//移除一个补丁包
	virtual bool removePack(const IUpdateXmlPlistNode* pPack) {return true;}
	//清空
	virtual void clear(){}
	//树是否可用
	virtual bool isValid() = 0;
};

typedef IUpdateXmlPlistNode IUpdatePack;
typedef std::map<XString, IUpdatePack*> TMapReadyPacks;
typedef std::pair<XString, IUpdatePack*> TPairReadyPack;
typedef TMapReadyPacks::iterator TIterMapReadyPack;
typedef TMapReadyPacks::const_iterator TCIterMapReadyPack;

#endif