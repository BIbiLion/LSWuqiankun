
#include <QtCore>
#include <QMouseEvent>
#include "aboutdlg.h"

AboutDlg::AboutDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	//设置对话框样式
	this->setWindowFlags(Qt::FramelessWindowHint);

}

AboutDlg::~AboutDlg()
{

}

void AboutDlg::mousePressEvent( QMouseEvent * pevent )
{
	if (pevent->button() == Qt::LeftButton)
		this->close();
}