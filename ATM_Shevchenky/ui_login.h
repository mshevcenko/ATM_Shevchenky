/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "IntegerLineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *cardNumberLabel;
    IntegerLineEdit *cardNumberLineEdit;
    QLabel *pinCodeLabel;
    IntegerLineEdit *pinCodeLineEdit;
    QPushButton *enterButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(648, 432);
        Login->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(Login);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        cardNumberLabel = new QLabel(Login);
        cardNumberLabel->setObjectName("cardNumberLabel");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cardNumberLabel->sizePolicy().hasHeightForWidth());
        cardNumberLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        cardNumberLabel->setFont(font);

        verticalLayout->addWidget(cardNumberLabel, 0, Qt::AlignHCenter);

        cardNumberLineEdit = new IntegerLineEdit(Login);
        cardNumberLineEdit->setObjectName("cardNumberLineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cardNumberLineEdit->sizePolicy().hasHeightForWidth());
        cardNumberLineEdit->setSizePolicy(sizePolicy1);
        cardNumberLineEdit->setMinimumSize(QSize(250, 0));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(false);
        cardNumberLineEdit->setFont(font1);
        cardNumberLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: white;\n"
"}"));
        cardNumberLineEdit->setMaxLength(16);
        cardNumberLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(cardNumberLineEdit);

        pinCodeLabel = new QLabel(Login);
        pinCodeLabel->setObjectName("pinCodeLabel");
        sizePolicy.setHeightForWidth(pinCodeLabel->sizePolicy().hasHeightForWidth());
        pinCodeLabel->setSizePolicy(sizePolicy);
        pinCodeLabel->setFont(font);

        verticalLayout->addWidget(pinCodeLabel, 0, Qt::AlignHCenter);

        pinCodeLineEdit = new IntegerLineEdit(Login);
        pinCodeLineEdit->setObjectName("pinCodeLineEdit");
        sizePolicy1.setHeightForWidth(pinCodeLineEdit->sizePolicy().hasHeightForWidth());
        pinCodeLineEdit->setSizePolicy(sizePolicy1);
        pinCodeLineEdit->setMaximumSize(QSize(90, 16777215));
        pinCodeLineEdit->setBaseSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(20);
        pinCodeLineEdit->setFont(font2);
        pinCodeLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: white;\n"
"}"));
        pinCodeLineEdit->setMaxLength(4);
        pinCodeLineEdit->setEchoMode(QLineEdit::Password);
        pinCodeLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(pinCodeLineEdit, 0, Qt::AlignHCenter);

        enterButton = new QPushButton(Login);
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


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        cardNumberLabel->setText(QCoreApplication::translate("Login", "CARD NUMBER", nullptr));
        cardNumberLineEdit->setText(QCoreApplication::translate("Login", "1234567890123456", nullptr));
        pinCodeLabel->setText(QCoreApplication::translate("Login", "PIN CODE", nullptr));
        pinCodeLineEdit->setText(QCoreApplication::translate("Login", "asdf", nullptr));
        enterButton->setText(QCoreApplication::translate("Login", "ENTER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
