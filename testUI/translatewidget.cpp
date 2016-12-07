#include "translatewidget.h"
#include "ui_translatewidget.h"
#include <QLabel>

#include <QVBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QHBoxLayout>
translateWidget::translateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::translateWidget)
{

    ui->setupUi(this);
    this->setFixedSize(690,690);
    QLabel * _label = new QLabel(this);
  //  _label->setStyleSheet("QLabel{background-color:red;}");
   // _label->setText("translate");
    _label->setPixmap(QPixmap("./earth.jpg"));
    QVBoxLayout * _layout= new QVBoxLayout;
    _layout->addWidget(_label);
    _layout->setSpacing(0);
    _layout->setMargin(0);
    this->setLayout(_layout);


    QVBoxLayout *_labelLayout= new QVBoxLayout;
    QPushButton * _newBtn= new QPushButton;
    QSpacerItem * _item= new QSpacerItem(40,40, QSizePolicy::Fixed, QSizePolicy::Expanding);
    _labelLayout->addSpacerItem(_item);
    _labelLayout->addWidget(_newBtn);

   _labelLayout->setSpacing(0);
   _labelLayout->setMargin(0);
   _newBtn->setStyleSheet("background-color:transparent;");
   _newBtn->setIcon(QIcon("./airplan.png"));
   _newBtn->setIconSize(QSize(60,60) );


   QPushButton * _Btn= new QPushButton;
   _Btn->setStyleSheet("background-color:transparent;");
   _Btn->setIcon(QIcon("./attack.png"));
   _Btn->setIconSize(QSize(60,60) );
   QVBoxLayout * _attackLayout= new QVBoxLayout;
   QSpacerItem * _itemV= new QSpacerItem(40,40, QSizePolicy::Fixed, QSizePolicy::Expanding);
  _attackLayout->addSpacerItem(_itemV);
  _attackLayout->addWidget(_Btn);



QHBoxLayout* _hboxlayout= new QHBoxLayout;

QSpacerItem * _item2= new QSpacerItem(40,40, QSizePolicy::Expanding, QSizePolicy::Fixed);

_hboxlayout->addLayout(_attackLayout);
_hboxlayout->addSpacerItem(_item2);


QVBoxLayout * _mainLayout= new QVBoxLayout;
_mainLayout->addLayout(_hboxlayout);
_mainLayout->addLayout(_labelLayout);

_label->setLayout(_mainLayout);
connect(_Btn,SIGNAL(clicked()),_Btn,SLOT(hide()));
connect(_newBtn,SIGNAL(clicked()),_Btn,SLOT(show()));
connect(_newBtn,SIGNAL(clicked()),this,SLOT(showMenu()));
}

translateWidget::~translateWidget()
{
    delete ui;
}

#include <QMenu>
void translateWidget::showMenu()
{
    QMenu * _menu= new QMenu;
   _menu->addAction(QIcon(),"quit");

    _menu->exec(QCursor::pos());//获取飞机按钮的起始点坐标，设置到这个位置

}
