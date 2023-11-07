#include <QMessageBox>
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
    if (_atm.insertCard(
        ui.cardNumberLineEdit->text().toStdString(),
        ui.pinCodeLineEdit->text().toStdString()))
    {
        emit login();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Incorrect data");
        msgBox.setText("Incorrect card number or pin code!");
        msgBox.exec();
    }
}