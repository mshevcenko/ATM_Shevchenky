#include <QMessageBox>
#include "CreditLimitWidget.h"
#include "ATM.h"

CreditLimitWidget::CreditLimitWidget(ATM& atm, QWidget* parent) :
    QWidget(parent),
    _atm(atm),
    _checkPinCodeDialog(new CheckPinCodeDialog(_atm, this))
{
    ui.setupUi(this);
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &CreditLimitWidget::closed);
    connect(
        ui.changeButton,
        &QPushButton::clicked,
        this,
        &CreditLimitWidget::tryChangeCreditLimit);
}

CreditLimitWidget::~CreditLimitWidget()
{}

void CreditLimitWidget::updateData()
{
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
}

void CreditLimitWidget::tryChangeCreditLimit()
{
    _checkPinCodeDialog->updateData();
    int result = _checkPinCodeDialog->exec();
    if (result == QDialog::Rejected)
    {
        emit logout();
        return;
    }
    _atm.changeCreditLimit(ui.creditLimitLineEdit->text().toDouble());
    QMessageBox msgBox;
    msgBox.setWindowTitle("Credit limit");
    msgBox.setText("Credit limit changed successfully!");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}