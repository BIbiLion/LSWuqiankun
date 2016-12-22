/********************************************************************************
** Form generated from reading UI file 'frmmain.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMAIN_H
#define UI_FRMMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMain
{
public:
    QTabWidget *tabWidget;
    QWidget *tab1;
    QFrame *fm1;
    QLabel *labValue1;
    QPushButton *btnGauge4;
    QPushButton *btnGauge6;
    QPushButton *btnProgressBar;
    QPushButton *btnVolume;
    QPushButton *btnGauge5;
    QPushButton *btnGauge2;
    QPushButton *btnGauge3;
    QPushButton *btnCoolBar;
    QPushButton *btnGauge1;
    QPushButton *btnIndicator;
    QPushButton *btnGauge7;
    QPushButton *btnBattery;
    QWidget *tab2;
    QFrame *fm2;
    QPushButton *btnChart1;
    QLabel *labValue2;
    QPushButton *btnFlashList;
    QPushButton *btnButtonBoard;
    QPushButton *btnSliderButton;
    QPushButton *btnPhotoView;
    QPushButton *btnAroundCircle;
    QPushButton *btnProgressBar1;
    QPushButton *btnNewLed;
    QPushButton *btnWave;
    QPushButton *btnWave1;
    QPushButton *btnWave2;

    void setupUi(QWidget *frmMain)
    {
        if (frmMain->objectName().isEmpty())
            frmMain->setObjectName(QStringLiteral("frmMain"));
        frmMain->resize(642, 548);
        tabWidget = new QTabWidget(frmMain);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 625, 533));
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setTabsClosable(false);
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        fm1 = new QFrame(tab1);
        fm1->setObjectName(QStringLiteral("fm1"));
        fm1->setGeometry(QRect(0, 0, 481, 509));
        fm1->setFrameShape(QFrame::StyledPanel);
        fm1->setFrameShadow(QFrame::Raised);
        labValue1 = new QLabel(tab1);
        labValue1->setObjectName(QStringLiteral("labValue1"));
        labValue1->setGeometry(QRect(490, 480, 131, 28));
        labValue1->setStyleSheet(QStringLiteral(""));
        btnGauge4 = new QPushButton(tab1);
        btnGauge4->setObjectName(QStringLiteral("btnGauge4"));
        btnGauge4->setGeometry(QRect(490, 120, 125, 29));
        btnGauge4->setCursor(QCursor(Qt::PointingHandCursor));
        btnGauge6 = new QPushButton(tab1);
        btnGauge6->setObjectName(QStringLiteral("btnGauge6"));
        btnGauge6->setGeometry(QRect(490, 200, 125, 29));
        btnGauge6->setCursor(QCursor(Qt::PointingHandCursor));
        btnProgressBar = new QPushButton(tab1);
        btnProgressBar->setObjectName(QStringLiteral("btnProgressBar"));
        btnProgressBar->setGeometry(QRect(490, 280, 125, 29));
        btnProgressBar->setCursor(QCursor(Qt::PointingHandCursor));
        btnVolume = new QPushButton(tab1);
        btnVolume->setObjectName(QStringLiteral("btnVolume"));
        btnVolume->setGeometry(QRect(490, 440, 125, 29));
        btnVolume->setCursor(QCursor(Qt::PointingHandCursor));
        btnGauge5 = new QPushButton(tab1);
        btnGauge5->setObjectName(QStringLiteral("btnGauge5"));
        btnGauge5->setGeometry(QRect(490, 160, 125, 29));
        btnGauge5->setCursor(QCursor(Qt::PointingHandCursor));
        btnGauge2 = new QPushButton(tab1);
        btnGauge2->setObjectName(QStringLiteral("btnGauge2"));
        btnGauge2->setGeometry(QRect(490, 40, 125, 29));
        btnGauge2->setCursor(QCursor(Qt::PointingHandCursor));
        btnGauge3 = new QPushButton(tab1);
        btnGauge3->setObjectName(QStringLiteral("btnGauge3"));
        btnGauge3->setGeometry(QRect(490, 80, 125, 29));
        btnGauge3->setCursor(QCursor(Qt::PointingHandCursor));
        btnCoolBar = new QPushButton(tab1);
        btnCoolBar->setObjectName(QStringLiteral("btnCoolBar"));
        btnCoolBar->setGeometry(QRect(490, 360, 125, 29));
        btnCoolBar->setCursor(QCursor(Qt::PointingHandCursor));
        btnGauge1 = new QPushButton(tab1);
        btnGauge1->setObjectName(QStringLiteral("btnGauge1"));
        btnGauge1->setGeometry(QRect(490, 3, 125, 29));
        btnGauge1->setCursor(QCursor(Qt::PointingHandCursor));
        btnIndicator = new QPushButton(tab1);
        btnIndicator->setObjectName(QStringLiteral("btnIndicator"));
        btnIndicator->setGeometry(QRect(490, 400, 125, 29));
        btnIndicator->setCursor(QCursor(Qt::PointingHandCursor));
        btnGauge7 = new QPushButton(tab1);
        btnGauge7->setObjectName(QStringLiteral("btnGauge7"));
        btnGauge7->setGeometry(QRect(490, 240, 125, 29));
        btnGauge7->setCursor(QCursor(Qt::PointingHandCursor));
        btnBattery = new QPushButton(tab1);
        btnBattery->setObjectName(QStringLiteral("btnBattery"));
        btnBattery->setGeometry(QRect(490, 320, 125, 29));
        btnBattery->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        fm2 = new QFrame(tab2);
        fm2->setObjectName(QStringLiteral("fm2"));
        fm2->setGeometry(QRect(0, 0, 481, 509));
        fm2->setFrameShape(QFrame::StyledPanel);
        fm2->setFrameShadow(QFrame::Raised);
        btnChart1 = new QPushButton(tab2);
        btnChart1->setObjectName(QStringLiteral("btnChart1"));
        btnChart1->setGeometry(QRect(490, 3, 125, 29));
        btnChart1->setCursor(QCursor(Qt::PointingHandCursor));
        labValue2 = new QLabel(tab2);
        labValue2->setObjectName(QStringLiteral("labValue2"));
        labValue2->setGeometry(QRect(490, 480, 131, 28));
        labValue2->setStyleSheet(QStringLiteral(""));
        btnFlashList = new QPushButton(tab2);
        btnFlashList->setObjectName(QStringLiteral("btnFlashList"));
        btnFlashList->setGeometry(QRect(490, 40, 125, 29));
        btnFlashList->setCursor(QCursor(Qt::PointingHandCursor));
        btnButtonBoard = new QPushButton(tab2);
        btnButtonBoard->setObjectName(QStringLiteral("btnButtonBoard"));
        btnButtonBoard->setGeometry(QRect(490, 80, 125, 29));
        btnButtonBoard->setCursor(QCursor(Qt::PointingHandCursor));
        btnSliderButton = new QPushButton(tab2);
        btnSliderButton->setObjectName(QStringLiteral("btnSliderButton"));
        btnSliderButton->setGeometry(QRect(490, 120, 125, 29));
        btnSliderButton->setCursor(QCursor(Qt::PointingHandCursor));
        btnPhotoView = new QPushButton(tab2);
        btnPhotoView->setObjectName(QStringLiteral("btnPhotoView"));
        btnPhotoView->setGeometry(QRect(490, 160, 125, 29));
        btnPhotoView->setCursor(QCursor(Qt::PointingHandCursor));
        btnAroundCircle = new QPushButton(tab2);
        btnAroundCircle->setObjectName(QStringLiteral("btnAroundCircle"));
        btnAroundCircle->setGeometry(QRect(490, 200, 125, 29));
        btnAroundCircle->setCursor(QCursor(Qt::PointingHandCursor));
        btnProgressBar1 = new QPushButton(tab2);
        btnProgressBar1->setObjectName(QStringLiteral("btnProgressBar1"));
        btnProgressBar1->setGeometry(QRect(490, 240, 125, 29));
        btnProgressBar1->setCursor(QCursor(Qt::PointingHandCursor));
        btnNewLed = new QPushButton(tab2);
        btnNewLed->setObjectName(QStringLiteral("btnNewLed"));
        btnNewLed->setGeometry(QRect(490, 280, 125, 29));
        btnNewLed->setCursor(QCursor(Qt::PointingHandCursor));
        btnWave = new QPushButton(tab2);
        btnWave->setObjectName(QStringLiteral("btnWave"));
        btnWave->setGeometry(QRect(490, 320, 125, 29));
        btnWave->setCursor(QCursor(Qt::PointingHandCursor));
        btnWave1 = new QPushButton(tab2);
        btnWave1->setObjectName(QStringLiteral("btnWave1"));
        btnWave1->setGeometry(QRect(490, 360, 125, 29));
        btnWave1->setCursor(QCursor(Qt::PointingHandCursor));
        btnWave2 = new QPushButton(tab2);
        btnWave2->setObjectName(QStringLiteral("btnWave2"));
        btnWave2->setGeometry(QRect(490, 400, 125, 29));
        btnWave2->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->addTab(tab2, QString());

        retranslateUi(frmMain);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmMain);
    } // setupUi

    void retranslateUi(QWidget *frmMain)
    {
        frmMain->setWindowTitle(QApplication::translate("frmMain", "\346\216\247\344\273\266\346\274\224\347\244\272", 0));
        labValue1->setText(QApplication::translate("frmMain", "\345\275\223\345\211\215\345\200\274:", 0));
        btnGauge4->setText(QApplication::translate("frmMain", "\347\272\277\346\200\247\345\210\273\345\272\246\346\214\207\347\244\272\344\273\252", 0));
        btnGauge6->setText(QApplication::translate("frmMain", "\345\236\202\347\233\264\345\217\263\345\210\273\345\272\246\346\214\207\347\244\272\344\273\252", 0));
        btnProgressBar->setText(QApplication::translate("frmMain", "\351\205\267\347\202\253\350\277\233\345\272\246\346\235\241", 0));
        btnVolume->setText(QApplication::translate("frmMain", "\351\242\221\350\260\261\345\210\206\346\236\220\346\216\247\344\273\266", 0));
        btnGauge5->setText(QApplication::translate("frmMain", "\345\234\206\345\275\242\345\210\273\345\272\246\346\214\207\347\244\272\344\273\252", 0));
        btnGauge2->setText(QApplication::translate("frmMain", "\345\234\206\345\275\242\346\214\207\351\222\210\346\214\207\347\244\272\344\273\252", 0));
        btnGauge3->setText(QApplication::translate("frmMain", "\345\267\246\345\217\263\346\273\221\345\235\227\346\214\207\347\244\272\344\273\252", 0));
        btnCoolBar->setText(QApplication::translate("frmMain", "\346\244\255\345\234\206\346\273\221\345\235\227", 0));
        btnGauge1->setText(QApplication::translate("frmMain", "\345\234\206\345\275\242\346\213\261\345\275\242\346\214\207\347\244\272\344\273\252", 0));
        btnIndicator->setText(QApplication::translate("frmMain", "\345\236\202\347\233\264\346\226\271\345\235\227\350\277\233\345\272\246\346\235\241", 0));
        btnGauge7->setText(QApplication::translate("frmMain", "\345\236\202\347\233\264\345\267\246\345\210\273\345\272\246\346\214\207\347\244\272\344\273\252", 0));
        btnBattery->setText(QApplication::translate("frmMain", "\347\224\265\346\272\220\346\214\207\347\244\272\344\273\252", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("frmMain", "tab1", 0));
        btnChart1->setText(QApplication::translate("frmMain", "\345\233\276\350\241\250\346\233\262\347\272\277\346\230\276\347\244\272", 0));
        labValue2->setText(QApplication::translate("frmMain", "\345\275\223\345\211\215\345\200\274:", 0));
        btnFlashList->setText(QApplication::translate("frmMain", "\346\273\221\345\212\250\345\210\227\350\241\250\346\241\206", 0));
        btnButtonBoard->setText(QApplication::translate("frmMain", "\346\214\211\351\222\256\351\235\242\346\235\277", 0));
        btnSliderButton->setText(QApplication::translate("frmMain", "\346\273\221\345\212\250\350\203\214\346\231\257\351\235\242\346\235\277", 0));
        btnPhotoView->setText(QApplication::translate("frmMain", "\345\233\276\347\211\207\346\265\217\350\247\210\345\267\245\345\205\267", 0));
        btnAroundCircle->setText(QApplication::translate("frmMain", "\346\227\213\350\275\254\347\232\204\345\234\206", 0));
        btnProgressBar1->setText(QApplication::translate("frmMain", "\345\217\246\347\261\273\350\277\233\345\272\246\346\235\241", 0));
        btnNewLed->setText(QApplication::translate("frmMain", "LED\346\225\260\345\255\227\346\230\276\347\244\272", 0));
        btnWave->setText(QApplication::translate("frmMain", "\345\243\260\351\237\263\346\263\242\345\275\242\345\212\250\346\200\201\345\233\276", 0));
        btnWave1->setText(QApplication::translate("frmMain", "\345\243\260\351\237\263\347\233\264\346\226\271\345\212\250\346\200\201\345\233\276", 0));
        btnWave2->setText(QApplication::translate("frmMain", "\345\257\271\347\247\260\347\233\264\346\226\271\345\212\250\346\200\201\345\233\276", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("frmMain", "tab2", 0));
    } // retranslateUi

};

namespace Ui {
    class frmMain: public Ui_frmMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMAIN_H
