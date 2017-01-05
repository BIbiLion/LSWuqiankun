#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-500,-500,1000,1000);
    ui->graphicsView->centerOn(0,0);
    item=new MyItem;
    scene->addItem(item);
    item->setPos(0,0);
    timer=new QTimer;
    //connect(timer,SIGNAL(timeout()),this,SLOT(on_Timer_Slot()));
   // timer->start(100);
    Scale=0;
}

void MainWindow::on_Timer_Slot(){
    if(item!=NULL){
        QRectF tem=QRectF(-Scale/2,-Scale/2,Scale,Scale);
        item->ResetRect(tem);
        Scale+=2;
        if(Scale==150)Scale=0;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
