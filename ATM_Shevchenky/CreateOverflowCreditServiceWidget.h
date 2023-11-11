#pragma once
#include "ui_create_overflow_credit_service.h"
#include "CheckPinCodeDialog.h"

class ATM;

class CreateOverflowCreditServiceWidget : public QWidget
{

    Q_OBJECT

public:
    CreateOverflowCreditServiceWidget(ATM& atm, QWidget* parent = nullptr);
    ~CreateOverflowCreditServiceWidget();

    void updateData();

signals:
    void closed();
    void logout();

private:
    Ui_CreateOverflowCreditService ui;
    ATM& _atm;
    CheckPinCodeDialog* _checkPinCodeDialog;

    void tryCreateOverflowCreditService();
};