#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "MyItem.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_Timer_Slot();
private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    MyItem* item;
    QTimer* timer;
    int Scale;
};

#endif // MAINWINDOW_H
