#pragma once
#include "ui_withdrawal.h"

class WithdrawalWidget : public QWidget
{

    Q_OBJECT

public:
    WithdrawalWidget(QWidget* parent = nullptr);
    ~WithdrawalWidget();

signals:
    void closed();

private:
    Ui_Withdrawal ui;
};