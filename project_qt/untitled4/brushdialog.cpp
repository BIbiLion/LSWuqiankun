#include "brushdialog.h"
#include <QPainter>
brushDialog::brushDialog(QWidget *parent) :
    QDialog(parent)
{
    QGridLayout* gridLayout = new QGridLayout();
    colorLabel = new QLabel(tr("填充颜色"));
    colorBox = new QComboBox();
    QPixmap pix(16,16);
    QPainter painter(&pix);
    /*
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
    painter.fillRect(0,0,16,16,Qt::white);
    colorBox->addItem(QIcon(pix),tr("   white"),Qt::white);
    gridLayout->addWidget(colorLabel,1,1,1,1);
    gridLayout->addWidget(colorBox,1,2,1,3);

    styleLabel = new QLabel(tr("填充图案"));
    styleBox = new QComboBox();
    styleBox->addItem(tr("None"),Qt::NoBrush);
    styleBox->addItem(tr("SolidPattern"),Qt::SolidPattern);
    styleBox->addItem(tr("Dense1Pattern"),Qt::Dense1Pattern);
    styleBox->addItem(tr("Dense2Pattern"),Qt::Dense2Pattern);
    styleBox->addItem(tr("Dense3Pattern"),Qt::Dense3Pattern);
    styleBox->addItem(tr("Dense4Pattern"),Qt::Dense4Pattern);
    styleBox->addItem(tr("Dense5Pattern"),Qt::Dense5Pattern);
    styleBox->addItem(tr("Dense6Pattern"),Qt::Dense6Pattern);
    styleBox->addItem(tr("Dense7Pattern"),Qt::Dense7Pattern);
    styleBox->addItem(tr("HorPattern"),Qt::HorPattern);
    styleBox->addItem(tr("VerPattern"),Qt::VerPattern);
    styleBox->addItem(tr("CrossPattern"),Qt::CrossPattern);
    styleBox->addItem(tr("BDiagPattern"),Qt::BDiagPattern);
    styleBox->addItem(tr("FDiagPattern"),Qt::FDiagPattern);
    styleBox->addItem(tr("DialCrossPattern"),Qt::DiagCrossPattern);

    gridLayout->addWidget(styleLabel,2,1,1,1);
    gridLayout->addWidget(styleBox,2,2,1,3);
*/
    cancleBtn = new QPushButton(tr("取消"));
    okBtn = new QPushButton(tr("确定"));
    gridLayout->addWidget(cancleBtn,3,1,1,2);
    gridLayout->addWidget(okBtn,3,3,1,2);
    this->setLayout(gridLayout);

    connect(okBtn,SIGNAL(clicked()),this,SIGNAL(accepted()));
    connect(okBtn,SIGNAL(clicked()),this,SLOT(close()));
    connect(cancleBtn,SIGNAL(clicked()),this,SLOT(close()));
}
