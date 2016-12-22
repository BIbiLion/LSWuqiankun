#ifndef GRADIENTTEST_H
#define GRADIENTTEST_H

#include <QWidget>

class gradientTest : public QWidget
{
    Q_OBJECT
public:
    explicit gradientTest(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // GRADIENTTEST_H
