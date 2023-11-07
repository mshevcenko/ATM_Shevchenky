/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MoneyLineEdit.h"
#include "ServiceOptionWidget.h"
#include "aspectratiopixmaplabel.h"

QT_BEGIN_NAMESPACE

class Ui_Main
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
    QGridLayout *gridLayout;
    ServiceOptionWidget *withdrawalFrame;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    AspectRatioPixmapLabel *withdrawalImage;
    QSpacerItem *verticalSpacer_2;
    QLabel *withdrawalLabel;
    ServiceOptionWidget *transferFrame;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    AspectRatioPixmapLabel *transferImage;
    QSpacerItem *verticalSpacer_4;
    QLabel *transferLabel;
    ServiceOptionWidget *transferHistoryFrame;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_5;
    AspectRatioPixmapLabel *transferHistoryImage;
    QSpacerItem *verticalSpacer_6;
    QLabel *transferHistoryLabel;
    ServiceOptionWidget *creditLimitFrame;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_8;
    AspectRatioPixmapLabel *creditLimitImage;
    QSpacerItem *verticalSpacer_7;
    QLabel *creditLimitLabel2;
    ServiceOptionWidget *overflowFrame;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_9;
    AspectRatioPixmapLabel *overflowImage;
    QSpacerItem *verticalSpacer_10;
    QLabel *overflowLabel;
    ServiceOptionWidget *pickupCardFrame;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_11;
    AspectRatioPixmapLabel *pickupCardImage;
    QSpacerItem *verticalSpacer_12;
    QLabel *pickupCardLabel;

    void setupUi(QWidget *Main)
    {
        if (Main->objectName().isEmpty())
            Main->setObjectName("Main");
        Main->resize(686, 602);
        Main->setMaximumSize(QSize(16777215, 16777215));
        Main->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(Main);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        balanceLabel = new QLabel(Main);
        balanceLabel->setObjectName("balanceLabel");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        balanceLabel->setFont(font);
        balanceLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, balanceLabel);

        balanceLineEdit = new MoneyLineEdit(Main);
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

        creditLimitLabel = new QLabel(Main);
        creditLimitLabel->setObjectName("creditLimitLabel");
        creditLimitLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, creditLimitLabel);

        creditLimitLineEdit = new MoneyLineEdit(Main);
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


        verticalLayout_2->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        withdrawalFrame = new ServiceOptionWidget(Main);
        withdrawalFrame->setObjectName("withdrawalFrame");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(withdrawalFrame->sizePolicy().hasHeightForWidth());
        withdrawalFrame->setSizePolicy(sizePolicy1);
        withdrawalFrame->setCursor(QCursor(Qt::ArrowCursor));
        withdrawalFrame->setTabletTracking(true);
        withdrawalFrame->setFocusPolicy(Qt::StrongFocus);
        withdrawalFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}"));
        withdrawalFrame->setFrameShape(QFrame::Panel);
        withdrawalFrame->setFrameShadow(QFrame::Sunken);
        withdrawalFrame->setLineWidth(10);
        verticalLayout = new QVBoxLayout(withdrawalFrame);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        withdrawalImage = new AspectRatioPixmapLabel(withdrawalFrame);
        withdrawalImage->setObjectName("withdrawalImage");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(withdrawalImage->sizePolicy().hasHeightForWidth());
        withdrawalImage->setSizePolicy(sizePolicy2);
        withdrawalImage->setMinimumSize(QSize(200, 200));
        withdrawalImage->setMaximumSize(QSize(200, 200));
        withdrawalImage->setBaseSize(QSize(0, 0));
        withdrawalImage->setStyleSheet(QString::fromUtf8("border-style: none;\n"
""));
        withdrawalImage->setPixmap(QPixmap(QString::fromUtf8("assets/images/withdraw.png")));
        withdrawalImage->setScaledContents(true);

        verticalLayout->addWidget(withdrawalImage, 0, Qt::AlignHCenter);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        withdrawalLabel = new QLabel(withdrawalFrame);
        withdrawalLabel->setObjectName("withdrawalLabel");
        sizePolicy2.setHeightForWidth(withdrawalLabel->sizePolicy().hasHeightForWidth());
        withdrawalLabel->setSizePolicy(sizePolicy2);
        withdrawalLabel->setFont(font);
        withdrawalLabel->setStyleSheet(QString::fromUtf8("border-style: none;"));
        withdrawalLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(withdrawalLabel);


        gridLayout->addWidget(withdrawalFrame, 0, 0, 1, 1);

        transferFrame = new ServiceOptionWidget(Main);
        transferFrame->setObjectName("transferFrame");
        sizePolicy1.setHeightForWidth(transferFrame->sizePolicy().hasHeightForWidth());
        transferFrame->setSizePolicy(sizePolicy1);
        transferFrame->setCursor(QCursor(Qt::ArrowCursor));
        transferFrame->setTabletTracking(true);
        transferFrame->setFocusPolicy(Qt::StrongFocus);
        transferFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}"));
        transferFrame->setFrameShape(QFrame::Panel);
        transferFrame->setFrameShadow(QFrame::Sunken);
        transferFrame->setLineWidth(10);
        verticalLayout_3 = new QVBoxLayout(transferFrame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        transferImage = new AspectRatioPixmapLabel(transferFrame);
        transferImage->setObjectName("transferImage");
        sizePolicy2.setHeightForWidth(transferImage->sizePolicy().hasHeightForWidth());
        transferImage->setSizePolicy(sizePolicy2);
        transferImage->setMinimumSize(QSize(200, 200));
        transferImage->setMaximumSize(QSize(200, 200));
        transferImage->setBaseSize(QSize(0, 0));
        transferImage->setStyleSheet(QString::fromUtf8("border: 1px solid white;"));
        transferImage->setPixmap(QPixmap(QString::fromUtf8("assets/images/transfer.png")));
        transferImage->setScaledContents(true);

        verticalLayout_3->addWidget(transferImage, 0, Qt::AlignHCenter);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        transferLabel = new QLabel(transferFrame);
        transferLabel->setObjectName("transferLabel");
        sizePolicy2.setHeightForWidth(transferLabel->sizePolicy().hasHeightForWidth());
        transferLabel->setSizePolicy(sizePolicy2);
        transferLabel->setFont(font);
        transferLabel->setStyleSheet(QString::fromUtf8("border-style: none;"));
        transferLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(transferLabel);


        gridLayout->addWidget(transferFrame, 0, 1, 1, 1);

        transferHistoryFrame = new ServiceOptionWidget(Main);
        transferHistoryFrame->setObjectName("transferHistoryFrame");
        sizePolicy1.setHeightForWidth(transferHistoryFrame->sizePolicy().hasHeightForWidth());
        transferHistoryFrame->setSizePolicy(sizePolicy1);
        transferHistoryFrame->setCursor(QCursor(Qt::ArrowCursor));
        transferHistoryFrame->setTabletTracking(true);
        transferHistoryFrame->setFocusPolicy(Qt::StrongFocus);
        transferHistoryFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}"));
        transferHistoryFrame->setFrameShape(QFrame::Panel);
        transferHistoryFrame->setFrameShadow(QFrame::Sunken);
        transferHistoryFrame->setLineWidth(10);
        verticalLayout_6 = new QVBoxLayout(transferHistoryFrame);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_5);

        transferHistoryImage = new AspectRatioPixmapLabel(transferHistoryFrame);
        transferHistoryImage->setObjectName("transferHistoryImage");
        sizePolicy2.setHeightForWidth(transferHistoryImage->sizePolicy().hasHeightForWidth());
        transferHistoryImage->setSizePolicy(sizePolicy2);
        transferHistoryImage->setMinimumSize(QSize(200, 200));
        transferHistoryImage->setMaximumSize(QSize(200, 200));
        transferHistoryImage->setBaseSize(QSize(0, 0));
        transferHistoryImage->setStyleSheet(QString::fromUtf8("border: 1px solid white;"));
        transferHistoryImage->setPixmap(QPixmap(QString::fromUtf8("assets/images/transaction-history.png")));
        transferHistoryImage->setScaledContents(true);

        verticalLayout_6->addWidget(transferHistoryImage, 0, Qt::AlignHCenter);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_6);

        transferHistoryLabel = new QLabel(transferHistoryFrame);
        transferHistoryLabel->setObjectName("transferHistoryLabel");
        sizePolicy2.setHeightForWidth(transferHistoryLabel->sizePolicy().hasHeightForWidth());
        transferHistoryLabel->setSizePolicy(sizePolicy2);
        transferHistoryLabel->setFont(font);
        transferHistoryLabel->setStyleSheet(QString::fromUtf8("border-style: none;"));
        transferHistoryLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(transferHistoryLabel);


        gridLayout->addWidget(transferHistoryFrame, 0, 2, 1, 1);

        creditLimitFrame = new ServiceOptionWidget(Main);
        creditLimitFrame->setObjectName("creditLimitFrame");
        sizePolicy1.setHeightForWidth(creditLimitFrame->sizePolicy().hasHeightForWidth());
        creditLimitFrame->setSizePolicy(sizePolicy1);
        creditLimitFrame->setCursor(QCursor(Qt::ArrowCursor));
        creditLimitFrame->setTabletTracking(true);
        creditLimitFrame->setFocusPolicy(Qt::StrongFocus);
        creditLimitFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}"));
        creditLimitFrame->setFrameShape(QFrame::Panel);
        creditLimitFrame->setFrameShadow(QFrame::Sunken);
        creditLimitFrame->setLineWidth(10);
        verticalLayout_4 = new QVBoxLayout(creditLimitFrame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_8);

        creditLimitImage = new AspectRatioPixmapLabel(creditLimitFrame);
        creditLimitImage->setObjectName("creditLimitImage");
        sizePolicy2.setHeightForWidth(creditLimitImage->sizePolicy().hasHeightForWidth());
        creditLimitImage->setSizePolicy(sizePolicy2);
        creditLimitImage->setMinimumSize(QSize(200, 200));
        creditLimitImage->setMaximumSize(QSize(200, 200));
        creditLimitImage->setBaseSize(QSize(0, 0));
        creditLimitImage->setStyleSheet(QString::fromUtf8("border: 1px solid white;"));
        creditLimitImage->setPixmap(QPixmap(QString::fromUtf8("assets/images/credit-limit.png")));
        creditLimitImage->setScaledContents(true);

        verticalLayout_4->addWidget(creditLimitImage, 0, Qt::AlignHCenter);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_7);

        creditLimitLabel2 = new QLabel(creditLimitFrame);
        creditLimitLabel2->setObjectName("creditLimitLabel2");
        sizePolicy2.setHeightForWidth(creditLimitLabel2->sizePolicy().hasHeightForWidth());
        creditLimitLabel2->setSizePolicy(sizePolicy2);
        creditLimitLabel2->setFont(font);
        creditLimitLabel2->setStyleSheet(QString::fromUtf8("border-style: none;"));
        creditLimitLabel2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(creditLimitLabel2);


        gridLayout->addWidget(creditLimitFrame, 1, 0, 1, 1);

        overflowFrame = new ServiceOptionWidget(Main);
        overflowFrame->setObjectName("overflowFrame");
        sizePolicy1.setHeightForWidth(overflowFrame->sizePolicy().hasHeightForWidth());
        overflowFrame->setSizePolicy(sizePolicy1);
        overflowFrame->setCursor(QCursor(Qt::ArrowCursor));
        overflowFrame->setTabletTracking(true);
        overflowFrame->setFocusPolicy(Qt::StrongFocus);
        overflowFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}"));
        overflowFrame->setFrameShape(QFrame::Panel);
        overflowFrame->setFrameShadow(QFrame::Sunken);
        overflowFrame->setLineWidth(10);
        verticalLayout_5 = new QVBoxLayout(overflowFrame);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_9);

        overflowImage = new AspectRatioPixmapLabel(overflowFrame);
        overflowImage->setObjectName("overflowImage");
        sizePolicy2.setHeightForWidth(overflowImage->sizePolicy().hasHeightForWidth());
        overflowImage->setSizePolicy(sizePolicy2);
        overflowImage->setMinimumSize(QSize(200, 200));
        overflowImage->setMaximumSize(QSize(200, 200));
        overflowImage->setBaseSize(QSize(0, 5));
        overflowImage->setStyleSheet(QString::fromUtf8("border: 1px solid white;"));
        overflowImage->setPixmap(QPixmap(QString::fromUtf8("assets/images/overflow.png")));
        overflowImage->setScaledContents(true);

        verticalLayout_5->addWidget(overflowImage, 0, Qt::AlignHCenter);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_10);

        overflowLabel = new QLabel(overflowFrame);
        overflowLabel->setObjectName("overflowLabel");
        sizePolicy2.setHeightForWidth(overflowLabel->sizePolicy().hasHeightForWidth());
        overflowLabel->setSizePolicy(sizePolicy2);
        overflowLabel->setFont(font);
        overflowLabel->setStyleSheet(QString::fromUtf8("border-style: none;"));
        overflowLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(overflowLabel);


        gridLayout->addWidget(overflowFrame, 1, 1, 1, 1);

        pickupCardFrame = new ServiceOptionWidget(Main);
        pickupCardFrame->setObjectName("pickupCardFrame");
        sizePolicy1.setHeightForWidth(pickupCardFrame->sizePolicy().hasHeightForWidth());
        pickupCardFrame->setSizePolicy(sizePolicy1);
        pickupCardFrame->setCursor(QCursor(Qt::ArrowCursor));
        pickupCardFrame->setTabletTracking(true);
        pickupCardFrame->setFocusPolicy(Qt::StrongFocus);
        pickupCardFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}"));
        pickupCardFrame->setFrameShape(QFrame::Panel);
        pickupCardFrame->setFrameShadow(QFrame::Sunken);
        pickupCardFrame->setLineWidth(10);
        verticalLayout_7 = new QVBoxLayout(pickupCardFrame);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_11);

        pickupCardImage = new AspectRatioPixmapLabel(pickupCardFrame);
        pickupCardImage->setObjectName("pickupCardImage");
        sizePolicy2.setHeightForWidth(pickupCardImage->sizePolicy().hasHeightForWidth());
        pickupCardImage->setSizePolicy(sizePolicy2);
        pickupCardImage->setMinimumSize(QSize(200, 200));
        pickupCardImage->setMaximumSize(QSize(200, 200));
        pickupCardImage->setBaseSize(QSize(0, 5));
        pickupCardImage->setStyleSheet(QString::fromUtf8("border: 1px solid white;"));
        pickupCardImage->setPixmap(QPixmap(QString::fromUtf8("assets/images/pickup-card.png")));
        pickupCardImage->setScaledContents(true);

        verticalLayout_7->addWidget(pickupCardImage, 0, Qt::AlignHCenter);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_12);

        pickupCardLabel = new QLabel(pickupCardFrame);
        pickupCardLabel->setObjectName("pickupCardLabel");
        sizePolicy2.setHeightForWidth(pickupCardLabel->sizePolicy().hasHeightForWidth());
        pickupCardLabel->setSizePolicy(sizePolicy2);
        pickupCardLabel->setFont(font);
        pickupCardLabel->setStyleSheet(QString::fromUtf8("border-style: none;"));
        pickupCardLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(pickupCardLabel);


        gridLayout->addWidget(pickupCardFrame, 1, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        retranslateUi(Main);

        QMetaObject::connectSlotsByName(Main);
    } // setupUi

    void retranslateUi(QWidget *Main)
    {
        Main->setWindowTitle(QCoreApplication::translate("Main", "Form", nullptr));
        balanceLabel->setText(QCoreApplication::translate("Main", "Balance:", nullptr));
        balanceLineEdit->setText(QCoreApplication::translate("Main", "0", nullptr));
        creditLimitLabel->setText(QCoreApplication::translate("Main", "Credit Limit:", nullptr));
        creditLimitLineEdit->setText(QCoreApplication::translate("Main", "0", nullptr));
        withdrawalImage->setText(QString());
        withdrawalLabel->setText(QCoreApplication::translate("Main", "Withdrawal", nullptr));
        transferImage->setText(QString());
        transferLabel->setText(QCoreApplication::translate("Main", "Transfer", nullptr));
        transferHistoryImage->setText(QString());
        transferHistoryLabel->setText(QCoreApplication::translate("Main", "Transfer History", nullptr));
        creditLimitImage->setText(QString());
        creditLimitLabel2->setText(QCoreApplication::translate("Main", "Credit Limit", nullptr));
        overflowImage->setText(QString());
        overflowLabel->setText(QCoreApplication::translate("Main", "Overflow", nullptr));
        pickupCardImage->setText(QString());
        pickupCardLabel->setText(QCoreApplication::translate("Main", "Pickup Card", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main: public Ui_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H
