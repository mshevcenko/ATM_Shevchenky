#pragma once
#include "ui_overflow.h"

class ATM;

class OverflowWidget : public QWidget
{

    Q_OBJECT

public:
    OverflowWidget(ATM& atm, QWidget* parent = nullptr);
    ~OverflowWidget();

    void updateData();

signals:
    void overflowService();
    void createOverflowCreditService();
    void overflowCreditServicesList();
    void closed();

private:
    ATM& _atm;
    Ui_Overflow ui;
};