/********************************************************************************
** Form generated from reading UI file 'translatewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLATEWIDGET_H
#define UI_TRANSLATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_translateWidget
{
public:

    void setupUi(QWidget *translateWidget)
    {
        if (translateWidget->objectName().isEmpty())
            translateWidget->setObjectName(QStringLiteral("translateWidget"));
        translateWidget->resize(400, 300);

        retranslateUi(translateWidget);

        QMetaObject::connectSlotsByName(translateWidget);
    } // setupUi

    void retranslateUi(QWidget *translateWidget)
    {
        translateWidget->setWindowTitle(QApplication::translate("translateWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class translateWidget: public Ui_translateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATEWIDGET_H
