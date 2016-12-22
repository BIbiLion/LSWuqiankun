#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "DisplayWidget.h"
#include <QFileDialog>
#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Image Painter"));

    m_displayWidget = new DisplayWidget(this);
    ui->scrollArea->setWidget(m_displayWidget);
    ui->pushButton_3->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString nullString;
    QString fileName = QFileDialog::getOpenFileName(this,
                                               tr("Save"),
                                               "/home",
                                               "Images (*.png *.jpg)",
                                                NULL,
                                                QFileDialog::DontUseNativeDialog);

    qDebug() << fileName;

    if (fileName.isEmpty())
    {
        return;
    }

    m_displayWidget->setPicture(fileName);
}

void MainWindow::on_pushButton_clicked()
{
    QString imageFile = QFileDialog::getSaveFileName(this,
                                               tr("Save"),
                                               tr("/home"),
                                               "Images (*.png *.jpg)",
                                               Q_NULLPTR,
                                               QFileDialog::DontUseNativeDialog);

    qDebug() << imageFile;

    if (imageFile.isEmpty())
    {
        return;
    }

    m_displayWidget->saveImage(imageFile);
}

void MainWindow::keyPressEvent(QKeyEvent* pevent)
{
    if (pevent->matches(QKeySequence::Undo))
    {
        m_displayWidget->undo();
    }


}

void MainWindow::on_redBtn_clicked()
{
    m_displayWidget->setPen("#FF0000");
}

void MainWindow::on_greenBtn_clicked()
{
    m_displayWidget->setPen("#00FF00");
}

void MainWindow::on_blueBtn_clicked()
{
    m_displayWidget->setPen("#0000FF");
}

void MainWindow::on_pushButton_3_clicked()
{
    //load();
}
