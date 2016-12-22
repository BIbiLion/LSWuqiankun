#ifndef PSV_CHARTDATETIMEITEM_H
#define PSV_CHARTDATETIMEITEM_H
#include <QDateTime>
#include "psv_chartitem.h"

/*!
  \class PSV_ChartDateTimeItem
  \brief X����������ΪDateTime��ά����ͼ
  \author miaozhengwei QQ��393758926
  \version 1.0.1
  \date 2014-03-10 �޸�
*/

class PSVLIB_API PSV_ChartDateTimeItem : public PSV_ChartItem
{
public:
    PSV_ChartDateTimeItem(const QMap<int, QVariant> &param, QGraphicsItem * parent = 0 );
    ~PSV_ChartDateTimeItem();
    virtual int type () const;

    bool addCurve(const QMap<QDateTime,double> &data,const PSV_CurveParam & curveParam,bool isDate = false);
    bool addCurve(const QMap<QDate,double> &data,const PSV_CurveParam & curveParam);

protected:
    PSV::DATATYPE dataType();
    virtual void setPrivateItemNull();
    virtual void afterUpdateItem();
    virtual PSV_Item* getInstance(){return this;}
    QString getToolTipText(const double x, const double y);
    virtual QString getTipDataTextX(const double dataX);//�����д�ʵ��

protected:
    QDateTime m_beginDateTime;
    QDateTime m_max_dateTime;
    QDateTime m_min_dateTime;
};

#endif // PSV_CHARTDATETIMEITEM_H
