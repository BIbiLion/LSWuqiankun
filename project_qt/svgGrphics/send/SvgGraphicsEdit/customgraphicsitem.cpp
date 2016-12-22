#include "customgraphicsitem.h"
#include "typedef.h"
#include <math.h>
#include <QtSvg>

CustomGraphicsItem::CustomGraphicsItem(quint16 tmpType,QGraphicsItem *parent)
	:m_type(tmpType),QGraphicsItem(parent)
{
    initVar();
	setAcceptDrops(true);
    setAcceptsHoverEvents(true);
	setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);

	createResizeFocus();
	
}

CustomGraphicsItem::CustomGraphicsItem(quint16 tmpType,qreal w,qreal h,qreal m,QGraphicsItem *parent)
	:m_type(tmpType),m_width(w),m_height(h),m_margin(m),QGraphicsItem(parent)
{
	angle = 0;

	setAcceptDrops(true);
    setAcceptsHoverEvents(true);
	setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);

	createResizeFocus();
	
}

CustomGraphicsItem::~CustomGraphicsItem()
{

}


QRectF CustomGraphicsItem::boundingRect() const
{
	return QRectF(0, 0, m_width, m_height);
}

void CustomGraphicsItem::initVar()
{
	m_penColor = Qt::cyan;
	m_fillColor = Qt::white;
	m_penWidth = 1;
	m_width = 20;
	m_height = 20;
	m_margin = 6;
	angle = 0;
	m_flag = true;

}

int CustomGraphicsItem::width()
{
	return m_width;
}
int CustomGraphicsItem::height()
{
	return m_height;
}

void CustomGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{
	Q_UNUSED(widget);

	bool bShow = false;

	if(option->state & QStyle::State_Selected)
	{
		
		setCursor(Qt::SizeAllCursor);
		//画选择的虚线框
		m_pen.setStyle(Qt::DotLine);
		bShow = true;			
	}
	else
	{    
		bShow = false;	

		if (!editShowModel())
		{
			if (this->type() == EQUIP_GRAPHICSITEM )
			{
				setCursor(Qt::PointingHandCursor);
			}
		}
		else
		{
			setCursor(Qt::ArrowCursor);	
			m_pen.setStyle(Qt::SolidLine);
		}
		
	}

	m_pen.setWidth(m_penWidth);
	m_pen.setColor(m_penColor);
	painter->setPen(m_pen);

    switch(m_type)
	{
	case BELLLINE_HORIZONTAL_GRAPHICSITEM:
		{	
			QPointF point1(m_margin,m_height/2);
			QPointF point2(m_width-m_margin,m_height/2);
            
			painter->drawLine(point1,point2); 
			
			break;
		}
	case BELLLINE_VERTICAL_GRAPHICSITEM:
		{
			QPointF point1(m_width/2,0);
			QPointF point2(m_width/2,m_height-0);
            
			painter->drawLine(point1,point2); 
			break;
		}
	case RECTANGLE_GRAPHICSITEM:
		{
			painter->setBrush(m_fillColor);
			painter->rotate(angle);
            painter->drawRect(m_margin,m_margin,m_width-2*m_margin,m_height-2*m_margin);
			break;
		}
	case STARRY_GRAPHICSITEM:
		{
			QPointF point1(m_margin,m_margin);
			QPointF point2(m_width-m_margin,m_margin);
			QPointF point3(m_width/2,m_height/2);
			QPointF point4(m_width/2, m_height);

			painter->drawLine(point1,point3);
			painter->drawLine(point2,point3);
			painter->drawLine(point3,point4);
			break;
		}
	case ELLIPSE_GRAPHICSITEM:
		{
			painter->setBrush(m_fillColor);
			painter->drawEllipse(m_margin,m_margin,m_width-2*m_margin,m_height-2*m_margin);
			break;
		}
	case CONTAINER_HORIZONTAL_GRAPHICSITEM:
		{
			QPointF point1(m_margin,m_height/2);
			QPointF point2(m_width-m_margin,m_height/2);

		    painter->setBrush(m_fillColor);
			painter->drawLine(point1,point2);
			painter->drawRect(m_margin+(m_width-2*m_margin)/4,m_margin,(m_width-2*m_margin)*2/4,m_height-2*m_margin);
			
			break;
		}
	case CONTAINER_VERTICAL_GRAPHICSITEM:
		{
            QPointF point5(m_width/2, m_margin);
			QPointF point6(m_width/2, m_height-m_margin);

			QRectF rect(m_margin,(m_height-2*m_margin)/4+m_margin,m_width-2*m_margin,(m_height-2*m_margin)/2);
			painter->setBrush(m_fillColor);
			painter->drawLine(point5,point6);
			painter->drawRect(rect);

			break;
		}
	case TRIANGLE_GRAPHICSITEM:
		{
			QPointF point1(m_width/2,0);
			QPointF point2(0,m_height);
			QPointF point3(m_width,m_height);

			QPolygonF   ploygon;
			ploygon.append (point1);
			ploygon.append (point2);
			ploygon.append (point3);
			
	        painter->setBrush(m_fillColor);
			painter->drawPolygon (ploygon);
			
			break;
		}
	case CAPACTIOR_HORIZONTAL_GRAPHICSITEM:
		{
			QPointF point1(m_margin,m_height/2);
			QPointF point2(m_margin+(m_width-2*m_margin)*1/3,m_height/2);
			QPointF point3(m_margin+(m_width-2*m_margin)/3,m_margin);
			QPointF point4(m_margin+(m_width-2*m_margin)/3,m_height-m_margin);
			QPointF point5(m_margin+(m_width-2*m_margin)*2/3,m_margin);
			QPointF point6(m_margin+(m_width-2*m_margin)*2/3,(m_height)/2);
			QPointF point7(m_margin+(m_width-2*m_margin)*2/3,(m_height-m_margin));
			QPointF point8(m_margin+(m_width-2*m_margin),(m_height)/2);
			
			painter->drawLine(point1,point2);
			painter->drawLine(point3,point4);
			painter->drawLine(point5,point7);
			painter->drawLine(point6,point8);
			break;
		}
	case CAPACTIOR_VERTICAL_GRAPHICSITEM:
		{

			QPointF point1(m_width/2,m_margin);
			QPointF point2(m_margin+(m_width-2*m_margin)/2,(m_height-2*m_margin)/3+m_margin);
			QPointF point3(m_margin,(m_height-2*m_margin)/3+m_margin);
			QPointF point4(m_width-m_margin,(m_height-2*m_margin)/3+m_margin);
			QPointF point5(m_margin,(m_height-2*m_margin)*2/3+m_margin);
			QPointF point6(m_width-m_margin,(m_height-2*m_margin)*2/3+m_margin);
			QPointF point7(m_width/2,(m_height-2*m_margin)*2/3+m_margin);
			QPointF point8(m_width/2,m_height-m_margin);
			
			painter->drawLine(point1,point2);
			painter->drawLine(point3,point4);
			painter->drawLine(point5,point6);
			painter->drawLine(point7,point8);
			break;
		}
	case TERMINAL_VERTICAL_GRAPHICSITEM:
		{
			QPointF point1(m_width/2,m_margin);
			QPointF point2(m_margin,m_height/2);
			QPointF point3(m_width/2,(m_height-m_margin)/2+(m_height-m_margin)/4);
			QPointF point4(m_width-m_margin,m_height/2);
			QPointF point5(m_width/2,m_height-m_margin);

			painter->drawLine(point1,point5);

			QPolygonF   ploygon;
			ploygon.append (point2);
			ploygon.append (point3);
			ploygon.append (point4);

			 painter->setBrush(m_fillColor);
			painter->drawPolygon (ploygon);

			break;
		}
	case TERMINAL_HORIZONTAL_GRAPHICSITEM:
		{

			break;
		}
	case KNIVESSWITCH_HORIZONTAL_GRAPHICSITEM:
		{
            qreal spx = m_margin;
			qreal spy = m_margin;
			qreal epx = m_width-m_margin;
			qreal epy = m_height-m_margin;
			qreal w,h;
			w = epx-spx;
			h = epy-spy;
			qreal spxw9c3 = spx+w*3/9;
			qreal spxw9c6 = spx+w*6/9;
			qreal epyh6c1 = epy-h*1/6;
			qreal epyh6c3 = epy-h*3/6;
		 
			painter->drawLine(QPointF(spx, epyh6c1), QPointF(spxw9c3, epyh6c1));
			painter->drawLine(QPointF(spxw9c6, epyh6c1), QPointF(epx, epyh6c1));
			painter->drawLine(QPointF(spxw9c3, spy), QPointF(spxw9c6, epyh6c1));
			painter->drawLine(QPointF(spxw9c3, epy), QPointF(spxw9c3, epyh6c3));


            break;
		}
	case KNIVESSWITCH_VERTICALL_GRAPHICSITEM:
		{	
			qreal spx = m_margin;
			qreal spy = m_margin;
			qreal epx = m_width-m_margin;
			qreal epy = m_height-m_margin;
			qreal w,h;
			w = epx-spx;
			h = epy-spy;
			qreal spxw6 = spx+w/6;
			qreal spxw9c6 = spx+w*6/9;
			qreal epxw6 = epx-w/6;
			qreal epxw9c6 = epx-w*6/9;
			qreal spyh3 = spy+h/3;
			qreal epyh9c4 = epy-h*4/9;

			painter->drawLine(QPointF(epxw6, spy), QPointF(epxw6, spyh3));
			painter->drawLine(QPointF(epx, spyh3), QPointF(epxw9c6, spyh3));
			painter->drawLine(QPointF(epxw6, epy), QPointF(epxw6, epyh9c4));
			painter->drawLine(QPointF(epxw6, epyh9c4), QPointF(spx, spyh3));

			break;
			}
	case BOTTOMLINE_HORIZONTAL_GRAPHICSITEM:
		{
			QPointF point1(m_margin,m_height/2);
			QPointF point2(m_margin+(m_width-2*m_margin)/2,m_height/2);
			QPointF point3(m_width/2,m_margin);
			QPointF point4(m_width/2,m_height-m_margin);
			QPointF point5(m_margin+(m_width-2*m_margin)*3/4,m_height/2 -(m_height-2*m_margin)/4);
			QPointF point6(m_margin+(m_width-2*m_margin)*3/4,m_height/2 +(m_height-2*m_margin)/4);
			QPointF point7(m_width-m_margin,m_height/2 -(m_height-2*m_margin)/9);
			QPointF point8(m_width-m_margin,m_height/2 +(m_height-2*m_margin)/9);

			painter->drawLine(point1,point2);
			painter->drawLine(point3,point4);
			painter->drawLine(point5,point6);
			painter->drawLine(point7,point8);
           
			break;
		}
	case BOTTOMLINE_VERTICALL_GRAPHICSITEM:
		{
			QPointF point1(m_width/2,m_margin);
			QPointF point2(m_width/2,m_height/2);
			QPointF point3(m_margin,m_height/2);
			QPointF point4(m_width-m_margin,m_height/2);
			QPointF point5(m_width/4,m_height/2 +(m_height-2*m_margin)/4);
			QPointF point6(m_width*3/4,m_height/2 +(m_height-2*m_margin)/4);
			QPointF point7(m_width/2-m_width/8,m_height-m_margin);
			QPointF point8(m_width/2+m_width/8,m_height-m_margin);

			painter->drawLine(point1,point2);
			painter->drawLine(point3,point4);
			painter->drawLine(point5,point6);
			painter->drawLine(point7,point8);


			break;
		}
	case GENERATRIX_GRAPHICSITEM:
		{	
			QRectF rect(m_margin,m_margin,m_width-2*m_margin,m_height-2*m_margin);
			QLinearGradient fade(0, 0, 0, rect.height());

			fade.setSpread (QGradient::ReflectSpread);
			fade.setColorAt(0, m_fillColor.light(150));
			fade.setColorAt(1, m_fillColor.dark(180));
			painter->setBrush(fade);		
			painter->drawRect(rect);
			break;
		}
	case CURRENTINDUCTANCE_LEFT_GRAPHICSITEM:
		{

			qreal x1,y1,x2,y2;
			x1=0;
			y1=0;
			x2=m_width;
			y2=m_height;

			int startAngle ;
			int spanAngle ;

			if (x1<x2)
		   {
				startAngle = 90 * 16;
				spanAngle = 180 * 16;
		
			}
			else
			{
				startAngle = 270 * 16;
				spanAngle = 180 * 16;
			}
			qreal h;
			if (y1<y2)
				h=y2-y1;
			else
				h=y1-y2;
			qreal h4 =h/4;
			qreal rw = m_width;//m_Rect.m_width();
			qreal yh4 = (y2-y1)/4;

			QRectF rt = QRectF(x1, y1, rw, h4);
			if (y2<y1)
				rt = QRectF(x1, y1-h4, rw, h4);
			painter->drawArc ( rt, startAngle, spanAngle ) ;
	
			rt = QRectF(x1, y1+yh4, rw, h4);
			if (y2<y1)
				rt = QRectF(x1, y1+2*yh4, rw, h4);
			painter->drawArc ( rt, startAngle, spanAngle ) ;
	
			rt = QRectF(x1, y1+2*yh4, rw, h4);
			if (y2<y1)
				rt = QRectF(x1, y1+3*yh4, rw, h4);
			painter->drawArc ( rt, startAngle, spanAngle ) ;
	
			if (y2<y1)
				rt = QRectF(x1, y2, rw, h4);
			else
				rt = QRectF(x1, y1+3*yh4, rw, h4);
			painter->drawArc ( rt, startAngle, spanAngle ) ;

			painter->drawLine ( QPointF (x1+(x2-x1)/2, y1-yh4/2), QPointF (x1+(x2-x1)/2, y2+yh4/2));
			painter->drawLine ( QPointF (x1+(x2-x1)/2, y1), QPointF (x2, y1));
			painter->drawLine ( QPointF (x1+(x2-x1)/2, y2), QPointF (x2, y2));

			

			break;
		}

	case CURRENTINDUCTANCE_RIGHT_GRAPHICSITEM:
		{
			qreal x1,y1,x2,y2;
			x1=0;
			y1=0;
			x2=m_width;
			y2=m_height;

			int startAngle ;
			int spanAngle ;

			
			startAngle = 270 * 16;
			spanAngle = 180 * 16;
			
			qreal h=y2-y1;
			qreal h4 =h/4;
			qreal rw = m_width;//m_Rect.m_width();
			qreal yh4 = (y2-y1)/4;

		
			QRectF rt = QRectF(x1, y1, rw, h4);
			painter->drawArc ( rt, startAngle, spanAngle ) ;
	
		
			rt = QRectF(x1, y1+1*yh4, rw, h4);
			painter->drawArc ( rt, startAngle, spanAngle ) ;
	
			
			rt = QRectF(x1, y1+2*yh4, rw, h4);
			painter->drawArc ( rt, startAngle, spanAngle ) ;
	
			
			rt = QRectF(x1, y1+3*yh4, rw, h4);	
			painter->drawArc ( rt, startAngle, spanAngle ) ;

			painter->drawLine ( QPointF (x1+(x2-x1)/2, y1-yh4/2), QPointF (x1+(x2-x1)/2, y2+yh4/2));
			painter->drawLine ( QPointF (x1, y1), QPointF (x1+(x2-x1)/2, y1));
			painter->drawLine ( QPointF (x1, y2), QPointF (x1+(x2-x1)/2, y2));

			break;
		}
	case VOLTAGEINDUCTANCE_HORIZONTAL_GRAPHICSITEM:
		{

			qreal x1,y1,x2,y2;
			x1=0;
			y1=0;
			x2=m_width;
			y2=m_height;

			int right_startAngle ;
			int right_spanAngle ;
			int left_startAngle ;
			int left_spanAngle ;

			if (x1<x2) {
				right_startAngle = 90 * 16;
				right_spanAngle = 180 * 16;

				left_startAngle = 270 * 16;
				left_spanAngle = 180 * 16;
			}else  {
				right_startAngle = 270 * 16;
				right_spanAngle = 180 * 16;

				left_startAngle = 90 * 16;
				left_spanAngle = 180 * 16;
			}
			qreal h;
			if (y1<y2)
				h=y2-y1;
			else
				h=y1-y2;
			qreal h4 =h/4;
			qreal rw = m_width;
			qreal yh4 = (y2-y1)/4;

			qreal rightX = 0.0;
			qreal leftX = 0.0;
	
			if (x1<x2) {
				rightX = x1+(x2-x1)/2+3;
				leftX = x1-(x2-x1)/2-3;
			}else {
				rightX = x1+(x2-x1)/2-3;
				leftX = x1-(x2-x1)/2+3;
			}
	
			QRectF rtR = QRectF(rightX, y1, rw, h4);
			QRectF rtL = QRectF(leftX, y1, rw, h4);
			if (y2<y1) {
				rtR = QRectF(rightX, y1-h4, rw, h4);
				rtL = QRectF(leftX, y1-h4, rw, h4);
			}
			painter->drawArc ( rtL, left_startAngle, left_spanAngle ) ;
			painter->drawArc ( rtR, right_startAngle, right_spanAngle ) ;
	
			rtL = QRectF(leftX, y1+yh4, rw, h4);
			rtR = QRectF(rightX, y1+yh4, rw, h4);
			if (y2<y1) {
				rtL = QRectF(leftX, y1+2*yh4, rw, h4);
				rtR = QRectF(rightX, y1+2*yh4, rw, h4);
			}
			painter->drawArc ( rtL, left_startAngle, left_spanAngle ) ;
			painter->drawArc ( rtR, right_startAngle, right_spanAngle ) ;
	
			rtL = QRectF(leftX, y1+2*yh4, rw, h4);
			rtR = QRectF(rightX, y1+2*yh4, rw, h4);
			if (y2<y1) {
				rtL = QRectF(leftX, y1+3*yh4, rw, h4);
				rtR = QRectF(rightX, y1+3*yh4, rw, h4);
			}
			painter->drawArc ( rtL, left_startAngle, left_spanAngle ) ;
			painter->drawArc ( rtR, right_startAngle, right_spanAngle ) ;
	
			rtL = QRectF(leftX, y1+3*yh4, rw, h4);
			rtR = QRectF(rightX, y1+3*yh4, rw, h4);
			if (y2<y1) {
				rtL = QRectF(leftX, y2, rw, h4);
				rtR = QRectF(rightX, y2, rw, h4);
			}
			painter->drawArc ( rtL, left_startAngle, left_spanAngle ) ;
			painter->drawArc ( rtR, right_startAngle, right_spanAngle ) ;


			break;
		}
	case VOLTAGEINDUCTANCE_VERTICALL_GRAPHICSITEM:
	{

		break;
	}
	case BREAKER_HORIZONTAL_GRAPHICSITEM:
	{
            QPointF point1(m_margin,m_height/2);
			QPointF point2(m_width-m_margin,m_height/2);

			QLinearGradient knobGradient(m_margin,m_margin,m_width,m_height);
			knobGradient.setSpread (QGradient::ReflectSpread);
			knobGradient.setColorAt(0, m_penColor.light(150));
			knobGradient.setColorAt(1, m_penColor.dark(180));
		    painter->setBrush(knobGradient);
			painter->drawLine(point1,point2);
			painter->drawRect(m_margin+(m_width-2*m_margin)/4,m_margin,(m_width-2*m_margin)*2/4,m_height-2*m_margin);


			break;
	}
    case BREAKER_VERTICAL_GRAPHICSITEM:
		{
			QPointF point1(m_width/2,m_margin);
			QPointF point2(m_width/2,m_height-m_margin);

			QLinearGradient knobGradient(m_margin,m_margin,m_width,m_height);
			knobGradient.setSpread (QGradient::ReflectSpread);
			knobGradient.setColorAt(0, m_penColor.light(150));
			knobGradient.setColorAt(1, m_penColor.dark(180));
		    painter->setBrush(knobGradient);
			painter->drawLine(point1,point2);
			painter->drawRect(m_margin,(m_height-2*m_margin)/4+m_margin,m_width-2*m_margin,(m_height-2*m_margin)/2);
			break;
		}
	case TRANSFORMER_GRAPHICSITEM:
		{
			qreal spx = 0/*+m_margin*/;
			qreal spy = 0/*+m_margin*/;
			qreal epx = m_width/*-2*m_margin*/;
			qreal epy = m_height/*-2*m_margin*/;
			
			qreal w = epx-spx;
			qreal h = epy-spy;
			qreal s3h5 = h * 3 / 5;
			qreal s3w5 = 3 * w / 5;
			qreal w5 = w/5;
			
			QRectF rc1 = QRectF(spx + w5,spy,s3w5,s3h5);
			painter->drawEllipse(rc1);

			QRectF rc2 = QRectF(spx,spy + 2*(epy-spy)/5,s3w5, s3h5);
			painter->drawEllipse(rc2);

			QRectF rc3 = QRectF(spx + 2*w*17/80,spy + 2*h/5,3*w*61/320,s3h5);
			painter->drawEllipse(rc3);
			break;
		}
	case TRANSFORMER1_GRAPHICSITEM:
		{
			QPointF point1(m_margin,m_margin);
			QPointF point2(m_margin,(m_height-m_margin)*2/5+m_margin);

			painter->drawEllipse(point1.x(),point1.y(),m_width-2*m_margin,(m_height-m_margin)*3/5);
			painter->drawEllipse(point2.x(),point2.y(),m_width-2*m_margin,(m_height-m_margin)*3/5);

			break;
		}
	case SPLITREACTOR_GRAPHICSITEM:
		{
			qreal x1,y1,x2,y2;
			x1= 0;
			y1= 0;
			x2= m_width;
			y2= m_height;

			int startAngle ;
			int spanAngle ;
			
			qreal w = x2-x1;
			qreal h = y2-y1;
			qreal w4 = w/4;
			qreal w8 = w/8;
			qreal h3 = h/3;
			qreal h16 = h/16;
			qreal h20 = h/20;

			if (y1<y2)
			{
				startAngle = 300 * 16;
				spanAngle = 300 * 16;
				
			}
			else
			{
				startAngle = 120 * 16;
				spanAngle = 300 * 16;
			}
			QRectF rect(0,0,m_width,m_height);
			painter->drawArc ( rect, startAngle, spanAngle ) ;
			painter->drawLine ( QPointF(x1+w4,y2-h16), QPointF(x1+w4,y2-h3) );
			painter->drawLine ( QPointF(x1+w4,y2-h3), QPointF(x1-w8,y2-h3) );
			painter->drawLine ( QPointF(x1-w8,y2-h3), QPointF(x1-w8,y2+h20));

			painter->drawLine ( QPointF(x1+3*w4,y2-h16), QPointF(x1+3*w4,y2-h3) );
			painter->drawLine ( QPointF(x1+3*w4,y2-h3), QPointF(x2+w8,y2-h3) );
			painter->drawLine ( QPointF(x2+w8,y2-h3), QPointF(x2+w8,y2+h20));

			break;
		}
	case REACTOR_GRAPHICSITEM:
		{
			qreal x1,y1,x2,y2;
			x1= 0;
			y1= 0;
			x2= m_width;
			y2= m_height;
			
			int startAngle ;
			int spanAngle ;

			if (x1<x2)
			{
				if (y1<y2)
				{
					startAngle = 270 * 16;
					spanAngle = 270 * 16;
				}
				else
				{
					startAngle = 180 * 16;
					spanAngle = 270 * 16;
				}
			}
			else
			{
				if (y1<y2)
				{
					startAngle = 0 * 16;
					spanAngle = 270 * 16;
				}
				else
				{
					startAngle = 90 * 16;
					spanAngle = 270 * 16;
				}

			}
			
			QRectF rect(0,0,m_width,m_height);
			painter->drawArc ( rect, startAngle, spanAngle ) ;
			painter->drawLine( QPointF(x1,y1+(y2-y1)/2), QPointF(x1+(x2-x1)/2,y1+(y2-y1)/2) );
			painter->drawLine( QPointF(x1+(x2-x1)/2,y1+(y2-y1)/2), QPointF(x1+(x2-x1)/2,y1-(y2-y1)/3) );
			painter->drawLine( QPointF(x1+(x2-x1)/2,y2), QPointF(x1+(x2-x1)/2,y2+(y2-y1)/3) );
			break;
		}
	case POWERHOUSE_GRAPHICSITEM:
		{

			qreal spx = 0;
			qreal spy = 0;
			qreal epx = m_width;
			qreal epy = m_height;
	

			qreal epxspx = epx-spx;
			qreal epyspy = epy-spy;
			qreal epxspx6 = epxspx/6;
			qreal epxspx3 = epxspx/3;
			qreal epyspy4c2 = epyspy*2/4;
			qreal epyspy4c1 = epyspy*1/4; 

			painter->drawEllipse(spx,spy,epx,epy);
			
			QVector<QPointF>	pointList;
			
			
			pointList.append (QPointF(spx + epxspx6, spy + epyspy4c2));
			pointList.append (QPointF(spx + epxspx3, spy + epyspy4c1));
			
			pointList.append (QPointF(epx - epxspx3, epy - epyspy4c1));
			pointList.append (QPointF(epx - epxspx6, spy + epyspy4c2));
			
			QPainterPath path;
			path.moveTo (pointList[0]);
			path.cubicTo (pointList[1], pointList[2], pointList[3]);
			painter->drawPath(path); 

			break;
		}

	case LINE_TOP_GRAPHICSITEM:
		{
			QPointF point1(m_width/2,m_margin);
			QPointF point2(m_margin,(m_height-2*m_margin)*1/4+m_margin);
			QPointF point3(m_width-m_margin,(m_height-2*m_margin)*1/4+m_margin);
			QPointF point4(m_width/2,(m_height-2*m_margin)*1/4+m_margin);
			QPointF point5(m_width/2,m_height-m_margin);

			QPolygonF   ploygon;
			ploygon.append (point1);
			ploygon.append (point2);
			ploygon.append (point3);

	        painter->setBrush(m_fillColor);
			painter->drawPolygon (ploygon);
			painter->drawLine(point4,point5);
			break;
		}
	case LINE_BUTTOM_GRAPHICSITEM:
		{
			QPointF point1(m_margin,m_height-m_margin-(m_height-2*m_margin)*1/4);
			QPointF point2(m_width-m_margin,m_height-m_margin-(m_height-2*m_margin)*1/4);
			QPointF point3(m_width/2,m_height-m_margin);
			QPointF point4(m_width/2,m_margin);
			QPointF point5(m_width/2,m_height-m_margin-(m_height-2*m_margin)*1/4);

			QPolygonF   ploygon;
			ploygon.append (point1);
			ploygon.append (point2);
			ploygon.append (point3);

	        painter->setBrush(m_fillColor);
			painter->drawPolygon (ploygon);
			painter->drawLine(point4,point5);
			break;
		}
	case LINE_LEFT_GRAPHICSITEM:
		{
			QPointF point1(m_margin,m_height/2);
			QPointF point2(m_margin+(m_width-2*m_margin)/4,m_margin);
			QPointF point3(m_margin+(m_width-2*m_margin)/4,m_height-m_margin);
			QPointF point4(m_margin+(m_width-2*m_margin)/4,m_height/2);
			QPointF point5(m_width-m_margin,m_height/2);

			QPolygonF   ploygon;
			ploygon.append (point1);
			ploygon.append (point2);
			ploygon.append (point3);

	        painter->setBrush(m_fillColor);
			painter->drawPolygon (ploygon);
			painter->drawLine(point4,point5);
			break;
		}
	case LINE_RIGHT_GRAPHICSITEM:
		{
			QPointF point1(m_width-(m_width-2*m_margin)/4,m_margin);
			QPointF point2(m_width-(m_width-2*m_margin)/4,m_height-m_margin);
			QPointF point3(m_width-m_margin,m_height/2);
			QPointF point4(m_margin,m_height/2);
			QPointF point5(m_width-(m_width-2*m_margin)/4,m_height/2);

			QPolygonF   ploygon;
			ploygon.append (point1);
			ploygon.append (point2);
			ploygon.append (point3);

	        painter->setBrush(m_fillColor);
			painter->drawPolygon (ploygon);
			painter->drawLine(point4,point5);
			break;
		}
	case TEXT_GRAPHICSITEM:
	case EQUIP_GRAPHICSITEM:
	case STATION_GRAPHICSITEM:
		{
			QFontMetrics fm(m_font);
			QRectF		 rt;
			painter->setFont (m_font);
			rt = fm.boundingRect(m_strText);
			painter->drawText(0,0,rt.width(),rt.height(),Qt::AlignLeft ,m_strText);

			m_width = rt.width();
			m_height = rt.height();
			break;
		}
	
	default:
		break;
	}

	showResizeFocus(bShow);


	
}


 void CustomGraphicsItem::createResizeFocus()
 {
	 QBrush  brush(m_penColor);

	 EResizeFocus *north_middle = new EResizeFocus(m_margin,EResizeFocus::NORTH_MIDDLE,this);
	 resizeFocus.append(north_middle);
	 north_middle->setBrush(brush);

	 EResizeFocus *north_east = new EResizeFocus(m_margin,EResizeFocus::NORTH_EAST,this);
	 resizeFocus.append(north_east);
	 north_east->setBrush(brush);

	 EResizeFocus *north_west = new EResizeFocus(m_margin,EResizeFocus::NORTH_WEST,this);
	 resizeFocus.append(north_west);
	 north_west->setBrush(brush);

	 EResizeFocus *south_middle = new EResizeFocus(m_margin,EResizeFocus::SOUTH_MIDDLE,this);
	 resizeFocus.append(south_middle);
	 south_middle->setBrush(brush);

	 EResizeFocus *south_east = new EResizeFocus(m_margin,EResizeFocus::SOUTH_EAST,this);
	 resizeFocus.append(south_east);
	 south_east->setBrush(brush);

	 EResizeFocus *south_west = new EResizeFocus(m_margin,EResizeFocus::SOUTH_WEST,this);
	 resizeFocus.append(south_west);
	 south_west->setBrush(brush);

	 EResizeFocus *east_middle = new EResizeFocus(m_margin,EResizeFocus::EAST_MIDDLE,this);
	 resizeFocus.append(east_middle);
	 east_middle->setBrush(brush);

	 EResizeFocus *west_middle = new EResizeFocus(m_margin,EResizeFocus::WEST_MIDDLE,this);
	 resizeFocus.append(west_middle);
	 west_middle->setBrush(brush);
 }

