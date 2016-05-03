#ifndef CLIENTENTITIES_H
#define CLIENTENTITIES_H

#include "IEntities.h"
class ClientEntities : public IEntities
{
public:
    ClientEntities();

    int idClient;
    QString FirstName;
    QString lastName;
    QString Email;
};

#endif // CLIENTENTITIES_H
