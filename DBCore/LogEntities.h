#ifndef LOGENTITIES_H
#define LOGENTITIES_H
#include "IEntities.h"
#include<QDateTime>
class LogEntities : public IEntities
{
public:
    LogEntities();
    int idlog;
    QDateTime Date;
    QString UserName;
    QString Operation;
    QString Product;
    QString Provider;
    QString Client;
    QString User;
};

#endif // LOGENTITIES_H
