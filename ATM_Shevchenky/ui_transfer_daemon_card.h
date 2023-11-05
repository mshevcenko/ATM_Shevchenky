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
    QLabel *nextTransferDateLabel;
    QLineEdit *lineEdit;
    QLabel *frequencyLabel;
    QLineEdit *lineEdit_2;
    QCheckBox *activeCheckBox;
    QLabel *label_2;

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
        nextTransferDateLabel = new QLabel(widget);
        nextTransferDateLabel->setObjectName("nextTransferDateLabel");
        nextTransferDateLabel->setFont(font);

        horizontalLayout_3->addWidget(nextTransferDateLabel);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(100, 0));
        lineEdit->setFont(font);
        lineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit);

        frequencyLabel = new QLabel(widget);
        frequencyLabel->setObjectName("frequencyLabel");
        frequencyLabel->setFont(font);

        horizontalLayout_3->addWidget(frequencyLabel);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(100, 0));
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QString::fromUtf8(""));
        lineEdit_2->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_2);


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

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(40, 40));
        label_2->setSizeIncrement(QSize(0, 0));
        label_2->setStyleSheet(QString::fromUtf8("QLabel:hover {\n"
"	filter: brightness(50%);\n"
"}"));
        label_2->setPixmap(QPixmap(QString::fromUtf8("assets/images/trash-bin.png")));
        label_2->setScaledContents(true);

        horizontalLayout->addWidget(label_2);


        horizontalLayout_4->addWidget(widget);


        retranslateUi(TransferDaemonCardWidgetClass);

        QMetaObject::connectSlotsByName(TransferDaemonCardWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *TransferDaemonCardWidgetClass)
    {
        TransferDaemonCardWidgetClass->setWindowTitle(QCoreApplication::translate("TransferDaemonCardWidgetClass", "TransferDaemonCardWidget", nullptr));
        targetLabel->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "Target:", nullptr));
        targetLineEdit->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "1234567890123456", nullptr));
        ammountLabel->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "Ammount:", nullptr));
        nextTransferDateLabel->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "Next Transfer Date:", nullptr));
        frequencyLabel->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "Frequency:", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "2132435647568764", nullptr));
        activeCheckBox->setText(QCoreApplication::translate("TransferDaemonCardWidgetClass", "Active", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TransferDaemonCardWidgetClass: public Ui_TransferDaemonCardWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFER_DAEMON_CARD_H
