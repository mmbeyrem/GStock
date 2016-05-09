#include "ClientViewDelegate.h"


ClientViewDelegate::ClientViewDelegate(QObject *parent ):ViewDelegates(parent)
{

}
ClientViewDelegate::~ClientViewDelegate()
{
    //nothing todo
}

void ClientViewDelegate::paint(QPainter *painter,
                                 const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::paint(painter, option, index);
}

