#pragma once
#include "ui_transfer_history.h"

class TransferHistoryWidget : public QWidget
{

    Q_OBJECT

public:
    TransferHistoryWidget(QWidget* parent = nullptr);
    ~TransferHistoryWidget();

signals:
    void closed();

private:
    Ui_TransferHistory ui;
};