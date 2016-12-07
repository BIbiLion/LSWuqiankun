#include "clockqt.h"
#include <QPainter>
#include <QTime>
QPoint sec[4] = {QPoint(0, 10), QPoint(3, 0), QPoint(0, -90), QPoint(-3, 0)};
QPoint min[4] = {QPoint(0, 8), QPoint(5, 0), QPoint(0, -70), QPoint(-5, 0)};
QPoint hour[4] = {QPoint(0, 6), QPoint(7, 0), QPoint(0, -50), QPoint(-7, 0)};

Clockqt::Clockqt(QWidget *parent) :
    QWidget(parent)
{
    //ctor
        resize(200, 200);
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));//update()会自动产生重绘消息，调用paintEvent()
        timer->start(1000);
}
  void Clockqt::paintEvent(QPaintEvent *event)
  {
      QPainter painter(this);
         painter.setRenderHint(QPainter::Antialiasing);
         //painter.translate(100, 100);
         painter.setWindow(-100, -100, 200, 200);

         //绘制大刻度
         painter.save(); //save() 与 restore() 必须是一一对应的
         for (int i = 0; i < 60 ; ++i)
         {
             painter.rotate(6);  //rotate()是顺时针旋转坐标轴
             if (i % 5 == 4)
             {
                 painter.setPen(QPen(Qt::black, 5));
                 painter.drawLine(0, -90, 0, -100);
             }
             else
             {
                 painter.setPen(QPen(Qt::black, 1));
                 painter.drawLine(0, -95, 0, -100);
             }
         }
         painter.restore();

         int s = QTime::currentTime().second();
         int m = QTime::currentTime().minute();
         int h = QTime::currentTime().hour();

         painter.drawText(-20, 50, QTime::currentTime().toString());

         painter.save();
         painter.rotate(((h % 12) +  static_cast<double>(m / 60.0)) * 30);
         painter.setBrush(Qt::blue);
         painter.setPen(Qt::blue);
         painter.drawConvexPolygon(hour, 4);
         painter.restore();

         painter.save();
         painter.rotate(m * 6);
         painter.setBrush(Qt::green);
         painter.setPen(Qt::green);
         painter.drawConvexPolygon(min, 4);
         painter.restore();

         painter.save();
         painter.rotate(s * 6);
         painter.setBrush(Qt::red);
         painter.setPen(Qt::red);
         painter.drawConvexPolygon(sec, 4);
         painter.restore();

  }
