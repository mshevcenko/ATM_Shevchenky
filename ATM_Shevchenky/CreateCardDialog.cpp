#include <QMessageBox>
#include <string>
#include <ctime>
#include "CreateCardDialog.h"
#include "ATM.h"
#include "autil.h"

CreateCardDialog::CreateCardDialog(ATM& atm, QWidget* parent) :
    QDialog(parent),
    _atm(atm)
{
    ui.setupUi(this);
    setWindowTitle("Crete card");
    connect(
        ui.createButton,
        &QPushButton::clicked,
        this,
        &CreateCardDialog::tryCreateCard);
    connect(
        ui.cancelButton,
        &QPushButton::clicked,
        this,
        &CreateCardDialog::close);
}

CreateCardDialog::~CreateCardDialog()
{}

void CreateCardDialog::updateData()
{
    ui.cardNumberLineEdit->setText("");
    ui.pinCodeLineEdit->setText("");
    ui.balanceLineEdit->setText("");
    ui.expiryDateDayEdit->setMinimumDateTime(QDateTime::fromSecsSinceEpoch(Toolbox::getCurrentDate()));
    ui.expiryDateDayEdit->setDateTime(QDateTime::fromSecsSinceEpoch(Toolbox::getCurrentDate()));
}

void CreateCardDialog::tryCreateCard()
{
    std::string cardNumber = ui.cardNumberLineEdit->text().toStdString();
    std::string pinCode = ui.pinCodeLineEdit->text().toStdString();
    double balance = ui.balanceLineEdit->text().replace(",", ".").toDouble();
    time_t expiryDate = ui.expiryDateDayEdit->dateTime().toSecsSinceEpoch();
    QMessageBox msgBox;
    msgBox.setWindowTitle("Create card");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    if (cardNumber.size() < 16)
    {
        msgBox.setText("The card number must consist of 16 characters!");
        msgBox.exec();
        return;
    }
    if (pinCode.size() < 4)
    {
        msgBox.setText("The pin code must consist of 4 characters!");
        msgBox.exec();
        return;
    }
    if (_atm.createCardAndAccount(cardNumber, pinCode, balance, expiryDate, _atm.bankId()))
    {
        msgBox.setText("Card was created successfully!");
        msgBox.exec();
        close();
    }
    else
    {
        msgBox.setText("Card wasn't created!");
        msgBox.exec();
    }
}