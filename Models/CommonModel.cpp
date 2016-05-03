#include "CommonModel.h"
#include<QSqlError>
#include<QDebug>
#include<QSqlQuery>
CommonReaderModel::CommonReaderModel(QSqlQueryModel *oModel)
{
    this->oModel = oModel;
}
QList<QSqlRecord *>* CommonReaderModel::GetAll()
{
    int i=0;
    QSqlRecord oRec;
    QList<QSqlRecord*> *oList = new QList<QSqlRecord*> ();
    while ( true )
    {
        oRec = oModel->record(i);
        if (oRec.isEmpty())
            break;
        oList->append(new QSqlRecord(oRec));
        i++;
    }
    return oList;
}

QSqlRecord *CommonReaderModel::Get(int key)
{
    qDebug()<<oModel->record(key);
    return  (new QSqlRecord(oModel->record(key)));
}

CommonWriterModel::CommonWriterModel(QSqlTableModel *mod):CommonReaderModel(mod)
{
    this->oModel = oModel;
}

bool CommonWriterModel::Add(QSqlRecord * const oRec)
{
    qInfo()<<"insert into db";
    bool dbr= static_cast<QSqlTableModel*>(oModel)->insertRecord(-1,*oRec);
    if (dbr)
        static_cast<QSqlTableModel*>(oModel)->submitAll()  ;
    else
        qDebug()<< oModel->lastError();

    return dbr;
}


bool CommonWriterModel::Update(int key ,  QSqlRecord* const oRec)
{
    qInfo()<<"key:"<<key<<" oRec:"<<*oRec;
    bool ret =  static_cast<QSqlTableModel*>(oModel)->setRecord(key,*oRec);
    if (ret)
    {
        if(!static_cast<QSqlTableModel*>(oModel)->submitAll())
        {
            qCritical()<<  oModel->lastError();
            return false;
        }
    }


    return ret;
}

QList<QSqlRecord *>* CommonWriterModel::Find(ColumnCondition & oCondition)
{
    qDebug()<<"CommonModel::Find";
    static_cast<QSqlTableModel*>(oModel)->setFilter(*(oCondition.Condition()));


    QList<QSqlRecord *> *oList = new QList<QSqlRecord *>();
    qDebug()<<oModel->lastError();
    qDebug()<<oModel->query().lastQuery();
    qDebug()<<" oModel->rowCount :"<< oModel->rowCount();
    for (int i = 0 ; i<oModel->rowCount(); i++ )
    {
        QSqlRecord oRec = oModel->record(i);
        if ( oRec.isEmpty())
            break;

        oList->append(new QSqlRecord(oRec));
        i++;
    }
    static_cast<QSqlTableModel*>(oModel)->setFilter(QString());
    return oList;
}
bool CommonWriterModel::Remove(int key)
{
   if(oModel->removeRow(key))
   {
       static_cast<QSqlTableModel*>(oModel)->submitAll();
       return true;
   }
   else
    {
       qCritical()<<oModel->lastError();
       return false;
   }
}
