#ifndef BOOSTTIME_H
#define BOOSTTIME_H

#include <QtWidgets/QWidget>
#include "ui_boosttime.h"

class boostTime : public QWidget
{
	Q_OBJECT

public:
	boostTime(QWidget *parent = 0);
	~boostTime();
	   void FunctionCostTime();
private:
	Ui::boostTimeClass ui;
};

#endif // BOOSTTIME_H
