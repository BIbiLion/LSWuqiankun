#include <QApplication>
#include <QTextCodec>
#include <QMetaType>
#include "LineEdit.h"

int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    CLineEdit lineedit;
    lineedit.show();
    return app.exec();
}

