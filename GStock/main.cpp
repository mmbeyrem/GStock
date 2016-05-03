#include "MainWindow.h"
#include"DbMigration.h"
#include <QApplication>
#include<QDebug>
#include"QSqlError"

bool createConnection(QSqlDatabase &db);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db;
    if (!createConnection(db))
    {
        qDebug()<<"error in dataBase";
        return -1;
    }

    MainWindow w(db);
    w.show();

    return a.exec();
}

bool createConnection(QSqlDatabase &db){
    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("GStock");
    db.setUserName("root");
    db.setPassword("admin@123");

    qDebug()<< "db.open : "<<db.open();
    if ( false) {
        db.open();
        DBMigration oMigration(db);
        oMigration.run();
    }
    return true;
}
