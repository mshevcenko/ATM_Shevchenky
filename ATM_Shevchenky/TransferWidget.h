#pragma once
#include "ui_transfer.h"

class ATM;

class TransferWidget : public QWidget
{

    Q_OBJECT

public:
    TransferWidget(ATM& atm, QWidget* parent = nullptr);
    ~TransferWidget();

    void updateData();

signals:
    void createTransfer();
    void createTransferDaemon();
    void transferDaemonsList();
    void closed();

private:
    ATM& _atm;
    Ui_Transfer ui;
};