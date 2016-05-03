#ifndef ENTITYDIAGFACTORY_H
#define ENTITYDIAGFACTORY_H

#include"CommonEntityDiag.h"
#include<QMap>
class EntityDiagFactory
{
private :
    EntityDiagFactory();
public:
   static CommonEntityDiag*  Get(QString DiagName, QWidget *parent, QSqlDatabase &db=QSqlDatabase());
     ~EntityDiagFactory();
private:
   static  EntityDiagFactory* EntityDiagFactory_;
   QMap<QString,CommonEntityDiag*> oAvailEntityDiag;
};

#endif // ENTITYDIAGFACTORY_H
