#ifndef IENITIES_H
#define IENITIES_H
#include <QObject>
class IEntities
{
public:
    virtual ~IEntities(){}
    virtual QString tocsv(QChar = ';')=0;
    virtual void fromcsv(QString val,QChar = ';')=0;
    //even virtual destructor makes a class polymorphic!
};

#endif // IENITIES_H




