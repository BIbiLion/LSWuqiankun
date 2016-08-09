//#ifndef WIDGET_H
//#define WIDGET_H
#ifndef CONSOLEDIALOG_H
#define CONSOLEDIALOG_H
#include <QWidget>


QT_USE_NAMESPACE

QT_BEGIN_NAMESPACE

namespace Ui {
class ConsoleDialog;
}

class ConsoleDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ConsoleDialog(QWidget *parent = 0);
    ~ConsoleDialog();

private slots:
    void on_ClosepushButton_clicked();

private:
    Ui::ConsoleDialog *ui;
};

#endif // WIDGET_H
