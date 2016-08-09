#include "widget.h"
#include <QLabel>
#include <QGridLayout>
Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    QLabel * label00=new QLabel("00");
    QLabel * label01=new QLabel("01");

    QLabel * label10=new QLabel("10");
    QLabel * label11=new QLabel("11");


    QGridLayout * _gridLayput=new QGridLayout();

    _gridLayput->addWidget(label00,0,0);
    _gridLayput->addWidget(label01,0,1);


    _gridLayput->addWidget(label10,1,0);
    _gridLayput->addWidget(label11,1,1);

     QLabel * label12=new QLabel("12");

     _gridLayput->addWidget(label12,1,2,2,2);

    setLayout(_gridLayput);
}
