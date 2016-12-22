#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PinyinResource.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->cmbSeparator->clear();
    ui->cmbSeparator->addItem("无", "");
    ui->cmbSeparator->addItem("空格", " ");
    ui->cmbSeparator->addItem("逗号", ",");
    ui->cmbSeparator->addItem("分号", ";");
    ui->cmbSeparator->addItem("TAB", "\t");
    ui->cmbSeparator->addItem("下划线", "_");
    ui->cmbSeparator->addItem("#", "#");
    ui->cmbSeparator->addItem("-", "-");
    ui->cmbSeparator->addItem("+", "+");
    ui->cmbSeparator->addItem("|", "|");
    ui->cmbSeparator->addItem("/", "/");
    ui->cmbSeparator->setCurrentIndex(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//转换到繁体字
void MainWindow::on_btnToFan_clicked()
{
    ui->txtOut->setPlainText(ChineseHelper::convertToTraditionalChinese(ui->txtIn->toPlainText()));
}


//转换到简体字
void MainWindow::on_btnToJian_clicked()
{
    ui->txtOut->setPlainText(ChineseHelper::convertToSimplifiedChinese(ui->txtIn->toPlainText()));
}


//转换到拼音
void MainWindow::on_btnToPinYin_clicked()
{
    QStringList txts = ui->txtIn->toPlainText().split("\n");
    QStringList strs;
    PinyinFormat::Format fmt = (PinyinFormat::Format)ui->cmbTone->currentIndex();
    QString strSpr = ui->cmbSeparator->currentData().toString();
    int layIdx = ui->cmbLayout->currentIndex();
    QString strp = "<p style='margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;'>";
    foreach (QString tem, txts) {
        tem = tem.trimmed();
        QString str = PinyinHelper::convertToPinyinString(tem, strSpr, fmt);
        switch (layIdx) {
            case 0: strs << QString(strp + "<span style='color:#007f00;'>%1</span></p>").arg(str); break;
            case 1: strs << QString(strp + "<span style='color:#007f00;'>%1</span></p>").arg(str) << QString(strp + "<span style='color:#00007f;'>%1</span></p>").arg(tem); break;
            case 2: strs << QString(strp + "<span style='color:#0000ff;'>%1</span>").arg(tem + " ") + QString("<span style='color:#007f00;'>%1</span></p>").arg(str); break;
            case 3: strs << QString(strp + "<span style='color:#007f00;'>%1</span>").arg(str + " ") + QString("<span style='color:#0000ff;'>%1</span></p>").arg(tem); break;
        }
    }
    ui->txtOut->setHtml(strs.join(""));
}
