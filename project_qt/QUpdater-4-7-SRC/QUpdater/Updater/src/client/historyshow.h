#ifndef HISTORYSHOW_H
#define HISTORYSHOW_H

#include <QDialog>
#include "ui_historyshow.h"

class HistoryShow : public QDialog
{
	Q_OBJECT

public:
	HistoryShow(QWidget *parent = 0);
	~HistoryShow();

private:
	Ui::HistoryShowClass ui;
};

#endif // HISTORYSHOW_H
