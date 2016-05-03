#ifndef COMUNMODEL_H
#define COMUNMODEL_H
#include<QList>
#include<QSqlRecord>
#include<QSqlTableModel>
#include <QSqlQueryModel>
#include"ColumnCondition.h"

class CommonReaderModel
{
public:
    CommonReaderModel(QSqlQueryModel*);
    QList<QSqlRecord*>* GetAll();
    QSqlRecord* Get(int key);
protected :
    QSqlQueryModel* oModel;
};

class CommonWriterModel: public CommonReaderModel
{
public:
    CommonWriterModel(QSqlTableModel*mod);

    bool Update(int key , QSqlRecord* const);
    bool Add(QSqlRecord*oRec);
    QList<QSqlRecord *> *Find(ColumnCondition &);
    bool Remove(int key);

};

#endif // COMUNMODEL_H
