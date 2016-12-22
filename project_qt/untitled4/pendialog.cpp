#include "pendialog.h"
#include <QtGui>

penDialog::penDialog(QWidget *parent) :
    QDialog(parent)
{
    setFixedSize(200,200);
    initWindow();
    initConnect();
}
void penDialog::initWindow()
{
    QPixmap pix(16,16);
    QPainter painter(&pix);
    QGridLayout* gridLayout = new QGridLayout(this);
    sizeLabel = new QLabel(tr("大小"));
    sizeBox   = new QComboBox();
    for(unsigned i = 1;i<9;i++)
    {
        sizeBox->addItem(tr("%1").arg(i),i);
    }
    gridLayout->addWidget(sizeLabel,1,1,1,1);
    gridLayout->addWidget(sizeBox,1,2,1,3);

    styleLabel = new QLabel(tr("样式"));
    styleBox = new QComboBox();
/*
    styleBox->addItem(tr("  Solid"),Qt::SolidLine);
    styleBox->addItem(tr("  Dash"),Qt::DashLine);
    styleBox->addItem(tr("  Dot"),Qt::DotLine);
    styleBox->addItem(tr("  Dash Dot"),Qt::DashDotLine);
    styleBox->addItem(tr("  Dash Dot Dot"),Qt::DashDotDotLine);
    styleBox->addItem(tr("  None"),Qt::NoPen);


    gridLayout->addWidget(styleLabel,2,1,1,1);
    gridLayout->addWidget(styleBox,2,2,1,3);

    //设置颜色
    colorLabel = new QLabel(tr("颜色"));
    colorBox   = new QComboBox();
    painter.fillRect(0,0,16,16,Qt::black);
    colorBox->addItem(QIcon(pix),tr("   black"),Qt::black);
    painter.fillRect(0,0,16,16,Qt::red);
    colorBox->addItem(QIcon(pix),tr("   red"),Qt::red);
    painter.fillRect(0,0,16,16,Qt::green);
    colorBox->addItem(QIcon(pix),tr("   green"),Qt::green);
    painter.fillRect(0,0,16,16,Qt::blue);
    colorBox->addItem(QIcon(pix),tr("   blue"),Qt::blue);
    painter.fillRect(0,0,16,16,Qt::yellow);
    colorBox->addItem(QIcon(pix),tr("   yellow"),Qt::yellow);
    gridLayout->addWidget(colorLabel,3,1,1,1);
    gridLayout->addWidget(colorBox,3,2,1,3);
*/
    cancleBtn = new QPushButton(tr("取消"));
    okBtn = new QPushButton(tr("确定"));
    gridLayout->addWidget(cancleBtn,4,1,1,2);
    gridLayout->addWidget(okBtn,4,3,1,2);
    this->setLayout(gridLayout);

}
void penDialog::initConnect()
{
    connect(okBtn,SIGNAL(clicked()),this,SIGNAL(accepted()));
    connect(okBtn,SIGNAL(clicked()),this,SLOT(close()));
    connect(cancleBtn,SIGNAL(clicked()),this,SLOT(close()));
}
