#include "ModelResearch.h"
#include<QSqlQuery>
ModelResearch::ModelResearch(QString Name,QString ColumnName, QObject *parent, QSqlDatabase &db):QSqlQueryModel(parent)
{
    QSqlQuery oQSqlQuery("select "+ColumnName + " from "+Name,db);
    this->setQuery(oQSqlQuery);
    this->oCommonModel = new CommonReaderModel(this);
}
