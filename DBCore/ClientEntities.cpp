#include "ClientEntities.h"
#include<QDebug>
ClientEntities::ClientEntities()
{

}
ClientEntities::ClientEntities(const ClientEntities *obj)
{
    qInfo()<<"CategoryEntities";
    this->idClient = obj->idClient;
    this->FirstName = obj->FirstName;
    this->lastName = obj->lastName;
    this->Email = obj->Email;
    qInfo()<<"ClientEntities end";
}
QString ClientEntities::tocsv(QChar sep)
{
    QString tmp;
    tmp = FirstName+sep+lastName+sep+Email+'\n';
    return tmp;
}

void ClientEntities::fromcsv(QString val, QChar sep)
{
    QStringList tmp = val.split(sep);
    if (tmp.count() != 3)
    {
        qDebug()<<"can not parse :"<<val << " as a ClientEntities" ;
        return ;
    }
    FirstName = tmp[0];
    lastName = tmp[1].toFloat();
    Email = tmp[2];
    return ;
}
