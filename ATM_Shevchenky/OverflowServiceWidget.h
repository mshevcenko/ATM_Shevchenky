#pragma once
#include "ui_overflow_service.h"

class ATM;

class OverflowServiceWidget : public QWidget
{

    Q_OBJECT

public:
    OverflowServiceWidget(ATM& atm, QWidget* parent = nullptr);
    ~OverflowServiceWidget();

    void updateData();

signals:
    void closed();

private:
    ATM& _atm;
    Ui_OverflowService ui;

    void tryDeleteOverflowService();
    void tryCreateOverflowService();
};