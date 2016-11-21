#include "config.h"

config::config(QWidget *parent) :
    QWidget(parent)
{
}
QString config::GetSavePath()
{
    return m_savePath;
}
void config::SetSavePath(QString str)
{
    m_savePath=str;
}
