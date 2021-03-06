#include "myserialport.h"
#include <QextSerialPort>
#include <QextSerialEnumerator>

 #include <QMessageBox>
 #include <QScrollBar>


MySerialPort::MySerialPort(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags),VERSION("1.04")
{
	ui.setupUi(this);

	//this->setUpdatesEnabled(true);
	ui.plainTextEdit_RecBuf->setUpdatesEnabled(true);
	this->setWindowTitle(QString::fromLocal8Bit("我的串口 V") + this->VERSION);

	//modify the port settings on your own
	comm = new QextSerialPort();	
	comm->setQueryMode(QextSerialPort::EventDriven);

	connect(comm, SIGNAL(readyRead()), this, SLOT(updateReceiveWindow()));

	timerSend.setInterval(1000);
	connect(&timerSend, SIGNAL(timeout()), this, SLOT(timeout()));

	bytesRcved = bytesSend = 0;
	ui.lcdNumber_ReceivedBytes->setNumDigits(7);
	ui.lcdNumber_SendBytes->setNumDigits(7);

	isStopDisplay = false;


	QStringList strlist;

	// 初始化界面

	QextSerialEnumerator enumer;

	QList<QextPortInfo> ports = enumer.getPorts();

	strlist.clear();
	for( int i = 0; i < ports.count(); ++i)
		strlist << ports.at(i).portName;

	ui.comboBox_Comm->addItems(strlist);

	strlist.clear();
	strlist << "300" << "600" << "1200" << "2400" << "4800" << "9600" 
		<< "19200" << "38400" << "56000" << "57600" << "115200";
	ui.comboBox_BaudRate->addItems(strlist);
	ui.comboBox_BaudRate->setCurrentIndex(5);

	strlist.clear();
	strlist << "NONE" << "ODD" << "EVEN";
	ui.comboBox_Parity->addItems(strlist);

	strlist.clear();
	strlist << "8" << "7" << "6";
	ui.comboBox_DataBits->addItems(strlist);

	strlist.clear();
	strlist << "1" << "2";
	ui.comboBox_StopBits->addItems(strlist);

	
	strlist.clear();
	strlist << "ASCII" << QString::fromLocal8Bit("10进制") << QString::fromLocal8Bit("16进制");
	ui.comboBox_DisplaySend->addItems(strlist);
	strlist << "BCD" << "CBCD";
	ui.comboBox_DisplayRec->addItems(strlist);

}

MySerialPort::~MySerialPort()
{
	comm->close();
	delete comm;

}


void MySerialPort::on_comboBox_Comm_currentIndexChanged(const QString &portName)
{
	comm->close();
	comm->setPortName(portName);
	comm->open(QIODevice::ReadWrite);
	
	if (!comm->isOpen())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), 
			QString::fromLocal8Bit("无法打开串口： ") + comm->portName()
			+ QString::fromLocal8Bit("\n指定的串口不存在或者被占用。"));
		ui.pushButton_Open->setText(QString::fromLocal8Bit("打开串口(&O)"));

	}
	else
		ui.pushButton_Open->setText(QString::fromLocal8Bit("关闭串口(&O)"));

	bytesRcved = bytesSend = 0;
	ui.lcdNumber_ReceivedBytes->display(0);
	ui.lcdNumber_ReceivedBytes->display(0);

}



void MySerialPort::on_comboBox_BaudRate_currentIndexChanged(const QString &baud)
{
	int i = baud.toInt();
	switch(i)
	{
	case 300:
		comm->setBaudRate(BAUD300);
		break;
	case 600:
		comm->setBaudRate(BAUD600);
		break;
	case 1200:
		comm->setBaudRate(BAUD1200);
		break;
	case 2400:
		comm->setBaudRate(BAUD2400);
		break;
	case 4800:
		comm->setBaudRate(BAUD4800);
		break;
	case 9600:
		comm->setBaudRate(BAUD9600);
		break;
	case 19200:
		comm->setBaudRate(BAUD19200);
		break;
	case 38400:
		comm->setBaudRate(BAUD38400);
		break;
	//case 43000:
	//	comm->setBaudRate(BAUD43000);
	//	break;
	case 56000:
		comm->setBaudRate(BAUD56000);
		break;
	case 57600:
		comm->setBaudRate(BAUD57600);
		break;
	case 115200:
		comm->setBaudRate(BAUD115200);
		break;
	}
}

