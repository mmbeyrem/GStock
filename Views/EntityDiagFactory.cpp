#include "EntityDiagFactory.h"
#include"categoryentitydiag.h"
#include"ClientEntityDiag.h"
#include<QException>
#include<QDebug>
EntityDiagFactory* EntityDiagFactory:: EntityDiagFactory_ = nullptr;


EntityDiagFactory::EntityDiagFactory()
{
    oAvailEntityDiag["Category"]= new CategoryEntityDiag();
    oAvailEntityDiag["Client"]= new ClientEntityDiag();
}

CommonEntityDiag *EntityDiagFactory::Get(QString DiagName,QWidget *parent,QSqlDatabase &db)
{
    if (EntityDiagFactory_ == nullptr)
        EntityDiagFactory_ = new EntityDiagFactory();
    try
    {
        return EntityDiagFactory_->oAvailEntityDiag[DiagName]->Clone(parent,db);
    }
    catch(QException ex)
    {
       qDebug()<<ex.what();
        return (CommonEntityDiag *)nullptr;
    }

}

EntityDiagFactory::~EntityDiagFactory()
{
    qDebug()<<"~EntityDiagFactory";
    foreach (CommonEntityDiag *obj, oAvailEntityDiag) {
       delete obj;
    }
    qDebug()<<"~EntityDiagFactory done";
}
