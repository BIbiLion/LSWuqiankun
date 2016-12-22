/********************************************************************************
** Form generated from reading UI file 'frmsliderruler.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSLIDERRULER_H
#define UI_FRMSLIDERRULER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <sliderruler.h>

QT_BEGIN_NAMESPACE

class Ui_frmSliderRuler
{
public:
    QVBoxLayout *verticalLayout;
    SliderRuler *widget1;
    SliderRuler *widget2;
    SliderRuler *widget3;

    void setupUi(QWidget *frmSliderRuler)
    {
        if (frmSliderRuler->objectName().isEmpty())
            frmSliderRuler->setObjectName(QStringLiteral("frmSliderRuler"));
        frmSliderRuler->resize(637, 300);
        verticalLayout = new QVBoxLayout(frmSliderRuler);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget1 = new SliderRuler(frmSliderRuler);
        widget1->setObjectName(QStringLiteral("widget1"));

        verticalLayout->addWidget(widget1);

        widget2 = new SliderRuler(frmSliderRuler);
        widget2->setObjectName(QStringLiteral("widget2"));

        verticalLayout->addWidget(widget2);

        widget3 = new SliderRuler(frmSliderRuler);
        widget3->setObjectName(QStringLiteral("widget3"));

        verticalLayout->addWidget(widget3);


        retranslateUi(frmSliderRuler);

        QMetaObject::connectSlotsByName(frmSliderRuler);
    } // setupUi

    void retranslateUi(QWidget *frmSliderRuler)
    {
        frmSliderRuler->setWindowTitle(QApplication::translate("frmSliderRuler", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class frmSliderRuler: public Ui_frmSliderRuler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSLIDERRULER_H
