#pragma once
#include "ui_transfer_daemons_list.h"
#include "TransferDaemonCardWidget.h"

class ATM;

class TransferDaemonsListWidget : public QWidget
{

    Q_OBJECT

public:
    TransferDaemonsListWidget(ATM& atm, QWidget* parent = nullptr);
    ~TransferDaemonsListWidget();

    void updateData();

signals:
    void closed();

private slots:
    void deleteTransferDaemonCard(TransferDaemonCardWidget*);

private:
    ATM& _atm;
    Ui_TransferDaemonsList ui;
};