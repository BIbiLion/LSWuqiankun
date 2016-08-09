//.h file
#ifndef IPLINEEDIT_H
#define IPLINEEDIT_H
#include <QLineEdit>
class COneIPLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    COneIPLineEdit(QWidget *parent);
    ~COneIPLineEdit();
//signals:
//  void SignalFinished();
//
//public slots:
//  void SlotPreFinished();
//
//private:
//  void SlotTextChanged();
};
/*********************************************************************************/
class CIPLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    CIPLineEdit(QWidget *parent);
    ~CIPLineEdit();
    void setGeometry(int x, int y, int w, int h);
    bool SetIPText(int nIP, int nIndex);
    int GetIPText(int nIndex);
private:
    void paintEvent(QPaintEvent *e);

private:
    COneIPLineEdit *m_pLineEdit[4];
};
#endif // IPLINEEDIT_H
