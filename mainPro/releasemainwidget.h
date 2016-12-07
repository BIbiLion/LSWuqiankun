#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void createConnect();
public slots:
   void showPage1();
   void selectFile();


   void showPage2();
   void saveDirPath();
   void copyFile();

   void showPage3();

private:
    Ui::MainWidget *ui;
   //QStringList m_fileNames;
    QString m_saveDir;
};

#endif // MAINWIDGET_H
