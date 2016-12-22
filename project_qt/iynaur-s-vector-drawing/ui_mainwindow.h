/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCurve;
    QAction *actionPolyline;
    QAction *actionPolygon;
    QAction *actionPick;
    QAction *actionCircle;
    QAction *actionFixcanvas;
    QAction *actionRect;
    QAction *actionEllipse;
    QAction *actionText;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionAdd;
    QAction *actionCombination;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionPalm;
    QAction *actionZoomOne;
    QAction *actionMoveToTop;
    QAction *actionMoveToBottom;
    QAction *actionCloseCurve;
    QAction *actionDivide;
    QAction *actionDivideToEnd;
    QAction *actionNew;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionExpand;
    QAction *actionCut;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionSaveAs;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuDraw;
    QMenu *menuPick;
    QMenu *menuFix;
    QMenu *menuFile;
    QMenu *menuCombination;
    QMenu *menuZoom;
    QMenu *menuEdit;
    QToolBar *toolBar_0;
    QToolBar *toolBar_1;
    QStatusBar *statusBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/5624330_201027415000_2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionCurve = new QAction(MainWindow);
        actionCurve->setObjectName(QStringLiteral("actionCurve"));
        actionCurve->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/pencapstyle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCurve->setIcon(icon1);
        actionPolyline = new QAction(MainWindow);
        actionPolyline->setObjectName(QStringLiteral("actionPolyline"));
        actionPolyline->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/polyline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPolyline->setIcon(icon2);
        actionPolygon = new QAction(MainWindow);
        actionPolygon->setObjectName(QStringLiteral("actionPolygon"));
        actionPolygon->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/polygon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPolygon->setIcon(icon3);
        actionPick = new QAction(MainWindow);
        actionPick->setObjectName(QStringLiteral("actionPick"));
        actionPick->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/th.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPick->setIcon(icon4);
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName(QStringLiteral("actionCircle"));
        actionCircle->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/circle.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        actionCircle->setIcon(icon5);
        actionFixcanvas = new QAction(MainWindow);
        actionFixcanvas->setObjectName(QStringLiteral("actionFixcanvas"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/fit.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionFixcanvas->setIcon(icon6);
        actionRect = new QAction(MainWindow);
        actionRect->setObjectName(QStringLiteral("actionRect"));
        actionRect->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/rect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRect->setIcon(icon7);
        actionEllipse = new QAction(MainWindow);
        actionEllipse->setObjectName(QStringLiteral("actionEllipse"));
        actionEllipse->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/image/ellipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEllipse->setIcon(icon8);
        actionText = new QAction(MainWindow);
        actionText->setObjectName(QStringLiteral("actionText"));
        actionText->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/image/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionText->setIcon(icon9);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/image/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon10);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon11);
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/image/blue-plus-sign-md.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon12);
        actionCombination = new QAction(MainWindow);
        actionCombination->setObjectName(QStringLiteral("actionCombination"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/image/combine.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionCombination->setIcon(icon13);
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName(QStringLiteral("actionZoomIn"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/image/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomIn->setIcon(icon14);
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName(QStringLiteral("actionZoomOut"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/image/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomOut->setIcon(icon15);
        actionPalm = new QAction(MainWindow);
        actionPalm->setObjectName(QStringLiteral("actionPalm"));
        actionPalm->setCheckable(true);
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/image/hand.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPalm->setIcon(icon16);
        actionZoomOne = new QAction(MainWindow);
        actionZoomOne->setObjectName(QStringLiteral("actionZoomOne"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/image/zoomone.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomOne->setIcon(icon17);
        actionMoveToTop = new QAction(MainWindow);
        actionMoveToTop->setObjectName(QStringLiteral("actionMoveToTop"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/image/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMoveToTop->setIcon(icon18);
        actionMoveToBottom = new QAction(MainWindow);
        actionMoveToBottom->setObjectName(QStringLiteral("actionMoveToBottom"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/image/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMoveToBottom->setIcon(icon19);
        actionCloseCurve = new QAction(MainWindow);
        actionCloseCurve->setObjectName(QStringLiteral("actionCloseCurve"));
        actionCloseCurve->setCheckable(true);
        actionCloseCurve->setIcon(icon);
        actionDivide = new QAction(MainWindow);
        actionDivide->setObjectName(QStringLiteral("actionDivide"));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/image/divide.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionDivide->setIcon(icon20);
        actionDivideToEnd = new QAction(MainWindow);
        actionDivideToEnd->setObjectName(QStringLiteral("actionDivideToEnd"));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/image/dividetoend.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionDivideToEnd->setIcon(icon21);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/image/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon22);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon23;
        icon23.addFile(QStringLiteral(":/image/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon23);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon24;
        icon24.addFile(QStringLiteral(":/image/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon24);
        actionExpand = new QAction(MainWindow);
        actionExpand->setObjectName(QStringLiteral("actionExpand"));
        QIcon icon25;
        icon25.addFile(QStringLiteral(":/image/expand.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionExpand->setIcon(icon25);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon26;
        icon26.addFile(QStringLiteral(":/image/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon26);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon27;
        icon27.addFile(QStringLiteral(":/image/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon27);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon28;
        icon28.addFile(QStringLiteral(":/image/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon28);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        QIcon icon29;
        icon29.addFile(QStringLiteral(":/image/save_all_download-512.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAs->setIcon(icon29);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 23));
        menuDraw = new QMenu(menuBar);
        menuDraw->setObjectName(QStringLiteral("menuDraw"));
        menuPick = new QMenu(menuBar);
        menuPick->setObjectName(QStringLiteral("menuPick"));
        menuFix = new QMenu(menuBar);
        menuFix->setObjectName(QStringLiteral("menuFix"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuCombination = new QMenu(menuBar);
        menuCombination->setObjectName(QStringLiteral("menuCombination"));
        menuZoom = new QMenu(menuBar);
        menuZoom->setObjectName(QStringLiteral("menuZoom"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        toolBar_0 = new QToolBar(MainWindow);
        toolBar_0->setObjectName(QStringLiteral("toolBar_0"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_0);
        toolBar_1 = new QToolBar(MainWindow);
        toolBar_1->setObjectName(QStringLiteral("toolBar_1"));
        toolBar_1->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_1);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuDraw->menuAction());
        menuBar->addAction(menuPick->menuAction());
        menuBar->addAction(menuFix->menuAction());
        menuBar->addAction(menuCombination->menuAction());
        menuBar->addAction(menuZoom->menuAction());
        menuDraw->addAction(actionCurve);
        menuDraw->addAction(actionCloseCurve);
        menuDraw->addAction(actionPolyline);
        menuDraw->addAction(actionPolygon);
        menuDraw->addAction(actionCircle);
        menuDraw->addAction(actionRect);
        menuDraw->addAction(actionEllipse);
        menuDraw->addAction(actionText);
        menuPick->addAction(actionPick);
        menuPick->addAction(actionPalm);
        menuFix->addAction(actionFixcanvas);
        menuFix->addAction(actionExpand);
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionAdd);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuCombination->addAction(actionCombination);
        menuCombination->addAction(actionDivide);
        menuCombination->addAction(actionDivideToEnd);
        menuZoom->addAction(actionZoomIn);
        menuZoom->addAction(actionZoomOut);
        menuZoom->addAction(actionZoomOne);
        menuEdit->addAction(actionMoveToTop);
        menuEdit->addAction(actionMoveToBottom);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        toolBar_0->addAction(actionNew);
        toolBar_0->addAction(actionOpen);
        toolBar_0->addAction(actionAdd);
        toolBar_0->addAction(actionSave);
        toolBar_0->addAction(actionSaveAs);
        toolBar_1->addAction(actionCurve);
        toolBar_1->addAction(actionCloseCurve);
        toolBar_1->addAction(actionPolyline);
        toolBar_1->addAction(actionPolygon);
        toolBar_1->addAction(actionCircle);
        toolBar_1->addAction(actionRect);
        toolBar_1->addAction(actionEllipse);
        toolBar_1->addAction(actionText);
        toolBar_2->addAction(actionPick);
        toolBar_2->addAction(actionCut);
        toolBar_2->addAction(actionCopy);
        toolBar_2->addAction(actionPaste);
        toolBar_2->addAction(actionMoveToTop);
        toolBar_2->addAction(actionMoveToBottom);
        toolBar_2->addAction(actionFixcanvas);
        toolBar_2->addAction(actionExpand);
        toolBar_2->addAction(actionZoomIn);
        toolBar_2->addAction(actionZoomOut);
        toolBar_2->addAction(actionZoomOne);
        toolBar_2->addAction(actionCombination);
        toolBar_2->addAction(actionDivide);
        toolBar_2->addAction(actionDivideToEnd);
        toolBar_2->addAction(actionPalm);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionCurve->setText(QApplication::translate("MainWindow", "Curve", 0));
        actionPolyline->setText(QApplication::translate("MainWindow", "Polyline", 0));
        actionPolygon->setText(QApplication::translate("MainWindow", "Polygon", 0));
        actionPick->setText(QApplication::translate("MainWindow", "Pick", 0));
        actionCircle->setText(QApplication::translate("MainWindow", "Circle", 0));
        actionFixcanvas->setText(QApplication::translate("MainWindow", "Fitcanvas", 0));
        actionRect->setText(QApplication::translate("MainWindow", "Rect", 0));
        actionEllipse->setText(QApplication::translate("MainWindow", "Ellipse", 0));
        actionText->setText(QApplication::translate("MainWindow", "Text", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        actionCombination->setText(QApplication::translate("MainWindow", "Combination", 0));
        actionZoomIn->setText(QApplication::translate("MainWindow", "ZoomIn", 0));
        actionZoomOut->setText(QApplication::translate("MainWindow", "ZoomOut", 0));
        actionPalm->setText(QApplication::translate("MainWindow", "Palm", 0));
        actionZoomOne->setText(QApplication::translate("MainWindow", "ZoomOne", 0));
        actionMoveToTop->setText(QApplication::translate("MainWindow", "MoveToTop", 0));
        actionMoveToBottom->setText(QApplication::translate("MainWindow", "MoveToBottom", 0));
        actionCloseCurve->setText(QApplication::translate("MainWindow", "CloseCurve", 0));
        actionDivide->setText(QApplication::translate("MainWindow", "Divide", 0));
        actionDivideToEnd->setText(QApplication::translate("MainWindow", "DivideToEnd", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0));
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0));
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        actionExpand->setText(QApplication::translate("MainWindow", "Expand", 0));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0));
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0));
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0));
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0));
        actionSaveAs->setText(QApplication::translate("MainWindow", "SaveAs", 0));
        menuDraw->setTitle(QApplication::translate("MainWindow", "Draw", 0));
        menuPick->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        menuFix->setTitle(QApplication::translate("MainWindow", "Fit", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuCombination->setTitle(QApplication::translate("MainWindow", "Combination", 0));
        menuZoom->setTitle(QApplication::translate("MainWindow", "Zoom", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        toolBar_0->setWindowTitle(QApplication::translate("MainWindow", "File", 0));
        toolBar_1->setWindowTitle(QApplication::translate("MainWindow", "Draw", 0));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
