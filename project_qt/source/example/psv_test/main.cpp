#include <QApplication>
#include <QDebug>
#include <QTextCodec>
#include "mainwindow.h"

class A
{
public:
    A(int i):m_i(i){}
    int getI(){return m_i;}
     A(){A a;
        qDebug()<<"t";}
    int m_i;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//#if QT_VERSION < QT_VERSION_CHECK(4, 6, 0)
#if defined(Q_WS_WIN)
    QTextCodec* tc = QTextCodec::codecForLocale();
#else
    QTextCodec* tc = QTextCodec::codecForName("GB2312");
#endif
    QTextCodec::setCodecForLocale(tc);
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    QTextCodec::setCodecForCStrings(tc);
    QTextCodec::setCodecForTr(tc);
#endif
//#endif
    qsrand(QTime::currentTime().msec());
//   return 0;
    MainWindow w;
    w.showMaximized();





//动画沿着制定线路进行运动

     QGraphicsItem *ball = new QGraphicsEllipseItem(0, 0, 20, 20);

      QTimeLine *timer = new QTimeLine(5000);
      timer->setFrameRange(0, 100);

      QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
      animation->setItem(ball);
      animation->setTimeLine(timer);

      for (int i = 0; i < 200; ++i)
          animation->setPosAt(i / 200.0, QPointF(i, i));

      QGraphicsScene *scene = new QGraphicsScene();
      scene->setSceneRect(0, 0, 250, 250);
      scene->addItem(ball);

      QGraphicsView *view = new QGraphicsView(scene);
      view->show();

      timer->start();
    
    return a.exec();
}
