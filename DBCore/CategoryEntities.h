#ifndef CATEGORYENTITIES_H
#define CATEGORYENTITIES_H

#include "IEntities.h"
class CategoryEntities : public IEntities
{
public:
    CategoryEntities();
    CategoryEntities(const CategoryEntities *);
    int idCategory;
    QString Name;
    float Tva;
    QString Specific;
};

#endif // CATEGORYENTITIES_H
