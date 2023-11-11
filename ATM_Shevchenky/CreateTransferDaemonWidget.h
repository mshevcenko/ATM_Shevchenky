#pragma once
#include "ui_create_transfer_daemon.h"
#include "CheckPinCodeDialog.h"

class ATM;

class CreateTransferDaemonWidget : public QWidget
{

    Q_OBJECT

public:
    CreateTransferDaemonWidget(ATM& atm, QWidget* parent = nullptr);
    ~CreateTransferDaemonWidget();

    void updateData();

signals:
    void closed();
    void logout();

private slots:
    void setAmmountToBeReceived(QString text);
    void setAmmountToBeSent(QString text);

private:
    ATM& _atm;
    Ui_CreateTransferDaemon ui;
    CheckPinCodeDialog* _checkPinCodeDialog;

    void tryCreateTransferDaemon();
};