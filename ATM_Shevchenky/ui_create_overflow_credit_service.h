/********************************************************************************
** Form generated from reading UI file 'create_overflow_credit_service.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_OVERFLOW_CREDIT_SERVICE_H
#define UI_CREATE_OVERFLOW_CREDIT_SERVICE_H

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
#include "IntegerLineEdit.h"
#include "MoneyLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_CreateOverflowCreditService
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QFormLayout *formLayout_4;
    QLabel *balanceLabel;
    MoneyLineEdit *balanceLineEdit;
    QLabel *creditLimitLabel;
    MoneyLineEdit *creditLimitLineEdit;
    QSpacerItem *horizontalSpacer_6;
    ClickableLabel *closeButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *createOverflowCreditServiceLabel;
    QFormLayout *formLayout_3;
    QLabel *targetLabel;
    IntegerLineEdit *targetLineEdit;
    QLabel *ammountToBeReceivedLabel;
    MoneyLineEdit *ammountToBeTriggeredLineEdit;
    QPushButton *createButton;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *CreateOverflowCreditService)
    {
        if (CreateOverflowCreditService->objectName().isEmpty())
            CreateOverflowCreditService->setObjectName("CreateOverflowCreditService");
        CreateOverflowCreditService->resize(509, 461);
        verticalLayout = new QVBoxLayout(CreateOverflowCreditService);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        balanceLabel = new QLabel(CreateOverflowCreditService);
        balanceLabel->setObjectName("balanceLabel");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        balanceLabel->setFont(font);
        balanceLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, balanceLabel);

        balanceLineEdit = new MoneyLineEdit(CreateOverflowCreditService);
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

        creditLimitLabel = new QLabel(CreateOverflowCreditService);
        creditLimitLabel->setObjectName("creditLimitLabel");
        creditLimitLabel->setFont(font);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, creditLimitLabel);

        creditLimitLineEdit = new MoneyLineEdit(CreateOverflowCreditService);
        creditLimitLineEdit->setObjectName("creditLimitLineEdit");
        sizePolicy.setHeightForWidth(creditLimitLineEdit->sizePolicy().hasHeightForWidth());
        creditLimitLineEdit->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(10);
        creditLimitLineEdit->setFont(font2);
        creditLimitLineEdit->setMaxLength(32765);
        creditLimitLineEdit->setReadOnly(true);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, creditLimitLineEdit);


        horizontalLayout_4->addLayout(formLayout_4);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        closeButton = new ClickableLabel(CreateOverflowCreditService);
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

        createOverflowCreditServiceLabel = new QLabel(CreateOverflowCreditService);
        createOverflowCreditServiceLabel->setObjectName("createOverflowCreditServiceLabel");
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        createOverflowCreditServiceLabel->setFont(font3);
        createOverflowCreditServiceLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(createOverflowCreditServiceLabel);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        targetLabel = new QLabel(CreateOverflowCreditService);
        targetLabel->setObjectName("targetLabel");
        QFont font4;
        font4.setPointSize(13);
        targetLabel->setFont(font4);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, targetLabel);

        targetLineEdit = new IntegerLineEdit(CreateOverflowCreditService);
        targetLineEdit->setObjectName("targetLineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(targetLineEdit->sizePolicy().hasHeightForWidth());
        targetLineEdit->setSizePolicy(sizePolicy1);
        targetLineEdit->setFont(font4);
        targetLineEdit->setMaxLength(16);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, targetLineEdit);

        ammountToBeReceivedLabel = new QLabel(CreateOverflowCreditService);
        ammountToBeReceivedLabel->setObjectName("ammountToBeReceivedLabel");
        ammountToBeReceivedLabel->setFont(font4);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, ammountToBeReceivedLabel);

        ammountToBeTriggeredLineEdit = new MoneyLineEdit(CreateOverflowCreditService);
        ammountToBeTriggeredLineEdit->setObjectName("ammountToBeTriggeredLineEdit");
        sizePolicy1.setHeightForWidth(ammountToBeTriggeredLineEdit->sizePolicy().hasHeightForWidth());
        ammountToBeTriggeredLineEdit->setSizePolicy(sizePolicy1);
        ammountToBeTriggeredLineEdit->setFont(font4);
        ammountToBeTriggeredLineEdit->setMaxLength(16);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, ammountToBeTriggeredLineEdit);


        verticalLayout_2->addLayout(formLayout_3);

        createButton = new QPushButton(CreateOverflowCreditService);
        createButton->setObjectName("createButton");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(createButton->sizePolicy().hasHeightForWidth());
        createButton->setSizePolicy(sizePolicy2);
        createButton->setMinimumSize(QSize(160, 60));
        createButton->setFont(font3);
        createButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        verticalLayout_2->addWidget(createButton, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(CreateOverflowCreditService);

        QMetaObject::connectSlotsByName(CreateOverflowCreditService);
    } // setupUi

    void retranslateUi(QWidget *CreateOverflowCreditService)
    {
        CreateOverflowCreditService->setWindowTitle(QCoreApplication::translate("CreateOverflowCreditService", "Form", nullptr));
        balanceLabel->setText(QCoreApplication::translate("CreateOverflowCreditService", "Balance:", nullptr));
        balanceLineEdit->setText(QCoreApplication::translate("CreateOverflowCreditService", "0", nullptr));
        creditLimitLabel->setText(QCoreApplication::translate("CreateOverflowCreditService", "Credit Limit:", nullptr));
        creditLimitLineEdit->setText(QCoreApplication::translate("CreateOverflowCreditService", "0", nullptr));
        closeButton->setText(QString());
#if QT_CONFIG(tooltip)
        createOverflowCreditServiceLabel->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        createOverflowCreditServiceLabel->setText(QCoreApplication::translate("CreateOverflowCreditService", "Create Overflow Credit Service", nullptr));
        targetLabel->setText(QCoreApplication::translate("CreateOverflowCreditService", "Target:", nullptr));
        targetLineEdit->setText(QCoreApplication::translate("CreateOverflowCreditService", "1234567890123456", nullptr));
        ammountToBeReceivedLabel->setText(QCoreApplication::translate("CreateOverflowCreditService", "Ammount to be triggered:", nullptr));
        createButton->setText(QCoreApplication::translate("CreateOverflowCreditService", "CREATE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateOverflowCreditService: public Ui_CreateOverflowCreditService {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_OVERFLOW_CREDIT_SERVICE_H
