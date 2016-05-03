#ifndef PRODUCTENTITIES_H
#define PRODUCTENTITIES_H

#include <QDateTime>
#include "IEntities.h"
class ProductEntities : public IEntities
{
public:
    ProductEntities();

    int idProduct;
    QString Name;
    QString Category;
    float PurchasePrice;
    float SellingPrice;
    int StockStatus;
    QDateTime ModifcationDate;
};

#endif // PRODUCTENTITIES_H
