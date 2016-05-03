#ifndef IMODELS_H
#define IMODELS_H
#include<QList>
#include <QMap>
#include <QVariant>
#include <QSqlRecord>
#include<QSQlTableModel>
#include"CommonModel.h"
#include"IEntities.h"
class IModels:public QSqlTableModel
{
    Q_OBJECT
protected :
    IModels(QObject *parent = nullptr, QSqlDatabase &db= QSqlDatabase()):QSqlTableModel(parent,db){ }
public:
    virtual ~IModels(){}
    virtual  IModels* Clone(QString Name,QWidget *parent , QSqlDatabase& db)=0;
public slots:

    virtual QList<IEntities*>* GetAll()=0;
    virtual IEntities* Get(int key)=0;
    virtual int Update(int key ,IEntities*)=0;
    virtual int Add(IEntities*)=0;
    virtual int Remove(int key)=0;
    virtual QList<IEntities*>* Find(ColumnCondition &) =0;

protected:
    CommonWriterModel* oCommonModel;
    QSqlRecord* oRec;
};

#endif // IMODELS_H
