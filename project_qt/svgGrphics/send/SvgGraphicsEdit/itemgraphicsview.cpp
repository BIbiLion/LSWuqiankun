#include "itemgraphicsview.h"
#include "diagramscene.h"
#include "mainwindow.h"
#include "typeDef.h"
#include <QtGui>

ItemGraphicsView::ItemGraphicsView(QGraphicsScene * scene,QWidget *parent)
	: QGraphicsView(scene,parent)
{


}

ItemGraphicsView::~ItemGraphicsView()
{

}



void  ItemGraphicsView:: dragMoveEvent(QDragMoveEvent *event)
{

	if (event->mimeData()->hasText()) {
         if (children().contains(event->source())) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
         } else {
             event->acceptProposedAction();
         }
     } else {
         event->ignore();
     }
	 
}


void ItemGraphicsView::dragEnterEvent(QDragEnterEvent *event)

 {

 if (event->mimeData()->hasText()) {
         if (children().contains(event->source())) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
         } else {
             event->acceptProposedAction();
         }
     } else {
         event->ignore();
     }
 }

void ItemGraphicsView::dropEvent(QDropEvent *event)

 {

	 if (event->mimeData()->hasText()) {

		 QString str = event->mimeData()->text();
         QStringList strList = event->mimeData()->text().split(QRegExp("\\s+"),
                              QString::SkipEmptyParts);
         QPoint position = event->pos();
		 QPointF  scenPoint = this->mapToScene(position);

		 DirStruct dir;
 
	     dir.staId     = strList[0].toInt();
		 dir.staName   = strList[1];
		 dir.lineId    = strList[2].toInt();
		 dir.lineName  = strList[3];
		 dir.equipId   = strList[4].toInt();
		 dir.equipName = strList[5];
		 dir.type      = strList[6].toInt();

		 DiagramScene *scene = (DiagramScene *)this->scene();
		
         switch(dir.type)
		 {
			 case STATION:
				 scene->dragItem(scenPoint,DiagramScene::Insert_Station,dir);
				 break;
			 case EQUIP:
				 scene->dragItem(scenPoint,DiagramScene::Insert_Equip,dir);
				 break;
				
			 default:
				 break;
		 }		 

         if (children().contains(event->source())) {
             event->setDropAction(Qt::MoveAction);
             event->accept();
         } else {
             event->acceptProposedAction();
         }
     } else {
         event->ignore();
     }

 }


void ItemGraphicsView:: mouseMoveEvent ( QMouseEvent * e ) 
{
	QPointF pF = e->pos();

	if (pF.x() < 5)
		MainWindow::m_self->setToolBoxDockVisual(true);
	else
		MainWindow::m_self->setToolBoxDockVisual(false);


	QGraphicsView::mouseMoveEvent(e);

}