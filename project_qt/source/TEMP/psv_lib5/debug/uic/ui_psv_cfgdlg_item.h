/********************************************************************************
** Form generated from reading UI file 'psv_cfgdlg_item.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PSV_CFGDLG_ITEM_H
#define UI_PSV_CFGDLG_ITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PSV_CfgDlg_Item
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_save;
    QPushButton *btn_cancel;

    void setupUi(QDialog *PSV_CfgDlg_Item)
    {
        if (PSV_CfgDlg_Item->objectName().isEmpty())
            PSV_CfgDlg_Item->setObjectName(QStringLiteral("PSV_CfgDlg_Item"));
        PSV_CfgDlg_Item->resize(687, 116);
        verticalLayout = new QVBoxLayout(PSV_CfgDlg_Item);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gLayout = new QGridLayout();
        gLayout->setObjectName(QStringLiteral("gLayout"));

        verticalLayout->addLayout(gLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_save = new QPushButton(PSV_CfgDlg_Item);
        btn_save->setObjectName(QStringLiteral("btn_save"));

        horizontalLayout->addWidget(btn_save);

        btn_cancel = new QPushButton(PSV_CfgDlg_Item);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));

        horizontalLayout->addWidget(btn_cancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PSV_CfgDlg_Item);

        QMetaObject::connectSlotsByName(PSV_CfgDlg_Item);
    } // setupUi

    void retranslateUi(QDialog *PSV_CfgDlg_Item)
    {
        PSV_CfgDlg_Item->setWindowTitle(QApplication::translate("PSV_CfgDlg_Item", "Dialog", 0));
        btn_save->setText(QApplication::translate("PSV_CfgDlg_Item", "\344\277\235\345\255\230", 0));
        btn_cancel->setText(QApplication::translate("PSV_CfgDlg_Item", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class PSV_CfgDlg_Item: public Ui_PSV_CfgDlg_Item {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PSV_CFGDLG_ITEM_H
