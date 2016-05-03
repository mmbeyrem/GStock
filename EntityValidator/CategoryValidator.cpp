#include "CategoryValidator.h"

void CategoryValidator::validateName(QString txt,IModel * Model)
{
    qDebug()<<"validateName:"<<txt;
    if( !txt.isNull() && !txt.isEmpty())
   {
        ColumnCondition Cond;
        Cond.Add("Name",txt);
        QList<IEntities *> *o = Model->Find(Cond);
        if (o != nullptr && o->count()>0)
        {
            ui->listWidget->addItem(QString(tr("Name all ready exists")));
            ui->listWidget->adjustSize();
            ui->listWidget->show();
            ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel|
                                              QDialogButtonBox::Reset);
            foreach (IEntities * obj, *o) {
                delete obj;
            }
            delete o;
        }else
        {
            ui->listWidget->hide();
            ui->listWidget->clear();
            ui->buttonBox->setStandardButtons(
                        ui->buttonBox->standardButtons()|
                        QDialogButtonBox::Save);
        }
    }
    else
        ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Reset);
}
CategoryValidator::CategoryValidator()
{

}

bool CategoryValidator::Validate(QMap<QString, QVariant> &)
{

}
