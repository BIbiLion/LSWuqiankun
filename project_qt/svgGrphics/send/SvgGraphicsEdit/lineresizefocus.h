#ifndef LINERESIZEFOCUS_H
#define LINERESIZEFOCUS_H

#include <QGraphicsRectItem>
#include <QCursor>

class LineResizeFocus : public QGraphicsRectItem
{
public:
    enum PosInHost{LEFT_HORIZ_NODE,RIGHT_HORIZ_NODE,TOP_VER_NODE,BOTTOM_VER_NODE};
	enum LineShape{HORIZ_LINE,VER_LINE};
	enum { Type = UserType + 2 };

	LineResizeFocus(PosInHost pos, QGraphicsItem *parent);
	LineResizeFocus(qreal len, PosInHost pos, QGraphicsItem *parent);
	~LineResizeFocus();

	int type() const {return Type;};
	void setInHost(PosInHost pos){posInHost = pos;};
	PosInHost getInHost(){return posInHost;};
	void locateInHost(qreal tmpX,qreal tmpY);
private:
	qreal wsize;
	PosInHost posInHost;

protected:
	void hoverEnterEvent ( QGraphicsSceneHoverEvent * event ) ;
	void hoverLeaveEvent ( QGraphicsSceneHoverEvent * event ) ;
};

#endif // LINERESIZEFOCUS_H
