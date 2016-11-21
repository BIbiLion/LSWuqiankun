#include "meterwidget.h"

#include <QTimer>
#define OFFsetDistance (6)
MeterWidget::MeterWidget(double startAngle,double endAngle,QWidget *parent) :
    QWidget(parent),m_startAngle(startAngle),m_endAngle(endAngle),m_meterPointer(NULL)
{
    this->setFixedSize(400,400);
     //this->setAttribute(Qt::WA_TranslucentBackground, true);
     InitMeterWidget();


     QTimer * _timer= new QTimer(this);
     connect(_timer,SIGNAL(timeout()),SLOT(test_setValue()));
     _timer->start(1000);
     m_value=m_startAngle;

     // connect(m_chartView, SIGNAL(viewPortChanged()), SLOT(InitMeterWidget()));
}


void MeterWidget::test_setValue()
{
//    if(( (m_value+=5) > m_endAngle) )
//    {
//        m_value=m_startAngle;
//    }
    setMetreValue(m_value+=15);
     //m_angularMeter->addPointer(m_value,0xff0000);
}
 MeterWidget:: ~MeterWidget()
{

}

 //初始化角表
 void MeterWidget::InitMeterWidget()
 {
     m_angularMeter= new AngularMeter(this->width(),this->height());//,Chart::Transparent);
     m_angularMeter->setMeter(this->width()/2,this->height()/2,this->width()/2-OFFsetDistance,m_startAngle,m_endAngle);

     m_angularMeter->setScale(0,360,15,5,1);


     m_meterPointer= m_angularMeter->addPointer(m_value,0xff0000);
     m_chartView= new QChartViewer(this);
     m_chartView->setChart(m_angularMeter);
     m_chartView->show();

 }

#include<QDebug>
 //设置角表的指针值
 void MeterWidget::setMetreValue(double Value)
 {
     /*
   if(m_meterPointer != NULL)
   {
       delete m_meterPointer;
   }
   qDebug()<<Value;
   m_meterPointer= m_angularMeter->addPointer(Value,0xff0000);
   m_chartView->show();

  m_chartView->updateViewPort(true,true);
*/
   if(m_angularMeter !=NULL)
   {
      delete m_angularMeter;
      // m_angularMeter=NULL;
   }

   qDebug()<<m_value;
   InitMeterWidget();
   //m_chartView->updateViewPort(true,true);
}
