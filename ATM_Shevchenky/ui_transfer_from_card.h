/********************************************************************************
** Form generated from reading UI file 'transfer_from_card.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFER_FROM_CARD_H
#define UI_TRANSFER_FROM_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransferFromCard
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *fromImage;
    QLabel *fromLabel;
    QLineEdit *fromLineEdit;
    QLabel *ammountLabel;
    QLineEdit *ammountLineEdit;

    void setupUi(QWidget *TransferFromCard)
    {
        if (TransferFromCard->objectName().isEmpty())
            TransferFromCard->setObjectName("TransferFromCard");
        TransferFromCard->resize(813, 58);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TransferFromCard->sizePolicy().hasHeightForWidth());
        TransferFromCard->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(TransferFromCard);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(TransferFromCard);
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
        fromImage->setPixmap(QPixmap(QString::fromUtf8("assets/images/from.png")));
        fromImage->setScaledContents(true);

        horizontalLayout->addWidget(fromImage);

        fromLabel = new QLabel(widget);
        fromLabel->setObjectName("fromLabel");
        QFont font;
        font.setPointSize(13);
        fromLabel->setFont(font);

        horizontalLayout->addWidget(fromLabel);

        fromLineEdit = new QLineEdit(widget);
        fromLineEdit->setObjectName("fromLineEdit");
        fromLineEdit->setMinimumSize(QSize(155, 0));
        fromLineEdit->setFont(font);
        fromLineEdit->setMaxLength(16);
        fromLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(fromLineEdit);

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


        retranslateUi(TransferFromCard);

        QMetaObject::connectSlotsByName(TransferFromCard);
    } // setupUi

    void retranslateUi(QWidget *TransferFromCard)
    {
        TransferFromCard->setWindowTitle(QCoreApplication::translate("TransferFromCard", "Form", nullptr));
        fromImage->setText(QString());
        fromLabel->setText(QCoreApplication::translate("TransferFromCard", "From:", nullptr));
        fromLineEdit->setText(QCoreApplication::translate("TransferFromCard", "1234567890123456", nullptr));
        ammountLabel->setText(QCoreApplication::translate("TransferFromCard", "Ammount:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransferFromCard: public Ui_TransferFromCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFER_FROM_CARD_H
