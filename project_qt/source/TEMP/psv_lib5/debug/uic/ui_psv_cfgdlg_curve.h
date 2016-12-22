/********************************************************************************
** Form generated from reading UI file 'psv_cfgdlg_curve.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PSV_CFGDLG_CURVE_H
#define UI_PSV_CFGDLG_CURVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PSV_CfgDlg_Curve
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QComboBox *cbox_line;
    QPushButton *btn_line;
    QLabel *label_3;
    QComboBox *cbox_point;
    QPushButton *btn_point;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbtn_parellel;
    QRadioButton *rbtn_line;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_ok;
    QPushButton *btn_cancel;

    void setupUi(QDialog *PSV_CfgDlg_Curve)
    {
        if (PSV_CfgDlg_Curve->objectName().isEmpty())
            PSV_CfgDlg_Curve->setObjectName(QStringLiteral("PSV_CfgDlg_Curve"));
        PSV_CfgDlg_Curve->resize(426, 185);
        verticalLayout = new QVBoxLayout(PSV_CfgDlg_Curve);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(PSV_CfgDlg_Curve);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(PSV_CfgDlg_Curve);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        cbox_line = new QComboBox(PSV_CfgDlg_Curve);
        cbox_line->setObjectName(QStringLiteral("cbox_line"));

        gridLayout->addWidget(cbox_line, 1, 1, 1, 1);

        btn_line = new QPushButton(PSV_CfgDlg_Curve);
        btn_line->setObjectName(QStringLiteral("btn_line"));
        btn_line->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(btn_line, 1, 2, 1, 1);

        label_3 = new QLabel(PSV_CfgDlg_Curve);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        cbox_point = new QComboBox(PSV_CfgDlg_Curve);
        cbox_point->setObjectName(QStringLiteral("cbox_point"));

        gridLayout->addWidget(cbox_point, 2, 1, 1, 1);

        btn_point = new QPushButton(PSV_CfgDlg_Curve);
        btn_point->setObjectName(QStringLiteral("btn_point"));
        btn_point->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(btn_point, 2, 2, 1, 1);

        groupBox = new QGroupBox(PSV_CfgDlg_Curve);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rbtn_parellel = new QRadioButton(groupBox);
        rbtn_parellel->setObjectName(QStringLiteral("rbtn_parellel"));

        horizontalLayout->addWidget(rbtn_parellel);

        rbtn_line = new QRadioButton(groupBox);
        rbtn_line->setObjectName(QStringLiteral("rbtn_line"));

        horizontalLayout->addWidget(rbtn_line);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout->addWidget(groupBox, 3, 0, 1, 3);

        lineEdit = new QLineEdit(PSV_CfgDlg_Curve);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btn_ok = new QPushButton(PSV_CfgDlg_Curve);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));

        horizontalLayout_3->addWidget(btn_ok);

        btn_cancel = new QPushButton(PSV_CfgDlg_Curve);
        btn_cancel->setObjectName(QStringLiteral("btn_cancel"));

        horizontalLayout_3->addWidget(btn_cancel);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(PSV_CfgDlg_Curve);

        QMetaObject::connectSlotsByName(PSV_CfgDlg_Curve);
    } // setupUi

    void retranslateUi(QDialog *PSV_CfgDlg_Curve)
    {
        PSV_CfgDlg_Curve->setWindowTitle(QApplication::translate("PSV_CfgDlg_Curve", "\347\274\226\350\276\221\346\233\262\347\272\277\345\261\236\346\200\247", 0));
        label->setText(QApplication::translate("PSV_CfgDlg_Curve", "\346\233\262\347\272\277\345\220\215", 0));
        label_2->setText(QApplication::translate("PSV_CfgDlg_Curve", "\347\272\277", 0));
        btn_line->setText(QString());
        label_3->setText(QApplication::translate("PSV_CfgDlg_Curve", "\347\202\271", 0));
        btn_point->setText(QString());
        groupBox->setTitle(QApplication::translate("PSV_CfgDlg_Curve", "\351\243\216\346\240\274", 0));
        rbtn_parellel->setText(QApplication::translate("PSV_CfgDlg_Curve", "\345\271\263\347\233\264", 0));
        rbtn_line->setText(QApplication::translate("PSV_CfgDlg_Curve", "\346\212\230\347\272\277", 0));
        btn_ok->setText(QApplication::translate("PSV_CfgDlg_Curve", "\347\241\256\345\256\232", 0));
        btn_cancel->setText(QApplication::translate("PSV_CfgDlg_Curve", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class PSV_CfgDlg_Curve: public Ui_PSV_CfgDlg_Curve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PSV_CFGDLG_CURVE_H
