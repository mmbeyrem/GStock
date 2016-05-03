#ifndef USERENTITES_H
#define USERENTITES_H

#include "IEntities.h"
class UserEntites : public IEntities
{
public:
    UserEntites();
    int idUser;
    QString FirstName;
    QString LastName;
};

#endif // USERENTITES_H
