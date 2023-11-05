/********************************************************************************
** Form generated from reading UI file 'test_shadow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_SHADOW_H
#define UI_TEST_SHADOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShadowForm
{
public:
    QWidget *widget;

    void setupUi(QWidget *ShadowForm)
    {
        if (ShadowForm->objectName().isEmpty())
            ShadowForm->setObjectName("ShadowForm");
        ShadowForm->resize(404, 300);
        widget = new QWidget(ShadowForm);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(120, 100, 120, 80));

        retranslateUi(ShadowForm);

        QMetaObject::connectSlotsByName(ShadowForm);
    } // setupUi

    void retranslateUi(QWidget *ShadowForm)
    {
        ShadowForm->setWindowTitle(QCoreApplication::translate("ShadowForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShadowForm: public Ui_ShadowForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_SHADOW_H
