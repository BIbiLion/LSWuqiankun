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
    connect(m_timer,SIGNAL(timeout()),this,SLOT(resetPlot()));
    m_timer->start(1000);
    m_count=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupPlot()
{
    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(Qt::blue));
    ui->plot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    QVector<double> x(250), y0(250), y1(250);
    for (int i=0; i<250; ++i)
    {
        x[i] = i;
        y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
        y1[i] = qExp(-i/150.0); // exponential envelope
    }

    connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->plot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->plot->yAxis2, SLOT(setRange(QCPRange)));


    ui->plot->xAxis2->setVisible(true);
    ui->plot->xAxis2->setTickLabels(true);
    ui->plot->yAxis2->setVisible(true);
    ui->plot->yAxis2->setTickLabels(false);
    ui->plot->graph(0)->setData(x, y0);

     ui->plot->graph(0)->rescaleAxes();
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}
void MainWindow::resetPlot()
{
    QVector<double> x(250), y0(250), y1(250);
    for (int i=0; i<250; ++i)
    {
        x[i] = i;
        y0[i] = qExp(-i/150.0+m_count*0.02)*qCos(i/10.0*m_count*0.03); // exponentially decaying cosine
        y1[i] = qExp(-i/150.0-m_count*0.004); // exponential envelope
    }
    ui->plot->graph(0)->setData(x, y0);

     ui->plot->graph()->setLineStyle( QCPGraph::lsImpulse );
    m_count++;
    ui->plot->replot();

}
