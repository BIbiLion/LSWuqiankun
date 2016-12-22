#ifndef ERESIZEFOCUS_H
#define ERESIZEFOCUS_H

#include <QGraphicsRectItem>
#include <QCursor>

class EResizeFocus : public QGraphicsRectItem
{
public:
	enum PosInHost{NORTH_MIDDLE,NORTH_EAST,EAST_MIDDLE,SOUTH_EAST,SOUTH_MIDDLE,SOUTH_WEST,WEST_MIDDLE,NORTH_WEST};
	enum { Type = UserType + 1 };

	EResizeFocus(PosInHost pos, QGraphicsItem *parent);
	EResizeFocus(qreal len, PosInHost pos, QGraphicsItem *parent);
	~EResizeFocus();

	int type() const {return Type;};
	void setInHost(PosInHost pos){posInHost = pos;};
	PosInHost getInHost(){return posInHost;};

	void locateInHost();

	const EResizeFocus &operator=(const EResizeFocus &right  );

protected:
	void hoverEnterEvent ( QGraphicsSceneHoverEvent * event ) ;
	void hoverLeaveEvent ( QGraphicsSceneHoverEvent * event ) ;

public:
	PosInHost posInHost;
	qreal wsize;
};

#endif // ERESIZEFOCUS_H
