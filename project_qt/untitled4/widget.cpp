#include "widget.h"
#include <QMouseEvent>
#include <QResizeEvent>
#include <QPoint>
#include <QPointF>
#include <QDebug>
#include <math.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    currShape = LINE;
    curPen.setWidth(1);
    curBrush.setStyle(Qt::NoBrush);
    isMoving = false;
    tempImage = QImage(width(),height(),QImage::Format_ARGB32_Premultiplied);//临时显示Image
    bufferImage = QImage(width(),height(),QImage::Format_ARGB32_Premultiplied);//最终显示Image
    bufferImage.fill(qRgb(255,255,255));
    update();
}
void Widget::setShape(int shape)
{
    currShape = shape;
}
void Widget::setMyPen(QPen pen)
{
    curPen = pen;
}
void Widget::setMyBrush(QBrush brush)
{
    curBrush = brush;
}
void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setPen(curPen);
    painter.setBrush(curBrush);
    painter.setRenderHint(QPainter::Antialiasing);
    if(isMoving == false)
        painter.drawImage(QPoint(0,0),bufferImage);
    else
        painter.drawImage(QPoint(0,0),tempImage);
}
void Widget::mouseMoveEvent(QMouseEvent *e)
{

    isMoving = true;
    w = e->x() - x;
    h = e->y() - y;
    tempImage = bufferImage;
    paintImage(tempImage);
    update();

}
void Widget::mousePressEvent(QMouseEvent *e)
{
    x = e->x();
    y = e->y();
    w = h = 0.0;
}
void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    isMoving = false;
    paintImage(bufferImage);
    update();
}
void Widget::paintImage(QImage &image)
{
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(curPen);
    painter.setBrush(curBrush);
    switch(currShape)
    {
         case RECTANGLE:painter.drawRect(x,y,w,h);break;
         case CIRCLE   :painter.drawEllipse(QPointF(x,y),sqrt(w*w+h*h),sqrt(w*w+h*h)); break;
         case ECLLIPSE :painter.drawEllipse(QPointF(x,y),w,h); break;
         case LINE     :painter.drawLine(QPointF(x,y),QPointF(x+w,y+h));break;
    }
    update();
}
void Widget::resizeEvent(QResizeEvent *e)
{
/*    tempImage = bufferImage;
    bufferImage = QImage(this->width(),this->height(),QImage::Format_ARGB32_Premultiplied);
    bufferImage.fill(qRgb(255,255,255));

    QPainter painter(&bufferImage);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawImage(QPointF(0,0),tempImage);

    tempImage = QImage(this->width(),this->height(),QImage::Format_ARGB32_Premultiplied);
    update();
    */
}
void Widget::changeCurrentShape(int shape)
{
    currShape = shape;
}
