#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QEvent>
#include <QPoint>
#include <QMouseEvent>
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

protected:
    void mousePressEvent(QMouseEvent* );
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

private:
    Ui::MainWidget *ui;
   //QStringList m_fileNames;
    QString m_saveDir;
    QPoint m_point;
    bool m_isMove;
};

#endif // MAINWIDGET_H
