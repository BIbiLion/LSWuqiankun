#include "edge.h"
#include <QPainter>
#include "node.h"
#include <QDebug>



Edge::Edge()
    :QGraphicsItem(0)
{
}

Edge::Edge(Node *desNode,Node * sourceNode)
    :QGraphicsItem(0),m_desNode(desNode),m_sourceNode(sourceNode)
{
    //  this->setFlag(ItemIsMovable,true);
    //  setFlags(  ItemIsMovable| ItemIsSelectable  | ItemIsFocusable| ItemSendsScenePositionChanges);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);

    desNode->addEdge(this);
    sourceNode->addEdge(this);
}
void Edge::adjust()
{
    prepareGeometryChange();

    //QLineF line(mapFromItem(m_sourceNode, 60, 60), mapFromItem(m_desNode, 60, 60));
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen( QPen(Qt::black,2,Qt::SolidLine) );

    // painter->drawLine(QPoint(10,20),QPoint(700,700));
    QPoint _startPoint(m_sourceNode->m_center);
    QPoint _endPoint(m_desNode->m_center);
    //qDebug()<<_startPoint <<_endPoint;

    //item自身坐标系对应 如果以（0,0）为坐标系统的原点。
    //QLineF line(mapFromItem(m_sourceNode, 60, 60), mapFromItem(m_desNode, 60, 60));
    QLineF line(mapFromItem(m_sourceNode, 0, 0), mapFromItem(m_desNode, 0, 0));
    // qDebug()<<mapFromItem(m_sourceNode, 0,0)<<mapFromItem(m_desNode, 0,0)<<line.p1()<<line.p2();
    painter->drawLine(line);
    // painter->drawLine(_startPoint,_endPoint);
}
#include <QLineF>
QRectF Edge::boundingRect() const
{
     QLineF line(mapFromItem(m_sourceNode, 0, 0), mapFromItem(m_desNode, 0, 0));
     QPointF _sourcePoint=mapFromItem(m_sourceNode, 0, 0);
     QPointF _desPoint= mapFromItem(m_desNode, 0, 0);
     qDebug()<<mapFromItem(m_sourceNode, 0, 0)<<mapFromItem(m_desNode, 0, 0)<<QRectF(line.p1(),QSize(2,(int)(line.length()))).normalized();
    //return QRectF(line.p1().x(),line.p1().y(),3,(int)(line.length())).normalized();
     return QRectF(_sourcePoint,QSizeF(_desPoint.x()-_sourcePoint.x(),_desPoint.y()-_sourcePoint.y())).normalized();
    // return QRectF(0,0,800,800);
}
