/********************************************************************************
** Form generated from reading UI file 'transfer_history.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFER_HISTORY_H
#define UI_TRANSFER_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ClickableLabel.h"
#include "MoneyLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_TransferHistory
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QFormLayout *formLayout_4;
    QLabel *balanceLabel;
    MoneyLineEdit *balanceLineEdit;
    QLabel *creditLimitLabel;
    MoneyLineEdit *creditLimitLineEdit;
    QSpacerItem *horizontalSpacer_6;
    ClickableLabel *closeButton;
    QLabel *overflowCreditServicesListLabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *transferHistoryWidget;
    QVBoxLayout *transferHistoryLayout;
    QLabel *emptyLabel;
    QPushButton *moreButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *TransferHistory)
    {
        if (TransferHistory->objectName().isEmpty())
            TransferHistory->setObjectName("TransferHistory");
        TransferHistory->resize(623, 490);
        verticalLayout_2 = new QVBoxLayout(TransferHistory);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        balanceLabel = new QLabel(TransferHistory);
        balanceLabel->setObjectName("balanceLabel");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        balanceLabel->setFont(font);
        balanceLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, balanceLabel);

        balanceLineEdit = new MoneyLineEdit(TransferHistory);
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

        creditLimitLabel = new QLabel(TransferHistory);
        creditLimitLabel->setObjectName("creditLimitLabel");
        creditLimitLabel->setFont(font);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, creditLimitLabel);

        creditLimitLineEdit = new MoneyLineEdit(TransferHistory);
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

        closeButton = new ClickableLabel(TransferHistory);
        closeButton->setObjectName("closeButton");
        closeButton->setMaximumSize(QSize(32, 32));
        closeButton->setBaseSize(QSize(32, 32));
        closeButton->setPixmap(QPixmap(QString::fromUtf8("assets/images/close-button.png")));
        closeButton->setScaledContents(true);

        horizontalLayout_4->addWidget(closeButton, 0, Qt::AlignTop);


        verticalLayout_2->addLayout(horizontalLayout_4);

        overflowCreditServicesListLabel = new QLabel(TransferHistory);
        overflowCreditServicesListLabel->setObjectName("overflowCreditServicesListLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(overflowCreditServicesListLabel->sizePolicy().hasHeightForWidth());
        overflowCreditServicesListLabel->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        overflowCreditServicesListLabel->setFont(font3);

        verticalLayout_2->addWidget(overflowCreditServicesListLabel, 0, Qt::AlignHCenter);

        scrollArea = new QScrollArea(TransferHistory);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 605, 370));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        transferHistoryWidget = new QWidget(scrollAreaWidgetContents);
        transferHistoryWidget->setObjectName("transferHistoryWidget");
        transferHistoryLayout = new QVBoxLayout(transferHistoryWidget);
        transferHistoryLayout->setObjectName("transferHistoryLayout");
        transferHistoryLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(transferHistoryWidget);

        emptyLabel = new QLabel(scrollAreaWidgetContents);
        emptyLabel->setObjectName("emptyLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(emptyLabel->sizePolicy().hasHeightForWidth());
        emptyLabel->setSizePolicy(sizePolicy2);
        emptyLabel->setFont(font3);
        emptyLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(emptyLabel);

        moreButton = new QPushButton(scrollAreaWidgetContents);
        moreButton->setObjectName("moreButton");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(moreButton->sizePolicy().hasHeightForWidth());
        moreButton->setSizePolicy(sizePolicy3);
        moreButton->setMinimumSize(QSize(120, 60));
        moreButton->setFont(font3);
        moreButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        verticalLayout->addWidget(moreButton, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        retranslateUi(TransferHistory);

        QMetaObject::connectSlotsByName(TransferHistory);
    } // setupUi

    void retranslateUi(QWidget *TransferHistory)
    {
        TransferHistory->setWindowTitle(QCoreApplication::translate("TransferHistory", "Form", nullptr));
        balanceLabel->setText(QCoreApplication::translate("TransferHistory", "Balance:", nullptr));
        balanceLineEdit->setText(QCoreApplication::translate("TransferHistory", "0", nullptr));
        creditLimitLabel->setText(QCoreApplication::translate("TransferHistory", "Credit Limit:", nullptr));
        creditLimitLineEdit->setText(QCoreApplication::translate("TransferHistory", "0", nullptr));
        closeButton->setText(QString());
        overflowCreditServicesListLabel->setText(QCoreApplication::translate("TransferHistory", "Transfer History", nullptr));
        emptyLabel->setText(QCoreApplication::translate("TransferHistory", "Empty", nullptr));
        moreButton->setText(QCoreApplication::translate("TransferHistory", "MORE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransferHistory: public Ui_TransferHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFER_HISTORY_H
