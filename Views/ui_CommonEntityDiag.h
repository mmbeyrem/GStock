/********************************************************************************
** Form generated from reading UI file 'CommonEntityDiag.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMONENTITYDIAG_H
#define UI_COMMONENTITYDIAG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CommonEntityDiag
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QSpacerItem *verticalSpacer;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CommonEntityDiag)
    {
        if (CommonEntityDiag->objectName().isEmpty())
            CommonEntityDiag->setObjectName(QStringLiteral("CommonEntityDiag"));
        CommonEntityDiag->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(CommonEntityDiag);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));

        verticalLayout_2->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        listWidget = new QListWidget(CommonEntityDiag);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        buttonBox = new QDialogButtonBox(CommonEntityDiag);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::Reset);
        buttonBox->setCenterButtons(false);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(CommonEntityDiag);
        QObject::connect(buttonBox, SIGNAL(accepted()), CommonEntityDiag, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CommonEntityDiag, SLOT(reject()));

        QMetaObject::connectSlotsByName(CommonEntityDiag);
    } // setupUi

    void retranslateUi(QDialog *CommonEntityDiag)
    {
        CommonEntityDiag->setWindowTitle(QApplication::translate("CommonEntityDiag", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class CommonEntityDiag: public Ui_CommonEntityDiag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMONENTITYDIAG_H
