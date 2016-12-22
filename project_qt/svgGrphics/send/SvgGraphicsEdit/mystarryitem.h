#ifndef MYSTARRYITEM_H
#define MYSTARRYITEM_H


#include "eresizefocus.h"
#include <QGraphicsItem>
#include <QtGui>
#include <QGraphicsRectItem>
#include <QPointF>


class MyStarryItem : public QGraphicsItem
{
public:
	enum MouseMode{MOVE,RESIZE};
	enum { Type = UserType + 102 };

	MyStarryItem(QGraphicsItem *parent = 0);
	MyStarryItem(qreal w,qreal h,qreal m,QGraphicsItem *parent = 0);
	~MyStarryItem();

	//由于QGraphicsItem是抽象基类，所以至少要实现两个纯虚函数boundingrect,paint
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

	virtual int type() const {return Type;};

 protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
	void createResizeFocus();
	void showResizeFocus(bool visible);

private:
	
	qreal width;
	qreal height;
	qreal margin;
	QPointF lastPoint;

	MouseMode myMode;
	QList<EResizeFocus*> resizeFocus;
	EResizeFocus *curResizeFocus;
	QGraphicsRectItem *dashRect;
};

#endif // MYSTARRYITEM_H
