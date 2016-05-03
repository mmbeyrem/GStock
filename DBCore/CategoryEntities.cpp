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
