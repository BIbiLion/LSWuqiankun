#include "mainwindow.h"
#include <QMenuBar>
#include <QCloseEvent>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
     _penDialog = new penDialog();
     _brushDialog = new brushDialog();
    initWindow();
}
void MainWindow::initWindow()
{
    setFixedSize(500,500);
    initMenuBar();
    initConnect();
    initToolBar();
    centerWidget = new Widget;
    centerWidget->setFixedSize(size());
    setCentralWidget(centerWidget);
}
void MainWindow::initMenuBar()
{
    QMenuBar* menu_Bar = menuBar();
    fileMenu = new QMenu(tr("文件(&F)"));
    menu_Bar->addMenu(fileMenu);

    newAction = new QAction(tr("新建"),this);
    newAction->setShortcut(QKeySequence("ctrl+shift+N"));
    fileMenu->addAction(newAction);

    fileMenu->addSeparator();
    closeAction = new QAction(tr("退出"),this);
    closeAction->setShortcut(QKeySequence("Ctrl+Shift+Q"));
    fileMenu->addAction(closeAction);

    //图形设置菜单
    optionMenu = new QMenu(tr("图形(&D)"));
    actionGroup = new QActionGroup(this);
    lineAction = new QAction(tr("直线"),this);
    lineAction->setShortcut(QKeySequence("Ctrl+Shift+L"));
    lineAction->setCheckable(true);
    lineAction->setChecked(true);
    actionGroup->addAction(lineAction);
    optionMenu->addAction(lineAction);

    circleAction = new QAction(tr("圆"),this);
    circleAction->setShortcut(QKeySequence("Ctrl+Shift+C"));
    circleAction->setCheckable(true);
    actionGroup->addAction(circleAction);
    optionMenu->addAction(circleAction);

    eclipseAction = new QAction(tr("椭圆"),this);
    eclipseAction->setShortcut(QKeySequence("Ctrl+Shift+E"));
    eclipseAction->setCheckable(true);
    actionGroup->addAction(eclipseAction);
    optionMenu->addAction(eclipseAction);

    rectAction = new QAction(tr("矩形"),this);
    rectAction->setShortcut(QKeySequence("Ctrl+Shift+R"));
    rectAction->setCheckable(true);
    actionGroup->addAction(rectAction);
    optionMenu->addAction(rectAction);
    menu_Bar->addMenu(optionMenu);

    //画笔、画刷设置
    setMenu = new QMenu(tr("设置(&S)"));
    setActGroup = new QActionGroup(this);
    penAction = new QAction(tr("画笔设置"),this);
    penAction->setShortcut(QKeySequence("Ctrl+Shift+P"));
    brushAction = new QAction(tr("画刷设置"),this);
    brushAction->setShortcut(QKeySequence("Ctrl+Shift+B"));
    setActGroup->addAction(penAction);
    setActGroup->addAction(brushAction);
    setMenu->addAction(this->penAction);
    setMenu->addAction(this->brushAction);
    menu_Bar->addMenu(setMenu);
}
void MainWindow::initConnect()
{
    connect(closeAction,SIGNAL(triggered()),this,SLOT(close()));
    connect(newAction,SIGNAL(triggered()),this,SLOT(newfile()));
    connect(actionGroup,SIGNAL(triggered(QAction*)),this,SLOT(changeDrawAction(QAction*)));
    connect(setActGroup,SIGNAL(triggered(QAction*)),this,SLOT(showSettingDoalog(QAction*)));
    connect(_penDialog,SIGNAL(accepted()),this,SLOT(setPen()));
    connect(_brushDialog,SIGNAL(accepted()),this,SLOT(setBrush()));
}
void MainWindow::initToolBar()
{
}
void MainWindow::changeDrawAction(QAction *action)
{
    if(action == lineAction)
        centerWidget->setShape(LINE);
    else if(action == circleAction)
        centerWidget->setShape(CIRCLE);
    else if(action == eclipseAction)
        centerWidget->setShape(ECLLIPSE);
    else if(action == rectAction)
        centerWidget->setShape(RECTANGLE);
}
void MainWindow::setPen()
{
        QPen pen;
        pen.setStyle(Qt::PenStyle(_penDialog->styleBox->itemData(_penDialog->styleBox->currentIndex()).toInt()));
        pen.setColor(QColor(_penDialog->colorBox->itemData(_penDialog->colorBox->currentIndex()).value<QColor>()));
        pen.setWidth(int(_penDialog->sizeBox->itemData(_penDialog->sizeBox->currentIndex()).toInt()));
        centerWidget->setMyPen(pen);
}
void MainWindow::setBrush()
{
    QBrush brush;
    brush.setStyle((Qt::BrushStyle)(_brushDialog->styleBox->itemData(_brushDialog->styleBox->currentIndex()).toInt()));
    brush.setColor((QColor)(_brushDialog->colorBox->itemData(_brushDialog->colorBox->currentIndex()).value<QColor>()));
    centerWidget->setMyBrush(brush);
}
void MainWindow::showSettingDoalog(QAction *action)
{
    if(action == penAction)
    {
        _penDialog->show();
    }
    else if(action == brushAction)
    {
        _brushDialog->show();
    }
}

void MainWindow::newfile()
{
    delete centerWidget;
    centerWidget = new Widget();
    setCentralWidget(centerWidget);
    centerWidget->setShape(LINE);
    lineAction->setChecked(true);
}
void MainWindow::closeEvent(QCloseEvent *event)
{

}
MainWindow::~MainWindow()
{

}