void CustomGraphicsItem::showResizeFocus(bool visible)
{
	 for(int i = 0; i < resizeFocus.count(); i++)
	 {
		 resizeFocus.at(i)->locateInHost();
		 resizeFocus.at(i)->setVisible(visible);
	 }
	
}
void CustomGraphicsItem::setResizeBrush()
{
	 QBrush  brush(m_penColor);

	 for(int i = 0; i < resizeFocus.count(); i++)
	 {
		 resizeFocus.at(i)->setBrush(brush);
	 }

}

 void CustomGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
 {
	 curResizeFocus = qgraphicsitem_cast<EResizeFocus*>(scene()->itemAt(event->scenePos()));
	 if(curResizeFocus)
	 {
		 myMode = RESIZE;
		 m_lastPoint.setX(event->scenePos().x());
		 m_lastPoint.setY(event->scenePos().y());
		 dashRect = new QGraphicsRectItem();
		 dashRect->setPen(QPen(Qt::DashLine));
		 dashRect->setParentItem(this);
		 dashRect->setRect(m_margin, m_margin, m_width-m_margin*2, m_height-m_margin*2);
	 }
	 else
	 {
		myMode = MOVE;
		QGraphicsItem::mousePressEvent(event);
	 }
 }
 void CustomGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
 {
	 if(myMode == RESIZE)
	 {
		 QPointF curPoint(event->scenePos());

		 qreal curX = m_margin, curY = m_margin, curm_width = m_width-m_margin*2, curm_height = m_height-m_margin*2;
		 qreal wChanging = curPoint.x()-m_lastPoint.x(), hChanging = curPoint.y()-m_lastPoint.y();

		 EResizeFocus::PosInHost pos = curResizeFocus->getInHost();
		 switch(pos){
			case EResizeFocus::NORTH_MIDDLE:
				curY += hChanging; curm_height-=hChanging;
				break;
			case EResizeFocus::SOUTH_MIDDLE:
				curm_height+=hChanging;
				break;
			case EResizeFocus::EAST_MIDDLE:
				curm_width+=wChanging;
				break;
			case EResizeFocus::WEST_MIDDLE:
				curX+=wChanging; curm_width-=wChanging;
				break;
			case EResizeFocus::NORTH_WEST:
				curX+=wChanging; curY+=hChanging; curm_width-=wChanging; curm_height-=hChanging;
				break;
			case EResizeFocus::SOUTH_EAST:
				curm_width+=wChanging; curm_height+=hChanging;
				break;
			case EResizeFocus::NORTH_EAST:
				curY+=hChanging; curm_width+=wChanging; curm_height-=hChanging;
				break;
			case EResizeFocus::SOUTH_WEST:
				curX+=wChanging; curm_width-=wChanging; curm_height+=hChanging;
				break;
			default:
				break;
		}
		if(curm_width < 10 ||curm_height <10) return; //!minimal size
		dashRect->setRect(curX,curY,curm_width,curm_height);
	 }
	 else
		QGraphicsItem::mouseMoveEvent(event);
 }
 void CustomGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
 {
	 if(myMode == RESIZE)
	 {
		 m_width = dashRect->rect().width() +m_margin*2;
		 m_height = dashRect->rect().height() +m_margin*2;
		 qreal curX = dashRect->rect().left() - m_margin;
		 qreal curY = dashRect->rect().top() - m_margin;
		 QPointF curPos(curX,curY);
		 setPos(mapToScene(curPos));
		 //scene()->removeItem(dashRect);
		 delete dashRect;
	 }
	 else
	 {
		QGraphicsItem::mouseReleaseEvent(event);

	 }
 }


void CustomGraphicsItem::setPenColor(const QColor color)
 {
	m_penColor = color;
	setResizeBrush();
 }


void CustomGraphicsItem::setFillColor(const QColor color)
{
	m_fillColor = color;
}

void CustomGraphicsItem::setFont(QFont font)
{
	m_font = font;
}

void CustomGraphicsItem::setText(QString str)
{

	m_strText = str;

}

const CustomGraphicsItem &CustomGraphicsItem::operator=(const CustomGraphicsItem & right )
{
	
   m_width = right.m_width;
   m_height = right.m_height;
   m_margin = right.m_margin;
   m_type = right.m_type;
   m_pen = right.m_pen;
   m_fillColor = right.m_fillColor;
   myMode = right.myMode;

   setPos(right.pos());
  	
   return *this;
}


