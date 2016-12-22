#ifndef GLOBAL_H
#define GLOBAL_H
#include <QString>
#include <QSettings>
#include <QProcess>
#include <QMessageBox>
#include <QFile>
#include <QObject>
#include <QApplication>
#include <QTextStream>
#include <QFileInfo>
#include <Phonon/AudioOutput>
#include <QDir>
#include <Phonon/MediaObject>
#include <QFileIconProvider>
#include <QListWidget>
#include <QDesktopWidget>
#include <QTextEdit>
#include <QVBoxLayout>

const QString gAppName=QString("Banana");
const QString gOrgName=QString("FruitSoft.com");

namespace Util {

    /***************************************************/
    /********| manipulate files or folders |************/
    /***************************************************/
    class FSO : public QObject
    {
    public:
        FSO();
       ~FSO();
       static bool FileExists(const QString& strFile)
       {
           QFile tempFile(strFile);
           if(tempFile.exists())
           {
               return true;
           }

           return false;
       }

       static bool FolderExists(const QString& strFolder)
       {
           QDir tempFolder(strFolder);
           if(tempFolder.exists())
           {
               return true;
           }
           return false;
       }



       static bool RemoveFile(const QString& strFile)
       {
           return QFile::remove(strFile);
       }

       static QString BaseName(const QString& str)
       {
           QString strFile(str);
           strFile.replace('\\','/');
           int slashPos=strFile.lastIndexOf('/');
           int dotPos=strFile.lastIndexOf('.');
           int dis=dotPos-slashPos;
           QString strBaseName=strFile.mid(slashPos+1,dis-1);
           return strBaseName;

       }

       static QString ShortName(const QString& str)
       {
           QString strFile(str);
           strFile.replace('\\','/');
           int slashPos=strFile.lastIndexOf('/');
           int tail=str.length()-1;
           return strFile.mid(slashPos+1,tail);
       }

       static bool RenameFile(const QString& srcName,const QString& desName)
       {
           return QFile::rename(srcName,desName);
       }

       static QString BasePath(const QString& strFullPath)
       {
           QFileInfo fInfo(strFullPath);
           return fInfo.path();
       }

       static QString GetExtension(const QString& strFile)
       {
           QFileInfo fInfo(strFile);
           return fInfo.suffix();
       }

       static QString FolderName(const QString& strFullPath)
       {
           QString strPath(strFullPath);
           strPath.replace('\\','/');
           int slashPos=strPath.lastIndexOf('/');
           return strPath.mid(slashPos+1);

       }


       static bool CopyTo(const QString& srcFile,const QString& desFile)
       {
           if(FileExists(desFile))
           {
               int ret=QMessageBox::information(NULL,tr("Warning"),tr("%1 is already there!\nProceed or Not ?").arg(desFile),QMessageBox::Yes|QMessageBox::No);
               if(ret!=QMessageBox::Yes)
               {
                   return false;
               }
           }
           return QFile::copy(srcFile,desFile);
       }

       static bool CopyFile2Folder(const QString& strFile,const QString& strFolder)
       {
           QString strBaseName=BaseName(strFile);
           QString strDesFile;
           strDesFile=tr("%1%2.%3").arg(strFolder).arg(strBaseName).arg(GetExtension(strFile));
           return CopyTo(strFile,strDesFile);

       }

       static bool MoveFile2Folder(const QString& strFile,const QString& strFolder)
       {
           CopyFile2Folder(strFile,strFolder);
           return RemoveFile(strFile);
       }

       static bool IsFile(const QString& str)
       {
           QFileInfo fInfo(str);
           return fInfo.isFile();
       }

       static bool IsFolder(const QString& str)
       {
           QFileInfo fInfo(str);
           return fInfo.isDir();
       }

       static QString TailName(const QString& str)
       {
           QString newStr(str);
           newStr.replace('\\','/');
           int lastPos=newStr.lastIndexOf('/');
           return newStr.right(newStr.length()-lastPos-1);

       }

