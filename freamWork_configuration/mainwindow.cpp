#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCursor>
#include <QMouseEvent>

#include "simpleitem.h"
#include "mygraphicsview.h"
#include "myscene.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

  m_graphicsScene= new QGraphicsScene(00, 00, 400, 400);


  m_graphicsView= new QGraphicsView(m_graphicsScene,this);
  m_graphicsView->setAcceptDrops(true);
  m_graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

  ui->middleLayout->addWidget(m_graphicsView);
 // m_graphicsScene->addText("Hello world!");


 // m_graphicsScene->addItem();
  SimpleItem * _item = new SimpleItem(m_graphicsView);
  m_graphicsScene->addItem(_item);



  //right
   MyScene * _myScene= new MyScene();
  m_view= new MyGraphicsView(_myScene);
  SimpleItem * _item2 = new SimpleItem(m_view);
  m_graphicsScene->addItem(_item2);
 _myScene->addItem(_item);
 _myScene->addLine(0,0,100,100);
  ui->rightLayout->addWidget(m_view);


  m_toolButton = new ToolButton(this);
  ui->leftLayout->addWidget(m_toolButton);
  m_toolButton->setText("Circle");
  m_toolButton->setIcon(QIcon(":/image/Lighthouse.jpg"));
  m_toolButton->setIconSize(QSize(80,80));
  m_toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
 // m_toolButton->setAcceptDrops(true);



}

MainWindow::~MainWindow()
{
    delete ui;
}





