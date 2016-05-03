#include "CategoryEntities.h"
#include <QDebug>

CategoryEntities::CategoryEntities()
{

}

CategoryEntities::CategoryEntities(const CategoryEntities *obj)
{
    qInfo()<<"CategoryEntities";
    this->idCategory = obj->idCategory;
    this->Name = obj->Name;
    this->Specific = obj->Specific;
    this->Tva = obj->Tva;
    qInfo()<<"CategoryEntities end";
}
QString CategoryEntities::tocsv(QChar sep)
{
    QString tmp;
    tmp = Name+sep+QString::number(Tva)+sep+Specific+'\n';
    return tmp;
}

void CategoryEntities::fromcsv(QString val, QChar sep)
{
    QStringList tmp = val.split(sep);
    if (tmp.count() != 3)
    {
        qDebug()<<"can not parse :"<<val << " as a CategoryEntitie" ;
        return ;
    }
    Name = tmp[0];
    Tva = tmp[1].toFloat();
    Specific = tmp[2];
    return ;
}
