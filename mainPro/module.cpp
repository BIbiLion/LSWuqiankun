#include "module.h"



 Module::Module()
 {

    m_process= new QProcess;
    qDebug()<<"construction................"<<m_process->pid();
 }



int Module::instllModule()
{
    QString _argument("insmod filterDriver");
    qDebug()<<"+++++++++++++++++"<<_argument<<m_process->pid();
  // m_process->start(_argument);
}

int Module::removeModule()
{
    QString _argument("rmmod filterDriver");
    qDebug()<<"------------------"<<_argument<<m_process->pid();
  //  m_process->start(_argument);
}
