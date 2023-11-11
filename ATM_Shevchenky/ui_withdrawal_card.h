/********************************************************************************
** Form generated from reading UI file 'withdrawal_card.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAWAL_CARD_H
#define UI_WITHDRAWAL_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WithdrawalCard
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *withdrawalImage;
    QLabel *ammountLabel;
    QLineEdit *ammountLineEdit;
    QLabel *dateLabel;
    QLineEdit *dateLineEdit;

    void setupUi(QWidget *WithdrawalCard)
    {
        if (WithdrawalCard->objectName().isEmpty())
            WithdrawalCard->setObjectName("WithdrawalCard");
        WithdrawalCard->resize(658, 58);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WithdrawalCard->sizePolicy().hasHeightForWidth());
        WithdrawalCard->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(WithdrawalCard);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(WithdrawalCard);
        widget->setObjectName("widget");
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8(".QWidget {\n"
"	background-color: white;\n"
"	border-radius: 10;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        withdrawalImage = new QLabel(widget);
        withdrawalImage->setObjectName("withdrawalImage");
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(withdrawalImage->sizePolicy().hasHeightForWidth());
        withdrawalImage->setSizePolicy(sizePolicy1);
        withdrawalImage->setMinimumSize(QSize(0, 0));
        withdrawalImage->setMaximumSize(QSize(40, 40));
        withdrawalImage->setSizeIncrement(QSize(0, 0));
        withdrawalImage->setStyleSheet(QString::fromUtf8("QLabel:hover {\n"
"	filter: brightness(50%);\n"
"}"));
        withdrawalImage->setPixmap(QPixmap(QString::fromUtf8("assets/images/withdraw.png")));
        withdrawalImage->setScaledContents(true);

        horizontalLayout->addWidget(withdrawalImage);

        ammountLabel = new QLabel(widget);
        ammountLabel->setObjectName("ammountLabel");
        QFont font;
        font.setPointSize(13);
        ammountLabel->setFont(font);

        horizontalLayout->addWidget(ammountLabel);

        ammountLineEdit = new QLineEdit(widget);
        ammountLineEdit->setObjectName("ammountLineEdit");
        ammountLineEdit->setMinimumSize(QSize(100, 0));
        ammountLineEdit->setFont(font);
        ammountLineEdit->setMaxLength(16);
        ammountLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(ammountLineEdit);

        dateLabel = new QLabel(widget);
        dateLabel->setObjectName("dateLabel");
        dateLabel->setFont(font);

        horizontalLayout->addWidget(dateLabel);

        dateLineEdit = new QLineEdit(widget);
        dateLineEdit->setObjectName("dateLineEdit");
        dateLineEdit->setFont(font);

        horizontalLayout->addWidget(dateLineEdit);


        horizontalLayout_2->addWidget(widget);


        retranslateUi(WithdrawalCard);

        QMetaObject::connectSlotsByName(WithdrawalCard);
    } // setupUi

    void retranslateUi(QWidget *WithdrawalCard)
    {
        WithdrawalCard->setWindowTitle(QCoreApplication::translate("WithdrawalCard", "Form", nullptr));
        withdrawalImage->setText(QString());
        ammountLabel->setText(QCoreApplication::translate("WithdrawalCard", "Amount:", nullptr));
        dateLabel->setText(QCoreApplication::translate("WithdrawalCard", "Date:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WithdrawalCard: public Ui_WithdrawalCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAWAL_CARD_H
