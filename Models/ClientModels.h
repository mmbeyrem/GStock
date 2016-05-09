#ifndef CLIENTMODELS_H
#define CLIENTMODELS_H
#include"CommonModel.h"
#include "IModels.h"
#include<QSqlRecord>

class ClientModels : public IModels
{
Q_OBJECT
public:
    ClientModels(){}
    ClientModels(QString Name, QObject *parent = Q_NULLPTR, QSqlDatabase &db = QSqlDatabase());
    virtual IModels* Clone(QString Name, QWidget *parent , QSqlDatabase &db);
    virtual  IEntities* CloneEntity();
    virtual QList<IEntities *> *GetAll();
    virtual IEntities* Get(int key);
    virtual int Update(int row ,IEntities*);
    virtual int Add(IEntities*);
    virtual int Remove(int key);
    virtual QList<IEntities*> *Find(ColumnCondition &);
    virtual ~ClientModels();
private :
    QString TableName ;
};

#endif // CLIENTMODELS_H
