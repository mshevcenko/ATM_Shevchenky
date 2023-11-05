/********************************************************************************
** Form generated from reading UI file 'withdrawal.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAWAL_H
#define UI_WITHDRAWAL_H

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
#include "MoneyLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_Withdrawal
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QFormLayout *formLayout_4;
    QLabel *balanceLabel;
    MoneyLineEdit *balanceLineEdit;
    QLabel *creditLimitLabel;
    QLineEdit *creditLimitLineEdit;
    QSpacerItem *horizontalSpacer_6;
    ClickableLabel *closeButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *withdrawalLabel;
    QLineEdit *ammountLineEdit;
    QPushButton *withdrawButton;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *Withdrawal)
    {
        if (Withdrawal->objectName().isEmpty())
            Withdrawal->setObjectName("Withdrawal");
        Withdrawal->resize(604, 462);
        verticalLayout = new QVBoxLayout(Withdrawal);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        balanceLabel = new QLabel(Withdrawal);
        balanceLabel->setObjectName("balanceLabel");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        balanceLabel->setFont(font);
        balanceLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, balanceLabel);

        balanceLineEdit = new MoneyLineEdit(Withdrawal);
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

        creditLimitLabel = new QLabel(Withdrawal);
        creditLimitLabel->setObjectName("creditLimitLabel");
        creditLimitLabel->setFont(font);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, creditLimitLabel);

        creditLimitLineEdit = new QLineEdit(Withdrawal);
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

        closeButton = new ClickableLabel(Withdrawal);
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

        withdrawalLabel = new QLabel(Withdrawal);
        withdrawalLabel->setObjectName("withdrawalLabel");
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        withdrawalLabel->setFont(font3);
        withdrawalLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(withdrawalLabel);

        ammountLineEdit = new QLineEdit(Withdrawal);
        ammountLineEdit->setObjectName("ammountLineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ammountLineEdit->sizePolicy().hasHeightForWidth());
        ammountLineEdit->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setPointSize(20);
        ammountLineEdit->setFont(font4);
        ammountLineEdit->setMaxLength(6);
        ammountLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(ammountLineEdit);

        withdrawButton = new QPushButton(Withdrawal);
        withdrawButton->setObjectName("withdrawButton");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(withdrawButton->sizePolicy().hasHeightForWidth());
        withdrawButton->setSizePolicy(sizePolicy2);
        withdrawButton->setMinimumSize(QSize(190, 60));
        withdrawButton->setFont(font3);
        withdrawButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        verticalLayout_2->addWidget(withdrawButton, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Withdrawal);

        QMetaObject::connectSlotsByName(Withdrawal);
    } // setupUi

    void retranslateUi(QWidget *Withdrawal)
    {
        Withdrawal->setWindowTitle(QCoreApplication::translate("Withdrawal", "Form", nullptr));
        balanceLabel->setText(QCoreApplication::translate("Withdrawal", "Balance:", nullptr));
        balanceLineEdit->setText(QCoreApplication::translate("Withdrawal", "0", nullptr));
        creditLimitLabel->setText(QCoreApplication::translate("Withdrawal", "Credit Limit:", nullptr));
        creditLimitLineEdit->setText(QCoreApplication::translate("Withdrawal", "0", nullptr));
        closeButton->setText(QString());
        withdrawalLabel->setText(QCoreApplication::translate("Withdrawal", "Withdrawal", nullptr));
        withdrawButton->setText(QCoreApplication::translate("Withdrawal", "WITHDRAW", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Withdrawal: public Ui_Withdrawal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAWAL_H
