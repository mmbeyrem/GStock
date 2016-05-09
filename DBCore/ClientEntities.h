#ifndef CLIENTENTITIES_H
#define CLIENTENTITIES_H

#include "IEntities.h"
class ClientEntities : public IEntities
{
public:
    ClientEntities();
    ClientEntities(const ClientEntities *);
    int idClient;
    QString FirstName;
    QString lastName;
    QString Email;
    virtual QString tocsv(QChar = ';');
    virtual void fromcsv(QString val, QChar = ';');
};

#endif // CLIENTENTITIES_H
