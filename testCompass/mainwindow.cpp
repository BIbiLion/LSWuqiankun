#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mythermo.h"
#include <QTimer>
#include "testcom_dial_thermo.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCompass();
    //ui->Dial->hide();
    //setDial();
    ui->Slider->setValue(20.0);
    ui->Thermo->setValue(20.0);

   mm = new myThermo;
    mm->setValue(45);
    mm->setScalePosition(QwtThermo::LeadingScale);
    mm->setFixedSize(30,500);
    mm->show();
    QTimer * tt= new QTimer;
    connect(tt,SIGNAL(timeout()),this,SLOT(changgeValue()));
    m_value=0;
    tt->start(1000);




    testCom_dial_thermo * tdt= new testCom_dial_thermo;
    tdt->setBaseSize(600,600);
    tdt->show();

}


void MainWindow::changgeValue()
{
    ++m_value;
    if((m_value>100)||(m_value<0) )
    {
        m_value=0;
    }
    mm->setValue(m_value);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
函数名：
*/
#include <qwt_compass.h>

void MainWindow::setCompass()
{
    //    QPalette p = palette();
    //    p.setColor( backgroundRole(), Qt::gray );
    //    setPalette( p );
    //   setAutoFillBackground( true );

    //设置刻度
    QMap<double, QString> map;
    for ( double d = 0.0; d < 360.0; d += 60.0 )
    {
        QString label;
        label.sprintf( "%.0f", d );
        map.insert( d, label );
    }
    QwtCompassScaleDraw * scaleDraw=new QwtCompassScaleDraw(map);
    //scaleDraw->enableComponent( QwtAbstractScaleDraw::Ticks, true );
    scaleDraw->setTickLength( QwtScaleDiv::MinorTick, 0 );
    scaleDraw->setTickLength( QwtScaleDiv::MediumTick, 0 );
    scaleDraw->setTickLength( QwtScaleDiv::MajorTick,30 );

    ui->Compass->setScaleMaxMajor( 36 );//大刻度 36 个  时钟的时 刻度
    ui->Compass->setScaleMaxMinor( 5 );//小刻度 5个  简单说：时钟的分 刻度
    // ui->Compass->setScaleStepSize(1);

    ui->Compass->setScaleDraw( scaleDraw );
    ui->Compass->setMode(QwtCompass::RotateScale);

    //设置指针
    //ui->Compass->setNeedle( new QwtCompassMagnetNeedle( QwtCompassMagnetNeedle::ThinStyle ) );
}

/*
函数名：Dial
*/
void MainWindow::setDial()
{

}

