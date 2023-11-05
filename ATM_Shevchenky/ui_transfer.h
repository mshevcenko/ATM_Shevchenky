/********************************************************************************
** Form generated from reading UI file 'transfer.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFER_H
#define UI_TRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ClickableLabel.h"
#include "MoneyLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_Transfer
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *balanceLabel;
    MoneyLineEdit *balanceLineEdit;
    QLabel *creditLimitLabel;
    MoneyLineEdit *creditLimitLineEdit;
    QSpacerItem *horizontalSpacer;
    ClickableLabel *closeButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *createTransferButton;
    QPushButton *createTransferDaemonButton;
    QPushButton *transferDaemonsListButton;

    void setupUi(QWidget *Transfer)
    {
        if (Transfer->objectName().isEmpty())
            Transfer->setObjectName("Transfer");
        Transfer->resize(597, 416);
        verticalLayout = new QVBoxLayout(Transfer);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        balanceLabel = new QLabel(Transfer);
        balanceLabel->setObjectName("balanceLabel");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        balanceLabel->setFont(font);
        balanceLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, balanceLabel);

        balanceLineEdit = new MoneyLineEdit(Transfer);
        balanceLineEdit->setObjectName("balanceLineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(balanceLineEdit->sizePolicy().hasHeightForWidth());
        balanceLineEdit->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        font1.setKerning(true);
        balanceLineEdit->setFont(font1);
        balanceLineEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, balanceLineEdit);

        creditLimitLabel = new QLabel(Transfer);
        creditLimitLabel->setObjectName("creditLimitLabel");
        creditLimitLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, creditLimitLabel);

        creditLimitLineEdit = new MoneyLineEdit(Transfer);
        creditLimitLineEdit->setObjectName("creditLimitLineEdit");
        sizePolicy.setHeightForWidth(creditLimitLineEdit->sizePolicy().hasHeightForWidth());
        creditLimitLineEdit->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(10);
        creditLimitLineEdit->setFont(font2);
        creditLimitLineEdit->setMaxLength(32765);
        creditLimitLineEdit->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, creditLimitLineEdit);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new ClickableLabel(Transfer);
        closeButton->setObjectName("closeButton");
        closeButton->setMaximumSize(QSize(32, 32));
        closeButton->setBaseSize(QSize(32, 32));
        closeButton->setPixmap(QPixmap(QString::fromUtf8("assets/images/close-button.png")));
        closeButton->setScaledContents(true);

        horizontalLayout->addWidget(closeButton, 0, Qt::AlignTop);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(12);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        createTransferButton = new QPushButton(Transfer);
        createTransferButton->setObjectName("createTransferButton");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(createTransferButton->sizePolicy().hasHeightForWidth());
        createTransferButton->setSizePolicy(sizePolicy1);
        createTransferButton->setMinimumSize(QSize(120, 60));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        createTransferButton->setFont(font3);
        createTransferButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        horizontalLayout_2->addWidget(createTransferButton);

        createTransferDaemonButton = new QPushButton(Transfer);
        createTransferDaemonButton->setObjectName("createTransferDaemonButton");
        sizePolicy1.setHeightForWidth(createTransferDaemonButton->sizePolicy().hasHeightForWidth());
        createTransferDaemonButton->setSizePolicy(sizePolicy1);
        createTransferDaemonButton->setMinimumSize(QSize(120, 60));
        createTransferDaemonButton->setFont(font3);
        createTransferDaemonButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        horizontalLayout_2->addWidget(createTransferDaemonButton);

        transferDaemonsListButton = new QPushButton(Transfer);
        transferDaemonsListButton->setObjectName("transferDaemonsListButton");
        sizePolicy1.setHeightForWidth(transferDaemonsListButton->sizePolicy().hasHeightForWidth());
        transferDaemonsListButton->setSizePolicy(sizePolicy1);
        transferDaemonsListButton->setMinimumSize(QSize(120, 60));
        transferDaemonsListButton->setFont(font3);
        transferDaemonsListButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        horizontalLayout_2->addWidget(transferDaemonsListButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Transfer);

        QMetaObject::connectSlotsByName(Transfer);
    } // setupUi

    void retranslateUi(QWidget *Transfer)
    {
        Transfer->setWindowTitle(QCoreApplication::translate("Transfer", "Form", nullptr));
        balanceLabel->setText(QCoreApplication::translate("Transfer", "Balance:", nullptr));
        balanceLineEdit->setText(QCoreApplication::translate("Transfer", "0", nullptr));
        creditLimitLabel->setText(QCoreApplication::translate("Transfer", "Credit Limit:", nullptr));
        creditLimitLineEdit->setText(QCoreApplication::translate("Transfer", "0", nullptr));
        closeButton->setText(QString());
        createTransferButton->setText(QCoreApplication::translate("Transfer", "CREATE\n"
"TRANSFER", nullptr));
        createTransferDaemonButton->setText(QCoreApplication::translate("Transfer", "CREATE\n"
"TRANSFER\n"
"DAEMON", nullptr));
        transferDaemonsListButton->setText(QCoreApplication::translate("Transfer", "TRANSFER\n"
"DAEMONS\n"
"LIST", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transfer: public Ui_Transfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFER_H
