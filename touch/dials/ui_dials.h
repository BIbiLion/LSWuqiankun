/********************************************************************************
** Form generated from reading UI file 'dials.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALS_H
#define UI_DIALS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dials
{
public:
    QGridLayout *gridLayout;
    QDial *dial_1;
    QDial *dial_2;
    QDial *dial_3;
    QDial *dial_4;
    QDial *dial_5;
    QDial *dial_6;
    QDial *dial_7;
    QDial *dial_8;

    void setupUi(QWidget *Dials)
    {
        if (Dials->objectName().isEmpty())
            Dials->setObjectName(QString::fromUtf8("Dials"));
        Dials->resize(400, 300);
        gridLayout = new QGridLayout(Dials);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dial_1 = new QDial(Dials);
        dial_1->setObjectName(QString::fromUtf8("dial_1"));
        dial_1->setNotchesVisible(true);

        gridLayout->addWidget(dial_1, 0, 0, 1, 1);

        dial_2 = new QDial(Dials);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));
        dial_2->setNotchesVisible(true);

        gridLayout->addWidget(dial_2, 0, 1, 1, 1);

        dial_3 = new QDial(Dials);
        dial_3->setObjectName(QString::fromUtf8("dial_3"));
        dial_3->setNotchesVisible(true);

        gridLayout->addWidget(dial_3, 0, 2, 1, 1);

        dial_4 = new QDial(Dials);
        dial_4->setObjectName(QString::fromUtf8("dial_4"));
        dial_4->setNotchesVisible(true);

        gridLayout->addWidget(dial_4, 0, 3, 1, 1);

        dial_5 = new QDial(Dials);
        dial_5->setObjectName(QString::fromUtf8("dial_5"));
        dial_5->setNotchesVisible(true);

        gridLayout->addWidget(dial_5, 1, 0, 1, 1);

        dial_6 = new QDial(Dials);
        dial_6->setObjectName(QString::fromUtf8("dial_6"));
        dial_6->setNotchesVisible(true);

        gridLayout->addWidget(dial_6, 1, 1, 1, 1);

        dial_7 = new QDial(Dials);
        dial_7->setObjectName(QString::fromUtf8("dial_7"));
        dial_7->setNotchesVisible(true);

        gridLayout->addWidget(dial_7, 1, 2, 1, 1);

        dial_8 = new QDial(Dials);
        dial_8->setObjectName(QString::fromUtf8("dial_8"));
        dial_8->setNotchesVisible(true);

        gridLayout->addWidget(dial_8, 1, 3, 1, 1);


        retranslateUi(Dials);

        QMetaObject::connectSlotsByName(Dials);
    } // setupUi

    void retranslateUi(QWidget *Dials)
    {
        Dials->setWindowTitle(QApplication::translate("Dials", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dials: public Ui_Dials {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALS_H
