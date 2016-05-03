#ifndef MODELFACTORY_H
#define MODELFACTORY_H
#include"IModels.h"

class ModelFactory
{
private:
    ModelFactory();
public:
   static IModels* Get(QString DiagName, QSqlDatabase &db, QWidget *parent);
   ~ModelFactory();
private:
   static ModelFactory* ModelFactory_;
   QMap<QString,IModels*> oAvailModels;
};

#endif // MODELFACTORY_H
