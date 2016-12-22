#ifndef CUSTOMGRAPHICSITEM_H
#define CUSTOMGRAPHICSITEM_H

#include "eresizefocus.h"
#include <QGraphicsItem>
#include <QtGui>
#include <QGraphicsRectItem>
#include <QPointF>
#include <QtXml/QtXml>

class CustomGraphicsItem : public QGraphicsItem
{
public:
	enum MouseMode{MOVE,RESIZE};
	CustomGraphicsItem(quint16 tmpType,QGraphicsItem *parent = 0);
	CustomGraphicsItem(quint16 tmpType,qreal w,qreal h,qreal m,QGraphicsItem *parent = 0);
	~CustomGraphicsItem();

	//由于QGraphicsItem是抽象基类，所以至少要实现两个纯虚函数boundingrect,paint
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

	//重载
	virtual int type() const  {return m_type;};

 protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
	void createResizeFocus();
	void showResizeFocus(bool visible);
	void setResizeBrush();

private:
	
	qreal		m_width;
	qreal		m_height;
	qreal		m_margin;
	QPointF		m_lastPoint;	
	int			m_type;
	QPen		m_pen;
	qreal		m_penWidth;
	qreal		m_penSelWidth;
	QColor		m_fillColor;
	QColor		m_penColor;
	QFont		m_font;
	bool        m_flag ;
	
	qint16	    angle;
	
	MouseMode				myMode;
	QList<EResizeFocus*>	resizeFocus;
	EResizeFocus			*curResizeFocus;
	QGraphicsRectItem		*dashRect;

   void initVar();

public:

	QString     m_staId;
	QString     m_staName;
	QString     m_lineName;
	QString     m_lineId;
	QString     m_equip;
	QString     m_equipId;
	QString		m_strText;
	
	int		width();
	int		height();
	void	setPenColor(const QColor color); 
	void	setPenWidth(int penWidth);
	void	setFillColor(const QColor color);
    void	setFont(QFont font);
	void	setText(QString str);
	void	saveItem(QDomDocument doc,QDomElement root);
	void    saveScdItem(QDomDocument doc,QDomElement root);
	QString fontText();
	void    setEditShowModel(bool flag); 
	bool    editShowModel();


	const CustomGraphicsItem &operator=(const CustomGraphicsItem &right  );
	void setAngle(qint16 tmpAngle);
	

};

#endif // CUSTOMGRAPHICSITEM_H
