#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QComboBox>
#include "widget.h"
#include "brushdialog.h"
#include "pendialog.h"
#define RECTANGLE 1
#define CIRCLE  2
#define ECLLIPSE 3
#define LINE    4
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QMenu* fileMenu;
    QMenu* optionMenu;
    QMenu* setMenu;
    QAction* newAction;
    QAction* openAction;
    QAction* closeAction;
    QAction* circleAction;
    QAction* eclipseAction;
    QAction* lineAction;
    QAction* rectAction;
    QActionGroup* actionGroup;

    QActionGroup* setActGroup;
    QAction* penAction;
    QAction* brushAction;
    Widget*  centerWidget;
    penDialog* _penDialog;
    brushDialog* _brushDialog;
    QToolBar* toolBar;
    QComboBox* styleBox;
    QComboBox* colorBox;
    QComboBox* sizeBox;
    void initWindow();
    void initMenuBar();
    void initConnect();
    void initToolBar();
signals:

private slots:
    void changeDrawAction(QAction* action);
    void setPen();
    void setBrush();
    void showSettingDoalog(QAction* action);
    void newfile();
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
