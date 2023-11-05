#pragma once
#include "ui_transfer_daemons_list.h"

class TransferDaemonsListWidget : public QWidget
{

    Q_OBJECT

public:
    TransferDaemonsListWidget(QWidget* parent = nullptr);
    ~TransferDaemonsListWidget();

signals:
    void closed();

private:
    Ui_TransferDaemonsList ui;
};