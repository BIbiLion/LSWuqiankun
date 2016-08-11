#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QAxObject"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void createExcel(QString fileName);
    void appendSheet( QString sheetName,int cnt);
    void setCellValue(int row, int column, const QString &value);
    void saveExcel(const QString &fileName);
    void freeExcel();


    void readExcel(QString fileName);
    void setUpEXCEL();
private:
    Ui::MainWindow *ui;
     QAxObject* pApplication;

     QAxObject* pWorkBooks;
     QAxObject* pWorkBook;

     QAxObject* pSheets;
     QAxObject* pSheet;

     QString fileName;
};

#endif // MAINWINDOW_H
