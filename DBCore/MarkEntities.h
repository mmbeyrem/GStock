#ifndef MARKENTITIES_H
#define MARKENTITIES_H

#include "IEntities.h"
#include<QImage>
class MarkEntities : public IEntities
{
public:
    MarkEntities();
    int  idMark;
    QString Name;
    QImage Photo;
};

#endif // MARKENTITIES_H
