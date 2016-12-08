#ifndef TESTITEM_H
#define TESTITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
class TestItem : public QGraphicsItem
{
public:
     TestItem(QGraphicsScene * secne);
    TestItem();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    QGraphicsScene *m_scene;

};

#endif // TESTITEM_H
