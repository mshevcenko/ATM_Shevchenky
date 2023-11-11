/********************************************************************************
** Form generated from reading UI file 'check_pin_code.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECK_PIN_CODE_H
#define UI_CHECK_PIN_CODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "IntegerLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_CheckPinCode
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *pinCodeLabel;
    IntegerLineEdit *pinCodeLineEdit;
    QPushButton *enterButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *CheckPinCode)
    {
        if (CheckPinCode->objectName().isEmpty())
            CheckPinCode->setObjectName("CheckPinCode");
        CheckPinCode->resize(243, 194);
        horizontalLayout = new QHBoxLayout(CheckPinCode);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(39, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pinCodeLabel = new QLabel(CheckPinCode);
        pinCodeLabel->setObjectName("pinCodeLabel");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pinCodeLabel->sizePolicy().hasHeightForWidth());
        pinCodeLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        pinCodeLabel->setFont(font);

        verticalLayout->addWidget(pinCodeLabel, 0, Qt::AlignHCenter);

        pinCodeLineEdit = new IntegerLineEdit(CheckPinCode);
        pinCodeLineEdit->setObjectName("pinCodeLineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pinCodeLineEdit->sizePolicy().hasHeightForWidth());
        pinCodeLineEdit->setSizePolicy(sizePolicy1);
        pinCodeLineEdit->setMaximumSize(QSize(90, 16777215));
        pinCodeLineEdit->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(20);
        pinCodeLineEdit->setFont(font1);
        pinCodeLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: white;\n"
"}"));
        pinCodeLineEdit->setMaxLength(4);
        pinCodeLineEdit->setEchoMode(QLineEdit::Password);
        pinCodeLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(pinCodeLineEdit, 0, Qt::AlignHCenter);

        enterButton = new QPushButton(CheckPinCode);
        enterButton->setObjectName("enterButton");
        sizePolicy1.setHeightForWidth(enterButton->sizePolicy().hasHeightForWidth());
        enterButton->setSizePolicy(sizePolicy1);
        enterButton->setMinimumSize(QSize(120, 60));
        enterButton->setFont(font);
        enterButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(100, 100, 100);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));

        verticalLayout->addWidget(enterButton, 0, Qt::AlignHCenter);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(CheckPinCode);

        QMetaObject::connectSlotsByName(CheckPinCode);
    } // setupUi

    void retranslateUi(QDialog *CheckPinCode)
    {
        CheckPinCode->setWindowTitle(QCoreApplication::translate("CheckPinCode", "Dialog", nullptr));
        pinCodeLabel->setText(QCoreApplication::translate("CheckPinCode", "PIN CODE", nullptr));
        pinCodeLineEdit->setText(QCoreApplication::translate("CheckPinCode", "asdf", nullptr));
        enterButton->setText(QCoreApplication::translate("CheckPinCode", "ENTER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckPinCode: public Ui_CheckPinCode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECK_PIN_CODE_H
