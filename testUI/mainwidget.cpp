#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QHBoxLayout>
#include <QLabel>
mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);

  m_index=0;

    m_oneWidget= new QWidget();
QLabel * _label =new QLabel("one widget");
_label->setStyleSheet("QLabel { background: yellow }");

QHBoxLayout * _layout= new QHBoxLayout;
_layout->addWidget(_label);
m_oneWidget->setLayout(_layout);





    m_twoWidget = new QWidget();
    QLabel * _label2 =new QLabel("two widget");
    _label2->setStyleSheet("QLabel { background: red }");
    QHBoxLayout * _layout2= new QHBoxLayout;
    _layout2->addWidget(_label2);
    m_twoWidget->setLayout(_layout2);

    ui->verticalLayout->addWidget(m_oneWidget);
    ui->verticalLayout->addWidget(m_twoWidget);
    m_oneWidget->show();
    m_twoWidget->hide();
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(showPage()));

}

mainWidget::~mainWidget()
{
    delete ui;
}


void mainWidget::showPage()
{
    if(0==m_index)
    {
      m_index=1;
      m_oneWidget->show();
      m_twoWidget->hide();

    }
    else
    {
        m_oneWidget->hide();
        m_twoWidget->show();
         m_index=0;
    }
}
