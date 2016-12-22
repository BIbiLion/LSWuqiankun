#ifndef ABOUTDLG_H
#define ABOUTDLG_H

#include <QDialog>
#include "ui_aboutdlg.h"

class QMouseEvent;
class AboutDlg : public QDialog
{
	Q_OBJECT

public:
	AboutDlg(QWidget *parent = 0);
	~AboutDlg();

protected:
	virtual void mousePressEvent ( QMouseEvent * pevent ) ;

private:
	Ui::AboutDlgClass ui;
};

#endif // ABOUTDLG_H
