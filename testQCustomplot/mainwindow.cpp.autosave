#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupPlot();
    QTimer *  m_timer= new QTimer(this);
    //connect(m_timer,SIGNAL(timeout()),this,SLOT(resetPlot()));
    connect(m_timer,SIGNAL(timeout()),this,SLOT(resetMoveXaxisPlot()));
    m_timer->start(0);
    m_count=0;
    QStringList _fileNameList;
    _fileNameList<<"customplotData";
    m_writeFile=new QWriteFile(QCoreApplication::applicationDirPath(),_fileNameList,this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupPlot()
{
    //标题
    ui->plot->plotLayout()->insertRow(0);
    ui->plot->plotLayout()->addElement(0,0,new QCPPlotTitle(ui->plot, "testCustomplot Example"));
    //ui->plot->plotLayout()->insertRow(0);
    //ui->plot->plotLayout()->addElement(0,0,new QCPPlotTitle(ui->plot, "he Example"));

    //图例
    ui->plot->legend->setVisible(true);




    //画图
    ui->plot->addGraph();
    ui->plot->graph()->setName("ttt");//这个和图例的 文本是关联的
    ui->plot->graph(0)->setPen(QPen(Qt::blue));
       ui->plot->graph(0)->setAntialiasedFill(false);
    //ui->plot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    QVector<double> x(250), y0(250), y1(250);
    for (int i=0; i<250; ++i)
    {

        x[i] = i+10;

        y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
        y1[i] = qExp(-i/150.0); // exponential envelope
    }
    m_x=x;
    m_y=y0;

    connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->plot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->yAxis2, SLOT(setRange(QCPRange)));


    ui->plot->xAxis2->setVisible(true);
    ui->plot->xAxis2->setTickLabels(true);
    ui->plot->yAxis2->setVisible(true);
    ui->plot->yAxis2->setTickLabels(false);
    ui->plot->graph(0)->setData(x, y0);

    ui->plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    ui->plot->xAxis->setDateTimeFormat("hh:mm:ss");
    ui->plot->xAxis->setAutoTickStep(false);
    ui->plot->xAxis->setTickStep(2);
    ui->plot->axisRect()->setupFullAxesBox();


    ui->plot->graph(0)->rescaleAxes();
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);



/*
    //画柱状图
    QCPBars * _bar= new QCPBars(ui->plot->xAxis,ui->plot->yAxis);
    _bar->setName("bars");
    this->ui->plot->addPlottable(_bar);

    QVector<QString> labels(5);
    QVector<double> values(5);
    for(int i=0;i<5;++i)
        labels[i]=QString("MAC")+('0'+i);
    values[0]=(10.05);
    values[1]=23;
    values[2]=12;
    values[3]=19.3;
    values[4]=20;

    QVector<double> index(5);
    for(int i=0;i<5;++i)
        index[i]=i;
    _bar->setData(index,values);


    this->ui->plot->xAxis->setAutoTicks(false);
    this->ui->plot->xAxis->setAutoTickLabels(false);
    this->ui->plot->xAxis->setAutoTickStep(false);
    this->ui->plot->rescaleAxes();

    double wid=this->ui->plot->xAxis->range().upper-this->ui->plot->xAxis->range().lower;
    double cl=_bar->width()+(1.0*wid-_bar->width()*5)/4;

    QVector<double> coor;
    for(int i=0;i<5;++i)
        coor.append(this->ui->plot->xAxis->range().lower+i*cl+_bar->width()/2);
    this->ui->plot->xAxis->setTickVector(coor);
    this->ui->plot->xAxis->setTickVectorLabels(labels);


    //画同一x点，有两个y值的 线
    QCPCurve * _cure= new QCPCurve(ui->plot->xAxis,ui->plot->yAxis);
    _cure->setName("cure");
    ui->plot->addPlottable(_cure);

    */
}



/*
函数名：移动的方法有两种：
1. 就是 坐标轴移动
2. 坐标点移动，但是如果想象的 图形发生变化，那就x坐标不发生变换，y轴发生变换
*/
void MainWindow::resetPlot()
{
    /*
    QVector<double> x(250), y0(250), y1(250);
    for (int i=0; i<250; ++i)
    {
        x[i] = i;
        y0[i] = qExp(-i/150.0+m_count*0.02)*qCos(i/10.0*m_count*0.03); // exponentially decaying cosine
        y1[i] = qExp(-i/150.0-m_count*0.004); // exponential envelope
    }
    ui->plot->graph(0)->setData(x, y0);
    m_count++;
      ui->plot->replot();
    */

    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    //for(int i=0;i<100;++i)
    {
//        double start_xD=m_x[0];
//        m_x.pop_front();

//        m_x.push_back(start_xD);

        double start_yD=m_y[0];
        m_y.pop_front();
        m_y.push_back(start_yD);
       // qDebug()<<m_x.count()<<start_xD<<start_yD;
    }




    //ui->plot->graph(0)->clearData();
    ui->plot->graph(0)->setData(m_x, m_y);
    qDebug()<<"ooooooo---"<<ui->plot->graph(0)->data()->count();
   // ui->plot->graph(0)->rescaleValueAxis(true);

    // ui->plot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);

    ui->plot->replot();

}

 void MainWindow::resetMoveXaxisPlot()
 {
       double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
       static double lastPointKey = 0;
       if (key-lastPointKey > 0.01) // at most add point every 10 ms
       {
         double value0 = qSin(key); //qSin(key*1.6+qCos(key*1.7)*2)*10 + qSin(key*1.2+0.56)*20 + 26;
         double value1 = qCos(key); //qSin(key*1.3+qCos(key*1.2)*1.2)*7 + qSin(key*0.9+0.26)*24 + 26;
         // add data to lines:
         ui->plot->graph(0)->addData(key, value0);

         ui->plot->graph(0)->removeDataBefore(key-8);

         // rescale value (vertical) axis to fit the current data:
         ui->plot->graph(0)->rescaleValueAxis();

         lastPointKey = key;
       }
       // make kexisy a range scroll with the data (at a constant range size of 8):
       ui->plot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
       ui->plot->replot();

       // calculate frames per second:
       static double lastFpsKey;
       static int frameCount;
       ++frameCount;
       if (key-lastFpsKey > 2) // average fps over 2 seconds
       {
         ui->statusBar->showMessage(
               QString("%1 FPS, Total Data points: %2")
               .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
               .arg(ui->plot->graph(0)->data()->count()+ui->plot->graph(0)->data()->count())
               , 0);
         lastFpsKey = key;
         frameCount = 0;
       }

       m_writeFile->writeFile(0,QString("%1").arg(frameCount));
 }
