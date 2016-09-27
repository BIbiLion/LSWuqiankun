#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialportobject.h"
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
    void openCom();
    void showData(QByteArray);
    void sendData_83();
    void sendData();
    void clear();
private:
    Ui::MainWindow *ui;
    SerialPortObject * m_serialPort;//串口类
    char * m_sendData;
    int m_length;
};

#endif // MAINWINDOW_H
