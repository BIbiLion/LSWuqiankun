#ifndef INPUTSCENESIZEDIALOG_H
#define INPUTSCENESIZEDIALOG_H

#include <QDialog>


class QGridLayout;
class QLabel;
class QLineEdit;
class QPushButton;

class InputSceneSizeDialog : public QDialog
{
	Q_OBJECT

public:
	InputSceneSizeDialog(QWidget *parent = NULL);
	~InputSceneSizeDialog();

	 void getWidthAndHight(int *tmpWidth,int *tmpHight);

private:

	 QGridLayout *gridLayout;
	 QLabel    *withLabel;
	 QLineEdit *withEdit;
	 QLabel    *highLabel;
	 QLineEdit *highEdit;
	 QPushButton *okBtn;
	 QPushButton *cancelBtn;
	 int width;
	 int hight;

	 void initWidget();
public slots:
	
	void okFun();
	
};

#endif // INPUTSCENESIZEDIALOG_H
