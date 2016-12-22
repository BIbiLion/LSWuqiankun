#ifndef PENDIALOG_H
#define PENDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>

class penDialog : public QDialog
{
    Q_OBJECT
public:
    explicit penDialog(QWidget *parent = 0);
    ~penDialog(){}
    QLabel* styleLabel;
    QLabel* colorLabel;
    QLabel* sizeLabel;
    QComboBox* styleBox;
    QComboBox* colorBox;
    QComboBox* sizeBox;
    QPushButton* cancleBtn;
    QPushButton* okBtn;
private:
    void initWindow();
    void initConnect();
signals:

public slots:

};

#endif // PENDIALOG_H
