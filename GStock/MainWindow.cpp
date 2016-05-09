#include "MainWindow.h"
#include "ui_mainwindow.h"
#include"CommonView.h"

#include<QDebug>
MainWindow::MainWindow(QSqlDatabase &db,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    UserLabel =new QLabel(this);
    ConnextionDate = new QLabel(this);
    DbName = new QLabel(db.databaseName(),this);
    ui->statusBar->addPermanentWidget(DbName);
    ui->statusBar->addPermanentWidget(UserLabel);
    ui->statusBar->addPermanentWidget(ConnextionDate);
    this->db = db;
    {
        CommonViews.append(new CommonView ("Category",db,this));
        oActions.append(ui->mainToolBar->addAction(tr("Category")));
        connect(oActions.last(), SIGNAL(triggered(bool)),CommonViews.last(),SLOT(show()));
    }
    {
        CommonViews.append(new CommonView ("Client",db,this));
        oActions.append(ui->mainToolBar->addAction(tr("Client")));
        connect(oActions.last(), SIGNAL(triggered(bool)),CommonViews.last(),SLOT(show()));
    }
}

MainWindow::~MainWindow()
{
    db.close();
    foreach (QAction *obj, oActions) {
       delete obj;
    }

    foreach (CommonView *obj, CommonViews) {
       if (obj != nullptr)
            delete obj;
    }

    delete ui;
    qDebug()<<"exiting done";
}
