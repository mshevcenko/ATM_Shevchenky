#include <QMessageBox>
#include "LoginWidget.h"

LoginWidget::LoginWidget(QWidget* parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    connect(
        ui.enterButton, 
        &QPushButton::clicked, 
        this,
        &LoginWidget::tryLogin);
}

LoginWidget::~LoginWidget()
{}

void LoginWidget::tryLogin()
{
    if (ui.cardNumberLineEdit->text() == "1234567890123456"
        && ui.pinCodeLineEdit->text() == "1234")
    {
        emit login();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Incorrect data");
        msgBox.setText("Icorrect card number or pin code!");
        msgBox.exec();
    }
}