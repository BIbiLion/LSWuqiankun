/********************************************************************************
** Form generated from reading UI file 'testcom_dial_thermo.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTCOM_DIAL_THERMO_H
#define UI_TESTCOM_DIAL_THERMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "mythermo.h"
#include "qwt_dial.h"

QT_BEGIN_NAMESPACE

class Ui_testCom_dial_thermo
{
public:
    QwtDial *Dial;
    myThermo *widget;

    void setupUi(QWidget *testCom_dial_thermo)
    {
        if (testCom_dial_thermo->objectName().isEmpty())
            testCom_dial_thermo->setObjectName(QStringLiteral("testCom_dial_thermo"));
        testCom_dial_thermo->resize(545, 300);
        Dial = new QwtDial(testCom_dial_thermo);
        Dial->setObjectName(QStringLiteral("Dial"));
        Dial->setGeometry(QRect(130, 39, 291, 231));
        Dial->setLineWidth(4);
        widget = new myThermo(testCom_dial_thermo);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(240, 119, 71, 91));

        retranslateUi(testCom_dial_thermo);

        QMetaObject::connectSlotsByName(testCom_dial_thermo);
    } // setupUi

    void retranslateUi(QWidget *testCom_dial_thermo)
    {
        testCom_dial_thermo->setWindowTitle(QApplication::translate("testCom_dial_thermo", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class testCom_dial_thermo: public Ui_testCom_dial_thermo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTCOM_DIAL_THERMO_H
