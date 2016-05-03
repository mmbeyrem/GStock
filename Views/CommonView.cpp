#include "CommonView.h"
#include "ui_CommonView.h"
#include"EntityDiagFactory.h"
#include "ModelFactory.h"
#include <QDebug>
#include<QSqlError>
CommonView::CommonView(QString titre,QSqlDatabase &db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommonView)
{
    ui->setupUi(this);

    ui->Titre->setText(titre);
    this->Model = ModelFactory::Get(titre,db,this);
    ui->tableView->setModel(Model);
    ui->tableView->hideColumn(0);

    this->entity = EntityDiagFactory::Get(titre,this);
    connect(entity,SIGNAL(add(IEntities*)),Model,SLOT(Add(IEntities*)));
    connect(entity,SIGNAL(add(int ,IEntities*)),Model,SLOT(Update(int ,IEntities*)));
    connect(entity,SIGNAL(Remove(int)),Model,SLOT(Remove(int)));


    qCritical()<<"CommonView model :"<< this->Model->lastError();
}

CommonView::~CommonView()
{
    delete ui;
}

void CommonView::on_InsetB_clicked()
{
    entity->insert();
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
        entity->update(index.row(),Model->Get(index.row()));
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
        entity->Delete(index.row());
    }
}

void CommonView::on_tableView_doubleClicked(const QModelIndex &index)
{
    qInfo()<<"doubleClicked on update";
    entity->update(index.row(),Model->Get(index.row()));
}

void CommonView::on_ExportB_clicked()
{
    qInfo()<<"Ask for data export";
}

void CommonView::on_ImportB_clicked()
{
      qInfo()<<"Ask for data import";
}
