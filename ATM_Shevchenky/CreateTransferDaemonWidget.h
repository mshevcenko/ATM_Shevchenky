#pragma once
#include "ui_create_transfer_daemon.h"

class CreateTransferDaemonWidget : public QWidget
{

    Q_OBJECT

public:
    CreateTransferDaemonWidget(QWidget* parent = nullptr);
    ~CreateTransferDaemonWidget();

signals:
    void closed();

private:
    Ui_CreateTransferDaemon ui;
};