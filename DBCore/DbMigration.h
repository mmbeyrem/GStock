#ifndef DBMIGRATION_H
#define DBMIGRATION_H

#include <QSqlDatabase>
class DBMigration
{

public:
    DBMigration(QSqlDatabase& );
    int run();
private:
    QSqlDatabase db;
};

#endif // DBMIGRATION_H
