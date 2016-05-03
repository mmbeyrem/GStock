#include "CommonView.h"
#include "ui_CommonView.h"
#include"EntityDiagFactory.h"
#include "ModelFactory.h"
#include <QDebug>
#include<QSqlError>
#include<QFile>
#include<QDir>
#include<QFileDialog>
#include<QMessageBox>
#include<QDateTime>
CommonView::CommonView(QString titre,QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommonView)
{
    ui->setupUi(this);

    ui->Titre->setText(titre);
    this->Model = ModelFactory::Get(titre,db,this);
    ui->tableView->setModel(Model);
    ui->tableView->hideColumn(0);

    this->EntityDiag = EntityDiagFactory::Get(titre,this);
    connect(EntityDiag,SIGNAL(add(IEntities*)),Model,SLOT(Add(IEntities*)));
    connect(EntityDiag,SIGNAL(add(int ,IEntities*)),Model,SLOT(Update(int ,IEntities*)));
    connect(EntityDiag,SIGNAL(Remove(int)),Model,SLOT(Remove(int)));


    qCritical()<<"CommonView model :"<< this->Model->lastError();
}

CommonView::~CommonView()
{
    delete ui;
}

void CommonView::on_InsetB_clicked()
{
    EntityDiag->insert();
}

void CommonView::on_UpdateB_clicked()
{
    qInfo()<<"click on update";
    QItemSelectionModel *select = ui->tableView->selectionModel();
    if (select == nullptr)
        return;
    QModelIndexList selection = select->selectedRows();

    if(selection.count()>0)
    {
        QModelIndex index = selection.at(0);
        EntityDiag->update(index.row(),Model->Get(index.row()));
    }
}

void CommonView::on_DeleteB_clicked()
{
    qInfo()<<"click on Delete";
    QItemSelectionModel *select = ui->tableView->selectionModel();
    if (select == nullptr)
        return;
    QModelIndexList selection = select->selectedRows();
    if (select == nullptr)
        return;
    for(int i = 0 ; i< selection.count(); i++)
    {
        QModelIndex index = selection.at(i);
        EntityDiag->Delete(index.row());
    }
}

void CommonView::on_tableView_doubleClicked(const QModelIndex &index)
{
    qInfo()<<"doubleClicked on update";
    EntityDiag->update(index.row(),Model->Get(index.row()));
}

void CommonView::on_ExportB_clicked()
{
    qInfo()<<"Ask for data export";
    QList<IEntities*>* oIEntities = this->Model->GetAll();

    QString filePath = QFileDialog::getExistingDirectory(this);


    QFile oFile(filePath+ QDir::separator()+ui->Titre->text()+"-"+ QDateTime::currentDateTime().toString("yy-MM-dd")+".csv");
    qInfo()<<filePath+ QDir::separator()+ui->Titre->text()+"-"+ QDateTime::currentDateTime().toString("yy-MM-dd")+".csv";

    if (!oFile.open(QIODevice::WriteOnly))
    {
        qCritical()<< oFile.errorString();
        QMessageBox::warning(this,tr("Error"),tr("Error to Open OutPut File"));
        return;
    }
    foreach (IEntities* obj, *oIEntities) {
            qInfo()<<obj->tocsv();
            oFile.write(obj->tocsv().toStdString().c_str());
    }
    oFile.close();
    foreach (IEntities* obj, *oIEntities) {
           delete obj;
    }
    delete oIEntities;
}

void CommonView::on_ImportB_clicked()
{
      qInfo()<<"Ask for data import";
      QString fileName = QFileDialog::getOpenFileName(this);
      qDebug()<<fileName;
      QFile oFile (fileName);
      if (!oFile.open(QIODevice::ReadOnly))
      {
          qCritical()<< oFile.errorString();
          QMessageBox::warning(this,tr("Error"),tr("Error to Open Input File"));
          return;
      }
      while(!oFile.atEnd())
      {
          IEntities * obj = this->Model->CloneEntity();
          obj->fromcsv(oFile.readLine());
          this->Model->Add(obj);

          delete obj;
      }
}
