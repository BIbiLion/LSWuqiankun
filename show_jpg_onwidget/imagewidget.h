#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>

class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageWidget(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
    
signals:
    
public slots:
    
};

#endif // IMAGEWIDGET_H
