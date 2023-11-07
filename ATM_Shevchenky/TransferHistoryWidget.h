#pragma once
#include "ui_transfer_history.h"

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
};