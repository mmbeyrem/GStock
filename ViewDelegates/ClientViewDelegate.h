#ifndef CLIENTVIEWDELEGATE_H
#define CLIENTVIEWDELEGATE_H

#include"ViewDelegates.h"
class ClientViewDelegate : public ViewDelegates
{
public:
    ClientViewDelegate(QObject *parent = Q_NULLPTR);
    virtual ~ClientViewDelegate();
// QAbstractItemDelegate interface
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const ;
};

#endif // CLIENTVIEWDELEGATE_H
