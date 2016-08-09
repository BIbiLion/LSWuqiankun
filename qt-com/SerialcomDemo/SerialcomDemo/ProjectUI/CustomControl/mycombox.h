#ifndef MYCOMBOX_H
#define MYCOMBOX_H
#include <QComboBox>

class MyCombox : public QComboBox
{
public:
    explicit MyCombox(QWidget *parent = 0);
    ~MyCombox();
public:
    virtual void showPopup();

private:
    void enumPortList();

};

#endif // MYCOMBOX_H
