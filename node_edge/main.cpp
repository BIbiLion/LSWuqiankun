#include <QApplication>

#include <QGraphicsView>
#include <QGraphicsScene>
#include "node.h"
#include "edge.h"

#include <QGraphicsRectItem>
#include "testitem.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    Widget w;
    //    w.show();

    QGraphicsScene  graphicsScene;
    graphicsScene.setSceneRect(20,20,800,800);

   // graphicsScene.setItemIndexMethod(QGraphicsScene::NoIndex);


    QGraphicsView graphicView;
    graphicView.setRenderHint(QPainter::Antialiasing);
    graphicView.setScene(&graphicsScene);


    TestItem _item(&graphicsScene);//red
    graphicsScene.addItem(&_item);


    TestItem _item2(&graphicsScene);//red
    graphicsScene.addItem(&_item2);

   //  _item.setPos(300,300);
    //graphicsScene.addText("hello  QGraphics!!!");

    //graphicsScene.addLine(QLineF(20,20,800,800));
    Node _node(&graphicsScene);//yellow
    graphicsScene.addItem(&_node);
    _node.setPos(400,400);

    Node _node2(&graphicsScene);//yellow
    graphicsScene.addItem(&_node2);
    _node2.setPos(400,500);


     Edge _edge(&_node,&_node2);
   graphicsScene.addItem(&_edge);





    /*
        Node _node2;
         _node2.setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
     graphicsScene.addItem(&_node2);
     _node2.setPos(600,600);

       Edge _edge;
      graphicsScene.addItem(&_edge);
      _edge.setPos(500,500);

*/
/*
      QGraphicsRectItem _item(0,0,200,200);
      _item.setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
       graphicsScene.addItem(&_item);
 */

    graphicView.show();
    return a.exec();
}
