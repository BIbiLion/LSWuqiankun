#include "mainwindow.h"
#include <QApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QSettings>
#include <QTemporaryFile>
#include <QTemporaryDir>
#include <QFile>
#include <QDataStream>
#include <QDataStream>


bool WritePrivateProfileString(QString strSectionName, QString strKeyName, QString strValue, QString strFileName)
{
    bool ret = false;
    //section是null则直接返回false
    if(strSectionName == NULL)
    {
        return ret;
    }

    bool flagFindSection = false;//是否找到了section
    int pos = 0;
    QString strSection("[" + strSectionName + "]");
    QString strKey(strKeyName + "=");

    //文件不存在，则创建，且直接写入
    if(!QFile::exists(strFileName))
    {
        QFile createFile(strFileName);
        if(!createFile.open(QFile::WriteOnly | QIODevice::Text))
        {
            return ret;
        }
        //如果key和value不是null，才写内容
        if(strKeyName != NULL && strValue != NULL)
        {
            QTextStream createStream(&createFile);
            createStream<<strSection<<"/n";
            createStream<<strKey<<strValue<<"/n";
            createStream.flush();

            ret = true;
        }
        createFile.close();
        return ret;
    }

    QFile readFile(strFileName);

    if (!readFile.open(QFile::ReadOnly | QIODevice::Text))
    {
        ret = false;
        return ret;
    }

    QFile writeFile(strFileName);

    //读入流和写入流
    //写入流文件在最后才WriteOnly打开
    QTextStream readStream(&readFile);
    QTextStream writeStream(&writeFile);

    //查找每一行是否包含section
    while (!readStream.atEnd())
    {
        QString line(readStream.readLine());

        if (line.indexOf(strSection) != 0) //该行不包含section，直接写入流
        {
            writeStream<<line<<"/n";
        }
        else
        {
            flagFindSection = true; //查到section
            ret = true;

            //key是null，则跳过该section,写入其余section
            if (strKeyName == NULL)
            {
                do //跳过该section
                {
                    line = QString(readStream.readLine());
                } while (line.indexOf("[") != 0 && !readStream.atEnd());

                if(readStream.atEnd())
                {
                    break;
                }
                else //写入其余section
                {
                    writeStream<<line<<"/n";
                    while(!readStream.atEnd())
                    {
                        writeStream<<readStream.readLine()<<"/n";
                    }
                    break;
                }
            }

            writeStream<<line<<"/n";//section写入流
            line = QString(readStream.readLine());
            while(line.indexOf(strKey) != 0 && line.indexOf("[") != 0 && !readStream.atEnd())
            {
                writeStream<<line<<"/n";
                line = QString(readStream.readLine());
            }
            if(readStream.atEnd())//文件末尾，若value!=null则直接加上key
            {
                //直接加上
                if(strValue != NULL)
                {
                    writeStream<<strKey<<strValue<<"/n";
                }
            }
            else if(line.indexOf("[") == 0)//查到下一个section，若value!=null则在下一个section前直接加上key
            {
                if(strValue != NULL)
                {
                    writeStream<<strKey<<strValue<<"/n";
                }
                writeStream<<line<<"/n";
                while(!readStream.atEnd()) //剩余行写入流中
                {
                    writeStream<<readStream.readLine()<<"/n";
                }
                break;
            }
            else if(line.indexOf(strKeyName) == 0)//查到key，若value!=null则修改value
            {
                if(strValue != NULL)
                {
                    line = line.mid(0, line.indexOf("=") + 1) + strValue;
                    writeStream<<line<<"/n";
                }
                while(!readStream.atEnd()) //剩余行写入流中
                {
                    writeStream<<readStream.readLine()<<"/n";
                }
                break;
            }
        }
    }
    if(!flagFindSection)//若未查到该section，且key和value！=null，写入section和key=value
    {
        if(strKeyName != NULL && strValue != NULL)
        {
            writeStream<<strSection<<"/n";
            writeStream<<strKey<<strValue<<"/n";
        }
    }
    readFile.close();

    //写打开文件
    if (!writeFile.open(QFile::WriteOnly | QIODevice::Text))
    {
        ret = false;
        return ret;
    }
    writeStream.flush();//写入流到文件

    writeFile.close();

    return ret;
}


