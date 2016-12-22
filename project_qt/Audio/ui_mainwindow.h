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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "CurvePlot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPlay;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionAdd;
    QAction *actionList;
    QAction *actionMinus;
    QAction *actionClear;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    CurvePlot *ploter;
    QLabel *lbCurTime;
    QSlider *slTime;
    QListWidget *lwList;
    QLabel *lbTotalTime;
    QSpacerItem *horizontalSpacer;
    CurvePlot *ploterAll;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(699, 333);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon1);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon2);
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon3);
        actionList = new QAction(MainWindow);
        actionList->setObjectName(QStringLiteral("actionList"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/list.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionList->setIcon(icon4);
        actionMinus = new QAction(MainWindow);
        actionMinus->setObjectName(QStringLiteral("actionMinus"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMinus->setIcon(icon5);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon6);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ploter = new CurvePlot(centralWidget);
        ploter->setObjectName(QStringLiteral("ploter"));

        gridLayout->addWidget(ploter, 0, 1, 1, 3);

        lbCurTime = new QLabel(centralWidget);
        lbCurTime->setObjectName(QStringLiteral("lbCurTime"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbCurTime->sizePolicy().hasHeightForWidth());
        lbCurTime->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lbCurTime, 3, 1, 1, 1);

        slTime = new QSlider(centralWidget);
        slTime->setObjectName(QStringLiteral("slTime"));
        slTime->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(slTime, 2, 1, 1, 3);

        lwList = new QListWidget(centralWidget);
        lwList->setObjectName(QStringLiteral("lwList"));
        lwList->setMaximumSize(QSize(200, 16777215));
        QFont font;
        font.setPointSize(12);
        lwList->setFont(font);
        lwList->setStyleSheet(QLatin1String("QListWidget::item{height: 40px}\n"
"\n"
"QListWidget {\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        lwList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(lwList, 0, 0, 4, 1);

        lbTotalTime = new QLabel(centralWidget);
        lbTotalTime->setObjectName(QStringLiteral("lbTotalTime"));
        sizePolicy.setHeightForWidth(lbTotalTime->sizePolicy().hasHeightForWidth());
        lbTotalTime->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lbTotalTime, 3, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 2, 1, 1);

        ploterAll = new CurvePlot(centralWidget);
        ploterAll->setObjectName(QStringLiteral("ploterAll"));
        ploterAll->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(ploterAll, 1, 1, 1, 3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 699, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actionAdd);
        mainToolBar->addAction(actionMinus);
        mainToolBar->addAction(actionClear);
        mainToolBar->addAction(actionList);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionPause);
        mainToolBar->addAction(actionStop);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\351\237\263\351\242\221\346\222\255\346\224\276\345\231\250", 0));
        actionPlay->setText(QApplication::translate("MainWindow", "play", 0));
#ifndef QT_NO_TOOLTIP
        actionPlay->setToolTip(QApplication::translate("MainWindow", "\346\222\255\346\224\276", 0));
#endif // QT_NO_TOOLTIP
        actionPause->setText(QApplication::translate("MainWindow", "pause", 0));
#ifndef QT_NO_TOOLTIP
        actionPause->setToolTip(QApplication::translate("MainWindow", "\346\232\202\345\201\234", 0));
#endif // QT_NO_TOOLTIP
        actionStop->setText(QApplication::translate("MainWindow", "stop", 0));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0));
#endif // QT_NO_TOOLTIP
        actionAdd->setText(QApplication::translate("MainWindow", "add", 0));
#ifndef QT_NO_TOOLTIP
        actionAdd->setToolTip(QApplication::translate("MainWindow", "\345\242\236\345\212\240", 0));
#endif // QT_NO_TOOLTIP
        actionList->setText(QApplication::translate("MainWindow", "List", 0));
#ifndef QT_NO_TOOLTIP
        actionList->setToolTip(QApplication::translate("MainWindow", "\345\210\227\350\241\250", 0));
#endif // QT_NO_TOOLTIP
        actionMinus->setText(QApplication::translate("MainWindow", "minus", 0));
#ifndef QT_NO_TOOLTIP
        actionMinus->setToolTip(QApplication::translate("MainWindow", "\345\207\217\345\216\273", 0));
#endif // QT_NO_TOOLTIP
        actionClear->setText(QApplication::translate("MainWindow", "clear", 0));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "\346\270\205\351\231\244", 0));
#endif // QT_NO_TOOLTIP
        lbCurTime->setText(QApplication::translate("MainWindow", " 00:00", 0));
        lbTotalTime->setText(QApplication::translate("MainWindow", "00:00 ", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
