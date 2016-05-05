#ifndef VIEWDELEGATES_H
#define VIEWDELEGATES_H
#include<QStyledItemDelegate>

class ViewDelegates:public QStyledItemDelegate
{
public:
    ViewDelegates(QObject *parent = Q_NULLPTR):QStyledItemDelegate(parent){}
    virtual ~ViewDelegates(){}
};

#endif // VIEWDELEGATES_H
