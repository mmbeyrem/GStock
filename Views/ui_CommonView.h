/********************************************************************************
** Form generated from reading UI file 'CommonView.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMONVIEW_H
#define UI_COMMONVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CommonView
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *Titre;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QPushButton *InsetB;
    QPushButton *UpdateB;
    QPushButton *DeleteB;
    QPushButton *ExportB;
    QPushButton *ImportB;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CommonView)
    {
        if (CommonView->objectName().isEmpty())
            CommonView->setObjectName(QStringLiteral("CommonView"));
        CommonView->resize(800, 600);
        verticalLayout_3 = new QVBoxLayout(CommonView);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        Titre = new QLabel(CommonView);
        Titre->setObjectName(QStringLiteral("Titre"));
        Titre->setMaximumSize(QSize(462, 13));
        Titre->setLayoutDirection(Qt::LeftToRight);
        Titre->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(Titre);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(CommonView);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        InsetB = new QPushButton(groupBox);
        InsetB->setObjectName(QStringLiteral("InsetB"));

        verticalLayout_6->addWidget(InsetB);

        UpdateB = new QPushButton(groupBox);
        UpdateB->setObjectName(QStringLiteral("UpdateB"));

        verticalLayout_6->addWidget(UpdateB);

        DeleteB = new QPushButton(groupBox);
        DeleteB->setObjectName(QStringLiteral("DeleteB"));

        verticalLayout_6->addWidget(DeleteB);

        ExportB = new QPushButton(groupBox);
        ExportB->setObjectName(QStringLiteral("ExportB"));

        verticalLayout_6->addWidget(ExportB);

        ImportB = new QPushButton(groupBox);
        ImportB->setObjectName(QStringLiteral("ImportB"));

        verticalLayout_6->addWidget(ImportB);


        verticalLayout_7->addLayout(verticalLayout_6);


        verticalLayout_2->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_2 = new QGroupBox(CommonView);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout_5->addWidget(groupBox_2);

        tableView = new QTableView(CommonView);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout_5->addWidget(tableView);


        horizontalLayout->addLayout(verticalLayout_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(CommonView);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(CommonView);
        QObject::connect(buttonBox, SIGNAL(accepted()), CommonView, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CommonView, SLOT(reject()));

        QMetaObject::connectSlotsByName(CommonView);
    } // setupUi

    void retranslateUi(QDialog *CommonView)
    {
        CommonView->setWindowTitle(QApplication::translate("CommonView", "Dialog", 0));
        Titre->setText(QApplication::translate("CommonView", "TextLabel", 0));
        groupBox->setTitle(QApplication::translate("CommonView", "GroupBox", 0));
        InsetB->setText(QApplication::translate("CommonView", "insert", 0));
        UpdateB->setText(QApplication::translate("CommonView", "update", 0));
        DeleteB->setText(QApplication::translate("CommonView", "delete", 0));
        ExportB->setText(QApplication::translate("CommonView", "Export csv", 0));
        ImportB->setText(QApplication::translate("CommonView", "Import csv", 0));
        groupBox_2->setTitle(QApplication::translate("CommonView", "GroupBox", 0));
    } // retranslateUi

};

namespace Ui {
    class CommonView: public Ui_CommonView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMONVIEW_H
