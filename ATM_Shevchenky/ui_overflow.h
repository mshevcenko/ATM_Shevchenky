/********************************************************************************
** Form generated from reading UI file 'overflow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERFLOW_H
#define UI_OVERFLOW_H

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

class Ui_Overflow
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
    QPushButton *overflowServiceButton;
    QPushButton *createOverflowCreditServiceButton;
    QPushButton *overflowCreditServicesListButton;

    void setupUi(QWidget *Overflow)
    {
        if (Overflow->objectName().isEmpty())
            Overflow->setObjectName("Overflow");
        Overflow->resize(587, 436);
        verticalLayout = new QVBoxLayout(Overflow);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        balanceLabel = new QLabel(Overflow);
        balanceLabel->setObjectName("balanceLabel");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        balanceLabel->setFont(font);
        balanceLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, balanceLabel);

        balanceLineEdit = new MoneyLineEdit(Overflow);
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

        creditLimitLabel = new QLabel(Overflow);
        creditLimitLabel->setObjectName("creditLimitLabel");
        creditLimitLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, creditLimitLabel);

        creditLimitLineEdit = new MoneyLineEdit(Overflow);
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

        closeButton = new ClickableLabel(Overflow);
        closeButton->setObjectName("closeButton");
        closeButton->setMaximumSize(QSize(32, 32));
        closeButton->setBaseSize(QSize(32, 32));
        closeButton->setStyleSheet(QString::fromUtf8(""));
        closeButton->setPixmap(QPixmap(QString::fromUtf8("assets/images/close-button.png")));
        closeButton->setScaledContents(true);

        horizontalLayout->addWidget(closeButton, 0, Qt::AlignTop);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(12);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        overflowServiceButton = new QPushButton(Overflow);
        overflowServiceButton->setObjectName("overflowServiceButton");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(overflowServiceButton->sizePolicy().hasHeightForWidth());
        overflowServiceButton->setSizePolicy(sizePolicy1);
        overflowServiceButton->setMinimumSize(QSize(120, 60));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        overflowServiceButton->setFont(font3);
        overflowServiceButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        horizontalLayout_2->addWidget(overflowServiceButton);

        createOverflowCreditServiceButton = new QPushButton(Overflow);
        createOverflowCreditServiceButton->setObjectName("createOverflowCreditServiceButton");
        sizePolicy1.setHeightForWidth(createOverflowCreditServiceButton->sizePolicy().hasHeightForWidth());
        createOverflowCreditServiceButton->setSizePolicy(sizePolicy1);
        createOverflowCreditServiceButton->setMinimumSize(QSize(120, 60));
        createOverflowCreditServiceButton->setFont(font3);
        createOverflowCreditServiceButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        horizontalLayout_2->addWidget(createOverflowCreditServiceButton);

        overflowCreditServicesListButton = new QPushButton(Overflow);
        overflowCreditServicesListButton->setObjectName("overflowCreditServicesListButton");
        sizePolicy1.setHeightForWidth(overflowCreditServicesListButton->sizePolicy().hasHeightForWidth());
        overflowCreditServicesListButton->setSizePolicy(sizePolicy1);
        overflowCreditServicesListButton->setMinimumSize(QSize(120, 60));
        overflowCreditServicesListButton->setFont(font3);
        overflowCreditServicesListButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        horizontalLayout_2->addWidget(overflowCreditServicesListButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Overflow);

        QMetaObject::connectSlotsByName(Overflow);
    } // setupUi

    void retranslateUi(QWidget *Overflow)
    {
        Overflow->setWindowTitle(QCoreApplication::translate("Overflow", "Form", nullptr));
        balanceLabel->setText(QCoreApplication::translate("Overflow", "Balance:", nullptr));
        balanceLineEdit->setText(QCoreApplication::translate("Overflow", "0", nullptr));
        creditLimitLabel->setText(QCoreApplication::translate("Overflow", "Credit Limit:", nullptr));
        creditLimitLineEdit->setText(QCoreApplication::translate("Overflow", "0", nullptr));
        closeButton->setText(QString());
        overflowServiceButton->setText(QCoreApplication::translate("Overflow", "OVERFLOW\n"
"SERVICE", nullptr));
        createOverflowCreditServiceButton->setText(QCoreApplication::translate("Overflow", "CREATE\n"
"OVERFLOW\n"
"CREDIT\n"
"SERVICE", nullptr));
        overflowCreditServicesListButton->setText(QCoreApplication::translate("Overflow", "OVERFLOW\n"
"CREDIT\n"
"SERVICES\n"
"LIST", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Overflow: public Ui_Overflow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERFLOW_H
