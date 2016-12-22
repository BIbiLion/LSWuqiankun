#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_btnToFan_clicked();

    void on_btnToJian_clicked();

    void on_btnToPinYin_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
