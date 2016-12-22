/****************************************************************************
**
** Copyright (C) 2007-2007 Trolltech ASA. All rights reserved.
**
** This file is part of the example classes of the Qt Toolkit.
**
** Licensees holding a valid Qt License Agreement may use this file in
** accordance with the rights, responsibilities and obligations
** contained therein.  Please consult your licensing agreement or
** contact sales@trolltech.com if any conditions of this licensing
** agreement are not clear to you.
**
** Further information about Qt licensing is available at:
** http://www.trolltech.com/products/qt/licensing.html or by
** contacting info@trolltech.com.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#include <QtGui>
#include <QtGui/QMessageBox>
#include <QTextCodec>

#include "mainwindow.h"

int main(int argv, char *args[])
{
   
    QApplication app(argv, args);

	QTextCodec *locale_codec = QTextCodec::codecForLocale();
	if (!locale_codec) {
		QMessageBox::critical(0, "����ʧ��", "ȡ���ر�������ʧ��");
		return false;
	}

	QTextCodec::setCodecForCStrings (locale_codec);
	QTextCodec::setCodecForTr (locale_codec);
    MainWindow mainWindow;
    mainWindow.setGeometry(100, 100, 800, 500);
    mainWindow.show();

    return app.exec();
}
