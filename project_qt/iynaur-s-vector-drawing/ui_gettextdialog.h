/********************************************************************************
** Form generated from reading UI file 'gettextdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETTEXTDIALOG_H
#define UI_GETTEXTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GetTextDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GetTextDialog)
    {
        if (GetTextDialog->objectName().isEmpty())
            GetTextDialog->setObjectName(QStringLiteral("GetTextDialog"));
        GetTextDialog->resize(361, 176);
        verticalLayoutWidget = new QWidget(GetTextDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 341, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        verticalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(GetTextDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GetTextDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GetTextDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GetTextDialog);
    } // setupUi

    void retranslateUi(QDialog *GetTextDialog)
    {
        GetTextDialog->setWindowTitle(QApplication::translate("GetTextDialog", "Dialog", 0));
        label->setText(QApplication::translate("GetTextDialog", "Enter text here!", 0));
    } // retranslateUi

};

namespace Ui {
    class GetTextDialog: public Ui_GetTextDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETTEXTDIALOG_H
