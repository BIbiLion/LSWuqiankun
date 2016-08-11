#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString _str=QApplication::applicationDirPath();
    QString fileNametmp = _str+"/112.xls"; //文件名可从此处修改


    //写文件
    createExcel(fileNametmp);
    //    appendSheet(QString("page1"),1);
    //    appendSheet("page2",2);
    //    appendSheet("page3",3);
    setCellValue(3, 3,"34343");
    setCellValue(3, 6,"55555");
    saveExcel(fileNametmp);
    freeExcel();



    //读文件
    readExcel(fileNametmp);

}
#include <QDebug>
//readExcel
void MainWindow::readExcel(QString fileName)
{
    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);
   excel.setProperty("DisplayAlerts", false);//不显示任何警告信息。
    QAxObject *work_books = excel.querySubObject("WorkBooks");
    work_books->dynamicCall("Open (const QString&)", fileName);
//    QVariant title_value = excel.property("Caption");  //获取标题
//    qDebug()<<QString("excel title : ")<<title_value;
    QAxObject *work_book = excel.querySubObject("ActiveWorkBook");
    QAxObject *work_sheets = work_book->querySubObject("Sheets");  //Sheets也可换用WorkSheets

    int sheet_count = work_sheets->property("Count").toInt();  //获取工作表数目
    qDebug()<<QString("sheet count : ")<<sheet_count;
    for(int i=1; i<=sheet_count; i++)
    {
        QAxObject *work_sheet = work_book->querySubObject("Sheets(int)", i);  //Sheets(int)也可换用Worksheets(int)
        QString work_sheet_name = work_sheet->property("Name").toString();  //获取工作表名称
        QString message = QString("sheet ")+QString::number(i, 10)+ QString(" name");
        qDebug()<<message<<work_sheet_name;
    }
    if(sheet_count > 0)
    {
        QAxObject *work_sheet = work_book->querySubObject("Sheets(int)", 1);
        QAxObject *used_range = work_sheet->querySubObject("UsedRange");
        QAxObject *rows = used_range->querySubObject("Rows");
        QAxObject *columns = used_range->querySubObject("Columns");
        int row_start = used_range->property("Row").toInt();  //获取起始行
        int column_start = used_range->property("Column").toInt();  //获取起始列
        int row_count = rows->property("Count").toInt();  //获取行数
        int column_count = columns->property("Count").toInt();  //获取列数
        for(int i=row_start ; i<=(row_start+row_count);++i)
        {
            for(int j=column_start; j<=(column_start+column_count);++j)
            {
                QAxObject *cell = work_sheet->querySubObject("Cells(int,int)", i, j);
                QVariant cell_value = cell->property("Value");  //获取单元格内容
                QString message = QString("row-")+QString::number(i, 10)+QString("-column-")+QString::number(j, 10)+QString(":");
                qDebug()<<message<<cell_value;
            }
        }
    }

    excel.dynamicCall("Quit()");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpEXCEL()
{
}

#include <QFile>
void MainWindow::createExcel(QString fileName)
{


    pApplication = new QAxObject("Excel.Application");

    if(pApplication == NULL){

        qWarning("pApplication\n");return;

    }

    pApplication->dynamicCall("SetVisible(bool)", false);//false不显示窗体

    pApplication->setProperty("DisplayAlerts", false);//不显示任何警告信息。

    pWorkBooks = pApplication->querySubObject("Workbooks");

    QFile file(fileName);

    if (file.exists())

    {

        pWorkBook = pWorkBooks->querySubObject("Open(const QString &)", fileName);

    }

    else

    {

        pWorkBooks->dynamicCall("Add");

        pWorkBook = pApplication->querySubObject("ActiveWorkBook");

    }

    pSheets = pWorkBook->querySubObject("Sheets");

    pSheet = pSheets->querySubObject("Item(int)", 1);
}

void MainWindow::appendSheet( QString sheetName,int cnt)
{
    QAxObject *pLastSheet = pSheets->querySubObject("Item(int)", cnt);

    pSheets->querySubObject("Add(QVariant)", pLastSheet->asVariant());

    pSheet = pSheets->querySubObject("Item(int)", cnt);

    pLastSheet->dynamicCall("Move(QVariant)", pSheet->asVariant());

    pSheet->setProperty("Name", sheetName);
}


void MainWindow::setCellValue(int row, int column, const QString &value)
{

    QAxObject *pRange = pSheet->querySubObject("Cells(int,int)", row, column);

    pRange->dynamicCall("Value", value);
}
void MainWindow::saveExcel(const QString &fileName)
{

    pWorkBook->dynamicCall("SaveAs(const QString &)",

                           QDir::toNativeSeparators(fileName));
}
void MainWindow::freeExcel()
{

    if (pApplication != NULL)

    {

        pApplication->dynamicCall("Quit()");

        delete pApplication;

        pApplication = NULL;

    }
}

/*
 * //test code
OleInitialize(0);

QString fileNametmp = "d:/112.xls"; //文件名可从此处修改

    newExcel(fileNametmp);

   // appendSheet("page1");

    setCellValue(3, 3,"34343");

    setCellValue(3, 6,"55555");

    saveExcel(fileNametmp);

    freeExcel();

    return;
    */
