#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include <QGraphicsScene>
#include <QtXml/QtXml>
#include "typeDef.h"

class CustomGraphicsItem;
class QMenu;
class QDragMoveEvent;
class QDragEnterEvent;
class QDropEvent;

class DiagramScene : public QGraphicsScene
{
	Q_OBJECT

public:
	enum Mode { 
		
				InsertItem,                    InsertRectangle,                  Insert_HorizonalBeeline,             Insert_VerticalBeeline   ,
				InsertStarry,                  InsertElipase,                    InsertCircle,                        InsertTriangle,
				Insert_HorizonalCapacitor,     Insert_VerticalCapacitor,         Insert_HorizonalTerminal,            Insert_VerticalTerminal,
				Insert_HorizonalContainer,     Insert_VerticalContainer,         Insert_HorizonalKnivesSwitch,        Insert_VerticalKnivesSwitch,
				Insert_HorizonalBottomLine,    Insert_VerticalBottomLine,        InsertGeneratrix,                    Insert_Left_CurrentInductance,
				Insert_Right_CurrentInductance,Insert_HorizonalVoltageInductance,Insert_VerticalVoltageInductance,    Insert_HorizonalBreaker,
				Insert_VerticalBreaker,        InsertSplitReactor,InsertReactor, InsertTransformer,Inserttransformer1,InsertPowerHouse,             
				Insert_Top_Line,               Insert_Bottom_Line,               Insert_Left_Line,                    Insert_Right_Line,            
				InsertText,                    Insert_Equip,                     Insert_Station,                      MoveItem,                            
				SelectItem
	    };

	DiagramScene(QMenu *itemMenu,QObject *parent= NULL);
	~DiagramScene();

private:
      
	  CustomGraphicsItem  *customItem;
	  Mode				  myMode;
	  QMenu				  *myItemMenu;	 
	  QGraphicsRectItem   *selRectItem;
	  QPointF             lastPoint;
	  QPointF             endPoint;
	  bool                textFinish;
	  bool                modifyText;
	  QColor              m_fillColor;
	  QColor              m_penColor;
	  qreal               m_penWidth;
	  QFont               m_font;
	  QDomDocument        doc;
	  bool                m_flag ;

	  QList<CustomGraphicsItem*> copyItemList;

	  void initVar();

	  //XML
	  bool loadXmlFile(QString fileName);
	  void phaseXMLFile();

	  void setGraphicsItemsEditModel(bool flag);
	  void UnselectAllItem();

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	void keyPressEvent( QKeyEvent * keyEvent ); 

	virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

public:

	void setPenColor(QColor color);
	void setFillColor(QColor color);
	void setPenWidth(int width);
	void setAngle(qreal angle);
	void setLeftArrange();
	void setRightArrange();
	void setTopArrange();
	void setbottom();
	void itemCopy();
	void itemPasve();
	void setFont(QFont font);
	void selectAllItem();
	void deleteAllItem();
	void deleteStaEquipItem();
	void setSceneSize(int width,int height);
	void initScene();
	
	void openXMLfile(QString fileName);
	void saveSvgFile(QString fileName);
	void saveScdFile(QString fileName);
	void openSCDXMLFile(QString fileName);

	void dragItem(QPointF pos,Mode mode,DirStruct dir);

	void setEditShowModel(bool flag); 
	bool editShowModel();

public slots:
    void setMode(Mode mode);
	
	
};

#endif // DIAGRAMSCENE_H
