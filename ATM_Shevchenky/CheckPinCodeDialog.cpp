#include <QMessageBox>
#include <string>
#include "CheckPinCodeDialog.h"
#include "ATM.h"

CheckPinCodeDialog::CheckPinCodeDialog(ATM& atm, QWidget* parent) :
    QDialog(parent),
    _atm(atm),
    _counter(0)
{
    ui.setupUi(this);
    setWindowTitle("Pin code");
    connect(
        ui.enterButton,
        &QPushButton::clicked,
        this,
        &CheckPinCodeDialog::checkPinCode);
}

CheckPinCodeDialog::~CheckPinCodeDialog()
{}

void CheckPinCodeDialog::updateData()
{
    ui.pinCodeLineEdit->setText("");
    _counter = 0;
}

void CheckPinCodeDialog::checkPinCode()
{
    std::string pinCode = ui.pinCodeLineEdit->text().toStdString();
    QMessageBox msgBox;
    if (_atm.checkPinCode(pinCode))
    {
        accept();
    }
    else
    {
        _counter++;
        msgBox.setWindowTitle("Pin code");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        QString message = "Pin code is incorrect!\n";
        message += QString::number(3 - _counter);
        message += " attempts left!";
        msgBox.setText(message);
        msgBox.exec();
        if (_counter == 3)
        {
            reject();
        }
    }
}