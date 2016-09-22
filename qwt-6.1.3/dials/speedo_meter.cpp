#include <qpainter.h>
#include <qwt_dial_needle.h>
#include <qwt_round_scale_draw.h>
#include "speedo_meter.h"
#include <math.h>
#include <qwt_point_polar.h>


IndiacatorNeedle::IndiacatorNeedle()
{
}

IndiacatorNeedle::IndiacatorNeedle(const QColor & color)
{
    QPalette palette;
    palette.setColor( QPalette::Text, color );
    setPalette( palette );
}
 void IndiacatorNeedle::setInsiderCirAngle(double & angle)
 {
      m_angle=angle;
 }

void  IndiacatorNeedle::setCenterAndRadiu(const QPointF & center,const double & radius, const double & angle)
{
    m_center.setX(center.x());
    m_center.setY(center.y());
    m_radius=radius;
    m_angle=angle;
}

//指南针的指针  length是指针的长度
void IndiacatorNeedle::drawNeedle( QPainter *painter,  double length, QPalette::ColorGroup colorGroup ) const
{
    qDebug()<<"enter";
    /*
         QPainterPath path;
         path.moveTo( 0, length*0.5 );//
         path.lineTo( length*0.8, 2 );
         path.lineTo( length*0.8, -2);
         path.closeSubpath();
         painter->setBrush( palette().brush( colorGroup, QPalette::Text ) );
         painter->drawPath( path );
*/


    double triangleSize = length * 0.1;
    double pos = length - 2.0;

    QPainterPath path;
    path.moveTo( pos, 0 );
    path.lineTo( pos - 5* triangleSize, triangleSize );
    path.lineTo( pos -  5* triangleSize, -triangleSize );
    path.closeSubpath();

    //qDebug()<<"长度："<<length<<"...."<<pos << triangleSize;
    painter->setBrush( palette().brush( colorGroup, QPalette::Text ) );
    painter->drawPath( path );


    //传入点就好   画线 length？？？


//    double _disOffsent=(m_radius*cos(30*M_PI/180.0))/90.0;


//    QPointF _pStartNeedle;
//    QPointF _pendNeedle;

//    _pStartNeedle.setX(m_center.x()-m_center.x()/3);
//    _pendNeedle.setX(m_center.x()-m_center.x()/5);

//    _pStartNeedle.setY(m_center.y()+m_angle*_disOffsent);
//    _pendNeedle.setY(m_center.y()+m_angle*_disOffsent);
//    painter->setPen(QColor(Qt::red));
//    painter->drawLine(m_center,_pendNeedle);


}




/***************华丽丽的分割线*********************/
SpeedoMeter::SpeedoMeter( QWidget *parent ):
    QwtDial( parent ),
    d_label( "km/h" )
{
    QwtRoundScaleDraw *scaleDraw = new QwtRoundScaleDraw();
    scaleDraw->setSpacing( 8 );
    scaleDraw->enableComponent( QwtAbstractScaleDraw::Backbone, false );
    scaleDraw->enableComponent( QwtAbstractScaleDraw::Ticks, false );
    scaleDraw->setTickLength( QwtScaleDiv::MinorTick,0.0 );
    scaleDraw->setTickLength( QwtScaleDiv::MediumTick, 0.0 );
    scaleDraw->setTickLength( QwtScaleDiv::MajorTick, 0.0 );


    setWrapping( false );
    setReadOnly( true );

    //画刻度线
    setOrigin( 90.0 );//开始起点；  默认的时候0.0，水平方向
    setScaleArc( 0.0,360.0 );


    //    scaleDraw->enableComponent( QwtAbstractScaleDraw::Labels, true );
    //    scaleDraw->setAngleRange(-90.0,90.0);



    //    QwtDialSimpleNeedle *needle = new QwtDialSimpleNeedle(
    //                QwtDialSimpleNeedle::Arrow, true, Qt::red,
    //                QColor( Qt::gray ).light( 130 ) );


    //     IndiacatorNeedle *needle = new IndicatorNeedle();
    //     setNeedle( needle );

    const QColor color = palette().color( QPalette::Text );
    m_needle=  new IndiacatorNeedle( color );
    setNeedle(m_needle  );

    setMode(RotateNeedle);
}

void SpeedoMeter::setLabel( const QString &label )
{
    d_label = label;
    update();
}

QString SpeedoMeter::label() const
{
    return d_label;
}

/*
函数名：设置角度
*/
void SpeedoMeter::setAngle(const double & angle)
{
    m_angle=angle;
    update();
}

void SpeedoMeter::update_widget()
{
}

void SpeedoMeter::drawScale( QPainter *painter, const QPointF &center, double radius ) const
{
    painter->save();
    qDebug()<<"..................";
    QwtDial::drawScale( painter, center, radius );

    painter->restore();


}

