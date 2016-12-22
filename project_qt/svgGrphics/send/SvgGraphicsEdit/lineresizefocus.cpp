#include "lineresizefocus.h"


LineResizeFocus::LineResizeFocus(PosInHost pos,QGraphicsItem *parent)
	: QGraphicsRectItem(0,0,4,4,parent),posInHost(pos),wsize(4)
{

	setAcceptsHoverEvents(true);
	setVisible(false);

}

LineResizeFocus::LineResizeFocus(qreal len, PosInHost pos, QGraphicsItem *parent)
	:QGraphicsRectItem(0,0,len,len,parent),posInHost(pos),wsize(len)
{
	setAcceptsHoverEvents(true);
	setVisible(false);

	locateInHost(0,0);
}
LineResizeFocus::~LineResizeFocus()
{

}

void LineResizeFocus::hoverEnterEvent ( QGraphicsSceneHoverEvent * event )
{
	switch(posInHost){
		case LEFT_HORIZ_NODE:
			setCursor(Qt::SizeHorCursor);
			break;
		case RIGHT_HORIZ_NODE:
			setCursor(Qt::SizeHorCursor);
			break;
		case TOP_VER_NODE:
			setCursor(Qt::SizeVerCursor);
			break;
		case BOTTOM_VER_NODE:
			setCursor(Qt::SizeVerCursor);
			break;
		default:
			break;
	}
	QGraphicsRectItem::hoverEnterEvent(event);
}
void LineResizeFocus::hoverLeaveEvent ( QGraphicsSceneHoverEvent * event )
{
	QGraphicsRectItem::hoverLeaveEvent(event);
}


void LineResizeFocus::locateInHost(qreal tmpX,qreal tmpY)
{
	const QRectF parentRect = this->parentItem()->boundingRect();
	qreal x = 0, y = 0;

	switch(posInHost){
		case LEFT_HORIZ_NODE:
			x = tmpX;
			y = tmpY-wsize/2;
			break;
		case RIGHT_HORIZ_NODE:
			x = tmpX-wsize/2 ;
			y = tmpY-wsize/2;
			break;
		case TOP_VER_NODE:
			x = tmpX - wsize/2;
			y = tmpY;
			break;
		case BOTTOM_VER_NODE:
			x = tmpX;
			y = tmpY-wsize/2;
			break;		
		default:
			break;
	}
	setPos(x,y);
	
}