       static bool Append2File(const QString& strFile,const QString& strContent)
       {
           QFile inFile(strFile);
           if(!inFile.open(QIODevice::Append|QIODevice::Text))
           {
               QMessageBox::warning(NULL,"Error",tr("%1").arg(inFile.errorString()));
               return false;
           }
           QTextStream inStream(&inFile);
           inStream << strContent;
           inFile.close();
           return true;
       }
       static bool Write2File(const QString& strFile,const QString& strContent)
       {
           if(!Util::FSO::FileExists(strFile))
           {
               Util::FSO::CreateFile(strFile);

           }

           QFile inFile(strFile);
           if(!inFile.open(QIODevice::WriteOnly|QIODevice::Text))
           {
               QMessageBox::warning(NULL,"Error",tr("%1").arg(inFile.errorString()));
               return false;
           }
           QTextStream inStream(&inFile);
           inStream << strContent;
           inFile.close();
       }

       static bool CreateFolder(const QString& strFolder)
       {
           QDir objDir;
           return objDir.mkdir(strFolder);
       }


       static bool CreateFile(const QString& strFile)
       {
           QFile objFile(strFile);
           if(!objFile.open(QIODevice::WriteOnly))
           {
               return false;
           }
           objFile.close();
           return true;

       }

       static QString FileContent(const QString& strFile)
       {
           QFile objFile(strFile);
           if(!objFile.open(QIODevice::ReadOnly|QIODevice::Text))
           {
               return QString();
           }
           QString fileContent=objFile.readAll();
           objFile.close();
           return fileContent;
       }
    };

    /***************************************************/
    /******| QListWidget related  functions |***********/
    /***************************************************/
    class ListWidget : public QObject
    {

    public:
        ListWidget();
       ~ListWidget();


       static bool HasTheData(QListWidget* root,int role,const QString& strData)
       {
           bool has=false;
           for(int i=0;i<root->count();i++)
           {
               QListWidgetItem* theItem=root->item(i);
               QString tmpData=theItem->data(role).toString();
               if(tmpData==strData)
               {
                has=true;
                break;
               }
           }
           return has;
       }

       static bool HasTheText(QListWidget* root,const QString& strText)
       {
           bool has=false;
           for(int i=0;i<root->count();i++)
           {
               QListWidgetItem* theItem=root->item(i);
               QString tmpData=theItem->text();
               if(tmpData==strText)
               {
                has=true;
                break;
               }
           }
           return has;
       }

       static int CheckedItemCount(QListWidget* root)
       {
           int count=0;
           for(int i=0;i<root->count();i++)
           {
               QListWidgetItem* item=root->item(i);
               if(item->checkState()==Qt::Checked)
               {
                    count++;
               }
           }
           return count;
       }

       static int UncheckedItemCount(QListWidget* root)
       {
           int checkedCount=CheckedItemCount(root);
           int totalCount=root->count();
           return totalCount-checkedCount;
       }

    };

    /***************************************************/
    /**************| manipulate shell   |***************/
    /***************************************************/

    class Shell : public QObject
    {
    public:
        Shell();
       ~Shell();

        static bool Run(const QString& program)
        {
            QProcess pro;
            return pro.startDetached(program);
        }

        // Alert
        static void Alert()
        {
            qApp->beep();
        }

#ifdef Q_WS_WIN32
        static void LocateFile(const QString& objFile){

            QStringList args;
            QString strFile=objFile;
            strFile.replace("/","\\");
            args<<"/select,"<<strFile;
            QProcess pro;
            pro.startDetached("explorer.exe",args);

        }
#endif

        static void AutoRun()
        {
            QString strFile("autorun.bat");
            QFile outFile(strFile);
            QTextStream outStream(&outFile);
            QFileInfo appInfo(qApp->applicationFilePath());
            QString appName=appInfo.baseName();

            QString appPath=qApp->applicationFilePath();
            if(!outFile.open(QIODevice::WriteOnly))
            {
                QMessageBox::warning(NULL,tr("Error"),tr("Failed to create file:\"%1\"").arg(strFile));
                return ;
            }
            appPath.replace('/','\\');
            QString fileContent=tr("reg add hklm\\software\\microsoft\\windows\\currentversion\\run /v %1 /t REG_SZ /d %2 \n del autorun.bat ").arg(appName).arg(appPath);
            outStream << fileContent;
            outFile.close();

            QProcess pro;
            pro.start("cmd.exe",QStringList("/c autorun.bat"));
        }

