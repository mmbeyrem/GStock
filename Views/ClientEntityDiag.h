#ifndef CLIENTENTITYDIAG_H
#define CLIENTENTITYDIAG_H
#include"CommonEntityDiag.h"
#include"ClientModels.h"
#include<QLineEdit>
class ClientEntityDiag :  public CommonEntityDiag
{
    Q_OBJECT
public:
    ClientEntityDiag(QWidget *parent=0,QSqlDatabase &db=QSqlDatabase());

    // IValidate interface
public:
    bool Validate() override;
    void accept();
    // CommonEntityDiag interface
public:
    CommonEntityDiag *Clone(QWidget *parent, QSqlDatabase &db) override;

public slots:
    void insert() override;
    void Delete(int) override;
    void update(int row, IEntities *) override;
private:
    QLineEdit *FirstName;
    QLineEdit *lastName;
    QLineEdit *Email;
    int iRow;
    ClientModels *Model;
};

#endif // CLIENTENTITYDIAG_H
