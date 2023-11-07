#pragma once
#include "ui_create_overflow_credit_service.h"

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

private:
    Ui_CreateOverflowCreditService ui;
    ATM& _atm;

    void tryCreateOverflowCreditService();
};