#include "curveplot.h"

CurvePlot::CurvePlot(QWidget *parent) :
    QWidget(parent)
{
    Margin = QMargin(2);
    Background = QBrush(QColor(255,255,255));
    Pen = QPen(QBrush(QColor(0xFF, 0xA1, 0)), 1);
    iAdjustVal = 0;
}

void CurvePlot::outPut()
{
    int w = width() - Margin.Left - Margin.Right;
    int h = height() - Margin.Top - Margin.Bottom;

    pixmap = QPixmap(w, h);
    QPainter painter(&pixmap);
    painter.fillRect(QRectF(0, 0, w, h), Background);

    painter.setPen(Pen);
    painter.drawLine(QPoint(Margin.Left, height()/2), QPoint(Margin.Left + w, height()/2));
    update();
}

void CurvePlot::transformPoints(QVector<float>&data, int w, int h, QVector<QPointF> &points)
{   // 获取极值
    float max = data[0], min = data[0];
    for (int i= 1; i< data.size(); i++)
    {
        if (max < data[i])
            max = data[i];
        if (min > data[i])
            min = data[i];
    }
    // 转化成当前屏幕的内的坐标大小
    max += iAdjustVal;
    min -= iAdjustVal;
    float diffVal = max - min;
    for (int i= 0; i< data.size(); i++)
        points.append(QPointF(i * w / data.size(), h - (data[i] - min) / diffVal * h));
}

void CurvePlot::outPut(QVector<float>&data)
{
    int w = width() - Margin.Left - Margin.Right;
    int h = height() - Margin.Top - Margin.Bottom;

    pixmap = QPixmap(w, h);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::SmoothPixmapTransform);
    painter.fillRect(QRectF(0, 0, w, h), Background);

    QVector<QPointF> points;
    transformPoints(data, w, h, points);
    painter.setPen(Pen);
    for (int i= 0; i< points.size()-1; i++)
        painter.drawLine(points[i], points[i+1]);

    update();
}

void CurvePlot::paintEvent(QPaintEvent *paint)
{
    QPainter painter(this);
    int w = width() - Margin.Left - Margin.Right;
    int h = height() - Margin.Top - Margin.Bottom;
    painter.fillRect(QRectF(0, 0, width(), height()), Background);
    painter.drawPixmap(Margin.Left, Margin.Top, w, h, pixmap);
}

void CurvePlot::resizeEvent(QResizeEvent *)
{
    outPut();
}

QSize CurvePlot::minimumSizeHint() const
{
    return QSize(Margin.Left + Margin.Right + 40, Margin.Top + Margin.Bottom + 40);
}
