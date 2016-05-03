#ifndef MODELRESEARCH_H
#define MODELRESEARCH_H

#include <QObject>
#include <QSqlQueryModel>
#include"CommonModel.h"
class ModelResearch : public QSqlQueryModel
{
public:
    ModelResearch(QString Name, QString ColumnName,QObject *parent, QSqlDatabase &db);
private:
    CommonReaderModel* oCommonModel;
};

#endif // MODELRESEARCH_H
