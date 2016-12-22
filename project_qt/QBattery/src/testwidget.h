#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include "qbattery.h"
#include "qt.h"

class TestWidget : public QWidget
{
    Q_OBJECT
public:
    TestWidget();

private:
    QBattery* battery;
    QVBoxLayout* mainLayout;
    QTimer* updateTimer;
    QHBoxLayout* bottomLayout;
    QLabel* numSpin;
    QPushButton* fireBtn;

private Q_SLOTS:
    void UpdateValue();
    void SetValue(qreal value);
};

#endif // TESTWIDGET_H
