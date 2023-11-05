#pragma once
#include "ui_credit_limit.h"

class CreditLimitWidget : public QWidget
{

    Q_OBJECT

public:
    CreditLimitWidget(QWidget* parent = nullptr);
    ~CreditLimitWidget();

signals:
    void closed();

private:
    Ui_CreditLimit ui;
};