#pragma once
#include <vector>
#include "ui_transfer_history.h"
#include "Transfer.h"
#include "WithdrawalService.h"

class ATM;

class TransferHistoryWidget : public QWidget
{

    Q_OBJECT

public:
    TransferHistoryWidget(ATM& atm, QWidget* parent = nullptr);
    ~TransferHistoryWidget();

    void updateData();

signals:
    void closed();

private:
    ATM& _atm;
    Ui_TransferHistory ui;
    std::vector<Transfer> _transfers;
    std::vector<WithdrawalService> _withdrawals;
    int _lastTransfer;
    int _lastWithdrawal;

    void loadMore();
};