#ifndef __WEX_TEXTCODECPLUGIN_H_INCLUDED
#define __WEX_TEXTCODECPLUGIN_H_INCLUDED

#include <QtCore/QTextCodecPlugin>
#include <QtCore/QList>

class WTextCodecPlugin : public QTextCodecPlugin
{
	Q_OBJECT

public:
	WTextCodecPlugin(QObject* parent = 0);
	virtual ~WTextCodecPlugin();

public:

	virtual QList<QByteArray> names () const;

	virtual QTextCodec * createForName ( const QByteArray & name );

	virtual QList<int> mibEnums () const;

	virtual QTextCodec * createForMib ( int mib );

	virtual QList<QByteArray> aliases () const;
};

static WTextCodecPlugin __g_w_textcodeplugin;

static QTextCodec* WGetTextCodeForName(const QByteArray & name)
{
	return __g_w_textcodeplugin.createForName(name);
}

typedef WTextCodecPlugin WexTextCodecPlugin;

#endif