void CustomGraphicsItem::saveItem(QDomDocument doc,QDomElement root)
{
	QDomElement nextElement = doc.createElement("g");

	switch(m_type)
	{
		case BELLLINE_HORIZONTAL_GRAPHICSITEM:

		{
            nextElement.setAttribute("class",QString("%1").arg(BELLLINE_HORIZONTAL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QDomElement lastElement = doc.createElement("line");
			element.appendChild(lastElement);

            QDomAttr strokeAttrib = doc.createAttribute("stroke");
			QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QPointF pf = this->pos();
			QPointF point1(pf.x()+m_margin,pf.y()+m_height/2);
			QPointF point2(pf.x()+m_width-m_margin,pf.y()+m_height/2);
			

		    QDomAttr y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point1.y()));
			lastElement.setAttributeNode(y1Attrib);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point2.y()));
			lastElement.setAttributeNode(y2Attrib);

			QDomAttr x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point1.x()));
			lastElement.setAttributeNode(x1Attrib);

			QDomAttr x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point2.x()));
			lastElement.setAttributeNode(x2Attrib);

            root.appendChild(nextElement);
			break;
		}
		case BELLLINE_VERTICAL_GRAPHICSITEM:
		{ 
			nextElement.setAttribute("class",QString("%1").arg(BELLLINE_VERTICAL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QDomElement lastElement = doc.createElement("line");
			element.appendChild(lastElement);

            QDomAttr strokeAttrib = doc.createAttribute("stroke");
			QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QPointF pf = this->pos();
			QPointF point1(pf.x()+m_width/2,pf.y());
			QPointF point2(pf.x()+m_width/2,pf.y()+m_height);
		

		    QDomAttr y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point1.y()));
			lastElement.setAttributeNode(y1Attrib);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point2.y()));
			lastElement.setAttributeNode(y2Attrib);

			QDomAttr x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point1.x()));
			lastElement.setAttributeNode(x1Attrib);

			QDomAttr x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point2.x()));
			lastElement.setAttributeNode(x2Attrib);

            root.appendChild(nextElement);

			break;
		}
		case RECTANGLE_GRAPHICSITEM:
		{
		    nextElement.setAttribute("class",QString("%1").arg(RECTANGLE_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QDomElement lastElement = doc.createElement("rect");
			element.appendChild(lastElement);

			QPointF pf = this->pos();

            QDomAttr xattrib = doc.createAttribute("x");
			xattrib.setValue(QString("%1").arg(pf.x() + m_margin));
			lastElement.setAttributeNode(xattrib);

			QDomAttr yattrib = doc.createAttribute("y");
			yattrib.setValue(QString("%1").arg(pf.y() + m_margin));
			lastElement.setAttributeNode(yattrib);

			QDomAttr widthattrib = doc.createAttribute("width");
			widthattrib.setValue(QString("%1").arg(m_width-2*m_margin));
			lastElement.setAttributeNode(widthattrib);

			QDomAttr heightattrib = doc.createAttribute("height");
			heightattrib.setValue(QString("%1").arg(m_height-2*m_margin));
			lastElement.setAttributeNode(heightattrib);

			QDomAttr strokeAttrib = doc.createAttribute("stroke");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    value = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			lastElement.setAttributeNode(fillAttrib);

            root.appendChild(nextElement);
			break;
		}
		case STARRY_GRAPHICSITEM:
		{

            nextElement.setAttribute("class",QString("%1").arg(STARRY_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			
			QPointF pf = this->pos();
			QPointF point1(pf.x()+m_margin,pf.y()+m_margin);
			QPointF point2(pf.x()+m_width-m_margin,pf.y()+m_margin);
			QPointF point3(pf.x()+m_width/2,pf.y()+m_height/2);
			QPointF point4(pf.x()+m_width/2,pf.y()+m_height);

			QDomElement lastElement1 = doc.createElement("line");
			element.appendChild(lastElement1);

            QDomAttr strokeAttrib = doc.createAttribute("stroke");
			QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement1.setAttributeNode(strokeAttrib);

		    QDomAttr y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point1.y()));
			lastElement1.setAttributeNode(y1Attrib);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement1.setAttributeNode(swidthAttrib);

			QDomAttr y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point3.y()));
			lastElement1.setAttributeNode(y2Attrib);

			QDomAttr x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point1.x()));
			lastElement1.setAttributeNode(x1Attrib);

			QDomAttr x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point3.x()));
			lastElement1.setAttributeNode(x2Attrib);

			QDomElement lastElement2 = doc.createElement("line");
			element.appendChild(lastElement2);

            strokeAttrib = doc.createAttribute("stroke");
		    value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement2.setAttributeNode(strokeAttrib);

		    y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point2.y()));
			lastElement2.setAttributeNode(y1Attrib);

		    swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement2.setAttributeNode(swidthAttrib);

			y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point3.y()));
			lastElement2.setAttributeNode(y2Attrib);

		    x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point2.x()));
			lastElement2.setAttributeNode(x1Attrib);

		    x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point3.x()));
			lastElement2.setAttributeNode(x2Attrib);

			QDomElement lastElement3 = doc.createElement("line");
			element.appendChild(lastElement3);

            strokeAttrib = doc.createAttribute("stroke");
		    value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement3.setAttributeNode(strokeAttrib);

		    y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point3.y()));
			lastElement3.setAttributeNode(y1Attrib);

		    swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement3.setAttributeNode(swidthAttrib);

			y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point4.y()));
			lastElement3.setAttributeNode(y2Attrib);

		    x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point3.x()));
			lastElement3.setAttributeNode(x1Attrib);

		    x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point4.x()));
			lastElement3.setAttributeNode(x2Attrib);

            root.appendChild(nextElement);
			break;
		}
		case ELLIPSE_GRAPHICSITEM:
		{
            nextElement.setAttribute("class",QString("%1").arg(ELLIPSE_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QDomElement lastElement = doc.createElement("ellipse");
			element.appendChild(lastElement);

			QPointF pf = this->pos();

            QDomAttr cxattrib = doc.createAttribute("cx");
			cxattrib.setValue(QString("%1").arg(pf.x() + m_width/2));
			lastElement.setAttributeNode(cxattrib);

			QDomAttr cyattrib = doc.createAttribute("cy");
			cyattrib.setValue(QString("%1").arg(pf.y() + m_height/2));
			lastElement.setAttributeNode(cyattrib);

			QDomAttr rxattrib = doc.createAttribute("rx");
			rxattrib.setValue(QString("%1").arg((m_width-2*m_margin)/2));
			lastElement.setAttributeNode(rxattrib);

			QDomAttr ryattrib = doc.createAttribute("ry");
			ryattrib.setValue(QString("%1").arg((m_height-2*m_margin)/2));
			lastElement.setAttributeNode(ryattrib);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr strokeAttrib = doc.createAttribute("stroke");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    value = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			lastElement.setAttributeNode(fillAttrib);
			
			root.appendChild(nextElement);
			break;
		}
		case TRIANGLE_GRAPHICSITEM:
		{

            nextElement.setAttribute("class",QString("%1").arg(TRIANGLE_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QDomElement lastElement = doc.createElement("polygon");
			element.appendChild(lastElement);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr strokeAttrib = doc.createAttribute("stroke");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    value = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			lastElement.setAttributeNode(fillAttrib);

            QPointF pf = this->pos();
			QPointF point1(pf.x()+m_width/2,pf.y()+0);
			QPointF point2(pf.x()+0,pf.y()+m_height);
			QPointF point3(pf.x()+m_width,pf.y()+m_height);

			QDomAttr pointsAttrib = doc.createAttribute("points");
		    value = QString("%1 %2 %3 %4 %5 %6").arg(point1.x()).arg(point1.y())
				     .arg(point2.x()).arg(point2.y())
					 .arg(point3.x()).arg(point3.y());
			pointsAttrib.setValue(value);
			lastElement.setAttributeNode(pointsAttrib);

            root.appendChild(nextElement);
			break;
		}
		case CAPACTIOR_HORIZONTAL_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(CAPACTIOR_HORIZONTAL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			QPointF point1(pf.x()+m_margin,pf.y()+m_height/2);
			QPointF point2(pf.x()+m_margin+(m_width-2*m_margin)*1/3,pf.y()+m_height/2);
			QPointF point3(pf.x()+m_margin+(m_width-2*m_margin)/3,pf.y()+m_margin);
			QPointF point4(pf.x()+m_margin+(m_width-2*m_margin)/3,pf.y()+m_height-m_margin);
			QPointF point5(pf.x()+m_margin+(m_width-2*m_margin)*2/3,pf.y()+m_margin);
			QPointF point6(pf.x()+m_margin+(m_width-2*m_margin)*2/3,pf.y()+(m_height)/2);
			QPointF point7(pf.x()+m_margin+(m_width-2*m_margin)*2/3,pf.y()+(m_height-m_margin));
			QPointF point8(pf.x()+m_margin+(m_width-2*m_margin),pf.y()+(m_height)/2);

			for (int i = 0 ; i < 4 ; i++)
			{
				QDomElement lastElement = doc.createElement("line");
				element.appendChild(lastElement);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				
				QPointF point9;
				QPointF point10;

				switch(i)
				{
				case 0 : 
					{
						point9 = point1;
						point10 = point2;
						break;
					}
				case 1 : 
					{
						point9 = point3;
						point10 = point4;
						break;
					}
				case 2 : 
					{
						point9 = point5;
						point10 = point7;
						break;
					}
				case 3 : 
					{
						point9 = point6;
						point10 = point8;
						break;
					}
				}
		
				QDomAttr y1Attrib = doc.createAttribute("y1");
				y1Attrib.setValue(QString("%1").arg(point9.y()));
				lastElement.setAttributeNode(y1Attrib);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr y2Attrib = doc.createAttribute("y2");
				y2Attrib.setValue(QString("%1").arg(point10.y()));
				lastElement.setAttributeNode(y2Attrib);

				QDomAttr x1Attrib = doc.createAttribute("x1");
				x1Attrib.setValue(QString("%1").arg(point9.x()));
				lastElement.setAttributeNode(x1Attrib);

				QDomAttr x2Attrib = doc.createAttribute("x2");
				x2Attrib.setValue(QString("%1").arg(point10.x()));
				lastElement.setAttributeNode(x2Attrib);
			}
			root.appendChild(nextElement);
			break;
		}
		case CAPACTIOR_VERTICAL_GRAPHICSITEM:
		{
            nextElement.setAttribute("class",QString("%1").arg(CAPACTIOR_VERTICAL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			QPointF point1(pf.x()+m_width/2,pf.y()+m_margin);
			QPointF point2(pf.x()+m_margin+(m_width-2*m_margin)/2,pf.y()+(m_height-2*m_margin)/3+m_margin);
			QPointF point3(pf.x()+m_margin,pf.y()+(m_height-2*m_margin)/3+m_margin);
			QPointF point4(pf.x()+m_width-m_margin,pf.y()+(m_height-2*m_margin)/3+m_margin);
			QPointF point5(pf.x()+m_margin,pf.y()+(m_height-2*m_margin)*2/3+m_margin);
			QPointF point6(pf.x()+m_width-m_margin,pf.y()+(m_height-2*m_margin)*2/3+m_margin);
			QPointF point7(pf.x()+m_width/2,pf.y()+(m_height-2*m_margin)*2/3+m_margin);
			QPointF point8(pf.x()+m_width/2,pf.y()+m_height-m_margin);

			for (int i = 0 ; i < 4 ; i++)
			{
				QDomElement lastElement = doc.createElement("line");
				element.appendChild(lastElement);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				
				QPointF point9;
				QPointF point10;

				switch(i)
				{
				case 0 : 
					{
						point9 = point1;
						point10 = point2;
						break;
					}
				case 1 : 
					{
						point9 = point3;
						point10 = point4;
						break;
					}
				case 2 : 
					{
						point9 = point5;
						point10 = point6;
						break;
					}
				case 3 : 
					{
						point9 = point7;
						point10 = point8;
						break;
					}
				}
		
				QDomAttr y1Attrib = doc.createAttribute("y1");
				y1Attrib.setValue(QString("%1").arg(point9.y()));
				lastElement.setAttributeNode(y1Attrib);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr y2Attrib = doc.createAttribute("y2");
				y2Attrib.setValue(QString("%1").arg(point10.y()));
				lastElement.setAttributeNode(y2Attrib);

				QDomAttr x1Attrib = doc.createAttribute("x1");
				x1Attrib.setValue(QString("%1").arg(point9.x()));
				lastElement.setAttributeNode(x1Attrib);

				QDomAttr x2Attrib = doc.createAttribute("x2");
				x2Attrib.setValue(QString("%1").arg(point10.x()));
				lastElement.setAttributeNode(x2Attrib);
			}
			root.appendChild(nextElement);
			break;
		}
		case TERMINAL_HORIZONTAL_GRAPHICSITEM:
		{
			
			break;
		}
		case TERMINAL_VERTICAL_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(TERMINAL_VERTICAL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			QPointF point1(pf.x()+m_width/2,pf.y()+m_margin);
			QPointF point2(pf.x()+m_margin,pf.y()+m_height/2);
			QPointF point3(pf.x()+m_width/2,pf.y()+(m_height-m_margin)/2+(m_height-m_margin)/4);
			QPointF point4(pf.x()+m_width-m_margin,pf.y()+m_height/2);
			QPointF point5(pf.x()+m_width/2,pf.y()+m_height-m_margin);

            //画直线
			QDomElement lastElement = doc.createElement("line");
			element.appendChild(lastElement);

            QDomAttr strokeAttrib = doc.createAttribute("stroke");
			QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);


		    QDomAttr y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point1.y()));
			lastElement.setAttributeNode(y1Attrib);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point5.y()));
			lastElement.setAttributeNode(y2Attrib);

			QDomAttr x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point1.x()));
			lastElement.setAttributeNode(x1Attrib);

			QDomAttr x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point5.x()));
			lastElement.setAttributeNode(x2Attrib);

			//画多边形
            lastElement = doc.createElement("polygon");
			element.appendChild(lastElement);

		    swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			strokeAttrib = doc.createAttribute("stroke");
		    value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    value = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			lastElement.setAttributeNode(fillAttrib);

			QDomAttr pointsAttrib = doc.createAttribute("points");
		    value = QString("%1 %2 %3 %4 %5 %6").arg(point2.x()).arg(point2.y())
				     .arg(point3.x()).arg(point3.y())
					 .arg(point4.x()).arg(point4.y());
			pointsAttrib.setValue(value);
			lastElement.setAttributeNode(pointsAttrib);


            root.appendChild(nextElement);
			break;
		}
		case CONTAINER_HORIZONTAL_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(CONTAINER_HORIZONTAL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));


			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			QPointF point5(pf.x()+m_margin, pf.y()+m_height/2);
			QPointF point6(pf.x()+m_width-m_margin, pf.y()+m_height/2);
	

            //画直线
		    QDomElement lastElement = doc.createElement("line");
			element.appendChild(lastElement);

            QDomAttr strokeAttrib = doc.createAttribute("stroke");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

		    QDomAttr y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point5.y()));
			lastElement.setAttributeNode(y1Attrib);

		    QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point6.y()));
			lastElement.setAttributeNode(y2Attrib);

			QDomAttr x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point5.x()));
			lastElement.setAttributeNode(x1Attrib);

			QDomAttr x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point6.x()));
			lastElement.setAttributeNode(x2Attrib);

            //画秬形
		    lastElement = doc.createElement("rect");
			element.appendChild(lastElement);


            QDomAttr xattrib = doc.createAttribute("x");
			xattrib.setValue(QString("%1").arg(pf.x() + m_margin+(m_width-2*m_margin)/4));
			lastElement.setAttributeNode(xattrib);

			QDomAttr yattrib = doc.createAttribute("y");
			yattrib.setValue(QString("%1").arg(pf.y() + m_margin));
			lastElement.setAttributeNode(yattrib);

			QDomAttr widthattrib = doc.createAttribute("width");
			widthattrib.setValue(QString("%1").arg((m_width-2*m_margin)*2/4));
			lastElement.setAttributeNode(widthattrib);

			QDomAttr heightattrib = doc.createAttribute("height");
			heightattrib.setValue(QString("%1").arg(m_height-2*m_margin));
			lastElement.setAttributeNode(heightattrib);

		    strokeAttrib = doc.createAttribute("stroke");
		    value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

		    swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    value = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			lastElement.setAttributeNode(fillAttrib);

            root.appendChild(nextElement);
			break;
		}
		case CONTAINER_VERTICAL_GRAPHICSITEM:
		{
            
			nextElement.setAttribute("class",QString("%1").arg(CONTAINER_VERTICAL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));


			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			QPointF point5(pf.x()+m_width/2, pf.y()+m_margin);
			QPointF point6(pf.x()+m_width/2, pf.y()+m_height-m_margin);

            //画直线
		    QDomElement lastElement = doc.createElement("line");
			element.appendChild(lastElement);

            QDomAttr strokeAttrib = doc.createAttribute("stroke");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

		    QDomAttr y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point5.y()));
			lastElement.setAttributeNode(y1Attrib);

		    QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point6.y()));
			lastElement.setAttributeNode(y2Attrib);

			QDomAttr x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point5.x()));
			lastElement.setAttributeNode(x1Attrib);

			QDomAttr x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point6.x()));
			lastElement.setAttributeNode(x2Attrib);

            //画秬形
		    lastElement = doc.createElement("rect");
			element.appendChild(lastElement);


            QDomAttr xattrib = doc.createAttribute("x");
			xattrib.setValue(QString("%1").arg(pf.x() + m_margin));
			lastElement.setAttributeNode(xattrib);

			QDomAttr yattrib = doc.createAttribute("y");
			yattrib.setValue(QString("%1").arg(pf.y() + (m_height-2*m_margin)/4+m_margin));
			lastElement.setAttributeNode(yattrib);

			QDomAttr widthattrib = doc.createAttribute("width");
			widthattrib.setValue(QString("%1").arg(m_width-2*m_margin));
			lastElement.setAttributeNode(widthattrib);

			QDomAttr heightattrib = doc.createAttribute("height");
			heightattrib.setValue(QString("%1").arg((m_height-2*m_margin)/2));
			lastElement.setAttributeNode(heightattrib);

		    strokeAttrib = doc.createAttribute("stroke");
		    value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

		    swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    value = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			lastElement.setAttributeNode(fillAttrib);

            root.appendChild(nextElement);
			break;
		}
		case KNIVESSWITCH_HORIZONTAL_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(KNIVESSWITCH_HORIZONTAL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			qreal spx = pf.x()+m_margin;
			qreal spy = pf.y()+m_margin;
			qreal epx = pf.x()+m_width-m_margin;
			qreal epy = pf.y()+ m_height-m_margin;
			qreal w,h;
			w = epx-spx;
			h = epy-spy;
			qreal spxw9c3 = spx+w*3/9;
			qreal spxw9c6 = spx+w*6/9;
			qreal epyh6c1 = epy-h*1/6;
			qreal epyh6c3 = epy-h*3/6;


			for (int i = 0 ; i < 4 ; i++)
			{
				QDomElement lastElement = doc.createElement("line");
				element.appendChild(lastElement);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				
				QPointF point1;
				QPointF point2;

				switch(i)
				{
				case 0 : 
					{
						point1.setX(spx);
						point1.setY(epyh6c1);
						point2.setX(spxw9c3);
						point2.setY(epyh6c1);
						
						break;
					}
				case 1 : 
					{
						point1.setX(spxw9c6);
						point1.setY(epyh6c1);
						point2.setX(epx);
						point2.setY(epyh6c1);
						break;
					}
				case 2 : 
					{
						point1.setX(spxw9c3);
						point1.setY(spy);
						point2.setX(spxw9c6);
						point2.setY(epyh6c1);
						break;
					}
				case 3 : 
					{
						point1.setX(spxw9c3);
						point1.setY(epy);
						point2.setX(spxw9c3);
						point2.setY(epyh6c3);
						break;
					}
				}
		
				QDomAttr y1Attrib = doc.createAttribute("y1");
				y1Attrib.setValue(QString("%1").arg(point1.y()));
				lastElement.setAttributeNode(y1Attrib);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr y2Attrib = doc.createAttribute("y2");
				y2Attrib.setValue(QString("%1").arg(point2.y()));
				lastElement.setAttributeNode(y2Attrib);

				QDomAttr x1Attrib = doc.createAttribute("x1");
				x1Attrib.setValue(QString("%1").arg(point1.x()));
				lastElement.setAttributeNode(x1Attrib);

				QDomAttr x2Attrib = doc.createAttribute("x2");
				x2Attrib.setValue(QString("%1").arg(point2.x()));
				lastElement.setAttributeNode(x2Attrib);
			}


			root.appendChild(nextElement);
			break;
		}
		case KNIVESSWITCH_VERTICALL_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(KNIVESSWITCH_VERTICALL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			qreal spx = pf.x()+m_margin;
			qreal spy = pf.y()+m_margin;
			qreal epx = pf.x()+m_width-m_margin;
			qreal epy = pf.y()+m_height-m_margin;
			qreal w,h;
			w = epx-spx;
			h = epy-spy;
			qreal spxw6 = spx+w/6;
			qreal spxw9c6 = spx+w*6/9;
			qreal epxw6 = epx-w/6;
			qreal epxw9c6 = epx-w*6/9;
			qreal spyh3 = spy+h/3;
			qreal epyh9c4 = epy-h*4/9;


			for (int i = 0 ; i < 4 ; i++)
			{
				QDomElement lastElement = doc.createElement("line");
				element.appendChild(lastElement);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				
				QPointF point1;
				QPointF point2;

				switch(i)
				{
				case 0 : 
					{
						point1.setX(epxw6);
						point1.setY(spy);
						point2.setX(epxw6);
						point2.setY(spyh3);
						
						break;
					}
				case 1 : 
					{
						point1.setX(epx);
						point1.setY(spyh3);
						point2.setX(epxw9c6);
						point2.setY(spyh3);
						break;
					}
				case 2 : 
					{
						point1.setX(epxw6);
						point1.setY(epy);
						point2.setX(epxw6);
						point2.setY(epyh9c4);
						break;
					}
				case 3 : 
					{
						point1.setX(epxw6);
						point1.setY(epyh9c4);
						point2.setX(spx);
						point2.setY(spyh3);
						break;
					}
				}
		
				QDomAttr y1Attrib = doc.createAttribute("y1");
				y1Attrib.setValue(QString("%1").arg(point1.y()));
				lastElement.setAttributeNode(y1Attrib);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr y2Attrib = doc.createAttribute("y2");
				y2Attrib.setValue(QString("%1").arg(point2.y()));
				lastElement.setAttributeNode(y2Attrib);

				QDomAttr x1Attrib = doc.createAttribute("x1");
				x1Attrib.setValue(QString("%1").arg(point1.x()));
				lastElement.setAttributeNode(x1Attrib);

				QDomAttr x2Attrib = doc.createAttribute("x2");
				x2Attrib.setValue(QString("%1").arg(point2.x()));
				lastElement.setAttributeNode(x2Attrib);
			}


			root.appendChild(nextElement);
			break;
		}
		case BOTTOMLINE_HORIZONTAL_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(BOTTOMLINE_HORIZONTAL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			QPointF point1(pf.x()+m_margin,pf.y()+m_height/2);
			QPointF point2(pf.x()+m_margin+(m_width-2*m_margin)/2,pf.y()+m_height/2);
			QPointF point3(pf.x()+m_width/2,pf.y()+m_margin);
			QPointF point4(pf.x()+m_width/2,pf.y()+m_height-m_margin);
			QPointF point5(pf.x()+m_margin+(m_width-2*m_margin)*3/4,pf.y()+m_height/2 -(m_height-2*m_margin)/4);
			QPointF point6(pf.x()+m_margin+(m_width-2*m_margin)*3/4,pf.y()+m_height/2 +(m_height-2*m_margin)/4);
			QPointF point7(pf.x()+m_width-m_margin,pf.y()+m_height/2 -(m_height-2*m_margin)/9);
			QPointF point8(pf.x()+m_width-m_margin,pf.y()+m_height/2 +(m_height-2*m_margin)/9);


			for (int i = 0 ; i < 4 ; i++)
			{
				QDomElement lastElement = doc.createElement("line");
				element.appendChild(lastElement);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				
				QPointF point9;
				QPointF point10;

				switch(i)
				{
				case 0 : 
					{
						point9 = point1;
						point10 = point2;
						
						break;
					}
				case 1 : 
					{
						point9 = point3;
						point10 = point4;
						break;
					}
				case 2 : 
					{
						point9 = point5;
						point10 = point6;
						break;
					}
				case 3 : 
					{
						point9 = point7;
						point10 = point8;
						break;
					}
				}
		
				QDomAttr y1Attrib = doc.createAttribute("y1");
				y1Attrib.setValue(QString("%1").arg(point9.y()));
				lastElement.setAttributeNode(y1Attrib);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr y2Attrib = doc.createAttribute("y2");
				y2Attrib.setValue(QString("%1").arg(point10.y()));
				lastElement.setAttributeNode(y2Attrib);

				QDomAttr x1Attrib = doc.createAttribute("x1");
				x1Attrib.setValue(QString("%1").arg(point9.x()));
				lastElement.setAttributeNode(x1Attrib);

				QDomAttr x2Attrib = doc.createAttribute("x2");
				x2Attrib.setValue(QString("%1").arg(point10.x()));
				lastElement.setAttributeNode(x2Attrib);
			}


			root.appendChild(nextElement);
			break;
		}
		case BOTTOMLINE_VERTICALL_GRAPHICSITEM:
		{

			nextElement.setAttribute("class",QString("%1").arg(BOTTOMLINE_VERTICALL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			QPointF point1(pf.x()+m_width/2,pf.y()+m_margin);
			QPointF point2(pf.x()+m_width/2,pf.y()+m_height/2);
			QPointF point3(pf.x()+m_margin,pf.y()+m_height/2);
			QPointF point4(pf.x()+m_width-m_margin,pf.y()+m_height/2);
			QPointF point5(pf.x()+m_width/4,pf.y()+m_height/2 +(m_height-2*m_margin)/4);
			QPointF point6(pf.x()+m_width*3/4,pf.y()+m_height/2 +(m_height-2*m_margin)/4);
			QPointF point7(pf.x()+m_width/2-m_width/8,pf.y()+m_height-m_margin);
			QPointF point8(pf.x()+m_width/2+m_width/8,pf.y()+m_height-m_margin);


			for (int i = 0 ; i < 4 ; i++)
			{
				QDomElement lastElement = doc.createElement("line");
				element.appendChild(lastElement);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				
				QPointF point9;
				QPointF point10;

				switch(i)
				{
				case 0 : 
					{
						point9 = point1;
						point10 = point2;
						
						break;
					}
				case 1 : 
					{
						point9 = point3;
						point10 = point4;
						break;
					}
				case 2 : 
					{
						point9 = point5;
						point10 = point6;
						break;
					}
				case 3 : 
					{
						point9 = point7;
						point10 = point8;
						break;
					}
				}
		
				QDomAttr y1Attrib = doc.createAttribute("y1");
				y1Attrib.setValue(QString("%1").arg(point9.y()));
				lastElement.setAttributeNode(y1Attrib);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr y2Attrib = doc.createAttribute("y2");
				y2Attrib.setValue(QString("%1").arg(point10.y()));
				lastElement.setAttributeNode(y2Attrib);

				QDomAttr x1Attrib = doc.createAttribute("x1");
				x1Attrib.setValue(QString("%1").arg(point9.x()));
				lastElement.setAttributeNode(x1Attrib);

				QDomAttr x2Attrib = doc.createAttribute("x2");
				x2Attrib.setValue(QString("%1").arg(point10.x()));
				lastElement.setAttributeNode(x2Attrib);
			}


			root.appendChild(nextElement);
			break;
		}
		case GENERATRIX_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(GENERATRIX_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QDomElement lastElement = doc.createElement("rect");
			element.appendChild(lastElement);

			QPointF pf = this->pos();

            QDomAttr xattrib = doc.createAttribute("x");
			xattrib.setValue(QString("%1").arg(pf.x() + m_margin));
			lastElement.setAttributeNode(xattrib);

			QDomAttr yattrib = doc.createAttribute("y");
			yattrib.setValue(QString("%1").arg(pf.y() + m_margin));
			lastElement.setAttributeNode(yattrib);

			QDomAttr widthattrib = doc.createAttribute("width");
			widthattrib.setValue(QString("%1").arg(m_width-2*m_margin));
			lastElement.setAttributeNode(widthattrib);

			QDomAttr heightattrib = doc.createAttribute("height");
			heightattrib.setValue(QString("%1").arg(m_height-2*m_margin));
			lastElement.setAttributeNode(heightattrib);

			QDomAttr strokeAttrib = doc.createAttribute("stroke");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    value = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			lastElement.setAttributeNode(fillAttrib);

			root.appendChild(nextElement);
			break;
		}
		case CURRENTINDUCTANCE_LEFT_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(CURRENTINDUCTANCE_LEFT_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			qreal x1,y1,x2,y2;
			x1=pf.x();
			y1=pf.y();
			x2=pf.x()+m_width;
			y2=pf.y()+m_height;

			qreal h = y2-y1;			
			qreal h4 = h/4;
			qreal rw = m_width;//m_Rect.m_width();
			qreal yh4 = (y2-y1)/4;

			for (int i= 0 ; i < 4 ; i++)
			{
				//画孤
				QDomElement lastElement = doc.createElement("path");
				element.appendChild(lastElement);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				QDomAttr fillAttrib = doc.createAttribute("fill");
				fillAttrib.setValue(QString("none"));
				lastElement.setAttributeNode(fillAttrib);


			   QDomAttr dAttrib = doc.createAttribute("d");
			   switch(i)
			   {
			    case 0:
				   {
					  value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x1+(x2-x1)/2)       //移动X,Y的位置
							   .arg(y1)
							   .arg((x2-(x1+(x2-x1)/2)))  //半径
							   .arg(m_height/4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(0)			 //使用曲线的下段
							   .arg(x1+(x2-x1)/2)
							   .arg(y1+yh4);
					   break;
				   }
			    case 1:
				   {
				     value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x1+(x2-x1)/2)       //移动X,Y的位置
							   .arg(y1+yh4)
							   .arg((x2-(x1+(x2-x1)/2)))  //半径
							   .arg(m_height/4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(0)			 //使用曲线的下段
							   .arg(x1+(x2-x1)/2)
							   .arg(y1+2*yh4);
					   break;
				   }
			    case 2:
				   {
				      value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x1+(x2-x1)/2)       //移动X,Y的位置
							   .arg(y1+2*yh4)
							   .arg((x2-(x1+(x2-x1)/2)))  //半径
							   .arg(m_height/4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(0)			 //使用曲线的下段
							   .arg(x1+(x2-x1)/2)
							   .arg(y1+3*yh4);
					   break;
				   }
			    case 3:
				   {
				      value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x1+(x2-x1)/2)       //移动X,Y的位置
							   .arg(y1+3*yh4)
							   .arg((x2-(x1+(x2-x1)/2)))  //半径
							   .arg(m_height/4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(0)			 //使用曲线的下段
							   .arg(x1+(x2-x1)/2)
							   .arg(y1+4*yh4);
					   break;
				   }
			   }
			  			   
				   
			   dAttrib.setValue(value);
			   lastElement.setAttributeNode(dAttrib);

			}

            //画直线
		   QPointF point1(x1+(x2-x1)/2, y1-yh4/2);
		   QPointF point2(x1+(x2-x1)/2, y2+yh4/2);
		   QPointF point3(x1+(x2-x1)/2, y1);
		   QPointF point4(x2, y1);
		   QPointF point5(x1+(x2-x1)/2, y2);
		   QPointF point6(x2, y2);
		  

		   for (int i = 0 ; i < 3 ; i++)
			{
				QDomElement lastElement = doc.createElement("line");
				element.appendChild(lastElement);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				
				QPointF point13;
				QPointF point14;

				switch(i)
				{
				case 0 : 
					{
						point13 = point1;
						point14 = point2;
						
						break;
					}
				case 1 : 
					{
						point13 = point3;
						point14 = point4;
						break;
					}
				case 2 : 
					{
						point13 = point5;
						point14 = point6;
						break;
					}

				}
		
				QDomAttr y1Attrib = doc.createAttribute("y1");
				y1Attrib.setValue(QString("%1").arg(point13.y()));
				lastElement.setAttributeNode(y1Attrib);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr y2Attrib = doc.createAttribute("y2");
				y2Attrib.setValue(QString("%1").arg(point14.y()));
				lastElement.setAttributeNode(y2Attrib);

				QDomAttr x1Attrib = doc.createAttribute("x1");
				x1Attrib.setValue(QString("%1").arg(point13.x()));
				lastElement.setAttributeNode(x1Attrib);

				QDomAttr x2Attrib = doc.createAttribute("x2");
				x2Attrib.setValue(QString("%1").arg(point14.x()));
				lastElement.setAttributeNode(x2Attrib);
			}

			
		
			
			root.appendChild(nextElement);
			break;
		}
		case CURRENTINDUCTANCE_RIGHT_GRAPHICSITEM:
		{
					
			nextElement.setAttribute("class",QString("%1").arg(CURRENTINDUCTANCE_RIGHT_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			qreal x1,y1,x2,y2;
			x1=pf.x();
			y1=pf.y();
			x2=pf.x()+m_width;
			y2=pf.y()+m_height;

			qreal h = y2-y1;			
			qreal h4 = h/4;
			qreal rw = m_width;//m_Rect.m_width();
			qreal yh4 = (y2-y1)/4;

			for (int i= 0 ; i < 4 ; i++)
			{
				//画孤
				QDomElement lastElement = doc.createElement("path");
				element.appendChild(lastElement);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				QDomAttr fillAttrib = doc.createAttribute("fill");
				fillAttrib.setValue(QString("none"));
				lastElement.setAttributeNode(fillAttrib);


			   QDomAttr dAttrib = doc.createAttribute("d");
			   switch(i)
			   {
			    case 0:
				   {
					  value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x1+(x2-x1)/2)       //移动X,Y的位置
							   .arg(y1)
							   .arg((x2-(x1+(x2-x1)/2)))  //半径
							   .arg(m_height/4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(1)			 //使用曲线的下段
							   .arg(x1+(x2-x1)/2)
							   .arg(y1+yh4);
					   break;
				   }
			    case 1:
				   {
				     value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x1+(x2-x1)/2)       //移动X,Y的位置
							   .arg(y1+yh4)
							   .arg((x2-(x1+(x2-x1)/2)))  //半径
							   .arg(m_height/4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(1)			 //使用曲线的下段
							   .arg(x1+(x2-x1)/2)
							   .arg(y1+2*yh4);
					   break;
				   }
			    case 2:
				   {
				      value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x1+(x2-x1)/2)       //移动X,Y的位置
							   .arg(y1+2*yh4)
							   .arg((x2-(x1+(x2-x1)/2)))  //半径
							   .arg(m_height/4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(1)			 //使用曲线的下段
							   .arg(x1+(x2-x1)/2)
							   .arg(y1+3*yh4);
					   break;
				   }
			    case 3:
				   {
				      value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x1+(x2-x1)/2)       //移动X,Y的位置
							   .arg(y1+3*yh4)
							   .arg((x2-(x1+(x2-x1)/2)))  //半径
							   .arg(m_height/4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(0)			 //使用椭圆长轴部分
							   .arg(1)			 //使用曲线的下段
							   .arg(x1+(x2-x1)/2)
							   .arg(y1+4*yh4);
					   break;
				   }
			   }
			  			   
				   
			   dAttrib.setValue(value);
			   lastElement.setAttributeNode(dAttrib);

			}

		   QPointF point1(x1+(x2-x1)/2, y1-yh4/2);
		   QPointF point2(x1+(x2-x1)/2, y2+yh4/2);
		   QPointF point3(x1, y1);
		   QPointF point4(x1+(x2-x1)/2, y1);
		   QPointF point5(x1, y2);
		   QPointF point6(x1+(x2-x1)/2, y2);
		  

		   for (int i = 0 ; i < 3 ; i++)
			{
				QDomElement lastElement = doc.createElement("line");
				element.appendChild(lastElement);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				
				QPointF point13;
				QPointF point14;

				switch(i)
				{
				case 0 : 
					{
						point13 = point1;
						point14 = point2;
						
						break;
					}
				case 1 : 
					{
						point13 = point3;
						point14 = point4;
						break;
					}
				case 2 : 
					{
						point13 = point5;
						point14 = point6;
						break;
					}

				}
		
				QDomAttr y1Attrib = doc.createAttribute("y1");
				y1Attrib.setValue(QString("%1").arg(point13.y()));
				lastElement.setAttributeNode(y1Attrib);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr y2Attrib = doc.createAttribute("y2");
				y2Attrib.setValue(QString("%1").arg(point14.y()));
				lastElement.setAttributeNode(y2Attrib);

				QDomAttr x1Attrib = doc.createAttribute("x1");
				x1Attrib.setValue(QString("%1").arg(point13.x()));
				lastElement.setAttributeNode(x1Attrib);

				QDomAttr x2Attrib = doc.createAttribute("x2");
				x2Attrib.setValue(QString("%1").arg(point14.x()));
				lastElement.setAttributeNode(x2Attrib);
			}

			
			root.appendChild(nextElement);

			break;
		}
		case VOLTAGEINDUCTANCE_HORIZONTAL_GRAPHICSITEM:
		{

			nextElement.setAttribute("class",QString("%1").arg(VOLTAGEINDUCTANCE_HORIZONTAL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			qreal x1,y1,x2,y2;
			x1=pf.x()+0;
			y1=pf.y()+0;
			x2=pf.x()+m_width;
			y2=pf.y()+m_height;
			qreal h=y2-y1;
			qreal h4 =h/4;
			qreal rw = m_width;
			qreal yh4 = (y2-y1)/4;

			for (int i= 0 ; i < 8 ; i++)
			{
				//画孤
				QDomElement lastElement = doc.createElement("path");
				element.appendChild(lastElement);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				QDomAttr fillAttrib = doc.createAttribute("fill");
				fillAttrib.setValue(QString("none"));
				lastElement.setAttributeNode(fillAttrib);


			   QDomAttr dAttrib = doc.createAttribute("d");
			   switch(i)
			   {
			    case 0:
				   {
					  value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x1)       //移动X,Y的位置
							   .arg(y1)
							   .arg(rw/2)  //半径
							   .arg(h4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(1)			 //使用曲线的下段
							   .arg(x1)
							   .arg(y1+yh4);
					   break;
				   }
			    case 1:
				   {
				     value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x1)       //移动X,Y的位置
							   .arg(y1+yh4)
							   .arg(rw/2)  //半径
							   .arg(h4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(1)			 //使用曲线的下段
							   .arg(x1)
							   .arg(y1+2*yh4);
					   break;
				   }
			    case 2:
				   {
				      value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x1)       //移动X,Y的位置
							   .arg(y1+2*yh4)
							   .arg(rw/2)  //半径
							   .arg(h4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(1)			 //使用曲线的下段
							   .arg(x1)
							   .arg(y1+3*yh4);
					   break;
				   }
			    case 3:
				   {
				      value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x1)       //移动X,Y的位置
							   .arg(y1+3*yh4)
							   .arg(rw/2)  //半径
							   .arg(h4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(1)			 //使用曲线的下段
							   .arg(x1)
							   .arg(y1+4*yh4);
					   break;
				   }
				case 4:
				   {
				      value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x2)       //移动X,Y的位置
							   .arg(y1)
							   .arg(rw/2)  //半径
							   .arg(h4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(0)			 //使用曲线的下段
							   .arg(x2)
							   .arg(y1+1*yh4);
					   break;
				   }
				case 5:
				   {
				      value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x2)       //移动X,Y的位置
							   .arg(y1+1*yh4)
							   .arg(rw/2)  //半径
							   .arg(h4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(0)			 //使用曲线的下段
							   .arg(x2)
							   .arg(y1+2*yh4);
					   break;
				   }
			    case 6:
				   {
				      value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x2)       //移动X,Y的位置
							   .arg(y1+2*yh4)
							   .arg(rw/2)  //半径
							   .arg(h4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(0)			 //使用曲线的下段
							   .arg(x2)
							   .arg(y1+3*yh4);
					   break;
				   }
			    case 7:
				   {
				      value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
							   .arg(x2)       //移动X,Y的位置
							   .arg(y1+3*yh4)
							   .arg(rw/2)  //半径
							   .arg(h4/2) //半径
							   .arg(0)			 //没有旋度
							   .arg(1)			 //使用椭圆长轴部分
							   .arg(0)			 //使用曲线的下段
							   .arg(x2)
							   .arg(y1+4*yh4);
					   break;
				   }			 

			   }
			  			   
				   
			   dAttrib.setValue(value);
			   lastElement.setAttributeNode(dAttrib);

			}

			root.appendChild(nextElement);
			break;
		}
		case VOLTAGEINDUCTANCE_VERTICALL_GRAPHICSITEM:
		{
			
			break;
		}
		case BREAKER_HORIZONTAL_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(BREAKER_HORIZONTAL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			//画直线
            QDomElement lastElement = doc.createElement("line");
			element.appendChild(lastElement);     

			QPointF pf = this->pos();

			QPointF point1(pf.x()+m_margin,pf.y()+m_height/2);
			QPointF point2(pf.x()+m_width-m_margin,pf.y()+m_height/2);

		    QDomAttr y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point1.y()));
			lastElement.setAttributeNode(y1Attrib);

			QDomAttr strokeAttrib = doc.createAttribute("stroke");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point2.y()));
			lastElement.setAttributeNode(y2Attrib);

			QDomAttr x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point1.x()));
			lastElement.setAttributeNode(x1Attrib);

			QDomAttr x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point2.x()));
			lastElement.setAttributeNode(x2Attrib);

			//画矩形
			lastElement = doc.createElement("rect");
			element.appendChild(lastElement);

					
            QDomAttr xattrib = doc.createAttribute("x");
			xattrib.setValue(QString("%1").arg(pf.x() +m_margin+(m_width-2*m_margin)/4));
			lastElement.setAttributeNode(xattrib);

			QDomAttr yattrib = doc.createAttribute("y");
			yattrib.setValue(QString("%1").arg(pf.y() + m_margin));
			lastElement.setAttributeNode(yattrib);

			QDomAttr widthattrib = doc.createAttribute("width");
			widthattrib.setValue(QString("%1").arg((m_width-2*m_margin)*2/4));
			lastElement.setAttributeNode(widthattrib);

			QDomAttr heightattrib = doc.createAttribute("height");
			heightattrib.setValue(QString("%1").arg(m_height-2*m_margin));
			lastElement.setAttributeNode(heightattrib);

			strokeAttrib = doc.createAttribute("stroke");
		    value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			lastElement.setAttributeNode(fillAttrib);			

			root.appendChild(nextElement);
			break;
		}
		case BREAKER_VERTICAL_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(BREAKER_VERTICAL_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			//画直线
            QDomElement lastElement = doc.createElement("line");
			element.appendChild(lastElement);     

			QPointF pf = this->pos();
			QPointF point1(pf.x()+m_width/2,pf.y()+m_margin);
			QPointF point2(pf.x()+m_width/2,pf.y()+m_height-m_margin);

		    QDomAttr y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point1.y()));
			lastElement.setAttributeNode(y1Attrib);

			QDomAttr strokeAttrib = doc.createAttribute("stroke");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point2.y()));
			lastElement.setAttributeNode(y2Attrib);

			QDomAttr x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point1.x()));
			lastElement.setAttributeNode(x1Attrib);

			QDomAttr x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point2.x()));
			lastElement.setAttributeNode(x2Attrib);

			//画矩形
			lastElement = doc.createElement("rect");
			element.appendChild(lastElement);

					
            QDomAttr xattrib = doc.createAttribute("x");
			xattrib.setValue(QString("%1").arg(pf.x() + m_margin));
			lastElement.setAttributeNode(xattrib);

			QDomAttr yattrib = doc.createAttribute("y");
			yattrib.setValue(QString("%1").arg(pf.y() + (m_height-2*m_margin)/4+m_margin));
			lastElement.setAttributeNode(yattrib);

			QDomAttr widthattrib = doc.createAttribute("width");
			widthattrib.setValue(QString("%1").arg(m_width-2*m_margin));
			lastElement.setAttributeNode(widthattrib);

			QDomAttr heightattrib = doc.createAttribute("height");
			heightattrib.setValue(QString("%1").arg((m_height-2*m_margin)/2));
			lastElement.setAttributeNode(heightattrib);

			strokeAttrib = doc.createAttribute("stroke");
		    value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			lastElement.setAttributeNode(fillAttrib);

			root.appendChild(nextElement);
			
			break;
		}
		case SPLITREACTOR_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(SPLITREACTOR_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			qreal x1,y1,x2,y2;
			x1= pf.x()+0;
			y1= pf.y()+0;
			x2= pf.x()+m_width;
			y2= pf.y()+m_height;

			int startAngle ;
			int spanAngle ;
			
			qreal w = x2-x1;
			qreal h = y2-y1;
			qreal w4 = w/4;
			qreal w8 = w/8;
			qreal h3 = h/3;
			qreal h16 = h/16;
			qreal h20 = h/20;
			

			QDomElement lastElement = doc.createElement("path");
			element.appendChild(lastElement);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr strokeAttrib = doc.createAttribute("stroke");
			QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
			fillAttrib.setValue(QString("none"));
			lastElement.setAttributeNode(fillAttrib);


           QDomAttr dAttrib = doc.createAttribute("d");
		   value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
			   .arg(x1+w4)       //移动X,Y的位置
			   .arg(y2-h16)
			   .arg(m_height/2)  //半径
			   .arg(m_width/2)   //半径
			   .arg(0)			 //没有旋度
			   .arg(1)			 //使用椭圆长轴部分
			   .arg(1)			 //使用曲线的下段
			   .arg(x1+3*w4)
			   .arg(y2-h16);			   
			   
		   dAttrib.setValue(value);
		   lastElement.setAttributeNode(dAttrib);

		   //画直线
		   QPointF point1(x1+w4,y2-h16);
		   QPointF point2(x1+w4,y2-h3);
		   QPointF point3(x1+w4,y2-h3);
		   QPointF point4(x1-w8,y2-h3);
		   QPointF point5(x1-w8,y2-h3);
		   QPointF point6(x1-w8,y2+h20);
		   QPointF point7(x1+3*w4,y2-h16);
		   QPointF point8(x1+3*w4,y2-h3);
		   QPointF point9(x1+3*w4,y2-h3);
		   QPointF point10(x2+w8,y2-h3);
		   QPointF point11(x2+w8,y2-h3);
		   QPointF point12(x2+w8,y2+h20);

		   for (int i = 0 ; i < 6 ; i++)
			{
				QDomElement lastElement = doc.createElement("line");
				element.appendChild(lastElement);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				
				QPointF point13;
				QPointF point14;

				switch(i)
				{
				case 0 : 
					{
						point13 = point1;
						point14 = point2;
						
						break;
					}
				case 1 : 
					{
						point13 = point3;
						point14 = point4;
						break;
					}
				case 2 : 
					{
						point13 = point5;
						point14 = point6;
						break;
					}
				case 3 : 
					{
						point13 = point7;
						point14 = point8;
						break;
					}
               case 4 : 
					{
						point13 = point9;
						point14 = point10;
						break;
					}
				case 5 : 
					{
						point13 = point11;
						point14 = point12;
						break;
					}

				}
		
				QDomAttr y1Attrib = doc.createAttribute("y1");
				y1Attrib.setValue(QString("%1").arg(point13.y()));
				lastElement.setAttributeNode(y1Attrib);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr y2Attrib = doc.createAttribute("y2");
				y2Attrib.setValue(QString("%1").arg(point14.y()));
				lastElement.setAttributeNode(y2Attrib);

				QDomAttr x1Attrib = doc.createAttribute("x1");
				x1Attrib.setValue(QString("%1").arg(point13.x()));
				lastElement.setAttributeNode(x1Attrib);

				QDomAttr x2Attrib = doc.createAttribute("x2");
				x2Attrib.setValue(QString("%1").arg(point14.x()));
				lastElement.setAttributeNode(x2Attrib);
			}



			root.appendChild(nextElement);
			break;
		}
		case REACTOR_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(REACTOR_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			qreal x1,y1,x2,y2;
			QPointF pf = this->pos();		
			x1= pf.x();
			y1= pf.y();
			x2= pf.x()+m_width;
			y2= pf.y()+m_height;
			

			//画孤
			QDomElement lastElement = doc.createElement("path");
			element.appendChild(lastElement);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr strokeAttrib = doc.createAttribute("stroke");
			QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
			fillAttrib.setValue(QString("none"));
			lastElement.setAttributeNode(fillAttrib);


           QDomAttr dAttrib = doc.createAttribute("d");
		   value = QString("M%1,%2 A%3,%4 %5 %6 %7 %8,%9")
			   .arg(x1)           //移动X,Y的位置
			   .arg(y1+(y2-y1)/2)
			   .arg(m_width/2)    //半径
			   .arg(m_height/2)   //半径
			   .arg(0)			 //没有旋度
			   .arg(1)			 //使用椭圆长轴部分
			   .arg(1)			 //使用曲线的下段
			   .arg(x1+(x2-x1)/2)
			   .arg(y2);			   
			   
		   dAttrib.setValue(value);
		   lastElement.setAttributeNode(dAttrib);

		   //画三条直线
		   QPointF point1(x1,y1+(y2-y1)/2);
		   QPointF point2(x1+(x2-x1)/2,y1+(y2-y1)/2);
		   QPointF point3(x1+(x2-x1)/2,y1+(y2-y1)/2);
		   QPointF point4(x1+(x2-x1)/2,y1-(y2-y1)/3);
		   QPointF point5(x1+(x2-x1)/2,y2);
		   QPointF point6(x1+(x2-x1)/2,y2+(y2-y1)/3);

		   for (int i = 0 ; i < 3 ; i++)
			{
				QDomElement lastElement = doc.createElement("line");
				element.appendChild(lastElement);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				
				QPointF point13;
				QPointF point14;

				switch(i)
				{
				case 0 : 
					{
						point13 = point1;
						point14 = point2;
						
						break;
					}
				case 1 : 
					{
						point13 = point3;
						point14 = point4;
						break;
					}
				case 2 : 
					{
						point13 = point5;
						point14 = point6;
						break;
					}
				}
		
				QDomAttr y1Attrib = doc.createAttribute("y1");
				y1Attrib.setValue(QString("%1").arg(point13.y()));
				lastElement.setAttributeNode(y1Attrib);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr y2Attrib = doc.createAttribute("y2");
				y2Attrib.setValue(QString("%1").arg(point14.y()));
				lastElement.setAttributeNode(y2Attrib);

				QDomAttr x1Attrib = doc.createAttribute("x1");
				x1Attrib.setValue(QString("%1").arg(point13.x()));
				lastElement.setAttributeNode(x1Attrib);

				QDomAttr x2Attrib = doc.createAttribute("x2");
				x2Attrib.setValue(QString("%1").arg(point14.x()));
				lastElement.setAttributeNode(x2Attrib);
			}

			root.appendChild(nextElement);
			break;
		}
		case TRANSFORMER_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(TRANSFORMER_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
		    qreal spx = pf.x()/*+m_margin*/;
			qreal spy = pf.y()/*+m_margin*/;
			qreal epx = pf.x()+m_width/*-2*m_margin*/;
			qreal epy = pf.y()+m_height/*-2*m_margin*/;
			
			qreal w = epx-spx;
			qreal h = epy-spy;
			qreal s3h5 = h * 3 / 5;
			qreal s3w5 = 3 * w / 5;
			qreal w5 = w/5;
			
			//QRectF rc1 = QRectF(spx + w5,spy,s3w5,s3h5);
			//QRectF rc2 = QRectF(spx,spy + 2*(epy-spy)/5,s3w5, s3h5);
			//QRectF rc3 = QRectF(spx + 2*w*17/80,spy + 2*h/5,3*w*61/320,s3h5);

			QRectF rc1 = QRectF(spx + w5+s3w5/2,             spy+s3h5/2,                     s3w5/2,      s3h5/2);
			QRectF rc2 = QRectF(spx+s3w5/2,                  spy + 2*(epy-spy)/5+ s3h5/2,     s3w5/2,      s3h5/2);
			QRectF rc3 = QRectF(spx + 2*w*17/80+3*w*61/320/2,spy + 2*h/5+ s3h5/2,             3*w*61/320/2,s3h5/2);

			
			for (int i= 0 ; i < 3; i++)
			{
				QDomElement lastElement = doc.createElement("ellipse");
				element.appendChild(lastElement);

				QDomAttr cxattrib = doc.createAttribute("cx");
				QDomAttr cyattrib = doc.createAttribute("cy");
				QDomAttr rxattrib = doc.createAttribute("rx");
				QDomAttr ryattrib = doc.createAttribute("ry");

				switch(i)
				{
				case 0:
					{						
						cxattrib.setValue(QString("%1").arg(rc1.x()));
						cyattrib.setValue(QString("%1").arg(rc1.y()));
						rxattrib.setValue(QString("%1").arg(rc1.width()));
						ryattrib.setValue(QString("%1").arg(rc1.height()));					
						break;
					}
				case 1:
					{						
						cxattrib.setValue(QString("%1").arg(rc2.x()));
						cyattrib.setValue(QString("%1").arg(rc2.y()));
						rxattrib.setValue(QString("%1").arg(rc2.width()));
						ryattrib.setValue(QString("%1").arg(rc2.height()));						
						break;
					}
				case 2:
					{
						cxattrib.setValue(QString("%1").arg(rc3.x()));
						cyattrib.setValue(QString("%1").arg(rc3.y()));
						rxattrib.setValue(QString("%1").arg(rc3.width()));
						ryattrib.setValue(QString("%1").arg(rc3.height()));						
						break;
					}

				}
				
				
				lastElement.setAttributeNode(cxattrib);							
				lastElement.setAttributeNode(cyattrib);			
				lastElement.setAttributeNode(rxattrib);			
				lastElement.setAttributeNode(ryattrib);

				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				QDomAttr fillAttrib = doc.createAttribute("fill");
				fillAttrib.setValue(QString("none"));
				lastElement.setAttributeNode(fillAttrib);

				
			}

			root.appendChild(nextElement);
			break;
		}
		case TRANSFORMER1_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(TRANSFORMER1_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			QPointF point1(pf.x()+m_margin+(m_width-2*m_margin)/2,  pf.y()+m_margin+(m_height-m_margin)*3/5/2);
			QPointF point2(pf.x()+m_margin+(m_width-2*m_margin)/2,  pf.y()+(m_height-m_margin)*2/5+m_margin+(m_height-m_margin)*3/5/2);


			for (int i = 0 ; i < 2 ; i++)
			{

				QDomElement lastElement = doc.createElement("ellipse");
				element.appendChild(lastElement);
				QDomAttr cxattrib = doc.createAttribute("cx");
				QDomAttr cyattrib = doc.createAttribute("cy");
				QDomAttr rxattrib = doc.createAttribute("rx");
				QDomAttr ryattrib = doc.createAttribute("ry");

				if (i == 0 )
				{
					cxattrib.setValue(QString("%1").arg(point1.x()));
					cyattrib.setValue(QString("%1").arg(point1.y()));
					

				}
				else
				{
					cxattrib.setValue(QString("%1").arg(point2.x()));
					cyattrib.setValue(QString("%1").arg(point2.y()));

				}

				rxattrib.setValue(QString("%1").arg((m_width-2*m_margin)/2));
				ryattrib.setValue(QString("%1").arg((m_height-m_margin)*3/5/2));
				
				lastElement.setAttributeNode(cxattrib);		
				lastElement.setAttributeNode(cyattrib);	
				lastElement.setAttributeNode(rxattrib);	
				lastElement.setAttributeNode(ryattrib);


				QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
				swidthAttrib.setValue(QString("%1").arg(m_penWidth));
				lastElement.setAttributeNode(swidthAttrib);

				QDomAttr strokeAttrib = doc.createAttribute("stroke");
				QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
				strokeAttrib.setValue(value);
				lastElement.setAttributeNode(strokeAttrib);

				QDomAttr fillAttrib = doc.createAttribute("fill");
				fillAttrib.setValue(QString("none"));
				lastElement.setAttributeNode(fillAttrib);


			}

			root.appendChild(nextElement);
			break;
		}
		case LINE_TOP_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(LINE_TOP_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			QPointF point1(pf.x()+m_width/2,pf.y()+m_margin);
			QPointF point2(pf.x()+m_margin,pf.y()+(m_height-2*m_margin)*1/4+m_margin);
			QPointF point3(pf.x()+m_width-m_margin,pf.y()+(m_height-2*m_margin)*1/4+m_margin);
			QPointF point4(pf.x()+m_width/2,pf.y()+(m_height-2*m_margin)*1/4+m_margin);
			QPointF point5(pf.x()+m_width/2,pf.y()+m_height-m_margin);

  
			//画三角形
			QDomElement lastElement = doc.createElement("polygon");
			element.appendChild(lastElement);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr strokeAttrib = doc.createAttribute("stroke");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    value = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			lastElement.setAttributeNode(fillAttrib);

			QDomAttr pointsAttrib = doc.createAttribute("points");
		    value = QString("%1 %2 %3 %4 %5 %6").arg(point1.x()).arg(point1.y())
				     .arg(point2.x()).arg(point2.y())
					 .arg(point3.x()).arg(point3.y());
			pointsAttrib.setValue(value);
			lastElement.setAttributeNode(pointsAttrib);

			//画直线
			lastElement = doc.createElement("line");
			element.appendChild(lastElement);

            strokeAttrib = doc.createAttribute("stroke");
			value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			
		    QDomAttr y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point4.y()));
			lastElement.setAttributeNode(y1Attrib);

			swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point5.y()));
			lastElement.setAttributeNode(y2Attrib);

			QDomAttr x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point4.x()));
			lastElement.setAttributeNode(x1Attrib);

			QDomAttr x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point5.x()));
			lastElement.setAttributeNode(x2Attrib);
			

			root.appendChild(nextElement);
			break;
		}
		case LINE_BUTTOM_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(LINE_BUTTOM_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			QPointF point1(pf.x()+m_margin,pf.y()+m_height-m_margin-(m_height-2*m_margin)*1/4);
			QPointF point2(pf.x()+m_width-m_margin,pf.y()+m_height-m_margin-(m_height-2*m_margin)*1/4);
			QPointF point3(pf.x()+m_width/2,pf.y()+m_height-m_margin);
			QPointF point4(pf.x()+m_width/2,pf.y()+m_margin);
			QPointF point5(pf.x()+m_width/2,pf.y()+m_height-m_margin-(m_height-2*m_margin)*1/4);

  
			//画三角形
			QDomElement lastElement = doc.createElement("polygon");
			element.appendChild(lastElement);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr strokeAttrib = doc.createAttribute("stroke");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    value = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			lastElement.setAttributeNode(fillAttrib);

			QDomAttr pointsAttrib = doc.createAttribute("points");
		    value = QString("%1 %2 %3 %4 %5 %6").arg(point1.x()).arg(point1.y())
				     .arg(point2.x()).arg(point2.y())
					 .arg(point3.x()).arg(point3.y());
			pointsAttrib.setValue(value);
			lastElement.setAttributeNode(pointsAttrib);

			//画直线
			lastElement = doc.createElement("line");
			element.appendChild(lastElement);

            strokeAttrib = doc.createAttribute("stroke");
			value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			
		    QDomAttr y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point4.y()));
			lastElement.setAttributeNode(y1Attrib);

			swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point5.y()));
			lastElement.setAttributeNode(y2Attrib);

			QDomAttr x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point4.x()));
			lastElement.setAttributeNode(x1Attrib);

			QDomAttr x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point5.x()));
			lastElement.setAttributeNode(x2Attrib);

			root.appendChild(nextElement);
			
			break;
		}
		case LINE_LEFT_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(LINE_LEFT_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
		    QPointF point1(pf.x()+m_margin,pf.y()+m_height/2);
			QPointF point2(pf.x()+m_margin+(m_width-2*m_margin)/4,pf.y()+m_margin);
			QPointF point3(pf.x()+m_margin+(m_width-2*m_margin)/4,pf.y()+m_height-m_margin);
			QPointF point4(pf.x()+m_margin+(m_width-2*m_margin)/4,pf.y()+m_height/2);
			QPointF point5(pf.x()+m_width-m_margin,pf.y()+m_height/2);

  
			//画三角形
			QDomElement lastElement = doc.createElement("polygon");
			element.appendChild(lastElement);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr strokeAttrib = doc.createAttribute("stroke");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    value = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			lastElement.setAttributeNode(fillAttrib);

			QDomAttr pointsAttrib = doc.createAttribute("points");
		    value = QString("%1 %2 %3 %4 %5 %6").arg(point1.x()).arg(point1.y())
				     .arg(point2.x()).arg(point2.y())
					 .arg(point3.x()).arg(point3.y());
			pointsAttrib.setValue(value);
			lastElement.setAttributeNode(pointsAttrib);

			//画直线
			lastElement = doc.createElement("line");
			element.appendChild(lastElement);

            strokeAttrib = doc.createAttribute("stroke");
			value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			
		    QDomAttr y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point4.y()));
			lastElement.setAttributeNode(y1Attrib);

			swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point5.y()));
			lastElement.setAttributeNode(y2Attrib);

			QDomAttr x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point4.x()));
			lastElement.setAttributeNode(x1Attrib);

			QDomAttr x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point5.x()));
			lastElement.setAttributeNode(x2Attrib);

			root.appendChild(nextElement);
			
			break;
		}
	   case LINE_RIGHT_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(LINE_RIGHT_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
		    QPointF point1(pf.x()+m_width-(m_width-2*m_margin)/4,pf.y()+m_margin);
			QPointF point2(pf.x()+m_width-(m_width-2*m_margin)/4,pf.y()+m_height-m_margin);
			QPointF point3(pf.x()+m_width-m_margin,pf.y()+m_height/2);
			QPointF point4(pf.x()+m_margin,pf.y()+m_height/2);
			QPointF point5(pf.x()+m_width-(m_width-2*m_margin)/4,pf.y()+m_height/2);

  
			//画三角形
			QDomElement lastElement = doc.createElement("polygon");
			element.appendChild(lastElement);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr strokeAttrib = doc.createAttribute("stroke");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    value = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			lastElement.setAttributeNode(fillAttrib);

			QDomAttr pointsAttrib = doc.createAttribute("points");
		    value = QString("%1 %2 %3 %4 %5 %6").arg(point1.x()).arg(point1.y())
				     .arg(point2.x()).arg(point2.y())
					 .arg(point3.x()).arg(point3.y());
			pointsAttrib.setValue(value);
			lastElement.setAttributeNode(pointsAttrib);

			//画直线
			lastElement = doc.createElement("line");
			element.appendChild(lastElement);

            strokeAttrib = doc.createAttribute("stroke");
			value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			
		    QDomAttr y1Attrib = doc.createAttribute("y1");
			y1Attrib.setValue(QString("%1").arg(point4.y()));
			lastElement.setAttributeNode(y1Attrib);

			swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr y2Attrib = doc.createAttribute("y2");
			y2Attrib.setValue(QString("%1").arg(point5.y()));
			lastElement.setAttributeNode(y2Attrib);

			QDomAttr x1Attrib = doc.createAttribute("x1");
			x1Attrib.setValue(QString("%1").arg(point4.x()));
			lastElement.setAttributeNode(x1Attrib);

			QDomAttr x2Attrib = doc.createAttribute("x2");
			x2Attrib.setValue(QString("%1").arg(point5.x()));
			lastElement.setAttributeNode(x2Attrib);

			root.appendChild(nextElement);

			break;
		 }

		case POWERHOUSE_GRAPHICSITEM:
		{
			nextElement.setAttribute("class",QString("%1").arg(POWERHOUSE_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QPointF pf = this->pos();
			qreal spx = pf.x() +0;
			qreal spy = pf.y()+0;
			qreal epx = pf.x()+m_width;
			qreal epy = pf.y()+m_height;
	

			qreal epxspx = epx-spx;
			qreal epyspy = epy-spy;
			qreal epxspx6 = epxspx/6;
			qreal epxspx3 = epxspx/3;
			qreal epyspy4c2 = epyspy*2/4;
			qreal epyspy4c1 = epyspy*1/4; 

			QDomElement element = doc.createElement("g1");
			nextElement.appendChild(element);
            /*
						
			QSvgGenerator svgGen;
			svgGen.setFileName("C:/Documents and Settings/Administrator/桌面/svg/test.svg");
			QPainter painter1;
			painter1.begin(&svgGen);
			

			QVector<QPointF>	pointList;
			pointList.append (QPointF(spx + epxspx6, spy + epyspy4c2));                                                
			pointList.append (QPointF(spx + epxspx3, spy + epyspy4c1));
			pointList.append (QPointF(epx - epxspx3, epy - epyspy4c1));
			pointList.append (QPointF(epx - epxspx6, spy + epyspy4c2));
			
			QPainterPath path;
			path.moveTo (pointList[0]);
			path.cubicTo (pointList[1], pointList[2], pointList[3]);
			painter1.drawPath(path); 

			painter1.end();
			*/
			

			
			//画贝塞尔曲线
			QDomElement lastElement = doc.createElement("path");
			element.appendChild(lastElement);

			QDomAttr swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			QDomAttr strokeAttrib = doc.createAttribute("stroke");
			QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
			fillAttrib.setValue(QString("none"));
			lastElement.setAttributeNode(fillAttrib);


           QDomAttr dAttrib = doc.createAttribute("d");
		   value = QString("M%1,%2 C%3,%4 %5,%6 %7,%8")
			   .arg(spx + epxspx6)           
			   .arg(spy + epyspy4c2)
			   .arg(spx + epxspx3)    
			   .arg(spy + epyspy4c1)  
			   .arg(epx - epxspx3)			
			   .arg(epy - epyspy4c1)			
			   .arg(epx - epxspx6)			 
			   .arg(spy + epyspy4c2);			   
			   
		   dAttrib.setValue(value);
		   lastElement.setAttributeNode(dAttrib);


		    lastElement = doc.createElement("ellipse");
			nextElement.appendChild(lastElement);


            QDomAttr cxattrib = doc.createAttribute("cx");
			cxattrib.setValue(QString("%1").arg(spx +epxspx/2));
			lastElement.setAttributeNode(cxattrib);

			QDomAttr cyattrib = doc.createAttribute("cy");
			cyattrib.setValue(QString("%1").arg(spy + epyspy/2));
			lastElement.setAttributeNode(cyattrib);

			QDomAttr rxattrib = doc.createAttribute("rx");
			rxattrib.setValue(QString("%1").arg(epxspx/2));
			lastElement.setAttributeNode(rxattrib);

			QDomAttr ryattrib = doc.createAttribute("ry");
			ryattrib.setValue(QString("%1").arg(epyspy/2));
			lastElement.setAttributeNode(ryattrib);

			swidthAttrib = doc.createAttribute("stroke-width");
			swidthAttrib.setValue(QString("%1").arg(m_penWidth));
			lastElement.setAttributeNode(swidthAttrib);

			strokeAttrib = doc.createAttribute("stroke");
		    value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			strokeAttrib.setValue(value);
			lastElement.setAttributeNode(strokeAttrib);

			fillAttrib = doc.createAttribute("fill");
		    //value = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(QString("none"));
			lastElement.setAttributeNode(fillAttrib);


          
			root.appendChild(nextElement);
			break;
		}
		case TEXT_GRAPHICSITEM:
		{
			/*
			QSvgGenerator svgGen;
			svgGen.setFileName("C:/Documents and Settings/Administrator/桌面/svg/test.svg");
			QPainter painter1;
			painter1.begin(&svgGen);
			painter1.rotate(45);
			painter1.drawText(m_margin,m_height/2,m_strText);

			painter1.end();
			*/

			nextElement.setAttribute("class",QString("%1").arg(TEXT_GRAPHICSITEM));
			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			QDomElement element = doc.createElement("text");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			QPointF point(pf.x()+m_margin,pf.y()+m_height/2);

			QDomAttr xAttrib = doc.createAttribute("x");
			xAttrib.setValue(QString("%1").arg(point.x()));
			element.setAttributeNode(xAttrib);

			QDomAttr yAttrib = doc.createAttribute("y");
			yAttrib.setValue(QString("%1").arg(point.y()));
			element.setAttributeNode(yAttrib);

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			element.setAttributeNode(fillAttrib);

			QDomAttr fontWeightAttrib = doc.createAttribute("font-weight");
		    value = QString("%1").arg(m_font.weight());
			fontWeightAttrib.setValue(value);
			element.setAttributeNode(fontWeightAttrib);

			QDomAttr fontFamilyAttrib = doc.createAttribute("font-family");
		    value = QString("%1").arg(m_font.family());
			fontFamilyAttrib.setValue(value);
			element.setAttributeNode(fontFamilyAttrib);

			QDomAttr fontSizeAttrib = doc.createAttribute("font-size");
		    value = QString("%1").arg(m_font.pointSize());
			fontSizeAttrib.setValue(value);
			element.setAttributeNode(fontSizeAttrib);

		    QDomText  domText = doc.createTextNode(m_strText) ;
			element.appendChild(domText);

			root.appendChild(nextElement);
			break;
		}
	}

	

}

