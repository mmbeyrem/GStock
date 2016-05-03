#ifndef PROVIDERENTITES_H
#define PROVIDERENTITES_H
#include "IEntities.h"
class ProviderEntites : public IEntities
{
public:
    ProviderEntites();
    int idProvide;
    QString Name;
    QString Tel;
    QString  Fax;
};

#endif // PROVIDERENTITES_H