#include <math.h>
#include <QDebug>
void SpeedoMeter::drawScaleContents( QPainter *painter,
                                     const QPointF &center, double radius ) const
{
    qDebug()<<"1enter drawScaleContents";
    QRectF rect( 0.0, 0.0, 2.0 * radius, 2.0 * radius - 10.0 );
    rect.moveCenter( center );

    const QColor color = palette().color( QPalette::Text );
    painter->setPen( color );
    painter->setPen(QColor(Qt::red));
    const int flags = Qt::AlignBottom | Qt::AlignHCenter;
    //画km/s的label
    painter->drawText( rect, flags, d_label );


    qDebug()<<radius;

    QPointF _point1(center.x(),center.y()-radius);QPointF point2(center.x(),center.y()+radius);
    painter->setPen(QColor(Qt::blue));


    //painter->drawLine(_point1,point2);


    double _offsetD=radius/5;
    //画线，刷新的时候重新进行绘制
    QVector<QPointF> _vec;
    QPointF _pointStart(center.x()+_offsetD,center.y()-radius);
    QPointF _pointStartPoint(center.x(),center.y()-radius);



    QPointF _point(center);
    QPointF _point222(center.x()+_offsetD,center.y());


    QPointF _pointEnd(center.x(),center.y()+radius);
    QPointF _pointEndPoint(center.x()+_offsetD,center.y()+radius);





    //半径平均分9分  起始点坐标 圆心, 终点坐标 圆心角15°= 弧度  点
    double _jianGeD=radius*cos(30*M_PI/180.0)/9.0;//一个间隔的长度

    _pointStart.setY(center.y()-_jianGeD*9);
    _pointStartPoint.setY(_pointStart.y());

    _pointEnd.setY(center.y()+_jianGeD*9);
    _pointEndPoint.setY(_pointEnd.y());

    painter->drawLine(_pointStartPoint,_pointEnd);



    _vec.push_back(_pointStart);
    _vec.push_back(_pointStartPoint);


    //中间部分线段 有两种方案1.一种就是每个线段一点点的画；方案2。是直接画一条类似直径的线段
    //    _vec.push_back(_pointStartPoint);
    //    _vec.push_back(_point);
    _vec.push_back(_point);
    _vec.push_back(_point222);

    //中间部分 出现这种原因的原因是因为： 画polyLine 取两个点画线
    //    _vec.push_back(_point222);
    //    _vec.push_back(_point);

    //    _vec.push_back(_point);
    //    _vec.push_back(_pointEnd);

    _vec.push_back(_pointEnd);
    _vec.push_back(_pointEndPoint);

    painter-> drawLines(_vec);



    QPointF _pointCom;

    for(int i=0; i<9;++i)
    {
        //画上半部分水平方向的线段
        _pointCom.setX(center.x());
        _pointCom.setY(center.y()-_jianGeD*i);
        _vec.push_back(_pointCom);

        _pointCom.setX(center.x()+_offsetD);
        _pointCom.setY(center.y()-_jianGeD*i);
        _vec.push_back(_pointCom);



        //画下半部分水平方向的线段
        _pointCom.setX(center.x());
        _pointCom.setY(center.y()+_jianGeD*i);
        _vec.push_back(_pointCom);

        _pointCom.setX(center.x()+_offsetD);
        _pointCom.setY(center.y()+_jianGeD*i);
        _vec.push_back(_pointCom);

    }

    painter-> drawLines(_vec);



    //字体偏移量
    double _textOffSetD=12.0;//rect宽的一半
    //画0°
    QRectF rectOriginText( 0.0, 0.0, 20,  20.0 );
    QPointF _textCenter(_point222.x()+_textOffSetD,_point222.y()) ;
    rectOriginText.moveCenter(_textCenter );
    QFont font;
    font.setPointSizeF(12);
    painter->setFont(font);
    painter->drawText( rectOriginText, "0°" );



    //needle线 1. x对应的坐标固定，改变y坐标的大小   2.对应的比例关系
    //    QPointF _pStartNeedle;
    //    QPointF _pendNeedle;

    //    _pStartNeedle.setX(center.x()-center.x()/3);
    //    _pendNeedle.setX(center.x()-center.x()/5);

    //    _pStartNeedle.setY(center.y());
    //    _pendNeedle.setY(center.y());
    //    painter->drawLine(_pStartNeedle,_pendNeedle);


    //角度对应的 距离   1°= 长度
    double _disOffsent=(radius*cos(30*M_PI/180.0))/90.0;


    QPointF _pStartNeedle;
    QPointF _pendNeedle;

    _pStartNeedle.setX(center.x()-center.x()/3);
    _pendNeedle.setX(center.x()-center.x()/5);

    _pStartNeedle.setY(center.y()+m_angle*_disOffsent);
    _pendNeedle.setY(center.y()+m_angle*_disOffsent);
    painter->setPen(QColor(Qt::darkYellow));
    painter->drawLine(_pStartNeedle,_pendNeedle);

    qDebug()<<"----dis----"<<_disOffsent<<m_angle<<m_angle*_disOffsent;
    //画一个圆
    // painter->drawRoundedRect();

   m_needle->setCenterAndRadiu(center,radius,m_angle);
}

