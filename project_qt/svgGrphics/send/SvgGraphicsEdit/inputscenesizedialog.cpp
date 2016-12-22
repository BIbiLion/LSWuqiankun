#include "inputscenesizedialog.h"
#include <QtGui>

InputSceneSizeDialog::InputSceneSizeDialog(QWidget *parent)
	: QDialog(parent)
{
	initWidget();
	setWindowTitle(tr("场景属性"));
}

InputSceneSizeDialog::~InputSceneSizeDialog()
{

}


void InputSceneSizeDialog::initWidget()
{

	gridLayout = new QGridLayout(this);

	withLabel = new QLabel();
	withLabel->setObjectName(QString::fromUtf8("withLabel"));
	withLabel->setText(tr("宽度"));
	withEdit = new QLineEdit();
	withEdit->setObjectName(QString::fromUtf8("withEdit"));
	withEdit->setText("1280");


	highLabel = new QLabel();
	highLabel->setObjectName(QString::fromUtf8("highLabel"));
	highLabel->setText(tr("高度"));
	highEdit = new QLineEdit();
	highEdit->setObjectName(QString::fromUtf8("withEdit"));
	highEdit->setText("800");

	okBtn = new QPushButton();
    okBtn->setObjectName(QString::fromUtf8("okBtn"));
	okBtn->setText(tr("确定"));
	connect(okBtn, SIGNAL(pressed()), this, SLOT(okFun()));

	cancelBtn = new QPushButton();
    cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
	cancelBtn->setText(tr("取消"));
	connect(cancelBtn, SIGNAL(pressed()), this, SLOT(close()));

    gridLayout->addWidget(withLabel,0,0);
	gridLayout->addWidget(withEdit,0,1);
	gridLayout->addWidget(highLabel,1,0);
	gridLayout->addWidget(highEdit,1,1);
	gridLayout->addWidget(okBtn,2,0);
	gridLayout->addWidget(cancelBtn,2,1);



}


void InputSceneSizeDialog::okFun()
{

	width = withEdit->text().toInt();
	hight = highEdit->text().toInt();
	done(1);
}


void InputSceneSizeDialog::getWidthAndHight(int *tmpWidth,int *tmpHight)
{

	*tmpWidth = width;
	*tmpHight = hight;

}