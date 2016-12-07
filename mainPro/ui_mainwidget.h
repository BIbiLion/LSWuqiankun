/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *minBtn;
    QPushButton *closeBtn;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QFrame *frame1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QFrame *frame2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *page1_lineEdit;
    QPushButton *page1_select_Btn;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *page1_nextStep_BTn;
    QPushButton *page1_cacle_btn;
    QSpacerItem *horizontalSpacer_7;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *page3_sure_Btn;
    QSpacerItem *horizontalSpacer_8;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_12;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_14;
    QFrame *frame3;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_5;
    QFrame *frame4;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *page2_lineEdit;
    QPushButton *page2_selected_Btn;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame5;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *page2_nextStep_Btn;
    QPushButton *page2_cacle_Btn;
    QSpacerItem *horizontalSpacer_9;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(700, 480);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWidget->sizePolicy().hasHeightForWidth());
        MainWidget->setSizePolicy(sizePolicy);
        MainWidget->setMinimumSize(QSize(700, 480));
        MainWidget->setMaximumSize(QSize(704, 480));
        MainWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayout_8 = new QVBoxLayout(MainWidget);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 20);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        frame = new QFrame(MainWidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(700, 100));
        frame->setMaximumSize(QSize(700, 100));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/pageone/resource/1/\351\241\265\347\234\211.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(8);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 5, 5, -1);
        minBtn = new QPushButton(frame);
        minBtn->setObjectName(QStringLiteral("minBtn"));
        sizePolicy1.setHeightForWidth(minBtn->sizePolicy().hasHeightForWidth());
        minBtn->setSizePolicy(sizePolicy1);
        minBtn->setMinimumSize(QSize(20, 20));
        minBtn->setMaximumSize(QSize(20, 20));
        minBtn->setStyleSheet(QString::fromUtf8("image: url(:/pageTwo/C:/Users/Administrator/Desktop/\346\234\200\345\260\217\345\214\226.png);"));
        minBtn->setFlat(true);

        horizontalLayout_2->addWidget(minBtn);

        closeBtn = new QPushButton(frame);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        sizePolicy1.setHeightForWidth(closeBtn->sizePolicy().hasHeightForWidth());
        closeBtn->setSizePolicy(sizePolicy1);
        closeBtn->setMinimumSize(QSize(20, 20));
        closeBtn->setMaximumSize(QSize(20, 20));
        closeBtn->setStyleSheet(QString::fromUtf8("image: url(:/pageone/resource/1/\345\205\263\351\227\255.png);"));
        closeBtn->setFlat(true);

        horizontalLayout_2->addWidget(closeBtn);


        verticalLayout_6->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_6);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_7->addWidget(frame);

        stackedWidget = new QStackedWidget(MainWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(page);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 30);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(700, 90));
        label_2->setMaximumSize(QSize(700, 90));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/pageone/resource/1/\345\206\205\345\256\271.png);"));

        verticalLayout_4->addWidget(label_2);

        frame1 = new QFrame(widget);
        frame1->setObjectName(QStringLiteral("frame1"));
        sizePolicy.setHeightForWidth(frame1->sizePolicy().hasHeightForWidth());
        frame1->setSizePolicy(sizePolicy);
        frame1->setMinimumSize(QSize(0, 120));
        verticalLayout_3 = new QVBoxLayout(frame1);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(frame1);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(0, 40));
        label_3->setMaximumSize(QSize(16777215, 10));
        QFont font;
        font.setPointSize(11);
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(label_3);

        frame2 = new QFrame(frame1);
        frame2->setObjectName(QStringLiteral("frame2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame2->sizePolicy().hasHeightForWidth());
        frame2->setSizePolicy(sizePolicy2);
        frame2->setMinimumSize(QSize(0, 20));
        frame2->setMaximumSize(QSize(16777215, 70));
        horizontalLayout_5 = new QHBoxLayout(frame2);
        horizontalLayout_5->setSpacing(15);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(frame2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        page1_lineEdit = new QLineEdit(frame2);
        page1_lineEdit->setObjectName(QStringLiteral("page1_lineEdit"));
        page1_lineEdit->setMinimumSize(QSize(40, 35));

        horizontalLayout_5->addWidget(page1_lineEdit);

        page1_select_Btn = new QPushButton(frame2);
        page1_select_Btn->setObjectName(QStringLiteral("page1_select_Btn"));
        page1_select_Btn->setMinimumSize(QSize(44, 36));
        page1_select_Btn->setMaximumSize(QSize(44, 36));
        page1_select_Btn->setStyleSheet(QStringLiteral("border-image: url(:/pageone/selected.png);"));

        horizontalLayout_5->addWidget(page1_select_Btn);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_3->addWidget(frame2);


        verticalLayout_4->addWidget(frame1);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        page1_nextStep_BTn = new QPushButton(widget);
        page1_nextStep_BTn->setObjectName(QStringLiteral("page1_nextStep_BTn"));
        sizePolicy1.setHeightForWidth(page1_nextStep_BTn->sizePolicy().hasHeightForWidth());
        page1_nextStep_BTn->setSizePolicy(sizePolicy1);
        page1_nextStep_BTn->setMinimumSize(QSize(130, 36));
        page1_nextStep_BTn->setMaximumSize(QSize(130, 36));
        page1_nextStep_BTn->setStyleSheet(QString::fromUtf8("border-image: url(:/pageone/resource/1/\344\270\213\344\270\200\346\255\245.png);"));

        horizontalLayout->addWidget(page1_nextStep_BTn);

        page1_cacle_btn = new QPushButton(widget);
        page1_cacle_btn->setObjectName(QStringLiteral("page1_cacle_btn"));
        sizePolicy1.setHeightForWidth(page1_cacle_btn->sizePolicy().hasHeightForWidth());
        page1_cacle_btn->setSizePolicy(sizePolicy1);
        page1_cacle_btn->setMinimumSize(QSize(130, 36));
        page1_cacle_btn->setMaximumSize(QSize(130, 36));
        page1_cacle_btn->setStyleSheet(QString::fromUtf8("border-image: url(:/pageone/resource/1/\345\217\226\346\266\210.png);"));

        horizontalLayout->addWidget(page1_cacle_btn);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout_5->addLayout(horizontalLayout);

        verticalLayout_5->setStretch(0, 8);
        verticalLayout_5->setStretch(1, 1);

        verticalLayout->addWidget(widget);

        verticalLayout->setStretch(0, 5);
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayout_11 = new QVBoxLayout(page_3);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        label_8->setMinimumSize(QSize(700, 138));
        label_8->setMaximumSize(QSize(700, 138));
        label_8->setStyleSheet(QString::fromUtf8("border-image: url(:/pageThree/resource/3/\347\240\264\350\247\243\345\212\240\345\257\206.png);"));

        verticalLayout_10->addWidget(label_8);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_10->addItem(verticalSpacer_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        page3_sure_Btn = new QPushButton(page_3);
        page3_sure_Btn->setObjectName(QStringLiteral("page3_sure_Btn"));
        page3_sure_Btn->setMinimumSize(QSize(130, 36));
        page3_sure_Btn->setMaximumSize(QSize(16777215, 30));
        page3_sure_Btn->setStyleSheet(QString::fromUtf8("border-image: url(:/pageThree/resource/3/\347\241\256\345\256\232.png);"));

        horizontalLayout_8->addWidget(page3_sure_Btn);

        horizontalSpacer_8 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);


        verticalLayout_10->addLayout(horizontalLayout_8);

        verticalLayout_10->setStretch(0, 5);
        verticalLayout_10->setStretch(2, 2);

        verticalLayout_11->addLayout(verticalLayout_10);

        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayout_12 = new QVBoxLayout(page_2);
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        widget1 = new QWidget(page_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        verticalLayout_14 = new QVBoxLayout(widget1);
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        frame3 = new QFrame(widget1);
        frame3->setObjectName(QStringLiteral("frame3"));
        verticalLayout_13 = new QVBoxLayout(frame3);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(frame3);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMinimumSize(QSize(700, 90));
        label_5->setMaximumSize(QSize(700, 90));
        label_5->setStyleSheet(QStringLiteral("image: url(:/pageTwo/resource/2/1.png);"));

        verticalLayout_13->addWidget(label_5);

        frame4 = new QFrame(frame3);
        frame4->setObjectName(QStringLiteral("frame4"));
        frame4->setMinimumSize(QSize(0, 120));
        verticalLayout_9 = new QVBoxLayout(frame4);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(frame4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 20));
        label_6->setMaximumSize(QSize(16777215, 10));
        label_6->setFont(font);

        verticalLayout_9->addWidget(label_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(15);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 0, -1, -1);
        label_7 = new QLabel(frame4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_6->addWidget(label_7);

        page2_lineEdit = new QLineEdit(frame4);
        page2_lineEdit->setObjectName(QStringLiteral("page2_lineEdit"));
        page2_lineEdit->setMinimumSize(QSize(0, 35));

        horizontalLayout_6->addWidget(page2_lineEdit);

        page2_selected_Btn = new QPushButton(frame4);
        page2_selected_Btn->setObjectName(QStringLiteral("page2_selected_Btn"));
        page2_selected_Btn->setMinimumSize(QSize(44, 36));
        page2_selected_Btn->setStyleSheet(QString::fromUtf8("border-image: url(:/pageTwo/resource/2/\351\200\211\346\213\251.png);"));

        horizontalLayout_6->addWidget(page2_selected_Btn);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_9->addLayout(horizontalLayout_6);


        verticalLayout_13->addWidget(frame4);


        verticalLayout_14->addWidget(frame3);

        frame5 = new QFrame(widget1);
        frame5->setObjectName(QStringLiteral("frame5"));
        sizePolicy2.setHeightForWidth(frame5->sizePolicy().hasHeightForWidth());
        frame5->setSizePolicy(sizePolicy2);
        frame5->setMinimumSize(QSize(0, 20));
        frame5->setMaximumSize(QSize(16777215, 70));
        horizontalLayout_9 = new QHBoxLayout(frame5);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        page2_nextStep_Btn = new QPushButton(frame5);
        page2_nextStep_Btn->setObjectName(QStringLiteral("page2_nextStep_Btn"));
        page2_nextStep_Btn->setMinimumSize(QSize(130, 36));
        page2_nextStep_Btn->setMaximumSize(QSize(1111, 30));
        page2_nextStep_Btn->setStyleSheet(QString::fromUtf8("border-image: url(:/pageTwo/resource/2/\347\240\264\347\242\216\345\212\240\345\257\206.png);"));

        horizontalLayout_9->addWidget(page2_nextStep_Btn);

        page2_cacle_Btn = new QPushButton(frame5);
        page2_cacle_Btn->setObjectName(QStringLiteral("page2_cacle_Btn"));
        page2_cacle_Btn->setMinimumSize(QSize(130, 36));
        page2_cacle_Btn->setMaximumSize(QSize(16777215, 30));
        page2_cacle_Btn->setStyleSheet(QString::fromUtf8("border-image: url(:/pageone/resource/1/\345\217\226\346\266\210.png);"));

        horizontalLayout_9->addWidget(page2_cacle_Btn);

        horizontalSpacer_9 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout_14->addWidget(frame5);

        verticalLayout_14->setStretch(1, 1);

        verticalLayout_12->addWidget(widget1);

        stackedWidget->addWidget(page_2);

        verticalLayout_7->addWidget(stackedWidget);

        verticalLayout_7->setStretch(0, 2);
        verticalLayout_7->setStretch(1, 7);

        verticalLayout_8->addLayout(verticalLayout_7);


        retranslateUi(MainWidget);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0));
        minBtn->setText(QString());
        closeBtn->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("MainWidget", "     \350\257\267\351\200\211\346\213\251\351\234\200\350\246\201\347\232\204\345\212\240\345\257\206\347\232\204\346\226\207\344\273\266", 0));
        label_4->setText(QApplication::translate("MainWidget", "     \351\200\211\346\213\251\346\226\207\344\273\266\357\274\232", 0));
        page1_select_Btn->setText(QString());
        page1_nextStep_BTn->setText(QString());
        page1_cacle_btn->setText(QString());
        label_8->setText(QString());
        page3_sure_Btn->setText(QString());
        label_5->setText(QString());
        label_6->setText(QApplication::translate("MainWidget", "       \350\257\267\351\200\211\346\213\251\346\226\207\344\273\266\347\232\204\345\255\230\345\202\250\345\234\260\345\235\200", 0));
        label_7->setText(QApplication::translate("MainWidget", "       \345\255\230\345\202\250\345\234\260\345\235\200\357\274\232", 0));
        page2_selected_Btn->setText(QString());
        page2_nextStep_Btn->setText(QString());
        page2_cacle_Btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
