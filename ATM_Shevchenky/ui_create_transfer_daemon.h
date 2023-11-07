/********************************************************************************
** Form generated from reading UI file 'create_transfer_daemon.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATE_TRANSFER_DAEMON_H
#define UI_CREATE_TRANSFER_DAEMON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ClickableLabel.h"
#include "IntegerLineEdit.h"
#include "MoneyLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_CreateTransferDaemon
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *balanceLabel;
    MoneyLineEdit *balanceLineEdit;
    QLabel *creditLimitLabel;
    MoneyLineEdit *creditLimitLineEdit;
    QLabel *commissionLabel;
    QLineEdit *commissionLineEdit;
    QSpacerItem *horizontalSpacer;
    ClickableLabel *closeButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *createTransferLabelDaemon;
    QFormLayout *formLayout_2;
    QLabel *targetLabel;
    IntegerLineEdit *targetLineEdit;
    QLabel *nextTransferDateLabel;
    QLabel *frequencyLabel;
    QSpinBox *frequencySpinBox;
    QLabel *ammountToBeSentLabel;
    MoneyLineEdit *ammountToBeSentLineEdit;
    QLabel *ammountToBeReceivedLabel;
    MoneyLineEdit *ammountToBeReceivedLineEdit;
    QDateEdit *nextTransferDayEdit;
    QCheckBox *activeCheckBox;
    QPushButton *createButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *CreateTransferDaemon)
    {
        if (CreateTransferDaemon->objectName().isEmpty())
            CreateTransferDaemon->setObjectName("CreateTransferDaemon");
        CreateTransferDaemon->resize(701, 504);
        verticalLayout_2 = new QVBoxLayout(CreateTransferDaemon);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        balanceLabel = new QLabel(CreateTransferDaemon);
        balanceLabel->setObjectName("balanceLabel");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        balanceLabel->setFont(font);
        balanceLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, balanceLabel);

        balanceLineEdit = new MoneyLineEdit(CreateTransferDaemon);
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

        creditLimitLabel = new QLabel(CreateTransferDaemon);
        creditLimitLabel->setObjectName("creditLimitLabel");
        creditLimitLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, creditLimitLabel);

        creditLimitLineEdit = new MoneyLineEdit(CreateTransferDaemon);
        creditLimitLineEdit->setObjectName("creditLimitLineEdit");
        sizePolicy.setHeightForWidth(creditLimitLineEdit->sizePolicy().hasHeightForWidth());
        creditLimitLineEdit->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(10);
        creditLimitLineEdit->setFont(font2);
        creditLimitLineEdit->setMaxLength(32765);
        creditLimitLineEdit->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, creditLimitLineEdit);

        commissionLabel = new QLabel(CreateTransferDaemon);
        commissionLabel->setObjectName("commissionLabel");
        commissionLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, commissionLabel);

        commissionLineEdit = new QLineEdit(CreateTransferDaemon);
        commissionLineEdit->setObjectName("commissionLineEdit");
        sizePolicy.setHeightForWidth(commissionLineEdit->sizePolicy().hasHeightForWidth());
        commissionLineEdit->setSizePolicy(sizePolicy);
        commissionLineEdit->setFont(font2);
        commissionLineEdit->setMaxLength(32765);
        commissionLineEdit->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, commissionLineEdit);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new ClickableLabel(CreateTransferDaemon);
        closeButton->setObjectName("closeButton");
        closeButton->setMaximumSize(QSize(32, 32));
        closeButton->setBaseSize(QSize(32, 32));
        closeButton->setPixmap(QPixmap(QString::fromUtf8("assets/images/close-button.png")));
        closeButton->setScaledContents(true);

        horizontalLayout->addWidget(closeButton, 0, Qt::AlignTop);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        createTransferLabelDaemon = new QLabel(CreateTransferDaemon);
        createTransferLabelDaemon->setObjectName("createTransferLabelDaemon");
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        createTransferLabelDaemon->setFont(font3);
        createTransferLabelDaemon->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(createTransferLabelDaemon);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        targetLabel = new QLabel(CreateTransferDaemon);
        targetLabel->setObjectName("targetLabel");
        QFont font4;
        font4.setPointSize(13);
        targetLabel->setFont(font4);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, targetLabel);

        targetLineEdit = new IntegerLineEdit(CreateTransferDaemon);
        targetLineEdit->setObjectName("targetLineEdit");
        targetLineEdit->setFont(font4);
        targetLineEdit->setMaxLength(16);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, targetLineEdit);

        nextTransferDateLabel = new QLabel(CreateTransferDaemon);
        nextTransferDateLabel->setObjectName("nextTransferDateLabel");
        nextTransferDateLabel->setFont(font4);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, nextTransferDateLabel);

        frequencyLabel = new QLabel(CreateTransferDaemon);
        frequencyLabel->setObjectName("frequencyLabel");
        frequencyLabel->setFont(font4);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, frequencyLabel);

        frequencySpinBox = new QSpinBox(CreateTransferDaemon);
        frequencySpinBox->setObjectName("frequencySpinBox");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frequencySpinBox->sizePolicy().hasHeightForWidth());
        frequencySpinBox->setSizePolicy(sizePolicy1);
        frequencySpinBox->setMinimumSize(QSize(0, 0));
        frequencySpinBox->setFont(font4);
        frequencySpinBox->setMinimum(1);
        frequencySpinBox->setMaximum(365);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, frequencySpinBox);

        ammountToBeSentLabel = new QLabel(CreateTransferDaemon);
        ammountToBeSentLabel->setObjectName("ammountToBeSentLabel");
        ammountToBeSentLabel->setFont(font4);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, ammountToBeSentLabel);

        ammountToBeSentLineEdit = new MoneyLineEdit(CreateTransferDaemon);
        ammountToBeSentLineEdit->setObjectName("ammountToBeSentLineEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ammountToBeSentLineEdit->sizePolicy().hasHeightForWidth());
        ammountToBeSentLineEdit->setSizePolicy(sizePolicy2);
        ammountToBeSentLineEdit->setFont(font4);
        ammountToBeSentLineEdit->setMaxLength(13);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, ammountToBeSentLineEdit);

        ammountToBeReceivedLabel = new QLabel(CreateTransferDaemon);
        ammountToBeReceivedLabel->setObjectName("ammountToBeReceivedLabel");
        ammountToBeReceivedLabel->setFont(font4);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, ammountToBeReceivedLabel);

        ammountToBeReceivedLineEdit = new MoneyLineEdit(CreateTransferDaemon);
        ammountToBeReceivedLineEdit->setObjectName("ammountToBeReceivedLineEdit");
        sizePolicy2.setHeightForWidth(ammountToBeReceivedLineEdit->sizePolicy().hasHeightForWidth());
        ammountToBeReceivedLineEdit->setSizePolicy(sizePolicy2);
        ammountToBeReceivedLineEdit->setFont(font4);
        ammountToBeReceivedLineEdit->setMaxLength(13);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, ammountToBeReceivedLineEdit);

        nextTransferDayEdit = new QDateEdit(CreateTransferDaemon);
        nextTransferDayEdit->setObjectName("nextTransferDayEdit");
        nextTransferDayEdit->setFont(font4);
        nextTransferDayEdit->setProperty("showGroupSeparator", QVariant(false));
        nextTransferDayEdit->setCalendarPopup(true);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, nextTransferDayEdit);


        verticalLayout->addLayout(formLayout_2);

        activeCheckBox = new QCheckBox(CreateTransferDaemon);
        activeCheckBox->setObjectName("activeCheckBox");
        sizePolicy2.setHeightForWidth(activeCheckBox->sizePolicy().hasHeightForWidth());
        activeCheckBox->setSizePolicy(sizePolicy2);
        activeCheckBox->setFont(font4);
        activeCheckBox->setChecked(true);

        verticalLayout->addWidget(activeCheckBox, 0, Qt::AlignHCenter);

        createButton = new QPushButton(CreateTransferDaemon);
        createButton->setObjectName("createButton");
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

        verticalLayout->addWidget(createButton, 0, Qt::AlignHCenter);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(CreateTransferDaemon);

        QMetaObject::connectSlotsByName(CreateTransferDaemon);
    } // setupUi

    void retranslateUi(QWidget *CreateTransferDaemon)
    {
        CreateTransferDaemon->setWindowTitle(QCoreApplication::translate("CreateTransferDaemon", "Form", nullptr));
        balanceLabel->setText(QCoreApplication::translate("CreateTransferDaemon", "Balance:", nullptr));
        balanceLineEdit->setText(QCoreApplication::translate("CreateTransferDaemon", "0", nullptr));
        creditLimitLabel->setText(QCoreApplication::translate("CreateTransferDaemon", "Credit Limit:", nullptr));
        creditLimitLineEdit->setText(QCoreApplication::translate("CreateTransferDaemon", "0", nullptr));
        commissionLabel->setText(QCoreApplication::translate("CreateTransferDaemon", "Commission:", nullptr));
        commissionLineEdit->setText(QCoreApplication::translate("CreateTransferDaemon", "0", nullptr));
        closeButton->setText(QString());
        createTransferLabelDaemon->setText(QCoreApplication::translate("CreateTransferDaemon", "Create Transfer Daemon", nullptr));
        targetLabel->setText(QCoreApplication::translate("CreateTransferDaemon", "Target:", nullptr));
        targetLineEdit->setText(QCoreApplication::translate("CreateTransferDaemon", "1234567890123456", nullptr));
        nextTransferDateLabel->setText(QCoreApplication::translate("CreateTransferDaemon", "Next Transfer Day:", nullptr));
        frequencyLabel->setText(QCoreApplication::translate("CreateTransferDaemon", "Frequency (days):", nullptr));
        ammountToBeSentLabel->setText(QCoreApplication::translate("CreateTransferDaemon", "Ammount to be sent:", nullptr));
        ammountToBeReceivedLabel->setText(QCoreApplication::translate("CreateTransferDaemon", "Ammount to be received:", nullptr));
        activeCheckBox->setText(QCoreApplication::translate("CreateTransferDaemon", "Active", nullptr));
        createButton->setText(QCoreApplication::translate("CreateTransferDaemon", "CREATE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateTransferDaemon: public Ui_CreateTransferDaemon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATE_TRANSFER_DAEMON_H
