#include "eresizefocus.h"

EResizeFocus::EResizeFocus(PosInHost pos,QGraphicsItem *parent)
	: QGraphicsRectItem(0,0,6,6,parent),posInHost(pos),wsize(6)
{
	setAcceptsHoverEvents(true);
	setVisible(false);

	locateInHost();
}

EResizeFocus::EResizeFocus(qreal len, PosInHost pos, QGraphicsItem *parent)
	:QGraphicsRectItem(0,0,len,len,parent),posInHost(pos),wsize(len)
{
	setAcceptsHoverEvents(true);
	setVisible(false);

	locateInHost();
}

EResizeFocus::~EResizeFocus()
{

}
void EResizeFocus::hoverEnterEvent ( QGraphicsSceneHoverEvent * event )
{
	switch(posInHost){
		case NORTH_MIDDLE:
			setCursor(Qt::SizeVerCursor);
			break;
		case SOUTH_MIDDLE:
			setCursor(Qt::SizeVerCursor);
			break;
		case EAST_MIDDLE:
			setCursor(Qt::SizeHorCursor);
			break;
		case WEST_MIDDLE:
			setCursor(Qt::SizeHorCursor);
			break;
		case NORTH_WEST:
			setCursor(Qt::SizeFDiagCursor);
			break;
		case SOUTH_EAST:
			setCursor(Qt::SizeFDiagCursor);
			break;
		case NORTH_EAST:
			setCursor(Qt::SizeBDiagCursor);
			break;
		case SOUTH_WEST:
			setCursor(Qt::SizeBDiagCursor);
			break;
		default:
			break;
	}
	QGraphicsRectItem::hoverEnterEvent(event);
}

void EResizeFocus::hoverLeaveEvent ( QGraphicsSceneHoverEvent * event )
{
	QGraphicsRectItem::hoverLeaveEvent(event);
}

void EResizeFocus::locateInHost()
{
	const QRectF parentRect = this->parentItem()->boundingRect();
	qreal x = 0, y = 0;

	switch(posInHost){
	    case NORTH_MIDDLE:
			x = parentRect.width() / 2 - wsize / 2;
			y = 0;
			break;
		case SOUTH_MIDDLE:
			x = parentRect.width() / 2 - wsize / 2;
			y = parentRect.height() - wsize;
			break;
		case EAST_MIDDLE:
			x = parentRect.width() - wsize;
			y = parentRect.height() / 2 - wsize / 2;
			break;
		case WEST_MIDDLE:
			x = 0;
			y = parentRect.height() / 2 - wsize / 2;
			break;
		case NORTH_WEST:
			x = 0;
			y = 0;
			break;
		case SOUTH_EAST:
			x = parentRect.width() - wsize;
			y = parentRect.height() - wsize;
			break;
		case NORTH_EAST:
			x = parentRect.width() - wsize;
			y = 0;
			break;
		case SOUTH_WEST:
			x = 0;
			y = parentRect.height() - wsize;
			break;
		default:
			break;
	}
	setPos(x,y);
}


const EResizeFocus &EResizeFocus::operator=(const EResizeFocus & right )
{

	wsize = right.wsize;

	return *this;


}