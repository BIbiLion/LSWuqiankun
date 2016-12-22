#include "testwidget.h"
TestWidget::TestWidget()
{


    battery=new QBattery(this);
    mainLayout=new QVBoxLayout();

    mainLayout->addWidget(battery);
    bottomLayout=new QHBoxLayout();
    numSpin=new QLabel(this);
    //numSpin->setRange(0,100);
    fireBtn=new QPushButton(tr("Fire"),this);
    bottomLayout->addWidget(numSpin);
    bottomLayout->addWidget(fireBtn);
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);

    updateTimer=new QTimer(this);
    updateTimer->setInterval(500);

    connect(updateTimer,SIGNAL(timeout()),this,SLOT(UpdateValue()));
    updateTimer->start();
    connect(fireBtn,SIGNAL(clicked()),this,SLOT(UpdateValue()));
    connect(battery,SIGNAL(valueChanged(qreal)),this,SLOT(SetValue(qreal)));




}

void TestWidget::UpdateValue()
{
    battery->setValue(qrand()%50);
}
void TestWidget::SetValue(qreal value)
{
    numSpin->setText(tr("%1").arg(value));
}
