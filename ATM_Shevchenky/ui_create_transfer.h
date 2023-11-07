/********************************************************************************
** Form generated from reading UI file 'create_transfer.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_TRANSFER_H
#define UI_CREATE_TRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ClickableLabel.h"
#include "IntegerLineEdit.h"
#include "MoneyLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_CreateTransfer
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QFormLayout *formLayout_4;
    QLabel *balanceLabel;
    MoneyLineEdit *balanceLineEdit;
    QLabel *creditLimitLabel;
    MoneyLineEdit *creditLimitLineEdit;
    QLabel *commissionLabel;
    QLineEdit *commissionLineEdit;
    QSpacerItem *horizontalSpacer_6;
    ClickableLabel *closeButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *createTransferLabel;
    QFormLayout *formLayout_3;
    QLabel *targetLabel;
    IntegerLineEdit *targetLineEdit;
    QLabel *ammountToBeSentLabel;
    MoneyLineEdit *ammountToBeSentLineEdit;
    QLabel *ammountToBeReceivedLabel;
    MoneyLineEdit *ammountToBeReceivedLineEdit;
    QPushButton *transferButton;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *CreateTransfer)
    {
        if (CreateTransfer->objectName().isEmpty())
            CreateTransfer->setObjectName("CreateTransfer");
        CreateTransfer->resize(561, 352);
        verticalLayout = new QVBoxLayout(CreateTransfer);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        balanceLabel = new QLabel(CreateTransfer);
        balanceLabel->setObjectName("balanceLabel");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        balanceLabel->setFont(font);
        balanceLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, balanceLabel);

        balanceLineEdit = new MoneyLineEdit(CreateTransfer);
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

        formLayout_4->setWidget(0, QFormLayout::FieldRole, balanceLineEdit);

        creditLimitLabel = new QLabel(CreateTransfer);
        creditLimitLabel->setObjectName("creditLimitLabel");
        creditLimitLabel->setFont(font);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, creditLimitLabel);

        creditLimitLineEdit = new MoneyLineEdit(CreateTransfer);
        creditLimitLineEdit->setObjectName("creditLimitLineEdit");
        sizePolicy.setHeightForWidth(creditLimitLineEdit->sizePolicy().hasHeightForWidth());
        creditLimitLineEdit->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(10);
        creditLimitLineEdit->setFont(font2);
        creditLimitLineEdit->setMaxLength(32765);
        creditLimitLineEdit->setReadOnly(true);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, creditLimitLineEdit);

        commissionLabel = new QLabel(CreateTransfer);
        commissionLabel->setObjectName("commissionLabel");
        commissionLabel->setFont(font);

        formLayout_4->setWidget(2, QFormLayout::LabelRole, commissionLabel);

        commissionLineEdit = new QLineEdit(CreateTransfer);
        commissionLineEdit->setObjectName("commissionLineEdit");
        sizePolicy.setHeightForWidth(commissionLineEdit->sizePolicy().hasHeightForWidth());
        commissionLineEdit->setSizePolicy(sizePolicy);
        commissionLineEdit->setFont(font2);
        commissionLineEdit->setMaxLength(32765);
        commissionLineEdit->setReadOnly(true);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, commissionLineEdit);


        horizontalLayout_4->addLayout(formLayout_4);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        closeButton = new ClickableLabel(CreateTransfer);
        closeButton->setObjectName("closeButton");
        closeButton->setMaximumSize(QSize(32, 32));
        closeButton->setBaseSize(QSize(32, 32));
        closeButton->setPixmap(QPixmap(QString::fromUtf8("assets/images/close-button.png")));
        closeButton->setScaledContents(true);

        horizontalLayout_4->addWidget(closeButton, 0, Qt::AlignTop);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        createTransferLabel = new QLabel(CreateTransfer);
        createTransferLabel->setObjectName("createTransferLabel");
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        createTransferLabel->setFont(font3);
        createTransferLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(createTransferLabel);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        targetLabel = new QLabel(CreateTransfer);
        targetLabel->setObjectName("targetLabel");
        QFont font4;
        font4.setPointSize(13);
        targetLabel->setFont(font4);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, targetLabel);

        targetLineEdit = new IntegerLineEdit(CreateTransfer);
        targetLineEdit->setObjectName("targetLineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(targetLineEdit->sizePolicy().hasHeightForWidth());
        targetLineEdit->setSizePolicy(sizePolicy1);
        targetLineEdit->setFont(font4);
        targetLineEdit->setMaxLength(16);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, targetLineEdit);

        ammountToBeSentLabel = new QLabel(CreateTransfer);
        ammountToBeSentLabel->setObjectName("ammountToBeSentLabel");
        ammountToBeSentLabel->setFont(font4);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, ammountToBeSentLabel);

        ammountToBeSentLineEdit = new MoneyLineEdit(CreateTransfer);
        ammountToBeSentLineEdit->setObjectName("ammountToBeSentLineEdit");
        sizePolicy1.setHeightForWidth(ammountToBeSentLineEdit->sizePolicy().hasHeightForWidth());
        ammountToBeSentLineEdit->setSizePolicy(sizePolicy1);
        ammountToBeSentLineEdit->setFont(font4);
        ammountToBeSentLineEdit->setMaxLength(13);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, ammountToBeSentLineEdit);

        ammountToBeReceivedLabel = new QLabel(CreateTransfer);
        ammountToBeReceivedLabel->setObjectName("ammountToBeReceivedLabel");
        ammountToBeReceivedLabel->setFont(font4);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, ammountToBeReceivedLabel);

        ammountToBeReceivedLineEdit = new MoneyLineEdit(CreateTransfer);
        ammountToBeReceivedLineEdit->setObjectName("ammountToBeReceivedLineEdit");
        sizePolicy1.setHeightForWidth(ammountToBeReceivedLineEdit->sizePolicy().hasHeightForWidth());
        ammountToBeReceivedLineEdit->setSizePolicy(sizePolicy1);
        ammountToBeReceivedLineEdit->setFont(font4);
        ammountToBeReceivedLineEdit->setMaxLength(13);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, ammountToBeReceivedLineEdit);


        verticalLayout_2->addLayout(formLayout_3);

        transferButton = new QPushButton(CreateTransfer);
        transferButton->setObjectName("transferButton");
        sizePolicy1.setHeightForWidth(transferButton->sizePolicy().hasHeightForWidth());
        transferButton->setSizePolicy(sizePolicy1);
        transferButton->setMinimumSize(QSize(160, 60));
        transferButton->setFont(font3);
        transferButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        verticalLayout_2->addWidget(transferButton, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(CreateTransfer);

        QMetaObject::connectSlotsByName(CreateTransfer);
    } // setupUi

    void retranslateUi(QWidget *CreateTransfer)
    {
        CreateTransfer->setWindowTitle(QCoreApplication::translate("CreateTransfer", "Form", nullptr));
        balanceLabel->setText(QCoreApplication::translate("CreateTransfer", "Balance:", nullptr));
        balanceLineEdit->setText(QCoreApplication::translate("CreateTransfer", "0", nullptr));
        creditLimitLabel->setText(QCoreApplication::translate("CreateTransfer", "Credit Limit:", nullptr));
        creditLimitLineEdit->setText(QCoreApplication::translate("CreateTransfer", "0", nullptr));
        commissionLabel->setText(QCoreApplication::translate("CreateTransfer", "Commission:", nullptr));
        commissionLineEdit->setText(QCoreApplication::translate("CreateTransfer", "0", nullptr));
        closeButton->setText(QString());
        createTransferLabel->setText(QCoreApplication::translate("CreateTransfer", "Create Transfer", nullptr));
        targetLabel->setText(QCoreApplication::translate("CreateTransfer", "Target:", nullptr));
        targetLineEdit->setText(QCoreApplication::translate("CreateTransfer", "1234567890123456", nullptr));
        ammountToBeSentLabel->setText(QCoreApplication::translate("CreateTransfer", "Ammount to be sent:", nullptr));
        ammountToBeReceivedLabel->setText(QCoreApplication::translate("CreateTransfer", "Ammount to be received:", nullptr));
        transferButton->setText(QCoreApplication::translate("CreateTransfer", "TRANSFER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateTransfer: public Ui_CreateTransfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_TRANSFER_H
