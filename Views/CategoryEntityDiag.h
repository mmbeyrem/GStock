#ifndef CATEGORYENTITYDIAG_H
#define CATEGORYENTITYDIAG_H
#include"CommonEntityDiag.h"
#include<QLineEdit>
#include"CategoryModels.h"

class CategoryEntityDiag : public CommonEntityDiag
{
    Q_OBJECT
public:
    CategoryEntityDiag(QWidget *parent=0,QSqlDatabase &db=QSqlDatabase());
    virtual CommonEntityDiag* Clone(QWidget *parent= 0,QSqlDatabase &db=QSqlDatabase());
     virtual ~CategoryEntityDiag();
     void accept();
     // IValidate interface
     bool Validate() override;
public slots:
    void insert();
    void update(int,IEntities*);
    void Delete(int);
private:
    QLineEdit *Name;
    QLineEdit *Tva;
    QLineEdit *Specific;
    int iRow;
    CategoryModels *Model;


};

#endif // CATEGORYENTITYDIAG_H
