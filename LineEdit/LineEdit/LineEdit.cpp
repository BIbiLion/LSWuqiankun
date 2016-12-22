/*
 * another way:To resized the ComWidget
 * use the ResizeEvent
 * */

#include "LineEdit.h"
#include <QDir>
#include <QDebug>
#include <QEvent>
CLineEdit::CLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
  //  this->setFrame(false);
    m_bFocus = false;
    initWidgets();
    installEventFilter(this);
    this->setStyleSheet("padding:0px 15px 0px 0px;");//留一点右边的空间用于放置删除内容的控件
    connect(this,SIGNAL(textChanged(QString)),this,SLOT(sltTextChanged(QString)));
    connect(m_qpClearLbl,SIGNAL(sigClicked()),this,SLOT(clear()));
}
void CLineEdit::initWidgets()
{
   m_qpClearLbl=new CLabel(this);  
   QPixmap  pixmap;
   qDebug()<<"currentPath"<<QDir::currentPath();
   // pixmap.load(":/images/clear.png");
  pixmap.load(QDir::currentPath()+"/images/clear.png");
   QPixmap newPixmap = pixmap.scaled(QSize(15,15),Qt::KeepAspectRatio,Qt::SmoothTransformation);
   m_qpClearLbl->setPixmap(newPixmap);
   m_qpClearLbl->hide();
}

void CLineEdit::resizeEvent(QResizeEvent *e)
{
   // qDebug()<<"width"<<this->width()<<"height"<<this->height();
    m_qpClearLbl->move(this->width()-20,3);
    QWidget::resizeEvent(e);
}
void CLineEdit::sltTextChanged(const QString &str)
{
    if(str.isEmpty())
    {
        m_qpClearLbl->hide();
    }
    else
    {
        m_qpClearLbl->show();
    }
}

bool CLineEdit::eventFilter(QObject *target,QEvent *event)
{

    if( event->type() == QEvent::FocusIn)
    {
        if(!this->text().isEmpty())
        {
            m_qpClearLbl->show();
        }
       m_bFocus = true;
    }
    if(event->type() == QEvent::FocusOut)
    {
        m_qpClearLbl->hide();
        m_bFocus = false;
    }
    return QWidget::eventFilter(target,event);
}



