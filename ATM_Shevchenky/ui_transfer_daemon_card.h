/********************************************************************************
** Form generated from reading UI file 'transfer_daemon_card.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFER_DAEMON_CARD_H
#define UI_TRANSFER_DAEMON_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ClickableLabel.h"
#include "IntegerLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_TransferDaemonCardWidgetClass
{
public:
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *targetLabel;
    IntegerLineEdit *targetLineEdit;
    QLabel *ammountLabel;
    QLineEdit *ammountLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *nextTransferDayLabel;
    QLineEdit *nextTransferDayLineEdit;
    QLabel *frequencyLabel;
    QLineEdit *frequencyLineEdit;
    QCheckBox *activeCheckBox;
    ClickableLabel *deleteLabel;

    void setupUi(QWidget *TransferDaemonCardWidgetClass)
    {
        if (TransferDaemonCardWidgetClass->objectName().isEmpty())
            TransferDaemonCardWidgetClass->setObjectName("TransferDaemonCardWidgetClass");
        TransferDaemonCardWidgetClass->resize(621, 84);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TransferDaemonCardWidgetClass->sizePolicy().hasHeightForWidth());
        TransferDaemonCardWidgetClass->setSizePolicy(sizePolicy);
        TransferDaemonCardWidgetClass->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(TransferDaemonCardWidgetClass);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(TransferDaemonCardWidgetClass);
        widget->setObjectName("widget");
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8(".QWidget {\n"
"	background-color: white;\n"
"	border-radius: 10;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        targetLabel = new QLabel(widget);
        targetLabel->setObjectName("targetLabel");
        QFont font;
        font.setPointSize(13);
        targetLabel->setFont(font);

        horizontalLayout_2->addWidget(targetLabel);

        targetLineEdit = new IntegerLineEdit(widget);
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


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        nextTransferDayLabel = new QLabel(widget);
        nextTransferDayLabel->setObjectName("nextTransferDayLabel");
        nextTransferDayLabel->setFont(font);

        horizontalLayout_3->addWidget(nextTransferDayLabel);

        nextTransferDayLineEdit = new QLineEdit(widget);
        nextTransferDayLineEdit->setObjectName("nextTransferDayLineEdit");
        nextTransferDayLineEdit->setMinimumSize(QSize(100, 0));
        nextTransferDayLineEdit->setFont(font);
        nextTransferDayLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(nextTransferDayLineEdit);

        frequencyLabel = new QLabel(widget);
        frequencyLabel->setObjectName("frequencyLabel");
        frequencyLabel->setFont(font);

        horizontalLayout_3->addWidget(frequencyLabel);

        frequencyLineEdit = new QLineEdit(widget);
        frequencyLineEdit->setObjectName("frequencyLineEdit");
        frequencyLineEdit->setMinimumSize(QSize(100, 0));
        frequencyLineEdit->setFont(font);
        frequencyLineEdit->setStyleSheet(QString::fromUtf8(""));
        frequencyLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(frequencyLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        activeCheckBox = new QCheckBox(widget);
        activeCheckBox->setObjectName("activeCheckBox");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(activeCheckBox->sizePolicy().hasHeightForWidth());
        activeCheckBox->setSizePolicy(sizePolicy1);
        activeCheckBox->setMinimumSize(QSize(75, 0));
        activeCheckBox->setFont(font);
        activeCheckBox->setChecked(true);

        horizontalLayout->addWidget(activeCheckBox);

        deleteLabel = new ClickableLabel(widget);
        deleteLabel->setObjectName("deleteLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(deleteLabel->sizePolicy().hasHeightForWidth());
        deleteLabel->setSizePolicy(sizePolicy2);
        deleteLabel->setMinimumSize(QSize(0, 0));
        deleteLabel->setMaximumSize(QSize(40, 40));
        deleteLabel->setSizeIncrement(QSize(0, 0));
        deleteLabel->setStyleSheet(QString::fromUtf8("QLabel:hover {\n"
"	filter: brightness(50%);\n"
"}"));
        deleteLabel->setPixmap(QPixmap(QString::fromUtf8("assets/images/trash-bin.png")));
        deleteLabel->setScaledContents(true);

        horizontalLayout->addWidget(deleteLabel);


        horizontalLayout_4->addWidget(widget);


        retranslateUi(TransferDaemonCardWidgetClass);

        QMetaObject::connectSlotsByName(TransferDaemonCardWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *TransferDaemonCardWidgetClass)
    {
        TransferDaemonCardWidgetClass->setWindowTitle(QCoreApplication::translate("TransferDaemonCardWidgetClass", "TransferDaemonCardWidget", nullptr));
        targetLabel->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "Target:", nullptr));
        targetLineEdit->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "1234567890123456", nullptr));
        ammountLabel->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "Amount:", nullptr));
        nextTransferDayLabel->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "Next Transfer Day:", nullptr));
        frequencyLabel->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "Frequency:", nullptr));
        frequencyLineEdit->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "2132435647568764", nullptr));
        activeCheckBox->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "Active", nullptr));
        deleteLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TransferDaemonCardWidgetClass: public Ui_TransferDaemonCardWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFER_DAEMON_CARD_H
