#include <QCoreApplication>

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
void connectMysql()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("10.0.0.131");//设置你远程服务器的IP

    db.setDatabaseName("mydb2");//数据库名
    db.setPort(3306);
    db.setUserName("Root");//数据库用户名和密码
    db.setPassword("3321");
    qDebug()<<db.port();
    if (!db.open())
    {
        qDebug() << "Failed to connect to mysql";
        qDebug()<<db.lastError().text();
    }
    else
    {
        qDebug() << "success!";
    }



//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("10.0.0.240");//设置你远程服务器的IP
//    db.setDatabaseName("systemation");//数据库名
//    db.setUserName("online");//数据库用户名和密码
//    db.setPassword("online");
//    if (!db.open())
//    {
//        qDebug() << "Failed to connect to mysql";
//        qDebug()<<db.lastError().text();
//    }
//    else
//    {
//        qDebug() << "success!";
//    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    connectMysql();


    return a.exec();
}
