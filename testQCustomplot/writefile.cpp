#include "writefile.h"
#include <QDebug>
QWriteFile::QWriteFile(const QString &savePath,const QStringList & fileNameList ,QObject *parent ):
    QObject(parent),m_savePath(savePath),m_fileNameList(fileNameList)
{
    if(fileNameList.count()<=0)
    {
        return;
    }
    qDebug()<<fileNameList.count();

    for(int i=0;i<fileNameList.count();++i)
    {
        QFile * _file =new QFile(savePath+fileNameList[i]+".txt");
        m_filePtrList.push_back(_file);
    }


    m_timer= new QTimer;
    connect(m_timer,SIGNAL(timeout()),this,SLOT(changeFileName()));
    m_timer->start(10000);
}
QWriteFile::~QWriteFile()
{
    for(int i=0;i<m_fileNameList.count();++i)
    {
        if(  m_filePtrList[i]->isOpen())
        {
            m_filePtrList[i]->close();
        }

        delete m_filePtrList[i];
    }
    m_filePtrList.clear();

    m_timer->deleteLater();
}
#include <QThread>
void QWriteFile::writeFile(const int &_index, const QString & str)
{
    qDebug()<<"WRITEfILE"<<QThread::currentThreadId();
    if(m_filePtrList.count()<=0)
    {
        return;
    }
    if(! m_filePtrList[_index]->isOpen())
    {
        if( m_filePtrList[_index]->open(QIODevice::WriteOnly| QIODevice::Append| QIODevice::Text) )
        {
            qDebug()<<"no open";
            return;
        }
    }
    QTextStream textStream( (( QFile*) m_filePtrList[_index]) );
    textStream<<str<<"\n";
}

 void QWriteFile::changeFileName()
 {


       qDebug()<<"timer slots:-------"<<QThread::currentThreadId();//the same threadId
     for(int i=0;i<m_fileNameList.count();++i)
     {
         if(  m_filePtrList[i]->isOpen())
         {
             m_filePtrList[i]->close();

         }
         if( m_filePtrList[i]!=NULL)
         {
              delete m_filePtrList[i];
             m_filePtrList[i]=NULL;
         }

     }
     m_filePtrList.clear();

     for(int i=0;i<m_fileNameList.count();++i)
     {
         QFile * _file =new QFile(m_savePath+m_fileNameList[i]+QDateTime::currentDateTime().toString("hhmmssyy")+".txt");
         m_filePtrList.push_back(_file);
     }

 }
