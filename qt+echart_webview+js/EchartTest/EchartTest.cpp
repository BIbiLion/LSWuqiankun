
#include <QWebElement>
#include <QWebFrame>

#include "EChartTest.h"
#include "mainwindow.h"

EChartTest::EChartTest(QObject* parent)
    : QObject(parent)
{
	m_nBaseData = 0;

}

EChartTest::~EChartTest()
{
}

QStringList EChartTest::GetMaxValue()
{
	QTime t = QTime::currentTime();
	QStringList lst;
	for (int i = 0; i < 7; i++)
	{
		lst << QString::number(m_nBaseData + + 30 + i%4*10 );
	}
	return lst;
}

QStringList EChartTest::GetMinValue()
{
	QTime t = QTime::currentTime();
	QStringList lst;
	for (int i = 0; i < 7; i++)
	{
		lst << QString::number(m_nBaseData + i % 3 * 10);
	}
	return lst;
}

void EChartTest::submit()
{
	MainWin * widget = (MainWin*)qApp->focusWidget();
	if (!widget)	return;

	QWebFrame *frame = widget->page()->mainFrame();
	QWebElement firstName = frame->findFirstElement("#basedata");
	m_nBaseData = firstName.evaluateJavaScript("this.value").toInt();
	widget->reload();
}
