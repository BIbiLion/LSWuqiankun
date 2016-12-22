#ifndef __TRAYWINDOW_H_INCLUDED
#define __TRAYWINDOW_H_INCLUDED

#include <QtGui/QMainWindow>
#include <QtGui/QIcon>
#include <list>

//! 任务栏对话框的实现

class QAction;
struct wTrayWindowParam
{
	wTrayWindowParam();

	QIcon icon;//图标

	bool containDefault;//含有默认的菜单项目
	std::list<QAction*> menuActions;//菜单上的项目，null显示为分隔条
};

/*
初始状态，默认含有三个菜单项目：最大化、最小化、还原
*/
//class QSystemTrayIcon;
#include <QtGui/QSystemTrayIcon>
class QMenu;
class wTrayWindow : public QMainWindow
{
	Q_OBJECT

public:
	wTrayWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	virtual ~wTrayWindow();

protected:
	void createTrayIcon(const wTrayWindowParam& param);

	void showTrayMessage(const QString & title, const QString & message, QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int millisecondsTimeoutHint = 10000);

	virtual void showLogs(){}

private slots:

	void on_TrayMsgActivated ( QSystemTrayIcon::ActivationReason reason );

private:
	QSystemTrayIcon* trayIcon;
	QMenu* trayMenu;

	//actions
protected:
	QAction* minAction;
	QAction* maxAction;
	QAction* restoreAction;
	QAction* closeAction;
};

#endif