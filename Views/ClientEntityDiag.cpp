#include "ClientEntityDiag.h"
#include "ModelFactory.h"
#include "ui_commonentitydiag.h"
#include "ClientEntities.h"
#include<QDebug>
ClientEntityDiag::ClientEntityDiag(QWidget *parent, QSqlDatabase &db):CommonEntityDiag(parent)
{
    FirstName = new QLineEdit(this);
   // Name->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Z]"),this) );
    FirstName->setToolTip(tr("First name should start with lettre"));
    FirstName->setValidator(new QRegExpValidator (QRegExp("^([a-zA-Z])+"), this));
    lastName = new QLineEdit(this);

    lastName->setToolTip(tr("Last name should start with lettre"));
    lastName->setValidator(new QRegExpValidator (QRegExp("^([a-zA-Z])+"), this));
    Email = new QLineEdit(this);
    Email->setValidator(new QRegExpValidator (QRegExp("^[a-zA-Z](\\d|\\D)*@[a-zA-Z].[a-zA-Z]"), this));
    Email->setToolTip(tr("Email format xxx@yyyy.zzz"));
    this->ui->formLayout->addRow(tr("FirstName"),FirstName);

    this->ui->formLayout->addRow(tr("lastName"),lastName);
    this->ui->formLayout->addRow(tr("Email"),Email);


    ui->listWidget->hide();
    Model = dynamic_cast<ClientModels *>( ModelFactory::Get("Client",db,this));
    iRow = -1;
}


bool ClientEntityDiag::Validate()
{
    if (iRow<0)
    {
        ColumnCondition oCond;
        oCond.Add("FirstName",FirstName->text());
         oCond.Add("lastName",lastName->text());
        QList<IEntities *> *oList = this->Model->Find(oCond);
        if ( oList != nullptr && oList->count()>0)
        {
             ui->listWidget->addItem(tr("this Name is already exist"));
             foreach (IEntities *bj , *oList) {
                     delete bj;
             }
             delete oList;
             return true;
        }
    }
    return false;
}
void ClientEntityDiag::accept()
{
    if (Validate())
    {
        ui->listWidget->show();
    }else
    {
        this->hide();
        ((ClientEntities*)Current.get())->FirstName = FirstName->text();
        ((ClientEntities*)Current.get())->lastName =  lastName->text();
        ((ClientEntities*)Current.get())->Email = Email->text();

        if(iRow<0)
            emit add(Current.get() );
        else
        emit add(iRow,Current.get() );
        ui->listWidget->clear();
        ui->listWidget->hide();
    }
}
CommonEntityDiag *ClientEntityDiag::Clone(QWidget *parent, QSqlDatabase &db)
{
     return  new ClientEntityDiag(parent,db) ;
}

void ClientEntityDiag::insert()
{
    qDebug()<<"ask for insert";
    iRow = -1;
    Current.reset(new ClientEntities());
    FirstName->clear();
    lastName->clear();
    Email->clear();
    this->show();
}

void ClientEntityDiag::Delete(int row)
{
    emit Remove(row);
}

void ClientEntityDiag::update(int row, IEntities *obj)
{
    FirstName->setModified(false);
    if (obj == nullptr || dynamic_cast<ClientEntities*>(obj)== nullptr)
    {
        qCritical()<<"bad IEntities obj on ClientEntities ";
        return ;
    }
    Current.reset (new ClientEntities(dynamic_cast<ClientEntities*>(obj)));
    delete obj;

    if(Current.get() == nullptr)
    {
        qDebug()<<"Internal Error ClientEntities::update bad param";
        return ;
    }

    iRow = row;
    if (iRow <0)
    {
        qDebug()<<"Internal Error update with negatif key";
        return ;
    }

    ui->buttonBox->setStandardButtons(
                ui->buttonBox->standardButtons()|
                QDialogButtonBox::Save);
    FirstName->setReadOnly(true);
    FirstName->setReadOnly(true);
    FirstName->setText(((ClientEntities*)Current.get())->FirstName);
    FirstName->setText(((ClientEntities*)Current.get())->lastName);
    Email->setText(((ClientEntities*)Current.get())->Email);
    this->show();
    qInfo()<<"CategoryEntityDiag::update end ";
}
