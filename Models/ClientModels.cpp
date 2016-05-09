#include "ClientModels.h"
#include "ClientEntities.h"
#include<QDebug>
#include<QSqlField>
#include<QSqlError>
ClientModels::ClientModels(QString Name, QObject *parent, QSqlDatabase &db):IModels(parent,db)
{
    qInfo()<<"create new CategoryModels TableName :" << Name;
    TableName =  Name;
    this->setTable(TableName);
    this->select();
    this->oCommonModel = new CommonWriterModel(this);
    this->setEditStrategy(QSqlTableModel::OnManualSubmit);
    oRec = new QSqlRecord();
    oRec->append(QSqlField("idClient"));
    oRec->append(QSqlField("FirstName"));
    oRec->append(QSqlField("lastName"));
    oRec->append(QSqlField("Email"));
    qCritical()<<this->lastError();
}
QList<IEntities*>* ClientModels::GetAll()
{
    QList<IEntities *> *oList = new QList<IEntities *>();
    foreach (QSqlRecord *oRec, *(this->oCommonModel->GetAll())) {
        ClientEntities *oEntitty = new ClientEntities();
        oEntitty->idClient = oRec->value("idClient").toInt();
        oEntitty->FirstName = oRec->value("FirstName").toString();
        oEntitty->lastName = oRec->value("lastName").toString();
        oEntitty->Email = oRec->value("Email").toString();
        oList->append(oEntitty );
        delete oRec;
    }
    return oList;
}

IEntities* ClientModels::Get(int key)
{
    qDebug()<<"ClientModels::Get";
    QSqlRecord* pRec = this->oCommonModel->Get(key);
    ClientEntities* oEntitty = new ClientEntities();
    oEntitty->idClient = pRec->value("idClient").toInt();
    oEntitty->FirstName = pRec->value("FirstName").toString();
    oEntitty->lastName = pRec->value("lastName").toString();
    oEntitty->Email = pRec->value("Email").toString();
    delete pRec;
    qDebug()<<"ClientModels::Get done";
    return oEntitty;
}
int ClientModels::Update(int key ,IEntities* oEntitty)
{
    qDebug()<<"Update request received";
    ClientEntities *oCat = dynamic_cast<ClientEntities*>(oEntitty);//it will be cleaned by the auto_ptr
    if(oCat != nullptr)
    {
        oRec->clearValues();
        qInfo()<<"oCat->idClient:"<<oCat->idClient;
        oRec->setGenerated("idClient",false);
        oRec->setValue("idClient",oCat->idClient);
        oRec->setValue("FirstName",oCat->FirstName);
        oRec->setValue("lastName",oCat->lastName);
        oRec->setValue("Email",oCat->Email);
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
int ClientModels::Add(IEntities *oEntitty)
{
    qDebug()<<"Add request received";
    //it will be cleaned by the auto_ptr
    ClientEntities *oCat = dynamic_cast<ClientEntities*>(oEntitty);
    if (oCat != nullptr)
    {
        oRec->clearValues();
        oRec->setGenerated("idCategory",true);
        oRec->setValue("FirstName",oCat->FirstName);
        oRec->setValue("lastName",oCat->lastName);
        oRec->setValue("Email",oCat->Email);
        if (oCommonModel->Add(oRec))
            emit this->dataChanged(QModelIndex(),QModelIndex());
        else
            return 0;
        return 1;
    }
    qDebug()<<"erro when converting a Category Entites";
    return -1;
}
int ClientModels::Remove(int key)
{
    return oCommonModel->Remove(key);
}
QList<IEntities *> *ClientModels::Find(ColumnCondition & cond)
{
    QList<IEntities *> *oList = new QList<IEntities *>();
    foreach (QSqlRecord *oRec, *(this->oCommonModel->Find(cond))) {
        ClientEntities *oEntitty = new ClientEntities();
        oEntitty->idClient = oRec->value("idClient").toInt();
        oEntitty->FirstName = oRec->value("FirstName").toString();
        oEntitty->lastName = oRec->value("lastName").toString();
        oEntitty->Email = oRec->value("Email").toString();
        oList->append( oEntitty );
        delete oRec;
    }
    return oList;
}

ClientModels::~ClientModels()
{
    qDebug()<<"~ClientModels";
    delete oRec;
    delete oCommonModel;
    qDebug()<<"~ClientModels done";
}
IModels* ClientModels::Clone(QString Name,QWidget *parent , QSqlDatabase &db)
{
    qInfo()<<"clone new ClientModels";
    qInfo()<<"Name:"<<Name;
    qInfo()<<"db:"<<db.databaseName()<<" status:"<<db.isOpen();
    return new ClientModels(Name,(QObject*)parent,db);
}

IEntities *ClientModels::CloneEntity()
{
    return new ClientEntities();
}

