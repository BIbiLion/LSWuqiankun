#include "ParseWorker.h"
#include "Public/global.h"
#include <iostream>
#include "Public/mycustonevent.h"
#include <QApplication>

ParseWorker::ParseWorker(QObject *parent)
    : QObject(parent)
{
    m_bParse = true;
    initConnect();
}

ParseWorker::~ParseWorker()
{

}

void ParseWorker::slot_startToParse()
{
    while(m_bParse)
    {
        QByteArray bytes = gParseQueue.take_front_block();
        std::cout<<bytes.toStdString()<<std::endl;
        MyCustonEvent *event = new MyCustonEvent(bytes);
        QApplication::postEvent(pReceiver, event);
    }
}

void ParseWorker::initConnect()
{
    connect(this, SIGNAL(sig_startToParse()), this, SLOT(slot_startToParse()));
}
