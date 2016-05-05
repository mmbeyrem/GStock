#include "CategoryViewDelegate.h"
#include<QDebug>
#include<QPainter>
#include<QStyleOptionViewItem>
CategoryViewDelegate::CategoryViewDelegate(QObject *parent ):ViewDelegates(parent)
{

}
CategoryViewDelegate::~CategoryViewDelegate()
{
    //nothing todo
}

void CategoryViewDelegate::paint(QPainter *painter,
                                 const QStyleOptionViewItem &option, const QModelIndex &index) const
{

        if (index.column() ==2)
        {
            painter->save();
            double val = index.data().toDouble();
            if (val < 20)
            {
                painter->setPen(QColor("blue")) ;
            }else
                if (val < 50)
                {
                    painter->setPen(QColor("green")) ;
                }
                else
                {
                    painter->setPen(QColor("red")) ;
                }
            if((option.state & QStyle::State_Selected) == QStyle::State_Selected)
            {
                qDebug()<<"Yes";
                painter->fillRect(option.rect,Qt::yellow);
                painter->setBrush(QBrush(QColor("yellow")));
            }
            painter->drawText(option.rect,Qt::AlignCenter, index.data().toString());
            painter->restore();
        }else
            if (index.column()==3)
            {
                QString val =  index.data().toString();
                if(val != "")
                {
                    painter->save();
                    painter->setPen(QColor("red")) ;
                    QFont font = painter->font() ;
                    font.setPointSize ( 15 );
                    font.setBold(true);
                    painter->setFont(font) ;
                    if((option.state & QStyle::State_Selected) == QStyle::State_Selected)
                    {
                        qDebug()<<"Yes";
                        painter->fillRect(option.rect,Qt::blue);
                        painter->setBrush(QBrush(QColor("yellow")));
                    }
                    painter->drawText(option.rect,Qt::AlignCenter, index.data().toString());
                    painter->restore();
                }
            }else

    QStyledItemDelegate::paint(painter, option, index);
}
