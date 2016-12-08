#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QPoint>
#include <QGraphicsView>
#include <QPainter>
class Edge;

class Node : public QGraphicsItem
{
    // Q_OBJECT
public:
    Node(QGraphicsScene * secne);

    Node(/*QPoint center,int radius ,*/);
    void addEdge(Edge * _edge);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    //画item
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const ;
    // QPainterPath shape() const;


    /*
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
*/
signals:

public slots:

public:
    QPoint m_center;//圆心
    int m_raius;//半径
    // QGraphicsView m_parentView;
    QList<Edge* > m_edgeList;
    QGraphicsScene *m_scene;

};

#endif // NODE_H
