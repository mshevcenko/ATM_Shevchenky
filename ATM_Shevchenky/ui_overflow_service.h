/********************************************************************************
** Form generated from reading UI file 'overflow_service.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERFLOW_SERVICE_H
#define UI_OVERFLOW_SERVICE_H

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

class Ui_OverflowService
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *balanceLabel;
    MoneyLineEdit *balanceLineEdit;
    QLabel *creditLimitLabel;
    MoneyLineEdit *creditLimitLineEdit;
    QSpacerItem *horizontalSpacer;
    ClickableLabel *closeButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QWidget *createOverflowServiceWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *createOverflowServiceLabel;
    QFormLayout *formLayout_3;
    QLabel *targetLabel1;
    IntegerLineEdit *targetLineEdit1;
    QLabel *thresholdLabel1;
    MoneyLineEdit *thresholdLineEdit1;
    QPushButton *createButton;
    QWidget *deleteOverflowServiceWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *overflowServiceLabel;
    QFormLayout *formLayout_4;
    QLabel *targetLabel2;
    IntegerLineEdit *targetLineEdit2;
    QLabel *thresholdLabel2;
    MoneyLineEdit *thresholdLineEdit2;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *OverflowService)
    {
        if (OverflowService->objectName().isEmpty())
            OverflowService->setObjectName("OverflowService");
        OverflowService->resize(595, 491);
        verticalLayout_4 = new QVBoxLayout(OverflowService);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        balanceLabel = new QLabel(OverflowService);
        balanceLabel->setObjectName("balanceLabel");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        balanceLabel->setFont(font);
        balanceLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, balanceLabel);

        balanceLineEdit = new MoneyLineEdit(OverflowService);
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

        creditLimitLabel = new QLabel(OverflowService);
        creditLimitLabel->setObjectName("creditLimitLabel");
        creditLimitLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, creditLimitLabel);

        creditLimitLineEdit = new MoneyLineEdit(OverflowService);
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

        closeButton = new ClickableLabel(OverflowService);
        closeButton->setObjectName("closeButton");
        closeButton->setMaximumSize(QSize(32, 32));
        closeButton->setBaseSize(QSize(32, 32));
        closeButton->setPixmap(QPixmap(QString::fromUtf8("assets/images/close-button.png")));
        closeButton->setScaledContents(true);

        horizontalLayout->addWidget(closeButton, 0, Qt::AlignTop);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        createOverflowServiceWidget = new QWidget(OverflowService);
        createOverflowServiceWidget->setObjectName("createOverflowServiceWidget");
        verticalLayout_2 = new QVBoxLayout(createOverflowServiceWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        createOverflowServiceLabel = new QLabel(createOverflowServiceWidget);
        createOverflowServiceLabel->setObjectName("createOverflowServiceLabel");
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        createOverflowServiceLabel->setFont(font3);
        createOverflowServiceLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(createOverflowServiceLabel);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        targetLabel1 = new QLabel(createOverflowServiceWidget);
        targetLabel1->setObjectName("targetLabel1");
        QFont font4;
        font4.setPointSize(13);
        targetLabel1->setFont(font4);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, targetLabel1);

        targetLineEdit1 = new IntegerLineEdit(createOverflowServiceWidget);
        targetLineEdit1->setObjectName("targetLineEdit1");
        targetLineEdit1->setMinimumSize(QSize(155, 0));
        targetLineEdit1->setFont(font4);
        targetLineEdit1->setMaxLength(16);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, targetLineEdit1);

        thresholdLabel1 = new QLabel(createOverflowServiceWidget);
        thresholdLabel1->setObjectName("thresholdLabel1");
        thresholdLabel1->setFont(font4);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, thresholdLabel1);

        thresholdLineEdit1 = new MoneyLineEdit(createOverflowServiceWidget);
        thresholdLineEdit1->setObjectName("thresholdLineEdit1");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(thresholdLineEdit1->sizePolicy().hasHeightForWidth());
        thresholdLineEdit1->setSizePolicy(sizePolicy1);
        thresholdLineEdit1->setFont(font4);
        thresholdLineEdit1->setMaxLength(16);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, thresholdLineEdit1);


        verticalLayout_2->addLayout(formLayout_3);

        createButton = new QPushButton(createOverflowServiceWidget);
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

        verticalLayout_2->addWidget(createButton, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(createOverflowServiceWidget);

        deleteOverflowServiceWidget = new QWidget(OverflowService);
        deleteOverflowServiceWidget->setObjectName("deleteOverflowServiceWidget");
        verticalLayout_3 = new QVBoxLayout(deleteOverflowServiceWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        overflowServiceLabel = new QLabel(deleteOverflowServiceWidget);
        overflowServiceLabel->setObjectName("overflowServiceLabel");
        overflowServiceLabel->setFont(font3);
        overflowServiceLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(overflowServiceLabel);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        targetLabel2 = new QLabel(deleteOverflowServiceWidget);
        targetLabel2->setObjectName("targetLabel2");
        targetLabel2->setFont(font4);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, targetLabel2);

        targetLineEdit2 = new IntegerLineEdit(deleteOverflowServiceWidget);
        targetLineEdit2->setObjectName("targetLineEdit2");
        targetLineEdit2->setMinimumSize(QSize(155, 0));
        targetLineEdit2->setFont(font4);
        targetLineEdit2->setMaxLength(16);
        targetLineEdit2->setReadOnly(true);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, targetLineEdit2);

        thresholdLabel2 = new QLabel(deleteOverflowServiceWidget);
        thresholdLabel2->setObjectName("thresholdLabel2");
        thresholdLabel2->setFont(font4);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, thresholdLabel2);

        thresholdLineEdit2 = new MoneyLineEdit(deleteOverflowServiceWidget);
        thresholdLineEdit2->setObjectName("thresholdLineEdit2");
        sizePolicy1.setHeightForWidth(thresholdLineEdit2->sizePolicy().hasHeightForWidth());
        thresholdLineEdit2->setSizePolicy(sizePolicy1);
        thresholdLineEdit2->setFont(font4);
        thresholdLineEdit2->setMaxLength(16);
        thresholdLineEdit2->setReadOnly(true);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, thresholdLineEdit2);


        verticalLayout_3->addLayout(formLayout_4);

        deleteButton = new QPushButton(deleteOverflowServiceWidget);
        deleteButton->setObjectName("deleteButton");
        sizePolicy2.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy2);
        deleteButton->setMinimumSize(QSize(160, 60));
        deleteButton->setFont(font3);
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        verticalLayout_3->addWidget(deleteButton, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(deleteOverflowServiceWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_2);


        retranslateUi(OverflowService);

        QMetaObject::connectSlotsByName(OverflowService);
    } // setupUi

    void retranslateUi(QWidget *OverflowService)
    {
        OverflowService->setWindowTitle(QCoreApplication::translate("OverflowService", "Form", nullptr));
        balanceLabel->setText(QCoreApplication::translate("OverflowService", "Balance:", nullptr));
        balanceLineEdit->setText(QCoreApplication::translate("OverflowService", "0", nullptr));
        creditLimitLabel->setText(QCoreApplication::translate("OverflowService", "Credit Limit:", nullptr));
        creditLimitLineEdit->setText(QCoreApplication::translate("OverflowService", "0", nullptr));
        closeButton->setText(QString());
        createOverflowServiceLabel->setText(QCoreApplication::translate("OverflowService", "Create Overflow Service", nullptr));
        targetLabel1->setText(QCoreApplication::translate("OverflowService", "Target:", nullptr));
        targetLineEdit1->setText(QCoreApplication::translate("OverflowService", "1234567890123456", nullptr));
        thresholdLabel1->setText(QCoreApplication::translate("OverflowService", "Threshold:", nullptr));
        createButton->setText(QCoreApplication::translate("OverflowService", "CREATE", nullptr));
        overflowServiceLabel->setText(QCoreApplication::translate("OverflowService", "Overflow Service", nullptr));
        targetLabel2->setText(QCoreApplication::translate("OverflowService", "Target:", nullptr));
        targetLineEdit2->setText(QCoreApplication::translate("OverflowService", "1234567890123456", nullptr));
        thresholdLabel2->setText(QCoreApplication::translate("OverflowService", "Threshold:", nullptr));
        deleteButton->setText(QCoreApplication::translate("OverflowService", "DELETE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OverflowService: public Ui_OverflowService {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERFLOW_SERVICE_H
