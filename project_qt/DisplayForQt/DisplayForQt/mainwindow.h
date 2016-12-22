#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class DisplayWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_redBtn_clicked();

    void on_greenBtn_clicked();

    void on_blueBtn_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    DisplayWidget* m_displayWidget;

    virtual void keyPressEvent(QKeyEvent* pevent);
};

#endif // MAINWINDOW_H
