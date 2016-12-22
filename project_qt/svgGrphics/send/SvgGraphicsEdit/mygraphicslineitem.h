#ifndef MYGRAPHICSLINEITEM_H
#define MYGRAPHICSLINEITEM_H

#include <QGraphicsLineItem>

class LineResizeFocus;

class MyGraphicsLineItem : public QGraphicsLineItem
{

public:
	
	MyGraphicsLineItem(QMenu *contextMenu,const QLineF & line, QGraphicsItem * parent = 0);
	~MyGraphicsLineItem();
public:
	enum MouseMode{MOVE,RESIZE};
	enum { Type = UserType + 100 };

	virtual int type() const {return Type;};
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

private:
	
	LineResizeFocus *curResizeFocus;
	QList<LineResizeFocus*> resizeFocus;
	qreal margin;
	MouseMode myMode;
	QPointF lineFOrgn;  
	QMenu *myContextMenu;

	void createResizeFocus();
	void showResizeFocus(QLineF lineF,bool visible);
	int analystLineShape(QLineF lineF);   //分析直线是水平的还是垂直的

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
};

#endif // MYGRAPHICSLINEITEM_H
