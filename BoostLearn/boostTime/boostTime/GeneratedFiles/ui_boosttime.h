/********************************************************************************
** Form generated from reading UI file 'boosttime.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOSTTIME_H
#define UI_BOOSTTIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_boostTimeClass
{
public:

    void setupUi(QWidget *boostTimeClass)
    {
        if (boostTimeClass->objectName().isEmpty())
            boostTimeClass->setObjectName(QStringLiteral("boostTimeClass"));
        boostTimeClass->resize(600, 400);

        retranslateUi(boostTimeClass);

        QMetaObject::connectSlotsByName(boostTimeClass);
    } // setupUi

    void retranslateUi(QWidget *boostTimeClass)
    {
        boostTimeClass->setWindowTitle(QApplication::translate("boostTimeClass", "boostTime", 0));
    } // retranslateUi

};

namespace Ui {
    class boostTimeClass: public Ui_boostTimeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOSTTIME_H
