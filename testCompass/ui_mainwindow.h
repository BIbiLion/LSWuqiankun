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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qwt_compass.h"
#include "qwt_dial.h"
#include "qwt_scale_widget.h"
#include "qwt_slider.h"
#include "qwt_thermo.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QwtScaleWidget *ScaleWidget;
    QwtCompass *Compass;
    QwtDial *Dial;
    QwtThermo *Thermo;
    QwtSlider *Slider;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1077, 677);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ScaleWidget = new QwtScaleWidget(centralWidget);
        ScaleWidget->setObjectName(QStringLiteral("ScaleWidget"));
        ScaleWidget->setGeometry(QRect(200, 300, 60, 101));
        ScaleWidget->setLayoutDirection(Qt::RightToLeft);
        Compass = new QwtCompass(centralWidget);
        Compass->setObjectName(QStringLiteral("Compass"));
        Compass->setEnabled(true);
        Compass->setGeometry(QRect(710, 30, 200, 200));
        Compass->setScaleMaxMinor(2);
        Compass->setScaleStepSize(0.1);
        Compass->setLineWidth(4);
        Dial = new QwtDial(centralWidget);
        Dial->setObjectName(QStringLiteral("Dial"));
        Dial->setGeometry(QRect(140, 250, 200, 200));
        Dial->setLineWidth(4);
        Thermo = new QwtThermo(centralWidget);
        Thermo->setObjectName(QStringLiteral("Thermo"));
        Thermo->setGeometry(QRect(620, 69, 60, 461));
        Thermo->setStyleSheet(QStringLiteral(""));
        Thermo->setLowerBound(-90);
        Thermo->setUpperBound(90);
        Thermo->setScaleMaxMajor(10);
        Thermo->setOriginMode(QwtThermo::OriginCustom);
        Thermo->setAlarmEnabled(false);
        Slider = new QwtSlider(centralWidget);
        Slider->setObjectName(QStringLiteral("Slider"));
        Slider->setGeometry(QRect(760, 260, 61, 250));
        Slider->setStyleSheet(QStringLiteral("background-color: rgb(101, 222, 255);"));
        Slider->setLowerBound(-90);
        Slider->setUpperBound(90);
        Slider->setScaleMaxMajor(20);
        Slider->setScaleMaxMinor(5);
        Slider->setInvertedControls(false);
        Slider->setOrientation(Qt::Vertical);
        Slider->setScalePosition(QwtSlider::LeadingScale);
        Slider->setGroove(false);
        MainWindow->setCentralWidget(centralWidget);
        Dial->raise();
        ScaleWidget->raise();
        Thermo->raise();
        Slider->raise();
        Compass->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1077, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
