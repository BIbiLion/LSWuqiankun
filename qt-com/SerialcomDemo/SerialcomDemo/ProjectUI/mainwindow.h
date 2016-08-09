#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <SerialCom/ParseWorker.h>
#include <SerialCom/SerialCom.h>
#include <QThread>
#include <QHBoxLayout>
#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include "ProjectUI/CustomControl/mycombox.h"
#include <QPushButton>
#include <QEvent>

// 主窗口界面
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void customEvent(QEvent *event);

private:
    void taskOpt();
    void createControl();
    void initUI();
    void initConnect();
    void insertList(const QByteArray& data);

signals:

public slots:
    void slot_openSerial();
    void slot_refreshList();

private:
    QThread parseThrd;
    ParseWorker *parse;
    SerialCom *serial;

private:
    QHBoxLayout *mainLayout;
    QWidget *leftWidget;
    QListWidget *rightList;
    QVBoxLayout *leftLayout;

    // 串口部分
    QHBoxLayout *serialPortLayout;
    MyCombox *serialPortBox;
    QPushButton *serialPortButton;

    QPushButton *refreshButton;
};

#endif // MAINWINDOW_H
