#pragma once
#include "ui_create_transfer.h"
#include "CheckPinCodeDialog.h"

class ATM;

class CreateTransferWidget : public QWidget
{

    Q_OBJECT

public:
    CreateTransferWidget(ATM& atm, QWidget* parent = nullptr);
    ~CreateTransferWidget();

    void updateData();

signals:
    void closed();
    void logout();

private slots:
    void setAmmountToBeReceived(QString text);
    void setAmmountToBeSent(QString text);

private:
    ATM& _atm;
    Ui_CreateTransfer ui;
    CheckPinCodeDialog* _checkPinCodeDialog;

    void tryTransfer();
};