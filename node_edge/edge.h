#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>
class Node;
class Edge : public QGraphicsItem
{
public:
    Edge(Node *desNode,Node * sourceNode);
    Edge();
    void adjust();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
      QRectF boundingRect() const ;

private:
  //一个线段有两个点
      Node *m_sourceNode;
      Node *m_desNode;
};

#endif // EDGE_H
