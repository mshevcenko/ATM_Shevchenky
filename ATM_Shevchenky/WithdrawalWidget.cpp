#include <QRegularExpressionValidator>
#include <QMessageBox>
#include "WithdrawalWidget.h"
#include "ATM.h"

WithdrawalWidget::WithdrawalWidget(ATM& atm, QWidget* parent) :
    QWidget(parent),
    _atm(atm),
    _checkPinCodeDialog(new CheckPinCodeDialog(_atm, this))
{
    ui.setupUi(this);
    ui.ammountLineEdit->setValidator((new QRegularExpressionValidator(QRegularExpression("[1-9][0-9]*"), ui.ammountLineEdit)));
    connect(
        ui.closeButton,
        &ClickableLabel::clicked,
        this,
        &WithdrawalWidget::closed);
    connect(
        ui.withdrawButton,
        &QPushButton::clicked,
        this,
        &WithdrawalWidget::tryWithdraw);
}

WithdrawalWidget::~WithdrawalWidget()
{}

void WithdrawalWidget::updateData() 
{
    _atm.updateData();
    ui.balanceLineEdit->setText(QString::number(_atm.getBalance(), 'f', 2));
    ui.creditLimitLineEdit->setText(QString::number(_atm.getCreditLimit(), 'f', 2));
    ui.ammountLineEdit->setText("");
}

void WithdrawalWidget::tryWithdraw()
{
    _checkPinCodeDialog->updateData();
    int result = _checkPinCodeDialog->exec();
    if (result == QDialog::Rejected)
    {
        emit logout();
        return;
    }
    vector<pair<int, unsigned int>> money = _atm.withdraw(ui.ammountLineEdit->text().toInt());
    QMessageBox msgBox;
    msgBox.setWindowTitle("Withdrawal");
    if (money.size() > 0) {
        QString res = "You received:\n";
        for (int i = 0; i < money.size(); i++) {
            if (money[i].second == 0) continue;
            res += QString::number(money[i].first);
            res += " - ";
            res += QString::number(money[i].second);
            res += " pieces\n";
        }
        msgBox.setText(res);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        _atm.saveToDB();
        updateData();
    }
    else 
    {
        msgBox.setText("Can't withdraw!\nCheck your balance or ATM doesn't have enough money!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}