int StrCopy(QString source, char *dest, int size)
{
    QByteArray temp = source.toLatin1();//.toascii()
    //拷贝字符串；
    //size合适，返回不加'/0'的字符串长度
    if(source.length() <= size - 1)
    {
        strcpy(dest, temp.data());
        return source.length();
    }
    //拷贝字符串；
    //size过小，返回size-1
    else
    {
        strncpy(dest, temp.data(), size-1);
        dest[size - 1] = '/0';
        return size-1;
    }
}

int GetPrivateProfileString(QString strSectionName, QString strKeyName, QString strDefault, char * pReturnedValue, int size, QString strFileName)
{
    //设置默认返回字符串
    if(strDefault == NULL)
    {
        strDefault = "";
    }
    //文件不存在，返回默认字符串及其长度
    if (!QFile::exists(strFileName) || strSectionName == NULL || strKeyName == NULL)
    {
        return StrCopy(strDefault, pReturnedValue, size);
    }

    QString strSection("[" + strSectionName + "]");
    QString strKey(strKeyName + "=");

    QFile readFile(strFileName);

    //打开失败，返回默认字符串及其长度
    if (!readFile.open(QFile::ReadOnly | QIODevice::Text))
    {
        return StrCopy(strDefault, pReturnedValue, size);
    }

    QTextStream readStream(&readFile);

    while (!readStream.atEnd())
    {
        QString line(readStream.readLine());
        if(line.indexOf(strSection) == 0) //找到Section
        {
            line = readStream.readLine();
            while(line.indexOf(strKey) != 0 && line.indexOf("[") != 0 && !readStream.atEnd())
            {
                line = readStream.readLine();
            }
            if (line.indexOf(strKey) == 0) //找到Key
            {
                QString source(line.mid(strKey.length()));
                readFile.close();
                return StrCopy(source, pReturnedValue, size);
            }
        }
    }
    readFile.close();
    //未找到，返回默认值及其长度
    return StrCopy(strDefault, pReturnedValue, size);
}

#include <QSettings>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();

    QList<QSerialPortInfo> _listSerialPort= QSerialPortInfo::availablePorts();
    foreach (QSerialPortInfo _protInfo, _listSerialPort)
    {
        qDebug()<<_protInfo.portName();
    }
    QTemporaryDir _tmpDir;
    QTemporaryFile _tmpFile;
    qDebug()<<_tmpDir.path()<<_tmpFile.fileName();

    //文件的读写

    char buffer[100];
    buffer[0]=0xaa;
    buffer[1]='\0';
    qDebug()<<strlen(buffer);
    /*
    //保存文件
    QString _appPath=QCoreApplication::applicationDirPath();
    QString _str("/fileData.ini");
    _appPath+=_str;

    QFile _file(_appPath);
    if(!_file.open(QFile::WriteOnly))
    {
        qDebug()<<"cannot open";
    }
    QDataStream out(&_file);

    out << QString("51所");   // serialize a string

    _file.close();

    //读文件
    QFile file(_appPath);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);    // read the data serialized from the file
    QString str;
    in >> str ;           // extract "the answer is" and 42
    qDebug()<<str;
    file.close();
    */

    QString _appPath=QCoreApplication::applicationDirPath();

    //    QString _path2(_appPath+"/hello.ini");
    //    QSettings setting2(_path2,QSettings::IniFormat);
    //    setting2.beginGroup("test");
    //    setting2.setValue("a","100");
    //    setting2.setValue("b", "full");
    //    setting2.endGroup();


    QString _path(_appPath+"/myapp.ini");
    qDebug()<<_path;

    QString _str;
    _str=QString::fromUtf8("你好");
    QSettings settings(_path,QSettings::IniFormat);
    settings.setIniCodec("UTF8");
    settings.beginGroup(_str);
    settings.setValue("啊","100");
    settings.setValue("d", "full");
    settings.endGroup();

    settings.beginGroup(_str);

    qDebug()<<  settings.value("啊").toString();;


    return a.exec();
}
