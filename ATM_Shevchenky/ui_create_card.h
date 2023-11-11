/********************************************************************************
** Form generated from reading UI file 'create_card.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_CARD_H
#define UI_CREATE_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "IntegerLineEdit.h"
#include "MoneyLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_CreateCard
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *createTransferLabel;
    QFormLayout *formLayout_3;
    QLabel *cardNumberLabel;
    IntegerLineEdit *cardNumberLineEdit;
    QLabel *pinCodeLabel;
    IntegerLineEdit *pinCodeLineEdit;
    QLabel *balanceLabel;
    MoneyLineEdit *balanceLineEdit;
    QLabel *expiryDateLabel;
    QDateEdit *expiryDateDayEdit;
    QFormLayout *formLayout;
    QPushButton *createButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *CreateCard)
    {
        if (CreateCard->objectName().isEmpty())
            CreateCard->setObjectName("CreateCard");
        CreateCard->resize(360, 270);
        horizontalLayout = new QHBoxLayout(CreateCard);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        createTransferLabel = new QLabel(CreateCard);
        createTransferLabel->setObjectName("createTransferLabel");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        createTransferLabel->setFont(font);
        createTransferLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(createTransferLabel);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        cardNumberLabel = new QLabel(CreateCard);
        cardNumberLabel->setObjectName("cardNumberLabel");
        QFont font1;
        font1.setPointSize(13);
        cardNumberLabel->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, cardNumberLabel);

        cardNumberLineEdit = new IntegerLineEdit(CreateCard);
        cardNumberLineEdit->setObjectName("cardNumberLineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cardNumberLineEdit->sizePolicy().hasHeightForWidth());
        cardNumberLineEdit->setSizePolicy(sizePolicy);
        cardNumberLineEdit->setFont(font1);
        cardNumberLineEdit->setMaxLength(16);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, cardNumberLineEdit);

        pinCodeLabel = new QLabel(CreateCard);
        pinCodeLabel->setObjectName("pinCodeLabel");
        pinCodeLabel->setFont(font1);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, pinCodeLabel);

        pinCodeLineEdit = new IntegerLineEdit(CreateCard);
        pinCodeLineEdit->setObjectName("pinCodeLineEdit");
        sizePolicy.setHeightForWidth(pinCodeLineEdit->sizePolicy().hasHeightForWidth());
        pinCodeLineEdit->setSizePolicy(sizePolicy);
        pinCodeLineEdit->setFont(font1);
        pinCodeLineEdit->setMaxLength(4);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, pinCodeLineEdit);

        balanceLabel = new QLabel(CreateCard);
        balanceLabel->setObjectName("balanceLabel");
        balanceLabel->setFont(font1);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, balanceLabel);

        balanceLineEdit = new MoneyLineEdit(CreateCard);
        balanceLineEdit->setObjectName("balanceLineEdit");
        sizePolicy.setHeightForWidth(balanceLineEdit->sizePolicy().hasHeightForWidth());
        balanceLineEdit->setSizePolicy(sizePolicy);
        balanceLineEdit->setFont(font1);
        balanceLineEdit->setMaxLength(13);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, balanceLineEdit);

        expiryDateLabel = new QLabel(CreateCard);
        expiryDateLabel->setObjectName("expiryDateLabel");
        expiryDateLabel->setFont(font1);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, expiryDateLabel);

        expiryDateDayEdit = new QDateEdit(CreateCard);
        expiryDateDayEdit->setObjectName("expiryDateDayEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(expiryDateDayEdit->sizePolicy().hasHeightForWidth());
        expiryDateDayEdit->setSizePolicy(sizePolicy1);
        expiryDateDayEdit->setFont(font1);
        expiryDateDayEdit->setProperty("showGroupSeparator", QVariant(false));
        expiryDateDayEdit->setCalendarPopup(true);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, expiryDateDayEdit);


        verticalLayout_2->addLayout(formLayout_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        createButton = new QPushButton(CreateCard);
        createButton->setObjectName("createButton");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(createButton->sizePolicy().hasHeightForWidth());
        createButton->setSizePolicy(sizePolicy2);
        createButton->setMinimumSize(QSize(160, 60));
        createButton->setFont(font);
        createButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        formLayout->setWidget(0, QFormLayout::LabelRole, createButton);

        cancelButton = new QPushButton(CreateCard);
        cancelButton->setObjectName("cancelButton");
        sizePolicy2.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy2);
        cancelButton->setMinimumSize(QSize(160, 60));
        cancelButton->setFont(font);
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cancelButton);


        verticalLayout_2->addLayout(formLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(CreateCard);

        QMetaObject::connectSlotsByName(CreateCard);
    } // setupUi

    void retranslateUi(QDialog *CreateCard)
    {
        CreateCard->setWindowTitle(QCoreApplication::translate("CreateCard", "Dialog", nullptr));
        createTransferLabel->setText(QCoreApplication::translate("CreateCard", "Create Card", nullptr));
        cardNumberLabel->setText(QCoreApplication::translate("CreateCard", "Card number:", nullptr));
        cardNumberLineEdit->setText(QCoreApplication::translate("CreateCard", "1234567890123456", nullptr));
        pinCodeLabel->setText(QCoreApplication::translate("CreateCard", "Pin code:", nullptr));
        balanceLabel->setText(QCoreApplication::translate("CreateCard", "Balance:", nullptr));
        expiryDateLabel->setText(QCoreApplication::translate("CreateCard", "Expiry date:", nullptr));
        createButton->setText(QCoreApplication::translate("CreateCard", "CREATE", nullptr));
        cancelButton->setText(QCoreApplication::translate("CreateCard", "CANCEL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateCard: public Ui_CreateCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_CARD_H
