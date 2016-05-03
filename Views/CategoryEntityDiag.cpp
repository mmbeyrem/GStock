#include "CategoryEntityDiag.h"
#include"CategoryEntities.h"
#include "ui_commonentitydiag.h"
#include "ModelFactory.h"
#include<QLabel>
#include <QDoubleValidator>
#include <QRegularExpressionValidator>
#include<QDebug>

CategoryEntityDiag::CategoryEntityDiag(QWidget *parent, QSqlDatabase &db):CommonEntityDiag(parent)
{
    Name = new QLineEdit(this);
   // Name->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-Z]"),this) );
    Name->setToolTip(tr("Name should start with lettre"));
    Tva = new QLineEdit(this);
    Tva->setValidator(new QDoubleValidator(0.,200.,2,this) );
    Tva->setToolTip(tr("tva should be a nositif value with decimal after '.'"));
    Specific = new QLineEdit(this);

    this->ui->formLayout->addRow(tr("Name"),Name);

    this->ui->formLayout->addRow(tr("Tva"),Tva);
    this->ui->formLayout->addRow(tr("Specific"),Specific);


    ui->listWidget->hide();
    Model = dynamic_cast<CategoryModels *>( ModelFactory::Get("Category",db,this));
    iRow = -1;
}

void CategoryEntityDiag::insert()
{
    qDebug()<<"ask for insert";
    iRow = -1;
    Current.reset(new CategoryEntities());
    Name->clear();
    Tva->clear();
    Specific->clear();
    this->show();
}

void CategoryEntityDiag::update(int row,IEntities *obj)
{
    Name->setModified(false);
    if (obj == nullptr || dynamic_cast<CategoryEntities*>(obj)== nullptr)
    {
        qCritical()<<"bad IEntities obj on CategoryEntityDiag ";
        return ;
    }
    Current.reset (new CategoryEntities(dynamic_cast<CategoryEntities*>(obj)));
    delete obj;

    if(Current.get() == nullptr)
    {
        qDebug()<<"Internal Error CategoryEntityDiag::update bad param";
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
    Name->setReadOnly(true);
    Name->setText(((CategoryEntities*)Current.get())->Name);
    Tva->setText(QString::number(((CategoryEntities*)Current.get())->Tva));
    Specific->setText(((CategoryEntities*)Current.get())->Specific);
    this->show();
    qInfo()<<"CategoryEntityDiag::update end ";
}

CategoryEntityDiag::~CategoryEntityDiag()
{
    qDebug()<<"~CategoryEntityDiag";
    delete ui;
    Current.release();

    qDebug()<<"~CategoryEntityDiag done";
}

void CategoryEntityDiag::accept()
{
    if (Validate())
    {
        ui->listWidget->show();
    }else
    {
        this->hide();
        ((CategoryEntities*)Current.get())->Name = Name->text();
        ((CategoryEntities*)Current.get())->Tva =  Tva->text().toFloat();
        ((CategoryEntities*)Current.get())->Specific = Specific->text();

        if(iRow<0)
            emit add(Current.get() );
        else
        emit add(iRow,Current.get() );
        ui->listWidget->clear();
        ui->listWidget->hide();
    }
}
CommonEntityDiag* CategoryEntityDiag:: Clone(QWidget *parent,QSqlDatabase &odb)
{
    return  new CategoryEntityDiag(parent,odb) ;
}


void CategoryEntityDiag::Delete(int row)
{
    emit Remove(row);
}
bool CategoryEntityDiag::Validate()
{
    ColumnCondition oCond;
    oCond.Add("Name",Name->text());
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
    return false;
}
