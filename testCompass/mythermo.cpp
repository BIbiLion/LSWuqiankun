#include "mythermo.h"
#include <QPainter>
#include <QStyleOption>
myThermo::myThermo()
{
}
 myThermo:: myThermo(QWidget*widget)
  {
     this->setParent(widget);
  }

/*
 * mythermo.cpp: In member function 'virtual void myThermo::paintEvent(QPaintEvent*)':
mythermo.cpp:12:36: error: invalid use of incomplete type 'class QPaintEvent'
        painter.setClipRegion( event->region() );
                                    ^
In file included from C:\Qt\Qt5.2.1\5.2.1\mingw48_32\include\qwt/qwt_abstract_scale.h:14:0,
                 from C:\Qt\Qt5.2.1\5.2.1\mingw48_32\include\qwt/qwt_thermo.h:14,
                 from mythermo.h:3,
                 from mythermo.cpp:1:
C:\Qt\Qt5.2.1\5.2.1\mingw48_32\include\QtWidgets/qwidget.h:78:7: error: forward declaration of 'class QPaintEvent'
 class QPaintEvent;
       ^
mythermo.cpp:20:35: error: invalid use of incomplete type 'class QPaintEvent'
        if ( !tRect.contains( event->rect() ) )
                                   ^
In file included from C:\Qt\Qt5.2.1\5.2.1\mingw48_32\include\qwt/qwt_abstract_scale.h:14:0,
                 from C:\Qt\Qt5.2.1\5.2.1\mingw48_32\include\qwt/qwt_thermo.h:14,
                 from mythermo.h:3,
                 from mythermo.cpp:1:
C:\Qt\Qt5.2.1\5.2.1\mingw48_32\include\QtWidgets/qwidget.h:78:7: error: forward declaration of 'class QPaintEvent'
 class QPaintEvent;
       ^
In file included from mythermo.h:3:0,
                 from mythermo.cpp:1:
C:\Qt\Qt5.2.1\5.2.1\mingw48_32\include\qwt/qwt_thermo.h:175:18: error: 'QwtThermo::PrivateData* QwtThermo::d_data' is private
     PrivateData *d_data;
                  ^
mythermo.cpp:22:17: error: within this context
            if ( d_data->scalePosition != QwtThermo::NoScale )
                 ^
mythermo.cpp:22:23: error: invalid use of incomplete type 'class QwtThermo::PrivateData'
            if ( d_data->scalePosition != QwtThermo::NoScale )
                       ^
In file included from mythermo.h:3:0,
                 from mythermo.cpp:1:
C:\Qt\Qt5.2.1\5.2.1\mingw48_32\include\qwt/qwt_thermo.h:174:11: error: forward declaration of 'class QwtThermo::PrivateData'
     class PrivateData;
           ^
mythermo.cpp:23:27: error: invalid use of incomplete type 'class QwtScaleDraw'
                scaleDraw()->draw( &painter, palette() );
                           ^
In file included from mythermo.h:3:0,
                 from mythermo.cpp:1:
C:\Qt\Qt5.2.1\5.2.1\mingw48_32\include\qwt/qwt_thermo.h:17:7: error: forward declaration of 'class QwtScaleDraw'
 class QwtScaleDraw;
 * */
#include <qwt_scale_draw.h>


void myThermo::paintEvent( QPaintEvent * event )
{

    QPainter painter( this );
    painter.setClipRegion( event->region()  );

    QStyleOption opt;
    opt.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    const QRect tRect = pipeRect();

    if ( !tRect.contains( event->rect() ) )
    {
        //if ( d_data->scalePosition != QwtThermo::NoScale )
        scaleDraw()->draw( &painter, palette() );
    }


    //  drawLiquid( &painter, tRect );
//    QPointF _firP(tRect.center());
//    QPointF _secP(tRect.center());
//    _secP.setX(tRect.center().x()+9);

    drawLiquid( &painter, tRect );


   // painter.setPen(QColor(Qt::red));
   // painter.drawLine(_firP,_secP);

}

#include <qwt_scale_map.h>
void myThermo::drawLiquid( QPainter *painter, const QRect &pipeRect ) const
{

    painter->save();
    painter->setClipRect( pipeRect, Qt::IntersectClip );
    painter->setPen( Qt::NoPen );

    const QwtScaleMap scaleMap = scaleDraw()->scaleMap();

    QRect liquidRect = fillRect( pipeRect );
    liquidRect.setBottom(liquidRect.top()+0.2);


    {

        {
            const QRect r = alarmRect( liquidRect );
            if ( !r.isEmpty() )
            {
                painter->fillRect( r, palette().brush( QPalette::Highlight ) );
                liquidRect = QRegion( liquidRect ).subtracted( r ).boundingRect();
            }
        }
        painter->setPen(QColor(Qt::red));
        painter->fillRect( liquidRect, palette().brush( QPalette::ButtonText ) );
    }


    painter->restore();
}
