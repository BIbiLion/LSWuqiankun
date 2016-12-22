#ifndef QBATTERY_H
#define QBATTERY_H

#include <QWidget>
#include "qt.h"

class QBattery : public QWidget
{

Q_OBJECT
public:
    explicit QBattery(QWidget *parent = 0);

public Q_SLOTS:
    void setValue(qreal value);

protected:
    void paintEvent(QPaintEvent *);
    QSize sizeHint() const
    {
        return QSize(200,120);
    }


private:
    void drawFrame(QPainter* painter);
    void drawBattery(QPainter* painter);
private:
    QTimer* updateTimer;
    bool    m_bReverse;
    qreal   m_headWidth;
    qreal   m_value;
    qreal   m_currentValue;
    QRectF  m_batteryRect;

private Q_SLOTS:
    void UpdateGraph();

Q_SIGNALS:
    void valueChanged(qreal value);

};

#endif // QBATTERY_H
