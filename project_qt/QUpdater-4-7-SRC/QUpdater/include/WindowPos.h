#ifndef __WINDOWPOS_H_INCLUDED
#define __WINDOWPOS_H_INCLUDED

#include <QtGui/QWidget>
#include <QtGui/QDesktopWidget>
#include <QtGui/QApplication>

//调整对话框位置的类

class wWindowPos 
{
public:
	enum enumWindowPos
	{
		WWP_CENTER = 0,
		WWP_LEFTTOP,
		WWP_RIGHTTOP,
		WWP_LEFTBOTTOM,
		WWP_RIGHTBOTTOM,
		WWP_MANUAL,//手动调整
	};

public:
	//欲调整的对话框、宽度、高度、调整类型、手动模式下的位置
	wWindowPos(QWidget* pthis, int width, int heigth, enumWindowPos ewp = WWP_CENTER, const QPoint& manualpos = QPoint(0, 0))
	{
		int clientWidth = width;
		int clientHeigth = heigth;

		QDesktopWidget* pdesktop = QApplication::desktop();
		int desktopWidth = pdesktop->width();
		int desktopHeight = pdesktop->height();

		QPoint windowPt(0, 0);
		//计算偏移量
		switch (ewp)
		{
		case WWP_CENTER:
			windowPt.setX( (desktopWidth - clientWidth) * .5f);
			windowPt.setY( (desktopHeight - clientHeigth) * .5f);
			break;
		case WWP_LEFTTOP:
			break;
		case WWP_RIGHTTOP:
			windowPt.setX( desktopWidth - clientWidth);
			break;
		case WWP_LEFTBOTTOM:
			windowPt.setY( desktopHeight - clientHeigth);
			break;
		case WWP_RIGHTBOTTOM:
			windowPt.setX( desktopWidth - clientWidth);
			windowPt.setY( desktopHeight - clientHeigth);
			break;
		case WWP_MANUAL:
			windowPt = manualpos;
			break;
		}

		//偏移
		pthis->move(windowPt);
	}

private:
	wWindowPos(){}
};

#endif