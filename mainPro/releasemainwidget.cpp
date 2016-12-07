#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    createConnect();
    showPage1();
}

MainWidget::~MainWidget()
{
    delete ui;
}

 void MainWidget::createConnect()
{
   connect(ui->minBtn,SIGNAL(clicked()),this,SLOT(hide()));
   connect(ui->closeBtn,SIGNAL(clicked()),this,SLOT(close()));

       //page1

   connect(ui->page1_select_Btn,SIGNAL(clicked()),this,SLOT(selectFile()));
   connect(ui->page1_nextStep_BTn,SIGNAL(clicked()),this,SLOT(showPage2()));
   connect(ui->page1_cacle_btn,SIGNAL(clicked()),this,SLOT());

    //page2
     connect(ui->page2_selected_Btn,SIGNAL(clicked()),this,SLOT(saveDirPath()));
     connect(ui->page2_nextStep_Btn,SIGNAL(clicked()),this,SLOT(showPage3()));
     connect(ui->page2_cacle_Btn,SIGNAL(clicked()),this,SLOT());

    //page3
     connect(ui->page3_sure_Btn,SIGNAL(clicked()),this,SLOT(close() ));

}

 void MainWidget::showPage1()
 {
     ui->stackedWidget->setCurrentWidget(ui->page);
 }

 //选择文件
 void MainWidget::selectFile()
 {
     QStringList  fileNames= QFileDialog::getOpenFileNames(
                             this,
                             "Select one or more files to open",
                             ".");
     qDebug()<<fileNames;
     QString _lineEdditTet;
     foreach (QString _var, fileNames)
     {
       _lineEdditTet+=_var;
       _lineEdditTet+=";";
     }
     ui->page1_lineEdit->setText(_lineEdditTet);
 }


  void MainWidget::showPage2()
  {
      if(ui->page1_lineEdit->text().isEmpty() )
      {
         QMessageBox::information(this,"错误提示：","请检查是否为空","确定");
          return ;
      }
        ui->stackedWidget->setCurrentWidget(ui->page_2);
  }


   void MainWidget::saveDirPath()
   {
       ui->page2_lineEdit->clear();
       QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                       ".",
                                                       QFileDialog::ShowDirsOnly );

       ui->page2_lineEdit->setText(dir);
        m_saveDir=dir;
   }

#include <QFileInfo>
   //page_2_next_Btn 破碎
   void MainWidget::copyFile()
   {
       QString _fileListStr= ui->page1_lineEdit->text();
       QStringList _fileList=_fileListStr.split(";");

       int i=0;

      while(i < _fileList.count() )
      {
          if(" "==_fileList[i])
          {
             ++i;
          }
        QFileInfo _fileInfo(_fileList[i]);
        QString _newFile=m_saveDir+_fileInfo.fileName();
        qDebug()<<"new FileName:"<<_newFile;
         bool _isOk=QFile::copy(_fileList[i],_newFile);

         ++i;
      }


   }




   void MainWidget::showPage3()
 {
       if(ui->page2_lineEdit->text().isEmpty())
       {
           QMessageBox::information(this,"错误提示：","请检查存储地址是否为空","确定");
            return ;
       }


   copyFile();

  ui->stackedWidget->setCurrentWidget(ui->page_3);
 }
