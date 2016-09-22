#include "testcom_dial_thermo.h"
#include "ui_testcom_dial_thermo.h"

testCom_dial_thermo::testCom_dial_thermo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testCom_dial_thermo)
{
    ui->setupUi(this);
    ui->widget ->setValue(90);
    ui->widget->setScalePosition(QwtThermo::LeadingScale);
    ui->widget->show();


}

testCom_dial_thermo::~testCom_dial_thermo()
{
    delete ui;
}