void CustomGraphicsItem::setAngle(qint16 tmpAngle)
{

}

QString CustomGraphicsItem::fontText()
{
	return m_strText;
}

void CustomGraphicsItem::setPenWidth(int penWidth)
{

	m_penWidth = qreal(penWidth);
}

void CustomGraphicsItem::saveScdItem(QDomDocument doc,QDomElement root)
{
	QDomElement nextElement = doc.createElement("g");

	switch(m_type)
	{
		case EQUIP_GRAPHICSITEM:
		case STATION_GRAPHICSITEM:

		{
			if (m_type == EQUIP_GRAPHICSITEM)
				nextElement.setAttribute("class",QString("%1").arg(EQUIP_GRAPHICSITEM));
			else if (m_type == STATION_GRAPHICSITEM)
				nextElement.setAttribute("class",QString("%1").arg(STATION_GRAPHICSITEM));

			nextElement.setAttribute("width",QString("%1").arg(m_width));
			nextElement.setAttribute("height",QString("%1").arg(m_height));
			nextElement.setAttribute("posX",QString("%1").arg(this->pos().x()));
			nextElement.setAttribute("posY",QString("%1").arg(this->pos().y()));
			nextElement.setAttribute("stroke-width",QString("%1").arg(m_penWidth));
			QString value1 = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			nextElement.setAttribute("stroke",QString("%1").arg(value1));
		    value1 = QString("#%1%2%3").arg(m_fillColor.red(),2,16,QLatin1Char( '0' )).arg(m_fillColor.green(),2,16,QLatin1Char( '0' )).arg(m_fillColor.blue(),2,16,QLatin1Char( '0'));
            nextElement.setAttribute("fill",QString("%1").arg(value1));

			 QDomElement element;
			if (m_type == EQUIP_GRAPHICSITEM)
			   element = doc.createElement("equip");
			else if (m_type == STATION_GRAPHICSITEM)
			   element = doc.createElement("station");
			nextElement.appendChild(element);

			QPointF pf = this->pos();
			QPointF point(pf.x()+m_margin,pf.y()+m_height/2);

			QDomAttr xAttrib = doc.createAttribute("x");
			xAttrib.setValue(QString("%1").arg(point.x()));
			element.setAttributeNode(xAttrib);

			QDomAttr yAttrib = doc.createAttribute("y");
			yAttrib.setValue(QString("%1").arg(point.y()));
			element.setAttributeNode(yAttrib);


			if (m_type == EQUIP_GRAPHICSITEM)
			{

				QDomAttr lineIdAttrib = doc.createAttribute("lineId");
				lineIdAttrib.setValue(QString("%1").arg(m_lineId));
				element.setAttributeNode(lineIdAttrib);

			    QDomAttr lineNameAttrib = doc.createAttribute("lineName");
				lineNameAttrib.setValue(QString("%1").arg(m_lineName));
				element.setAttributeNode(lineNameAttrib);

				QDomAttr equipIdAttrib = doc.createAttribute("equipId");
				equipIdAttrib.setValue(QString("%1").arg(m_equipId));
				element.setAttributeNode(equipIdAttrib);

				QDomAttr equipAttrib = doc.createAttribute("equip");
				equipAttrib.setValue(QString("%1").arg(m_equip));
				element.setAttributeNode(equipAttrib);

				QDomAttr equipNameAttrib = doc.createAttribute("equipName");
				equipNameAttrib.setValue(QString("%1").arg(m_strText));
				element.setAttributeNode(equipNameAttrib);

			}
			else if (m_type == STATION_GRAPHICSITEM)
			{
				QDomAttr staIdAttrib = doc.createAttribute("stationId");
				staIdAttrib.setValue(QString("%1").arg(m_staId));
				element.setAttributeNode(staIdAttrib);

				QDomAttr staNameAttrib = doc.createAttribute("stationName");
				staNameAttrib.setValue(QString("%1").arg(m_staName));
				element.setAttributeNode(staNameAttrib);

			}

			QDomAttr fillAttrib = doc.createAttribute("fill");
		    QString value = QString("#%1%2%3").arg(m_penColor.red(),2,16,QLatin1Char( '0' )).arg(m_penColor.green(),2,16,QLatin1Char( '0' )).arg(m_penColor.blue(),2,16,QLatin1Char( '0'));
			fillAttrib.setValue(value);
			element.setAttributeNode(fillAttrib);

			QDomAttr fontWeightAttrib = doc.createAttribute("font-weight");
		    value = QString("%1").arg(m_font.weight());
			fontWeightAttrib.setValue(value);
			element.setAttributeNode(fontWeightAttrib);

			QDomAttr fontFamilyAttrib = doc.createAttribute("font-family");
		    value = QString("%1").arg(m_font.family());
			fontFamilyAttrib.setValue(value);
			element.setAttributeNode(fontFamilyAttrib);

			QDomAttr fontSizeAttrib = doc.createAttribute("font-size");
		    value = QString("%1").arg(m_font.pointSize());
			fontSizeAttrib.setValue(value);
			element.setAttributeNode(fontSizeAttrib);

		    QDomText  domText = doc.createTextNode(m_strText) ;
			element.appendChild(domText);

			root.appendChild(nextElement);
			break;
		}
	   default:
		{
			break;
		}

	}
}


void CustomGraphicsItem::setEditShowModel(bool flag)
{
    m_flag = flag;

	if (m_flag)
	{
		setAcceptDrops(true);
		setAcceptsHoverEvents(true);
		setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
	}
	else
	{
		setAcceptDrops(false);
		setAcceptsHoverEvents(false);
		setFlags(!QGraphicsItem::ItemIsMovable | !QGraphicsItem::ItemIsSelectable | !QGraphicsItem::ItemIsFocusable);
	}
	
}

bool CustomGraphicsItem::editShowModel()
{
	return m_flag;
}