#include "mainwindow.h"
#include "EChartTest.h"

#include <QWebFrame>
#include <QWebElementCollection>
#include <QNetworkDiskCache>

MainWin::MainWin(QWidget * parent) : QWebView(parent)
{
    //! The object we will expose to JavaScript engine:
	m_analyzer = new EChartTest(this);

    // Signal is emitted before frame loads any web content:
    QObject::connect(page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
                     this, SLOT(addJSObject()));


	load(QUrl::fromLocalFile(qApp->applicationDirPath() + "/html/index.html"));
}
void MainWin::addJSObject() 
{
    page()->mainFrame()->addToJavaScriptWindowObject(QString("echarttest"), m_analyzer);
}
