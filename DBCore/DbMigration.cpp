#include "DbMigration.h"

#include <QFile>
#include<QDir>
#include <QSqlQuery>
#include <QDebug>
#include<QSqlError>
#include<QSettings>
DBMigration::DBMigration(QSqlDatabase &db)
{
    this->db  = db;
}
int DBMigration::run()
{
    QFile oFile("script.sql");
    QDir oDir;
    qDebug()<< oDir.currentPath();
    if (!oFile.open(QIODevice::ReadOnly))
    {
        qDebug()<<oFile.errorString();
        return -1;
    }
    QString Scripts(oFile.readAll());
    QSqlQuery oQuery(db);
    foreach (QString Script, Scripts.split(QChar(';'))) {
        qDebug()<<"Script::"<<Script;
        if (!oQuery.exec(Script))
        {

            qDebug()<<oQuery.lastError();
            return -1;
        }
    }
    QSettings settings;
    settings.setValue("dbv",oFile.fileName());
    return 0;
}
