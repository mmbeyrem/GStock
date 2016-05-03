#ifndef COLUMNCONDITION_H
#define COLUMNCONDITION_H

#include<QMap>
#include<QVariant>
class ColumnCondition
{
public:
    ColumnCondition();
    int Add(QString,QVariant);
    QString* Condition();
private:

    QMap<QString,QVariant> Conidtions;
};

#endif // COLUMNCONDITION_H
