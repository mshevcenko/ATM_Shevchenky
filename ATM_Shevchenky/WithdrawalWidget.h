#pragma once
#include "ui_withdrawal.h"
#include "CheckPinCodeDialog.h"

class ATM;

class WithdrawalWidget : public QWidget
{

    Q_OBJECT

public:
    WithdrawalWidget(ATM& atm, QWidget* parent = nullptr);
    ~WithdrawalWidget();

    void updateData();

signals:
    void closed();
    void logout();

private:
    ATM& _atm;
    Ui_Withdrawal ui;
    CheckPinCodeDialog* _checkPinCodeDialog;

    void tryWithdraw();
};