/********************************************************************************
** Form generated from reading UI file 'DialogButtonRight.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGBUTTONRIGHT_H
#define UI_DIALOGBUTTONRIGHT_H

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

class Ui_Dialog
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
    IntegerLineEdit *pincCodeLineEdit;
    QLabel *balanceLabel;
    MoneyLineEdit *balanceLineEdit;
    QLabel *nextTransferDateLabel;
    QDateEdit *nextTransferDayEdit;
    QFormLayout *formLayout;
    QPushButton *createButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(360, 270);
        horizontalLayout = new QHBoxLayout(Dialog);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        createTransferLabel = new QLabel(Dialog);
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
        cardNumberLabel = new QLabel(Dialog);
        cardNumberLabel->setObjectName("cardNumberLabel");
        QFont font1;
        font1.setPointSize(13);
        cardNumberLabel->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, cardNumberLabel);

        cardNumberLineEdit = new IntegerLineEdit(Dialog);
        cardNumberLineEdit->setObjectName("cardNumberLineEdit");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cardNumberLineEdit->sizePolicy().hasHeightForWidth());
        cardNumberLineEdit->setSizePolicy(sizePolicy);
        cardNumberLineEdit->setFont(font1);
        cardNumberLineEdit->setMaxLength(16);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, cardNumberLineEdit);

        pinCodeLabel = new QLabel(Dialog);
        pinCodeLabel->setObjectName("pinCodeLabel");
        pinCodeLabel->setFont(font1);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, pinCodeLabel);

        pincCodeLineEdit = new IntegerLineEdit(Dialog);
        pincCodeLineEdit->setObjectName("pincCodeLineEdit");
        sizePolicy.setHeightForWidth(pincCodeLineEdit->sizePolicy().hasHeightForWidth());
        pincCodeLineEdit->setSizePolicy(sizePolicy);
        pincCodeLineEdit->setFont(font1);
        pincCodeLineEdit->setMaxLength(4);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, pincCodeLineEdit);

        balanceLabel = new QLabel(Dialog);
        balanceLabel->setObjectName("balanceLabel");
        balanceLabel->setFont(font1);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, balanceLabel);

        balanceLineEdit = new MoneyLineEdit(Dialog);
        balanceLineEdit->setObjectName("balanceLineEdit");
        sizePolicy.setHeightForWidth(balanceLineEdit->sizePolicy().hasHeightForWidth());
        balanceLineEdit->setSizePolicy(sizePolicy);
        balanceLineEdit->setFont(font1);
        balanceLineEdit->setMaxLength(13);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, balanceLineEdit);

        nextTransferDateLabel = new QLabel(Dialog);
        nextTransferDateLabel->setObjectName("nextTransferDateLabel");
        nextTransferDateLabel->setFont(font1);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, nextTransferDateLabel);

        nextTransferDayEdit = new QDateEdit(Dialog);
        nextTransferDayEdit->setObjectName("nextTransferDayEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nextTransferDayEdit->sizePolicy().hasHeightForWidth());
        nextTransferDayEdit->setSizePolicy(sizePolicy1);
        nextTransferDayEdit->setFont(font1);
        nextTransferDayEdit->setProperty("showGroupSeparator", QVariant(false));
        nextTransferDayEdit->setCalendarPopup(true);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, nextTransferDayEdit);


        verticalLayout_2->addLayout(formLayout_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        createButton = new QPushButton(Dialog);
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

        cancelButton = new QPushButton(Dialog);
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


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        createTransferLabel->setText(QCoreApplication::translate("Dialog", "Create Card", nullptr));
        cardNumberLabel->setText(QCoreApplication::translate("Dialog", "Card number:", nullptr));
        cardNumberLineEdit->setText(QCoreApplication::translate("Dialog", "1234567890123456", nullptr));
        pinCodeLabel->setText(QCoreApplication::translate("Dialog", "Pin code:", nullptr));
        balanceLabel->setText(QCoreApplication::translate("Dialog", "Balance:", nullptr));
        nextTransferDateLabel->setText(QCoreApplication::translate("Dialog", "Expiry date:", nullptr));
        createButton->setText(QCoreApplication::translate("Dialog", "CREATE", nullptr));
        cancelButton->setText(QCoreApplication::translate("Dialog", "CANCEL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBUTTONRIGHT_H
