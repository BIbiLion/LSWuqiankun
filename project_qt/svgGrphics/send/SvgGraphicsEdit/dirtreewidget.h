#ifndef DIRTREEWIDGET_H
#define DIRTREEWIDGET_H

#include <QTreeWidget>

#ifndef __DirStruct__
#define __DirStruct__

	enum fillType{STATION,LINE,EQUIP};
		typedef struct {
		int staId;
		QString staName;
		int lineId;
		QString lineName;
		int equipId;
		QString equipName;
		fillType type;
    }DirStruct;
	
	//先注册DirStruct,Qvariant还不认识这个类型,这是一个Macro--只能在全局中使用--否则出现错误。
    Q_DECLARE_METATYPE(DirStruct)
#endif

class DirTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	DirTreeWidget(QWidget *parent= NULL);
	~DirTreeWidget();

private:

	QString   connectName;					//数据库连接名称
	QTreeWidgetItem *root ;
	QPoint        dragStartPosition ;

	QTreeWidgetItem* createChildItem(QTreeWidgetItem *item,DirStruct dirData);
	QString   getStationName();
	int       getStationId();
	void      fillLine(QTreeWidgetItem *parent,DirStruct dirData);
	void      fillEquip(QTreeWidgetItem *parent,DirStruct dirData);
	void      initTree();

protected:

	void  dragMoveEvent(QDragMoveEvent *event);
	void  dragEnterEvent(QDragEnterEvent *event);
	void  dropEvent(QDropEvent *event);

public slots:

    void  itemPressed( QTreeWidgetItem * item, int column );

};

#endif // DIRTREEWIDGET_H
