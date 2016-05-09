#include "ViewDelegatesFactory.h"
#include "CategoryViewDelegate.h"
#include "ClientViewDelegate.h"

ViewDelegatesFactory* ViewDelegatesFactory:: ViewDelegatesFactory_ = nullptr;

ViewDelegatesFactory::ViewDelegatesFactory( QObject * parent)
{
    oAvail["Category"] = new CategoryViewDelegate(parent);
    oAvail["Client"] = new ClientViewDelegate(parent);
}

ViewDelegates* ViewDelegatesFactory::Get(QString ViewName, QObject * parent)
{
    if (ViewDelegatesFactory_ == nullptr)
        ViewDelegatesFactory_ = new ViewDelegatesFactory(parent);

    return ViewDelegatesFactory_->oAvail[ViewName];
}
ViewDelegatesFactory:: ~ViewDelegatesFactory()
{
    for(auto it = oAvail.begin(); it != oAvail.end(); ++it)
        delete it.value();

    delete ViewDelegatesFactory_;
}
