#include "CommonEntityDiag.h"
#include "ui_commonentitydiag.h"
#include<QDebug>
#include<QLineEdit>


CommonEntityDiag::CommonEntityDiag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommonEntityDiag)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Reset|QDialogButtonBox::Save);
    connect(ui->buttonBox,SIGNAL(clicked(QAbstractButton*)),this,SLOT(clean(QAbstractButton*)));
}
void CommonEntityDiag::clean(QAbstractButton* oDemand)
{
     if (!QString::compare("Reset",oDemand->text()))
     {
          for (int i = 0; i < ui->formLayout->count(); ++i)
          {
              QWidget *widget = ui->formLayout->itemAt(i)->widget();
               if (dynamic_cast<QLineEdit*>(widget)!= nullptr && !dynamic_cast<QLineEdit*>(widget)->isReadOnly() )
               {
                    dynamic_cast<QLineEdit*>(widget)->clear();
               }
           }
         ui->listWidget->clear();
         ui->listWidget->hide();
     }
}
