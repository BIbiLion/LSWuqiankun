#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QtGui/QDialog>
#include "ui_myserialport.h"

#include <QextSerialPort>
#include <QTimer>

class MySerialPort : public QDialog
{
	Q_OBJECT

public:
	MySerialPort(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MySerialPort();

public:
	QString VERSION;

private slots:
	void on_comboBox_Comm_currentIndexChanged(const QString &);
	void on_comboBox_DisplayRec_currentIndexChanged(const QString &);
	void on_comboBox_StopBits_currentIndexChanged(const QString &);
	void on_comboBox_DataBits_currentIndexChanged(const QString &);
	void on_comboBox_Parity_currentIndexChanged(const QString &);
	void on_comboBox_BaudRate_currentIndexChanged(const QString &);
	void on_pushButton_Send_clicked();
	void on_pushButton_ClearSend_clicked();
	void on_pushButton_ClearRec_clicked();
	void on_pushButton_Open_clicked();
	void on_pushButton_StopDisplay_clicked();
	void on_pushButton_Browse_clicked();
	void on_pushButton_About_clicked();
	void on_checkBox_AutoSend_stateChanged(int);
	void on_lineEdit_SendTime_editingFinished();
	void updateReceiveWindow();
	void timeout();
	//void clearCounter();
	void onScroll(int action);

private:
	Ui::MySerialPortClass ui;

	QextSerialPort *comm;
	//QextSerialPort commReader;

	QByteArray sendBuf;
	QString receiveBuf;
	QRegExp regExpCheck;

	QTimer timerSend;

	int bytesRcved;
	int bytesSend;
	bool isStopDisplay;

};

#endif // MYSERIALPORT_H
