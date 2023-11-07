#pragma once
#include "ui_overflow_credit_services_list.h"
#include "OverflowCreditServiceCardWidget.h"

class ATM;

class OverflowCreditServicesListWidget : public QWidget
{

    Q_OBJECT

public:
    OverflowCreditServicesListWidget(ATM& atm, QWidget* parent = nullptr);
    ~OverflowCreditServicesListWidget();

    void updateData();

signals:
    void closed();

private slots:
    void deleteOverflowCreditServiceCard(OverflowCreditServiceCardWidget*);

private:
    ATM& _atm;
    Ui_OverflowCreditServicesList ui;
};