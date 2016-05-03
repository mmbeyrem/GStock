#ifndef COMMONENTITYDIAG_H
#define COMMONENTITYDIAG_H

#include <QDialog>
#include "IEntities.h"
#include "IModels.h"
#include<memory>
#include <QList>
#include<QAbstractButton>
#include "IValidate.h"
namespace Ui {
class CommonEntityDiag;
}

class CommonEntityDiag : public QDialog,IValidate
{
    Q_OBJECT

public:
    explicit CommonEntityDiag(QWidget *parent = 0);
    virtual CommonEntityDiag* Clone(QWidget *parent= 0,QSqlDatabase &db=QSqlDatabase())=0;
public slots:
    virtual void insert()=0;
    virtual void Delete(int )=0;
    virtual void update(int row ,IEntities*)=0;
    void clean(QAbstractButton*);
signals:
   void add(IEntities*);
   void add(int row ,IEntities*);
   void Remove(int);
protected:
    Ui::CommonEntityDiag *ui;
    QList<IModels*> ValidationModels;
    std::auto_ptr<IEntities> Current;
    QSqlDatabase db;


};

#endif // COMMONENTITYDIAG_H
