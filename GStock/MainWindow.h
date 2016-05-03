#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QSqlDatabase>
#include"CommonView.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QSqlDatabase &db, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *UserLabel;
    QLabel *ConnextionDate;
    QLabel*DbName;
    QSqlDatabase db;
    QList<CommonView*>CommonViews;
    QList<QAction*>oActions;
};

#endif // MAINWINDOW_H
