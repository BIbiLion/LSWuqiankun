#ifndef TRANSLATEWIDGET_H
#define TRANSLATEWIDGET_H

#include <QWidget>

namespace Ui {
class translateWidget;
}

class translateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit translateWidget(QWidget *parent = 0);
    ~translateWidget();

private slots:
    void showMenu();
private:
    Ui::translateWidget *ui;
};

#endif // TRANSLATEWIDGET_H
