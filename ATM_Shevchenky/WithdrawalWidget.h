#pragma once
#include "ui_withdrawal.h"

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

private:
    ATM& _atm;
    Ui_Withdrawal ui;

    void tryWithdraw();
};