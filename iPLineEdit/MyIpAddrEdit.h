// MyIpAddrEdit.h
#pragma once

#include <QWidget>

class QLineEdit;
class QLabel;
class MyIpPartLineEdit;

class MyIpAddrEdit : public QWidget
{
    Q_OBJECT
public:
    MyIpAddrEdit(QWidget* pParent = 0);
    ~MyIpAddrEdit();

    void settext(const QString &text);
    QString text();
    void setStyleSheet(const QString &styleSheet);

signals:
    void textchanged(const QString& text);
    void textedited(const QString &text);

private slots:
    void textchangedslot(const QString& text);
    void texteditedslot(const QString &text);

private:
    MyIpPartLineEdit *ip_part1_;
    MyIpPartLineEdit *ip_part2_;
    MyIpPartLineEdit *ip_part3_;
    QLineEdit *ip_part4_;

    QLabel *labeldot1_;
    QLabel *labeldot2_;    
    QLabel *labeldot3_;
};