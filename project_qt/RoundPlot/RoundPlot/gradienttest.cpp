#include "gradienttest.h"
#include <QPainter>
gradientTest::gradientTest(QWidget *parent) : QWidget(parent)
{

}

 void gradientTest::paintEvent(QPaintEvent *)
 {
     int x=50,y=50,radius_=10,alpha=255;
     QRadialGradient gradient(x, y, radius_);
     gradient.setColorAt(0, QColor(0, 0, 0, alpha));
     gradient.setColorAt(1, QColor(0, 0, 0, 0));

     QPainter painter(this);
     painter.setPen(Qt::NoPen);
     painter.setBrush(gradient);
     painter.drawEllipse(QPoint(x, y), radius_, radius_);

 }
