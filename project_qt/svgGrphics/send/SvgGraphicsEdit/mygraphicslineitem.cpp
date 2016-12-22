#include "mygraphicslineitem.h"
#include "lineresizefocus.h"
#include <math.h>
#include <QtGui>

MyGraphicsLineItem::MyGraphicsLineItem(QMenu *contextMenu,const QLineF & line, QGraphicsItem * parent)
	: QGraphicsLineItem(line,parent)
{
    margin = 4;
	myContextMenu = contextMenu;

	setAcceptDrops(true);
    setAcceptsHoverEvents(true);
	setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
	createResizeFocus();
}

MyGraphicsLineItem::~MyGraphicsLineItem()
{

}

void MyGraphicsLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{
	QGraphicsLineItem::paint(painter,option,widget);
	QLineF lineF = line();
	if(option->state & QStyle::State_Selected){	

		setCursor(Qt::SizeAllCursor);
		//画选择虚线框
		painter->setPen(Qt::DotLine);
		painter->setPen(Qt::yellow);
		painter->drawLine(lineF);
		showResizeFocus(lineF,true);
	}
	else{

		showResizeFocus(lineF,false);
	}

}

int MyGraphicsLineItem::analystLineShape(QLineF lineF)
{
	qreal x1 = lineF.x1(),y1 = lineF.y1(),x2 = lineF.x2(),y2 = lineF.y2();

	if ((x1 != x2) && (y1 == y2)){  //水平
			return  LineResizeFocus::HORIZ_LINE;
	}else{                          //垂直
			return  LineResizeFocus::VER_LINE;
	}

}


void MyGraphicsLineItem::createResizeFocus()
 {
	 QBrush  brush(Qt::black);
	 
	 LineResizeFocus *left_Node = new LineResizeFocus(margin,LineResizeFocus::LEFT_HORIZ_NODE,this);
	 left_Node->setBrush(brush);
	 resizeFocus.append(left_Node);

	 LineResizeFocus *right_Node = new LineResizeFocus(margin,LineResizeFocus::RIGHT_HORIZ_NODE,this);
	 right_Node->setBrush(brush);
	 resizeFocus.append(right_Node);

	 LineResizeFocus *top_Node = new LineResizeFocus(margin,LineResizeFocus::TOP_VER_NODE,this);
	 top_Node->setBrush(brush);
	 resizeFocus.append(top_Node);

	 LineResizeFocus *bottom_Node = new LineResizeFocus(margin,LineResizeFocus::BOTTOM_VER_NODE,this);
	 bottom_Node->setBrush(brush);
	 resizeFocus.append(bottom_Node);
	
 }

 void MyGraphicsLineItem::showResizeFocus(QLineF lineF,bool visible)
 {
	 for(int i = 0; i < resizeFocus.count(); i++)
	 {
		 LineResizeFocus *focus = resizeFocus.at(i);
		 focus->setVisible(false);
		 if (analystLineShape(lineF) == LineResizeFocus::HORIZ_LINE){ //水平		
			 switch(focus->getInHost()){
			     case LineResizeFocus::LEFT_HORIZ_NODE:
				      focus->locateInHost(lineF.x1(),lineF.y1());
					   focus->setVisible(visible);
		       	      break;
		         case LineResizeFocus::RIGHT_HORIZ_NODE:
			          focus->locateInHost(lineF.x2(),lineF.y2());
					   focus->setVisible(visible);
			          break;
		
		         default:
			          break;
	          }
			
		 }else{                                                      //垂直
			 switch(focus->getInHost()){
			     case LineResizeFocus::TOP_VER_NODE:
				      focus->locateInHost(lineF.x1(),lineF.y1());
					  focus->setVisible(visible);
		       	      break;
		         case LineResizeFocus::BOTTOM_VER_NODE:
			          focus->locateInHost(lineF.x2(),lineF.y2());
					  focus->setVisible(visible);
			          break;
		
		         default:
			          break;
	          }
		 }	 
	 }
 }

void MyGraphicsLineItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    scene()->clearSelection();
    setSelected(true);
    myContextMenu->exec(event->screenPos());
}
 
 void MyGraphicsLineItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
 {
	 curResizeFocus = qgraphicsitem_cast<LineResizeFocus*>(scene()->itemAt(event->scenePos()));
	 if(curResizeFocus)
	 {
		 myMode = RESIZE;

		 switch(curResizeFocus->getInHost()){
			case LineResizeFocus::LEFT_HORIZ_NODE:
				 lineFOrgn.setX(line().x2());
				 lineFOrgn.setY(line().y2());
				 break;
			case LineResizeFocus::RIGHT_HORIZ_NODE:
				 lineFOrgn.setX(line().x1());
				 lineFOrgn.setY(line().y1());
				 break;
			case LineResizeFocus::TOP_VER_NODE:
				 lineFOrgn.setX(line().x2());
				 lineFOrgn.setY(line().y2());
				break;
			case LineResizeFocus::BOTTOM_VER_NODE:
				 lineFOrgn.setX(line().x1());
				 lineFOrgn.setY(line().y1());
				break;
			default:
				break;

		 }	
	 }
	 else
	 {
		myMode = MOVE;
		QGraphicsItem::mousePressEvent(event);
	 }
 }
 void MyGraphicsLineItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
 {
	 if(myMode == RESIZE)
	 {
		 QPointF curPoint(event->scenePos());
		 QLineF lineF(lineFOrgn.x(),lineFOrgn.y(),curPoint.x(),curPoint.y()) ;
		 setLine(lineF);		
	 }
	 else
		QGraphicsItem::mouseMoveEvent(event);
 }
 void MyGraphicsLineItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
 {
	 if(myMode == RESIZE)
	 {
		
	 }
	 else
		QGraphicsItem::mouseReleaseEvent(event);
 }