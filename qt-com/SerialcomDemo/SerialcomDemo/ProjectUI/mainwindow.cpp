#include "mainwindow.h"
#include "Public/mycustonevent.h"
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    taskOpt();
    createControl();
    initUI();
    initConnect();
}

MainWindow::~MainWindow()
{

}

void MainWindow::customEvent(QEvent *event)
{
    switch(event->type())
    {
    case QEvent::User+1:
        {
            MyCustonEvent *cusEve = reinterpret_cast<MyCustonEvent *>(event);
            QByteArray bytes = cusEve->strData;
            insertList(bytes);
        }
        break;
    default:

        break;
    }
}

void MainWindow::taskOpt()
{
    parse = new ParseWorker;
    parse->pReceiver = this;
    serial = new SerialCom(this);
    parse->moveToThread(&parseThrd);
    parseThrd.start();
    emit parse->sig_startToParse();
}

void MainWindow::createControl()
{
    this->setMinimumSize(850, 550);
    QWidget *mainWidget = new QWidget(this);
    this->setCentralWidget(mainWidget);
    mainLayout = new QHBoxLayout(mainWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    leftWidget = new QWidget(this);
    rightList = new QListWidget(this);
    rightList->setFocusPolicy(Qt::NoFocus);
    leftLayout = new QVBoxLayout(leftWidget);
    leftLayout->setSpacing(30);
    leftLayout->setContentsMargins(10, 25, 10, 0);

    serialPortLayout = new QHBoxLayout;
    serialPortBox = new MyCombox(this);
    serialPortBox->setStyleSheet(QString("QComboBox{border-radius: 3px;"
                                         "padding: 1px 10px 1px 5px;"
                                         "border: 1px solid #5CACEE;"
                                         "}"
                                         "QComboBox::drop-down,QDateEdit::drop-down {"
                                         "subcontrol-origin: padding;"
                                         "subcontrol-position: top right;"
                                         "width: 15px;"
                                         "border-left-width: 1px;"
                                         "border-left-style: solid;"
                                         "border-top-right-radius: 3px;"
                                         "border-bottom-right-radius: 3px;"
                                         "border-left-color: #5CACEE;"
                                         "}"
                                         "QComboBox::down-arrow,QDateEdit::down-arrow {"
                                         "image: url(:/Image/array_down.png);"
                                         "}"));
    serialPortButton = new QPushButton(this);
    QFont font1, font2;
    font1.setFamily("microsoft yahei");
    font1.setPointSize(9);
    serialPortButton->setFont(font1);
    serialPortButton->setFixedHeight(25);
    serialPortButton->setText(tr("打开"));

    font2.setFamily(tr("宋体"));
    font2.setPointSize(15);
    font2.setBold(true);
    refreshButton = new QPushButton(this);
    refreshButton->setFont(font2);
    refreshButton->setFixedHeight(35);
    refreshButton->setText(tr("刷新"));
}

void MainWindow::initUI()
{
    mainLayout->addWidget(leftWidget);
    mainLayout->addWidget(rightList);
    mainLayout->setStretch(0, 1);
    mainLayout->setStretch(1, 3);
    serialPortLayout->addWidget(serialPortBox);
    serialPortLayout->addWidget(serialPortButton);
    leftLayout->addLayout(serialPortLayout);
    leftLayout->addWidget(refreshButton);
    leftLayout->addStretch();
}

void MainWindow::initConnect()
{
    connect(serialPortButton, SIGNAL(clicked()), this, SLOT(slot_openSerial()));
    connect(refreshButton, SIGNAL(clicked()), this, SLOT(slot_refreshList()));
}

// 数据显示列表 数据插入
void MainWindow::insertList(const QByteArray& data)
{
    QFont font;
    font.setFamily("Microsoft Yahei");
    font.setPointSize(9);
    QListWidgetItem *item = new QListWidgetItem(rightList);
    item->setSizeHint(QSize(0, 25));
    item->setFont(font);
    item->setText(data);
    // 确保当前插入的数据可见
    rightList->setCurrentItem(item);
}

void MainWindow::slot_openSerial()
{
    SERIAL_PORT port;
    port.strPort = serialPortBox->currentText();
    if(serial->serialState())
    {
        serial->closeSerial();
        serialPortBox->setEnabled(true);
        serialPortButton->setText(tr("打开"));
    }
    else
    {
        serial->openSerial(port);
        serialPortBox->setEnabled(false);
        serialPortButton->setText(tr("关闭"));
    }
}

void MainWindow::slot_refreshList()
{
    rightList->clear();
}
