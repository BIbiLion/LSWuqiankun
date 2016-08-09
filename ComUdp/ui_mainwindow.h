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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *comboBox_comPort;
    QPushButton *openBtn;
    QLineEdit *lineEdit_UdpPort;
    QLabel *label;
    QPushButton *pauseBtn;
    QPushButton *closeBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox_comPort = new QComboBox(centralWidget);
        comboBox_comPort->setObjectName(QStringLiteral("comboBox_comPort"));
        comboBox_comPort->setGeometry(QRect(30, 70, 69, 22));
        openBtn = new QPushButton(centralWidget);
        openBtn->setObjectName(QStringLiteral("openBtn"));
        openBtn->setGeometry(QRect(30, 120, 75, 23));
        lineEdit_UdpPort = new QLineEdit(centralWidget);
        lineEdit_UdpPort->setObjectName(QStringLiteral("lineEdit_UdpPort"));
        lineEdit_UdpPort->setGeometry(QRect(240, 70, 113, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 70, 54, 12));
        pauseBtn = new QPushButton(centralWidget);
        pauseBtn->setObjectName(QStringLiteral("pauseBtn"));
        pauseBtn->setGeometry(QRect(130, 200, 75, 23));
        closeBtn = new QPushButton(centralWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(250, 200, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 19));
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
        openBtn->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        label->setText(QApplication::translate("MainWindow", "Udp\347\253\257\345\217\243", 0));
        pauseBtn->setText(QApplication::translate("MainWindow", "Udp\345\217\221\351\200\201\346\225\260\346\215\256", 0));
        closeBtn->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
