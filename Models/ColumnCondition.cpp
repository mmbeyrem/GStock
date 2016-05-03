#include "ColumnCondition.h"

ColumnCondition::ColumnCondition()
{

}
int ColumnCondition::Add(QString key,QVariant val)
{
    Conidtions[key]= val;
    return 0;
}
QString *ColumnCondition::Condition()
{
   QString* filter = new QString();
    for (auto it = Conidtions.begin(); it != Conidtions.end(); ++it) {
        (*filter)+=it.key()+"=\'"+it.value().toString()+"\' ADD ";
    }
    filter->remove(filter->lastIndexOf("ADD"),3);
    return filter;
}
