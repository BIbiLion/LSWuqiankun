/********************************************************************************
** Form generated from reading UI file 'edittextdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITTEXTDIALOG_H
#define UI_EDITTEXTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditTextDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditTextDialog)
    {
        if (EditTextDialog->objectName().isEmpty())
            EditTextDialog->setObjectName(QStringLiteral("EditTextDialog"));
        EditTextDialog->resize(481, 430);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EditTextDialog->sizePolicy().hasHeightForWidth());
        EditTextDialog->setSizePolicy(sizePolicy);
        gridLayoutWidget = new QWidget(EditTextDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 461, 361));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buttonBox = new QDialogButtonBox(EditTextDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(310, 390, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(EditTextDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditTextDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditTextDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditTextDialog);
    } // setupUi

    void retranslateUi(QDialog *EditTextDialog)
    {
        EditTextDialog->setWindowTitle(QApplication::translate("EditTextDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class EditTextDialog: public Ui_EditTextDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITTEXTDIALOG_H
