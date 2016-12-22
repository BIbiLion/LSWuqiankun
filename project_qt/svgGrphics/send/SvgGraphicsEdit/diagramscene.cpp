#include "diagramscene.h"
#include "customgraphicsitem.h"
#include "typedef.h"
#include "mainwindow.h"
#include "equipselectwidget.h"
#include <QtGui>
#include <QtXml/QtXml>
#include "mainwindow.h"

DiagramScene::DiagramScene(QMenu *itemMenu,QObject *parent)
	: QGraphicsScene(parent)
{
    myItemMenu = itemMenu;
	setItemIndexMethod(NoIndex);
	initVar();	
    
}

DiagramScene::~DiagramScene()
{



}

void DiagramScene::initVar()
{
	lastPoint.setX(0.0);
	lastPoint.setY(0.0);
	endPoint.setX(0.0);
	endPoint.setY(0.0);
	textFinish = false;
	modifyText = false;
	selRectItem = NULL;
	m_penColor = Qt::cyan;
	m_fillColor = Qt::white;
	m_penWidth = 1;
	
	this->setSceneRect(QRectF(0, 0, 800, 600));
	this->setBackgroundBrush(QBrush(Qt::white));
	m_font = QFont("Helvetica", 12); 

}

void DiagramScene::initScene()
{
    deleteAllItem();
	initVar();

}

void DiagramScene::setMode(Mode mode)
{
    myMode = mode;
}

void DiagramScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() == Qt::RightButton)
	{   
		CustomGraphicsItem *item1= (CustomGraphicsItem *)(this->itemAt(mouseEvent->scenePos()));
		if (item1 != NULL)
		{
			if (item1->type() == EQUIP_GRAPHICSITEM)
				MainWindow::m_self->addContextMenuAction(editShowModel(),true);

		}
		else
		{
			MainWindow::m_self->addContextMenuAction(editShowModel(),false);
		}
			

		return ;
	}
      

	
    if (!editShowModel())
		 return ;

	QGraphicsItem *item = this->itemAt(mouseEvent->scenePos());
	if ((item == NULL) && (myMode == MoveItem ))
	{
		myMode = SelectItem;
		foreach (QGraphicsItem *item, this->selectedItems()) {

			item->setSelected(false);
		}
	}
		 


    switch (myMode) {
        case InsertItem:					
            break;
		case InsertRectangle:
			customItem = new CustomGraphicsItem(RECTANGLE_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());		
			break;
        case Insert_HorizonalBeeline:		
            customItem = new CustomGraphicsItem(BELLLINE_HORIZONTAL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
            break;
		case Insert_VerticalBeeline:
			customItem = new CustomGraphicsItem(BELLLINE_VERTICAL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case InsertStarry:
			customItem = new CustomGraphicsItem(STARRY_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());			
			break;
		case InsertElipase:
		    customItem = new CustomGraphicsItem(ELLIPSE_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case InsertTriangle:
		    customItem = new CustomGraphicsItem(TRIANGLE_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_HorizonalCapacitor:
		    customItem = new CustomGraphicsItem(CAPACTIOR_HORIZONTAL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_VerticalCapacitor:
			customItem = new CustomGraphicsItem(CAPACTIOR_VERTICAL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_VerticalTerminal:
			customItem = new CustomGraphicsItem(TERMINAL_VERTICAL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_HorizonalTerminal:
			break;
		case Insert_HorizonalContainer:
		    customItem = new CustomGraphicsItem(CONTAINER_HORIZONTAL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_VerticalContainer:
			customItem = new CustomGraphicsItem(CONTAINER_VERTICAL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_HorizonalKnivesSwitch:
			customItem = new CustomGraphicsItem(KNIVESSWITCH_HORIZONTAL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_VerticalKnivesSwitch:
			customItem = new CustomGraphicsItem(KNIVESSWITCH_VERTICALL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_VerticalBottomLine:
			customItem = new CustomGraphicsItem(BOTTOMLINE_VERTICALL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_HorizonalBottomLine:
			customItem = new CustomGraphicsItem(BOTTOMLINE_HORIZONTAL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case InsertGeneratrix:
			customItem = new CustomGraphicsItem(GENERATRIX_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_Left_CurrentInductance:
			customItem = new CustomGraphicsItem(CURRENTINDUCTANCE_LEFT_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());
			break;
		case Insert_Right_CurrentInductance:
			customItem = new CustomGraphicsItem(CURRENTINDUCTANCE_RIGHT_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());
			break;
		case Insert_HorizonalVoltageInductance:
			customItem = new CustomGraphicsItem(VOLTAGEINDUCTANCE_HORIZONTAL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_VerticalVoltageInductance:
			break;
		case Insert_VerticalBreaker:
			customItem = new CustomGraphicsItem(BREAKER_VERTICAL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_HorizonalBreaker:
			customItem = new CustomGraphicsItem(BREAKER_HORIZONTAL_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case InsertSplitReactor:
			customItem = new CustomGraphicsItem(SPLITREACTOR_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case InsertReactor:
			customItem = new CustomGraphicsItem(REACTOR_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case InsertTransformer:
			customItem = new CustomGraphicsItem(TRANSFORMER_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Inserttransformer1:
			customItem = new CustomGraphicsItem(TRANSFORMER1_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case InsertPowerHouse:
			customItem = new CustomGraphicsItem(POWERHOUSE_GRAPHICSITEM);
			setPenColor(m_penColor);
			setFillColor(m_fillColor);
			setPenWidth(m_penWidth);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_Top_Line:
            customItem = new CustomGraphicsItem(LINE_TOP_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());			
			break;
		case Insert_Bottom_Line:
            customItem = new CustomGraphicsItem(LINE_BUTTOM_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());			
			break;
		case Insert_Left_Line:
            customItem = new CustomGraphicsItem(LINE_LEFT_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());			
			break;
		case Insert_Right_Line:
            customItem = new CustomGraphicsItem(LINE_RIGHT_GRAPHICSITEM);
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());			
			break;
        case InsertText:

			if (modifyText)
			{				
				QLineEdit	* ptrEdit = ((MainWindow *)this->parent())->m_textEdit;
				QString strText = ptrEdit->text();
				customItem->setText(strText);
				modifyText = false;
				((MainWindow *)this->parent())->showTextEdit(QPointF(0,0),false);	
			
			}
			else
			{

				if (textFinish == false)
				{
					QPointF tp = mouseEvent->scenePos();
					((MainWindow *)this->parent())->showTextEdit (QPointF(tp.rx(),tp.ry()),true);				
					textFinish = true;
					return ;

				}else{

					QLineEdit	* ptrEdit = ((MainWindow *)this->parent())->m_textEdit;
					QString strText = ptrEdit->text();
					customItem = new CustomGraphicsItem(TEXT_GRAPHICSITEM);	
					customItem->setFont(m_font);
					customItem->setText(strText);
					addItem(customItem);	
					customItem->setPos(mouseEvent->scenePos());	
					((MainWindow *)this->parent())->showTextEdit(QPointF(0,0),false);	
					textFinish = false;

				}

			}

			
            break;
		case Insert_Equip:
			customItem = new CustomGraphicsItem(EQUIP_GRAPHICSITEM);	
			customItem->setFont(m_font);
			customItem->setText(tr("保护装置"));
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
			break;
		case Insert_Station:
			customItem = new CustomGraphicsItem(STATION_GRAPHICSITEM);	
			customItem->setFont(m_font);
			customItem->setText(tr("子站名称"));
			addItem(customItem);	
			customItem->setPos(mouseEvent->scenePos());	
		case SelectItem:
			lastPoint = mouseEvent->scenePos(); 
			return ;
			break;
        default:
            break;
    }

    if((myMode >= InsertItem) && (myMode <= Insert_Station))
	{
		customItem->setPenColor(m_penColor);
		customItem->setFillColor(m_fillColor);
		customItem->setPenWidth(m_penWidth);
	}
	
	setMode( MoveItem);

    QGraphicsScene::mousePressEvent(mouseEvent);
}

void DiagramScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
  
   if (myMode == MoveItem) {

        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }else if (myMode == SelectItem)
	{   
		if (selRectItem)
		{
			removeItem(selRectItem);
			delete selRectItem;
			selRectItem = NULL;
		}

		if (lastPoint.x() != 0 && lastPoint.y() != 0)
		{
			endPoint  =  mouseEvent->scenePos();
			selRectItem = new QGraphicsRectItem(lastPoint.x(),lastPoint.y(),endPoint.x()-lastPoint.x(),endPoint.y()-lastPoint.y());
			QPen pen(Qt::DotLine);
			pen.setColor(m_penColor);
			selRectItem->setPen(pen);
			addItem(selRectItem);
		}

		
	}

	 
	 this->update();
}



void DiagramScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    if (myMode == SelectItem){
	
		removeItem(selRectItem);
		delete selRectItem;
		selRectItem = NULL;
		
		QList<QGraphicsItem *> list = this->items();
		 foreach (QGraphicsItem *item, list) {
			QPointF pos = item->pos();
			if( (pos.x()> lastPoint.x() ) && (pos.x() < endPoint.x()) && (pos.y() > lastPoint.y()) && (pos.y() < endPoint.y()) )
			{
				item ->setSelected(true);
			}
		 }

		lastPoint.setX(0.0);
		lastPoint.setY(0.0);
		endPoint.setX(0.0);
		endPoint.setY(0.0);		
	}else if ((myMode == InsertText) )
	{
		 QGraphicsScene::mouseReleaseEvent(mouseEvent);
		 return ;
	}

 
	setMode(MoveItem); 
	
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}



void DiagramScene::dragItem(QPointF pos,Mode mode,DirStruct dir)
{
	myMode = mode;

	 switch (myMode) {
		case Insert_Equip:
			customItem = new CustomGraphicsItem(EQUIP_GRAPHICSITEM);		
			customItem->setFont(m_font);
			customItem->setText(dir.equipName);
			customItem->m_lineName = dir.lineName;
			customItem->m_lineId = QString("%1").arg(dir.lineId);
			customItem->m_equip = dir.equipName;
			customItem->m_equipId =  QString("%1").arg(dir.equipId);
			addItem(customItem);	
			customItem->setPos(pos);	
			break;
		case Insert_Station:
            customItem = new CustomGraphicsItem(STATION_GRAPHICSITEM);		
			customItem->setFont(m_font);
			customItem->setText(dir.staName);
			customItem->m_staId = QString("%1").arg(dir.staId);
			customItem->m_staName = QString("%1").arg(dir.staName);
			addItem(customItem);	
			customItem->setPos(pos);	
			break;
	 }
	

	setMode( MoveItem);
	this->update();
}




void DiagramScene::contextMenuEvent ( QGraphicsSceneContextMenuEvent * contextMenuEvent )
{
    myItemMenu->exec(contextMenuEvent->screenPos());
	QGraphicsScene::contextMenuEvent(contextMenuEvent);
}

void DiagramScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	QList<QGraphicsItem *> listItems = items(event->scenePos());

	
	foreach (QGraphicsItem *item, listItems) {
	
		CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
		if (item1->type() == TEXT_GRAPHICSITEM)
		{
			QString str = item1->fontText();
			QPointF tp = event->scenePos();
			((MainWindow *)this->parent())->setTextEdit(str);
			((MainWindow *)this->parent())->showTextEdit(QPointF(tp.rx(),tp.ry()),true);
			 modifyText = true;
			 myMode = InsertText;
			 customItem = item1;
		}
		else if (item1->type() == EQUIP_GRAPHICSITEM)
		{
			QString lineName = item1->m_lineName;
			QString lineId   = item1->m_lineId;
			QString equip    = item1->m_equip;
			QString equipId  = item1->m_equipId;
			QString equipName = item1->fontText();

			equipSelectWidget *dlg = new equipSelectWidget((MainWindow *)this->parent(),lineName,
				                                           lineId,equip,equipId,equipName);
			int code = dlg->exec();

			if (code == QDialog::Accepted)
			{
				item1->m_lineName = dlg->getLineName();
				item1->m_lineId = dlg->getLineId();
				item1->m_equip = dlg->getEquip();
				item1->m_equipId = dlg->getEquipId();
				item1->setText(dlg->getEquipName());
				
			}
			else if(code == QDialog::Rejected)
			{
			
			}

		}
		else if (item1->type() == STATION_GRAPHICSITEM)
		{

			QString staId = item1->m_staId;
			QString staName   = item1->m_staName;
			

			stationSelectWidget *dlg = new stationSelectWidget((MainWindow *)this->parent(),staId,staName);
			int code = dlg->exec();

			if (code == QDialog::Accepted)
			{
				item1->m_staName = dlg->getStatName();
				item1->m_staId = dlg->getStatId();
				item1->setText(dlg->getStatName());
				
			}
			else if(code == QDialog::Rejected)
			{
			
			}

		}

	}

	QGraphicsScene::mouseDoubleClickEvent(event);
}


void DiagramScene::keyPressEvent( QKeyEvent * keyEvent )
{

	//if (!editShowModel())
	//	return ;

    int key = keyEvent->key();
	bool flag = false;


	
	foreach (QGraphicsItem *item, this->selectedItems()) {
	
		CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);	
		QPointF tp = item1->scenePos();
		switch(key)
		{
			case 16777234:  //left
				tp.setX(tp.x()-1);
				break;
			case 16777235:  //up
				tp.setY(tp.y()-1);
				break;
			case 16777236:  //right
				tp.setX(tp.x()+1);
				break;
			case 16777237:  //down
				tp.setY(tp.y()+1);
				break;		
		}
	   
	    item1->setPos(tp);	
		flag = true;


	}
	
    if (!flag)
		QGraphicsScene::keyPressEvent(keyEvent);
}

void DiagramScene::setPenColor(QColor color)
{
	m_penColor = color;

	foreach (QGraphicsItem *item, this->selectedItems()) {

         CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
		 if (item1->isSelected())
			 item1->setPenColor(color);		
    }
}


void DiagramScene::setFillColor(QColor color)
{
	m_fillColor = color;
	
	foreach (QGraphicsItem *item, this->selectedItems()) {

         CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
		 if (item1->isSelected())
			 item1->setFillColor(color);		

    }

}

void DiagramScene::setPenWidth(int width)
{
	m_penWidth = width;

	foreach (QGraphicsItem *item, this->selectedItems()) {

         CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
		 if (item1->isSelected())
			 item1->setPenWidth(width);		

    }
}

void DiagramScene::setAngle(qreal angle)
{

	foreach (QGraphicsItem *item, this->selectedItems()) {

         CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
		 item1->setAngle(90);
		 item1->rotate(angle);		

    }

}


void DiagramScene::setLeftArrange()
{

	QPointF  minPointF(0,0);
	foreach (QGraphicsItem *item, this->selectedItems()) {
       
		 QPointF curPointF = item->pos();

		 if ((minPointF.x() == 0 ) && (minPointF.y() == 0))
			minPointF.setX(curPointF.x());
		 else
		 {
			if (curPointF.x() < minPointF.x() )			
			   minPointF.setX(curPointF.x());
		 }

		 
	}

	foreach (QGraphicsItem *item, this->selectedItems()) {	

	  item->setPos(minPointF.x(),item->pos().y());
	}


}

void DiagramScene::setRightArrange()
{

	QPointF  maxPointF(0,0);
	int      maxWidth;

	foreach (QGraphicsItem *item, this->selectedItems()) {
       
		 QPointF curPointF = item->pos();
		 CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);

		 if ((maxPointF.x() == 0 ) && (maxPointF.y() == 0)){
			maxPointF.setX(curPointF.x());
			maxWidth = item1->width();
		 
		 }else
		 {
			 if (curPointF.x() > maxPointF.x() )	{		
			   maxPointF.setX(curPointF.x());
			   maxWidth = item1->width();

			 }
		 }

		 
	}

	foreach (QGraphicsItem *item, this->selectedItems()) {	

	  CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
	  item->setPos(maxPointF.x()+maxWidth-item1->width(),item->pos().y());
	}


}


void DiagramScene::setTopArrange()
{

	QPointF  topPointF(0,0);
	foreach (QGraphicsItem *item, this->selectedItems()) {
       
		 QPointF curPointF = item->pos();

		 if ((topPointF.x() == 0 ) && (topPointF.y() == 0))
			topPointF.setY(curPointF.y());
		 else
		 {
			if (curPointF.y() < topPointF.y() )			
			   topPointF.setY(curPointF.y());
		 }

		 
	}

	foreach (QGraphicsItem *item, this->selectedItems()) {	

	  item->setPos(item->pos().x(),topPointF.y());
	}

}


void DiagramScene::setbottom()
{

	QPointF  botmPointF(0,0);
	int      botmHeight;

	foreach (QGraphicsItem *item, this->selectedItems()) {
       
		 QPointF curPointF = item->pos();
		 CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);

		 if ((botmPointF.x() == 0 ) && (botmPointF.y() == 0)){
			botmPointF.setY(curPointF.y());
			botmHeight = item1->height();
		 }else
		 {
			 if (curPointF.y() > botmPointF.y() ){			
			   botmPointF.setY(curPointF.y());
			   botmHeight = item1->height();
			 }
		 }

		 
	}

	foreach (QGraphicsItem *item, this->selectedItems()) {	
		
	  CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
	  item->setPos(item->pos().x(),botmPointF.y()+botmHeight-item1->height());
	}


}


void DiagramScene::itemCopy()
{
	
	foreach (QGraphicsItem *item, copyItemList){
		
		removeItem(item);
		delete item;
	}

	copyItemList.clear();


	foreach (QGraphicsItem *item, this->selectedItems()) {

		CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
		CustomGraphicsItem *item2 = new CustomGraphicsItem(0);

		*item2 = *item1;
		item1->setSelected(false);

		copyItemList.append(item2);
		
	}
}

void DiagramScene::itemPasve()
{

	foreach (QGraphicsItem *item, copyItemList) {

		CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
		CustomGraphicsItem *item2 = new CustomGraphicsItem(0);
		*item2 = *item1;
		addItem(item2);

		item2->setSelected(true);
		item2->setPos(item1->pos().x()+10,item1->pos().y()+10);

	}


}

void DiagramScene::setFont(QFont font)
{

	foreach (QGraphicsItem *item, this->selectedItems()) {

		CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
	    if ((item1->type() == TEXT_GRAPHICSITEM) || 
			(item1->type() == EQUIP_GRAPHICSITEM)|| 
			(item1->type() == STATION_GRAPHICSITEM) )
		{
			item1->setFont(font);

		}
		
	}

}


void DiagramScene::selectAllItem()
{

	foreach (QGraphicsItem *item, this->items()) {

		item->setFlags(QGraphicsItem::ItemIsSelectable);
		item->setSelected(true);
		
	}

}

void DiagramScene::deleteAllItem()
{
	selectAllItem();

	foreach (QGraphicsItem *item, selectedItems()) {
	
		CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
		int type = item->type();

	    if ((type>= BELLLINE_HORIZONTAL_GRAPHICSITEM) &&
			(type <= STATION_GRAPHICSITEM) )
		{
		    this->removeItem(item1);
			delete item1;
		}
		
	}

	this->update();
}

void DiagramScene::setSceneSize(int width,int height)
{

	this->setSceneRect(QRectF(0, 0, width, height));
	this->update();

}

void DiagramScene::deleteStaEquipItem()
{
    selectAllItem();

	foreach (QGraphicsItem *item, selectedItems()) {
	
		CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
	    if ((item1->type() == EQUIP_GRAPHICSITEM) ||
			(item1->type() == STATION_GRAPHICSITEM) )
		{
				this->removeItem(item);
				delete item;
		}
		
	}

	this->update();

}

void DiagramScene::saveSvgFile(QString fileName)
{

	QFile file(fileName);
	
	if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
	{
		return  ;
	}
	
	QDomDocument doc;
	QDomText text;
	QDomElement element;
	QString value;
	QDomProcessingInstruction instruction;

	//描述xml头
	instruction = doc.createProcessingInstruction("xml","version=\'1.0\' encoding=\'UTF-8\'");
	doc.appendChild(instruction);

	QDomElement root = doc.createElement("svg");
	doc.appendChild(root);

	value = QString("%1").arg(this->width());
	root.setAttribute("width",value);
	value = QString("%1").arg(this->height());
	root.setAttribute("height",value);
	root.setAttribute("xmlns",QString("http://www.w3.org/2000/svg"));
	root.setAttribute("xmlns:xlink",QString("http://www.w3.org/1999/xlink"));


    element = doc.createElement("rect");

	QDomAttr wdithAttr = doc.createAttribute("width");
	value = QString("%1").arg(this->width());
	wdithAttr.setValue(value);
	element.setAttributeNode(wdithAttr);

	value = QString("%1").arg(this->height());
	QDomAttr xAttrib = doc.createAttribute("x");
	xAttrib.setValue(tr("0"));
	element.setAttributeNode(xAttrib);

	
	QDomAttr yAttrib = doc.createAttribute("y");
	yAttrib.setValue(tr("0"));
	element.setAttributeNode(yAttrib);

	QDomAttr zAttrib = doc.createAttribute("z");
	zAttrib.setValue(tr("0"));
	element.setAttributeNode(zAttrib);

	QBrush brush = this->backgroundBrush();
	QColor color = brush.color();
    int value1 = color.red();
	int value2 = color.green();
	int value3 = color.blue();

	value = tr("#%1%2%3").arg(value1,2,16,QLatin1Char( '0' )).arg(value2,2,16,QLatin1Char( '0' )).arg(value3,2,16,QLatin1Char( '0'));
	QDomAttr colorAttrib = doc.createAttribute("fill");
	colorAttrib.setValue(value);
	element.setAttributeNode(colorAttrib);

	QDomAttr heightAttrib = doc.createAttribute("height");
	value = QString("%1").arg(this->height());
	heightAttrib.setValue(value);
	element.setAttributeNode(heightAttrib);

	QDomAttr strokeAttrib = doc.createAttribute("stroke");
	strokeAttrib.setValue(QString("none"));
	element.setAttributeNode(strokeAttrib);

	root.appendChild(element);

   foreach (QGraphicsItem *item, this->items()) {

		CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
		int value = item1->type();
		if ((value != STATION_GRAPHICSITEM) || (value != EQUIP_GRAPHICSITEM))
			item1->saveItem(doc,root);
		
	}


	QTextStream out(&file);
	doc.save(out, 4);

}


void DiagramScene::openXMLfile(QString fileName)
{

   if (loadXmlFile(fileName))  
		phaseXMLFile();

}


bool DiagramScene::loadXmlFile(QString fileName)
{

	QFile *xmlFile;
	xmlFile = new QFile(fileName);

	if (!xmlFile->open(QIODevice::ReadOnly)){

		QString title = QString("打开%1文件").arg(fileName);
		QString text  = QString("打开%1文件,可能不存在该文件!").arg(fileName);
		QMessageBox::warning(NULL,title,text);
        return false;
	}

    if (!doc.setContent(xmlFile)) {

		QString title = QString("装载%1文件").arg(fileName);
		QString text  = QString("装载%1文件,可能该XML文件有错误!").arg(fileName);
		QMessageBox::warning(NULL,title,text);

        xmlFile->close();
        return false;
    }
    xmlFile->close();

	return true;

}

void DiagramScene::phaseXMLFile()
{
     deleteAllItem();     //删除所有元素
	 initVar();

	 QDomNodeList rootList = doc.elementsByTagName("svg");
	 for (int i= 0 ; i < rootList.count() ;i++)
	 {
         //svg   node 
         QDomNode rootNode = rootList.item(i);
		 QString nodeName = rootNode.nodeName();
		 int width = rootNode.toElement().attribute("width").toInt();
		 int height = rootNode.toElement().attribute("height").toInt();
		 //设置场景大小
		 setSceneSize(width,height);


        //rect ,g   node
		QDomNodeList childNodeList = rootNode.childNodes(); 
		for (int j = 0 ; j < childNodeList.count() ; j++)
		{
 
			QDomNode node1 = childNodeList.item(j);
			QString  node1Name = node1.nodeName();

			//g  node
			if (node1Name != "rect")
			{
				 int classValue  = node1.toElement().attribute("class").toInt();
				 int width1 = node1.toElement().attribute("width").toInt();
				 int height1 = node1.toElement().attribute("height").toInt();
				 int posX = node1.toElement().attribute("posX").toInt();
				 int posY = node1.toElement().attribute("posY").toInt();
				 int stroke_width = node1.toElement().attribute("stroke-width").toInt();
				 QString strStroke =  node1.toElement().attribute("stroke");
				 QColor strokeColor(strStroke.mid(1,2).toInt(0,16),strStroke.mid(3,2).toInt(0,16),strStroke.mid(5,2).toInt(0,16));			
				 QString strFill = node1.toElement().attribute("fill");			
				 QColor fillColor(strFill.mid(1,2).toInt(0,16),strFill.mid(3,2).toInt(0,16),strFill.mid(5,2).toInt(0,16));


				 customItem = new CustomGraphicsItem(classValue,width1,height1,6);
				 //设置笔的宽度
                 customItem->setPenWidth(stroke_width);
				 //设置笔的颜色
				 customItem->setPenColor(strokeColor);
				 //设置填充色
                 customItem->setFillColor(fillColor);

				 if (classValue == TEXT_GRAPHICSITEM)
				 {
					 QDomNodeList childNodeList1 = node1.childNodes(); 

					 QDomNode node2;
					 
					 if (childNodeList.count() > 0)
					     node2 = childNodeList1.item(0);
					 else
						 continue;


					QString fontFamily = node2.toElement().attribute("font-family");
					QString fontWeight = node2.toElement().attribute("font-weight");
					QString fontSize   = node2.toElement().attribute("font-size");
					QString strText    = node2.toElement().text();

					QFont font(fontFamily,fontSize.toInt(),fontWeight.toInt());
					customItem->m_strText  = strText;
					customItem->setFont(font);

				 }

				 addItem(customItem);	
				 customItem->setPos(posX,posY);		
			}
			else //rect
			{
				QString strFill = node1.toElement().attribute("fill");			
				QColor fillColor(strFill.mid(1,2).toInt(0,16),strFill.mid(3,2).toInt(0,16),strFill.mid(5,2).toInt(0,16));
				
				//设置背景色
			    this->setBackgroundBrush(QBrush(fillColor));
				this->update();

			}
		}

	 }
}

void DiagramScene::saveScdFile(QString fileName)
{

	QFile file(fileName);
	
	if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
	{
		return  ;
	}
	
	QDomDocument doc;
	QDomText text;
	QDomElement element;
	QString value;
	QDomProcessingInstruction instruction;

	//描述xml头
	instruction = doc.createProcessingInstruction("xml","version=\'1.0\' encoding=\'UTF-8\'");
	doc.appendChild(instruction);

	QDomElement root = doc.createElement("scd");
	doc.appendChild(root);

	root.setAttribute("xmlns",QString("http://www.w3.org/2000/scd"));
	root.setAttribute("xmlns:xlink",QString("http://www.w3.org/1999/xlink"));

	//存储子站
    foreach (QGraphicsItem *item, this->items()) {

		CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
		int value = item1->type();
		if (value == STATION_GRAPHICSITEM)
			item1->saveScdItem(doc,root);
		
	}

	//存储装置
    foreach (QGraphicsItem *item, this->items()) {

		CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
		int value = item1->type();
		if (value == EQUIP_GRAPHICSITEM)
			item1->saveScdItem(doc,root);
		
	}


	QTextStream out(&file);
	doc.save(out, 4);
}


void DiagramScene::openSCDXMLFile(QString fileName)
{

	if (!loadXmlFile(fileName))  
		return ;

     deleteStaEquipItem();  //删除所有装置和站元素

	 QDomNodeList rootList = doc.elementsByTagName("scd");
	 for (int i= 0 ; i < rootList.count() ;i++)
	 {
         //svg   node 
         QDomNode rootNode = rootList.item(i);
		 QString nodeName = rootNode.nodeName();

        //g   node
		QDomNodeList childNodeList = rootNode.childNodes(); 
		for (int j = 0 ; j < childNodeList.count() ; j++)
		{
 
			QDomNode node1 = childNodeList.item(j);
			QString  node1Name = node1.nodeName();

		    int classValue  = node1.toElement().attribute("class").toInt();
		    int width1 = node1.toElement().attribute("width").toInt();
		    int height1 = node1.toElement().attribute("height").toInt();
			int posX = node1.toElement().attribute("posX").toInt();
			int posY = node1.toElement().attribute("posY").toInt();
			int stroke_width = node1.toElement().attribute("stroke-width").toInt();
			QString strStroke =  node1.toElement().attribute("stroke");
			QColor strokeColor(strStroke.mid(1,2).toInt(0,16),strStroke.mid(3,2).toInt(0,16),strStroke.mid(5,2).toInt(0,16));			
			QString strFill = node1.toElement().attribute("fill");			
		    QColor fillColor(strFill.mid(1,2).toInt(0,16),strFill.mid(3,2).toInt(0,16),strFill.mid(5,2).toInt(0,16));
			
			QDomNodeList endNodeList = node1.childNodes(); 

			for (int l = 0 ; l < endNodeList.count() ; l++)
			{
				QDomNode node2 = endNodeList.item(l);
				QString node2Name = node2.nodeName();

				QString fontFamily = node2.toElement().attribute("font-family");
				QString fontWeight = node2.toElement().attribute("font-weight");
				QString fontSize   = node2.toElement().attribute("font-size");

				QFont font(fontFamily,fontSize.toInt(),fontWeight.toInt());
				customItem = new CustomGraphicsItem(classValue,width1,height1,6);

				if (classValue ==  STATION_GRAPHICSITEM)
				{
					QString stationName   = node2.toElement().attribute("stationName");
					QString stationId     = node2.toElement().attribute("stationId");
					customItem->m_staId   = stationId;
					customItem->m_staName = stationName;
					customItem->m_strText  = stationName;


				}
				else if (classValue ==  EQUIP_GRAPHICSITEM)
				{
					QString lineId    = node2.toElement().attribute("lineId");
					QString lineName  = node2.toElement().attribute("lineName");
					QString equipId   = node2.toElement().attribute("equipId");
					QString equipName = node2.toElement().attribute("equipName");
					QString strText   = node2.toElement().text();

					customItem->m_lineId   = lineId;
					customItem->m_lineName = lineName;
					customItem->m_equipId  = equipId;
					customItem->m_equip    = equipName;
					customItem->m_strText  = strText;

				 }
					
				//设置字体
				customItem->setFont(font);
				//设置笔的宽度
				customItem->setPenWidth(stroke_width);
				//设置笔的颜色
				customItem->setPenColor(strokeColor);
				//设置填充色
				customItem->setFillColor(fillColor);

				addItem(customItem);	
				customItem->setPos(posX,posY);		
				

			}
			
			
		}

	 }

	 UnselectAllItem();
}


void DiagramScene::setEditShowModel(bool flag)
{
    m_flag = flag;
	setGraphicsItemsEditModel(flag);
}

bool DiagramScene::editShowModel()
{
	return m_flag;
}

void DiagramScene::UnselectAllItem()
{
	foreach (QGraphicsItem *item, this->items()) {
		
			item->setSelected(false);
			
	}
}

void DiagramScene::setGraphicsItemsEditModel(bool flag)
{
	selectAllItem();

	foreach (QGraphicsItem *item, selectedItems()) {
	
		CustomGraphicsItem *item1= (CustomGraphicsItem *)(item);
	    
		item1->setEditShowModel(flag);
	}

	UnselectAllItem();


}