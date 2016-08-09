#include "imagewidget.h"
#include <QPainter>
#include <QPalette>
#include <QPushButton>
#include <QStateMachine>
#include <QFinalState>
ImageWidget::ImageWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(200,200);
    //this->setBackgroundRole(QPalette::);


    QPushButton *button= new QPushButton;

    QStateMachine *machine= new QStateMachine;
    QState *s1 = new QState();
    s1->assignProperty(button, "text", QVariant("Click me"));



    QState *s2 = new QState();
    s2->assignProperty(button, "text", QVariant("strong Click me"));
    s1->addTransition(button, SIGNAL(clicked()), s2);

    QFinalState *fina = new QFinalState();
    s2->addTransition(button, SIGNAL(clicked()), s1);


    machine->addState(s1);
    machine->addState(s2);
    machine->addState(fina);
    machine->setInitialState(s1);
    machine->start();
    button->show();
}

void ImageWidget::paintEvent(QPaintEvent *)
{

    QImage _image("://pre//Winter.jpg");
//    QPanter _paint(this);
    QPainter p(this);
    p.drawImage(QPoint(0, 0), _image);
    p.end();
}
