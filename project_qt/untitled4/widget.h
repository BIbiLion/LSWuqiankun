#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include <QPen>
#include <QBrush>
#define RECTANGLE 1
#define CIRCLE  2
#define ECLLIPSE 3
#define LINE    4

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    void paintImage(QImage& image);
    void setShape(int shape);
    void setMyPen(QPen pen);
    void setMyBrush(QBrush brush);
    QImage bufferImage;
    QImage tempImage;
private:
    float x,y,w,h;
    bool isMoving;
    int  currShape;
    QPen curPen;
    QBrush curBrush;
private slots:
    void changeCurrentShape(int shape);
protected:
    void paintEvent(QPaintEvent * e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void resizeEvent(QResizeEvent *e);

};

#endif // WIDGET_H
