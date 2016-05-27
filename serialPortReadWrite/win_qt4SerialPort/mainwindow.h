#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "win_qextserialport.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void readMyCom();//∂¡»°
private:
    Ui::MainWindow *ui;

    Win_QextSerialPort * myCom;
};

#endif // MAINWINDOW_H
