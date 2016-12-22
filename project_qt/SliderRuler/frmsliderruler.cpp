#include "frmsliderruler.h"
#include "ui_frmsliderruler.h"
#include "qtimer.h"

#include <QDebug>
frmSliderRuler::frmSliderRuler(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::frmSliderRuler)
{
	ui->setupUi(this);
	this->initForm();
    qDebug()<<__FILE__<<__LINE__<<__FUNCTION__;
}

frmSliderRuler::~frmSliderRuler()
{
	delete ui;
}

void frmSliderRuler::initForm()
{
	ui->widget2->setRange(0, 50);
	ui->widget2->setStep(10, 2);
	ui->widget2->setPrecision(1);

	ui->widget3->setRange(0, 200);
	ui->widget3->setStep(20, 5);

	ui->widget2->setSliderColor(QColor(204, 0, 0), QColor(254, 48, 48));
	ui->widget3->setSliderColor(QColor(1, 139, 0), QColor(101, 205, 107));

    QTimer::singleShot(0, this, SLOT(setValue()));

	//connect(ui->widget1, SIGNAL(valueChanged(double)), ui->widget2, SLOT(setValue(double)));
	//connect(ui->widget2, SIGNAL(valueChanged(double)), ui->widget1, SLOT(setValue(double)));
}

void frmSliderRuler::setValue()
{
	ui->widget1->setValue(15);
	ui->widget2->setValue(45);
	ui->widget3->setValue(80);
}
