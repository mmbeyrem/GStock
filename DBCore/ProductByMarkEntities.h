#ifndef PRODUCTBYMARKENTITIES_H
#define PRODUCTBYMARKENTITIES_H
#include <QImage>
#include"IEntities.h"

class ProductByMarkEntities : public IEntities
{
public:
    ProductByMarkEntities();
    QString Product;
    QString Mark;
    QImage photo;
    float SellingPrice;
    float PurchasePrice;
    int Stock;
    QString Description;
};

#endif // PRODUCTBYMARKENTITIES_H
