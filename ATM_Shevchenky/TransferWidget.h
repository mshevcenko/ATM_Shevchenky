#pragma once
#include "ui_transfer.h"

class TransferWidget : public QWidget
{

    Q_OBJECT

public:
    TransferWidget(QWidget* parent = nullptr);
    ~TransferWidget();

signals:
    void createTransfer();
    void createTransferDaemon();
    void transferDaemonsList();
    void closed();

private:
    Ui_Transfer ui;
};