#pragma once
#include "ui_overflow_service.h"
#include "CheckPinCodeDialog.h"

class ATM;

class OverflowServiceWidget : public QWidget
{

    Q_OBJECT

public:
    OverflowServiceWidget(ATM& atm, QWidget* parent = nullptr);
    ~OverflowServiceWidget();

    void updateData();

signals:
    void closed();
    void logout();

private:
    ATM& _atm;
    Ui_OverflowService ui;
    CheckPinCodeDialog* _checkPinCodeDialog;

    void tryDeleteOverflowService();
    void tryCreateOverflowService();
};