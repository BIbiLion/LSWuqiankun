#ifndef ITEMGRAPHICSVIEW_H
#define ITEMGRAPHICSVIEW_H

#include <QGraphicsView>

class QDragMoveEvent;
class QDragEnterEvent;
class QDropEvent;
class QMouseEvent;


class ItemGraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	ItemGraphicsView( QGraphicsScene * scene,QWidget *parent=0);
	~ItemGraphicsView();

protected:

	void dragMoveEvent(QDragMoveEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);

    void mouseMoveEvent ( QMouseEvent * e ) ;

private:
	
};

#endif // ITEMGRAPHICSVIEW_H
