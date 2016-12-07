#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = 0);
    ~mainWidget();
private slots:
    void showPage();
private:
    Ui::mainWidget *ui;
    QWidget * m_oneWidget;
     QWidget * m_twoWidget;
     int m_index;
};

#endif // MAINWIDGET_H
