#include <QApplication>
#include <QSettings>
#include<QDebug>
#include"QSqlError"
#include "MainWindow.h"
#include"DbMigration.h"
#include <QDir>
bool createConnection(QSqlDatabase &db, bool update);

int main(int argc, char *argv[])
{
    bool NeedUpdate = false;
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("mmbeyrem");
    QCoreApplication::setOrganizationDomain("mmbeyrem.com");
    QCoreApplication::setApplicationName("GStock");

    QSqlDatabase db;
    QSettings settings;

    QString dbv = settings.value("dbv").toString();
    qDebug()<<dbv;

    QDir oDir ;
    QStringList lastScript = oDir.entryList(QStringList("*.sql"));


    if (dbv == "" || dbv < lastScript.first())
        NeedUpdate = true;


    if (!createConnection(db,NeedUpdate))
    {
        qDebug()<<"error in dataBase";
        return -1;
    }

    MainWindow w(db);
    w.show();

    return a.exec();
}

bool createConnection(QSqlDatabase &db, bool update){

    qInfo()<<"Do "<<update;
    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("GStock");
    db.setUserName("root");
    db.setPassword("admin@123");
    db.open();
    if ( update) {
        db.open();
        DBMigration oMigration(db);
        oMigration.run();
    }
    return true;
}
