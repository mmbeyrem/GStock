#ifndef CATEGORYLMODELS_H
#define CATEGORYLMODELS_H


#include"CommonModel.h"
#include "IModels.h"
#include<QSqlRecord>
class CategoryModels : public IModels
{
Q_OBJECT
public:
    CategoryModels(){}
    CategoryModels(QString Name, QObject *parent = Q_NULLPTR, QSqlDatabase &db = QSqlDatabase());
    virtual IModels* Clone(QString Name, QWidget *parent , QSqlDatabase &db);
    virtual  IEntities* CloneEntity();
    virtual QList<IEntities *> *GetAll();
    virtual IEntities* Get(int key);
    virtual int Update(int row ,IEntities*);
    virtual int Add(IEntities*);
    virtual int Remove(int key);
    virtual QList<IEntities*> *Find(ColumnCondition &);
    virtual ~CategoryModels();
private :
    QString TableName ;

};

#endif // CATEGORYLMODELS_H
