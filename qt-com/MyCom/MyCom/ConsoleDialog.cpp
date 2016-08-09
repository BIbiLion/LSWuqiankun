

#include "ConsoleDialog.h"
//#include "ui_console.h"


#include "ui_ConsoleDialog.h"  //必不可少

//static const char blankString[] = QT_TRANSLATE_NOOP("ConsoleDialog", "N/A");

ConsoleDialog::ConsoleDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConsoleDialog)
{
    ui->setupUi(this);
}

ConsoleDialog::~ConsoleDialog()
{
    delete ui;
}


//关闭
void ConsoleDialog::on_ClosepushButton_clicked()
{
    this->close();

}
