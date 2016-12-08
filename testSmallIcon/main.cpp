#include "widget.h"
#include <QApplication>

#include<QFileIconProvider>
#include <QString>

//1、获取文件夹图标
/*
 QFileIconProvider icon_provider;

 QIcon icon = icon_provider.icon(QFileIconProvider::Folder);



//2、获取指定文件图标

QFileInfo file_info(name);
QFileIconProvider icon_provider;
QIcon icon = icon_provider.icon(file_info);



//二、Windows编程中获取系统图标、类型：

QIcon getFileIcon(QString file_name)
{
 QIcon file_icon = QIcon(":/icon/file");
 if(!file_name.isEmpty())
 {
  //获取后缀
  std::string str = "file";
  int index = file_name.lastIndexOf(".");
  if(index >= 0)
  {
   QString suffix = file_name.mid(index);

   //将QString转化为std::string
   str = suffix.toUtf8().constData(); //std::string((const char *)path.toLocal8Bit())   path.toLatin1().data();
  }

  LPCSTR name = str.c_str();


  SHFILEINFOA info;
  if(SHGetFileInfoA(name,
   FILE_ATTRIBUTE_NORMAL,
   &info,
   sizeof(info),
   SHGFI_SYSICONINDEX | SHGFI_ICON | SHGFI_USEFILEATTRIBUTES))
  {
   HICON icon = info.hIcon;
   file_icon = QIcon(QPixmap::fromWinHICON(icon));
  }
 }

 return file_icon;
}



QString getFileType(QString file_name)
{
 QString file_type = QString("file");
 if(!file_name.isEmpty())
 {
  //获取后缀
  std::string str = "file";
  int index = file_name.lastIndexOf(".");
  if(index >= 0)
  {
   QString suffix = file_name.mid(index);

   //将QString转化为std::string
   str = suffix.toUtf8().constData();
  }

  LPCSTR name = str.c_str();


  SHFILEINFOA info;
  if(SHGetFileInfoA(name,
   FILE_ATTRIBUTE_NORMAL,
   &info,
   sizeof(info),
   SHGFI_TYPENAME | SHGFI_USEFILEATTRIBUTES))
  {
   std::string type = info.szTypeName;
   file_type = type.c_str();
  }
 }

 return file_type;
}



QIcon Setting::getFolderIcon()
{
 QIcon folder_icon = QIcon(":/icon/folder");

 //将QString转化为std::string
 std::string str = "folder";
 LPCSTR name = str.c_str();


 SHFILEINFOA info;
 if(SHGetFileInfoA(name,
  FILE_ATTRIBUTE_DIRECTORY,
  &info,
  sizeof(info),
  SHGFI_SYSICONINDEX | SHGFI_ICON | SHGFI_USEFILEATTRIBUTES))
 {
  HICON h_icon = info.hIcon;

  folder_icon = QIcon(QPixmap::fromWinHICON(h_icon));
 }

 return folder_icon;
}



QString Setting::getFolderType()
{
 QString folder_type = QString("folder");
 std::string str = "folder";
 LPCSTR name = str.c_str();


 SHFILEINFOA info;
 if(SHGetFileInfoA(name,
  FILE_ATTRIBUTE_DIRECTORY,
  &info,
  sizeof(info),
  SHGFI_TYPENAME | SHGFI_USEFILEATTRIBUTES))
 {
  std::string type = info.szTypeName;
  folder_type = type.c_str();
 }

 return folder_type;
}
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    QFile _file("./a.txt");

    return a.exec();
}
