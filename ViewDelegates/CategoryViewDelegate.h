#ifndef COMMONVIEWDELEGATE_H
#define COMMONVIEWDELEGATE_H

#include <QObject>
#include <QWidget>

#include"ViewDelegates.h"
class CategoryViewDelegate : public ViewDelegates
{
public:
    CategoryViewDelegate(QObject *parent = Q_NULLPTR);
    virtual ~CategoryViewDelegate();
// QAbstractItemDelegate interface
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const ;

};

#endif // COMMONVIEWDELEGATE_H
