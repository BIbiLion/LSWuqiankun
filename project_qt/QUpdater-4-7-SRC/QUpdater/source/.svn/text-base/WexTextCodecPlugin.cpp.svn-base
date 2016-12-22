#include "WexTextCodecPlugin.h"
#include <QtCore/QtPlugin>
#include <WPlugins/Textcodec>

WTextCodecPlugin::WTextCodecPlugin(QObject* parent)
: QTextCodecPlugin(parent)
{

}

WTextCodecPlugin::~WTextCodecPlugin()
{

}

QList<QByteArray> WTextCodecPlugin::names() const
{
	return QList<QByteArray>() << QGbkCodec::_name() << QGb18030Codec::_name() << QGb2312Codec::_name();
}

QTextCodec* WTextCodecPlugin::createForName( const QByteArray & name )
{
	if (name == QGbkCodec::_name())
		return new QGbkCodec();
	else if (name == QGb18030Codec::_name())
		return new QGb18030Codec();
	else if (name == QGb2312Codec::_name())
		return new QGb2312Codec();
	
	return 0;
}

QList<QByteArray> WTextCodecPlugin::aliases() const
{
	return QList<QByteArray>() << QGbkCodec::_aliases() << QGb18030Codec::_aliases() << QGb2312Codec::_aliases();
}

QList<int> WTextCodecPlugin::mibEnums() const
{
	return QList<int>() << QGbkCodec::_mibEnum() << QGb18030Codec::_mibEnum() << QGb2312Codec::_mibEnum();
}

QTextCodec* WTextCodecPlugin::createForMib( int mib )
{
	if (mib == QGbkCodec::_mibEnum() )
		return new QGbkCodec();
	else if ( mib == QGb18030Codec::_mibEnum() )
		return new QGb18030Codec();
	else if ( mib == QGb2312Codec::_mibEnum() )
		return new QGb2312Codec();

	return 0;
}