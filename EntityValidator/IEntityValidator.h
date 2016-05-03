#ifndef IENTITYVALIDATOR_H
#define IENTITYVALIDATOR_H

#include<QObject>
#include<QMap>
#include<QVariant>
#include"IModels.h"
class IEntityValidator:public QObject
{
Q_OBJECT

public slots:
    virtual bool Validate(QMap<QString,QVariant>&)=0;
protected:

    typedef bool (IEntityValidator::*IVadationFunc)(QVariant &, IModels *model);
    QMap<QString , IVadationFunc > *m_Func;

};

#endif // IENTITYVALIDATOR_H
