#include "xylinewidget.h"
#include<QTimer>
#include <string.h>
#include <math.h>
#include <QTextCodec>
#include <QDebug>
static const int DataInterval = 250;

XYLineWidget::XYLineWidget(QWidget *parent) :
    QWidget(parent),m_xyChart(NULL),m_chartView(NULL)
{
    this->setFixedSize(900,900);
    for (int i=0;i < sampleSizeW;i++)
    {
       dataArray[i]=Chart::NoValue;
    }
    m_dateTime=QDateTime::currentDateTime();
   m_chartView = new QChartViewer(this);

  QTimer * _tt= new QTimer(this);
  connect(_tt,SIGNAL(timeout()),SLOT(dateSave()));
  _tt->start(200);

   QTimer * _time= new QTimer(this);
   connect(_time,SIGNAL(timeout()),SLOT(draw()));
   _time->start(200);
}

  XYLineWidget:: ~XYLineWidget()
{
  if(m_chartView != NULL)
  {
      delete m_chartView;
      m_chartView=NULL;
  }

  if(m_xyChart != NULL)
  {
      delete m_xyChart;
      m_xyChart=NULL;
  }
}

#include <stdio.h>
#include <stdlib.h>

void  XYLineWidget::dateSave()
{
    // The current time
    QDateTime now = QDateTime::currentDateTime();

    // This is our formula for the random number generator
    do
    {
        // We need the currentTime in millisecond resolution
        double currentTime = Chart::chartTime2(m_dateTime.toTime_t())
                             + m_dateTime.time().msec() / 1000.0;

        // Get a data sample
        double p = currentTime * 4;
        srand(currentTime);
        double dataA = 20+cos(rand()%180);

qDebug()<<dataA;

        // Shift the values into the arrays
       // shiftData(dataArray, sampleSize, dataA);
        memmove(dataArray, dataArray + 1, sizeof(*dataArray) * (sampleSizeW - 1));
        dataArray[sampleSizeW - 1] = dataA;

        //shiftData(m_timeStamps, sampleSize, currentTime);
        memmove(m_timeStamps, m_timeStamps + 1, sizeof(*m_timeStamps) * (sampleSizeW - 1));
        m_timeStamps[sampleSizeW - 1] = currentTime;

        m_dateTime = m_dateTime.addMSecs(DataInterval);
    }
    while (m_dateTime < now);
}

void XYLineWidget::draw()
{
    if(m_xyChart !=NULL)
    {
        delete m_xyChart;
    }


   m_xyChart= new XYChart(this->width(),this->height());
     m_xyChart->setDefaultFonts("simsun.ttc");//设置中文

   m_xyChart->addTitle(QTextCodec::codecForName("UTF-8")->fromUnicode("经度").constData(), "simsun.ttc", 18);
   //设置xychart
   m_xyChart->setPlotArea(60,60,this->width()-80,this->height()-80);

   m_xyChart->xAxis()->setTickDensity(75,15);
  m_xyChart->setClipping();// Set clipping mode to clip the data lines to the plot area.
   //add Legend
   LegendBox* _legendBox= m_xyChart->addLegend(60,60,true);

   //add Data
   double lastTime= m_timeStamps[sampleSizeW - 1];
    if(lastTime != Chart::NoValue)
   {
        //设置刻度范围
        m_xyChart->xAxis()->setDateScale(lastTime - 100 * sampleSizeW / 1000, lastTime);

      //  m_xyChart->xAxis()->setDateScale(m_timeStamps[0],lastTime);
       m_xyChart->yAxis()->setDateScale(0,30);
        m_xyChart->xAxis()->setLabelFormat("{value|hh:nn:ss}");
        LineLayer *layer = m_xyChart->addLineLayer();
        layer->setXData(DoubleArray(m_timeStamps, sampleSizeW));

        // as part of the data set name, so you can see them updated in the legend box.
        char buffer[1024];

        sprintf(buffer, "经度: <*bgColor=FFCCCC*> %.2f ", m_timeStamps[sampleSizeW - 1]);
       //   sprintf(buffer, "%s: <*bgColor=FFCCCC*> ",QTextCodec::codecForName("UTF-8")->fromUnicode("经度").constData());

     DataSet* _dateSet=   layer->addDataSet(DoubleArray(dataArray, sampleSizeW), 0xff0000, buffer);
    // _dateSet->setDataSymbol(Chart::DiamondSymbol,12);//point's symbol
   //  layer->setDataLabelFormat("{value|0}%");
       // layer->set3D();//3D的形势显示


     //平滑的曲线
    // SplineLayer *_splineLayer= m_xyChart->addSplineLayer();

     //阶梯线 i步线
     //StepLineLayer * _stepLineLayer= m_xyChart->addStepLineLayer();

     //线的相交区域
     //In ChartDirector, an InterLineLayer can be used to fill the region between any two lines.
     //The lines can be from a LineLayer, StepLineLayer, SplineLayer, TrendLayer, or from an axis Mark.
     //Two colors can be used for filling, depending on which line is on top.

     // Color the region between the above spline curve and normal line. Use the semi-transparent red
     // (80ff000000) if the spline curve is higher than the normal line, otherwise use
     // semi-transparent green (80008800)
     //m_xyChart->addInterLineLayer(layer->getLine(), layer1->getLine(), 0x80ff0000, 0x80008800);

   //eg
     Mark * _mark= m_xyChart->yAxis()->addMark(20,-1);
     _mark->setWidth(10);
     _mark->setAlignment(Chart::Left);
     _mark->setBackground(0x880088);
     m_xyChart->addInterLineLayer(_mark->getLine(),layer->getLine(),0xff8ff8ff,0x0000ffaa);


   }


  m_chartView->setChart(m_xyChart);

}
