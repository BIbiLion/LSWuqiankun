#include <QtCore>
#include <QtGui>
#include "TrayWindow.h"
#include "pubfuncs.h"
#include "IClientCenter.h"

wTrayWindow::wTrayWindow(QWidget *parent, Qt::WFlags flags)
: QMainWindow(parent, flags),
trayIcon(0),
trayMenu(0),
minAction(0),
maxAction(0),
restoreAction(0),
closeAction(0)
{
	
}

wTrayWindow::~wTrayWindow()
{
	pubfunc::release(trayIcon);
	pubfunc::release(trayMenu);
	pubfunc::release(minAction);
	pubfunc::release(maxAction);
	pubfunc::release(restoreAction);
	pubfunc::release(closeAction);
}

wTrayWindowParam::wTrayWindowParam()
: containDefault(true)
{
	
}


void wTrayWindow::createTrayIcon(const wTrayWindowParam& param)
{
	if (!IsNull(trayIcon) && !IsNull(trayMenu))
		return;

	trayIcon = new QSystemTrayIcon(this);
	trayMenu = new QMenu(this);

	//初始化时间记录器
	getClientCenter()->pTrayIcon = trayIcon;
	getClientCenter()->logs.clear();

	//设置菜单
	//遍历菜单项目
	std::list<QAction*>::const_iterator iterAction = param.menuActions.begin();
	while (iterAction != param.menuActions.end())
	{
		QAction* pAction = *iterAction;
		if (IsNull(pAction))
		{
			trayMenu->addSeparator();
		}
		else
			trayMenu->addAction(pAction);

		++iterAction;
	}

	//是否含有默认的项目
	if (param.containDefault)
	{
		pubfunc::release(minAction);
		pubfunc::release(maxAction);
		pubfunc::release(restoreAction);
		pubfunc::release(closeAction);

		minAction = new QAction(tr("minimize"), this);
		maxAction = new QAction(tr("maximize"), this);
		restoreAction = new QAction(tr("restore"), this);
		closeAction = new QAction(tr("quit"), this);
		connect(minAction, SIGNAL(triggered()), this, SLOT(hide()));
		connect(maxAction, SIGNAL(triggered()), this, SLOT(showMaximized()));
		connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
		connect(closeAction, SIGNAL(triggered()), this, SLOT(on_proxyClose()));

		trayMenu->addAction(minAction);
		trayMenu->addAction(maxAction);
		trayMenu->addAction(restoreAction);
		trayMenu->addAction(closeAction);
	}

	connect(trayIcon, SIGNAL(activated ( QSystemTrayIcon::ActivationReason)),
		this, SLOT(on_TrayMsgActivated(QSystemTrayIcon::ActivationReason)));

	trayIcon->setIcon(param.icon);//设置显示图标
	trayIcon->setContextMenu(trayMenu);

	QMetaObject::invokeMethod(trayIcon, "show");//显示状态栏
}

void wTrayWindow::showTrayMessage(const QString & title, const QString & message, QSystemTrayIcon::MessageIcon icon /* = Information */, int millisecondsTimeoutHint /* = 10000 */)
{
	if (IsNull(trayIcon))
		return;

	if (!QSystemTrayIcon::supportsMessages())
		return;

	trayIcon->showMessage(title, message, icon, millisecondsTimeoutHint);
}

void wTrayWindow::on_TrayMsgActivated(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
	case QSystemTrayIcon::Trigger:
		{
			showLogs();
		}
	case QSystemTrayIcon::DoubleClick:
		{
			if (this->isHidden())
			{
				this->show();
			}
		}
		this->setWindowState(Qt::WindowActive);
		break;
	}
}