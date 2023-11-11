#include <QMessageBox>
#include "CreateTransferDaemonWidget.h"
#include "ATM.h"
#include "autil.h"

CreateTransferDaemonWidget::CreateTransferDaemonWidget(ATM& atm, QWidget* parent) :
    QWidget(parent),
    _atm(atm),
    _checkPinCodeDialog(new CheckPinCodeDialog(_atm, this))
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &CreateTransferDaemonWidget::closed);
    connect(
        ui.createButton,
        &QPushButton::clicked,
        this,
        &CreateTransferDaemonWidget::tryCreateTransferDaemon);
    connect(
        ui.ammountToBeSentLineEdit,
        &MoneyLineEdit::textEdited,
        this,
        &CreateTransferDaemonWidget::setAmmountToBeReceived);
    connect(
        ui.ammountToBeReceivedLineEdit,
        &QLineEdit::textEdited,
        this,
        &CreateTransferDaemonWidget::setAmmountToBeSent);
}

CreateTransferDaemonWidget::~CreateTransferDaemonWidget()
{}

void CreateTransferDaemonWidget::updateData()
{
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
    ui.commissionLineEdit->setText(QString::number(_atm.getCommission() * 100) + "%");
    ui.ammountToBeReceivedLineEdit->setText("");
    ui.ammountToBeSentLineEdit->setText("");
    ui.targetLineEdit->setText("");
    ui.nextTransferDayEdit->setMinimumDateTime(QDateTime::fromSecsSinceEpoch(Toolbox::getCurrentDate()));
    ui.nextTransferDayEdit->setDateTime(QDateTime::fromSecsSinceEpoch(Toolbox::getCurrentDate()));
    ui.frequencySpinBox->setValue(1);
    ui.activeCheckBox->setChecked(true);
}

void CreateTransferDaemonWidget::tryCreateTransferDaemon()
{
    _checkPinCodeDialog->updateData();
    int result = _checkPinCodeDialog->exec();
    if (result == QDialog::Rejected)
    {
        emit logout();
        return;
    }
    TransferDaemon transfer(
        _atm.currentCardNumber(),
        ui.targetLineEdit->text().toStdString(),
        _atm.calculateFeeSend(ui.ammountToBeReceivedLineEdit->text().replace(",", ".").toDouble()),
        ui.nextTransferDayEdit->dateTime().toMSecsSinceEpoch(),
        ui.frequencySpinBox->value() * Toolbox::getOneDay(),
        ui.activeCheckBox->isChecked()
    );
    QMessageBox msgBox;
    msgBox.setWindowTitle("Transfer Daemon");
    if (_atm.createTransferDaemon(transfer))
    {
        msgBox.setText("Transfer daemon was created successfully!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        _atm.updateData();
        updateData();
    }
    else
    {
        msgBox.setText("Transfer daemon wasn't created!");
        msgBox.setInformativeText("Target or ammount to be sent is incorrect!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}

void CreateTransferDaemonWidget::setAmmountToBeReceived(QString text)
{
    double feeReceived = _atm.calculateFeeReceived(text.replace(",", ".").toDouble());
    ui.ammountToBeReceivedLineEdit->setText(QString::number(feeReceived, 'f', 2));
}

void CreateTransferDaemonWidget::setAmmountToBeSent(QString text)
{
    double feeSent = _atm.calculateFeeSend(text.replace(",", ".").toDouble());
    ui.ammountToBeSentLineEdit->setText(QString::number(feeSent, 'f', 2));
}