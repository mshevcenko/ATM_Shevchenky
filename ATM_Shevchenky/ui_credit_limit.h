/********************************************************************************
** Form generated from reading UI file 'credit_limit.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_LIMIT_H
#define UI_CREDIT_LIMIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ClickableLabel.h"
#include "MoneyLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_CreditLimit
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *balanceLabel;
    MoneyLineEdit *balanceLineEdit;
    QSpacerItem *horizontalSpacer_6;
    ClickableLabel *closeButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *creditLimitLabel;
    MoneyLineEdit *creditLimitLineEdit;
    QPushButton *changeButton;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *CreditLimit)
    {
        if (CreditLimit->objectName().isEmpty())
            CreditLimit->setObjectName("CreditLimit");
        CreditLimit->resize(566, 469);
        verticalLayout = new QVBoxLayout(CreditLimit);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        balanceLabel = new QLabel(CreditLimit);
        balanceLabel->setObjectName("balanceLabel");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        balanceLabel->setFont(font);
        balanceLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(balanceLabel);

        balanceLineEdit = new MoneyLineEdit(CreditLimit);
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

        horizontalLayout->addWidget(balanceLineEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        closeButton = new ClickableLabel(CreditLimit);
        closeButton->setObjectName("closeButton");
        closeButton->setMaximumSize(QSize(32, 32));
        closeButton->setBaseSize(QSize(32, 32));
        closeButton->setPixmap(QPixmap(QString::fromUtf8("assets/images/close-button.png")));
        closeButton->setScaledContents(true);

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        creditLimitLabel = new QLabel(CreditLimit);
        creditLimitLabel->setObjectName("creditLimitLabel");
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        creditLimitLabel->setFont(font2);
        creditLimitLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(creditLimitLabel);

        creditLimitLineEdit = new MoneyLineEdit(CreditLimit);
        creditLimitLineEdit->setObjectName("creditLimitLineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(creditLimitLineEdit->sizePolicy().hasHeightForWidth());
        creditLimitLineEdit->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setPointSize(20);
        creditLimitLineEdit->setFont(font3);
        creditLimitLineEdit->setMaxLength(7);
        creditLimitLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(creditLimitLineEdit);

        changeButton = new QPushButton(CreditLimit);
        changeButton->setObjectName("changeButton");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(changeButton->sizePolicy().hasHeightForWidth());
        changeButton->setSizePolicy(sizePolicy2);
        changeButton->setMinimumSize(QSize(160, 60));
        changeButton->setFont(font2);
        changeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        verticalLayout_2->addWidget(changeButton, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(CreditLimit);

        QMetaObject::connectSlotsByName(CreditLimit);
    } // setupUi

    void retranslateUi(QWidget *CreditLimit)
    {
        CreditLimit->setWindowTitle(QCoreApplication::translate("CreditLimit", "Form", nullptr));
        balanceLabel->setText(QCoreApplication::translate("CreditLimit", "Balance:", nullptr));
        balanceLineEdit->setText(QCoreApplication::translate("CreditLimit", "0", nullptr));
        closeButton->setText(QString());
        creditLimitLabel->setText(QCoreApplication::translate("CreditLimit", "Credit Limit", nullptr));
        changeButton->setText(QCoreApplication::translate("CreditLimit", "CHANGE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreditLimit: public Ui_CreditLimit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_LIMIT_H
