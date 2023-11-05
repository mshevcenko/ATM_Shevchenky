#pragma once
#include "ui_create_overflow_credit_service.h"

class CreateOverflowCreditServiceWidget : public QWidget
{

    Q_OBJECT

public:
    CreateOverflowCreditServiceWidget(QWidget* parent = nullptr);
    ~CreateOverflowCreditServiceWidget();

signals:
    void closed();

private:
    Ui_CreateOverflowCreditService ui;
};