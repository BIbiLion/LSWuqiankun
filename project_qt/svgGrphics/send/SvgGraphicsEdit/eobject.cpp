#include "eobject.h"

EObject::EObject(QGraphicsItem *parent)
	:width(100),height(100),margin(6), QGraphicsItem(parent)
{
	setAcceptDrops(true);
    setAcceptsHoverEvents(true);
	setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
	

	createResizeFocus();
}
EObject::EObject(qreal w,qreal h,qreal m, QGraphicsItem *parent)
	:width(w),height(h),margin(m), QGraphicsItem(parent)
{
	setAcceptDrops(true);
    setAcceptsHoverEvents(true);
	setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);

	createResizeFocus();
}

EObject::~EObject()
{

}

QRectF EObject::boundingRect() const
{
	return QRectF(0, 0, width, height);
}

void EObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{
	Q_UNUSED(widget);

    QColor fillColor = QColor(100,100,255);
	if (option->state & QStyle::State_Selected) {fillColor = fillColor.darker(150);setCursor(Qt::SizeAllCursor);}
    if (option->state & QStyle::State_MouseOver) fillColor = fillColor.lighter(125);

	if(option->state & QStyle::State_Selected)
	{
		//填充矩形的颜色
		painter->fillRect(margin, margin, width-margin*2, height-margin*2 ,fillColor);
		painter->setPen(Qt::DotLine);
		//画选择的虚线框
		painter->drawRect(margin, margin, width-margin*2, height-margin*2);
		showResizeFocus(true);
	}
	else
	{
		painter->fillRect(margin, margin, width-margin*2, height-margin*2 ,fillColor);
		painter->drawRect(margin, margin, width-margin*2, height-margin*2);
		showResizeFocus(false);
	}
}
QPainterPath EObject::shape() const
{
	QPainterPath path;
	path.addRect(0,0,width,height);
	return path;
}
 void EObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
 {
	 curResizeFocus = qgraphicsitem_cast<EResizeFocus*>(scene()->itemAt(event->scenePos()));
	 if(curResizeFocus)
	 {
		 myMode = RESIZE;
		 lastPoint.setX(event->scenePos().x());
		 lastPoint.setY(event->scenePos().y());
		 dashRect = new QGraphicsRectItem();
		 dashRect->setPen(QPen(Qt::DashLine));
		 dashRect->setParentItem(this);
		 dashRect->setRect(margin, margin, width-margin*2, height-margin*2);
	 }
	 else
	 {
		myMode = MOVE;
		QGraphicsItem::mousePressEvent(event);
	 }
 }
 void EObject::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
 {
	 if(myMode == RESIZE)
	 {
		 QPointF curPoint(event->scenePos());

		 qreal curX = margin, curY = margin, curWidth = width-margin*2, curHeight = height-margin*2;
		 qreal wChanging = curPoint.x()-lastPoint.x(), hChanging = curPoint.y()-lastPoint.y();

		 EResizeFocus::PosInHost pos = curResizeFocus->getInHost();
		 switch(pos){
			case EResizeFocus::NORTH_MIDDLE:
				curY += hChanging; curHeight-=hChanging;
				break;
			case EResizeFocus::SOUTH_MIDDLE:
				curHeight+=hChanging;
				break;
			case EResizeFocus::EAST_MIDDLE:
				curWidth+=wChanging;
				break;
			case EResizeFocus::WEST_MIDDLE:
				curX+=wChanging; curWidth-=wChanging;
				break;
			case EResizeFocus::NORTH_WEST:
				curX+=wChanging; curY+=hChanging; curWidth-=wChanging; curHeight-=hChanging;
				break;
			case EResizeFocus::SOUTH_EAST:
				curWidth+=wChanging; curHeight+=hChanging;
				break;
			case EResizeFocus::NORTH_EAST:
				curY+=hChanging; curWidth+=wChanging; curHeight-=hChanging;
				break;
			case EResizeFocus::SOUTH_WEST:
				curX+=wChanging; curWidth-=wChanging; curHeight+=hChanging;
				break;
			default:
				break;
		}
		if(curWidth < 20 ||curHeight <20) return; //!minimal size
		dashRect->setRect(curX,curY,curWidth,curHeight);
	 }
	 else
		QGraphicsItem::mouseMoveEvent(event);
 }
 void EObject::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
 {
	 if(myMode == RESIZE)
	 {
		 width = dashRect->rect().width() +margin*2;
		 height = dashRect->rect().height() +margin*2;
		 qreal curX = dashRect->rect().left() - margin;
		 qreal curY = dashRect->rect().top() - margin;
		 QPointF curPos(curX,curY);
		 setPos(mapToScene(curPos));
		 //scene()->removeItem(dashRect);
		 delete dashRect;
	 }
	 else
		QGraphicsItem::mouseReleaseEvent(event);
 }

 void EObject::showResizeFocus(bool visible)
 {
	 for(int i = 0; i < resizeFocus.count(); i++)
	 {
		 resizeFocus.at(i)->locateInHost();
		 resizeFocus.at(i)->setVisible(visible);
	 }
 }

 void EObject::createResizeFocus()
 {
	 EResizeFocus *north_middle = new EResizeFocus(margin,EResizeFocus::NORTH_MIDDLE,this);
	 resizeFocus.append(north_middle);
	 EResizeFocus *north_east = new EResizeFocus(margin,EResizeFocus::NORTH_EAST,this);
	 resizeFocus.append(north_east);
	 EResizeFocus *north_west = new EResizeFocus(margin,EResizeFocus::NORTH_WEST,this);
	 resizeFocus.append(north_west);
	 EResizeFocus *south_middle = new EResizeFocus(margin,EResizeFocus::SOUTH_MIDDLE,this);
	 resizeFocus.append(south_middle);
	 EResizeFocus *south_east = new EResizeFocus(margin,EResizeFocus::SOUTH_EAST,this);
	 resizeFocus.append(south_east);
	 EResizeFocus *south_west = new EResizeFocus(margin,EResizeFocus::SOUTH_WEST,this);
	 resizeFocus.append(south_west);
	 EResizeFocus *east_middle = new EResizeFocus(margin,EResizeFocus::EAST_MIDDLE,this);
	 resizeFocus.append(east_middle);
	 EResizeFocus *west_middle = new EResizeFocus(margin,EResizeFocus::WEST_MIDDLE,this);
	 resizeFocus.append(west_middle);
 }