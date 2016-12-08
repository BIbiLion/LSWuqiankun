#include "node.h"
#include "edge.h"
Node::Node(/*QPoint center,int radius, */)
/*m_center(center),m_raius(radius),m_parentView(parent)*/
    :QGraphicsItem(0)
{
    this->setFlag(ItemIsMovable,true);
    setFlags(  ItemIsMovable| ItemIsSelectable  | ItemIsFocusable| ItemSendsScenePositionChanges);
    //setFlag(ItemSendsGeometryChanges);

    setCacheMode(DeviceCoordinateCache);

    //setAcceptDrops(true);

    //setZValue(0);
}

Node::Node(QGraphicsScene * secne)
    :QGraphicsItem(0),m_scene(secne)
{
    //备注设置flage的是否发现：如果设置不对，焦点会出现问题
    this->setFlag(ItemIsMovable,true);
    setFlags(  ItemIsMovable| ItemIsSelectable  | ItemIsFocusable| ItemSendsScenePositionChanges);
    //setFlag(ItemSendsGeometryChanges);

    setCacheMode(DeviceCoordinateCache);
    setZValue(0);
}


#include <QStyle>
#include <QStyleOptionGraphicsItem>
void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::SolidLine);
    painter->fillRect(QRectF(30,30,60,60  ),QBrush(QColor(Qt::yellow)));

//    QPoint _center(60,60);
//    painter->drawEllipse(_center,30,30);


        QPoint _center(0,0);
        painter->drawEllipse(_center,30,30);
}

//纯虚函数必须实现
QRectF Node::boundingRect() const
{
    return QRectF(-30,-30,60,60  );
    //return QRectF(30,30,60,60  );
}

//QPainterPath Node::shape() const
//{
//    QPainterPath path;
//    path.addEllipse(-0, -0, 50, 50);
//}

void Node::addEdge(Edge * _edge)
{
      m_edgeList.push_back(_edge);
}

 QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
 {
     switch (change)
     {
     case ItemPositionHasChanged:
         foreach (Edge * _edge, m_edgeList)
         {
           _edge->adjust();
         }

     break;
     default:
         break;
     }
    return QGraphicsItem::itemChange(change,value);
 }

/*
    QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
    {
        switch (change) {
        case ItemPositionHasChanged:
            this->setPos(this->pos().x()+20,this->pos().y()+20);
        default:
            break;
        };

        return QGraphicsItem::itemChange(change, value);
    }

#include <QDebug>
void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<" Node   press"<<m_scene->selectedItems().count();

    update();
    QGraphicsItem::mousePressEvent(event);
    return;
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"Node   mouseReleaseEvent";
    update();
    QGraphicsItem::mouseReleaseEvent(event);
    return;
}

*/
