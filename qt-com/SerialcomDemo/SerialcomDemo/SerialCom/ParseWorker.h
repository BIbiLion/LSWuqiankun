#ifndef _PARSEWORKER_H_
#define _PARSEWORKER_H_
#include <QObject>

// 用于解析上行数据的工作类
class ParseWorker : public QObject
{
    Q_OBJECT
public:
    explicit ParseWorker(QObject *parent = 0);
    ~ParseWorker();

signals:
    void sig_startToParse();

private slots:
    void slot_startToParse();

private:
    void initConnect();

public:
    // 事件接受者
    QObject *pReceiver;

private:
    bool m_bParse;

};

#endif
