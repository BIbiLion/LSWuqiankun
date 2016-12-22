#ifndef __COMMONFILEOPERFUNCTION_H_INCLUDED
#define __COMMONFILEOPERFUNCTION_H_INCLUDED

#include <QtCore/QFile>
#include  "md5.h"
#include <fstream>

struct wFileFunc
{
	//计算一个文件的md5编码
	static QString calcFileMd5(const QString& filename)
	{
		QString re("md5 calc error");
		QFile xfile(filename);
		
		if (!xfile.open(QIODevice::ReadOnly))
			return QString("error open file");

		MD5 md5calcer;
		md5calcer.update(xfile);

		re = md5calcer.toString();

		re = re.toLower();

		return re;
	}
};

#endif