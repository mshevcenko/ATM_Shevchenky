/********************************************************************************
** Form generated from reading UI file 'transfer_to_card.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFER_TO_CARD_H
#define UI_TRANSFER_TO_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransferToCard
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *fromImage;
    QLabel *toLabel;
    QLineEdit *toLineEdit;
    QLabel *ammountLabel;
    QLineEdit *ammountLineEdit;

    void setupUi(QWidget *TransferToCard)
    {
        if (TransferToCard->objectName().isEmpty())
            TransferToCard->setObjectName("TransferToCard");
        TransferToCard->resize(715, 62);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TransferToCard->sizePolicy().hasHeightForWidth());
        TransferToCard->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(TransferToCard);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(TransferToCard);
        widget->setObjectName("widget");
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8(".QWidget {\n"
"	background-color: white;\n"
"	border-radius: 10;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        fromImage = new QLabel(widget);
        fromImage->setObjectName("fromImage");
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fromImage->sizePolicy().hasHeightForWidth());
        fromImage->setSizePolicy(sizePolicy1);
        fromImage->setMinimumSize(QSize(0, 0));
        fromImage->setMaximumSize(QSize(40, 40));
        fromImage->setSizeIncrement(QSize(0, 0));
        fromImage->setStyleSheet(QString::fromUtf8("QLabel:hover {\n"
"	filter: brightness(50%);\n"
"}"));
        fromImage->setPixmap(QPixmap(QString::fromUtf8("assets/images/to.png")));
        fromImage->setScaledContents(true);

        horizontalLayout->addWidget(fromImage);

        toLabel = new QLabel(widget);
        toLabel->setObjectName("toLabel");
        QFont font;
        font.setPointSize(13);
        toLabel->setFont(font);

        horizontalLayout->addWidget(toLabel);

        toLineEdit = new QLineEdit(widget);
        toLineEdit->setObjectName("toLineEdit");
        toLineEdit->setMinimumSize(QSize(155, 0));
        toLineEdit->setFont(font);
        toLineEdit->setMaxLength(16);
        toLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(toLineEdit);

        ammountLabel = new QLabel(widget);
        ammountLabel->setObjectName("ammountLabel");
        ammountLabel->setFont(font);

        horizontalLayout->addWidget(ammountLabel);

        ammountLineEdit = new QLineEdit(widget);
        ammountLineEdit->setObjectName("ammountLineEdit");
        ammountLineEdit->setMinimumSize(QSize(100, 0));
        ammountLineEdit->setFont(font);
        ammountLineEdit->setMaxLength(16);
        ammountLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(ammountLineEdit);


        horizontalLayout_2->addWidget(widget);


        retranslateUi(TransferToCard);

        QMetaObject::connectSlotsByName(TransferToCard);
    } // setupUi

    void retranslateUi(QWidget *TransferToCard)
    {
        TransferToCard->setWindowTitle(QCoreApplication::translate("TransferToCard", "Form", nullptr));
        fromImage->setText(QString());
        toLabel->setText(QCoreApplication::translate("TransferToCard", "To:", nullptr));
        toLineEdit->setText(QCoreApplication::translate("TransferToCard", "1234567890123456", nullptr));
        ammountLabel->setText(QCoreApplication::translate("TransferToCard", "Ammount:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransferToCard: public Ui_TransferToCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFER_TO_CARD_H
