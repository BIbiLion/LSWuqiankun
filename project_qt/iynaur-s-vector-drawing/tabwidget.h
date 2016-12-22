#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include "gettextdialog.h"
#include "myfontdialog.h"
#include "mycolordialog.h"
namespace Ui {
class TabWidget;
}

class TabWidget : public QTabWidget//,public QDialog
{
    Q_OBJECT

public:
    explicit TabWidget(QWidget *parent = 0);
    ~TabWidget();
    QFont newfont;
    QString newtext;
    QColor newcolor;
    MyFontDialog* fdlg;
    MyColorDialog* cdlg;
    GetTextDialog* gtdlg;

    //void exec();
public slots:
    //void onTextChanged();

private:
    //Ui::TabWidget *ui;

};

#endif // TABWIDGET_H
