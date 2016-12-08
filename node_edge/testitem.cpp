#include "testitem.h"
#include <QPainter>
#include <QStyle>
#include <QStyleOptionGraphicsItem>
TestItem::TestItem()
    :QGraphicsItem(0)
{
    this->setFlag(ItemIsMovable,true);
    this->setFlags(ItemIsMovable| ItemIsSelectable | ItemIsFocusable| ItemSendsScenePositionChanges);
    setCacheMode(DeviceCoordinateCache);
}

 TestItem::TestItem(QGraphicsScene * secne)
     :QGraphicsItem(0),m_scene(secne)
  {

    this->setFlag(ItemIsMovable,true);
    this->setFlags(ItemIsMovable| ItemIsSelectable | ItemSendsScenePositionChanges);
    setCacheMode(DeviceCoordinateCache);
  }

void TestItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::SolidLine);

    painter->fillRect(QRectF(50,50,100,100  ),QBrush(QColor(Qt::red)));
//    if(option->state& QStyle::State_Selected)
//    {
//        painter->setPen(Qt::DotLine);
//    }
    QPoint _center(600,600);
    painter->drawEllipse(_center,50,50);
}

QRectF TestItem::boundingRect() const
{
    return QRectF(50,50,100,100  );
}


#include <QDebug>
void TestItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"press"<<m_scene->selectedItems().count();

    update();
    QGraphicsItem::mousePressEvent(event);
}

void TestItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"mouseReleaseEvent";
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