void MySerialPort::on_comboBox_Parity_currentIndexChanged(const QString & strPar)
{

	if (strPar == "NONE")
		comm->setParity(PAR_NONE);
	else
		if (strPar == "ODD")
			comm->setParity(PAR_ODD);
		else
			if (strPar == "EVEN")
				comm->setParity(PAR_EVEN);

}


void MySerialPort::on_comboBox_DataBits_currentIndexChanged(const QString &strDBits)
{

	if (strDBits == "8")
		comm->setDataBits(DATA_8);
	else
		if (strDBits == "7")
			comm->setDataBits(DATA_7);
		else
			if (strDBits == "6")
				comm->setDataBits(DATA_6);

}

void MySerialPort::on_comboBox_StopBits_currentIndexChanged(const QString &strStop)
{
	if (strStop == "1")
		comm->setStopBits(STOP_1);
	else
		if (strStop == "2")
			comm->setStopBits(STOP_2);

}

void MySerialPort::on_comboBox_DisplayRec_currentIndexChanged(const QString &strDisplay)
{
	
}

void MySerialPort::on_pushButton_Send_clicked()
{

	if (!comm->isOpen())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), 
			QString::fromLocal8Bit("串口没有打开： ") + comm->portName());
		return;
	}

	QString & strText = ui.textEdit_Send->toPlainText();
	if (strText.length() <= 0)
		return;

	QString strFile = strText.mid(0, strText.indexOf("\n"));
	if (strFile.length() == 0)
		strFile = strText;

	// 发送文件
	if (QFile::exists(strFile)) 
	{

	}
	else	// 发送编辑框内容
	{
		if ("ASCII" == ui.comboBox_DisplaySend->currentText())
		{
			int len = strText.length();

			char * buf = new char[len];

			for (int i = 0; i < len; ++i)
				buf[i] = strText.at(i).toAscii();

			comm->write(buf ,len);

			delete [] buf;

			bytesSend += len;
			ui.lcdNumber_SendBytes->display(bytesSend);

			return;
		}

		if (QString::fromLocal8Bit("10进制") == ui.comboBox_DisplaySend->currentText())
		{

			if (!strText.endsWith(' '))
				strText.append(' ');

			QString strTemp;
			int len = strText.length();
			
			sendBuf.clear();
			for (int i = 0; i < len;)
			{
				int index = strText.indexOf(' ', i, Qt::CaseInsensitive);
				if (index < 0)
					break;

				strTemp = strText.mid(i, index - i);
				i = index + 1;

				unsigned short k = strTemp.toUShort();	
				char c = (char)k;
				sendBuf.append((unsigned char)k);
				++bytesSend;
			}

			comm->write(sendBuf);

			ui.lcdNumber_SendBytes->display(bytesSend);

			return;
		}

		if (QString::fromLocal8Bit("16进制") == ui.comboBox_DisplaySend->currentText())
		{

			if (!strText.endsWith(' '))
				strText.append(' ');

			QString strTemp;
			int len = strText.length();
			
			sendBuf.clear();
			for (int i = 0; i < len;)
			{
				bool ok;
				int index = strText.indexOf(' ', i, Qt::CaseInsensitive);
				if (index < 0)
					break;

				strTemp = strText.mid(i, index - i);
				i = index + 1;

				unsigned short k = strTemp.toUShort(&ok, 16);		
				sendBuf.append((char)k);
				++bytesSend;
			}

			comm->write(sendBuf);

			ui.lcdNumber_SendBytes->display(bytesSend);

			return;
		}		
	}

}


