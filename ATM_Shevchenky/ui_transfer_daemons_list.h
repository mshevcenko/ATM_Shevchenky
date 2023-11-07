/********************************************************************************
** Form generated from reading UI file 'transfer_daemons_list.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFER_DAEMONS_LIST_H
#define UI_TRANSFER_DAEMONS_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ClickableLabel.h"
#include "MoneyLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_TransferDaemonsList
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *balanceLabel;
    MoneyLineEdit *balanceLineEdit;
    QLabel *creditLimitLabel;
    MoneyLineEdit *creditLimitLineEdit;
    QSpacerItem *horizontalSpacer;
    ClickableLabel *closeButton;
    QLabel *transferDaemonsList;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *transferDaemonsListWidget;
    QVBoxLayout *transferDaemonsListLayout;
    QLabel *emptyLabel;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *TransferDaemonsList)
    {
        if (TransferDaemonsList->objectName().isEmpty())
            TransferDaemonsList->setObjectName("TransferDaemonsList");
        TransferDaemonsList->resize(710, 415);
        verticalLayout_2 = new QVBoxLayout(TransferDaemonsList);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        balanceLabel = new QLabel(TransferDaemonsList);
        balanceLabel->setObjectName("balanceLabel");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        balanceLabel->setFont(font);
        balanceLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, balanceLabel);

        balanceLineEdit = new MoneyLineEdit(TransferDaemonsList);
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

        creditLimitLabel = new QLabel(TransferDaemonsList);
        creditLimitLabel->setObjectName("creditLimitLabel");
        creditLimitLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, creditLimitLabel);

        creditLimitLineEdit = new MoneyLineEdit(TransferDaemonsList);
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

        closeButton = new ClickableLabel(TransferDaemonsList);
        closeButton->setObjectName("closeButton");
        closeButton->setMaximumSize(QSize(32, 32));
        closeButton->setBaseSize(QSize(32, 32));
        closeButton->setPixmap(QPixmap(QString::fromUtf8("assets/images/close-button.png")));
        closeButton->setScaledContents(true);

        horizontalLayout->addWidget(closeButton, 0, Qt::AlignTop);


        verticalLayout_2->addLayout(horizontalLayout);

        transferDaemonsList = new QLabel(TransferDaemonsList);
        transferDaemonsList->setObjectName("transferDaemonsList");
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(transferDaemonsList->sizePolicy().hasHeightForWidth());
        transferDaemonsList->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        transferDaemonsList->setFont(font3);

        verticalLayout_2->addWidget(transferDaemonsList, 0, Qt::AlignHCenter);

        scrollArea = new QScrollArea(TransferDaemonsList);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 692, 295));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        transferDaemonsListWidget = new QWidget(scrollAreaWidgetContents);
        transferDaemonsListWidget->setObjectName("transferDaemonsListWidget");
        transferDaemonsListLayout = new QVBoxLayout(transferDaemonsListWidget);
        transferDaemonsListLayout->setObjectName("transferDaemonsListLayout");
        transferDaemonsListLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(transferDaemonsListWidget);

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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        retranslateUi(TransferDaemonsList);

        QMetaObject::connectSlotsByName(TransferDaemonsList);
    } // setupUi

    void retranslateUi(QWidget *TransferDaemonsList)
    {
        TransferDaemonsList->setWindowTitle(QCoreApplication::translate("TransferDaemonsList", "Form", nullptr));
        balanceLabel->setText(QCoreApplication::translate("TransferDaemonsList", "Balance:", nullptr));
        balanceLineEdit->setText(QCoreApplication::translate("TransferDaemonsList", "0", nullptr));
        creditLimitLabel->setText(QCoreApplication::translate("TransferDaemonsList", "Credit Limit:", nullptr));
        creditLimitLineEdit->setText(QCoreApplication::translate("TransferDaemonsList", "0", nullptr));
        closeButton->setText(QString());
        transferDaemonsList->setText(QCoreApplication::translate("TransferDaemonsList", "Transfer Daemons List", nullptr));
        emptyLabel->setText(QCoreApplication::translate("TransferDaemonsList", "Empty", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransferDaemonsList: public Ui_TransferDaemonsList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFER_DAEMONS_LIST_H
