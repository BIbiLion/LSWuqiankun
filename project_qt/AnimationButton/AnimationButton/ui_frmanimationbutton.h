/********************************************************************************
** Form generated from reading UI file 'frmanimationbutton.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMANIMATIONBUTTON_H
#define UI_FRMANIMATIONBUTTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "animationbutton.h"

QT_BEGIN_NAMESPACE

class Ui_frmAnimationButton
{
public:
    QHBoxLayout *horizontalLayout;
    AnimationButton *widget1;
    AnimationButton *widget2;
    AnimationButton *widget3;
    AnimationButton *widget4;

    void setupUi(QWidget *frmAnimationButton)
    {
        if (frmAnimationButton->objectName().isEmpty())
            frmAnimationButton->setObjectName(QStringLiteral("frmAnimationButton"));
        frmAnimationButton->resize(662, 158);
        frmAnimationButton->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(frmAnimationButton);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget1 = new AnimationButton(frmAnimationButton);
        widget1->setObjectName(QStringLiteral("widget1"));

        horizontalLayout->addWidget(widget1);

        widget2 = new AnimationButton(frmAnimationButton);
        widget2->setObjectName(QStringLiteral("widget2"));

        horizontalLayout->addWidget(widget2);

        widget3 = new AnimationButton(frmAnimationButton);
        widget3->setObjectName(QStringLiteral("widget3"));

        horizontalLayout->addWidget(widget3);

        widget4 = new AnimationButton(frmAnimationButton);
        widget4->setObjectName(QStringLiteral("widget4"));

        horizontalLayout->addWidget(widget4);


        retranslateUi(frmAnimationButton);

        QMetaObject::connectSlotsByName(frmAnimationButton);
    } // setupUi

    void retranslateUi(QWidget *frmAnimationButton)
    {
        frmAnimationButton->setWindowTitle(QApplication::translate("frmAnimationButton", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class frmAnimationButton: public Ui_frmAnimationButton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMANIMATIONBUTTON_H
