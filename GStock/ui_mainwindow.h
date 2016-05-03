/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QTableView *tableView_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        dockWidget = new QDockWidget(centralWidget);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setFloating(false);
        dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView_2 = new QTableView(dockWidgetContents_2);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));

        verticalLayout->addWidget(tableView_2);

        groupBox_3 = new QGroupBox(dockWidgetContents_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_8 = new QVBoxLayout(groupBox_3);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_3->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_3->addWidget(pushButton_6);


        verticalLayout_8->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(groupBox_3);


        verticalLayout_4->addLayout(verticalLayout);

        dockWidget->setWidget(dockWidgetContents_2);

        verticalLayout_2->addWidget(dockWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "tester", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "clear", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "follow", 0));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Services", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
