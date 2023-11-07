#include <QMessageBox>
#include "CreateTransferWidget.h"
#include "ATM.h"

CreateTransferWidget::CreateTransferWidget(ATM& atm, QWidget* parent) :
    QWidget(parent),
    _atm(atm)
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &CreateTransferWidget::closed);
    connect(
        ui.transferButton,
        &QPushButton::clicked,
        this,
        &CreateTransferWidget::tryTransfer);
    connect(
        ui.ammountToBeSentLineEdit,
        &MoneyLineEdit::textEdited,
        this,
        &CreateTransferWidget::setAmmountToBeReceived);
    connect(
        ui.ammountToBeReceivedLineEdit,
        &QLineEdit::textEdited,
        this,
        &CreateTransferWidget::setAmmountToBeSent);
}

CreateTransferWidget::~CreateTransferWidget()
{}

void CreateTransferWidget::updateData()
{
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
    ui.commissionLineEdit->setText(QString::number(_atm.getCommission() * 100) + "%");
    ui.ammountToBeReceivedLineEdit->setText("");
    ui.ammountToBeSentLineEdit->setText("");
    ui.targetLineEdit->setText("");
}

void CreateTransferWidget::tryTransfer()
{
    Transfer transfer(
        _atm.currentCardNumber(),
        ui.targetLineEdit->text().toStdString(),
        _atm.calculateFeeSend(ui.ammountToBeReceivedLineEdit->text().replace(",", ".").toDouble())
    );
    QMessageBox msgBox;
    msgBox.setWindowTitle("Transfer");
    if (_atm.createTransfer(transfer))
    {
        msgBox.setText("Transfer was created successfully!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        _atm.updateData();
        updateData();
    }
    else
    {
        msgBox.setText("Transfer wasn't created!");
        msgBox.setInformativeText("Target or ammount to be sent is incorrect!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}

void CreateTransferWidget::setAmmountToBeReceived(QString text)
{
    double feeReceived = _atm.calculateFeeReceived(text.replace(",", ".").toDouble());
    ui.ammountToBeReceivedLineEdit->setText(QString::number(feeReceived, 'f', 2));
}

void CreateTransferWidget::setAmmountToBeSent(QString text)
{
    double feeSent = _atm.calculateFeeSend(text.replace(",", ".").toDouble());
    ui.ammountToBeSentLineEdit->setText(QString::number(feeSent, 'f', 2));
}