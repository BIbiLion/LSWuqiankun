#include "mycustonevent.h"

    MyCustonEvent::MyCustonEvent(QByteArray str)
        : QEvent((QEvent::Type)(QEvent::User+1)), strData(str)
    {

    }
