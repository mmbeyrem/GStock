#ifndef DIALOGCOMMONVIEW_H
#define DIALOGCOMMONVIEW_H


#include<QDialog>
#include"IModels.h"
#include "CommonEntityDiag.h"
namespace Ui {
class CommonView;
}

class CommonView : public QDialog
{
    Q_OBJECT

public:
    explicit CommonView(QString titre, QSqlDatabase &db, QWidget *parent = 0);
    ~CommonView();

private slots:
    void on_InsetB_clicked();

    void on_UpdateB_clicked();

    void on_DeleteB_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_ExportB_clicked();

    void on_ImportB_clicked();

private:
    Ui::CommonView *ui;
    IModels *Model;
    CommonEntityDiag *EntityDiag;
};

#endif // DIALOGCOMMONVIEW_H