        static QString GetCMDOutput(const QString& program ,const QStringList& args)
        {
            QProcess pro;
            QByteArray output;
            pro.start(program,args);
            QProcess::ExitStatus exitStatus=pro.exitStatus();

            if(exitStatus==QProcess::NormalExit)
            {
                output=pro.readAllStandardOutput();
            }else{
                output=pro.readAllStandardError();
            }


            QString strOutput(output);
            pro.waitForFinished(5000);

            return strOutput;
        }

        static int Exec(const QString& program,const QStringList& args)
        {
           return  QProcess::execute(program,args);
        }


    };

    /***************************************************/
    /**********| read or write setting info |***********/
    /***************************************************/
    class SettingMgr : public QObject
    {
    public:
        SettingMgr();
       ~SettingMgr();

       static QString ReadSetting(const QString &key){

           QSettings settings(gOrgName,gAppName);
           return settings.value(key).toString();
       }

       //writeSetting
       static void WriteSetting(const QString &key, const QString &value){

           QSettings settings(gOrgName,gAppName);
           settings.setValue(key,value);

       }

    };


    class Extra : public QObject
    {
    public:
        Extra();
       ~Extra();

    static QIcon LocalFileIcon(const QString& strFile)
    {
           QFileIconProvider fIconProvider;
           return fIconProvider.icon(QFileInfo(strFile));
    }

    static bool ApplyStyle(const QString& styleFile)
    {
        QFile inFile(styleFile);
        if(!inFile.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            QMessageBox::warning(NULL,tr("Error"),tr("Failed to load style file: %1!").arg(inFile.errorString()));
            return false;
        }
        qApp->setStyleSheet(inFile.readAll());
        inFile.close();
        return true;
    }

    static void MessageBox(const QString& tips)
    {
        QMessageBox::information(NULL,"Debug",tips);
    }

    static QString GetPWD()
    {
        QString pwd=qApp->applicationDirPath();
        return pwd;
    }

    static bool InstallStyle(QWidget* window,const QString& styleFile)
    {
        QString strStyleSheet=Util::FSO::FileContent(styleFile);
        if(strStyleSheet.isEmpty())
        {
            return false;
        }
        window->setStyleSheet(strStyleSheet);
        return true;
    }

    static bool Dump(const QString& strDebugInfo)
    {
        QDialog *dumpDialog=new QDialog();
        QTextEdit* dumpEdit=new QTextEdit(dumpDialog);
        dumpEdit->setText(strDebugInfo);
        QVBoxLayout* dumpLayout=new QVBoxLayout();
        dumpLayout->addWidget(dumpEdit);
        dumpDialog->setLayout(dumpLayout);
        dumpDialog->setModal(true);
        dumpDialog->show();
    }

    };


    class ML : public QObject
    {
    public:
        ML();
       ~ML();
       static void PlaySound(const QString& mediaFile)
       {
           Phonon::Path mediaPath;
           Phonon::MediaObject *mediaObject=new Phonon::MediaObject(NULL);
           Phonon::AudioOutput *audioOutput=new Phonon::AudioOutput(Phonon::MusicCategory, NULL);
           mediaPath=Phonon::createPath(mediaObject, audioOutput);
           Phonon::MediaSource mediaSource(mediaFile);
           mediaObject->setCurrentSource(mediaSource);
           mediaObject->play();

       }
   };


    class Math : public QObject
    {
    public:
        Math();
       ~Math();

       static bool IsLeapYear(const QString& strDate)
       {
           int year=strDate.left(4).toInt();
           if(((year % 4 ==0) && (year % 100 !=0 ))|| (year % 400 ==0)){
               return true;
           }else{
               return false;
           }
       }
   };

    class WndMgr : public QObject
    {
    public:
        WndMgr();
       ~WndMgr();
       static void CenterWindow(QWidget* target)
       {
           QDesktopWidget desktop;
           int screenX=desktop.availableGeometry().width();
           int screenY=desktop.availableGeometry().height();
           int wndX=target->width()/2;
           int wndY=target->height()/2;
           QPoint movePoint(screenX/2-wndX/2,screenY/2-wndY/2);
           target->move(movePoint);
       }

       static QSize DesktopSize()
       {
           QDesktopWidget desktop;
           return QSize(desktop.availableGeometry().width(),desktop.availableGeometry().height());
       }
    };

};
#endif // GLOBAL_H
