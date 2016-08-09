#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExpValidator>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(10);
    ui->lcdNumber->display(1);


    //设置正则表达式
    QRegExpValidator *validator = new QRegExpValidator(QRegExp("^[0-9]*$"), this);
    this->ui->lineEdit->setValidator(validator);

    //显示整数的输入范围【0-100】
    //this->ui->lineEdit_2->setValidator(new QIntValidator(0,100,this));

    //显示的范围是【-9999.999999】
  QDoubleValidator * doubleVaildtor=  new QDoubleValidator(-9999.999999,9999.999999,6,this);
  doubleVaildtor->setNotation(QDoubleValidator::StandardNotation);
  ui->lineEdit_2->setValidator(doubleVaildtor);
  //SetNotation setlocal

  ui->lineEdit->setText("hello");
  ui->lineEdit->setEchoMode(QLineEdit::Password);
  ui->lineEdit->setMaxLength(6);

  connect(ui->checkBox,SIGNAL(toggled(bool)),this,SLOT(testCheckBox(bool)));
  ui->pushButton->setFocusPolicy(Qt::NoFocus);
  ui->pushButton->setFlat(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testCheckBox(bool _false)
{

    QMessageBox *_box =new QMessageBox(this);
    QFont _font;
    _font.setPointSize(15);
    _box->setObjectName("Mes");
   //("QLineEdit#nameEdit { background-color: yellow }");

    _box->information(this,"上位机监控系统","截图成功,文件保存为","确定");
    _box->setStyleSheet("background-color: yellow;");

    qDebug()<<"------"<<_false;
    if(ui->checkBox->checkState()==Qt::Checked)
    {
        qDebug()<<"checked";
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
    }
    else
    {
         ui->lineEdit->setEchoMode(QLineEdit::Password);
    }
}