void MySerialPort::updateReceiveWindow()
{
	qint64 len = comm->bytesAvailable();
	if (len <= 0)
		return;


	if ("ASCII" == ui.comboBox_DisplayRec->currentText())
	{	
		char * buf = new char[len];
		int realLen = comm->read(buf, len);

		if (!isStopDisplay)
		{
			ui.plainTextEdit_RecBuf->moveCursor((QTextCursor::End));
			ui.plainTextEdit_RecBuf->insertPlainText(QString::fromAscii(buf, len));
			ui.plainTextEdit_RecBuf->moveCursor((QTextCursor::End));	
		}

		//this->setWindowTitle(QString::number(ui.plainTextEdit_RecBuf->document()->indentWidth()));
		//this->setWindowTitle(QString::number(ui.plainTextEdit_RecBuf->document()->indentWidth ()));

		delete []buf;

		bytesRcved += realLen;
		ui.lcdNumber_ReceivedBytes->display(bytesRcved);

		return;
	}	

	if (QString::fromLocal8Bit("10进制") == ui.comboBox_DisplayRec->currentText())
	{	
		QString strBuf, strTemp;

		char * buf = new char[len];
		int realLen = comm->read(buf, len);
		
		QChar ch;
		for(int i = 0; i < len; ++i)
		{
			strTemp.setNum((unsigned char)buf[i]);
			strBuf.append(strTemp);
			strBuf.append(' ');
		}

		if (!isStopDisplay)
		{
			ui.plainTextEdit_RecBuf->moveCursor((QTextCursor::End));
			ui.plainTextEdit_RecBuf->insertPlainText(strBuf);
			ui.plainTextEdit_RecBuf->moveCursor((QTextCursor::End));
			//ui.plainTextEdit_RecBuf->update();

			//if (ui.checkBox_AutoClear->isChecked() && ui.plainTextEdit_RecBuf->verticalScrollBar()->isVisible())
			//	ui.plainTextEdit_RecBuf->clear();
		}
		delete []buf;

		bytesRcved += realLen;
		ui.lcdNumber_ReceivedBytes->display(bytesRcved);

		return;
	}	

	if (QString::fromLocal8Bit("16进制") == ui.comboBox_DisplayRec->currentText())
	{	
		QString strBuf, strTemp;

		char * buf = new char[len];
		int realLen = comm->read(buf, len);
		
		QChar ch;
		for(int i = 0; i < len; ++i)
		{
			strTemp = QString("%1").arg((unsigned char)buf[i], 2, 16, QChar('0'));
			strBuf.append(strTemp.toUpper());
			strBuf.append(' ');
		}

		if (!isStopDisplay)
		{
			ui.plainTextEdit_RecBuf->moveCursor((QTextCursor::End));
			ui.plainTextEdit_RecBuf->insertPlainText(strBuf);
			ui.plainTextEdit_RecBuf->moveCursor((QTextCursor::End));
			//if (ui.checkBox_AutoClear->isChecked() && ui.plainTextEdit_RecBuf->verticalScrollBar()->isVisible())
			//	ui.plainTextEdit_RecBuf->clear();
		}

		delete []buf;

		bytesRcved += realLen;
		ui.lcdNumber_ReceivedBytes->display(bytesRcved);

		return;
	}

	if ("BCD" == ui.comboBox_DisplayRec->currentText())
	{	
		QString strBuf, strTemp;

		char * buf = new char[len];
		int realLen = comm->read(buf, len);
		
		QChar ch;
		for(int i = 0; i < len; ++i)
		{
			strTemp = QString("%1").arg((unsigned char)((0x0F & buf[i])),2,16, QChar('0'));
			strBuf.append(strTemp.toUpper());
			strBuf.append(' ');
		}

		if (!isStopDisplay)
		{
			ui.plainTextEdit_RecBuf->moveCursor((QTextCursor::End));
			ui.plainTextEdit_RecBuf->insertPlainText(strBuf);
			ui.plainTextEdit_RecBuf->moveCursor((QTextCursor::End));
			//if (ui.checkBox_AutoClear->isChecked() && ui.plainTextEdit_RecBuf->verticalScrollBar()->isVisible())
			//	ui.plainTextEdit_RecBuf->clear();
		}

		delete []buf;

		bytesRcved += realLen;
		ui.lcdNumber_ReceivedBytes->display(bytesRcved);

		return;
	}	


	if ("CBCD" == ui.comboBox_DisplayRec->currentText())
	{	
		QString strBuf, strTemp;

		char * buf = new char[len];
		int realLen = comm->read(buf, len);
		
		QChar ch;
		for(int i = 0; i < len; ++i)
		{
			strTemp = QString("%1").arg((unsigned char)((0x0F & (buf[i])>>4)),1,16);
			strBuf.append(strTemp.toUpper());
			strTemp = QString("%1").arg((unsigned char)((0x0F & buf[i])),1,16);
			strBuf.append(strTemp.toUpper());
			strBuf.append(' ');
		}

		if (!isStopDisplay)
		{
			ui.plainTextEdit_RecBuf->moveCursor((QTextCursor::End));
			ui.plainTextEdit_RecBuf->insertPlainText(strBuf);
			ui.plainTextEdit_RecBuf->moveCursor((QTextCursor::End));
			//if (ui.checkBox_AutoClear->isChecked() && ui.plainTextEdit_RecBuf->verticalScrollBar()->isVisible())
			//	ui.plainTextEdit_RecBuf->clear();
		}

		delete []buf;

		bytesRcved += realLen;
		ui.lcdNumber_ReceivedBytes->display(bytesRcved);

		return;
	}	

}



