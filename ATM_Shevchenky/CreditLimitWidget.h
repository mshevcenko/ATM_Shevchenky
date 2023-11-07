#pragma once
#include "ui_credit_limit.h"

class ATM;

class CreditLimitWidget : public QWidget
{

    Q_OBJECT

public:
    CreditLimitWidget(ATM& atm, QWidget* parent = nullptr);
    ~CreditLimitWidget();

    void updateData();

signals:
    void closed();

private:
    ATM& _atm;
    Ui_CreditLimit ui;

    void tryChangeCreditLimit();
};