#include <QMessageBox>
#include <string>
#include "LoginWidget.h"
#include "ATM.h"

LoginWidget::LoginWidget(ATM& atm, QWidget* parent):
    QWidget(parent),
    _atm(atm)
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

void LoginWidget::updateData()
{
    ui.cardNumberLineEdit->setText("");
    ui.pinCodeLineEdit->setText("");
}

void LoginWidget::tryLogin()
{
    std::string cardNumber = ui.cardNumberLineEdit->text().toStdString();
    std::string pinCode = ui.pinCodeLineEdit->text().toStdString();
    QMessageBox msgBox;
    msgBox.setWindowTitle("Login");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    if (_atm.isExpired(cardNumber))
    {
        msgBox.setText("Your card is expired!");
        msgBox.exec();
        return;
    }
    if (_atm.insertCard(
        cardNumber,
        pinCode))
    {
        emit login();
    }
    else
    {
        msgBox.setText("Incorrect card number or pin code!");
        msgBox.exec();
    }
}