void MySerialPort::on_pushButton_Open_clicked()
{
	if (comm->isOpen())
	{
		comm->close();
		ui.pushButton_Open->setText(QString::fromLocal8Bit("打开串口(&O)"));
	}
	else
	{
		comm->setPortName(ui.comboBox_Comm->currentText());
		comm->open(QextSerialPort::ReadWrite);

		if (!comm->isOpen())
		{
			QMessageBox::critical(this, QString::fromLocal8Bit("错误"), 
				QString::fromLocal8Bit("无法打开串口： ") + comm->portName()
				+ QString::fromLocal8Bit("\n指定的串口不存在或者被占用。"));
			ui.pushButton_Open->setText(QString::fromLocal8Bit("打开串口(&O)"));
		}
		else
			ui.pushButton_Open->setText(QString::fromLocal8Bit("关闭串口(&O)"));

	}

	bytesRcved = bytesSend = 0;
	ui.lcdNumber_ReceivedBytes->display(0);
	ui.lcdNumber_SendBytes->display(0);


}

void MySerialPort::on_pushButton_ClearRec_clicked()
{
	ui.plainTextEdit_RecBuf->clear();

}

void MySerialPort::on_pushButton_ClearSend_clicked()
{
	ui.textEdit_Send->clear();
}

void MySerialPort::timeout()
{

	if (!ui.checkBox_AutoSend->isChecked() || !comm->isOpen())
		return;

	emit ui.pushButton_Send->click();
}

void MySerialPort::on_lineEdit_SendTime_editingFinished()
{
	int i = ui.lineEdit_SendTime->text().toInt();

	if (i < 10)
	{
		ui.lineEdit_SendTime->setText("10");
		i = 10;
	}

	timerSend.setInterval(i);
}

void MySerialPort::on_checkBox_AutoSend_stateChanged(int i)
{
	if (ui.checkBox_AutoSend->isChecked())
		timerSend.start();
	else
		timerSend.stop();
}

void MySerialPort::on_pushButton_About_clicked()
{
	//QMessageBox::about(this, QString::fromLocal8Bit("关于"),
	//	QString::fromLocal8Bit("\n\nMySerialPort V1.0\n\n作者：后排男生\n有关源码、技术或其它问题，欢迎致电：csoapy@gmail.com"));

	
	QMessageBox::about(this, tr("关于"),
			tr("<B>" "我的串口 V1.03" "</B><BR>"
			"\n作者：后排男生<br>"
                "\n<a href='电子邮箱：csoapy@gmail.com'>csoapy@gmail.com</a>"));

}

void MySerialPort::on_pushButton_Browse_clicked()
{
	this->close();
}



void MySerialPort::on_pushButton_StopDisplay_clicked()
{
	isStopDisplay = !isStopDisplay;
	if (isStopDisplay)
		ui.pushButton_StopDisplay->setText(QString::fromLocal8Bit("继续(&S)"));
	else
		ui.pushButton_StopDisplay->setText(QString::fromLocal8Bit("停止(&S)"));

}

void MySerialPort::onScroll(int action)
{
	// && ui.plainTextEdit_RecBuf->verticalScrollBar()->isVisible()

	//ui.plainTextEdit_RecBuf->update();

	if (ui.checkBox_AutoClear->isChecked())
		ui.plainTextEdit_RecBuf->clear();

}


