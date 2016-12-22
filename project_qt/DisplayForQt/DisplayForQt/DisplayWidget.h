#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QWidget>
#include <QMutex>
#include <QMutexLocker>

namespace Ui {
class DisplayWidget;
}

typedef struct BrushCell
{
    QMutex lock;
    QList<QPoint> pathValue;
    QString color;
    int size;

    QList<QPoint>& path()
    {
        QMutexLocker locker(&lock);
        return pathValue;
    }

    void addPath(const QPoint& p)
    {
        QMutexLocker locker(&lock);
        pathValue.append(p);
    }

} BRUSH_CELL;

class DisplayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayWidget(QWidget *parent = 0);
    virtual ~DisplayWidget();

    void setPicture(const QString& imagePath);
    void saveImage(const QString& imagePath);

    void setPen(const QString& penColor);
    void undo();

private:
    Ui::DisplayWidget *ui;

    virtual void paintEvent(QPaintEvent* pevent);
    virtual void mousePressEvent(QMouseEvent* pevent);
    virtual void mouseReleaseEvent(QMouseEvent* pevent);
    virtual void mouseMoveEvent(QMouseEvent* pevent);

    QList<BRUSH_CELL*> m_commands;
    QImage m_image;
    BRUSH_CELL* m_brushCell;
    QMutex m_locker;
};

#endif // DISPLAYWIDGET_H
