#ifndef VIEWDELEGATESFACTORY_H
#define VIEWDELEGATESFACTORY_H
#include<QMap>
#include<QObject>
#include"ViewDelegates.h"

class ViewDelegatesFactory
{
private:
    ViewDelegatesFactory(QObject * );
public:
   static ViewDelegates*  Get(QString ViewName, QObject * parent);
     virtual ~ViewDelegatesFactory();
private:
   static  ViewDelegatesFactory* ViewDelegatesFactory_;
   QMap<QString,ViewDelegates*> oAvail;
};

#endif // VIEWDELEGATESFACTORY_H
