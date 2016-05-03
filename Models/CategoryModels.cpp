#include "CategoryModels.h"
#include"CategoryEntities.h"
#include<QDebug>
#include<QSqlField>
#include<QDebug>
#include<QSqlError>
CategoryModels::CategoryModels(QString Name, QObject *parent, QSqlDatabase &db):IModels(parent,db)
{
    qInfo()<<"create new CategoryModels TableName :" << Name;
    TableName =  Name;
    this->setTable(TableName);
    this->select();
    this->oCommonModel = new CommonWriterModel(this);
    this->setEditStrategy(QSqlTableModel::OnManualSubmit);
    oRec = new QSqlRecord();
    oRec->append(QSqlField("idCategory"));
    oRec->append(QSqlField("Name"));
    oRec->append(QSqlField("Tva"));
    oRec->append(QSqlField("Specific"));
    qCritical()<<this->lastError();
}
QList<IEntities*>* CategoryModels::GetAll()
{
    QList<IEntities *> *oList = new QList<IEntities *>();
    foreach (QSqlRecord *oRec, *(this->oCommonModel->GetAll())) {
        CategoryEntities *oCategoryEntitty = new CategoryEntities();
        oCategoryEntitty->idCategory = oRec->value("idCategory").toInt();
        oCategoryEntitty->Name = oRec->value("Name").toString();
        oCategoryEntitty->Specific = oRec->value("Specific").toString();
        oCategoryEntitty->Tva = oRec->value("Tva").toFloat();
        oList->append(oCategoryEntitty );
        delete oRec;
    }
    return oList;
}

IEntities* CategoryModels::Get(int key)
{
    qDebug()<<"CategoryModels::Get";
    QSqlRecord* pRec = this->oCommonModel->Get(key);
    CategoryEntities* oCategoryEntitty = new CategoryEntities();
    oCategoryEntitty->idCategory = pRec->value("idCategory").toInt();
    oCategoryEntitty->Name = pRec->value("Name").toString();
    oCategoryEntitty->Specific = pRec->value("Specific").toString();
    oCategoryEntitty->Tva = pRec->value("Tva").toFloat();
    delete pRec;
    qDebug()<<"CategoryModels::Get done";
    return oCategoryEntitty;
}
int CategoryModels::Update(int key ,IEntities* oCategoryEntitty)
{
    qDebug()<<"Update request received";
    CategoryEntities *oCat = dynamic_cast<CategoryEntities*>(oCategoryEntitty);//it will be cleaned by the auto_ptr
    if(oCat != nullptr)
    {
        oRec->clearValues();
        qInfo()<<"oCat->idCategory:"<<oCat->idCategory;
        oRec->setGenerated("idCategory",false);
        oRec->setValue("idCategory",oCat->idCategory);
        oRec->setValue("Name",oCat->Name);
        oRec->setValue("Specific",oCat->Specific);
        oRec->setValue("Tva",oCat->Tva);
        if(oCommonModel->Update(key,oRec))
         {
            emit this->dataChanged(QModelIndex(),QModelIndex());
            qDebug()<<"Update request OK ";
            return 1;
          }
        qCritical()<<"Update request NOK ";
        return -2;
    }
    qCritical()<<"Update request error ";
    return -1;
}
int CategoryModels::Add(IEntities *oCategoryEntitty)
{
    qDebug()<<"Add request received";
    //it will be cleaned by the auto_ptr
    CategoryEntities *oCat = dynamic_cast<CategoryEntities*>(oCategoryEntitty);
    if (oCat != nullptr)
    {
        oRec->clearValues();
        oRec->setGenerated("idCategory",true);
        oRec->setValue("Name",oCat->Name);
        oRec->setValue("Specific",oCat->Specific);
        oRec->setValue("Tva",oCat->Tva);
        if (oCommonModel->Add(oRec))
            emit this->dataChanged(QModelIndex(),QModelIndex());
        return 1;
    }
    qDebug()<<"erro when converting a Category Entites";
    return -1;
}
int CategoryModels::Remove(int key)
{
    return oCommonModel->Remove(key);
}
QList<IEntities *> *CategoryModels::Find(ColumnCondition & cond)
{
    QList<IEntities *> *oList = new QList<IEntities *>();
    foreach (QSqlRecord *oRec, *(this->oCommonModel->Find(cond))) {
        CategoryEntities *oCategoryEntitty = new CategoryEntities();
        oCategoryEntitty->idCategory = oRec->value("idCategory").toInt();
        oCategoryEntitty->Name = oRec->value("Name").toString();
        oCategoryEntitty->Specific = oRec->value("Specific").toString();
        oCategoryEntitty->Tva = oRec->value("Tva").toFloat();
        oList->append( oCategoryEntitty );
        delete oRec;
    }
    return oList;
}

CategoryModels::~CategoryModels()
{
    qDebug()<<"~CategoryModels";
    delete oRec;
    delete oCommonModel;
    qDebug()<<"~CategoryModels done";
}
IModels* CategoryModels::Clone(QString Name,QWidget *parent , QSqlDatabase &db)
{
    qInfo()<<"clone new CategoryModels";
    qInfo()<<"Name:"<<Name;
    qInfo()<<"db:"<<db.databaseName()<<" status:"<<db.isOpen();
    return new CategoryModels(Name,(QObject*)parent,db);
}

IEntities *CategoryModels::CloneEntity()
{
    return new CategoryEntities();
}
