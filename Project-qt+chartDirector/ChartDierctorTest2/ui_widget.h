/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ldtdir;
    QPushButton *ptnsavedir;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *ptnshowimg;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(655, 521);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        ldtdir = new QLineEdit(Widget);
        ldtdir->setObjectName(QStringLiteral("ldtdir"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ldtdir->sizePolicy().hasHeightForWidth());
        ldtdir->setSizePolicy(sizePolicy);
        ldtdir->setMaximumSize(QSize(400, 16777215));
        ldtdir->setReadOnly(true);

        horizontalLayout->addWidget(ldtdir);

        ptnsavedir = new QPushButton(Widget);
        ptnsavedir->setObjectName(QStringLiteral("ptnsavedir"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ptnsavedir->sizePolicy().hasHeightForWidth());
        ptnsavedir->setSizePolicy(sizePolicy1);
        ptnsavedir->setMaximumSize(QSize(90, 16777215));

        horizontalLayout->addWidget(ptnsavedir);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ptnshowimg = new QPushButton(Widget);
        ptnshowimg->setObjectName(QStringLiteral("ptnshowimg"));
        sizePolicy1.setHeightForWidth(ptnshowimg->sizePolicy().hasHeightForWidth());
        ptnshowimg->setSizePolicy(sizePolicy1);
        ptnshowimg->setMaximumSize(QSize(90, 16777215));

        horizontalLayout->addWidget(ptnshowimg);

        horizontalSpacer_2 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QApplication::translate("Widget", "\345\233\276\347\211\207\344\277\235\345\255\230\344\275\215\347\275\256\357\274\232", 0));
        ldtdir->setText(QApplication::translate("Widget", "E:\\", 0));
        ptnsavedir->setText(QApplication::translate("Widget", "\346\233\264\346\224\271\344\277\235\345\255\230\347\233\256\345\275\225", 0));
        label_2->setText(QApplication::translate("Widget", "\344\277\235\345\255\230\347\233\256\345\275\225\346\232\202\344\270\215\346\224\257\346\214\201\344\270\255\346\226\207\347\233\256\345\275\225", 0));
        ptnshowimg->setText(QApplication::translate("Widget", "\346\237\245\347\234\213\346\210\252\345\233\276", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
