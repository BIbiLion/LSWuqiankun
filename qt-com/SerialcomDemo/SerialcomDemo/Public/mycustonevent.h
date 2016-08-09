#ifndef MYCUSTONEVENT
#define MYCUSTONEVENT
#include <QEvent>
#include <QByteArray>

// 自定义事件
// QEvent::type  =  QEvent::User+1

class MyCustonEvent : public QEvent
{
public:
    explicit MyCustonEvent(QByteArray str);

public:
    QByteArray strData;
};

#endif // MYCUSTONEVENT

