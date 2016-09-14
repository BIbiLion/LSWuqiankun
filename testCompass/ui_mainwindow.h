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
#include <QtWidgets/QKeySequenceEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qwt_compass.h"
#include "qwt_counter.h"
#include "qwt_dial.h"
#include "qwt_knob.h"
#include "qwt_plot.h"
#include "qwt_scale_widget.h"
#include "qwt_slider.h"
#include "qwt_text_label.h"
#include "qwt_thermo.h"
#include "qwt_wheel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QKeySequenceEdit *keySequenceEdit;
    QwtPlot *qwtPlot;
    QwtScaleWidget *ScaleWidget;
    QwtCompass *Compass;
    QwtCounter *Counter;
    QwtDial *Dial;
    QwtThermo *Thermo;
    QwtWheel *Wheel;
    QwtKnob *Knob;
    QwtTextLabel *TextLabel;
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
        keySequenceEdit = new QKeySequenceEdit(centralWidget);
        keySequenceEdit->setObjectName(QStringLiteral("keySequenceEdit"));
        keySequenceEdit->setGeometry(QRect(180, 120, 113, 20));
        qwtPlot = new QwtPlot(centralWidget);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));
        qwtPlot->setGeometry(QRect(20, 20, 400, 200));
        ScaleWidget = new QwtScaleWidget(centralWidget);
        ScaleWidget->setObjectName(QStringLiteral("ScaleWidget"));
        ScaleWidget->setGeometry(QRect(90, 380, 60, 141));
        ScaleWidget->setLayoutDirection(Qt::RightToLeft);
        Compass = new QwtCompass(centralWidget);
        Compass->setObjectName(QStringLiteral("Compass"));
        Compass->setGeometry(QRect(260, 330, 200, 200));
        Compass->setScaleMaxMinor(2);
        Compass->setScaleStepSize(0.1);
        Compass->setLineWidth(4);
        Counter = new QwtCounter(centralWidget);
        Counter->setObjectName(QStringLiteral("Counter"));
        Counter->setGeometry(QRect(940, 90, 67, 20));
        Dial = new QwtDial(centralWidget);
        Dial->setObjectName(QStringLiteral("Dial"));
        Dial->setGeometry(QRect(480, 70, 200, 200));
        Dial->setLineWidth(4);
        Thermo = new QwtThermo(centralWidget);
        Thermo->setObjectName(QStringLiteral("Thermo"));
        Thermo->setGeometry(QRect(800, 330, 60, 250));
        Wheel = new QwtWheel(centralWidget);
        Wheel->setObjectName(QStringLiteral("Wheel"));
        Wheel->setGeometry(QRect(800, 80, 64, 24));
        Knob = new QwtKnob(centralWidget);
        Knob->setObjectName(QStringLiteral("Knob"));
        Knob->setGeometry(QRect(560, 360, 150, 150));
        TextLabel = new QwtTextLabel(centralWidget);
        TextLabel->setObjectName(QStringLiteral("TextLabel"));
        TextLabel->setGeometry(QRect(140, 230, 100, 20));
        Slider = new QwtSlider(centralWidget);
        Slider->setObjectName(QStringLiteral("Slider"));
        Slider->setGeometry(QRect(960, 300, 60, 250));
        MainWindow->setCentralWidget(centralWidget);
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
