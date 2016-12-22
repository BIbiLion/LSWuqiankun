/********************************************************************************
** Form generated from reading UI file 'frmroundplot.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMROUNDPLOT_H
#define UI_FRMROUNDPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "roundplot.h"

QT_BEGIN_NAMESPACE

class Ui_frmRoundPlot
{
public:
    QVBoxLayout *verticalLayout;
    RoundPlot *widget1;
    RoundPlot *widget2;
    QGridLayout *gridLayout;
    QLabel *labMaxValue;
    QLineEdit *txtMaxValue;
    QLineEdit *txtMinValue;
    QLineEdit *txtValue;
    QLabel *labUnit;
    QLabel *labValue;
    QLineEdit *txtUnit;
    QLabel *labMinValue;
    QPushButton *pushButton;

    void setupUi(QWidget *frmRoundPlot)
    {
        if (frmRoundPlot->objectName().isEmpty())
            frmRoundPlot->setObjectName(QStringLiteral("frmRoundPlot"));
        frmRoundPlot->resize(318, 605);
        verticalLayout = new QVBoxLayout(frmRoundPlot);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget1 = new RoundPlot(frmRoundPlot);
        widget1->setObjectName(QStringLiteral("widget1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget1->sizePolicy().hasHeightForWidth());
        widget1->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(widget1);

        widget2 = new RoundPlot(frmRoundPlot);
        widget2->setObjectName(QStringLiteral("widget2"));
        sizePolicy.setHeightForWidth(widget2->sizePolicy().hasHeightForWidth());
        widget2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(widget2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labMaxValue = new QLabel(frmRoundPlot);
        labMaxValue->setObjectName(QStringLiteral("labMaxValue"));

        gridLayout->addWidget(labMaxValue, 0, 2, 1, 1);

        txtMaxValue = new QLineEdit(frmRoundPlot);
        txtMaxValue->setObjectName(QStringLiteral("txtMaxValue"));

        gridLayout->addWidget(txtMaxValue, 0, 3, 1, 1);

        txtMinValue = new QLineEdit(frmRoundPlot);
        txtMinValue->setObjectName(QStringLiteral("txtMinValue"));

        gridLayout->addWidget(txtMinValue, 0, 1, 1, 1);

        txtValue = new QLineEdit(frmRoundPlot);
        txtValue->setObjectName(QStringLiteral("txtValue"));

        gridLayout->addWidget(txtValue, 1, 1, 1, 1);

        labUnit = new QLabel(frmRoundPlot);
        labUnit->setObjectName(QStringLiteral("labUnit"));

        gridLayout->addWidget(labUnit, 1, 2, 1, 1);

        labValue = new QLabel(frmRoundPlot);
        labValue->setObjectName(QStringLiteral("labValue"));

        gridLayout->addWidget(labValue, 1, 0, 1, 1);

        txtUnit = new QLineEdit(frmRoundPlot);
        txtUnit->setObjectName(QStringLiteral("txtUnit"));

        gridLayout->addWidget(txtUnit, 1, 3, 1, 1);

        labMinValue = new QLabel(frmRoundPlot);
        labMinValue->setObjectName(QStringLiteral("labMinValue"));

        gridLayout->addWidget(labMinValue, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton = new QPushButton(frmRoundPlot);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(frmRoundPlot);

        QMetaObject::connectSlotsByName(frmRoundPlot);
    } // setupUi

    void retranslateUi(QWidget *frmRoundPlot)
    {
        frmRoundPlot->setWindowTitle(QApplication::translate("frmRoundPlot", "widget", 0));
        labMaxValue->setText(QApplication::translate("frmRoundPlot", "\346\234\200\345\244\247\345\200\274", 0));
        txtMaxValue->setText(QApplication::translate("frmRoundPlot", "100", 0));
        txtMinValue->setText(QApplication::translate("frmRoundPlot", "0", 0));
        txtValue->setText(QApplication::translate("frmRoundPlot", "88", 0));
        labUnit->setText(QApplication::translate("frmRoundPlot", "\345\215\225\344\275\215", 0));
        labValue->setText(QApplication::translate("frmRoundPlot", "\345\275\223\345\211\215\345\200\274", 0));
        txtUnit->setText(QString());
        labMinValue->setText(QApplication::translate("frmRoundPlot", "\346\234\200\345\260\217\345\200\274", 0));
        pushButton->setText(QApplication::translate("frmRoundPlot", "\345\212\240\350\275\275", 0));
    } // retranslateUi

};

namespace Ui {
    class frmRoundPlot: public Ui_frmRoundPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMROUNDPLOT_H
