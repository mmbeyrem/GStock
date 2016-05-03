#ifndef CATEGORYVALIDATOR_H
#define CATEGORYVALIDATOR_H
#include"IEntityValidator.h"


class CategoryValidator : public IEntityValidator
{
public:
    CategoryValidator();
public slots:
    virtual bool Validate(QMap<QString,QVariant>&);

};

#endif // CATEGORYVALIDATOR_H
