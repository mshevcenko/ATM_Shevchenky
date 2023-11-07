#pragma once
#include "ui_main.h"

class ATM;

class MainWidget : public QWidget
{

    Q_OBJECT

public:
    MainWidget(ATM& atm, QWidget* parent = nullptr);
    ~MainWidget();

    void updateData();

signals:
    void withdrawal();
    void transfer();
    void creditLimit();
    void overflow();
    void transferHistory();
    void pickupCard();

private:
    ATM& _atm;
    Ui_Main ui;

    void tryPickupCard();
};