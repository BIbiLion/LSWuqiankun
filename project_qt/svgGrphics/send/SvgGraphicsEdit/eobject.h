#ifndef EOBJECT_H
#define EOBJECT_H

#include "eresizefocus.h"

#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QFocusEvent>
#include <QList>
#include <QPointF>

class EObject : public QGraphicsItem
{

public:
	enum MouseMode{MOVE,RESIZE};
	enum { Type = UserType + 100 };

	EObject(QGraphicsItem *parent = 0);
	EObject(qreal w,qreal h,qreal m, QGraphicsItem *parent = 0);
	~EObject();

	virtual int type() const {return Type;};
	QRectF boundingRect() const;
    QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

 protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

	void showResizeFocus(bool visible);

private:
	void createResizeFocus();

private:
	qreal width;
	qreal height;
	qreal margin;

	MouseMode myMode;
	QColor myColor;

	QGraphicsTextItem *name;
	QGraphicsPixmapItem *symbol;
	QGraphicsRectItem *state;

	QList<EResizeFocus*> resizeFocus;
	EResizeFocus *curResizeFocus;
	QPointF lastPoint;
	QGraphicsRectItem *dashRect;
};

#endif // EOBJECT_H
