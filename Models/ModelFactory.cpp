#include<QException>
#include<QDebug>
#include "ModelFactory.h"
#include"CategoryModels.h"

ModelFactory* ModelFactory:: ModelFactory_ = nullptr;

ModelFactory::ModelFactory()
{
 oAvailModels["Category"]= new CategoryModels();
}

IModels* ModelFactory::Get(QString Name, QSqlDatabase & db, QWidget *parent)
{
    if (ModelFactory_ == nullptr)
        ModelFactory_ = new ModelFactory();
    try
    {
        return ModelFactory_->oAvailModels[Name]->Clone(Name,parent,db);
    }
    catch(QException ex)
    {
       qDebug()<<ex.what();
        return nullptr;
    }

}

ModelFactory::~ModelFactory()
{
    qDebug()<<"ModelFactory exiting  ";
    foreach (IModels *obj, oAvailModels) {
       delete obj;
    }
    qDebug()<<"ModelFactory exiting  done";
}
