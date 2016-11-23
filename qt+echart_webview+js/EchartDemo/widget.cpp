#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->btnLine->click();
     qDebug()<< qApp->applicationDirPath();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnLine_clicked()
{
    //ui->webView->load(QUrl(qApp->applicationDirPath()+"/html/line.html"));
    ui->webView->load( QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/line.html") );
}

void Widget::on_btnLinex_clicked()
{
   // ui->webView->load(QUrl(qApp->applicationDirPath()+"/html/linex.html"));
       ui->webView->load( QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/linex.html") );
}

void Widget::on_btnLiney_clicked()
{
   // ui->webView->load(QUrl(qApp->applicationDirPath()+"/html/liney.html"));
       ui->webView->load( QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/liney.html") );
}

void Widget::on_btnBar_clicked()
{
   // ui->webView->load(QUrl(qApp->applicationDirPath()+"/html/bar.html"));
       ui->webView->load( QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/bar.html") );
}

void Widget::on_btnBarx_clicked()
{
    //ui->webView->load(QUrl(qApp->applicationDirPath()+"/html/barx.html"));
       ui->webView->load( QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/barx.html") );
}

void Widget::on_btnBary_clicked()
{
   // ui->webView->load(QUrl(qApp->applicationDirPath()+"/html/bary.html"));
       ui->webView->load( QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/bary.html") );
}

void Widget::on_btnScatter_clicked()
{
  //  ui->webView->load(QUrl(qApp->applicationDirPath()+"/html/scatter.html"));
       ui->webView->load( QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/scatter.html") );
}

void Widget::on_btnK_clicked()
{
    //ui->webView->load(QUrl(qApp->applicationDirPath()+"/html/k.html"));
       ui->webView->load( QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/k.html") );
}

void Widget::on_btnPie_clicked()
{
    ui->webView->load(QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/pie.html"));
}

void Widget::on_btnRadar_clicked()
{
    ui->webView->load(QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/radar.html"));
}

void Widget::on_btnChord_clicked()
{
    ui->webView->load(QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/chord.html"));
}

void Widget::on_btnGauge_clicked()
{
    ui->webView->load(QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/gauge.html"));
}

void Widget::on_btnFunnel_clicked()
{
    ui->webView->load(QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/funnel.html"));
}

void Widget::on_btnData_clicked()
{
    ui->webView->load(QUrl::fromLocalFile(qApp->applicationDirPath()+"/html/data.html"));
}
