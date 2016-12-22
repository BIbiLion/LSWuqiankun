#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
//http://www.qtcn.org/bbs/read-htm-tid-25500-fpage-15.html
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


 void Dialog::paintEvent(QPaintEvent *)
 {

     //Qt中每一个窗口都有一个坐标系，默认的，窗口左上角为坐标原点，然后水平向右依次增大，水平向左依次减小，垂直向下依次增大，垂直向上依次减小。原点即为（0，0）点，然后以像素为单位增减。
     /*
       QPainter painter(this);
       painter.setBrush(Qt::red);
       painter.drawRect(0,0,100,100);
       painter.setBrush(Qt::yellow);
       painter.drawRect(-50,-50,100,100);
   */


     //translate
      /* QPainter painter(this);
        painter.setBrush(Qt::yellow);
        painter.drawRect(0,0,50,50);

       painter.translate(100,100); //将点（100，100）设为原点
        painter.setBrush(Qt::red);
        painter.drawRect(0,0,50,50);

       painter.translate(-100,-100);
        painter.drawLine(0,0,20,20);
        */

     //scale
     /*  QPainter painter(this);
       painter.setBrush(Qt::yellow);
       painter.drawRect(0,0,100,100);

       painter.scale(2,2); //放大两倍(宽，高)
       painter.setBrush(Qt::red);
       painter.drawRect(50,50,50,50);
       */

       //shear 扭曲变形
        /*
         QPainter painter(this);
         painter.setBrush(Qt::yellow);
         painter.drawRect(0,0,50,50);

         painter.shear(0,1); //纵向扭曲变形 0不扭曲
         painter.setBrush(Qt::red);
         painter.drawRect(50,0,50,50);
         */

     //rotate
     /*
       QPainter painter(this);
        painter.drawLine(0,0,100,0);
        painter.rotate(30); //以原点为中心，顺时针旋转30度

        painter.drawLine(0,0,100,0);

        painter.translate(100,100);
        painter.drawLine(0,0,100,0);

        painter.rotate(30);

        painter.drawLine(0,0,100,0);

  */
     QPainter painter(this);
     painter.translate(this->width()/2,this->height()/2);

     for(int i=0; i<12;++i)
     {
         painter.rotate(30);
         painter.drawLine(100,0,120,0);

     }


        //我们可以先利用save()函数来保存坐标系现在的状态，然后进行变换操作，操作完之后，再用restore()函数将以前的坐标系状态恢复，其实就是一个入栈和出栈的操作。
}
