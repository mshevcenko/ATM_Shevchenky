#pragma once
#include "ui_overflow_credit_services_list.h"

class OverflowCreditServicesListWidget : public QWidget
{

    Q_OBJECT

public:
    OverflowCreditServicesListWidget(QWidget* parent = nullptr);
    ~OverflowCreditServicesListWidget();

signals:
    void closed();

private:
    Ui_OverflowCreditServicesList ui;
};