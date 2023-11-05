/********************************************************************************
** Form generated from reading UI file 'overflow_credit_service_card.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERFLOW_CREDIT_SERVICE_CARD_H
#define UI_OVERFLOW_CREDIT_SERVICE_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OverflowCreditServiceCard
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *targetLabel;
    QLineEdit *targetLineEdit;
    QLabel *ammountLabel;
    QLineEdit *ammountLineEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;

    void setupUi(QWidget *OverflowCreditServiceCard)
    {
        if (OverflowCreditServiceCard->objectName().isEmpty())
            OverflowCreditServiceCard->setObjectName("OverflowCreditServiceCard");
        OverflowCreditServiceCard->resize(696, 58);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OverflowCreditServiceCard->sizePolicy().hasHeightForWidth());
        OverflowCreditServiceCard->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(OverflowCreditServiceCard);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(OverflowCreditServiceCard);
        widget->setObjectName("widget");
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8(".QWidget {\n"
"	background-color: white;\n"
"	border-radius: 10;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        targetLabel = new QLabel(widget);
        targetLabel->setObjectName("targetLabel");
        QFont font;
        font.setPointSize(13);
        targetLabel->setFont(font);

        horizontalLayout_2->addWidget(targetLabel);

        targetLineEdit = new QLineEdit(widget);
        targetLineEdit->setObjectName("targetLineEdit");
        targetLineEdit->setMinimumSize(QSize(155, 0));
        targetLineEdit->setFont(font);
        targetLineEdit->setMaxLength(16);
        targetLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(targetLineEdit);

        ammountLabel = new QLabel(widget);
        ammountLabel->setObjectName("ammountLabel");
        ammountLabel->setFont(font);

        horizontalLayout_2->addWidget(ammountLabel);

        ammountLineEdit = new QLineEdit(widget);
        ammountLineEdit->setObjectName("ammountLineEdit");
        ammountLineEdit->setMinimumSize(QSize(100, 0));
        ammountLineEdit->setFont(font);
        ammountLineEdit->setMaxLength(16);
        ammountLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(ammountLineEdit);


        horizontalLayout->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(40, 40));
        label_2->setSizeIncrement(QSize(0, 0));
        label_2->setStyleSheet(QString::fromUtf8("QLabel:hover {\n"
"	filter: brightness(50%);\n"
"}"));
        label_2->setPixmap(QPixmap(QString::fromUtf8("assets/images/trash-bin.png")));
        label_2->setScaledContents(true);

        horizontalLayout->addWidget(label_2);


        horizontalLayout_3->addWidget(widget);


        retranslateUi(OverflowCreditServiceCard);

        QMetaObject::connectSlotsByName(OverflowCreditServiceCard);
    } // setupUi

    void retranslateUi(QWidget *OverflowCreditServiceCard)
    {
        OverflowCreditServiceCard->setWindowTitle(QCoreApplication::translate("OverflowCreditServiceCard", "Form", nullptr));
        targetLabel->setText(QCoreApplication::translate("OverflowCreditServiceCard", "Target:", nullptr));
        targetLineEdit->setText(QCoreApplication::translate("OverflowCreditServiceCard", "1234567890123456", nullptr));
        ammountLabel->setText(QCoreApplication::translate("OverflowCreditServiceCard", "Ammount:", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OverflowCreditServiceCard: public Ui_OverflowCreditServiceCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERFLOW_CREDIT_SERVICE_CARD_H
