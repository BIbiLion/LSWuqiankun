#ifndef BRUSHDIALOG_H
#define BRUSHDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>

class brushDialog : public QDialog
{
    Q_OBJECT
public:
    explicit brushDialog(QWidget *parent = 0);
    ~brushDialog(){}
    QLabel* styleLabel;
    QLabel* colorLabel;
    QComboBox* styleBox;
    QComboBox* colorBox;
    QPushButton* cancleBtn;
    QPushButton* okBtn;


};

#endif // BRUSHDIALOG_H
