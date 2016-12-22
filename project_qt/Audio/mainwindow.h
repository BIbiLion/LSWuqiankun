#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QTimer>
#include "fmod.h"
#include "fmod_errors.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void loadIni(bool isLoad);
    void plotAllWav(char *fileName);

public slots:
    void onTimer();

private slots:
    void on_actionAdd_triggered();
    void on_actionList_triggered();
    void on_actionPlay_triggered();
    void on_actionPause_triggered();
    void on_actionStop_triggered();
    void on_slTime_sliderMoved(int position);
    void on_lwList_doubleClicked(const QModelIndex &index);
    void on_actionMinus_triggered();
    void on_actionClear_triggered();

private:
    QTimer timer;
    QVector<float>wav;

    FMOD_SYSTEM *system;
    FMOD_SOUND *sound;
    FMOD_CHANNEL *channel;
    FMOD_RESULT result;
};

#endif // MAINWINDOW_H
