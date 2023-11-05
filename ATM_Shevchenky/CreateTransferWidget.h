#pragma once
#include "ui_create_transfer.h"

class CreateTransferWidget : public QWidget
{

    Q_OBJECT

public:
    CreateTransferWidget(QWidget* parent = nullptr);
    ~CreateTransferWidget();

signals:
    void closed();

private:
    Ui_CreateTransfer ui;
};